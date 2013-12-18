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
void playnote_g2ext(int a,bool &gb,bool &gg,bool &ggb,bool &gr,bool &grb,bool &grg,bool &grgb,bool &gw,bool &go){
	#ifdef EXCESSIVE
	printf("playnote_g2ext\n");
	#endif
	if (guitar2treb){
		if (guit2diff==2){
			long int testmeasure=99999999;//to ignore the next line.
			if (songs[thesong].extnotetime[a]>=0&&songs[thesong].extnotetime[a]<=100000){
				if (songs[thesong].extnotemeas[a]>=0&&songs[thesong].extnotemeas[a]<=999){
					testmeasure=(songs[thesong].extnotemeas[a]*240000+int((double(songs[thesong].extnotetime[a])/10000.0)*240000.0))+(notesoundoffset*currbpm)-(songs[thesong].offset*500);
				}
			}
			//printf("the measure: %i the timing: %i all together: %i ||",songs[thesong].extnotemeas[a]*240000,songs[thesong].extnotetime[a],testmeasure);
			//eh... ^this has like HUGE offset^, but kinda have to have it for those songs that just might be 1BPM ~.O
			if (testmeasure+(almostlv*currbpm/150)<songposition+(entiresongoffset*currbpm)){
				if (!songs[thesong].g2extnoteplayed[a]){
					if (songs[thesong].extnotesound[a]!=NULL){
						//openpick
						if (strcmp(songs[thesong].extnotetype2[a],"20")==0||strcmp(songs[thesong].extnotetype2[a],"g0")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2ograde,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2ogradetime=0;
							}
						}
						//blue
						if (strcmp(songs[thesong].extnotetype2[a],"21")==0||strcmp(songs[thesong].extnotetype2[a],"g1")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2bgrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2bgradetime=0;
							}
						}
						//green
						if (strcmp(songs[thesong].extnotetype2[a],"22")==0||strcmp(songs[thesong].extnotetype2[a],"g2")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2ggrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2ggradetime=0;
							}
						}
						//green+blue
						if (strcmp(songs[thesong].extnotetype2[a],"23")==0||strcmp(songs[thesong].extnotetype2[a],"g3")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2ggrade,24,"Miss");
								snprintf(gpg2bgrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2lifebar-=lifedifficulty;
								gpg2ggradetime=0;
								gpg2bgradetime=0;
							}
						}
						//red
						if (strcmp(songs[thesong].extnotetype2[a],"24")==0||strcmp(songs[thesong].extnotetype2[a],"g4")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2rgrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2rgradetime=0;
							}
						}
						//red+blue
						if (strcmp(songs[thesong].extnotetype2[a],"25")==0||strcmp(songs[thesong].extnotetype2[a],"g5")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2rgrade,24,"Miss");
								snprintf(gpg2bgrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2lifebar-=lifedifficulty;
								gpg2rgradetime=0;
								gpg2bgradetime=0;
							}
						}
						//red+green
						if (strcmp(songs[thesong].extnotetype2[a],"26")==0||strcmp(songs[thesong].extnotetype2[a],"g6")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2rgrade,24,"Miss");
								snprintf(gpg2ggrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2lifebar-=lifedifficulty;
								gpg2rgradetime=0;
								gpg2ggradetime=0;
							}
						}
						//red+green+blue
						if (strcmp(songs[thesong].extnotetype2[a],"27")==0||strcmp(songs[thesong].extnotetype2[a],"g7")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2miss++;
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2rgrade,24,"Miss");
								snprintf(gpg2ggrade,24,"Miss");
								snprintf(gpg2bgrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2lifebar-=lifedifficulty;
								gpg2lifebar-=lifedifficulty;
								gpg2rgradetime=0;
								gpg2ggradetime=0;
								gpg2bgradetime=0;
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"28")==0||strcmp(songs[thesong].extnotetype2[a],"gw")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2wgradetime=0;
							}
						}
					}
				}
			}
			if (testmeasure-(almostlv*currbpm/150)<songposition+(entiresongoffset*currbpm)){
				if (!songs[thesong].g2extnoteplayed[a]){
					if (songs[thesong].extnotesound[a]!=NULL){
						int marmot=alphatoi(songs[thesong].extnotesound[a]);
						if (strcmp(songs[thesong].extnotetype2[a],"20")==0||strcmp(songs[thesong].extnotetype2[a],"g0")==0){
							if (g2ots>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!go){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									go=true;
									if (g2ots<=testmeasure+(perfectlv*currbpm/150)&&g2ots>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2ograde,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										gpg2ogradetime=0;
									}else if(g2ots<=testmeasure+(greatlv*currbpm/150)&&g2ots>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2ograde,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										gpg2ogradetime=0;
									}else if(g2ots<=testmeasure+(goodlv*currbpm/150)&&g2ots>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2currcombo++;
										snprintf(gpg2ograde,24,"Good");
										gpg2score+=2500;
										gpg2ogradetime=0;
									}else if(g2ots<=testmeasure+(almostlv*currbpm/150)&&g2ots>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2ograde,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										gpg2ogradetime=0;
									}
									g2ots=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"21")==0||strcmp(songs[thesong].extnotetype2[a],"g1")==0){
							if (g2bts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!gb){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									gb=true;
									if (g2bts<=testmeasure+(perfectlv*currbpm/150)&&g2bts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2bgrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										g23exp=true;
										g23expc=0;
										gpg2bgradetime=0;
									}else if(g2bts<=testmeasure+(greatlv*currbpm/150)&&g2bts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2bgrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g23exp=true;
										g23expc=1;
										gpg2bgradetime=0;
									}else if(g2bts<=testmeasure+(goodlv*currbpm/150)&&g2bts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2currcombo++;
										snprintf(gpg2bgrade,24,"Good");
										gpg2score+=2500;
										g23exp=true;
										g23expc=2;
										gpg2bgradetime=0;
									}else if(g2bts<=testmeasure+(almostlv*currbpm/150)&&g2bts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2bgrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										g23exp=true;
										g23expc=3;
										gpg2bgradetime=0;
									}
									g2bts=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"22")==0||strcmp(songs[thesong].extnotetype2[a],"g2")==0){
							if (g2gts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!gg){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									gg=true;
									if (g2gts<=testmeasure+(perfectlv*currbpm/150)&&g2gts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2ggrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										g22exp=true;
										g22expc=0;
										gpg2ggradetime=0;
									}else if(g2gts<=testmeasure+(greatlv*currbpm/150)&&g2gts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2ggrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g22exp=true;
										g22expc=1;
										gpg2ggradetime=0;
									}else if(g2gts<=testmeasure+(goodlv*currbpm/150)&&g2gts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2currcombo++;
										snprintf(gpg2ggrade,24,"Good");
										gpg2score+=2500;
										g22exp=true;
										g22expc=2;
										gpg2ggradetime=0;
									}else if(g2gts<=testmeasure+(almostlv*currbpm/150)&&g2gts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2ggrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										g22exp=true;
										g22expc=3;
										gpg2ggradetime=0;
									}
									g2gts=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"23")==0||strcmp(songs[thesong].extnotetype2[a],"g3")==0){
							if (g2gbts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!ggb){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									ggb=true;
									if (g2gbts<=testmeasure+(perfectlv*currbpm/150)&&g2gbts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2ggrade,24,"Perfect");
										snprintf(gpg2bgrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										gpg2lifebar+=pldiff;
										g22exp=true;
										g22expc=0;
										g23exp=true;
										g23expc=0;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
									}else if(g2gbts<=testmeasure+(greatlv*currbpm/150)&&g2gbts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2ggrade,24,"Great");
										snprintf(gpg2bgrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g22exp=true;
										g22expc=1;
										g23exp=true;
										g23expc=1;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
									}else if(g2gbts<=testmeasure+(goodlv*currbpm/150)&&g2gbts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2currcombo++;
										gpg2good++;
										gpg2currcombo++;
										snprintf(gpg2ggrade,24,"Good");
										snprintf(gpg2bgrade,24,"Good");
										gpg2score+=2500;
										gpg2score+=2500;
										g22exp=true;
										g22expc=2;
										g23exp=true;
										g23expc=2;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
									}else if(g2gbts<=testmeasure+(almostlv*currbpm/150)&&g2gbts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2ggrade,24,"Almost");
										snprintf(gpg2bgrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										g22exp=true;
										g22expc=3;
										g23exp=true;
										g23expc=3;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
									}
									g2gbts=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"24")==0||strcmp(songs[thesong].extnotetype2[a],"g4")==0){
							if (g2rts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!gr){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									gr=true;
									if (g2rts<=testmeasure+(perfectlv*currbpm/150)&&g2rts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										g21exp=true;
										g21expc=0;
										gpg2rgradetime=0;
									}else if(g2rts<=testmeasure+(greatlv*currbpm/150)&&g2rts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g21exp=true;
										g21expc=1;
										gpg2rgradetime=0;
									}else if(g2rts<=testmeasure+(goodlv*currbpm/150)&&g2rts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2currcombo++;
										snprintf(gpg2rgrade,24,"Good");
										gpg2score+=2500;
										g21exp=true;
										g21expc=2;
										gpg2rgradetime=0;
									}else if(g2rts<=testmeasure+(almostlv*currbpm/150)&&g2rts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2rgrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										g21exp=true;
										g21expc=3;
										gpg2rgradetime=0;
									}
									g2rts=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"25")==0||strcmp(songs[thesong].extnotetype2[a],"g5")==0){
							if (g2rbts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!grb){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									grb=true;
									if (g2rbts<=testmeasure+(perfectlv*currbpm/150)&&g2rbts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Perfect");
										snprintf(gpg2bgrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										g21exp=true;
										g21expc=0;
										g23exp=true;
										g23expc=0;
										gpg2rgradetime=0;
										gpg2bgradetime=0;
									}else if(g2rbts<=testmeasure+(greatlv*currbpm/150)&&g2rbts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Great");
										snprintf(gpg2bgrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g21exp=true;
										g21expc=1;
										g23exp=true;
										g23expc=1;
										gpg2rgradetime=0;
										gpg2bgradetime=0;
									}else if(g2rbts<=testmeasure+(goodlv*currbpm/150)&&g2rbts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2currcombo++;
										gpg2good++;
										gpg2currcombo++;
										snprintf(gpg2rgrade,24,"Good");
										snprintf(gpg2bgrade,24,"Good");
										gpg2score+=2500;
										gpg2score+=2500;
										g21exp=true;
										g21expc=2;
										g23exp=true;
										g23expc=2;
										gpg2rgradetime=0;
										gpg2bgradetime=0;
									}else if(g2rbts<=testmeasure+(almostlv*currbpm/150)&&g2rbts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2rgrade,24,"Almost");
										snprintf(gpg2bgrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										gpg2score+=1000;
										g21exp=true;
										g21expc=3;
										g23exp=true;
										g23expc=3;
										gpg2rgradetime=0;
										gpg2bgradetime=0;
									}
									g2rbts=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"26")==0||strcmp(songs[thesong].extnotetype2[a],"g6")==0){
							if (g2rgts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!grg){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									grg=true;
									if (g2rgts<=testmeasure+(perfectlv*currbpm/150)&&g2rgts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Perfect");
										snprintf(gpg2ggrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										g21exp=true;
										g21expc=0;
										g22exp=true;
										g22expc=0;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
									}else if(g2rgts<=testmeasure+(greatlv*currbpm/150)&&g2rgts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Great");
										snprintf(gpg2ggrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g21exp=true;
										g21expc=1;
										g22exp=true;
										g22expc=1;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
									}else if(g2rgts<=testmeasure+(goodlv*currbpm/150)&&g2rgts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2good++;
										gpg2currcombo+=2;
										snprintf(gpg2rgrade,24,"Good");
										snprintf(gpg2ggrade,24,"Good");
										gpg2score+=2500;
										gpg2score+=2500;
										g21exp=true;
										g21expc=2;
										g22exp=true;
										g22expc=2;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
									}else if(g2rgts<=testmeasure+(almostlv*currbpm/150)&&g2rgts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2rgrade,24,"Almost");
										snprintf(gpg2ggrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										g21exp=true;
										g21expc=3;
										g22exp=true;
										g22expc=3;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
									}
									g2rgts=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"27")==0||strcmp(songs[thesong].extnotetype2[a],"g7")==0){
							if (g2rgbts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!grgb){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									grgb=true;
									if (g2rgbts<=testmeasure+(perfectlv*currbpm/150)&&g2rgbts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										gpg2perfect++;
										gpg2currcombo++;
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Perfect");
										snprintf(gpg2ggrade,24,"Perfect");
										snprintf(gpg2bgrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										g21exp=true;
										g21expc=0;
										g22exp=true;
										g22expc=0;
										g23exp=true;
										g23expc=0;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
									}else if(g2rgbts<=testmeasure+(greatlv*currbpm/150)&&g2rgbts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										gpg2great++;
										gpg2currcombo++;
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Great");
										snprintf(gpg2bgrade,24,"Great");
										snprintf(gpg2ggrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g21exp=true;
										g21expc=1;
										g22exp=true;
										g22expc=1;
										g23exp=true;
										g23expc=1;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
									}else if(g2rgbts<=testmeasure+(goodlv*currbpm/150)&&g2rgbts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2good++;
										gpg2good++;
										gpg2currcombo+=3;
										snprintf(gpg2rgrade,24,"Good");
										snprintf(gpg2ggrade,24,"Good");
										snprintf(gpg2bgrade,24,"Good");
										gpg2score+=2500;
										gpg2score+=2500;
										gpg2score+=2500;
										g21exp=true;
										g21expc=2;
										g22exp=true;
										g22expc=2;
										g23exp=true;
										g23expc=2;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
									}else if(g2rgbts<=testmeasure+(almostlv*currbpm/150)&&g2rgbts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										gpg2almost++;
										gpg2almost++;
										snprintf(gpg2rgrade,24,"Almost");
										snprintf(gpg2ggrade,24,"Almost");
										snprintf(gpg2bgrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										g21exp=true;
										g21expc=3;
										g22exp=true;
										g22expc=3;
										g23exp=true;
										g23expc=3;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
									}
									g2rgbts=0;
								}
							}
						}
						
						if (strcmp(songs[thesong].extnotetype2[a],"28")==0||strcmp(songs[thesong].extnotetype2[a],"gw")==0){
							if (g2wts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!gw){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									gw=true;
									if (g2wts<=testmeasure+(perfectlv*currbpm/150)&&g2wts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2wgrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2wgradetime=0;
									}else if(g2wts<=testmeasure+(greatlv*currbpm/150)&&g2wts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2wgrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2wgradetime=0;
									}else if(g2wts<=testmeasure+(goodlv*currbpm/150)&&g2wts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										snprintf(gpg2wgrade,24,"Good");
										gpg2score+=2500;
										gpg2wgradetime=0;
									}else if(g2wts<=testmeasure+(almostlv*currbpm/150)&&g2wts>=testmeasure-(almostlv*currbpm/150)){
										snprintf(gpg2wgrade,24,"Almost");
										gpg2score+=1000;
										gpg2wgradetime=0;
									}
									g2wts=0;
								}
							}
						}
					}
				}
			}
		}
	}else{
		if (guit2diff==2){
			long int testmeasure=99999999;//to ignore the next line.
			if (songs[thesong].extnotetime[a]>=0&&songs[thesong].extnotetime[a]<=100000){
				if (songs[thesong].extnotemeas[a]>=0&&songs[thesong].extnotemeas[a]<=999){
					testmeasure=(songs[thesong].extnotemeas[a]*240000+int((double(songs[thesong].extnotetime[a])/10000.0)*240000.0))+(notesoundoffset*currbpm)-(songs[thesong].offset*500);
				}
			}
			//printf("the measure: %i the timing: %i all together: %i ||",songs[thesong].extnotemeas[a]*240000,songs[thesong].extnotetime[a],testmeasure);
			//eh... ^this has like HUGE offset^, but kinda have to have it for those songs that just might be 1BPM ~.O
			if (testmeasure+(almostlv*currbpm/150)<songposition+(entiresongoffset*currbpm)){
				if (!songs[thesong].g2extnoteplayed[a]){
					if (songs[thesong].extnotesound[a]!=NULL){
						//openpick
						if (strcmp(songs[thesong].extnotetype2[a],"a0")==0||strcmp(songs[thesong].extnotetype2[a],"b0")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2ograde,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2ogradetime=0;
							}
						}
						//blue
						if (strcmp(songs[thesong].extnotetype2[a],"a1")==0||strcmp(songs[thesong].extnotetype2[a],"b1")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2bgrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2bgradetime=0;
							}
						}
						//green
						if (strcmp(songs[thesong].extnotetype2[a],"a2")==0||strcmp(songs[thesong].extnotetype2[a],"b2")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2ggrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2ggradetime=0;
							}
						}
						//green+blue
						if (strcmp(songs[thesong].extnotetype2[a],"a3")==0||strcmp(songs[thesong].extnotetype2[a],"b3")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2ggrade,24,"Miss");
								snprintf(gpg2bgrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2lifebar-=lifedifficulty;
								gpg2bgradetime=0;
								gpg2ggradetime=0;
							}
						}
						//red
						if (strcmp(songs[thesong].extnotetype2[a],"a4")==0||strcmp(songs[thesong].extnotetype2[a],"b4")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2rgrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2rgradetime=0;
							}
						}
						//red+blue
						if (strcmp(songs[thesong].extnotetype2[a],"a5")==0||strcmp(songs[thesong].extnotetype2[a],"b5")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2rgrade,24,"Miss");
								snprintf(gpg2bgrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2lifebar-=lifedifficulty;
								gpg2rgradetime=0;
								gpg2bgradetime=0;
							}
						}
						//red+green
						if (strcmp(songs[thesong].extnotetype2[a],"a6")==0||strcmp(songs[thesong].extnotetype2[a],"b6")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2rgrade,24,"Miss");
								snprintf(gpg2ggrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2lifebar-=lifedifficulty;
								gpg2rgradetime=0;
								gpg2ggradetime=0;
							}
						}
						//red+green+blue
						if (strcmp(songs[thesong].extnotetype2[a],"a7")==0||strcmp(songs[thesong].extnotetype2[a],"b7")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								gpg2miss++;
								gpg2miss++;
								gpg2miss++;
								gpg2currcombo=0;
								snprintf(gpg2rgrade,24,"Miss");
								snprintf(gpg2ggrade,24,"Miss");
								snprintf(gpg2bgrade,24,"Miss");
								songs[thesong].g2extnoteplayed[a]=true;
								gpg2lifebar-=lifedifficulty;
								gpg2lifebar-=lifedifficulty;
								gpg2lifebar-=lifedifficulty;
								gpg2rgradetime=0;
								gpg2ggradetime=0;
								gpg2bgradetime=0;
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"a8")==0||strcmp(songs[thesong].extnotetype2[a],"bw")==0){
							if (!songs[thesong].g2extnoteplayed[a]){
								songs[thesong].g2extnoteplayed[a]=true;
							}
						}
					}
				}
			}
			if (testmeasure-(almostlv*currbpm/150)<songposition+(entiresongoffset*currbpm)){
				if (!songs[thesong].g2extnoteplayed[a]){
					if (songs[thesong].extnotesound[a]!=NULL){
						int marmot=alphatoi(songs[thesong].extnotesound[a]);
						if (strcmp(songs[thesong].extnotetype2[a],"a0")==0||strcmp(songs[thesong].extnotetype2[a],"b0")==0){
							if (g2ots>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!go){
									playsound(marmot+256,volbass);
									go=true;
									if (g2ots<=testmeasure+(perfectlv*currbpm/150)&&g2ots>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2ograde,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										gpg2ogradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2ots<=testmeasure+(greatlv*currbpm/150)&&g2ots>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2ograde,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										gpg2ogradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2ots<=testmeasure+(goodlv*currbpm/150)&&g2ots>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2currcombo++;
										snprintf(gpg2ograde,24,"Good");
										gpg2score+=2500;
										gpg2ogradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2ots<=testmeasure+(almostlv*currbpm/150)&&g2ots>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2ograde,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										gpg2ogradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}
									g2ots=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"a1")==0||strcmp(songs[thesong].extnotetype2[a],"b1")==0){
							if (g2bts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!gb){
									playsound(marmot+256,volbass);
									gb=true;
									if (g2bts<=testmeasure+(perfectlv*currbpm/150)&&g2bts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2bgrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										g23exp=true;
										g23expc=0;
										gpg2bgradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2bts<=testmeasure+(greatlv*currbpm/150)&&g2bts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2bgrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g23exp=true;
										g23expc=1;
										gpg2bgradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2bts<=testmeasure+(goodlv*currbpm/150)&&g2bts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2currcombo++;
										snprintf(gpg2bgrade,24,"Good");
										gpg2score+=2500;
										g23exp=true;
										g23expc=2;
										gpg2bgradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2bts<=testmeasure+(almostlv*currbpm/150)&&g2bts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2bgrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										g23exp=true;
										g23expc=3;
										gpg2bgradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}
									g2bts=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"a2")==0||strcmp(songs[thesong].extnotetype2[a],"b2")==0){
							if (g2gts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!gg){
									playsound(marmot+256,volbass);
									gg=true;
									if (g2gts<=testmeasure+(perfectlv*currbpm/150)&&g2gts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2ggrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										g22exp=true;
										g22expc=0;
										gpg2ggradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2gts<=testmeasure+(greatlv*currbpm/150)&&g2gts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2ggrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g22exp=true;
										g22expc=1;
										gpg2ggradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2gts<=testmeasure+(goodlv*currbpm/150)&&g2gts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2currcombo++;
										snprintf(gpg2ggrade,24,"Good");
										gpg2score+=2500;
										g22exp=true;
										g22expc=2;
										gpg2ggradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2gts<=testmeasure+(almostlv*currbpm/150)&&g2gts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2ggrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										g22exp=true;
										g22expc=3;
										gpg2ggradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}
									g2gts=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"a3")==0||strcmp(songs[thesong].extnotetype2[a],"b3")==0){
							if (g2gbts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!ggb){
									playsound(marmot+256,volbass);
									ggb=true;
									if (g2gbts<=testmeasure+(perfectlv*currbpm/150)&&g2gbts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2ggrade,24,"Perfect");
										snprintf(gpg2bgrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										gpg2lifebar+=pldiff;
										g22exp=true;
										g22expc=0;
										g23exp=true;
										g23expc=0;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2gbts<=testmeasure+(greatlv*currbpm/150)&&g2gbts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2ggrade,24,"Great");
										snprintf(gpg2bgrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g22exp=true;
										g22expc=1;
										g23exp=true;
										g23expc=1;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2gbts<=testmeasure+(goodlv*currbpm/150)&&g2gbts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2currcombo++;
										gpg2good++;
										gpg2currcombo++;
										snprintf(gpg2ggrade,24,"Good");
										snprintf(gpg2bgrade,24,"Good");
										gpg2score+=2500;
										gpg2score+=2500;
										g22exp=true;
										g22expc=2;
										g23exp=true;
										g23expc=2;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2gbts<=testmeasure+(almostlv*currbpm/150)&&g2gbts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2ggrade,24,"Almost");
										snprintf(gpg2bgrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										g22exp=true;
										g22expc=3;
										g23exp=true;
										g23expc=3;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}
									g2gbts=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"a4")==0||strcmp(songs[thesong].extnotetype2[a],"b4")==0){
							if (g2rts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!gr){
									playsound(marmot+256,volbass);
									gr=true;
									if (g2rts<=testmeasure+(perfectlv*currbpm/150)&&g2rts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										g21exp=true;
										g21expc=0;
										gpg2rgradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2rts<=testmeasure+(greatlv*currbpm/150)&&g2rts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g21exp=true;
										g21expc=1;
										gpg2rgradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2rts<=testmeasure+(goodlv*currbpm/150)&&g2rts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2currcombo++;
										snprintf(gpg2rgrade,24,"Good");
										gpg2score+=2500;
										g21exp=true;
										g21expc=2;
										gpg2rgradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}else if(g2rts<=testmeasure+(almostlv*currbpm/150)&&g2rts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2rgrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										g21exp=true;
										g21expc=3;
										gpg2rgradetime=0;
										songs[thesong].g2extnoteplayed[a]=true;
									}
									g2rts=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"a5")==0||strcmp(songs[thesong].extnotetype2[a],"b5")==0){
							if (g2rbts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!grb){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									grb=true;
									if (g2rbts<=testmeasure+(perfectlv*currbpm/150)&&g2rbts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Perfect");
										snprintf(gpg2bgrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										g21exp=true;
										g21expc=0;
										g23exp=true;
										g23expc=0;
										gpg2rgradetime=0;
										gpg2bgradetime=0;
									}else if(g2rbts<=testmeasure+(greatlv*currbpm/150)&&g2rbts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Great");
										snprintf(gpg2bgrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g21exp=true;
										g21expc=1;
										g23exp=true;
										g23expc=1;
										gpg2rgradetime=0;
										gpg2bgradetime=0;
									}else if(g2rbts<=testmeasure+(goodlv*currbpm/150)&&g2rbts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2currcombo++;
										gpg2good++;
										gpg2currcombo++;
										snprintf(gpg2rgrade,24,"Good");
										snprintf(gpg2bgrade,24,"Good");
										gpg2score+=2500;
										gpg2score+=2500;
										g21exp=true;
										g21expc=2;
										g23exp=true;
										g23expc=2;
										gpg2rgradetime=0;
										gpg2bgradetime=0;
									}else if(g2rbts<=testmeasure+(almostlv*currbpm/150)&&g2rbts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2rgrade,24,"Almost");
										snprintf(gpg2bgrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										gpg2score+=1000;
										g21exp=true;
										g21expc=3;
										g23exp=true;
										g23expc=3;
										gpg2rgradetime=0;
										gpg2bgradetime=0;
									}
									g2rbts=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"a6")==0||strcmp(songs[thesong].extnotetype2[a],"b6")==0){
							if (g2rgts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!grg){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									grg=true;
									if (g2rgts<=testmeasure+(perfectlv*currbpm/150)&&g2rgts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Perfect");
										snprintf(gpg2ggrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										g21exp=true;
										g21expc=0;
										g22exp=true;
										g22expc=0;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
									}else if(g2rgts<=testmeasure+(greatlv*currbpm/150)&&g2rgts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Great");
										snprintf(gpg2ggrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g21exp=true;
										g21expc=1;
										g22exp=true;
										g22expc=1;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
									}else if(g2rgts<=testmeasure+(goodlv*currbpm/150)&&g2rgts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2good++;
										gpg2currcombo++;
										gpg2currcombo++;
										snprintf(gpg2rgrade,24,"Good");
										snprintf(gpg2ggrade,24,"Good");
										gpg2score+=2500;
										gpg2score+=2500;
										g21exp=true;
										g21expc=2;
										g22exp=true;
										g22expc=2;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
									}else if(g2rgts<=testmeasure+(almostlv*currbpm/150)&&g2rgts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2almost++;
										gpg2currcombo=0;
										snprintf(gpg2rgrade,24,"Almost");
										snprintf(gpg2ggrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										g21exp=true;
										g21expc=3;
										g22exp=true;
										g22expc=3;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
									}
									g2rgts=0;
								}
							}
						}
						if (strcmp(songs[thesong].extnotetype2[a],"a7")==0||strcmp(songs[thesong].extnotetype2[a],"b7")==0){
							if (g2rgbts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!grgb){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									grgb=true;
									if (g2rgbts<=testmeasure+(perfectlv*currbpm/150)&&g2rgbts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										gpg2perfect++;
										gpg2currcombo++;
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Perfect");
										snprintf(gpg2ggrade,24,"Perfect");
										snprintf(gpg2bgrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=pldiff;
										g21exp=true;
										g21expc=0;
										g22exp=true;
										g22expc=0;
										g23exp=true;
										g23expc=0;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
									}else if(g2rgbts<=testmeasure+(greatlv*currbpm/150)&&g2rgbts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										gpg2great++;
										gpg2currcombo++;
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2rgrade,24,"Great");
										snprintf(gpg2bgrade,24,"Great");
										snprintf(gpg2ggrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2lifebar+=gldiff;
										g21exp=true;
										g21expc=1;
										g22exp=true;
										g22expc=1;
										g23exp=true;
										g23expc=1;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
									}else if(g2rgbts<=testmeasure+(goodlv*currbpm/150)&&g2rgbts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										gpg2good++;
										gpg2good++;
										gpg2currcombo+=3;
										snprintf(gpg2rgrade,24,"Good");
										snprintf(gpg2ggrade,24,"Good");
										snprintf(gpg2bgrade,24,"Good");
										gpg2score+=2500;
										gpg2score+=2500;
										gpg2score+=2500;
										g21exp=true;
										g21expc=2;
										g22exp=true;
										g22expc=2;
										g23exp=true;
										g23expc=2;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
									}else if(g2rgbts<=testmeasure+(almostlv*currbpm/150)&&g2rgbts>=testmeasure-(almostlv*currbpm/150)){
										gpg2almost++;
										gpg2currcombo=0;
										gpg2almost++;
										gpg2almost++;
										snprintf(gpg2rgrade,24,"Almost");
										snprintf(gpg2ggrade,24,"Almost");
										snprintf(gpg2bgrade,24,"Almost");
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										gpg2lifebar-=lifedifficulty/2;
										gpg2score+=1000;
										g21exp=true;
										g21expc=3;
										g22exp=true;
										g22expc=3;
										g23exp=true;
										g23expc=3;
										gpg2rgradetime=0;
										gpg2ggradetime=0;
										gpg2bgradetime=0;
									}
									g2rgbts=0;
								}
							}
						}
						
						if (strcmp(songs[thesong].extnotetype2[a],"a8")==0||strcmp(songs[thesong].extnotetype2[a],"bw")==0){
							if (g2wts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g2extnoteplayed[a]){
								if (!gw){
									playsound(marmot+256,volbass);
									songs[thesong].g2extnoteplayed[a]=true;
									gw=true;
									if (g2wts<=testmeasure+(perfectlv*currbpm/150)&&g2wts>=testmeasure-(perfectlv*currbpm/150)){
										gpg2perfect++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2wgrade,24,"Perfect");
										gpg2score+=10000+(100*gpg2currcombo)+gpg2currcombo;
										gpg2wgradetime=0;
									}else if(g2wts<=testmeasure+(greatlv*currbpm/150)&&g2wts>=testmeasure-(greatlv*currbpm/150)){
										gpg2great++;
										gpg2currcombo++;
										if (gpg2maxcombo<gpg2currcombo){
											gpg2maxcombo=gpg2currcombo;
										}
										snprintf(gpg2wgrade,24,"Great");
										gpg2score+=5000+(50*gpg2currcombo)+gpg2currcombo;
										gpg2wgradetime=0;
									}else if(g2wts<=testmeasure+(goodlv*currbpm/150)&&g2wts>=testmeasure-(goodlv*currbpm/150)){
										gpg2good++;
										snprintf(gpg2wgrade,24,"Good");
										gpg2score+=2500;
										gpg2wgradetime=0;
									}else if(g2wts<=testmeasure+(almostlv*currbpm/150)&&g2wts>=testmeasure-(almostlv*currbpm/150)){
										snprintf(gpg2wgrade,24,"Almost");
										gpg2score+=1000;
										gpg2wgradetime=0;
									}
									g2wts=0;
								}
							}
						}
					}
				}
			}
		}
	}
}
