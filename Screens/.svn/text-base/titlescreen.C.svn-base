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
void titlescreen(int totalframes){
	#ifdef EXCESSIVE
	printf("titlescreen\n");
	#endif
	if (currscreen!=prevscreen){
		if (presong>-1&&presong<gbsongcount){
			if(songsloaded>0)unloadwaves();
		}
		if (thesong>-1&&thesong<gbsongcount){
			if(songsloaded>0)loadwaves();
		}
		if(prevscreen==13){
			savescores();		
		}
	}
	draw_quad(0,512,384,-9000,640,400,255,255,255,255,0,0,1);
	currstage=1;
	gptscore=0;
	gpg1tscore=0;
	gpg2tscore=0;
	gplifebar=50;
	gpg1lifebar=50;
	gpg2lifebar=50;
	if(!arcademode){
		draw_quad(0,512,384,-5000,640,400,255,255,255,255,0,0,55);
	}else{
		draw_quad(0,512,384,-5000,640,400,255,255,255,255,0,0,2);
	}
	if (!arcademode){
		static char option1[256];
		static char option2[256];
		static char option3[256];
		snprintf(option1,255,"Game Start");
		snprintf(option2,255,"Options");
		snprintf(option3,255,"Quit");
		static drawtext option1d;
		option1d.load(option1,"font.ttf",255,255,255,uivars.title_start_s);
		static drawtext option2d;
		option2d.load(option2,"font.ttf",255,255,255,uivars.title_options_s);
		static drawtext option3d;
		option3d.load(option3,"font.ttf",255,255,255,uivars.title_quit_s);
		if (optionselected<1)optionselected=3;
		if (optionselected>3)optionselected=1;
		if (optionselected!=1){option1d.draw(uivars.title_start_x,uivars.title_start_y,0,255,255,255,255,false,true);}
		else{option1d.draw(uivars.title_start_x,uivars.title_start_y,0,255,128,128,255,true,true);}
		if (optionselected!=2){option2d.draw(uivars.title_options_x,uivars.title_options_y,0,255,255,255,255,false,true);}
		else{option2d.draw(uivars.title_options_x,uivars.title_options_y,0,255,128,128,255,true,true);}
		if (optionselected!=3){option3d.draw(uivars.title_quit_x,uivars.title_quit_y,0,255,255,255,255,false,true);}
		else{option3d.draw(uivars.title_quit_x,uivars.title_quit_y,0,255,128,128,255,true,true);}
	}else{
		static char option1[256];
		snprintf(option1,255,"Coins %i/%i Credits (%i)",coinsinserted,coinsperplay,credits);
		static drawtext option1s;
		option1s.load(option1,"font.ttf",255,255,255,20);
		option1s.draw(400,0,0,255,255,255,255,false,true);
	}
	//version
	static char theversion[256];
	snprintf(theversion,255,"Version %s",VERSION);
	static drawtext theversiont;
	theversiont.load(theversion,"font.ttf",255,255,255,uivars.title_version_s);
	theversiont.draw(uivars.title_version_x,uivars.title_version_y,0,255,255,255,255,false,true);
	//YAY!!! ADD!!	
	if (arcademode){
		if (menucountertime>0){
			static long timer=0;
			if (currscreen!=prevscreen)
				timer=SDL_GetTicks();
			#ifndef EXCESSIVE
			int timeleft=int(double(40)-((double(SDL_GetTicks())-double(timer))/1000.0));
			#else
			int timeleft=int(double(5)-((double(SDL_GetTicks())-double(timer))/1000.0));
			#endif
			char disptime[10];
			snprintf(disptime,9,"%i",timeleft);
			if (timeleft==0){
				nextscreen=20;
				screenfaddingout=true;
				screenchangenow=false;
				screenfaddingin=false;
			}
		}
	}
}
