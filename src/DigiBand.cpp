/*     DigiBand (c)2005 Seijinohki PC Services and Software, This code written by Joe Wall with assitance from Velex
*      Loutzenhiser, and respected other parties.  This code is protected under the GPL License.  For any questions
*      regarding this code, please contact Joe @ www.seijinohki.net.
*
*      This software is free software; you can redistribute it and/or
*      modify it under the terms of the GNU Lesser General Public
*      License as published by the Free Software Foundation; either
*      version 2 of the License, or (at your option) any later version.
*
*      This software is distributed in the hope that it will be useful,
*      but WITHOUT ANY WARRANTY; without even the implied warranty of
*      MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
*      Lesser General Public License for more details.
*
*      You should have received a copy of the GNU Lesser General Public
*      License along with this software;  if not, write to the:
*      Free Software Foundation, Inc.
*      59 Temple Place - Suite 330
*      Boston, MA 02111-1307, USA
*/
//load C++ headers and dependencies.
#define INT64_C(c)	c ## LL
#include <iostream>
#include <dirent.h>
#include <sys/stat.h>
#include <fstream>
using namespace std;
#include <time.h>
#include <math.h>
#define SDLCALL
#define NO_STDIO_REDIRECT
#include <SDL.h>
#include <SDL_image.h>
//#include <SDL_ttf.h>
#include <SDL_thread.h>
#include <ft2build.h>
#include FT_FREETYPE_H

#ifndef LINUX
#include <xadec.h>
#endif
#include <errno.h>
extern "C" {
#ifndef LINUX
#include <avcodec.h>
#include <avformat.h>
#else
#include <ffmpeg/avcodec.h>
#include <ffmpeg/avformat.h>
#endif
}
#include <GL/gl.h>
#include <GL/glu.h>
#include <string.h>
#include <sys/types.h>
#include <iconv.h>
#include <AL/al.h>
#ifndef LINUX
#include <os_support.h>
#endif
#include <unistd.h>
#include "stream.h"
using namespace Oswego;


typedef unsigned char u_int8_t;

//load headers associated with this app.
#include "drawtext.h"
#include "song.h"
#include "themeini.h"
#include "settings.h"
#include "playavi.h"
#include "wavemngr.h"
#include "Screens/gp/playrender.h"
#include "playbgavi.h"
#include "screeninit.h"
#include "systemload.h"
#include "tileeffect.h"
#include "playsound.h"
#include "songlist.h"

//globals
#include "globals.h"
#include "stoi.C"
#include "testfile.C"

//Audio stuff
#ifndef LINUX
#include "decodexa.C"
#endif
#include "playpreview.C"
#include "playsound.C"

//load source files associated with this app.
#include "loadtexture.C"
#include "loadtextureondemand.C"
#include "genericobjects.C"
#include "parsekey.C"
#include "getmidi.C"
#include "getjoy.C"
#include "getkey.C"
#include "screeninit.C"
#include "songlist.C"
#include "drawtable.C"

//Screens!
#include "Screens/titlescreen.C" //01 obviously..
#include "Screens/arcadesettingsscreen.C" //17
#include "Screens/optionsscreen.C" //02
//#include "Screens/keyconfigscreen.C" //03 SACKED!
#include "Screens/gameselectscreen.C" //04
#include "Screens/songselectscreen.C" //05
#include "Screens/gp/drawtrack.C"
#include "Screens/gp/drawdnote0.C"
#include "Screens/gp/drawdnote1.C"
#include "Screens/gp/drawdnote2.C"
#include "Screens/gp/drawgnote0.C"
#include "Screens/gp/drawgnote1.C"
#include "Screens/gp/drawgnote2.C"
#include "Screens/gp/playnote0.C"
#include "Screens/gp/playnote1.C"
#include "Screens/gp/playnote2.C"
#include "Screens/gp/playgnote0.C"
#include "Screens/gp/playgnote1.C"
#include "Screens/gp/playgnote2.C"
#include "Screens/gp/playg2note0.C"
#include "Screens/gp/playg2note1.C"
#include "Screens/gp/playg2note2.C"
#include "Screens/gp/playoffbeat.C"
#include "Screens/freebeatscreen.C"//16 SACKED!
#include "Screens/gameplayscreen.C" //06
#include "Screens/configuredrum.C"//07
#include "Screens/configureguitar1.C"//08
#include "Screens/configureguitar2.C"//09
#include "Screens/configureauto.C"//10
#include "Screens/configuresound.C"//11
#include "Screens/gameresultscreen.C"//12
#include "Screens/gamecreditsscreen.C"//13
#include "Screens/gameoverscreen.C" //14
#include "Screens/savesettingsscreen.C" //15
#include "Screens/autoplayscreen.C"//20
#include "Screens/logoscreen.C"
#include "Screens/gp/autobgm0.C"
#include "Screens/gp/autobgm1.C"
#include "Screens/gp/autobgm2.C"
#include "Screens/gp/autoplay0.C"
#include "Screens/gp/autoplay1.C"
#include "Screens/gp/autoplay2.C"
//more source files ass. with this app.
#include "renderscreen.C"
#include "movenext.C"
#include "cachesongs.C"
#include "systemload.C"
#include "gameloop.C"
#include "Screens/gp/playrender.cpp"
#include "wavemngr.cpp"
#include "drawtext.cpp"
#include "song.cpp"
#include "settings.cpp"
#include "themeini.cpp"
#include "playavi.cpp"
#include "playbgavi.cpp"
#include "tileeffect.cpp"
#ifndef LINUX
#ifndef NOOSWEGO
#include "stream.cpp"
#include "madcodec.cpp"
#include "vorbisfilecodec.cpp"
#include "codec.cpp"
#include "sndfilecodec.cpp"
#include "alsubsys.cpp"
#endif
#endif

void cleanup(){
   	#ifdef EXCESSIVE
	printf("cleanup\n");
	#endif
	closewaves();
	killpreview();
	if (presong>-1&&presong<gbsongcount){
		songs[presong].unloadsteps();
	}
	drawtext::nukeAllInstances();
}

int main(int argc, char* argv[]){
	#ifdef EXCESSIVE
	printf("main\n");
	#endif
	//for (int a=0;a<12;a++){
      //  songtext[a]=NULL;
	//}
	srand(time(0));
	settings.load();
//	screeninit(resx,resy,drumbpp,drumfullscreen);
	screeninit(resx,resy,drumbpp,false);
//	playpreview();
	systemload();
	isloading=false;
	gameloop();
	cleanup();
	#ifdef DEBUG
	printf("ran cleanup\n");
	#endif
	//TTF_Quit();
	#ifdef DEBUG
	//printf("TTF Quit\n");
	#endif
	#ifndef NOOSWEGO
	AL::Stream::class_shutdown();
	#endif
	FT_Done_FreeType( ftlibrary );
	#ifdef DEBUG
	printf("Stream::class_shutdown\n");
	#endif
	SDL_Quit();
	#ifdef DEBUG
	printf("SDL Quit\n");
	#endif
	return 0;
}

