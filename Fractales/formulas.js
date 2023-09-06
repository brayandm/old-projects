//Definido por la funcion recursiva Z = C * C + C ..... Z' = Z * Z + C ..... Z'' = Z' + Z' + C
function checkIfBelongsToMandelbrotSet(x, y, maxIterations) {
	var realComponentOfResult = x;
	var imaginaryComponentOfResult = y;

	for(var i = 0 ; i < maxIterations ; i++) {
		//Calculate the real and imaginary components of the result separately
		var tempRealComponent = realComponentOfResult * realComponentOfResult - imaginaryComponentOfResult * imaginaryComponentOfResult + x;
		var tempImaginaryComponent = 2 * realComponentOfResult * imaginaryComponentOfResult + y;
		
		realComponentOfResult = tempRealComponent;
		imaginaryComponentOfResult = tempImaginaryComponent;
		
		//Return a number as a percentage
		var divergence = realComponentOfResult * realComponentOfResult + imaginaryComponentOfResult * imaginaryComponentOfResult;
		var criteria = 2;
		if(divergence > criteria * criteria) return (i / maxIterations * 100);
	}
	return 0;
}