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

#include <sys/stat.h>

int countsongs(){
	#ifdef EXCESSIVE
	printf("countsongs\n");
	#endif
	//begin discovery of directory structure.
	int songcount=0;
	int catcount=0;
	DIR *d;
	DIR *d2;
	dirent *dir;
	dirent *cat;
	d=opendir("./Songs");
	char dircat[256];
	if (d==NULL){
		printf("Security settings for directory incorrect.");
		exit(1);
	}
	while(dir=readdir(d)){
		if (strcmp( dir->d_name, ".")==0 ||strcmp(dir->d_name,"..")==0){
			continue;
		}
		struct stat idiots;
		char fuckingidiots[1024];
		snprintf(fuckingidiots,1023, "./Songs/%s", dir->d_name);
		stat(fuckingidiots,&idiots);
		if (!S_ISDIR(idiots.st_mode)){
			continue;
		}
		snprintf(dircat,255,"./Songs/%s",dir->d_name);
		d2=opendir(dircat);
		catcount++;
		while(cat=readdir(d2)){
			if (strcmp( cat->d_name, ".")==0 ||strcmp(cat->d_name,"..")==0){
				continue;
			}
			struct stat grumblegrumble;
			char fuckinggrr[1024];
			snprintf (fuckinggrr,1023,"./Songs/%s/%s",dir->d_name,cat->d_name);
			stat(fuckinggrr,&grumblegrumble);
			if (!S_ISDIR(grumblegrumble.st_mode)){
				continue;
			};
			songcount++;
		}
	}
	//end of directory structure thingy.
	//MAYFAIL
	gbsongcount=songcount;
	gbcatcount=catcount;
	catlist=(char**)malloc(sizeof(char*)*(gbcatcount+1));
	for (int a=0;a<gbcatcount;a++){
		catlist[a]=(char*)malloc(sizeof(char)*256);	
	}
	catsongs=(int*)malloc(sizeof(int)*gbcatcount);
	return gbsongcount;
}

void nextobject(int alpha=0,bool movenext=true){
	#ifdef EXCESSIVE
	printf("nextobject\n");
	#endif
	getkey();
	texani[13][2]++;
	if (texani[13][2]>=texani[13][0])
		texani[13][2]=0.0;
	static int files=countsongs();
	static int a=0;
	static int b=0;
	static char theversion[256];
	static char themessage[256];
	snprintf(theversion,255,"DigiBand v%s", VERSION);
	snprintf(themessage,255,"Loading %i songs...", files);
	static drawtext message;
	static drawtext version;
	message.load(themessage,"font.ttf",255,255,255,uivars.load_message1_s);
	version.load(theversion,"font.ttf",255,255,255,uivars.load_version_s);
	if (strlen(textureframe)<2){
		snprintf(textureframe,127,"");
	}
	static drawtext message2;
	message2.load(textureframe,"font.ttf",255,255,255,uivars.load_message2_s);
	static drawtext logotext;
	logotext.load("Seijin-Ohki Soft","POR2.TTF",128,128,255,uivars.load_logotext1_s);
	static drawtext logotext2;
	logotext2.load("Presents","impact.ttf",255,50,200,uivars.load_logotext2_s);
	static int totala=files+25;
	char logomodel[300];
	double percent=(double(a)/double(totala))*100;
	if (percent<100){
		snprintf(themessage,255,"%.2f%%", percent);
	}else{
		snprintf(themessage,255,"done");
	}
	static drawtext status;
	status.load(themessage,"font.ttf",255,255,255,uivars.load_status_s);
	
	int totalobjects=0;
	//ghetto way of disabling vsync, makes for faster loads on some systems.
	static int lasttick=0;
	if (SDL_GetTicks()>lasttick+11){
		SDL_GL_SwapBuffers();
		lasttick=SDL_GetTicks();
	}
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity( );
	if (movenext)a++;
	b++;
	for (int x=0;x<100;x+=2){
		if (x<(double(a)/double(totala))*100.0){
		draw_quad(0,x*10+15,15,0,8,10,0,0,255,255,0,0,13);
		}
	}
	status.draw(uivars.load_status_x,uivars.load_status_y,10);
	version.draw(uivars.load_version_x,uivars.load_version_y,0);
	message.draw(uivars.load_message1_x,uivars.load_message1_y,0);
	message2.draw(uivars.load_message2_x,uivars.load_message2_y,-20);
	logotext.draw(uivars.load_logotext1_x,uivars.load_logotext1_y,0,255,128,128,255);
	logotext2.draw(uivars.load_logotext2_x,uivars.load_logotext2_y,0,255,255,50,200);
	if (alpha>0)
		draw_quad(0,512,384,9999,640,400,0,0,0,alpha,0,0,0);
}	

void fadein(){
    #ifdef EXCESSIVE
	printf("fadein\n");
	#endif
	for (int a=255;a>0;a-=10){
		nextobject(a);
	}
}

void fadout(){
    #ifdef EXCESSIVE
	printf("fadeout\n");
	#endif
	for (int a=0;a<258;a+=10){
		nextobject(a);
	}
}
