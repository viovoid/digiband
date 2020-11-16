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
void gameselectscreen(int totalframes){
	#ifdef EXCESSIVE
	printf("gameselectscreen\n");
	#endif
	if (currscreen!=prevscreen){
		if (presong>-1&&presong<gbsongcount){
			if(songsloaded>0)unloadwaves();
		}
		if (thesong>-1&&thesong<gbsongcount){
			if(songsloaded>0)loadwaves();
		}
		playsound(14,"selectmode.wav");
	}
	static bool hasavi=true;
	currstage=1;
	gptscore=0;
	gpg1tscore=0;
	gpg2tscore=0;
	gplifebar=50;
	gpg1lifebar=50;
	gpg2lifebar=50;
	static drawtext drumplayer;
	drumplayer.load("Drum Player","silly.ttf",255,255,255,uivars.mode_drumtext1_s);
	static drawtext drumplayer2;
	drumplayer2.load("Press Start","silly.ttf",255,255,255,uivars.mode_drumtext2_s);
	static drawtext guit1player;
	guit1player.load("Guitar Player 1","silly.ttf",255,255,255,uivars.mode_guitar1text1_s);
	static drawtext guit2player;
	guit2player.load("Guitar Player 2","silly.ttf",255,255,255,uivars.mode_guitar2text1_s);


	draw_quad(0,512,384,-9000,640,400,255,255,255,255,0,0,11);
	static double aniframes1=90;
	static double aniframes2=90;
	static double aniframes3=90;
	static int lastframe=0;
	draw_quad(0,uivars.mode_drumgraphic_x,uivars.mode_drumgraphic_y,-300,161,251,255,255,255,255,0,0,5);
	draw_quad(0,uivars.mode_guitar1graphic_x,uivars.mode_guitar1graphic_y,-300,161,251,255,255,255,255,0,0,5);
	draw_quad(0,uivars.mode_guitar2graphic_x,uivars.mode_guitar2graphic_y,-300,161,251,255,255,255,255,0,0,5);
	if (drummode==true){
		aniframes1-=10*double(steptime)/16.0;
		if (aniframes1<0){
			aniframes1=0;}
	}else{
		aniframes1=90;
	}
	if (guitar1mode==true){
		aniframes2-=10*double(steptime)/16.0;
		if (aniframes2<0){
			aniframes2=0;}
	}else{
		aniframes2=90;
	}
	if (guitar2mode==true){
		aniframes3-=10*double(steptime)/16.0;
		if (aniframes3<0){
			aniframes3=0;}
	}else{
		aniframes3=90;
	}
	draw_quad(0,uivars.mode_drumgraphic_x,uivars.mode_drumgraphic_y,-100,163,253,255,255,255,255,int(aniframes1),0,8);
	draw_quad(0,uivars.mode_guitar1graphic_x,uivars.mode_guitar1graphic_y,-100,163,253,255,255,255,255,int(aniframes2),0,9);
	draw_quad(0,uivars.mode_guitar2graphic_x,uivars.mode_guitar2graphic_y,-100,163,253,255,255,255,255,int(aniframes3),0,10);
	if (!drummode){
		drumplayer.draw(uivars.mode_drumtext1_x,uivars.mode_drumtext1_y,0,255,128,128,255,true,true);
		drumplayer2.draw(uivars.mode_drumtext2_x,uivars.mode_drumtext2_y,10,255,128,128,255,true,true);
	}
	if (!guitar1mode){
		guit1player.draw(uivars.mode_guitar1text1_x,uivars.mode_guitar1text1_y,0,255,128,128,255,true,true);
		drumplayer2.draw(uivars.mode_guitar1text2_x,uivars.mode_guitar1text2_y,10,255,128,128,255,true,true);
	}
	if (!guitar2mode){
		guit2player.draw(uivars.mode_guitar2text1_x,uivars.mode_guitar2text1_y,0,255,128,128,255,true,true);
		drumplayer2.draw(uivars.mode_guitar2text2_x,uivars.mode_guitar2text2_y,10,255,128,128,255,true,true);
	}
	if (optionselected<0)
		optionselected=1;
	if (optionselected>1)
		optionselected=0;
	static drawtext gamemodetext;
	static drawtext waitforplayer;
	if (!arcademode){
		if (optionselected==0){
			gamemodetext.load("   Press Start! ","font.ttf",255,255,255,uivars.mode_start_s);
		}
		if (optionselected==1){
			gamemodetext.load("   Press Start! ","font.ttf",255,255,255,uivars.mode_start_s);
		}
	}
	waitforplayer.load("Waiting for other players. To skip, press start.","font.ttf",255,255,255,uivars.mode_message_s);
	if (!screenfaddingout&&!screenfaddingin&&currscreen==4)draw_quad(0,512,384,5000,640,400,255,255,255,255,0,0,12);//must be at end.
	if (screenfaddingin&&lastscreen==1&&nextscreen!=5)draw_quad(0,512,384,5000,640,400,255,255,255,255,0,0,12);//must be at end.
	if (screenfaddingout&&lastscreen==1&&nextscreen!=5)draw_quad(0,512,384,5000,640,400,255,255,255,255,0,0,12);//must be at end.
	if (screenfaddingout&&currscreen==4&&nextscreen==1)draw_quad(0,512,384,5000,640,400,255,255,255,255,0,0,12);//must be at end.
	if (drummode||guitar1mode||guitar2mode){
		waitforplayer.draw(uivars.mode_message_x,uivars.mode_message_y,5100,255,128,128,255,true,true);
	}
	if (!screenfaddingin&&!screenfaddingout){
		if (!arcademode)
			gamemodetext.draw(uivars.mode_start_x,uivars.mode_start_y,5100,255,128,128,255,true,true);
		static char screentext[128];
		sprintf(screentext,"Select Game Mode");
		static drawtext screentextt;
		screentextt.load(screentext,"font.ttf",255,255,255,uivars.mode_screenname_s);
		screentextt.draw(uivars.mode_screenname_x,uivars.mode_screenname_y,5100,255,255,255,255,false,true);
	}
	if (arcademode){
		static char option1[256];
		sprintf(option1,"Coins %i/%i Credits (%i)",coinsinserted,coinsperplay,credits);
		static drawtext option1s;
		option1s.load(option1,"font.ttf",255,255,255,20);
		option1s.draw(415,20,5100,255,255,255,255,false,true);
	}
	//counter
	if (arcademode){
		if (menucountertime>0){
			static long timer=0;
			if (currscreen!=prevscreen)
				timer=SDL_GetTicks();
			int timeleft=int(double(menucountertime)-((double(SDL_GetTicks())-double(timer))/1000.0));
			char disptime[10];
			sprintf(disptime,"%i",timeleft);
			static drawtext timerdisp;
			timerdisp.load(disptime,"font.ttf",255,255,255,uivars.timer_s);
			draw_quad(0,27,743,9800,25,25,255,255,255,255,0,0,66);
			if (timeleft>5){
				timerdisp.draw(uivars.timer_x-(timerdisp.width/2),uivars.timer_y-(timerdisp.height/2),9900,255,255,255,255,false,true);
			}else{
				if (timeleft==5)playsound(17,"timer.wav");
				timerdisp.draw(uivars.timer_x-(timerdisp.width/2),uivars.timer_y-(timerdisp.height/2),9900,255,128,128,255,true,true);
			}
			if (timeleft==0){
				screenfaddingout=true;
				nextscreen=5;
				screenchangenow=false;	
			}
		}
	}
}
