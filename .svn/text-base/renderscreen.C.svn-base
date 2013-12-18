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
void renderscreen(){
	#ifdef EXCESSIVE
	printf("renderscreen\n");
	#endif
	//things that need to happen before rendering, but on screen change.
	drawbgavi();
	if (currbpm==0){
		currbpm=100;
	}
	if (currscreen>=7&&currscreen<=11){
		draw_quad(0,512,384,-9000,640,400,255,255,255,255,0,0,1);
		if(!arcademode){
			draw_quad(0,512,384,-5000,640,400,255,255,255,255,0,0,55);
		}else{
			draw_quad(0,512,384,-5000,640,400,255,255,255,255,0,0,2);
		}
		draw_quad(0,512,384,-8990,640,400,255,255,255,255,0,0,3);
	}
	if (currscreen==17){
		draw_quad(0,512,384,-9000,640,400,255,255,255,255,0,0,1);
		if(!arcademode){
			draw_quad(0,512,384,-5000,640,400,255,255,255,255,0,0,55);
		}else{
			draw_quad(0,512,384,-5000,640,400,255,255,255,255,0,0,2);
		}
		draw_quad(0,512,384,-8990,640,400,255,255,255,255,0,0,3);
	}
	static long long totalframes=0;
	totalframes++;
	if (totalframes>65535)totalframes=-65536;
	if (currscreen==1)
		titlescreen(totalframes);
	if (currscreen==2)
		optionsscreen(totalframes);
	if (currscreen==4)
		gameselectscreen(totalframes);
	if (currscreen==5)
		songselectscreen(totalframes);
	if (currscreen==6)
		gameplayscreen(totalframes);
	if (currscreen==7)
		configuredrum();
	if (currscreen==8)
		configureguitar1();
	if (currscreen==9)
		configureguitar2();
	if (currscreen==10)
		configuresound();
	if (currscreen==12)
		gameresultscreen();
	if (currscreen==13)
		gamecreditsscreen();
	if (currscreen==14)
		gameoverscreen();
	if (currscreen==15)
		savesettingsscreen();
	if (currscreen==17)
		arcadesettingsscreen();
	if (currscreen==20)
		autoplayscreen();
	if (currscreen==21)
	    logoscreen();
	if (currscreen==6&&screenfaddingout&&songs[thesong].offset!=songs[thesong].poffset){
		nextscreen=15;
	}
	static char screentext[128];
	snprintf(screentext,127,"Options");
	static drawtext screentextt;
	screentextt.load(screentext,"font.ttf",255,255,255,uivars.options_screenname_s);
	if (currscreen>=7&&currscreen<=11){
		screentextt.draw(uivars.options_screenname_x,uivars.options_screenname_y,5100,255,255,255,255,false,true);
	}
	if (currscreen==17){
		screentextt.draw(uivars.options_screenname_x,uivars.options_screenname_y,5100,255,255,255,255,false,true);
	}
	if (currscreen==2){
		if (!screenfaddingout&&!screenfaddingin)screentextt.draw(uivars.options_screenname_x,uivars.options_screenname_y,5100,255,255,255,255,false,true);
	}
	//things that need to happen after rendering, but on screen change.
	if (prevscreen!=currscreen){
		if (currscreen<5&&currscreen!=2){
			playpreview();
		}
		if (currscreen==2&&prevscreen<7){
			playpreview();
		}
		if (currscreen!=5)
			optionselected=0;
		if (currscreen==1)optionselected=1;
		prevscreen=currscreen;
        snprintf(curravi,255,"NULL");
	}
	if (screenfaddingout){
		if (screenfaddingouttime>=255)
			screenfaddingouttime=255.0;
		if (currscreen==5&&nextscreen==4){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,640,400,255,255,255,255-int(screenfaddingouttime),0,0,14);
		}
		if (currscreen==6&&nextscreen==15){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==2)
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,640,400,255,255,255,255-int(screenfaddingouttime),0,0,3);
		if (currscreen==1&&nextscreen==4){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==20&&nextscreen==4){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==21&&nextscreen==4){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==1&&nextscreen==20){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==20&&nextscreen==21){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==21&&nextscreen==1){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==4&&nextscreen==1){//my how the tides have turned!
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==4&&nextscreen==5){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,640,400,255,255,255,255-int(screenfaddingouttime),0,0,12);
		}
		if (currscreen==6&&nextscreen==5){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==5&&nextscreen==6){
			if (screenfaddingouttime<255){
                if (widemode){
                    draw_quadt2(0,512,384,9000,640,400,255,255,255,int(screenfaddingouttime),0,0,tempbackgroundtexture);
                }else{
                    draw_quadt2(0,512,384,9000,512,384,255,255,255,int(screenfaddingouttime),0,0,tempbackgroundtexture);
                }
			}else{
				if (widemode){
                    draw_quadt2(0,512,384,9000,640,400,255,255,255,255,0,0,tempbackgroundtexture);
                }else{
                    draw_quadt2(0,512,384,9000,512,384,255,255,255,255,0,0,tempbackgroundtexture);
                }
            }
		}
		if (currscreen==6&&nextscreen==14){
			draw_quad(0,int(screenfaddingouttime)*2,384,8900,640,400,255,255,255,255,0,0,46);
			draw_quad(0,1024-int(screenfaddingouttime*2),384,9000,640,400,255,255,255,255,0,0,47);
		}
		if (currscreen==14&&nextscreen==1){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==6&&nextscreen==12){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,8500,640,400,255,255,255,int(screenfaddingouttime),0,0,48);
			else
				draw_quad(0,512,384,8500,640,400,255,255,255,255,0,0,48);
			draw_quad(0,512,int(screenfaddingouttime*3)-384,9000,512,384,255,255,255,255,0,0,49);
		}
		if (currscreen==12&&nextscreen==5){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==12&&nextscreen==13){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==13&&nextscreen==1){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==16&&nextscreen==1){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
		if (currscreen==4&&nextscreen==16){
			if (screenfaddingouttime<255)
				draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingouttime),0,0,51);
			else
				draw_quad(0,512,384,9000,642,404,0,0,0,255,0,0,51);
		}
	}else{
		screenfaddingouttime=0.0;
	}
	if (screenfaddingin){
		if (lastscreen==6&&currscreen==5){
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (lastscreen==5&&currscreen==6){
			if (screenfaddingintime>0){
                if (widemode){
                    draw_quadt2(0,512,384,9000,640,400,255,255,255,int(screenfaddingintime),0,0,tempbackgroundtexture);
                }else{
                    draw_quadt2(0,512,384,9000,512,384,255,255,255,int(screenfaddingintime),0,0,tempbackgroundtexture);
                }
            }
		}
		if (lastscreen==4&&currscreen==5){
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,640,400,255,255,255,255-int(screenfaddingintime),0,0,14);
			else draw_quad(0,512,384,9000,640,400,255,255,255,255,0,0,14);
		}
		if (lastscreen==5&&currscreen==4){
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,640,400,255,255,255,255-int(screenfaddingintime),0,0,12);
			else draw_quad(0,512,384,9000,640,400,255,255,255,255,0,0,12);
		}
		if (lastscreen==4&&currscreen==1){
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (lastscreen==15&&currscreen==14){
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (lastscreen==15&&currscreen==12){
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (lastscreen==1&&currscreen==4){//we meet again batman!
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (lastscreen==20&&currscreen==4){//we meet again batman!
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (lastscreen==21&&currscreen==4){//we meet again batman!
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (lastscreen==1&&currscreen==20){//we meet again batman!
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (lastscreen==20&&currscreen==21){//we meet again batman!
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (lastscreen==21&&currscreen==1){//we meet again batman!
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (lastscreen==1&&currscreen==1){
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (currscreen==2&&lastscreen==1){
			if (screenfaddingintime>0){
				draw_quad(0,512,384,9000,640,400,255,255,255,255-int(screenfaddingintime),0,0,3);
			}else draw_quad(0,512,384,9000,640,400,255,255,255,255,0,0,3);
		}
		if (currscreen==1&&lastscreen==14){
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (currscreen==13&&lastscreen==12){
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (currscreen==1&&lastscreen==13){
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (currscreen==16&&lastscreen==4){
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
		if (currscreen==1&&lastscreen==16){
			if (screenfaddingintime>0)draw_quad(0,512,384,9000,642,404,0,0,0,int(screenfaddingintime),0,0,51);
		}
	}else{
		screenfaddingintime=255.0;
	}
	if (screenfaddingout){
		screenfaddingouttime+=10*double(steptime)/16.0;
		if (screenfaddingouttime>=255){
			screenfaddingout=false;
			screenfaddingouttime=0.0;
			screenchangenow=true;
		}
	}else if (screenfaddingin){
		screenfaddingintime-=10.0*double(steptime)/16.0;
		if (screenfaddingintime<=0.0){
			screenfaddingin=false;
			screenfaddingintime=255.0;
		}
	}
}
