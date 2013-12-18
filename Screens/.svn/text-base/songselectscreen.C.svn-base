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
//Songselection!:
void songselectscreen(int totalframes){
	#ifdef EXCESSIVE
	printf("songselectscreen\n");
	#endif
	if (currscreen!=prevscreen){
		jukeboxmode=false;
		if (prevscreen<5){
            prevlistmode=listmode-1;
			optionselected=1;
			catselected=0;
			sssloptionselected=0;
			prevsongselected=-1;
		}else{
			optionselected=sssloptionselected;
		}
	}
	if (prevlistmode!=listmode){
		genlist();
	}
	if (currscreen!=prevscreen){
		if (prevscreen<5){
			songselected=
            currsongloaded=songselected;
            lastsongloaded=currsongloaded;
			thesong=lastsongloaded;
			loadlisttext();
			playpreview();
		}
		songs[0].reloadsong();
		if (prevscreen==4){
			drumnotespeed=notespeed;
			guitar1notespeed=notespeed;
			guitar2notespeed=notespeed;
		}
		if (thesong>-1){
			if(prevscreen>5)playpreview();
		}
		playsound(15,"selectmusic.wav");
	}
 	prevlistmode=listmode;
	gpscore=0;
	gpg1score=0;
	gpg2score=0;
	gplifebar=50;
	gpg1lifebar=50;
	gpg2lifebar=50;
	static char previewfile[256];
	static drawtext bpmtext;
	static drawtext artisttext;
	static char det[256]="--";
	static char dat[256]="--";
	static char dbt[256]="--";
	static char get[256]="--";
	static char gat[256]="--";
	static char gbt[256]="--";
	static char bet[256]="--";
	static char bat[256]="--";
	static char bbt[256]="--";
	static char bpmt[256];
	static char artistt[256];
	static drawtext detext;
	static drawtext datext;
	static drawtext dbtext;
	static drawtext getext;
	static drawtext gatext;
	static drawtext gbtext;
	static drawtext betext;
	static drawtext batext;
	static drawtext bbtext;
	static drawtext marmottext[30];
	char marmott[30][256];
	static bool hasavi=true;
	static double anistep=0;
	if (screenfaddingin==true&&lastscreen==4)
		gameselectscreen(totalframes);
	if (screenfaddingout==true&&nextscreen==4)
		gameselectscreen(totalframes);
	if (!screenfaddingin&&!screenfaddingout)
		draw_quad(0,512,384,1000,640,400,255,255,255,255,0,0,14);
	if ((lastscreen==6||nextscreen==6||lastscreen==12)&&nextscreen!=4){
		draw_quad(0,512,384,1000,640,400,255,255,255,255,0,0,14);
	}
	if (upanimation){
		anistep+=20.0*double(steptime)/16.0;
		if (holdtime>10)
			anistep+=30*double(steptime)/16.0;
		if (anistep>80){
			optionselected++;
			upanimation=false;
			anistep=0;
			if(currscreen!=6)playsound(2,"selection.wav");
			holdtime++;
			jukeboxmode=false;
		}
	}
	if (downanimation){
		anistep-=20*double(steptime)/16.0;
		if (holdtime>10)
			anistep-=30*double(steptime)/16.0;
		if (anistep<-80){
			optionselected--;
			downanimation=false;
			anistep=0;
			if(currscreen!=6)playsound(2,"selection.wav");
			holdtime++;
			jukeboxmode=false;
		}
	}
	//FPS:260,
	if (!upanimation&&!downanimation){
		beenidle+=double(steptime)/16.0;
	}else{
		beenidle=0;
	}
	if (beenidle>1){
		holdtime=0;
	}
	if ((!screenfaddingin&&!screenfaddingout)||((lastscreen==6||nextscreen==6)&&nextscreen!=4)){
		if (songselected!=prevsongselected){
			currsongloaded=songselected;
		}
		if (beenidle<8)
			okaytodraw=false;
		if (newsong){
			if (!jukeboxmode)
				playpreview();
			else
				playpreview(true);
		}
		if (jukeboxmode&&thesong>-1){
			currbpm=songs[thesong].origbpm;
			if (currbpm==0)
				currbpm=150;
			playrender();
			if ( songposition > ((songs[thesong].highestmeasure+3)*240000)){
				srand(SDL_GetTicks());
				catselected=int(((double)rand()/(double)RAND_MAX)*(double)curcatcount);
				if (catselected>=curcatcount)catselected=curcatcount-1;
				if (catselected<0)catselected=0;
				optionselected=int( ((double)rand()/(double)RAND_MAX)*(double)curcatsongcount[catselected]);
				if (optionselected>curcatsongcount[catselected])optionselected=curcatsongcount[catselected];
				if (optionselected<1)optionselected=1;
				playsound(2,"selection.wav");
				catchangewait=1000;
				songs[thesong].resetplayed();
			}
		}
		if (lastsongloaded!=currsongloaded){
			okaytoload=true;
			if (beenidle<20)
				okaytoload=false;
		}else{
			okaytoload=false;
		}
		okaytodraw=true;
		if (okaytoload){
			lastsongloaded=currsongloaded;
			thesong=lastsongloaded;
		}
		if (okaytodraw){
			if (songselected>-1){
				//DRUM
				if (drumdiff==-1)drumdiff=0;
				if (songs[songselected].drumbasdiff>0){
					snprintf(dbt,255,"%i",songs[songselected].drumbasdiff);
					if(songs[songselected].drumbasdiff==101){
						snprintf(dbt,255,"?");
					}
				}else{
					if (drumdiff==0)drumdiff=1;
					snprintf(dbt,255,"--");
				}
				if (songs[songselected].drumextdiff<11&&songs[songselected].drumadvdiff<11&&songs[songselected].drumbasdiff<11&&strcmp(dbt,"--")!=0)
					snprintf(dbt,255,"%s*",dbt);
				dbtext.load(dbt,"impact.ttf",255,255,255,50);
				if (songs[songselected].drumadvdiff>0){
					snprintf(dat,255,"%i",songs[songselected].drumadvdiff);
					if(songs[songselected].drumadvdiff==101){
						snprintf(dat,255,"?");
					}
				}else{
					if (drumdiff==1)drumdiff=2;
					snprintf(dat,255,"--");
				}
				if (songs[songselected].drumextdiff<11&&songs[songselected].drumadvdiff<11&&songs[songselected].drumbasdiff<11&&strcmp(dat,"--")!=0)
					snprintf(dat,255,"%s*",dat);
				datext.load(dat,"impact.ttf",255,255,255,50);
				if (songs[songselected].drumextdiff>0){
					snprintf(det,255,"%i",songs[songselected].drumextdiff);
					if(songs[songselected].drumextdiff==101){
						snprintf(det,255,"?");
					}
				}else{
					if (drumdiff==2){
						if (songs[songselected].drumadvdiff>0){
							drumdiff=1;
						}else if(songs[songselected].drumbasdiff>0){
							drumdiff=0;
						}else{
							drumdiff=-1;
						}
					}
					snprintf(det,255,"--");
				}
				if (songs[songselected].drumextdiff<11&&songs[songselected].drumadvdiff<11&&songs[songselected].drumbasdiff<11&&strcmp(det,"--")!=0)
					snprintf(det,255,"%s*",det);
				detext.load(det,"impact.ttf",255,255,255,50);
				//BASS
				if (songs[songselected].guitbbasdiff>0){
					snprintf(bbt,255,"%i",songs[songselected].guitbbasdiff);
					if(songs[songselected].guitbbasdiff==101){
						snprintf(bbt,255,"?");
					}
				}else{
					snprintf(bbt,255,"--");
					if (guitar1treb==false&&guit1diff==0)
						guitar1treb=true;
					if (guitar2treb==false&&guit2diff==0)
						guitar2treb=true;
				}
				if (songs[songselected].guitbextdiff<11&&songs[songselected].guitbadvdiff<11&&songs[songselected].guitbbasdiff<11&&strcmp(bbt,"--")!=0)
					snprintf(bbt,255,"%s*",bbt);
				bbtext.load(bbt,"impact.ttf",255,255,255,50);
				if (songs[songselected].guitbadvdiff>0){
					snprintf(bat,255,"%i",songs[songselected].guitbadvdiff);
					if(songs[songselected].guitbadvdiff==101){
						snprintf(bat,255,"?");
					}
				}else{
					snprintf(bat,255,"--");
					if (guitar1treb==false&&guit1diff==1)
						guitar1treb=true;
					if (guitar2treb==false&&guit2diff==1)
						guitar2treb=true;
				}
				if (songs[songselected].guitbextdiff<11&&songs[songselected].guitbadvdiff<11&&songs[songselected].guitbbasdiff<11&&strcmp(bat,"--")!=0)
					snprintf(bat,255,"%s*",bat);
				batext.load(bat,"impact.ttf",255,255,255,50);
				if (songs[songselected].guitbextdiff>0){
					snprintf(bet,255,"%i",songs[songselected].guitbextdiff);
					if(songs[songselected].guitbextdiff==101){
						snprintf(bet,255,"?");
					}
				}else{
					snprintf(bet,255,"--");
					if (guitar1treb==false&&guit1diff==2)
						guitar1treb=true;
					if (guitar2treb==false&&guit2diff==2)
						guitar2treb=true;
				}
				if (songs[songselected].guitbextdiff<11&&songs[songselected].guitbadvdiff<11&&songs[songselected].guitbbasdiff<11&&strcmp(bet,"--")!=0)
					snprintf(bet,255,"%s*",bet);
				betext.load(bet,"impact.ttf",255,255,255,50);
				//GUITAR
				if (guit1diff==-1)
					guit1diff=0;
				if (guit2diff==-1)
					guit2diff=0;
				if (songs[songselected].guitbasdiff>0){
					snprintf(gbt,255,"%i",songs[songselected].guitbasdiff);
					if(songs[songselected].guitbasdiff==101){
						snprintf(gbt,255,"?");
					}
				}else{
					snprintf(gbt,255,"--");
					if (guit1diff==0)guit1diff=1;
					if (guit2diff==0)guit2diff=1;
				}
				if (songs[songselected].guitextdiff<11&&songs[songselected].guitadvdiff<11&&songs[songselected].guitbasdiff<11&&strcmp(gbt,"--")!=0)
					snprintf(gbt,255,"%s*",gbt);
				gbtext.load(gbt,"impact.ttf",255,255,255,50);
				if (songs[songselected].guitadvdiff>0){
					snprintf(gat,255,"%i",songs[songselected].guitadvdiff);
					if(songs[songselected].guitadvdiff==101){
						snprintf(gat,255,"?");
					}
				}else{
					if (guit1diff==1)guit1diff=2;
					if (guit2diff==1)guit2diff=2;
					snprintf(gat,255,"--");
				}
				if (songs[songselected].guitextdiff<11&&songs[songselected].guitadvdiff<11&&songs[songselected].guitbasdiff<11&&strcmp(gat,"--")!=0)
					snprintf(gat,255,"%s*",gat);
				gatext.load(gat,"impact.ttf",255,255,255,50);
				if (songs[songselected].guitextdiff>0){
					snprintf(get,255,"%i",songs[songselected].guitextdiff);
					if(songs[songselected].guitextdiff==101){
						snprintf(get,255,"?");
					}
				}else{
					snprintf(get,255,"--");
					if (guit1diff==2){
						if (songs[songselected].guitadvdiff>0){
							guit1diff=1;
						}else if(songs[songselected].guitbasdiff>0){
							guit1diff=0;
						}else{
							guit1diff=-1;
						}
					}
					if (guit2diff==2){
						if (songs[songselected].guitadvdiff>0){
							guit2diff=1;
						}else if(songs[songselected].guitbasdiff>0){
							guit2diff=0;
						}else{
							guit2diff=-1;
						}
					}
				}
				if (songs[songselected].guitextdiff<11&&songs[songselected].guitadvdiff<11&&songs[songselected].guitbasdiff<11&&strcmp(get,"--")!=0)
					snprintf(get,255,"%s*",get);
				getext.load(get,"impact.ttf",255,255,255,50);
				snprintf(bpmt,255,"%i BPM",songs[songselected].bpm);
				snprintf(artistt,255,"%s",songs[songselected].artist);
				bpmtext.load(bpmt,"impact.ttf",255,255,255,uivars.song_bpmtext_s);
				artisttext.load(artistt,"unicode.ttf",128,128,255,uivars.song_artitist_s);
				static int pss=-10;
				if (pss!=songselected){
					//if (artisttext!=NULL)artisttext->unloadmemory();
					//artisttext=songs[songselected].artitt;
					//if (artisttext!=NULL)artisttext->loadmemory();
				}
				pss=songselected;
			}else{
				drumdiff=-1;
				guit1diff=-1;
				guit2diff=-1;
			}
		}
		draw_quad(0,uivars.song_selector_x+260+40+int((anistep/80.0)*10.0),uivars.song_selector_y-506+685+int(anistep/3),1050,335,50,255,255,255,255,0,0,16);
		draw_quad(0,uivars.song_selector_x+260+30+int((anistep/80.0)*10.0),uivars.song_selector_y-506+650+int(anistep/3),1075,335,50,255,255,255,255,0,0,16);
		draw_quad(0,uivars.song_selector_x+260+20+int((anistep/80.0)*10.0),uivars.song_selector_y-506+615+int(anistep/3),1100,335,50,255,255,255,255,0,0,16);
		draw_quad(0,uivars.song_selector_x+260+10+int((anistep/80.0)*10.0),uivars.song_selector_y-506+580+int(anistep/3),1150,335,50,255,255,255,255,0,0,16);
		if (downanimation){ draw_quad(0,uivars.song_selector_x+260-abs(int(anistep*.625)),uivars.song_selector_y-506+545+int(anistep/3),1200,335,50,255,255,255,255,0,0,16);}
		else{ draw_quad(0,uivars.song_selector_x+260+int((anistep/80.0)*10.0),uivars.song_selector_y-506+545+int(anistep/3),1200,335,50,255,255,255,255,0,0,16);}
		if (upanimation){ draw_quad(0,uivars.song_selector_x+260-abs(int((anistep/3)*.625)),uivars.song_selector_y-506+475+int(anistep/3),1250,335,50,255,255,255,255,0,0,16);}
		else{ draw_quad(0,uivars.song_selector_x+260+int(-(anistep/80.0)*10.0),uivars.song_selector_y-506+475+int(anistep/3),1250,335,50,255,255,255,255,0,0,16);}
		draw_quad(0,uivars.song_selector_x+260+10+int(-(anistep/80.0)*10.0),uivars.song_selector_y-506+440+int(anistep/3),1300,335,50,255,255,255,255,0,0,16);
		draw_quad(0,uivars.song_selector_x+260+20+int(-(anistep/80.0)*10.0),uivars.song_selector_y-506+405+int(anistep/3),1350,335,50,255,255,255,255,0,0,16);
		draw_quad(0,uivars.song_selector_x+260+30+int(-(anistep/80.0)*10.0),uivars.song_selector_y-506+370+int(anistep/3),1400,335,50,255,255,255,255,0,0,16);
		if (!downanimation)draw_quad(0,uivars.song_selector_x+260+40+int(-(anistep/80.0)*10.0),uivars.song_selector_y-506+335+int(anistep/3),1450,335,50,255,255,255,255,0,0,16);
		else draw_quad(0,uivars.song_selector_x+260+40+int(-(anistep/80.0)*10.0),uivars.song_selector_y-506+335+int(anistep/3),1450,335,50,255,255,255,255-abs(int(anistep*3.1875)),0,0,16);
		if (upanimation)draw_quad(0,uivars.song_selector_x+260+50+int(-(anistep/80.0)*10.0),uivars.song_selector_y-506+300+int(anistep/3),1500,335,50,255,255,255,abs(int(anistep*3.1875)),0,0,16);
		draw_quad(0,uivars.song_selector_x+190+abs(int(anistep*.625)),uivars.song_selector_y-506+510+int(anistep/3),1500,335,50,255,255,255,255,0,0,15);
		
		//the new list thingy.
		loadlisttext();
		songtext[5].draw(uivars.song_selector_x+10-80+abs(int(anistep*.625)),uivars.song_selector_y-4+int(anistep/4),3000,255,255,255,255,true,true);
		if (downanimation){
			songtext[6].draw(uivars.song_selector_x+10-abs(int(anistep*.625)),uivars.song_selector_y+int(anistep/3)+35,3100,255,255,255,255,false,true);
		}else {
			songtext[6].draw(uivars.song_selector_x+10,uivars.song_selector_y+int(anistep/3)+35,3100,255,255,255,255,false,true);
		}
		if (upanimation){
			songtext[4].draw(uivars.song_selector_x+10-abs(int(anistep*.625)),uivars.song_selector_y+int(anistep/3)-35,3200,255,255,255,255,false,true);
		}else{
			songtext[4].draw(uivars.song_selector_x+10,uivars.song_selector_y+int(anistep/3)-35,3200,255,255,255,255,false,true);
		}
		songtext[7].draw(uivars.song_selector_x+10+10+int((anistep/80.0)*10.0),uivars.song_selector_y+int(anistep/3)+70,3300,255,255,255,255,false,true);
		songtext[3].draw(uivars.song_selector_x+10+10+int(-(anistep/80.0)*10.0),uivars.song_selector_y+int(anistep/3)-70,3300,255,255,255,255,false,true);
		songtext[8].draw(uivars.song_selector_x+10+20+int((anistep/80.0)*10.0),uivars.song_selector_y+int(anistep/3)+105,3400,255,255,255,255,false,true);
		songtext[2].draw(uivars.song_selector_x+10+20+int(-(anistep/80.0)*10.0),uivars.song_selector_y+int(anistep/3)-105,3400,255,255,255,255,false,true);
		songtext[9].draw(uivars.song_selector_x+10+30+int((anistep/80.0)*10.0),uivars.song_selector_y+int(anistep/3)+140,3500,255,255,255,255,false,true);
		songtext[1].draw(uivars.song_selector_x+10+30+int(-(anistep/80.0)*10.0),uivars.song_selector_y+int(anistep/3)-140,3500,255,255,255,255,false,true);
		if (upanimation){   
			songtext[10].draw(uivars.song_selector_x+10+40+int((anistep/80.0)*10.0),uivars.song_selector_y+int(anistep/3)+175,3600,255-abs(int(anistep*3.1875)),255,255,255,false,true);
			songtext[0].draw(uivars.song_selector_x+10+40+int(-(anistep/80.0)*10.0),uivars.song_selector_y+int(anistep/3)-175,3600,abs(int(anistep*3.1875)),255,255,255,false,true);
		}
		if (downanimation){
			songtext[10].draw(uivars.song_selector_x+10+40+int((anistep/80.0)*10.0),uivars.song_selector_y+int(anistep/3)+175,3600,abs(int(anistep*3.1875)),255,255,255,false,true);
			songtext[0].draw(uivars.song_selector_x+10+40+int(-(anistep/80.0)*10.0),uivars.song_selector_y+int(anistep/3)-175,3600,255-abs(int(anistep*3.1875)),255,255,255,false,true);
		}
		if (!upanimation&&!downanimation){
			songtext[10].draw(uivars.song_selector_x+10+40+int((anistep/80.0)*10.0),uivars.song_selector_y+int(anistep/3)+175,3600,255,255,255,255,false,true);
			songtext[0].draw(uivars.song_selector_x+10+40+int(-(anistep/80.0)*10.0),uivars.song_selector_y+int(anistep/3)-175,3600,255,255,255,255,false,true);
		}
		if (!jukeboxmode){
			draw_quadt2(0,uivars.song_previewimage_x,uivars.song_previewimage_y,3000,103,136,255,255,255,255,0,0,previewtexture);
		}else{
			if (songposition>0){
				if(!screenfaddingin&&!screenfaddingout){
					if (gpavi.isloaded()){
						gpavi.drawavi(uivars.song_previewimage_x,uivars.song_previewimage_y,3000,103,136);
					}else{
						draw_quadt2(0,uivars.song_previewimage_x,uivars.song_previewimage_y,3000,103,136,255,255,255,255,0,0,previewtexture);	
					}
				}
			}else{
				draw_quadt2(0,uivars.song_previewimage_x,uivars.song_previewimage_y,3000,103,136,255,255,255,255,0,0,previewtexture);
			}
		}
		dbtext.draw(uivars.song_difficulties_x,uivars.song_difficulties_y+180,2000,255,255,255,255,false,true);
		datext.draw(uivars.song_difficulties_x,uivars.song_difficulties_y+90,2100,255,255,255,255,false,true);
		detext.draw(uivars.song_difficulties_x,uivars.song_difficulties_y,2200,255,255,255,255,false,true);
		gbtext.draw(uivars.song_difficulties_x+100,uivars.song_difficulties_y+180,2000,255,255,255,255,false,true);
		gatext.draw(uivars.song_difficulties_x+100,uivars.song_difficulties_y+90,2100,255,255,255,255,false,true);
		getext.draw(uivars.song_difficulties_x+100,uivars.song_difficulties_y,2200,255,255,255,255,false,true);
		bbtext.draw(uivars.song_difficulties_x+200,uivars.song_difficulties_y+180,2000,255,255,255,255,false,true);
		batext.draw(uivars.song_difficulties_x+200,uivars.song_difficulties_y+90,2100,255,255,255,255,false,true);
		betext.draw(uivars.song_difficulties_x+200,uivars.song_difficulties_y,2200,255,255,255,255,false,true);
		//bpmtext.draw(uivars.song_bpmtext_x,uivars.song_bpmtext_y,2000,255,255,255,255,false,true);
		//if (artisttext!=NULL)artisttext->draw(uivars.song_artitist_x,uivars.song_artitist_y,2000,255,255,255,255,false,true);
		if (!arcademode){
			if (jukeboxmode)
				snprintf(marmott[1],255,"Jukebox mode: on (F6)");
			else
				snprintf(marmott[1],255,"Jukebox mode: off (F6)");
		}else{
			snprintf(marmott[1],255,"Player Configuration:");
		}
		if (jukeboxmode){
			marmottext[1].load(marmott[1],"font.ttf",0,0,255,40);
		}else{
			marmottext[1].load(marmott[1],"font.ttf",128,128,255,40);
		}
		marmottext[1].draw(uivars.song_options_x,uivars.song_options_y+175,2000,255,255,255,255,false,true);
		snprintf(marmott[2],255,"Random (ht, ht or g,p,p,g) - Category (sn+lt or r+b)");
		marmottext[2].load(marmott[2],"font.ttf",255,255,255,20);
		marmottext[2].draw(uivars.song_options_x,uivars.song_options_y+150,2000,255,255,255,255,false,true);
		int tablex=uivars.song_options_x+130;
		int tabley=uivars.song_options_y+120;
		snprintf(marmott[9],255,"(drum)-  (g1) -  (g2)");
		marmottext[9].load(marmott[9],"font.ttf",255,255,255,uivars.song_options_s);
		marmottext[9].draw(tablex-22,tabley+9,2000,255,255,255,255,false,true);
		
		//non standard table text
		snprintf(marmott[3],255,"Note Speed");
		marmottext[3].load(marmott[3],"font.ttf",255,255,255,uivars.song_options_s);
		marmottext[3].draw(uivars.song_options_x,tabley-9,2000,255,255,255,255,false,true);
		snprintf(marmott[4],255,"Reg/Alt Notes");
		marmottext[4].load(marmott[4],"font.ttf",255,255,255,uivars.song_options_s);
		marmottext[4].draw(uivars.song_options_x,tabley-27,2000,255,255,255,255,false,true);
		snprintf(marmott[5],255,"Fade Notes");
		marmottext[5].load(marmott[5],"font.ttf",255,255,255,uivars.song_options_s);
		marmottext[5].draw(uivars.song_options_x,tabley-45,2000,255,255,255,255,false,true);
		snprintf(marmott[6],255,"Random Notes");
		marmottext[6].load(marmott[6],"font.ttf",255,255,255,uivars.song_options_s);
		marmottext[6].draw(uivars.song_options_x,tabley-63,2000,255,255,255,255,false,true);
		snprintf(marmott[7],255,"Spin Notes");
		marmottext[7].load(marmott[7],"font.ttf",255,255,255,uivars.song_options_s);
		marmottext[7].draw(uivars.song_options_x,tabley-81,2000,255,255,255,255,false,true);
		snprintf(marmott[8],255,"Difficulty");
		marmottext[8].load(marmott[8],"font.ttf",255,255,255,uivars.song_options_s);
		marmottext[8].draw(uivars.song_options_x,tabley-99,2000,255,255,255,255,false,true);

		if (drummode){
			//drum table
			if (drumnotespeed<10){
				draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,0);
			}else if(drumnotespeed==10){
				draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,1);
			}else if(drumnotespeed>10&&drumnotespeed<100){
				draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,2);
			}else if(drumnotespeed>=100&&drumnotespeed<200){
				draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,3);
			}else if(drumnotespeed==200){
				draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,4);
			}
			draw_quad_frame(0,tablex,tabley-18,2000,22,9,255,255,255,255,0,0,65,1);
			if (drumfademode==0)
				draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,1);
			if (drumfademode==1||drumfademode==2)
				draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,2);
			if (drumfademode==3)
				draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,3);
			if (!drumrandommode)
				draw_quad_frame(0,tablex,tabley-54,2000,22,9,255,255,255,255,0,0,65,1);
			else
				draw_quad_frame(0,tablex,tabley-54,2000,22,9,255,255,255,255,0,0,65,3);
			if (!drumspin)
				draw_quad_frame(0,tablex,tabley-72,2000,22,9,255,255,255,255,0,0,65,1);
			else
				draw_quad_frame(0,tablex,tabley-72,2000,22,9,255,255,255,255,0,0,65,3);		
			if (drumdiff==-1)
				draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,0);
			if (drumdiff==0)
				draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,1);
			if (drumdiff==1)
				draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,2);
			if (drumdiff==2)
				draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,3);
			//drum table text	
			static drawtext drumns;
			static drawtext drumas;
			static drawtext drumfm;
			static drawtext drumrm;
			static drawtext drumsm;
			static drawtext drumdf;
			static char drumnstext[7];
			static char drumastext[7];
			static char drumfmtext[7];
			static char drumrmtext[7];
			static char drumsmtext[7];
			static char drumdftext[7];
			if (drumnotespeed<100){
				snprintf(drumnstext,6,"0%.1fx",double(drumnotespeed)/10.0);
			}else{
				snprintf(drumnstext,6,"%.1fx",double(drumnotespeed)/10.0);
			}
			snprintf(drumastext,6,"Norml");
			if (drumfademode==0)
				snprintf(drumfmtext,6,"NoFad");
			if (drumfademode==1)
				snprintf(drumfmtext,6,"F-Out");
			if (drumfademode==2)
				snprintf(drumfmtext,6,"F-In");
			if (drumfademode==3)
				snprintf(drumfmtext,6,"FBoth");
			if (drumrandommode)
				snprintf(drumrmtext,6,"RandN");
			else
				snprintf(drumrmtext,6,"Norml");
			if (drumspin)
				snprintf(drumsmtext,6,"SpinM");
			else
				snprintf(drumsmtext,6,"Norml");
			if (drumdiff<0||drumdiff>2)
				snprintf(drumdftext,6," N/A ");
			if (drumdiff==0)
				snprintf(drumdftext,6," Std ");
			if (drumdiff==1)
				snprintf(drumdftext,6," Adv ");
			if (drumdiff==2)
				snprintf(drumdftext,6," Ext ");
			drumns.load(drumnstext,"mono.ttf",255,255,255,12);
			drumas.load(drumastext,"mono.ttf",255,255,255,12);
			drumfm.load(drumfmtext,"mono.ttf",255,255,255,12);
			drumrm.load(drumrmtext,"mono.ttf",255,255,255,12);
			drumsm.load(drumsmtext,"mono.ttf",255,255,255,12);
			drumdf.load(drumdftext,"mono.ttf",255,255,255,12);
			drumns.draw(tablex-18,tabley-8,2010,255,255,255,255,false,true);
			drumas.draw(tablex-18,tabley-8-18,2010,255,255,255,255,false,true);
			drumfm.draw(tablex-18,tabley-8-36,2010,255,255,255,255,false,true);
			drumrm.draw(tablex-18,tabley-8-54,2010,255,255,255,255,false,true);
			drumsm.draw(tablex-18,tabley-8-72,2010,255,255,255,255,false,true);
			drumdf.draw(tablex-18,tabley-8-90,2010,255,255,255,255,false,true);
		}else{
			draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex,tabley-18,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex,tabley-54,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex,tabley-72,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,0);
		}
		
		if (guitar1mode){
			//guitar 1 table
			if (guitar1notespeed<10){
				draw_quad_frame(0,tablex+44,tabley,2000,22,9,255,255,255,255,0,0,65,0);
			}else if(guitar1notespeed==10){
				draw_quad_frame(0,tablex+44,tabley,2000,22,9,255,255,255,255,0,0,65,1);
			}else if(guitar1notespeed>10&&guitar1notespeed<100){
				draw_quad_frame(0,tablex+44,tabley,2000,22,9,255,255,255,255,0,0,65,2);
			}else if(guitar1notespeed>=100&&guitar1notespeed<200){
				draw_quad_frame(0,tablex+44,tabley,2000,22,9,255,255,255,255,0,0,65,3);
			}else if(guitar1notespeed==200){
				draw_quad_frame(0,tablex+44,tabley,2000,22,9,255,255,255,255,0,0,65,4);
			}
			if (guitar1treb)
				draw_quad_frame(0,tablex+44,tabley-18,2000,22,9,255,255,255,255,0,0,65,1);
			else
				draw_quad_frame(0,tablex+44,tabley-18,2000,22,9,255,255,255,255,0,0,65,2);
			if (guit1fademode==0)
				draw_quad_frame(0,tablex+44,tabley-36,2000,22,9,255,255,255,255,0,0,65,1);
			if (guit1fademode==1||guit1fademode==2)
				draw_quad_frame(0,tablex+44,tabley-36,2000,22,9,255,255,255,255,0,0,65,2);
			if (guit1fademode==3)
				draw_quad_frame(0,tablex+44,tabley-36,2000,22,9,255,255,255,255,0,0,65,3);
			if (!guit1randommode)
				draw_quad_frame(0,tablex+44,tabley-54,2000,22,9,255,255,255,255,0,0,65,1);
			else
				draw_quad_frame(0,tablex+44,tabley-54,2000,22,9,255,255,255,255,0,0,65,3);
			if (!guit1spin)
				draw_quad_frame(0,tablex+44,tabley-72,2000,22,9,255,255,255,255,0,0,65,1);
			else
				draw_quad_frame(0,tablex+44,tabley-72,2000,22,9,255,255,255,255,0,0,65,3);
			if (guit1diff==-1)
				draw_quad_frame(0,tablex+44,tabley-90,2000,22,9,255,255,255,255,0,0,65,0);
			if (guit1diff==0)
				draw_quad_frame(0,tablex+44,tabley-90,2000,22,9,255,255,255,255,0,0,65,1);
			if (guit1diff==1)
				draw_quad_frame(0,tablex+44,tabley-90,2000,22,9,255,255,255,255,0,0,65,2);
			if (guit1diff==2)
				draw_quad_frame(0,tablex+44,tabley-90,2000,22,9,255,255,255,255,0,0,65,3);
			//guitar 1 table text
			static drawtext guitar1ns;
			static drawtext guitar1as;
			static drawtext guitar1fm;
			static drawtext guitar1rm;
			static drawtext guitar1sm;
			static drawtext guitar1df;
			static char guitar1nstext[7];
			static char guitar1astext[7];
			static char guitar1fmtext[7];
			static char guitar1rmtext[7];
			static char guitar1smtext[7];
			static char guitar1dftext[7];
			if (guitar1notespeed<100){
				snprintf(guitar1nstext,6,"0%.1fx",double(guitar1notespeed)/10.0);
			}else{
				snprintf(guitar1nstext,6,"%.1fx",double(guitar1notespeed)/10.0);
			}
			if (guitar1treb)
				snprintf(guitar1astext,6,"Norml");
			else
				snprintf(guitar1astext,6," Alt ");
			if (guit1fademode==0)
				snprintf(guitar1fmtext,6,"NoFad");
			if (guit1fademode==1)
				snprintf(guitar1fmtext,6,"F-Out");
			if (guit1fademode==2)
				snprintf(guitar1fmtext,6,"F-In");
			if (guit1fademode==3)
				snprintf(guitar1fmtext,6,"FBoth");
			if (guit1randommode)
				snprintf(guitar1rmtext,6,"RandN");
			else
				snprintf(guitar1rmtext,6,"Norml");
			if (guit1spin)
				snprintf(guitar1smtext,6,"SpinM");
			else
				snprintf(guitar1smtext,6,"Norml");
			if (guit1diff<0||guit1diff>2)
				snprintf(guitar1dftext,6," N/A ");
			if (guit1diff==0)
				snprintf(guitar1dftext,6," Std ");
			if (guit1diff==1)
				snprintf(guitar1dftext,6," Adv ");
			if (guit1diff==2)
				snprintf(guitar1dftext,6," Ext ");
			guitar1ns.load(guitar1nstext,"mono.ttf",255,255,255,12);
			guitar1as.load(guitar1astext,"mono.ttf",255,255,255,12);
			guitar1fm.load(guitar1fmtext,"mono.ttf",255,255,255,12);
			guitar1rm.load(guitar1rmtext,"mono.ttf",255,255,255,12);
			guitar1sm.load(guitar1smtext,"mono.ttf",255,255,255,12);
			guitar1df.load(guitar1dftext,"mono.ttf",255,255,255,12);
			guitar1ns.draw(tablex-18+44,tabley-8,2010,255,255,255,255,false,true);
			guitar1as.draw(tablex-18+44,tabley-8-18,2010,255,255,255,255,false,true);
			guitar1fm.draw(tablex-18+44,tabley-8-36,2010,255,255,255,255,false,true);
			guitar1rm.draw(tablex-18+44,tabley-8-54,2010,255,255,255,255,false,true);
			guitar1sm.draw(tablex-18+44,tabley-8-72,2010,255,255,255,255,false,true);
			guitar1df.draw(tablex-18+44,tabley-8-90,2010,255,255,255,255,false,true);
		}else{
			draw_quad_frame(0,tablex+44,tabley,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex+44,tabley-18,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex+44,tabley-36,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex+44,tabley-54,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex+44,tabley-72,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex+44,tabley-90,2000,22,9,255,255,255,255,0,0,65,0);
		}
		
		if (guitar2mode){
			//guitar 2 table
			if (guitar2notespeed<10){
				draw_quad_frame(0,tablex+88,tabley,2000,22,9,255,255,255,255,0,0,65,0);
			}else if(guitar2notespeed==10){
				draw_quad_frame(0,tablex+88,tabley,2000,22,9,255,255,255,255,0,0,65,1);
			}else if(guitar2notespeed>10&&guitar2notespeed<100){
				draw_quad_frame(0,tablex+88,tabley,2000,22,9,255,255,255,255,0,0,65,2);
			}else if(guitar2notespeed>=100&&guitar2notespeed<200){
				draw_quad_frame(0,tablex+88,tabley,2000,22,9,255,255,255,255,0,0,65,3);
			}else if(guitar2notespeed==200){
				draw_quad_frame(0,tablex+88,tabley,2000,22,9,255,255,255,255,0,0,65,4);
			}
			if (guitar2treb)
				draw_quad_frame(0,tablex+88,tabley-18,2000,22,9,255,255,255,255,0,0,65,1);
			else
				draw_quad_frame(0,tablex+88,tabley-18,2000,22,9,255,255,255,255,0,0,65,2);
			if (guit2fademode==0)
				draw_quad_frame(0,tablex+88,tabley-36,2000,22,9,255,255,255,255,0,0,65,1);
			if (guit2fademode==1||guit2fademode==2)
				draw_quad_frame(0,tablex+88,tabley-36,2000,22,9,255,255,255,255,0,0,65,2);
			if (guit2fademode==3)
				draw_quad_frame(0,tablex+88,tabley-36,2000,22,9,255,255,255,255,0,0,65,3);
			if (!guit2randommode)
				draw_quad_frame(0,tablex+88,tabley-54,2000,22,9,255,255,255,255,0,0,65,1);
			else
				draw_quad_frame(0,tablex+88,tabley-54,2000,22,9,255,255,255,255,0,0,65,3);
			if (!guit2spin)
				draw_quad_frame(0,tablex+88,tabley-72,2000,22,9,255,255,255,255,0,0,65,1);
			else
				draw_quad_frame(0,tablex+88,tabley-72,2000,22,9,255,255,255,255,0,0,65,3);
			if (guit2diff==-1)
				draw_quad_frame(0,tablex+88,tabley-90,2000,22,9,255,255,255,255,0,0,65,0);
			if (guit2diff==0)
				draw_quad_frame(0,tablex+88,tabley-90,2000,22,9,255,255,255,255,0,0,65,1);
			if (guit2diff==1)
				draw_quad_frame(0,tablex+88,tabley-90,2000,22,9,255,255,255,255,0,0,65,2);
			if (guit2diff==2)
				draw_quad_frame(0,tablex+88,tabley-90,2000,22,9,255,255,255,255,0,0,65,3);
			//guitar 2 table text
			static drawtext guitar2ns;
			static drawtext guitar2as;
			static drawtext guitar2fm;
			static drawtext guitar2rm;
			static drawtext guitar2sm;
			static drawtext guitar2df;
			static char guitar2nstext[7];
			static char guitar2astext[7];
			static char guitar2fmtext[7];
			static char guitar2rmtext[7];
			static char guitar2smtext[7];
			static char guitar2dftext[7];
			if (guitar2notespeed<100){
				snprintf(guitar2nstext,6,"0%.1fx",double(guitar2notespeed)/10.0);
			}else{
				snprintf(guitar2nstext,6,"%.1fx",double(guitar2notespeed)/10.0);
			}
			if (guitar2treb)
				snprintf(guitar2astext,6,"Norml");
			else
				snprintf(guitar2astext,6," Alt ");
			if (guit2fademode==0)
				snprintf(guitar2fmtext,6,"NoFad");
			if (guit2fademode==1)
				snprintf(guitar2fmtext,6,"F-Out");
			if (guit2fademode==2)
				snprintf(guitar2fmtext,6,"F-In");
			if (guit2fademode==3)
				snprintf(guitar2fmtext,6,"FBoth");
			if (guit2randommode)
				snprintf(guitar2rmtext,6,"RandN");
			else
				snprintf(guitar2rmtext,6,"Norml");
			if (guit2spin)
				snprintf(guitar2smtext,6,"SpinM");
			else
				snprintf(guitar2smtext,6,"Norml");
			if (guit2diff<0||guit2diff>2)
				snprintf(guitar2dftext,6," N/A ");
			if (guit2diff==0)
				snprintf(guitar2dftext,6," Std ");
			if (guit2diff==1)
				snprintf(guitar2dftext,6," Adv ");
			if (guit2diff==2)
				snprintf(guitar2dftext,6," Ext ");
			guitar2ns.load(guitar2nstext,"mono.ttf",255,255,255,12);
			guitar2as.load(guitar2astext,"mono.ttf",255,255,255,12);
			guitar2fm.load(guitar2fmtext,"mono.ttf",255,255,255,12);
			guitar2rm.load(guitar2rmtext,"mono.ttf",255,255,255,12);
			guitar2sm.load(guitar2smtext,"mono.ttf",255,255,255,12);
			guitar2df.load(guitar2dftext,"mono.ttf",255,255,255,12);
			guitar2ns.draw(tablex-18+88,tabley-8,2010,255,255,255,255,false,true);
			guitar2as.draw(tablex-18+88,tabley-8-18,2010,255,255,255,255,false,true);
			guitar2fm.draw(tablex-18+88,tabley-8-36,2010,255,255,255,255,false,true);
			guitar2rm.draw(tablex-18+88,tabley-8-54,2010,255,255,255,255,false,true);
			guitar2sm.draw(tablex-18+88,tabley-8-72,2010,255,255,255,255,false,true);
			guitar2df.draw(tablex-18+88,tabley-8-90,2010,255,255,255,255,false,true);
		}else{
			draw_quad_frame(0,tablex+88,tabley,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex+88,tabley-18,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex+88,tabley-36,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex+88,tabley-54,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex+88,tabley-72,2000,22,9,255,255,255,255,0,0,65,0);
			draw_quad_frame(0,tablex+88,tabley-90,2000,22,9,255,255,255,255,0,0,65,0);
		}
		const int ins=6;
		static char inss[ins][100];
		static drawtext inst[ins];
		snprintf(inss[0],99,"drum: bs, bs  Guitar: g, g");
		snprintf(inss[1],99,"drum: n/a  Guitar: p, g, g, p");
		snprintf(inss[2],99,"drum: sn, lt, sn  Guitar: r, b, r");
		snprintf(inss[3],99,"drum: lt, sn, lt  Guitar: b, r, b");
		snprintf(inss[4],99,"drum: sn, sn, lt  Guitar: b, b, r");
		snprintf(inss[5],99,"drum: hh, hh  Guitar: p, p");
		for (int a=0;a<ins;a++){
			inst[a].load(inss[a],"font.ttf",255,255,255,uivars.song_options_s);
			inst[a].draw(tablex+120,tabley-10-(a*18),2010,255,255,255,255,false,true);
		}
		
		if (stages>0)
			snprintf(marmott[10],256,"Stage: %i/%i",currstage,stages);
		else
			snprintf(marmott[10],256,"Stage: %i",currstage);
		marmottext[10].load(marmott[10],"silly.ttf",255,0,0,uivars.song_stages_s);
		if (drummode){
			if (drumdiff!=-1)draw_quad(0,uivars.song_difficultymarker_x,uivars.song_difficultymarker_y-(92*drumdiff),2500,36,36,255,255,int(cos(double(totalframes)/10.0)*128.0)+127,255,0,0-totalframes,19);
		}
		if (guitar1mode){
			if (guitar1treb){
				if (guit1diff!=-1)draw_quad(0,uivars.song_difficultymarker_x+100,uivars.song_difficultymarker_y-(92*guit1diff),2500+int(cos(double(totalframes+31)/10.0)*128.0),36,36,255,int(cos(double(totalframes)/10.0)*128.0)+127,int(cos(double(totalframes)/10.0)*128.0)+127,255,0,0-totalframes,19);
			}else{
				if (guit1diff!=-1)draw_quad(0,uivars.song_difficultymarker_x+200,uivars.song_difficultymarker_y-(92*guit1diff),2500+int(cos(double(totalframes+31)/10.0)*128.0),36,36,255,int(cos(double(totalframes)/10.0)*128.0)+127,int(cos(double(totalframes)/10.0)*128.0)+127,255,0,0-totalframes,19);
			}
		}
		if (guitar2mode){
			if (guitar2treb){
				if (guit2diff!=-1)draw_quad(0,uivars.song_difficultymarker_x+100,uivars.song_difficultymarker_y-(92*guit2diff),2500+int(cos(double(totalframes)/10.0)*128.0),36,36,int(cos(double(totalframes+31)/10.0)*128.0)+127,int(cos(double(totalframes+31)/10.0)*128.0)+127,255,255,0,0-totalframes,19);
			}else{
				if (guit2diff!=-1)draw_quad(0,uivars.song_difficultymarker_x+200,uivars.song_difficultymarker_y-(92*guit2diff),2500+int(cos(double(totalframes)/10.0)*128.0),36,36,int(cos(double(totalframes+31)/10.0)*128.0)+127,int(cos(double(totalframes+31)/10.0)*128.0)+127,255,255,0,0-totalframes,19);
			}
		}
		draw_quad(0,512,384,4000,640,400,255,255,255,255,0,0,53);
		//middle:557	//top:732	//bottom:383
		static int scrollbar=0;
		scrollbar=int(349.0*(double(optionselected+curcatcount-1)/double(curcatcount-1+curcatsongcount[catselected])));
		draw_quad(0,1011,689-scrollbar,4010,15,10,255,255,255,255,0,0,54);
		marmottext[10].draw(uivars.song_stages_x,uivars.song_stages_y,9000,255,255,255,255,false,true);
	}
	ssoptionselected=optionselected;
	//FPS:200
	if (!screenfaddingin&&!screenfaddingout){
		static char screentext[20];
		snprintf(screentext,19,"Select Your Song");
		static drawtext screentextt;
		screentextt.load(screentext,"font.ttf",255,255,255,uivars.song_screenname_s);
		screentextt.draw(uivars.song_screenname_x,uivars.song_screenname_y,5100,255,255,255,255,false,true);
		static char text1[20];
		snprintf(text1,19,"Drum");
		static drawtext text1t;
		text1t.load(text1,"font.ttf",255,255,255,uivars.song_drum_s);
		text1t.draw(uivars.song_drum_x,uivars.song_drum_y,5100,255,255,255,255,false,true);
		static char text2[20];
		if (songs[songselected].hasopenpick){
			snprintf(text2,19,"Open");
		}else{
			snprintf(text2,19,"Normal");
		}
		static drawtext text2t;
		text2t.load(text2,"font.ttf",255,255,255,uivars.song_normal_s);
		text2t.draw(uivars.song_normal_x,uivars.song_normal_y,5100,255,255,255,255,false,true);
		static char text3[20];
		snprintf(text3,19,"Alt.");
		static drawtext text3t;
		text3t.load(text3,"font.ttf",255,255,255,uivars.song_bass_s);
		text3t.draw(uivars.song_bass_x,uivars.song_bass_y,5100,255,255,255,255,false,true);
		
		static char text4[20];
		snprintf(text4,19,"Standard");
		static drawtext text4t;
		text4t.load(text4,"font.ttf",0,255,0,uivars.song_standard_s);
		text4t.draw(uivars.song_standard_x,uivars.song_standard_y,5100,255,255,255,255,false,true);
		static char text5[20];
		snprintf(text5,19,"Advanced");
		static drawtext text5t;
		text5t.load(text5,"font.ttf",255,255,0,uivars.song_advanced_s);
		text5t.draw(uivars.song_advanced_x,uivars.song_advanced_y,5100,255,255,255,255,false,true);
		static char text6[20];
		snprintf(text6,19,"Extreme");
		static drawtext text6t;
		text6t.load(text6,"font.ttf",255,0,0,uivars.song_extreme_s);
		text6t.draw(uivars.song_extreme_x,uivars.song_extreme_y,5100,255,255,255,255,false,true);
		if (thesong>-1&&thesong<gbsongcount){
			static char text7[128];
			static drawtext text7t;
			if (drumdiff==0){
				snprintf(text7,127,"Drum STD High Score: %i",songs[thesong].basdrumhs);
				text7t.load(text7,"grade.ttf",0,255,0,uivars.song_highscoretable_s);
				text7t.draw(uivars.song_highscoretable_x,uivars.song_highscoretable_y+60,5100,255,255,255,255,false,true);
			}
			if (drumdiff==1){
				snprintf(text7,127,"Drum ADV High Score: %i",songs[thesong].advdrumhs);
				text7t.load(text7,"grade.ttf",255,255,0,22);
				text7t.draw(uivars.song_highscoretable_x,uivars.song_highscoretable_y+60,5100,255,255,255,255,false,true);
			}
			if (drumdiff==2){
				snprintf(text7,127,"Drum EXT High Score: %i",songs[thesong].extdrumhs);
				text7t.load(text7,"grade.ttf",255,0,0,22);
				text7t.draw(uivars.song_highscoretable_x,uivars.song_highscoretable_y+60,5100,255,255,255,255,false,true);
			}
			static char text8[128];
			static drawtext text8t;
			if (guit1diff==0){
				snprintf(text8,127,"Gtr-1 STD High Score: %i",songs[thesong].basguitar1hs);
				text8t.load(text8,"grade.ttf",0,255,0,22);
				text8t.draw(uivars.song_highscoretable_x,uivars.song_highscoretable_y+30,5100,255,255,255,255,false,true);
			}
			if (guit1diff==1){
				snprintf(text8,127,"Gtr-1 ADV High Score: %i",songs[thesong].advguitar1hs);
				text8t.load(text8,"grade.ttf",255,255,0,22);
				text8t.draw(uivars.song_highscoretable_x,uivars.song_highscoretable_y+30,5100,255,255,255,255,false,true);
			}
			if (guit1diff==2){
				snprintf(text8,127,"Gtr-1 EXT High Score: %i",songs[thesong].extguitar1hs);
				text8t.load(text8,"grade.ttf",255,0,0,22);
				text8t.draw(uivars.song_highscoretable_x,uivars.song_highscoretable_y+30,5100,255,255,255,255,false,true);
			}
			static char text9[128];
			static drawtext text9t;
			if (guit2diff==0){
				snprintf(text9,127,"Gtr-2 STD High Score: %i",songs[thesong].basguitar2hs);
				text9t.load(text9,"grade.ttf",0,255,0,22);
				text9t.draw(uivars.song_highscoretable_x,uivars.song_highscoretable_y,5100,255,255,255,255,false,true);
			}
			if (guit2diff==1){
				snprintf(text9,127,"Gtr-2 ADV High Score: %i",songs[thesong].advguitar2hs);
				text9t.load(text9,"grade.ttf",255,255,0,22);
				text9t.draw(uivars.song_highscoretable_x,uivars.song_highscoretable_y,5100,255,255,255,255,false,true);
			}
			if (guit2diff==2){
				snprintf(text9,127,"Gtr-2 EXT High Score: %i",songs[thesong].extguitar2hs);
				text9t.load(text9,"grade.ttf",255,0,0,22);
				text9t.draw(uivars.song_highscoretable_x,uivars.song_highscoretable_y,5100,255,255,255,255,false,true);
			}
			///more s--t to throw randomly on the screen.
			static char text10[128];
			static drawtext text10t;
			if (drumdiff==0){
				snprintf(text10,127,"Max Combo:  %i",songs[thesong].basdrummc);
				text10t.load(text10,"font.ttf",255,255,255,17);
				text10t.draw(uivars.song_highscoretable_x+28,uivars.song_highscoretable_y+50,5500,255,255,255,255,false,true);
			}
			if (drumdiff==1){
				snprintf(text10,127,"Max Combo:  %i",songs[thesong].advdrummc);
				text10t.load(text10,"font.ttf",255,255,255,17);
				text10t.draw(uivars.song_highscoretable_x+28,uivars.song_highscoretable_y+50,5500,255,255,255,255,false,true);
			}
			if (drumdiff==2){
				snprintf(text10,127,"Max Combo:  %i",songs[thesong].extdrummc);
				text10t.load(text10,"font.ttf",255,255,255,17);
				text10t.draw(uivars.song_highscoretable_x+28,uivars.song_highscoretable_y+50,5500,255,255,255,255,false,true);
			}
			static char text11[128];
			static drawtext text11t;
			if (guit1diff==0){
				snprintf(text11,127,"Max Combo:  %i",songs[thesong].basguitar1mc);
				text11t.load(text11,"font.ttf",255,255,255,17);
				text11t.draw(uivars.song_highscoretable_x+28,uivars.song_highscoretable_y+20,5500,255,255,255,255,false,true);
			}
			if (guit1diff==1){
				snprintf(text11,127,"Max Combo:  %i",songs[thesong].advguitar1mc);
				text11t.load(text11,"font.ttf",255,255,255,17);
				text11t.draw(uivars.song_highscoretable_x+28,uivars.song_highscoretable_y+20,5500,255,255,255,255,false,true);
			}
			if (guit1diff==2){
				snprintf(text11,127,"Max Combo:  %i",songs[thesong].extguitar1mc);
				text11t.load(text11,"font.ttf",255,255,255,17);
				text11t.draw(uivars.song_highscoretable_x+28,uivars.song_highscoretable_y+20,5500,255,255,255,255,false,true);
			}
			static char text12[128];
			static drawtext text12t;
			if (guit2diff==0){
				snprintf(text12,127,"Max Combo:  %i",songs[thesong].basguitar2mc);
				text12t.load(text12,"font.ttf",255,255,255,17);
				text12t.draw(uivars.song_highscoretable_x+28,uivars.song_highscoretable_y-10,5500,255,255,255,255,false,true);
			}
			if (guit2diff==1){
				snprintf(text12,127,"Max Combo:  %i",songs[thesong].advguitar2mc);
				text12t.load(text12,"font.ttf",255,255,255,17);
				text12t.draw(uivars.song_highscoretable_x+28,uivars.song_highscoretable_y-10,5500,255,255,255,255,false,true);
			}
			if (guit2diff==2){
				snprintf(text12,127,"Max Combo:  %i",songs[thesong].extguitar2mc);
				text12t.load(text12,"font.ttf",255,255,255,17);
				text12t.draw(uivars.song_highscoretable_x+28,uivars.song_highscoretable_y-10,5500,255,255,255,255,false,true);
			}
		}
		static char sortt[16];
		static drawtext sorttext;
		if (listmode==1)
			snprintf(sortt,15,"SORT: CAT");
		if (listmode==2)
			snprintf(sortt,15,"SORT: ABC");
		if (listmode==3)
			snprintf(sortt,15,"SORT: DDL");
		if (listmode==4)
			snprintf(sortt,15,"SORT: GDL");
		if (listmode==5)
			snprintf(sortt,15,"SORT: BPM");
		sorttext.load(sortt,"impact.ttf",255,255,255,uivars.song_sort_s);
		sorttext.draw(uivars.song_sort_x,uivars.song_sort_y,4500,255,255,255,255,false,true);
		
		static double longalpha=0.0;
		if (songs[songselected].islong&&optionselected>0)
			longalpha+=steptime*3;
		else
			longalpha-=steptime*3;		
		if (longalpha<0.0)
			longalpha=0.0;
		if (longalpha>255.0)
			longalpha=255.0;
		static int s=50;
		draw_quad(0,uivars.song_selector_x+400,uivars.song_selector_y-s,6000,90,int(double(s)*(longalpha/255.0)),255,255,255,int(longalpha),0,0,68);
		artisttext.draw(uivars.song_artitist_x,uivars.song_artitist_y,9000,255,255,255,255,false,true);
		bpmtext.draw(uivars.song_bpmtext_x,uivars.song_bpmtext_y,9000,255,255,255,255,false,true);
	}
	//FPS:260
	//counter
	if (arcademode){
		if (menucountertime>0){
			static long timer=0;
			if (currscreen!=prevscreen)
				timer=SDL_GetTicks();
			int timeleft=int(double(menucountertime)-((double(SDL_GetTicks())-double(timer))/1000.0));
			static char disptime[10];
			snprintf(disptime,9,"%i",timeleft);
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
				jukeboxmode=false;
				nextscreen=6;
				screenfaddingout=true;
				screenchangenow=false;
				screenfaddingin=false;
				tempbackgroundtexture=backgroundtexture;
			}
		}
	}
	static char previewtext[128];
	snprintf(previewtext,127,"Please Wait...");
	static drawtext previewtextt;
	previewtextt.load(previewtext,"font.ttf",255,255,255,20);
	if (beenidle<24){
		previewtextt.draw(uivars.song_previewimage_x-(previewtextt.width/2),uivars.song_previewimage_y-(previewtextt.height/2),9000,255,255,255,255,false,true);
	}
}
