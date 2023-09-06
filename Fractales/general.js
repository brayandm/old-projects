var myCanvas, ctx, contenedor, selector;
var f_precision, f_sat, f_mag_, f_panX, f_panY;

var precision = 30;
var saturationRange = 3.6;
var magnificationFactor = 200;
var panX = 0.7;
var panY = 0;

function iniciar() {
	var enviar = document.getElementById("generar");
	contenedor = document.getElementById("contenedor");
	myCanvas = document.getElementById("canvas");
	myCanvas.width = 600;
	myCanvas.height = 600;
	ctx = myCanvas.getContext("2d");
	
	draw();
	createSelector();
	initForm();
	
	contenedor.addEventListener("mousedown", startSelector);
	contenedor.addEventListener("mousemove", defineSelectorSize, false);
	document.body.addEventListener("mouseup", endSelector);
	document.addEventListener("keydown", inputSelector);
	
	enviar.addEventListener("click", generar);
};

function initForm() {
	f_precision = document.getElementById("iterations");
	f_sat = document.getElementById("saturation");
	f_mag = document.getElementById("magnification");
	f_panX = document.getElementById("moveX");
	f_panY = document.getElementById("moveY");
	
	updateForm();
}

function updateForm() {
	f_precision.value = precision;
	f_sat.value = saturationRange;
	f_mag.value = magnificationFactor;
	f_panX.value = panX;
	f_panY.value = panY;
}

function generar() {
	precision = new Number(f_precision.value);
	saturationRange = new Number(f_sat.value);
	magnificationFactor = new Number(f_mag.value);
	panX = new Number(f_panX.value);
	panY = new Number(f_panY.value);
	
	draw();
}

var flagSelector = false, startX, startY, endX, endY, w, h;

function startSelector(evento) {
	
	if(evento.target.id != "canvas" || evento.button != "0") return;
	
	flagSelector = true;
	startX = evento.offsetX;
	startY = evento.offsetY;
	
	selector.style.display = "inline-block";
	selector.style.width = "1px";
	selector.style.height = "1px";
	selector.style.top = startY + "px";
	selector.style.left = startX + "px";
}

var negX = false, negY = false; 
function defineSelectorSize(evento) {
	if(flagSelector) {
		
		var mouseX, mouseY;
		if(evento.target.id == "canvas") {
			mouseX = evento.offsetX;
			mouseY = evento.offsetY;
		}
		else if(evento.target.id == "selector"){
			if(negX == false) mouseX = evento.offsetX + startX;
			else mouseX = evento.offsetX + endX;
			
			if(negY == false) mouseY = evento.offsetY + startY;
			else mouseY = evento.offsetY + endY;
		}
		
		endX = mouseX;
		if(mouseX >= startX) {
			negX = false;
			selector.style.left = startX + "px";
		}
		else {
			negX = true;
			selector.style.left = mouseX + "px";
		}
		
		endY = mouseY;
		if(mouseY >= startY) {
			negY = false;
			selector.style.top = startY + "px";
		}
		else {
			negY = true;
			selector.style.top = mouseY + "px";
		}
		
		w = endX - startX;
		h = endY - startY;
		if(w < 0) w = -w;
		if(h < 0) h = -h;
		selector.style.width = w + "px";
		selector.style.height = h + "px";
	}
}

function endSelector() {
	flagSelector = false;
}

function inputSelector(evento) {
	if(evento.key == "Enter" && selector.style.display == "inline-block") {
		var tempX = selector.style.left.substring(0, selector.style.left.length - 2);
		var tempY = selector.style.top.substring(0, selector.style.top.length - 2);
		var initX = new Number(tempX);
		var initY = new Number(tempY);
		selector.style.display = "none";
		
		if(w > h) h = w;
		else w = h;
		
		var centerX = myCanvas.width / 2, centerY = myCanvas.height / 2;
		var scenterX = initX + w / 2, scenterY = initY + h / 2;
		
		var dpx = scenterX - centerX;
		var dpy = scenterY - centerY;
		var dx = dpx / magnificationFactor;
		var dy = dpy / magnificationFactor;
		panX -= dx;
		panY -= dy;
		
		ratio = myCanvas.width / w;
		magnificationFactor *= ratio;
		magnificationFactor = parseInt(magnificationFactor);
		
		updateForm();
		draw();
	}
}

function draw() {
	var halfW = myCanvas.width / 2, halfH = myCanvas.height / 2;
	for(var x = -halfW ; x < halfW ; x++) {
		for(var y = -halfH ; y < halfH ; y++) {
			var belongsToSet = checkIfBelongsToMandelbrotSet(x / magnificationFactor - panX, y / magnificationFactor - panY, precision);
			if(belongsToSet == 0) {
				ctx.fillStyle = "#000000";
				ctx.fillRect(x + halfW, y + halfH, 1, 1); //Draw a black pixel
			}
			else {
				var hvalue = belongsToSet * saturationRange;
				ctx.fillStyle = "hsl(" + hvalue + ", 100%, " + belongsToSet + "%)";
				ctx.fillRect(x + halfW, y + halfH, 1, 1); //Draw a colorful pixel
			}
		}
	}
}

function createSelector() {
	selector = document.createElement("div");
	selector.id = "selector";
	contenedor.appendChild(selector);
}

window.addEventListener("load", iniciar);