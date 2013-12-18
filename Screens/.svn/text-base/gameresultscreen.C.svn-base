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
void gameresultscreen(){
	#ifdef EXCESSIVE
	printf("gameresultscreen\n");
	#endif
	static int gptotal;
	static int gpbonus;
	static int gpg1total;
	static int gpg1bonus;
	static int gpg2total;
	static int gpg2bonus;
	if (currscreen!=prevscreen){
		songs[thesong].loadextended();
		currstage++;
		if (songs[thesong].islong)
			currstage++;
		gptotal=gpmiss+gpalmost+gpgood+gpgreat+gpperfect;
		gpbonus=1000*gpmaxcombo;
		if (gpmaxcombo==gptotal)
			gpbonus=gpbonus+10000*gpmaxcombo;
		gpscore=gpscore+gpbonus;
		gptscore=gptscore+gpscore;
		gpg1total=gpg1miss+gpg1almost+gpg1good+gpg1great+gpg1perfect;
		gpg1bonus=1000*gpg1maxcombo;
		if (gpg1maxcombo==gpg1total)
			gpg1bonus=gpg1bonus+10000*gpg1maxcombo;
		gpg1score=gpg1score+gpg1bonus;
		gpg1tscore=gpg1tscore+gpg1score;
		gpg2total=gpg2miss+gpg2almost+gpg2good+gpg2great+gpg2perfect;
		gpg2bonus=1000*gpg2maxcombo;
		if (gpg2maxcombo==gpg2total)
			gpg2bonus=gpg2bonus+10000*gpg2maxcombo;
		gpg2score=gpg2score+gpg2bonus;
		gpg2tscore=gpg2tscore+gpg2score;
		if (drumdiff==0){if (songs[thesong].basdrumhs<gpscore){songs[thesong].basdrumhs=gpscore;songs[thesong].basdrummc=gpmaxcombo;}}
		if (drumdiff==1){if (songs[thesong].advdrumhs<gpscore){songs[thesong].advdrumhs=gpscore;songs[thesong].advdrummc=gpmaxcombo;}}
		if (drumdiff==2){if (songs[thesong].extdrumhs<gpscore){songs[thesong].extdrumhs=gpscore;songs[thesong].extdrummc=gpmaxcombo;}}
		if (guit1diff==0){if (songs[thesong].basguitar1hs<gpg1score){songs[thesong].basguitar1hs=gpg1score;songs[thesong].basguitar1mc=gpg1maxcombo;}}
		if (guit1diff==1){if (songs[thesong].advguitar1hs<gpg1score){songs[thesong].advguitar1hs=gpg1score;songs[thesong].advguitar1mc=gpg1maxcombo;}}
		if (guit1diff==2){if (songs[thesong].extguitar1hs<gpg1score){songs[thesong].extguitar1hs=gpg1score;songs[thesong].extguitar1mc=gpg1maxcombo;}}
		if (guit2diff==0){if (songs[thesong].basguitar2hs<gpg2score){songs[thesong].basguitar2hs=gpg2score;songs[thesong].basguitar2mc=gpg2maxcombo;}}
		if (guit2diff==1){if (songs[thesong].advguitar2hs<gpg2score){songs[thesong].advguitar2hs=gpg2score;songs[thesong].advguitar2mc=gpg2maxcombo;}}
		if (guit2diff==2){if (songs[thesong].extguitar2hs<gpg2score){songs[thesong].extguitar2hs=gpg2score;songs[thesong].extguitar2mc=gpg2maxcombo;}}
		songs[thesong].saveextended();
		songs[thesong].loadextended();
		playpreview();
	}
	draw_quad(0,512,384,-8000,640,400,255,255,255,255,0,0,48);
	draw_quad(0,512,384,-7900,512,384,255,255,255,255,0,0,49);
	int bot=uivars.result_bottomdrum;
	int left=uivars.result_leftdrum;
	if (drummode){
		static drawtext dmperfect;
		static char dmper[256];
		sprintf(dmper,"%i",gpperfect);
		dmperfect.load(dmper,"grade.ttf",255,255,255,40);
		dmperfect.draw(left,484+bot,0,255,255,255,255,false,true,false);
		static drawtext dmgreat;
		static char dmgre[256];
		sprintf(dmgre,"%i",gpgreat);
		dmgreat.load(dmgre,"grade.ttf",255,255,255,40);
		dmgreat.draw(left,440+bot,0,255,255,255,255,false,true,false);
		static drawtext dmgood;
		static char dmgoo[256];
		sprintf(dmgoo,"%i",gpgood);
		dmgood.load(dmgoo,"grade.ttf",255,255,255,40);
		dmgood.draw(left,396+bot,0,255,255,255,255,false,true,false);
		static drawtext dmalmost;
		static char dmalm[256];
		sprintf(dmalm,"%i",gpalmost);
		dmalmost.load(dmalm,"grade.ttf",255,255,255,40);
		dmalmost.draw(left,352+bot,0,255,255,255,255,false,true,false);
		static drawtext dmmiss;
		static char dmmis[256];
		sprintf(dmmis,"%i",gpmiss);
		dmmiss.load(dmmis,"grade.ttf",255,255,255,40);
		dmmiss.draw(left,308+bot,0,255,255,255,255,false,true,false);
		static drawtext dmtotal;
		static char dmtot[256];
		sprintf(dmtot,"%i",gptotal);
		dmtotal.load(dmtot,"grade.ttf",255,255,255,40);
		dmtotal.draw(left,264+bot,0,255,255,255,255,false,true,false);
		static drawtext dmmaxcombo;
		static char dmmax[256];
		if (gpmaxcombo==gptotal){
			sprintf(dmmax,"%i*",gpmaxcombo);
			if (currscreen!=prevscreen)playsound(16,"fullcombo.wav");
		}else{
			sprintf(dmmax,"%i",gpmaxcombo);
		}
		dmmaxcombo.load(dmmax,"grade.ttf",255,255,255,40);
		dmmaxcombo.draw(left,220+bot,0,255,255,255,255,false,true,false);
		static drawtext dmbonus;
		static char dmbon[256];
		sprintf(dmbon,"%i",gpbonus);
		dmbonus.load(dmbon,"grade.ttf",255,255,255,40);
		dmbonus.draw(left-190,132+bot,0,255,255,255,255,false,true,false);
		static drawtext dmscore;
		static char dmsco[256];
		sprintf(dmsco,"%i",gpscore);
		dmscore.load(dmsco,"grade.ttf",255,255,255,40);
		dmscore.draw(left-190,44+bot,0,255,255,255,255,false,true,false);
		static drawtext dmtscore;
		static char dmtsc[256];
		sprintf(dmtsc,"%i",gptscore);
		dmtscore.load(dmtsc,"grade.ttf",255,255,255,40);
		dmtscore.draw(left-190,518+bot,100,255,255,255,255,false,true,false);
		static drawtext dmlettergrade;
		static char dmletgrade[256];
		if (currscreen!=prevscreen){
			if ((gpperfect+gpgreat+gpgood)<=(.75*gptotal)){
				sprintf(dmletgrade,"F");
				dmlettergrade.load(dmletgrade,"grade.ttf",128,0,0,120);
			}
			if ((gpperfect+gpgreat+gpgood)>(.75*gptotal)){
				sprintf(dmletgrade,"D");
				dmlettergrade.load(dmletgrade,"grade.ttf",0,192,0,120);
			}
			if ((gpperfect+gpgreat+gpgood)>(.85*gptotal)){
				sprintf(dmletgrade,"C");
				dmlettergrade.load(dmletgrade,"grade.ttf",0,0,255,120);
			}
			if ((gpperfect+gpgreat+gpgood)>(.9*gptotal)){
				sprintf(dmletgrade,"B");
				dmlettergrade.load(dmletgrade,"grade.ttf",255,192,0,120);
			}
			if ((gpperfect+gpgreat+gpgood)>(.95*gptotal)){
				sprintf(dmletgrade,"A");
				dmlettergrade.load(dmletgrade,"grade.ttf",255,0,255,120);
			}
			if ((gpperfect+gpgreat+gpgood)==gptotal){
				sprintf(dmletgrade,"S");
				dmlettergrade.load(dmletgrade,"grade.ttf",255,255,0,120);
			}
			if ((gpperfect+gpgreat)==gptotal){
				sprintf(dmletgrade,"SS");
				dmlettergrade.load(dmletgrade,"grade.ttf",255,255,128,120);
			}
			if (gpperfect==gptotal){
				sprintf(dmletgrade,"SSS");
				dmlettergrade.load(dmletgrade,"grade.ttf",255,255,255,120);
			}
		}
		dmlettergrade.draw(left-80,578+bot,5,128,128,128,255,false,true,false);
		dmlettergrade.draw(left-90,588+bot,10,255,255,255,255,false,true,false);
	}
	if (guitar1mode){
		bot=uivars.result_bottomg1;
		left=uivars.result_leftg1;
		static drawtext g1perfect;
		static char g1per[256];
		sprintf(g1per,"%i",gpg1perfect);
		g1perfect.load(g1per,"grade.ttf",255,255,255,40);
		g1perfect.draw(left,484+bot,0,255,255,255,255,false,true,false);
		static drawtext g1great;
		static char g1gre[256];
		sprintf(g1gre,"%i",gpg1great);
		g1great.load(g1gre,"grade.ttf",255,255,255,40);
		g1great.draw(left,440+bot,0,255,255,255,255,false,true,false);
		static drawtext g1good;
		static char g1goo[256];
		sprintf(g1goo,"%i",gpg1good);
		g1good.load(g1goo,"grade.ttf",255,255,255,40);
		g1good.draw(left,396+bot,0,255,255,255,255,false,true,false);
		static drawtext g1almost;
		static char g1alm[256];
		sprintf(g1alm,"%i",gpg1almost);
		g1almost.load(g1alm,"grade.ttf",255,255,255,40);
		g1almost.draw(left,352+bot,0,255,255,255,255,false,true,false);
		static drawtext g1miss;
		static char g1mis[256];
		sprintf(g1mis,"%i",gpg1miss);
		g1miss.load(g1mis,"grade.ttf",255,255,255,40);
		g1miss.draw(left,308+bot,0,255,255,255,255,false,true,false);
		static drawtext g1total;
		static char g1tot[256];
		sprintf(g1tot,"%i",gpg1total);
		g1total.load(g1tot,"grade.ttf",255,255,255,40);
		g1total.draw(left,264+bot,0,255,255,255,255,false,true,false);
		static drawtext g1maxcombo;
		static char g1max[256];
		if (gpg1maxcombo==gpg1total){
			sprintf(g1max,"%i*",gpg1maxcombo);
			if (currscreen!=prevscreen)playsound(16,"fullcombo.wav");
		}else{
			sprintf(g1max,"%i",gpg1maxcombo);
		}
		g1maxcombo.load(g1max,"grade.ttf",255,255,255,40);
		g1maxcombo.draw(left,220+bot,0,255,255,255,255,false,true,false);
		static drawtext g1bonus;
		static char g1bon[256];
		sprintf(g1bon,"%i",gpg1bonus);
		g1bonus.load(g1bon,"grade.ttf",255,255,255,40);
		g1bonus.draw(left-190,132+bot,0,255,255,255,255,false,true,false);
		static drawtext g1score;
		static char g1sco[256];
		sprintf(g1sco,"%i",gpg1score);
		g1score.load(g1sco,"grade.ttf",255,255,255,40);
		g1score.draw(left-190,44+bot,0,255,255,255,255,false,true,false);
		static drawtext g1tscore;
		static char g1tsc[256];
		sprintf(g1tsc,"%i",gpg1tscore);
		g1tscore.load(g1tsc,"grade.ttf",255,255,255,40);
		g1tscore.draw(left-190,518+bot,100,255,255,255,255,false,true,false);
		static drawtext g1lettergrade;
		static char g1letgrade[256];
		if (currscreen!=prevscreen){
			if ((gpg1perfect+gpg1great+gpg1good)<=(.75*gpg1total)){
				sprintf(g1letgrade,"F");
				g1lettergrade.load(g1letgrade,"grade.ttf",128,0,0,120);
			}
			if ((gpg1perfect+gpg1great+gpg1good)>(.8*gpg1total)){
				sprintf(g1letgrade,"D");
				g1lettergrade.load(g1letgrade,"grade.ttf",0,192,0,120);
			}
			if ((gpg1perfect+gpg1great+gpg1good)>(.85*gpg1total)){
				sprintf(g1letgrade,"C");
				g1lettergrade.load(g1letgrade,"grade.ttf",0,0,255,120);
			}
			if ((gpg1perfect+gpg1great+gpg1good)>(.9*gpg1total)){
				sprintf(g1letgrade,"B");
				g1lettergrade.load(g1letgrade,"grade.ttf",255,192,0,120);
			}
			if ((gpg1perfect+gpg1great+gpg1good)>(.95*gpg1total)){
				sprintf(g1letgrade,"A");
				g1lettergrade.load(g1letgrade,"grade.ttf",255,0,255,120);
			}
			if ((gpg1perfect+gpg1great+gpg1good)==gpg1total){
				sprintf(g1letgrade,"S");
				g1lettergrade.load(g1letgrade,"grade.ttf",255,255,0,120);
			}
			if ((gpg1perfect+gpg1great)==gpg1total){
				sprintf(g1letgrade,"SS");
				g1lettergrade.load(g1letgrade,"grade.ttf",255,255,128,120);
			}
			if (gpg1perfect==gpg1total){
				sprintf(g1letgrade,"SSS");
				g1lettergrade.load(g1letgrade,"grade.ttf",255,255,255,120);
			}
		}
		g1lettergrade.draw(left-80,578+bot,5,128,128,128,255,false,true,false);
		g1lettergrade.draw(left-90,588+bot,10,255,255,255,255,false,true,false);
	}
	if (guitar2mode){
		bot=uivars.result_bottomg2;
		left=uivars.result_leftg2;
		static drawtext g2perfect;
		static char g2per[256];
		sprintf(g2per,"%i",gpg2perfect);
		g2perfect.load(g2per,"grade.ttf",255,255,255,40);
		g2perfect.draw(left,484+bot,0,255,255,255,255,false,true,false);
		static drawtext g2great;
		static char g2gre[256];
		sprintf(g2gre,"%i",gpg2great);
		g2great.load(g2gre,"grade.ttf",255,255,255,40);
		g2great.draw(left,440+bot,0,255,255,255,255,false,true,false);
		static drawtext g2good;
		static char g2goo[256];
		sprintf(g2goo,"%i",gpg2good);
		g2good.load(g2goo,"grade.ttf",255,255,255,40);
		g2good.draw(left,396+bot,0,255,255,255,255,false,true,false);
		static drawtext g2almost;
		static char g2alm[256];
		sprintf(g2alm,"%i",gpg2almost);
		g2almost.load(g2alm,"grade.ttf",255,255,255,40);
		g2almost.draw(left,352+bot,0,255,255,255,255,false,true,false);
		static drawtext g2miss;
		static char g2mis[256];
		sprintf(g2mis,"%i",gpg2miss);
		g2miss.load(g2mis,"grade.ttf",255,255,255,40);
		g2miss.draw(left,308+bot,0,255,255,255,255,false,true,false);
		static drawtext g2total;
		static char g2tot[256];
		sprintf(g2tot,"%i",gpg2total);
		g2total.load(g2tot,"grade.ttf",255,255,255,40);
		g2total.draw(left,264+bot,0,255,255,255,255,false,true,false);
		static drawtext g2maxcombo;
		static char g2max[256];
		if (gpg2maxcombo==gpg2total){
			sprintf(g2max,"%i*",gpg2maxcombo);
			if (currscreen!=prevscreen)playsound(16,"fullcombo.wav");
		}else{
			sprintf(g2max,"%i",gpg2maxcombo);
		}
		g2maxcombo.load(g2max,"grade.ttf",255,255,255,40);
		g2maxcombo.draw(left,220+bot,0,255,255,255,255,false,true,false);
		static drawtext g2bonus;
		static char g2bon[256];
		sprintf(g2bon,"%i",gpg2bonus);
		g2bonus.load(g2bon,"grade.ttf",255,255,255,40);
		g2bonus.draw(left-190,132+bot,0,255,255,255,255,false,true,false);
		static drawtext g2score;
		static char g2sco[256];
		sprintf(g2sco,"%i",gpg2score);
		g2score.load(g2sco,"grade.ttf",255,255,255,40);
		g2score.draw(left-190,44+bot,0,255,255,255,255,false,true,false);
		static drawtext g2tscore;
		static char g2tsc[256];
		sprintf(g2tsc,"%i",gpg2tscore);
		g2tscore.load(g2tsc,"grade.ttf",255,255,255,40);
		g2tscore.draw(left-190,518+bot,100,255,255,255,255,false,true,false);
		static drawtext g2lettergrade;
		static char g2letgrade[256];
		if (currscreen!=prevscreen){
			if ((gpg2perfect+gpg2great+gpg2good)<=(.75*gpg2total)){
				sprintf(g2letgrade,"F");
				g2lettergrade.load(g2letgrade,"grade.ttf",128,0,0,120);
			}
			if ((gpg2perfect+gpg2great+gpg2good)>(.8*gpg2total)){
				sprintf(g2letgrade,"D");
				g2lettergrade.load(g2letgrade,"grade.ttf",0,192,0,120);
			}
			if ((gpg2perfect+gpg2great+gpg2good)>(.85*gpg2total)){
				sprintf(g2letgrade,"C");
				g2lettergrade.load(g2letgrade,"grade.ttf",0,0,255,120);
			}
			if ((gpg2perfect+gpg2great+gpg2good)>(.9*gpg2total)){
				sprintf(g2letgrade,"B");
				g2lettergrade.load(g2letgrade,"grade.ttf",255,192,0,120);
			}
			if ((gpg2perfect+gpg2great+gpg2good)>(.95*gpg2total)){
				sprintf(g2letgrade,"A");
				g2lettergrade.load(g2letgrade,"grade.ttf",255,0,255,120);
			}
			if ((gpg2perfect+gpg2great+gpg2good)==gpg2total){
				sprintf(g2letgrade,"S");
				g2lettergrade.load(g2letgrade,"grade.ttf",255,255,0,120);
			}
			if ((gpg2perfect+gpg2great)==gpg2total){
				sprintf(g2letgrade,"SS");
				g2lettergrade.load(g2letgrade,"grade.ttf",255,255,128,120);
			}
			if (gpg2perfect==gpg2total){
				sprintf(g2letgrade,"SSS");
				g2lettergrade.load(g2letgrade,"grade.ttf",255,255,255,120);
			}
		}
		g2lettergrade.draw(left-80,578+bot,5,128,128,128,255,false,true,false);
		g2lettergrade.draw(left-90,588+bot,10,255,255,255,255,false,true,false);
	}
	//text(possible from .ini file?)
	if (!screenfaddingin&&!screenfaddingout){	
		static char text1[20];
		sprintf(text1,"Game Results for This Stage");
		static drawtext text1t;
		text1t.load(text1,"font.ttf",255,255,255,uivars.result_screenname_s);
		text1t.draw(uivars.result_screenname_x,uivars.result_screenname_y,5100,255,255,255,255,false,true);
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
				if (currstage<=stages){
					nextscreen=5;
				}else{
					if (stages!=0)
						nextscreen=13;
					else
						nextscreen=5;
				}
				screenfaddingout=true;
				screenchangenow=false;
				screenfaddingin=false;
			}
		}
	}
}
