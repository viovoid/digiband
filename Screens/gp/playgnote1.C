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
void playnote_g1adv(int a,bool &gb,bool &gg,bool &ggb,bool &gr,bool &grb,bool &grg,bool &grgb,bool &gw,bool &go){
	#ifdef EXCESSIVE
	printf("playnote_g1adv\n");
	#endif
	if (guitar1treb){
		if (guit1diff==1){
			long int testmeasure=99999999;//to ignore the nadv line.
			if (songs[thesong].advnotetime[a]>=0&&songs[thesong].advnotetime[a]<=100000){
				if (songs[thesong].advnotemeas[a]>=0&&songs[thesong].advnotemeas[a]<=999){
					testmeasure=(songs[thesong].advnotemeas[a]*240000+int((double(songs[thesong].advnotetime[a])/10000.0)*240000.0))+(notesoundoffset*currbpm)-(songs[thesong].offset*500);
				}
			}
			//printf("the measure: %i the timing: %i all together: %i ||",songs[thesong].advnotemeas[a]*240000,songs[thesong].advnotetime[a],testmeasure);
			//eh... ^this has like HUGE offset^, but kinda have to have it for those songs that just might be 1BPM ~.O
			if (testmeasure+(almostlv*currbpm/150)<songposition+(entiresongoffset*currbpm)){
				if (!songs[thesong].g1advnoteplayed[a]){
					if (songs[thesong].advnotesound[a]!=NULL){
						//openpick
						if (strcmp(songs[thesong].advnotetype[a],"20")==0||strcmp(songs[thesong].advnotetype[a],"g0")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1ograde,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1ogradetime=0;
							}
						}
						//blue
						if (strcmp(songs[thesong].advnotetype[a],"21")==0||strcmp(songs[thesong].advnotetype[a],"g1")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1bgrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1bgradetime=0;
							}
						}
						//green
						if (strcmp(songs[thesong].advnotetype[a],"22")==0||strcmp(songs[thesong].advnotetype[a],"g2")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1ggrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1ggradetime=0;
							}
						}
						//green+blue
						if (strcmp(songs[thesong].advnotetype[a],"23")==0||strcmp(songs[thesong].advnotetype[a],"g3")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1ggrade,24,"Miss");
								snprintf(gpg1bgrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1lifebar-=lifedifficulty;
								gpg1ggradetime=0;
								gpg1bgradetime=0;
							}
						}
						//red
						if (strcmp(songs[thesong].advnotetype[a],"24")==0||strcmp(songs[thesong].advnotetype[a],"g4")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1rgrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1rgradetime=0;
							}
						}
						//red+blue
						if (strcmp(songs[thesong].advnotetype[a],"25")==0||strcmp(songs[thesong].advnotetype[a],"g5")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1rgrade,24,"Miss");
								snprintf(gpg1bgrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1lifebar-=lifedifficulty;
								gpg1rgradetime=0;
								gpg1bgradetime=0;
							}
						}
						//red+green
						if (strcmp(songs[thesong].advnotetype[a],"26")==0||strcmp(songs[thesong].advnotetype[a],"g6")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1rgrade,24,"Miss");
								snprintf(gpg1ggrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1lifebar-=lifedifficulty;
								gpg1rgradetime=0;
								gpg1ggradetime=0;
							}
						}
						//red+green+blue
						if (strcmp(songs[thesong].advnotetype[a],"27")==0||strcmp(songs[thesong].advnotetype[a],"g7")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1miss++;
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1rgrade,24,"Miss");
								snprintf(gpg1ggrade,24,"Miss");
								snprintf(gpg1bgrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1lifebar-=lifedifficulty;
								gpg1lifebar-=lifedifficulty;
								gpg1rgradetime=0;
								gpg1ggradetime=0;
								gpg1bgradetime=0;
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"28")==0||strcmp(songs[thesong].advnotetype[a],"gw")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1wgradetime=0;
							}
						}
					}
				}
			}
			if (testmeasure-(almostlv*currbpm/150)<songposition+(entiresongoffset*currbpm)){
				if (!songs[thesong].g1advnoteplayed[a]){
					if (songs[thesong].advnotesound[a]!=NULL){
						int marmot=alphatoi(songs[thesong].advnotesound[a]);
						if (strcmp(songs[thesong].advnotetype[a],"20")==0||strcmp(songs[thesong].advnotetype[a],"g0")==0){
							if (g1ots>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!go){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									go=true;
									if (g1ots<=testmeasure+(perfectlv*currbpm/150)&&g1ots>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1ograde,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										gpg1ogradetime=0;
									}else if(g1ots<=testmeasure+(greatlv*currbpm/150)&&g1ots>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1ograde,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										gpg1ogradetime=0;
									}else if(g1ots<=testmeasure+(goodlv*currbpm/150)&&g1ots>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1currcombo++;
										snprintf(gpg1ograde,24,"Good");
										gpg1score+=2500;
										gpg1ogradetime=0;
									}else if(g1ots<=testmeasure+(almostlv*currbpm/150)&&g1ots>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1ograde,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										gpg1ogradetime=0;
									}
									g1ots=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"21")==0||strcmp(songs[thesong].advnotetype[a],"g1")==0){
							if (g1bts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!gb){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									gb=true;
									if (g1bts<=testmeasure+(perfectlv*currbpm/150)&&g1bts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1bgrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										g13exp=true;
										g13expc=0;
										gpg1bgradetime=0;
									}else if(g1bts<=testmeasure+(greatlv*currbpm/150)&&g1bts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1bgrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g13exp=true;
										g13expc=1;
										gpg1bgradetime=0;
									}else if(g1bts<=testmeasure+(goodlv*currbpm/150)&&g1bts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1currcombo++;
										snprintf(gpg1bgrade,24,"Good");
										gpg1score+=2500;
										g13exp=true;
										g13expc=2;
										gpg1bgradetime=0;
									}else if(g1bts<=testmeasure+(almostlv*currbpm/150)&&g1bts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1bgrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										g13exp=true;
										g13expc=3;
										gpg1bgradetime=0;
									}
									g1bts=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"22")==0||strcmp(songs[thesong].advnotetype[a],"g2")==0){
							if (g1gts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!gg){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									gg=true;
									if (g1gts<=testmeasure+(perfectlv*currbpm/150)&&g1gts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1ggrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										g12exp=true;
										g12expc=0;
										gpg1ggradetime=0;
									}else if(g1gts<=testmeasure+(greatlv*currbpm/150)&&g1gts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1ggrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g12exp=true;
										g12expc=1;
										gpg1ggradetime=0;
									}else if(g1gts<=testmeasure+(goodlv*currbpm/150)&&g1gts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1currcombo++;
										snprintf(gpg1ggrade,24,"Good");
										gpg1score+=2500;
										g12exp=true;
										g12expc=2;
										gpg1ggradetime=0;
									}else if(g1gts<=testmeasure+(almostlv*currbpm/150)&&g1gts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1ggrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										g12exp=true;
										g12expc=3;
										gpg1ggradetime=0;
									}
									g1gts=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"23")==0||strcmp(songs[thesong].advnotetype[a],"g3")==0){
							if (g1gbts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!ggb){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									ggb=true;
									if (g1gbts<=testmeasure+(perfectlv*currbpm/150)&&g1gbts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1ggrade,24,"Perfect");
										snprintf(gpg1bgrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										gpg1lifebar+=pldiff;
										g12exp=true;
										g12expc=0;
										g13exp=true;
										g13expc=0;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
									}else if(g1gbts<=testmeasure+(greatlv*currbpm/150)&&g1gbts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1ggrade,24,"Great");
										snprintf(gpg1bgrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g12exp=true;
										g12expc=1;
										g13exp=true;
										g13expc=1;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
									}else if(g1gbts<=testmeasure+(goodlv*currbpm/150)&&g1gbts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1currcombo++;
										gpg1good++;
										gpg1currcombo++;
										snprintf(gpg1ggrade,24,"Good");
										snprintf(gpg1bgrade,24,"Good");
										gpg1score+=2500;
										gpg1score+=2500;
										g12exp=true;
										g12expc=2;
										g13exp=true;
										g13expc=2;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
									}else if(g1gbts<=testmeasure+(almostlv*currbpm/150)&&g1gbts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1ggrade,24,"Almost");
										snprintf(gpg1bgrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										g12exp=true;
										g12expc=3;
										g13exp=true;
										g13expc=3;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
									}
									g1gbts=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"24")==0||strcmp(songs[thesong].advnotetype[a],"g4")==0){
							if (g1rts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!gr){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									gr=true;
									if (g1rts<=testmeasure+(perfectlv*currbpm/150)&&g1rts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										g11exp=true;
										g11expc=0;
										gpg1rgradetime=0;
									}else if(g1rts<=testmeasure+(greatlv*currbpm/150)&&g1rts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g11exp=true;
										g11expc=1;
										gpg1rgradetime=0;
									}else if(g1rts<=testmeasure+(goodlv*currbpm/150)&&g1rts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1currcombo++;
										snprintf(gpg1rgrade,24,"Good");
										gpg1score+=2500;
										g11exp=true;
										g11expc=2;
										gpg1rgradetime=0;
									}else if(g1rts<=testmeasure+(almostlv*currbpm/150)&&g1rts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1rgrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										g11exp=true;
										g11expc=3;
										gpg1rgradetime=0;
									}
									g1rts=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"25")==0||strcmp(songs[thesong].advnotetype[a],"g5")==0){
							if (g1rbts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!grb){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									grb=true;
									if (g1rbts<=testmeasure+(perfectlv*currbpm/150)&&g1rbts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Perfect");
										snprintf(gpg1bgrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										g11exp=true;
										g11expc=0;
										g13exp=true;
										g13expc=0;
										gpg1rgradetime=0;
										gpg1bgradetime=0;
									}else if(g1rbts<=testmeasure+(greatlv*currbpm/150)&&g1rbts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Great");
										snprintf(gpg1bgrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g11exp=true;
										g11expc=1;
										g13exp=true;
										g13expc=1;
										gpg1rgradetime=0;
										gpg1bgradetime=0;
									}else if(g1rbts<=testmeasure+(goodlv*currbpm/150)&&g1rbts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1currcombo++;
										gpg1good++;
										gpg1currcombo++;
										snprintf(gpg1rgrade,24,"Good");
										snprintf(gpg1bgrade,24,"Good");
										gpg1score+=2500;
										gpg1score+=2500;
										g11exp=true;
										g11expc=2;
										g13exp=true;
										g13expc=2;
										gpg1rgradetime=0;
										gpg1bgradetime=0;
									}else if(g1rbts<=testmeasure+(almostlv*currbpm/150)&&g1rbts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1rgrade,24,"Almost");
										snprintf(gpg1bgrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										gpg1score+=1000;
										g11exp=true;
										g11expc=3;
										g13exp=true;
										g13expc=3;
										gpg1rgradetime=0;
										gpg1bgradetime=0;
									}
									g1rbts=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"26")==0||strcmp(songs[thesong].advnotetype[a],"g6")==0){
							if (g1rgts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!grg){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									grg=true;
									if (g1rgts<=testmeasure+(perfectlv*currbpm/150)&&g1rgts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Perfect");
										snprintf(gpg1ggrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										g11exp=true;
										g11expc=0;
										g12exp=true;
										g12expc=0;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
									}else if(g1rgts<=testmeasure+(greatlv*currbpm/150)&&g1rgts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Great");
										snprintf(gpg1ggrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g11exp=true;
										g11expc=1;
										g12exp=true;
										g12expc=1;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
									}else if(g1rgts<=testmeasure+(goodlv*currbpm/150)&&g1rgts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1good++;
										gpg1currcombo+=2;
										snprintf(gpg1rgrade,24,"Good");
										snprintf(gpg1ggrade,24,"Good");
										gpg1score+=2500;
										gpg1score+=2500;
										g11exp=true;
										g11expc=2;
										g12exp=true;
										g12expc=2;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
									}else if(g1rgts<=testmeasure+(almostlv*currbpm/150)&&g1rgts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1rgrade,24,"Almost");
										snprintf(gpg1ggrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										g11exp=true;
										g11expc=3;
										g12exp=true;
										g12expc=3;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
									}
									g1rgts=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"27")==0||strcmp(songs[thesong].advnotetype[a],"g7")==0){
							if (g1rgbts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!grgb){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									grgb=true;
									if (g1rgbts<=testmeasure+(perfectlv*currbpm/150)&&g1rgbts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										gpg1perfect++;
										gpg1currcombo++;
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Perfect");
										snprintf(gpg1ggrade,24,"Perfect");
										snprintf(gpg1bgrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										g11exp=true;
										g11expc=0;
										g12exp=true;
										g12expc=0;
										g13exp=true;
										g13expc=0;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
									}else if(g1rgbts<=testmeasure+(greatlv*currbpm/150)&&g1rgbts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										gpg1great++;
										gpg1currcombo++;
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Great");
										snprintf(gpg1bgrade,24,"Great");
										snprintf(gpg1ggrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g11exp=true;
										g11expc=1;
										g12exp=true;
										g12expc=1;
										g13exp=true;
										g13expc=1;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
									}else if(g1rgbts<=testmeasure+(goodlv*currbpm/150)&&g1rgbts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1good++;
										gpg1good++;
										gpg1currcombo+=3;
										snprintf(gpg1rgrade,24,"Good");
										snprintf(gpg1ggrade,24,"Good");
										snprintf(gpg1bgrade,24,"Good");
										gpg1score+=2500;
										gpg1score+=2500;
										gpg1score+=2500;
										g11exp=true;
										g11expc=2;
										g12exp=true;
										g12expc=2;
										g13exp=true;
										g13expc=2;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
									}else if(g1rgbts<=testmeasure+(almostlv*currbpm/150)&&g1rgbts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										gpg1almost++;
										gpg1almost++;
										snprintf(gpg1rgrade,24,"Almost");
										snprintf(gpg1ggrade,24,"Almost");
										snprintf(gpg1bgrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										g11exp=true;
										g11expc=3;
										g12exp=true;
										g12expc=3;
										g13exp=true;
										g13expc=3;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
									}
									g1rgbts=0;
								}
							}
						}
						
						if (strcmp(songs[thesong].advnotetype[a],"28")==0||strcmp(songs[thesong].advnotetype[a],"gw")==0){
							if (g1wts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!gw){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									gw=true;
									if (g1wts<=testmeasure+(perfectlv*currbpm/150)&&g1wts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1wgrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1wgradetime=0;
									}else if(g1wts<=testmeasure+(greatlv*currbpm/150)&&g1wts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1wgrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1wgradetime=0;
									}else if(g1wts<=testmeasure+(goodlv*currbpm/150)&&g1wts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										snprintf(gpg1wgrade,24,"Good");
										gpg1score+=2500;
										gpg1wgradetime=0;
									}else if(g1wts<=testmeasure+(almostlv*currbpm/150)&&g1wts>=testmeasure-(almostlv*currbpm/150)){
										snprintf(gpg1wgrade,24,"Almost");
										gpg1score+=1000;
										gpg1wgradetime=0;
									}
									g1wts=0;
								}
							}
						}
					}
				}
			}
		}
	}else{
		if (guit1diff==1){
			long int testmeasure=99999999;//to ignore the nadv line.
			if (songs[thesong].advnotetime[a]>=0&&songs[thesong].advnotetime[a]<=100000){
				if (songs[thesong].advnotemeas[a]>=0&&songs[thesong].advnotemeas[a]<=999){
					testmeasure=(songs[thesong].advnotemeas[a]*240000+int((double(songs[thesong].advnotetime[a])/10000.0)*240000.0))+(notesoundoffset*currbpm)-(songs[thesong].offset*500);
				}
			}
			//printf("the measure: %i the timing: %i all together: %i ||",songs[thesong].advnotemeas[a]*240000,songs[thesong].advnotetime[a],testmeasure);
			//eh... ^this has like HUGE offset^, but kinda have to have it for those songs that just might be 1BPM ~.O
			if (testmeasure+(almostlv*currbpm/150)<songposition+(entiresongoffset*currbpm)){
				if (!songs[thesong].g1advnoteplayed[a]){
					if (songs[thesong].advnotesound[a]!=NULL){
						//openpick
						if (strcmp(songs[thesong].advnotetype[a],"a0")==0||strcmp(songs[thesong].advnotetype[a],"b0")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1ograde,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1ogradetime=0;
							}
						}
						//blue
						if (strcmp(songs[thesong].advnotetype[a],"a1")==0||strcmp(songs[thesong].advnotetype[a],"b1")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1bgrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1bgradetime=0;
							}
						}
						//green
						if (strcmp(songs[thesong].advnotetype[a],"a2")==0||strcmp(songs[thesong].advnotetype[a],"b2")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1ggrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1ggradetime=0;
							}
						}
						//green+blue
						if (strcmp(songs[thesong].advnotetype[a],"a3")==0||strcmp(songs[thesong].advnotetype[a],"b3")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1ggrade,24,"Miss");
								snprintf(gpg1bgrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1lifebar-=lifedifficulty;
								gpg1bgradetime=0;
								gpg1ggradetime=0;
							}
						}
						//red
						if (strcmp(songs[thesong].advnotetype[a],"a4")==0||strcmp(songs[thesong].advnotetype[a],"b4")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1rgrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1rgradetime=0;
							}
						}
						//red+blue
						if (strcmp(songs[thesong].advnotetype[a],"a5")==0||strcmp(songs[thesong].advnotetype[a],"b5")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1rgrade,24,"Miss");
								snprintf(gpg1bgrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1lifebar-=lifedifficulty;
								gpg1rgradetime=0;
								gpg1bgradetime=0;
							}
						}
						//red+green
						if (strcmp(songs[thesong].advnotetype[a],"a6")==0||strcmp(songs[thesong].advnotetype[a],"b6")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1rgrade,24,"Miss");
								snprintf(gpg1ggrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1lifebar-=lifedifficulty;
								gpg1rgradetime=0;
								gpg1ggradetime=0;
							}
						}
						//red+green+blue
						if (strcmp(songs[thesong].advnotetype[a],"a7")==0||strcmp(songs[thesong].advnotetype[a],"b7")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								gpg1miss++;
								gpg1miss++;
								gpg1miss++;
								gpg1currcombo=0;
								snprintf(gpg1rgrade,24,"Miss");
								snprintf(gpg1ggrade,24,"Miss");
								snprintf(gpg1bgrade,24,"Miss");
								songs[thesong].g1advnoteplayed[a]=true;
								gpg1lifebar-=lifedifficulty;
								gpg1lifebar-=lifedifficulty;
								gpg1lifebar-=lifedifficulty;
								gpg1rgradetime=0;
								gpg1ggradetime=0;
								gpg1bgradetime=0;
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"a8")==0||strcmp(songs[thesong].advnotetype[a],"bw")==0){
							if (!songs[thesong].g1advnoteplayed[a]){
								songs[thesong].g1advnoteplayed[a]=true;
							}
						}
					}
				}
			}
			if (testmeasure-(almostlv*currbpm/150)<songposition+(entiresongoffset*currbpm)){
				if (!songs[thesong].g1advnoteplayed[a]){
					if (songs[thesong].advnotesound[a]!=NULL){
						int marmot=alphatoi(songs[thesong].advnotesound[a]);
						if (strcmp(songs[thesong].advnotetype[a],"a0")==0||strcmp(songs[thesong].advnotetype[a],"b0")==0){
							if (g1ots>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!go){
									playsound(marmot+256,volguit);
									go=true;
									if (g1ots<=testmeasure+(perfectlv*currbpm/150)&&g1ots>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1ograde,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										gpg1ogradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1ots<=testmeasure+(greatlv*currbpm/150)&&g1ots>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1ograde,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										gpg1ogradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1ots<=testmeasure+(goodlv*currbpm/150)&&g1ots>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1currcombo++;
										snprintf(gpg1ograde,24,"Good");
										gpg1score+=2500;
										gpg1ogradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1ots<=testmeasure+(almostlv*currbpm/150)&&g1ots>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1ograde,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										gpg1ogradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}
									g1ots=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"a1")==0||strcmp(songs[thesong].advnotetype[a],"b1")==0){
							if (g1bts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!gb){
									playsound(marmot+256,volguit);
									gb=true;
									if (g1bts<=testmeasure+(perfectlv*currbpm/150)&&g1bts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1bgrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										g13exp=true;
										g13expc=0;
										gpg1bgradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1bts<=testmeasure+(greatlv*currbpm/150)&&g1bts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1bgrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g13exp=true;
										g13expc=1;
										gpg1bgradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1bts<=testmeasure+(goodlv*currbpm/150)&&g1bts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1currcombo++;
										snprintf(gpg1bgrade,24,"Good");
										gpg1score+=2500;
										g13exp=true;
										g13expc=2;
										gpg1bgradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1bts<=testmeasure+(almostlv*currbpm/150)&&g1bts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1bgrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										g13exp=true;
										g13expc=3;
										gpg1bgradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}
									g1bts=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"a2")==0||strcmp(songs[thesong].advnotetype[a],"b2")==0){
							if (g1gts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!gg){
									playsound(marmot+256,volguit);
									gg=true;
									if (g1gts<=testmeasure+(perfectlv*currbpm/150)&&g1gts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1ggrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										g12exp=true;
										g12expc=0;
										gpg1ggradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1gts<=testmeasure+(greatlv*currbpm/150)&&g1gts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1ggrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g12exp=true;
										g12expc=1;
										gpg1ggradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1gts<=testmeasure+(goodlv*currbpm/150)&&g1gts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1currcombo++;
										snprintf(gpg1ggrade,24,"Good");
										gpg1score+=2500;
										g12exp=true;
										g12expc=2;
										gpg1ggradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1gts<=testmeasure+(almostlv*currbpm/150)&&g1gts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1ggrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										g12exp=true;
										g12expc=3;
										gpg1ggradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}
									g1gts=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"a3")==0||strcmp(songs[thesong].advnotetype[a],"b3")==0){
							if (g1gbts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!ggb){
									playsound(marmot+256,volguit);
									ggb=true;
									if (g1gbts<=testmeasure+(perfectlv*currbpm/150)&&g1gbts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1ggrade,24,"Perfect");
										snprintf(gpg1bgrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										gpg1lifebar+=pldiff;
										g12exp=true;
										g12expc=0;
										g13exp=true;
										g13expc=0;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1gbts<=testmeasure+(greatlv*currbpm/150)&&g1gbts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1ggrade,24,"Great");
										snprintf(gpg1bgrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g12exp=true;
										g12expc=1;
										g13exp=true;
										g13expc=1;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1gbts<=testmeasure+(goodlv*currbpm/150)&&g1gbts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1currcombo++;
										gpg1good++;
										gpg1currcombo++;
										snprintf(gpg1ggrade,24,"Good");
										snprintf(gpg1bgrade,24,"Good");
										gpg1score+=2500;
										gpg1score+=2500;
										g12exp=true;
										g12expc=2;
										g13exp=true;
										g13expc=2;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1gbts<=testmeasure+(almostlv*currbpm/150)&&g1gbts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1ggrade,24,"Almost");
										snprintf(gpg1bgrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										g12exp=true;
										g12expc=3;
										g13exp=true;
										g13expc=3;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}
									g1gbts=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"a4")==0||strcmp(songs[thesong].advnotetype[a],"b4")==0){
							if (g1rts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!gr){
									playsound(marmot+256,volguit);
									gr=true;
									if (g1rts<=testmeasure+(perfectlv*currbpm/150)&&g1rts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										g11exp=true;
										g11expc=0;
										gpg1rgradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1rts<=testmeasure+(greatlv*currbpm/150)&&g1rts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g11exp=true;
										g11expc=1;
										gpg1rgradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1rts<=testmeasure+(goodlv*currbpm/150)&&g1rts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1currcombo++;
										snprintf(gpg1rgrade,24,"Good");
										gpg1score+=2500;
										g11exp=true;
										g11expc=2;
										gpg1rgradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}else if(g1rts<=testmeasure+(almostlv*currbpm/150)&&g1rts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1rgrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										g11exp=true;
										g11expc=3;
										gpg1rgradetime=0;
										songs[thesong].g1advnoteplayed[a]=true;
									}
									g1rts=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"a5")==0||strcmp(songs[thesong].advnotetype[a],"b5")==0){
							if (g1rbts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!grb){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									grb=true;
									if (g1rbts<=testmeasure+(perfectlv*currbpm/150)&&g1rbts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Perfect");
										snprintf(gpg1bgrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										g11exp=true;
										g11expc=0;
										g13exp=true;
										g13expc=0;
										gpg1rgradetime=0;
										gpg1bgradetime=0;
									}else if(g1rbts<=testmeasure+(greatlv*currbpm/150)&&g1rbts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Great");
										snprintf(gpg1bgrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g11exp=true;
										g11expc=1;
										g13exp=true;
										g13expc=1;
										gpg1rgradetime=0;
										gpg1bgradetime=0;
									}else if(g1rbts<=testmeasure+(goodlv*currbpm/150)&&g1rbts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1currcombo++;
										gpg1good++;
										gpg1currcombo++;
										snprintf(gpg1rgrade,24,"Good");
										snprintf(gpg1bgrade,24,"Good");
										gpg1score+=2500;
										gpg1score+=2500;
										g11exp=true;
										g11expc=2;
										g13exp=true;
										g13expc=2;
										gpg1rgradetime=0;
										gpg1bgradetime=0;
									}else if(g1rbts<=testmeasure+(almostlv*currbpm/150)&&g1rbts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1rgrade,24,"Almost");
										snprintf(gpg1bgrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										gpg1score+=1000;
										g11exp=true;
										g11expc=3;
										g13exp=true;
										g13expc=3;
										gpg1rgradetime=0;
										gpg1bgradetime=0;
									}
									g1rbts=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"a6")==0||strcmp(songs[thesong].advnotetype[a],"b6")==0){
							if (g1rgts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!grg){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									grg=true;
									if (g1rgts<=testmeasure+(perfectlv*currbpm/150)&&g1rgts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Perfect");
										snprintf(gpg1ggrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										g11exp=true;
										g11expc=0;
										g12exp=true;
										g12expc=0;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
									}else if(g1rgts<=testmeasure+(greatlv*currbpm/150)&&g1rgts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Great");
										snprintf(gpg1ggrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g11exp=true;
										g11expc=1;
										g12exp=true;
										g12expc=1;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
									}else if(g1rgts<=testmeasure+(goodlv*currbpm/150)&&g1rgts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1good++;
										gpg1currcombo++;
										gpg1currcombo++;
										snprintf(gpg1rgrade,24,"Good");
										snprintf(gpg1ggrade,24,"Good");
										gpg1score+=2500;
										gpg1score+=2500;
										g11exp=true;
										g11expc=2;
										g12exp=true;
										g12expc=2;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
									}else if(g1rgts<=testmeasure+(almostlv*currbpm/150)&&g1rgts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1almost++;
										gpg1currcombo=0;
										snprintf(gpg1rgrade,24,"Almost");
										snprintf(gpg1ggrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										g11exp=true;
										g11expc=3;
										g12exp=true;
										g12expc=3;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
									}
									g1rgts=0;
								}
							}
						}
						if (strcmp(songs[thesong].advnotetype[a],"a7")==0||strcmp(songs[thesong].advnotetype[a],"b7")==0){
							if (g1rgbts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!grgb){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									grgb=true;
									if (g1rgbts<=testmeasure+(perfectlv*currbpm/150)&&g1rgbts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										gpg1perfect++;
										gpg1currcombo++;
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Perfect");
										snprintf(gpg1ggrade,24,"Perfect");
										snprintf(gpg1bgrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=pldiff;
										g11exp=true;
										g11expc=0;
										g12exp=true;
										g12expc=0;
										g13exp=true;
										g13expc=0;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
									}else if(g1rgbts<=testmeasure+(greatlv*currbpm/150)&&g1rgbts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										gpg1great++;
										gpg1currcombo++;
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1rgrade,24,"Great");
										snprintf(gpg1bgrade,24,"Great");
										snprintf(gpg1ggrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1lifebar+=gldiff;
										g11exp=true;
										g11expc=1;
										g12exp=true;
										g12expc=1;
										g13exp=true;
										g13expc=1;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
									}else if(g1rgbts<=testmeasure+(goodlv*currbpm/150)&&g1rgbts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										gpg1good++;
										gpg1good++;
										gpg1currcombo+=3;
										snprintf(gpg1rgrade,24,"Good");
										snprintf(gpg1ggrade,24,"Good");
										snprintf(gpg1bgrade,24,"Good");
										gpg1score+=2500;
										gpg1score+=2500;
										gpg1score+=2500;
										g11exp=true;
										g11expc=2;
										g12exp=true;
										g12expc=2;
										g13exp=true;
										g13expc=2;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
									}else if(g1rgbts<=testmeasure+(almostlv*currbpm/150)&&g1rgbts>=testmeasure-(almostlv*currbpm/150)){
										gpg1almost++;
										gpg1currcombo=0;
										gpg1almost++;
										gpg1almost++;
										snprintf(gpg1rgrade,24,"Almost");
										snprintf(gpg1ggrade,24,"Almost");
										snprintf(gpg1bgrade,24,"Almost");
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										gpg1lifebar-=lifedifficulty/2;
										gpg1score+=1000;
										g11exp=true;
										g11expc=3;
										g12exp=true;
										g12expc=3;
										g13exp=true;
										g13expc=3;
										gpg1rgradetime=0;
										gpg1ggradetime=0;
										gpg1bgradetime=0;
									}
									g1rgbts=0;
								}
							}
						}
						
						if (strcmp(songs[thesong].advnotetype[a],"a8")==0||strcmp(songs[thesong].advnotetype[a],"bw")==0){
							if (g1wts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].g1advnoteplayed[a]){
								if (!gw){
									playsound(marmot+256,volguit);
									songs[thesong].g1advnoteplayed[a]=true;
									gw=true;
									if (g1wts<=testmeasure+(perfectlv*currbpm/150)&&g1wts>=testmeasure-(perfectlv*currbpm/150)){
										gpg1perfect++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1wgrade,24,"Perfect");
										gpg1score+=10000+(100*gpg1currcombo)+gpg1currcombo;
										gpg1wgradetime=0;
									}else if(g1wts<=testmeasure+(greatlv*currbpm/150)&&g1wts>=testmeasure-(greatlv*currbpm/150)){
										gpg1great++;
										gpg1currcombo++;
										if (gpg1maxcombo<gpg1currcombo){
											gpg1maxcombo=gpg1currcombo;
										}
										snprintf(gpg1wgrade,24,"Great");
										gpg1score+=5000+(50*gpg1currcombo)+gpg1currcombo;
										gpg1wgradetime=0;
									}else if(g1wts<=testmeasure+(goodlv*currbpm/150)&&g1wts>=testmeasure-(goodlv*currbpm/150)){
										gpg1good++;
										snprintf(gpg1wgrade,24,"Good");
										gpg1score+=2500;
										gpg1wgradetime=0;
									}else if(g1wts<=testmeasure+(almostlv*currbpm/150)&&g1wts>=testmeasure-(almostlv*currbpm/150)){
										snprintf(gpg1wgrade,24,"Almost");
										gpg1score+=1000;
										gpg1wgradetime=0;
									}
									g1wts=0;
								}
							}
						}
					}
				}
			}
		}
	}
}
