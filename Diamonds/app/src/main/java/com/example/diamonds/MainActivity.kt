package com.example.diamonds

import android.content.Context
import android.media.MediaActionSound
import android.media.MediaPlayer
import android.os.Bundle
import android.widget.Space
import androidx.activity.ComponentActivity
import androidx.activity.compose.setContent
import androidx.activity.viewModels
import androidx.compose.animation.*
import androidx.compose.foundation.Image
import androidx.compose.foundation.layout.*
import androidx.compose.foundation.lazy.LazyColumn
import androidx.compose.foundation.lazy.items
import androidx.compose.material.MaterialTheme
import androidx.compose.material.Surface
import androidx.compose.material.Text
import androidx.compose.runtime.*
import androidx.compose.runtime.livedata.observeAsState
import androidx.compose.ui.Alignment
import androidx.compose.ui.Modifier
import androidx.compose.ui.graphics.Color
import androidx.compose.ui.platform.LocalDensity
import androidx.compose.ui.res.painterResource
import androidx.compose.ui.text.font.Font
import androidx.compose.ui.text.font.FontStyle
import androidx.compose.ui.text.style.TextAlign
import androidx.compose.ui.unit.dp
import androidx.compose.ui.unit.sp
import androidx.lifecycle.LiveData
import androidx.lifecycle.MutableLiveData
import androidx.lifecycle.ViewModel
import com.example.diamonds.ui.theme.DiamondsTheme

class MainActivity : ComponentActivity() {

    lateinit var music : MediaPlayer

    override fun onCreate(savedInstanceState: Bundle?) {
        super.onCreate(savedInstanceState)
        setContent {
            DiamondsTheme {
                // A surface container using the 'background' color from the theme
                Surface(
                    modifier = Modifier.fillMaxSize(),
                    color = Color.Black
                ) {
                    music = MediaPlayer.create(this, R.raw.diamonds)

                    music.start()

                    val viewModel: MainViewModel by viewModels()

                    Main(this, viewModel)
                }
            }
        }
    }
}

@Composable
fun Main(context: Context, viewModel: MainViewModel)
{
    val state = viewModel.state().observeAsState(false)

    val pos = viewModel.pos().observeAsState(0)

    val list = viewModel.list().observeAsState(mutableListOf<Info>())

    val begin = viewModel.begin().observeAsState(0L)

    if(!state.value)
    {
        val text = context.getResources().openRawResource(
            context.getResources().getIdentifier("subtitles",
                "raw", context.getPackageName()));

        val lines = text.reader().readLines()

        fun GetNumber(cad : String): Long {

            val hour = cad[0].digitToInt()*10L + cad[1].digitToInt()
            val min = cad[3].digitToInt()*10L + cad[4].digitToInt()
            val sec = cad[6].digitToInt()*10L + cad[7].digitToInt()
            val mil = cad[9].digitToInt()*100L + cad[10].digitToInt()*10L + cad[11].digitToInt()

            return hour*3600000L + min*60000L + sec*1000L + mil
        }

        var tlist = mutableListOf<Info>()

        for(i in lines.indices)
        {
            if(i%4 == 0)
            {
                val t1 = GetNumber(lines[i+1].substring(0,12))
                val t2 = GetNumber(lines[i+1].substring(17,29))
                val cad = lines[i+2]

                tlist.add(Info(t1, cad))
                tlist.add(Info(t2, ""))
            }
        }

        viewModel.listSet(tlist)
        viewModel.beginSet(System.nanoTime())
        viewModel.stateSet(!state.value)
    }
    else
    {
        Piece(list, begin, pos, viewModel)
    }
}

data class Info(val t: Long, val cad: String);

@Composable
fun Piece(list : State<MutableList<Info>>, begin : State<Long>, pos : State<Int>, viewModel: MainViewModel)
{
    if (pos.value >= list.value.size)
    {
        while(true)
        {

        }
    }

    var delay = 39300
    do {
        val now = System.nanoTime() - begin.value
    } while (now < (list.value[pos.value].t-delay)*1000000)

    Image(painter = painterResource(id = R.drawable.picture), contentDescription = "",
    alignment = Alignment.Center)

    Column(horizontalAlignment = Alignment.CenterHorizontally,
    verticalArrangement = Arrangement.Center) {

        Spacer(modifier = Modifier.padding(160.dp))

        Text(list.value[pos.value].cad, fontSize = 30.sp,
            modifier = Modifier.padding(15.dp), textAlign = TextAlign.Center,
            fontStyle = FontStyle.Italic, color = Color.LightGray)
    }

    viewModel.posSet(pos.value + 1)
}

class MainViewModel : ViewModel()
{
    private var state = MutableLiveData(false)
    private var pos = MutableLiveData(0)
    private var list = MutableLiveData(mutableListOf<Info>())
    private var begin = MutableLiveData(0L)

    fun state() : LiveData<Boolean> = state
    fun pos() : LiveData<Int> = pos
    fun list() : LiveData<MutableList<Info>> = list
    fun begin() : LiveData<Long> = begin

    fun stateSet(v : Boolean)
    {
        state.value = v
    }

    fun posSet(v : Int)
    {
        pos.value = v
    }

    fun listSet(v : MutableList<Info>)
    {
        list.value = v
    }

    fun beginSet(v : Long)
    {
        begin.value = v
    }
}

