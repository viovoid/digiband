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
void parsekey(int lastkeypressed, bool &uppressed, bool &downpressed){
	#ifdef EXCESSIVE
	printf("parsekey\n");
	#endif
	static int codenum=0;
	static int codenum2=0;
	static int codes[10];
	static int codes2[10];
	if (currscreen==7){
		if (suboptionselection){
			if (optionselected==0)
				hihatkey=lastkeypressed;
			if (optionselected==1)
				snarekey=lastkeypressed;
			if (optionselected==2)
				basskey=lastkeypressed;
			if (optionselected==3)
				hitomkey=lastkeypressed;
			if (optionselected==4)
				lotomkey=lastkeypressed;
			if (optionselected==5)
				cymbalkey=lastkeypressed;
			if (optionselected==6)
				startkey=lastkeypressed;
			if (optionselected==7)
				backkey=lastkeypressed;
			if (optionselected==8)
				althihatkey=lastkeypressed;
			if (optionselected==9)
				altsnarekey=lastkeypressed;
			if (optionselected==10)
				altbasskey=lastkeypressed;
			if (optionselected==11)
				althitomkey=lastkeypressed;
			if (optionselected==12)
				altlotomkey=lastkeypressed;
			if (optionselected==13)
				altcymbalkey=lastkeypressed;
			suboptionselection=false;
			lastkeypressed=0;
		}
	}
	if (currscreen==8){
		if (suboptionselection){
			if (optionselected==0)
				guitar1r=lastkeypressed;
			if (optionselected==1)
				guitar1g=lastkeypressed;
			if (optionselected==2)
				guitar1b=lastkeypressed;
			if (optionselected==3)
				guitar1w=lastkeypressed;
			if (optionselected==4)
				guitar1p=lastkeypressed;
			if (optionselected==5)
				guitar1start=lastkeypressed;
			if (optionselected==6)
				guitar1back=lastkeypressed;
			if (optionselected==7)
				guitar1a=lastkeypressed;
			suboptionselection=false;
			lastkeypressed=0;
		}
	}
	if (currscreen==9){
		if (suboptionselection){
			if (optionselected==0)
				guitar2r=lastkeypressed;
			if (optionselected==1)
				guitar2g=lastkeypressed;
			if (optionselected==2)
				guitar2b=lastkeypressed;
			if (optionselected==3)
				guitar2w=lastkeypressed;
			if (optionselected==4)
				guitar2p=lastkeypressed;
			if (optionselected==5)
				guitar2start=lastkeypressed;
			if (optionselected==6)
				guitar2back=lastkeypressed;
			if (optionselected==7)
				guitar2a=lastkeypressed;
			suboptionselection=false;
			lastkeypressed=0;
		}
	}
	if (currscreen==17){
		if (suboptionselection){
			if (optionselected==3||optionselected==4){
				if (optionselected==3)
					coinkey=lastkeypressed;
				if (optionselected==4)
					opskey=lastkeypressed;
				suboptionselection=false;
				lastkeypressed=0;
			}
		}
	}	
	if (lastkeypressed>0){
		switch( lastkeypressed ){
			case SDLK_ESCAPE:
                #ifdef DEBUG
				printf("quit detected.\n");
				#endif
				if (isloading)appisrunning=false;
				break;
		}
		//can someone explain to me why I can compare a const int and a regular int with if(),
		//but cannot with switch()?
		if (currscreen==6){
			if (lastkeypressed==hihatkey||lastkeypressed==althihatkey){
				hihatani=2;
				hihatts=songposition;
				hihatpressed=true;
			}
			if (lastkeypressed==snarekey||lastkeypressed==altsnarekey){
				snareani=2;
				snarets=songposition;
				snarepressed=true;
			}
			if (lastkeypressed==basskey||lastkeypressed==altbasskey){
				bassani=2;
				bassts=songposition;
				basspressed=true;
			}
			if (lastkeypressed==hitomkey||lastkeypressed==althitomkey){
				hitomani=2;
				hitomts=songposition;
				hitompressed=true;
			}
			if (lastkeypressed==lotomkey||lastkeypressed==altlotomkey){
				lotomani=2;
				lotomts=songposition;
				lotompressed=true;
			}
			if (lastkeypressed==cymbalkey||lastkeypressed==altcymbalkey){
				cymbalani=2;
				cymbalts=songposition;
				cymbalpressed=true;
			}
			if (lastkeypressed==guitar1r){
				g1rp=true;
			}
			if (lastkeypressed==guitar1g){
				g1gp=true;
			}
			if (lastkeypressed==guitar1b){
				g1bp=true;
			}
			if (lastkeypressed==guitar1w){
				g1wp=true;
			}
			if (lastkeypressed==guitar2r){
				g2rp=true;
			}
			if (lastkeypressed==guitar2g){
				g2gp=true;
			}
			if (lastkeypressed==guitar2b){
				g2bp=true;
			}
			if (lastkeypressed==guitar2w){
				g2wp=true;
			}
			if (lastkeypressed==guitar1p){
				if (!g1pp){
					if (!g1rp&&!g1gp&&!g1bp)
						g1ots=songposition;
					if (!g1rp&&!g1gp&&g1bp)
						g1bts=songposition;
					if (!g1rp&&g1gp&&!g1bp)
						g1gts=songposition;
					if (!g1rp&&g1gp&&g1bp)
						g1gbts=songposition;
					if (g1rp&&!g1gp&&!g1bp)
						g1rts=songposition;
					if (g1rp&&!g1gp&&g1bp)
						g1rbts=songposition;
					if (g1rp&&g1gp&&!g1bp)
						g1rgts=songposition;
					if (g1rp&&g1gp&&g1bp)
						g1rgbts=songposition;
					if (g1wp)
						g1wts=songposition;
					g1pp=true;
				}
			}
			if (lastkeypressed==guitar1a){
				if (!g1pp){
					if (!g1rp&&!g1gp&&!g1bp)
						g1ots=songposition;
					if (!g1rp&&!g1gp&&g1bp)
						g1bts=songposition;
					if (!g1rp&&g1gp&&!g1bp)
						g1gts=songposition;
					if (!g1rp&&g1gp&&g1bp)
						g1gbts=songposition;
					if (g1rp&&!g1gp&&!g1bp)
						g1rts=songposition;
					if (g1rp&&!g1gp&&g1bp)
						g1rbts=songposition;
					if (g1rp&&g1gp&&!g1bp)
						g1rgts=songposition;
					if (g1rp&&g1gp&&g1bp)
						g1rgbts=songposition;
					if (g1wp)
						g1wts=songposition;
					g1pp=true;
				}
			}
			if (lastkeypressed==guitar2p){
				if (!g2pp){
					if (!g2rp&&!g2gp&&!g2bp)
						g2ots=songposition;
					if (!g2rp&&!g2gp&&g2bp)
						g2bts=songposition;
					if (!g2rp&&g2gp&&!g2bp)
						g2gts=songposition;
					if (!g2rp&&g2gp&&g2bp)
						g2gbts=songposition;
					if (g2rp&&!g2gp&&!g2bp)
						g2rts=songposition;
					if (g2rp&&!g2gp&&g2bp)
						g2rbts=songposition;
					if (g2rp&&g2gp&&!g2bp)
						g2rgts=songposition;
					if (g2rp&&g2gp&&g2bp)
						g2rgbts=songposition;
					if (g2wp)
						g2wts=songposition;
					g2pp=true;
				}
			}
			if (lastkeypressed==guitar2a){
				if (!g2pp){
					if (!g2rp&&!g2gp&&!g2bp)
						g2ots=songposition;
					if (!g2rp&&!g2gp&&g2bp)
						g2bts=songposition;
					if (!g2rp&&g2gp&&!g2bp)
						g2gts=songposition;
					if (!g2rp&&g2gp&&g2bp)
						g2gbts=songposition;
					if (g2rp&&!g2gp&&!g2bp)
						g2rts=songposition;
					if (g2rp&&!g2gp&&g2bp)
						g2rbts=songposition;
					if (g2rp&&g2gp&&!g2bp)
						g2rgts=songposition;
					if (g2rp&&g2gp&&g2bp)
						g2rgbts=songposition;
					if (g2wp)
						g2wts=songposition;
					g2pp=true;
				}
			}
		}
		if (currscreen==13){
			if (lastkeypressed==snarekey){
				dmoptionselected--;
			}
			if (lastkeypressed==lotomkey){
				dmoptionselected++;	
			}	
			if (lastkeypressed==startkey){
				if (dmhs){
					if (dmoptionselected<='Z'){
						dmpos++;	
					}
					if (dmoptionselected=='Z'+1){
						if (dmpos>0){
							dminitials[dmpos]='\0';
							dmpos--;
						}	
					}
					if (dmoptionselected=='Z'+2){
						dminitials[dmpos]='\0';
						if (strlen(dminitials)<1)
							snprintf(dminitials,4,"DGB");
						dmhs=false;
					}
				}
			}
			if (lastkeypressed==guitar1r){
				g1optionselected--;
			}
			if (lastkeypressed==guitar1b){
				g1optionselected++;
			}
			if (lastkeypressed==guitar1start){
				if (g1hs){
					if (g1optionselected<='Z'){
						g1pos++;	
					}
					if (g1optionselected=='Z'+1){
						if (g1pos>0){
							g1initials[g1pos]='\0';
							g1pos--;	
						}
					}
					if (g1optionselected=='Z'+2){
						g1initials[g1pos]='\0';
						if (strlen(g1initials)<1)
							snprintf(g1initials,4,"DGB");
						g1hs=false;
					}
				}
			}
			if (lastkeypressed==guitar2r){
				g2optionselected--;
			}
			if (lastkeypressed==guitar2b){
				g2optionselected++;
			}
			if (lastkeypressed==guitar2start){
				if (g2hs){
					if (g2optionselected<='Z'){
						g2pos++;	
					}
					if (g2optionselected=='Z'+1){
						if (g2pos>0){
							g2initials[g2pos]='\0';
							g2pos--;	
						}
					}
					if (g2optionselected=='Z'+2){
						g2initials[g2pos]='\0';
						if (strlen(g2initials)<1)
							snprintf(g2initials,4,"DGB");
						g2hs=false;
					}
				}
			}			
		}
		if (lastkeypressed==snarekey ||
			lastkeypressed==guitar1r ||
			lastkeypressed==SDLK_UP ||
			lastkeypressed==SDLK_LEFT){
			if(!suboptionselection&&currscreen!=5)optionselected--;
			if(currscreen<11&&currscreen!=4&&currscreen!=6)playsound(2,"selection.wav");
			if(currscreen==17)playsound(2,"selection.wav");
			if(suboptionselection){
				if (currscreen==11){
					if (optionselected==0)
						if (autohihat)autohihat=false;
						else autohihat=true;
					if (optionselected==1)
						if (autobass)autobass=false;
						else autobass=true;
					if (optionselected==2)
						if (autocymbal)autocymbal=false;
						else autocymbal=true;
					if (optionselected==3)
						if (autoall)autoall=false;
						else autoall=true;
				}
				if (currscreen==10){
					if (optionselected==0)
						voldrum--;
					if (voldrum<0)
						voldrum=10;
					if (optionselected==1)
						volguit--;
					if (volguit<0)
						volguit=10;
					if (optionselected==2)
						volbass--;
					if (volbass<0)
						volbass=10;
					if (optionselected==3)
						volbgm--;
					if (volbgm<0)
						volbgm=10;
				}
			}
			if (currscreen==17){
				if(suboptionselection){
					if (optionselected==0){
						if (arcademode){
							arcademode=false;
						}else{
							arcademode=true;
						}
					}
					if (optionselected==1){
						coinsperplay--;
						if (coinsperplay<1)	
							coinsperplay=9;
					}
					if (optionselected==2){
						menucountertime-=5;
						if (menucountertime<5)
							menucountertime=500;
					}
					
				}
			}
			if (currscreen==2){
				if(suboptionselection){
					if (optionselected==0){
						if(drumfullscreen)
							drumfullscreen=false;
						else
							drumfullscreen=true;
					}
					if (optionselected==1){
						resx--;
					}
					if (optionselected==2){
						resy--;
					}
					if (optionselected==3){
						if (drumbpp==8)
							drumbpp=32;
						else if(drumbpp==16)
							drumbpp=8;
						else if(drumbpp==32)
							drumbpp=16;
					}
					if (optionselected==4){
						themenumber--;
						if (themenumber<0)themenumber=themecount;
						snprintf(theme,255,"%s", themes[themenumber]);
					}
					if (optionselected==5){
						lifedifficulty--;
						if (lifedifficulty<0)
							lifedifficulty=10;
					}
					if (optionselected==6){
						if (stagefail)
							stagefail=false;
						else
							stagefail=true;
					}
					if (optionselected==7){
						stages--;
						if (stages<0)
							stages=9;
					}
					if (optionselected==8){
						notespeed--;
						if (notespeed<1)
							notespeed=200;
					}
					if (optionselected==9){
						if (verticlesync)
							verticlesync=false;
						else
							verticlesync=true;
					}
					if (optionselected==10){
						noteskinnumber--;
						if (noteskinnumber<0)noteskinnumber=noteskincount;
						snprintf(noteskin,255,"%s",noteskins[noteskinnumber]);
					}
				}
			}
			uppressed=true;
		}
		if (lastkeypressed==SDLK_F11){
			if (currscreen==6){
				songs[thesong].offset--;
			}
		}
		if (lastkeypressed==SDLK_F12){
			if (currscreen==6){
				songs[thesong].offset++;
			}
		}
		if (lastkeypressed==SDLK_F8){
			if (currscreen==5){
				playsound(7,"selection.wav");
				listmode++;
				if (optionselected<0){
					optionselected=0;
					thesong=0;
				}
			}
		}
		if (lastkeypressed==SDLK_F6){
			if (currscreen==5){
				if (!jukeboxmode){
					char playstring[512];
					jukeboxmode=true;
					guit1diff=2;
					guit2diff=2;
					drumdiff=2;
					newsong=true;
					if (thesong<0){
						srand(SDL_GetTicks());
						catselected=int( ((double)rand()/(double)RAND_MAX)*(double)curcatcount);
						if (catselected>=curcatcount)catselected=curcatcount-1;
						if (catselected<0)catselected=0;
						optionselected=int( ((double)rand()/(double)RAND_MAX)*(double)curcatsongcount[catselected]);
						if (optionselected>curcatsongcount[catselected])optionselected=curcatsongcount[catselected];
						if (optionselected<1)optionselected=1;
						playsound(2,"selection.wav");
						catchangewait=1000;		
					}
					songs[thesong].resetplayed();
				}else{
					jukeboxmode=false;
					newsong=true;
				}
			}
		}
		if (lastkeypressed==SDLK_F7){
			if (currscreen==5){
				srand(SDL_GetTicks());
				catselected=int( ((double)rand()/(double)RAND_MAX)*(double)curcatcount);
				if (catselected>=curcatcount)catselected=curcatcount-1;
				if (catselected<0)catselected=0;
				optionselected=int( ((double)rand()/(double)RAND_MAX)*(double)curcatsongcount[catselected]);
				if (optionselected>curcatsongcount[catselected])optionselected=curcatsongcount[catselected];
				if (optionselected<1)optionselected=1;
				playsound(2,"selection.wav");
				catchangewait=1000;
			}
		}
		if (lastkeypressed==SDLK_PAGEUP){
			if (currscreen==5){
				optionselected-=4;
				playsound(2,"selection.wav");
				uppressed=true;
			}
		}
		if (lastkeypressed==SDLK_PAGEDOWN){
			if (currscreen==5){
				optionselected+=4;
				playsound(2,"selection.wav");
				downpressed=true;
			}
		}
		if (lastkeypressed==lotomkey ||
			lastkeypressed==guitar1b ||
			lastkeypressed==SDLK_DOWN ||
			lastkeypressed==SDLK_RIGHT){
			if(!suboptionselection&&currscreen!=5)optionselected++;
			if(currscreen<11&&currscreen!=4&&currscreen!=6)playsound(2,"selection.wav");
			if(currscreen==17)playsound(2,"selection.wav");
			if(suboptionselection){
				if (currscreen==11){
					if (optionselected==0)
						if (autohihat)autohihat=false;
						else autohihat=true;
					if (optionselected==1)
						if (autobass)autobass=false;
						else autobass=true;
					if (optionselected==2)
						if (autocymbal)autocymbal=false;
						else autocymbal=true;
					if (optionselected==3)
						if (autoall)autoall=false;
						else autoall=true;
				}
				if (currscreen==10){
					if (optionselected==0)
						voldrum++;
					if (voldrum>10)
						voldrum=0;
					if (optionselected==1)
						volguit++;
					if (volguit>10)
						volguit=0;
					if (optionselected==2)
						volbass++;
					if (volbass>10)
						volbass=0;
					if (optionselected==3)
						volbgm++;
					if (volbgm>10)
						volbgm=0;
				}
			}
			if (currscreen==17){
				if(suboptionselection){
					if (optionselected==0){
						if (arcademode){
							arcademode=false;
						}else{
							arcademode=true;
						}
					}
					if (optionselected==1){
						coinsperplay++;
						if (coinsperplay>9)	
							coinsperplay=1;
					}
					if (optionselected==2){
						menucountertime+=5;
						if (menucountertime>500)
							menucountertime=5;
					}
					
				}
			}
			if (currscreen==2){
				if(suboptionselection){
					if (optionselected==0){
						if(drumfullscreen)
							drumfullscreen=false;
						else
							drumfullscreen=true;
					}
					if (optionselected==1){
						resx++;
					}
					if (optionselected==2){
						resy++;
					}
					if (optionselected==3){
						if (drumbpp==8)
							drumbpp=16;
						else if(drumbpp==16)
							drumbpp=32;
						else if(drumbpp==32)
							drumbpp=8;
					}
					if (optionselected==4){
						themenumber++;
						if (themenumber>themecount)themenumber=0;
						snprintf(theme,255,"%s",themes[themenumber]);
					}
					if (optionselected==5){
						lifedifficulty++;
						if (lifedifficulty>10)
							lifedifficulty=0;
					}
					if (optionselected==6){
						if (stagefail)
							stagefail=false;
						else
							stagefail=true;
					}
					if (optionselected==7){
						stages++;
						if (stages>9)
							stages=0;
					}
					if (optionselected==8){
						notespeed++;
						if (notespeed>200)
							notespeed=1;
					}
					if (optionselected==9){
						if (verticlesync)
							verticlesync=false;
						else
							verticlesync=true;
					}
					if (optionselected==10){
						noteskinnumber++;
						if (noteskinnumber>noteskincount)noteskinnumber=0;
						snprintf(noteskin,255,"%s", noteskins[noteskinnumber]);
					}
				}
			}
			downpressed=true;
		}
		if (lastkeypressed==SDLK_ESCAPE ||
			lastkeypressed==backkey ||
			lastkeypressed==guitar1back ){
			if (arcademode){
				if (currscreen==1){
			        #ifdef DEBUG
					printf("quit detected.\n");
					#endif
					appisrunning=false;
				}
				if (currscreen==20){
                    #ifdef DEBUG
					printf("quit detected.\n");
					#endif
					appisrunning=false;
				}
				if (currscreen==21){
                    #ifdef DEBUG
					printf("quit detected.\n");
					#endif
					appisrunning=false;
				}
			}
			if (!arcademode){
				if (currscreen==16){
					screenfaddingout=true;
					screenfaddingin=false;
					screenchangenow=false;
					nextscreen=1;
				}
				if (currscreen==13){
					nextscreen=1;
					screenfaddingout=true;
					screenchangenow=false;
					screenfaddingin=false;
				}
				if (currscreen==15){
					if (gameover)
						nextscreen=14;
					else
						nextscreen=12;
					screenfaddingout=true;
					screenchangenow=false;
					screenfaddingin=false;
					gameover=false;
				}
				if (currscreen==12){
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
				if (currscreen==14){
					nextscreen=1;
					screenfaddingout=true;
					screenchangenow=false;
					screenfaddingin=false;
				}
				if (currscreen==6){
					nextscreen=5;
					screenfaddingout=true;
					screenchangenow=false;
					screenfaddingin=false;
				}
				if (currscreen==2){
					if (!suboptionselection){
						nextscreen=1;
						screenfaddingout=true;
						screenchangenow=false;
						screenfaddingin=false;
						settings.save();
					}
					if (suboptionselection)
						suboptionselection=false;
				}
				if (currscreen>=7&&currscreen<=11){
					if (!suboptionselection){
						screenfaddingout=false;
						screenfaddingin=false;
						screenchangenow=true;
						nextscreen=lastscreen;
					}else{
						suboptionselection=false;
					}
				}
				if (currscreen==4){
					nextscreen=1;
					screenchangenow=false;
					screenfaddingout=true;
				}
				if (currscreen==5){
					if (jukeboxmode){
						newsong=true;
						jukeboxmode=false;
					}
					nextscreen=4;
					screenfaddingout=true;
					screenchangenow=false;
					sssloptionselected=optionselected;
				}
			}
		}
		if (lastkeypressed==startkey){
			if (currscreen==4){
				if (!screenfaddingout){
					if (!drummode){
						if (!arcademode){
							drummode=true;
							playsound(3,"drumstart.wav");
						}else{
							if (credits>0){
								credits--;
								drummode=true;
								playsound(3,"drumstart.wav");
							}
						}
					}else{
						screenfaddingout=true;
						nextscreen=5;
						screenchangenow=false;
					}
				}
			}
		}
		if (lastkeypressed==guitar1start){
			if (currscreen==4){
				if (!screenfaddingout){
					if (!guitar1mode){
						if (!arcademode){
							guitar1mode=true;
							playsound(4,"guitarstart.wav");
						}else{
							if (credits>0){
								credits--;
								guitar1mode=true;
								playsound(4,"guitarstart.wav");
							}
						}
					}else{
						screenfaddingout=true;
						if (optionselected==0)
							nextscreen=5;
						if (optionselected==1)
							nextscreen=5;
						screenchangenow=false;
					}
				}
			}
		}
		if (lastkeypressed==guitar2start){
			if (currscreen==4){
				if (!screenfaddingout){
					if (!guitar2mode){
						if (!arcademode){
							guitar2mode=true;
							playsound(5,"bassstart.wav");
						}else{
							if (credits>0){
								credits--;
								guitar2mode=true;
								playsound(5,"bassstart.wav");
							}
						}
					}else{
						screenfaddingout=true;
						if (optionselected==0)
							nextscreen=5;
						if (optionselected==1)
							nextscreen=5;
						screenchangenow=false;
					}
				}
			}
		}
		if (lastkeypressed==coinkey){
			coinsinserted++;
			if (coinsinserted>=coinsperplay){
				coinsinserted-=coinsperplay;	
				credits++;
				playsound(13,"credit.wav");
			}else{
				playsound(7,"code.wav");
			}
		}
		if (lastkeypressed==opskey){
			lastcymbal=0;
			if (presong>-1&&presong<gbsongcount){
				if(songsloaded>0)unloadwaves();
			}
			if (thesong>-1&&thesong<gbsongcount){
				if(songsloaded>0)loadwaves();
			}
			coinsinserted=0;
			credits=0;	
			nextscreen=2;
			screenchangenow=true;
			screenfaddingin=true;
		}
		if (lastkeypressed==startkey ||
			lastkeypressed==SDLK_RETURN ||
			lastkeypressed==guitar1start ||
			lastkeypressed==guitar2start ||
			lastkeypressed==cymbalkey ){
			if (currscreen==15){
				if (gameover)
					nextscreen=14;
				else
					nextscreen=12;
				screenfaddingout=true;
				screenchangenow=false;
				screenfaddingin=false;
				gameover=false;
				if (optionselected==0)
					songs[thesong].saveextended();
			}
			if (currscreen==13){
				if (!dmhs&&!g1hs&&!g2hs){
					nextscreen=1;
					screenfaddingout=true;
					screenchangenow=false;
					screenfaddingin=false;	
				}				
			}
			if (currscreen==12){
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
			if (currscreen==14){
				nextscreen=1;
				screenfaddingout=true;
				screenchangenow=false;
				screenfaddingin=false;
			}
			if (currscreen==1||currscreen==20||currscreen==21){
				if (!arcademode){
					if (optionselected==1){
						nextscreen=4;
						screenchangenow=false;
						screenfaddingout=true;
						playsound(6,"gamestart.wav");
						drummode=false;
						guitar1mode=false;
						guitar2mode=false;
						if (lastkeypressed==startkey||lastkeypressed==cymbalkey)
							drummode=true;
						if (lastkeypressed==guitar1start)
							guitar1mode=true;
						if (lastkeypressed==guitar2start)
							guitar2mode=true;
					}
					if (optionselected==3){
                        #ifdef DEBUG
						printf("quit detected.\n");
						#endif
						appisrunning=false;
					}
					if (optionselected==2){
						nextscreen=2;
						screenchangenow=true;
						screenfaddingin=true;
					}
				}else{
					if (!screenfaddingout&&!screenfaddingin){
						if (credits>0){
							/*if (currscreen==20||currscreen==21){
								if(songsloaded>0)unloadwaves();
								if(songsloaded>0)loadwaves();
							}*/
							credits--;
							drummode=false;
							guitar1mode=false;
							guitar2mode=false;
							if (lastkeypressed==startkey||lastkeypressed==cymbalkey||lastkeypressed==SDLK_RETURN)
								drummode=true;
							if (lastkeypressed==guitar1start)
								guitar1mode=true;
							if (lastkeypressed==guitar2start)
								guitar2mode=true;
							nextscreen=4;
							screenchangenow=false;
							screenfaddingout=true;
							playsound(6,"gamestart.wav");
						}
					}
				}
			}
			if (currscreen==5){
				if (optionselected<0){
					int os2=catselected-optionselected;
					if (os2>=curcatcount)
					os2-=curcatcount;
					catselected=os2;
					optionselected=0;
					playsound(10,"category.wav");
					catchangewait=1000;
				}
				if (thesong>-1&&beenidle>30&&catchangewait<=0){
					if (songs[thesong].islong&&stages-currstage<1&&stages>0)
						return;
					if (optionselected>-1){
						jukeboxmode=false;
						nextscreen=6;
						screenfaddingout=true;
						screenchangenow=false;
						screenfaddingin=false;
						tempbackgroundtexture=backgroundtexture;
						sssloptionselected=optionselected;
					}
				}
			}
			if (currscreen==2){
				if (optionselected==16&&!suboptionselection){
					nextscreen=1;
					screenfaddingout=true;
					screenchangenow=false;
					screenfaddingin=false;
					settings.save();
				}
				if (optionselected<11&&!suboptionselection){
					suboptionselection=true;
				}else{
					if (suboptionselection)
						suboptionselection=false;
				}
				if (optionselected>=11&&optionselected<15){
					nextscreen=optionselected-4;
					screenfaddingout=false;
					screenfaddingin=false;
					screenchangenow=true;
				}
				if (optionselected==15){
					nextscreen=17;
					screenfaddingout=false;
					screenfaddingin=false;
					screenchangenow=true;
				}
			}
			if (currscreen==17){
				if (optionselected<5&&!suboptionselection){
					suboptionselection=true;
				}else{
					if (suboptionselection)
						suboptionselection=false;
				}
				if (optionselected==5){
					nextscreen=2;
					screenfaddingout=false;
					screenfaddingin=false;
					screenchangenow=true;
				}
			}
			if (currscreen==7){
				if (optionselected==14){
					nextscreen=lastscreen;
					screenfaddingout=false;
					screenfaddingin=false;
					screenchangenow=true;
				}else{
					suboptionselection=true;
				}
			}
			if (currscreen==8||currscreen==9){
				if (optionselected==8){
					nextscreen=lastscreen;
					screenfaddingout=false;
					screenfaddingin=false;
					screenchangenow=true;
				}else{
					suboptionselection=true;
				}
			}
			if (currscreen==10){
				if (optionselected==4){
					nextscreen=lastscreen;
					screenfaddingout=false;
					screenfaddingin=false;
					screenchangenow=true;
				}else{
					if (!suboptionselection)suboptionselection=true;
					else suboptionselection=false;
				}
			}
			if (currscreen==11){
				if (optionselected==4){
					nextscreen=lastscreen;
					screenfaddingout=false;
					screenfaddingin=false;
					screenchangenow=true;
				}else{
					if (!suboptionselection)suboptionselection=true;
					else suboptionselection=false;
				}
			}
		}	
	}
	if (lastkeypressed!=hihatkey&&lastkeypressed!=basskey&&lastkeypressed!=snarekey&&lastkeypressed!=hitomkey&&lastkeypressed!=lotomkey&&lastkeypressed!=cymbalkey&&
		lastkeypressed!=althihatkey&&lastkeypressed!=altbasskey&&lastkeypressed!=altsnarekey&&lastkeypressed!=althitomkey&&lastkeypressed!=altlotomkey&&lastkeypressed!=altcymbalkey&&
		lastkeypressed!=guitar1r&&lastkeypressed!=guitar1g&&lastkeypressed!=guitar1b&&lastkeypressed!=guitar1w&&lastkeypressed!=guitar1p&&lastkeypressed!=guitar1a&&lastkeypressed!=guitar1back&&lastkeypressed!=guitar1start&&
		lastkeypressed!=guitar2r&&lastkeypressed!=guitar2g&&lastkeypressed!=guitar2b&&lastkeypressed!=guitar2w&&lastkeypressed!=guitar2p&&lastkeypressed!=guitar2a&&lastkeypressed!=guitar2back&&lastkeypressed!=guitar2start){
		return;
	}
	if (currscreen==5){
		if (codetime2<5&&lastkeypressed>0){
			codetime2=0;
			codenum2++;
			bool clear=false;
			if (codenum2<5)codes2[codenum2]=lastkeypressed;
			if (codes2[0]==snarekey && codes2[1]==lotomkey){
				//category change drum 1
				clear=true;
				playsound(7,"selection.wav");
				listmode++;
				if (optionselected<0){
					optionselected=0;
					thesong=0;
				}
			}
			if (codes2[0]==lotomkey&&codes2[1]==snarekey){
				//category change drum 2
				clear=true;
				playsound(7,"selection.wav");
				listmode++;
				if (optionselected<0){
					optionselected=0;
					thesong=0;
				}
			}
			if (codes2[0]==guitar1r&&codes2[1]==guitar1b){
				//category change guit 1 - 1
				clear=true;
				playsound(7,"selection.wav");
				listmode++;
				if (optionselected<0){
					optionselected=0;
					thesong=0;
				}
			}
			if (codes2[0]==guitar1b&&codes2[1]==guitar1r){
				//category change guit 1 - 2
				clear=true;
				playsound(7,"selection.wav");
				listmode++;
				if (optionselected<0){
					optionselected=0;
					thesong=0;
				}
			}
			if (codes2[0]==guitar2r&&codes2[1]==guitar2b){
				//category change guit 2 - 1
				clear=true;
				playsound(7,"selection.wav");
				listmode++;
				if (optionselected<0){
					optionselected=0;
					thesong=0;
				}
			}
			if (codes2[0]==guitar2b&&codes2[1]==guitar2r){
				//category change guit 2 - 2
				codetime2=20;
				playsound(7,"selection.wav");
				listmode++;
				if (optionselected<0){
					optionselected=0;
					thesong=0;
				}
			}
			if (clear){
   				codetime2=20;
				codenum2=0;
				for (int a=0;a<10;a++){
					codes2[a]=0;
				}
			}
		}else{
			if (lastkeypressed>0){
				codenum2=0;
				codetime2=0;
				codes2[0]=lastkeypressed;
			}
		}
		if (codetime<20&&lastkeypressed>0){
   			codetime=0;
			codenum++;
			bool clear=false;
			if (codenum<10)codes[codenum]=lastkeypressed;
			if (codes[0]==hitomkey&&codes[1]==hitomkey){
				//drum random
				clear=true;
				srand(SDL_GetTicks());
				catselected=int( ((double)rand()/(double)RAND_MAX)*(double)curcatcount);
				if (catselected>=curcatcount)catselected=curcatcount-1;
				if (catselected<0)catselected=0;
				optionselected=int( ((double)rand()/(double)RAND_MAX)*(double)curcatsongcount[catselected]);
				if (optionselected>curcatsongcount[catselected])optionselected=curcatsongcount[catselected];
				if (optionselected<1)optionselected=1;
				playsound(2,"selection.wav");
				catchangewait=1000;
			}
			if (codes[0]==guitar1g&&codes[1]==guitar1p&&codes[2]==guitar1p&&codes[3]==guitar1g){
				//guit 1 random
				clear=true;
				srand(SDL_GetTicks());
				catselected=int( ((double)rand()/(double)RAND_MAX)*(double)curcatcount);
				if (catselected>=curcatcount)catselected=curcatcount-1;
				if (catselected<0)catselected=0;
				optionselected=int( ((double)rand()/(double)RAND_MAX)*(double)curcatsongcount[catselected]);
				if (optionselected>curcatsongcount[catselected])optionselected=curcatsongcount[catselected];
				if (optionselected<1)optionselected=1;
				playsound(2,"selection.wav");
				catchangewait=1000;
			}
			if (codes[0]==guitar2g&&codes[1]==guitar2p&&codes[2]==guitar2p&&codes[3]==guitar2g){
				//guit 2 random
				clear=true;
				srand(SDL_GetTicks());
				catselected=int( ((double)rand()/(double)RAND_MAX)*(double)curcatcount);
				if (catselected>=curcatcount)catselected=curcatcount-1;
				if (catselected<0)catselected=0;
				optionselected=int( ((double)rand()/(double)RAND_MAX)*(double)curcatsongcount[catselected]);
				if (optionselected>curcatsongcount[catselected])optionselected=curcatsongcount[catselected];
				if (optionselected<1)optionselected=1;
				playsound(2,"selection.wav");
				catchangewait=1000;
			}
			if (codes[0]==snarekey&&codes[1]==lotomkey&&codes[2]==snarekey){
				//drum fade
				clear=true;
				drumfademode++;
				if (drumfademode>3)
					drumfademode=0;
				playsound(7,"code.wav");
			}
			if (codes[0]==lotomkey&&codes[1]==snarekey&&codes[2]==lotomkey){
				//drum random
				clear=true;
				if (drumrandommode)
					drumrandommode=false;
				else
					drumrandommode=true;
				playsound(7,"code.wav");
			}
			if (codes[0]==snarekey&&codes[1]==snarekey&&codes[2]==lotomkey){
				//drum spin 
				clear=true;
				if (drumspin)
					drumspin=false;
				else
					drumspin=true;
				playsound(7,"code.wav");
			}
			if (codes[0]==guitar1r&&codes[1]==guitar1b&&codes[2]==guitar1r){
				//guit 1 fade
				clear=true;
				guit1fademode++;
				if (guit1fademode>3)
					guit1fademode=0;
				playsound(7,"code.wav");
			}
			if (codes[0]==guitar1b&&codes[1]==guitar1r&&codes[2]==guitar1b){
				//guit 1 random
				clear=true;
				if (guit1randommode)
					guit1randommode=false;
				else
					guit1randommode=true;
				playsound(7,"code.wav");
			}
			if (codes[0]==guitar1b&&codes[1]==guitar1b&&codes[2]==guitar1r){
				//guit 1 spin
				clear=true;
				if (guit1spin)
					guit1spin=false;
				else
					guit1spin=true;
				playsound(7,"code.wav");
			}
			if (codes[0]==guitar2r&&codes[1]==guitar2b&&codes[2]==guitar2r){
				//guit 2 fade
				clear=true;
				guit2fademode++;
				if (guit2fademode>3)
					guit2fademode=0;
				playsound(7,"code.wav");
			}
			if (codes[0]==guitar2b&&codes[1]==guitar2r&&codes[2]==guitar2b){
				//guit 2 random
				clear=true;
				if (guit2randommode)
					guit2randommode=false;
				else
					guit2randommode=true;
				playsound(7,"code.wav");
			}
			if (codes[0]==guitar2b&&codes[1]==guitar2b&&codes[2]==guitar2r){
				//guit 2 spin
				clear=true;
				if (guit2spin)
					guit2spin=false;
				else
					guit2spin=true;
				playsound(7,"code.wav");
			}
			if (codes[0]==guitar1p&&codes[1]==guitar1g&&codes[2]==guitar1g&&codes[3]==guitar1p){
				clear=true;
				if (guitar1treb)
					guitar1treb=false;
				else
					guitar1treb=true;
				playsound(7,"code.wav");
			}
			if (codes[0]==guitar2p&&codes[1]==guitar2g&&codes[2]==guitar2g&&codes[3]==guitar2p){
				clear=true;
				if (guitar2treb)
					guitar2treb=false;
				else
					guitar2treb=true;
				playsound(7,"code.wav");
			}
			if (codes[0]==guitar1p&&codes[1]==guitar1p){
				clear=true;
				guit1diff++;
				if (guit1diff>2)guit1diff=0;
				if (thesong>-1){
					if (guit1diff==2&&songs[thesong].guitextdiff<1)
						guit1diff=0;
				}
				if (jukeboxmode)newsong=true;
				playsound(7,"code.wav");
			}
			if (codes[0]==guitar2p&&codes[1]==guitar2p){
				clear=true;
				guit2diff++;
				if (guit2diff>2)guit2diff=0;
				if (thesong>-1){
					if (guit2diff==2&&songs[thesong].guitextdiff<1)
						guit2diff=0;
				}
				if (jukeboxmode)newsong=true;
				playsound(7,"code.wav");
			}
			if (codes[0]==hihatkey&&codes[1]==hihatkey){
				clear=true;
				drumdiff++;
				if (drumdiff>2)drumdiff=0;
				if (thesong>-1){
					if (drumdiff==2&&songs[thesong].drumextdiff<1)
						drumdiff=0;
				}
				if (jukeboxmode)newsong=true;
				playsound(7,"code.wav");
			}
			if (codes[0]==guitar1g&&codes[1]==guitar1g){
				clear=true;
				guitar1notespeed+=5;
				if (guitar1notespeed>200)guitar1notespeed-=200;
				playsound(7,"code.wav");
			}
			if (codes[0]==guitar2g&&codes[1]==guitar2g){
				clear=true;
				guitar2notespeed+=5;
				if (guitar2notespeed>200)guitar2notespeed-=200;
				playsound(7,"code.wav");
			}
			if (codes[0]==basskey&&codes[1]==basskey){
				clear=true;
				drumnotespeed+=5;
				if (drumnotespeed>200)drumnotespeed-=200;
				playsound(7,"code.wav");
			}
			if (clear){
   				codetime=20;
				codenum=0;
				for (int a=0;a<10;a++){
					codes[a]=0;
				}
			}
		}else{
			if (lastkeypressed>0){
				codenum=0;
				codetime=0;
				codes[0]=lastkeypressed;
			}
		}
	}
}
