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
void playnote_dmext(int a,bool &hh,bool &sd,bool &bd,bool &ht,bool &lt,bool &cy){
	#ifdef EXCESSIVE
	printf("playnote_dmext\n");
	#endif
	if (drumdiff==2){
		long int testmeasure=99999999;//to ignore the next line.
		if (songs[thesong].extnotetime[a]>=0&&songs[thesong].extnotetime[a]<=100000){
			if (songs[thesong].extnotemeas[a]>=0&&songs[thesong].extnotemeas[a]<=999){
				testmeasure=(songs[thesong].extnotemeas[a]*240000+int((double(songs[thesong].extnotetime[a])/10000.0)*240000.0))+(notesoundoffset*currbpm)-(songs[thesong].offset*500);
			}
		}
		if (testmeasure+(almostlv*currbpm/150)<songposition+(entiresongoffset*currbpm)){
			if (!songs[thesong].extnoteplayed[a]){
				if (songs[thesong].extnotesound[a]!=NULL){
					if (strcmp(songs[thesong].extnotetype[a],"hh")==0||strcmp(songs[thesong].extnotetype[a],"11")==0){
						if (!songs[thesong].extnoteplayed[a]){
							gpmiss++;
							gpcurrcombo=0;
							snprintf(gphhgrade,24,"Miss");
							gphhgradetime=0;
							songs[thesong].extnoteplayed[a]=true;
							gplifebar-=lifedifficulty;
						}
					}
					if (strcmp(songs[thesong].extnotetype[a],"sd")==0||strcmp(songs[thesong].extnotetype[a],"12")==0){
						if (!songs[thesong].extnoteplayed[a]){
							gpmiss++;
							gpcurrcombo=0;
							snprintf(gpsdgrade,24,"Miss");
							gpsdgradetime=0;
							songs[thesong].extnoteplayed[a]=true;
							gplifebar-=lifedifficulty;
						}
					}
					if (strcmp(songs[thesong].extnotetype[a],"bd")==0||strcmp(songs[thesong].extnotetype[a],"13")==0){
						if (!songs[thesong].extnoteplayed[a]){
							gpmiss++;
							gpcurrcombo=0;
							snprintf(gpbdgrade,24,"Miss");
							gpbdgradetime=0;
							songs[thesong].extnoteplayed[a]=true;
							gplifebar-=lifedifficulty;
						}
					}
					if (strcmp(songs[thesong].extnotetype[a],"ht")==0||strcmp(songs[thesong].extnotetype[a],"14")==0){
						if (!songs[thesong].extnoteplayed[a]){
							gpmiss++;
							gpcurrcombo=0;
							snprintf(gphtgrade,24,"Miss");
							gphtgradetime=0;
							songs[thesong].extnoteplayed[a]=true;
							gplifebar-=lifedifficulty;
						}
					}
					if (strcmp(songs[thesong].extnotetype[a],"lt")==0||strcmp(songs[thesong].extnotetype[a],"15")==0){
						if (!songs[thesong].extnoteplayed[a]){
							gpmiss++;
							gpcurrcombo=0;
							snprintf(gpltgrade,24,"Miss");
							gpltgradetime=0;
							songs[thesong].extnoteplayed[a]=true;
							gplifebar-=lifedifficulty;
						}
					}
					if (strcmp(songs[thesong].extnotetype[a],"cy")==0||strcmp(songs[thesong].extnotetype[a],"16")==0){
						if (!songs[thesong].extnoteplayed[a]){
							gpmiss++;
							gpcurrcombo=0;
							snprintf(gpcygrade,24,"Miss");
							gpcygradetime=0;
							songs[thesong].extnoteplayed[a]=true;
							gplifebar-=lifedifficulty;
						}
					}
				}
			}
		}
		if (testmeasure-(almostlv*currbpm/150)<songposition+(entiresongoffset*currbpm)){
			if (!songs[thesong].extnoteplayed[a]){
				if (songs[thesong].extnotesound[a]!=NULL){
					int marmot=alphatoi(songs[thesong].extnotesound[a]);
					if (strcmp(songs[thesong].extnotetype[a],"sd")==0||strcmp(songs[thesong].extnotetype[a],"12")==0){
						if (snarets>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].extnoteplayed[a]){
							if (!sd){
								playsound(marmot+256,voldrum);
								lastsnare=marmot;
								snarepressed=false;
								songs[thesong].extnoteplayed[a]=true;
								sd=true;
								if (snarets<=testmeasure+(perfectlv*currbpm/150)&&snarets>=testmeasure-(perfectlv*currbpm/150)){
									gpperfect++;
									gpcurrcombo++;
									if (gpmaxcombo<gpcurrcombo){
										gpmaxcombo=gpcurrcombo;
									}
									snprintf(gpsdgrade,24,"Perfect");
									gpscore+=10000+(100*gpcurrcombo)+gpcurrcombo;
									gpsdgradetime=0;
									gplifebar+=pldiff;
									d2exp=true;
									d2expc=0;
								}else if(snarets<=testmeasure+(greatlv*currbpm/150)&&snarets>=testmeasure-(greatlv*currbpm/150)){
									gpgreat++;
									gpcurrcombo++;
									if (gpmaxcombo<gpcurrcombo){
										gpmaxcombo=gpcurrcombo;
									}
									snprintf(gpsdgrade,24,"Great");
									gpsdgradetime=0;
									gpscore+=5000+(50*gpcurrcombo)+gpcurrcombo;
									gplifebar+=gldiff;
									d2exp=true;
									d2expc=1;
								}else if(snarets<=testmeasure+(goodlv*currbpm/150)&&snarets>=testmeasure-(goodlv*currbpm/150)){
									gpgood++;
									gpcurrcombo++;
									snprintf(gpsdgrade,24,"Good");
									gpscore+=2500;
									gpsdgradetime=0;
									d2exp=true;
									d2expc=2;
								}else if(snarets<=testmeasure+(almostlv*currbpm/150)&&snarets>=testmeasure-(almostlv*currbpm/150)){
									gpalmost++;
									gpcurrcombo=0;
									snprintf(gpsdgrade,24,"Almost");
									gpsdgradetime=0;
									gplifebar-=lifedifficulty/2;
									gpscore+=1000;
									d2exp=true;
									d2expc=3;
								}
							}
						}
					}
					if (strcmp(songs[thesong].extnotetype[a],"hh")==0||strcmp(songs[thesong].extnotetype[a],"11")==0){
						if (hihatts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].extnoteplayed[a]){
							if (!hh){
								playsound(marmot+256,voldrum);
								lasthihat=marmot;
								hihatpressed=false;
								songs[thesong].extnoteplayed[a]=true;
								hh=true;
								if (hihatts<=testmeasure+(perfectlv*currbpm/150)&&hihatts>=testmeasure-(perfectlv*currbpm/150)){
									gpperfect++;
									gpcurrcombo++;
									if (gpmaxcombo<gpcurrcombo){
										gpmaxcombo=gpcurrcombo;
									}
									snprintf(gphhgrade,24,"Perfect");
									gpscore+=10000+(100*gpcurrcombo)+gpcurrcombo;
									gphhgradetime=0;
									gplifebar+=pldiff;
									d1exp=true;
									d1expc=0;
								}else if(hihatts<=testmeasure+(greatlv*currbpm/150)&&hihatts>=testmeasure-(greatlv*currbpm/150)){
									gpgreat++;
									gpcurrcombo++;
									if (gpmaxcombo<gpcurrcombo){
										gpmaxcombo=gpcurrcombo;
									}
									snprintf(gphhgrade,24,"Great");
									gphhgradetime=0;
									gpscore+=5000+(50*gpcurrcombo)+gpcurrcombo;
									gplifebar+=gldiff;
									d1exp=true;
									d1expc=1;
								}else if(hihatts<=testmeasure+(goodlv*currbpm/150)&&hihatts>=testmeasure-(goodlv*currbpm/150)){
									gpgood++;
									gpcurrcombo++;
									snprintf(gphhgrade,24,"Good");
									gphhgradetime=0;
									gpscore+=2500;
									d1exp=true;
									d1expc=2;
								}else if(hihatts<=testmeasure+(almostlv*currbpm/150)&&hihatts>=testmeasure-(almostlv*currbpm/150)){
									gpalmost++;
									gpcurrcombo=0;
									snprintf(gphhgrade,24,"Almost");
									gphhgradetime=0;
									gplifebar-=lifedifficulty/2;
									gpscore+=1000;
									d1exp=true;
									d1expc=3;
								}
							}
						}
					}
					if (strcmp(songs[thesong].extnotetype[a],"bd")==0||strcmp(songs[thesong].extnotetype[a],"13")==0){
						if (bassts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].extnoteplayed[a]){
							if (!bd){
								playsound(marmot+256,voldrum);
								lastbass=marmot;
								basspressed=false;
								songs[thesong].extnoteplayed[a]=true;
								bd=true;
								if (bassts<=testmeasure+(perfectlv*currbpm/150)&&bassts>=testmeasure-(perfectlv*currbpm/150)){
									gpperfect++;
									gpcurrcombo++;
									if (gpmaxcombo<gpcurrcombo){
										gpmaxcombo=gpcurrcombo;
									}
									snprintf(gpbdgrade,24,"Perfect");
									gpscore+=10000+(100*gpcurrcombo)+gpcurrcombo;
									gpbdgradetime=0;
									gplifebar+=pldiff;
									d3exp=true;
									d3expc=0;
								}else if(bassts<=testmeasure+(greatlv*currbpm/150)&&bassts>=testmeasure-(greatlv*currbpm/150)){
									gpgreat++;
									gpcurrcombo++;
									if (gpmaxcombo<gpcurrcombo){
										gpmaxcombo=gpcurrcombo;
									}
									snprintf(gpbdgrade,24,"Great");
									gpbdgradetime=0;
									gpscore+=5000+(50*gpcurrcombo)+gpcurrcombo;
									gplifebar+=gldiff;
									d3exp=true;
									d3expc=1;
								}else if(bassts<=testmeasure+(goodlv*currbpm/150)&&bassts>=testmeasure-(goodlv*currbpm/150)){
									gpgood++;
									gpcurrcombo++;
									snprintf(gpbdgrade,24,"Good");
									gpbdgradetime=0;
									gpscore+=2500;
									d3exp=true;
									d3expc=2;
								}else if(bassts<=testmeasure+(almostlv*currbpm/150)&&bassts>=testmeasure-(almostlv*currbpm/150)){
									gpalmost++;
									gpcurrcombo=0;
									snprintf(gpbdgrade,24,"Almost");
									gpbdgradetime=0;
									gplifebar-=lifedifficulty/2;
									gpscore+=1000;
									d3exp=true;
									d3expc=3;
								}
							}
						}
					}
					if (strcmp(songs[thesong].extnotetype[a],"ht")==0||strcmp(songs[thesong].extnotetype[a],"14")==0){
						if (hitomts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].extnoteplayed[a]){
							if (!ht){
								playsound(marmot+256,voldrum);
								lasthitom=marmot;
								hitompressed=false;
								songs[thesong].extnoteplayed[a]=true;
								ht=true;
								if (hitomts<=testmeasure+(perfectlv*currbpm/150)&&hitomts>=testmeasure-(perfectlv*currbpm/150)){
									gpperfect++;
									gpcurrcombo++;
									if (gpmaxcombo<gpcurrcombo){
										gpmaxcombo=gpcurrcombo;
									}
									snprintf(gphtgrade,24,"Perfect");
									gphtgradetime=0;
									gplifebar+=pldiff;
									gpscore+=10000+(100*gpcurrcombo)+gpcurrcombo;
									d4exp=true;
									d4expc=0;
								}else if(hitomts<=testmeasure+(greatlv*currbpm/150)&&hitomts>=testmeasure-(greatlv*currbpm/150)){
									gpgreat++;
									gpcurrcombo++;
									if (gpmaxcombo<gpcurrcombo){
										gpmaxcombo=gpcurrcombo;
									}
									snprintf(gphtgrade,24,"Great");
									gphtgradetime=0;
									gplifebar+=gldiff;
									gpscore+=5000+(50*gpcurrcombo)+gpcurrcombo;
									d4exp=true;
									d4expc=1;
								}else if(hitomts<=testmeasure+(goodlv*currbpm/150)&&hitomts>=testmeasure-(goodlv*currbpm/150)){
									gpgood++;
									gpcurrcombo++;
									snprintf(gphtgrade,24,"Good");
									gphtgradetime=0;
									gpscore+=2500;
									d4exp=true;
									d4expc=2;
								}else if(hitomts<=testmeasure+(almostlv*currbpm/150)&&hitomts>=testmeasure-(almostlv*currbpm/150)){
									gpalmost++;
									gpcurrcombo=0;
									snprintf(gphtgrade,24,"Almost");
									gphtgradetime=0;
									gplifebar-=lifedifficulty/2;
									gpscore+=1000;
									d4exp=true;
									d4expc=3;
								}
							}
						}
					}
					if (strcmp(songs[thesong].extnotetype[a],"lt")==0||strcmp(songs[thesong].extnotetype[a],"15")==0){
						if (lotomts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].extnoteplayed[a]){
							if (!lt){
								playsound(marmot+256,voldrum);
								lastlotom=marmot;
								lotompressed=false;
								lt=true;
								songs[thesong].extnoteplayed[a]=true;
								if (lotomts<=testmeasure+(perfectlv*currbpm/150)&&lotomts>=testmeasure-(perfectlv*currbpm/150)){
									gpperfect++;
									gpcurrcombo++;
									if (gpmaxcombo<gpcurrcombo){
										gpmaxcombo=gpcurrcombo;
									}
									snprintf(gpltgrade,24,"Perfect");
									gpltgradetime=0;
									gplifebar+=pldiff;
									gpscore+=10000+(100*gpcurrcombo)+gpcurrcombo;
									d5exp=true;
									d5expc=0;
								}else if(lotomts<=testmeasure+(greatlv*currbpm/150)&&lotomts>=testmeasure-(greatlv*currbpm/150)){
									gpgreat++;
									gpcurrcombo++;
									if (gpmaxcombo<gpcurrcombo){
										gpmaxcombo=gpcurrcombo;
									}
									snprintf(gpltgrade,24,"Great");
									gpltgradetime=0;
									gplifebar+=gldiff;
									gpscore+=5000+(50*gpcurrcombo)+gpcurrcombo;
									d5exp=true;
									d5expc=1;
								}else if(lotomts<=testmeasure+(goodlv*currbpm/150)&&lotomts>=testmeasure-(goodlv*currbpm/150)){
									gpgood++;
									gpcurrcombo++;
									snprintf(gpltgrade,24,"Good");
									gpltgradetime=0;
									gpscore+=2500;
									d5exp=true;
									d5expc=2;
								}else if(lotomts<=testmeasure+(almostlv*currbpm/150)&&lotomts>=testmeasure-(almostlv*currbpm/150)){
									gpalmost++;
									gpcurrcombo=0;
									snprintf(gpltgrade,24,"Almost");
									gpltgradetime=0;
									gplifebar-=lifedifficulty/2;
									gpscore+=1000;
									d5exp=true;
									d5expc=3;
								}
							}
						}
					}
					if (strcmp(songs[thesong].extnotetype[a],"cy")==0||strcmp(songs[thesong].extnotetype[a],"16")==0){
						if (cymbalts>=testmeasure-(almostlv*currbpm/150)&&!songs[thesong].extnoteplayed[a]){
							if (!cy){
								playsound(marmot+256,voldrum);
								lastcymbal=marmot;
								cymbalpressed=false;
								songs[thesong].extnoteplayed[a]=true;
								cy=true;
								if (cymbalts<=testmeasure+(perfectlv*currbpm/150)&&cymbalts>=testmeasure-(perfectlv*currbpm/150)){
									gpperfect++;
									gpcurrcombo++;
									if (gpmaxcombo<gpcurrcombo){
										gpmaxcombo=gpcurrcombo;
									}
									snprintf(gpcygrade,24,"Perfect");
									gpcygradetime=0;
									gplifebar+=pldiff;
									gpscore+=10000+(100*gpcurrcombo)+gpcurrcombo;
									d6exp=true;
									d6expc=0;
								}else if(cymbalts<=testmeasure+(greatlv*currbpm/150)&&cymbalts>=testmeasure-(greatlv*currbpm/150)){
									gpgreat++;
									gpcurrcombo++;
									if (gpmaxcombo<gpcurrcombo){
										gpmaxcombo=gpcurrcombo;
									}
									snprintf(gpcygrade,24,"Great");
									gpcygradetime=0;
									gplifebar+=gldiff;
									gpscore+=5000+(50*gpcurrcombo)+gpcurrcombo;
									d6exp=true;
									d6expc=1;
								}else if(cymbalts<=testmeasure+(goodlv*currbpm/150)&&cymbalts>=testmeasure-(goodlv*currbpm/150)){
									gpgood++;
									gpcurrcombo++;
									snprintf(gpcygrade,24,"Good");
									gpcygradetime=0;
									gpscore+=2500;
									d6exp=true;
									d6expc=2;
								}else if(cymbalts<=testmeasure+(almostlv*currbpm/150)&&cymbalts>=testmeasure-(almostlv*currbpm/150)){
									gpalmost++;
									gpcurrcombo=0;
									snprintf(gpcygrade,24,"Almost");
									gpcygradetime=0;
									gplifebar-=lifedifficulty/2;
									gpscore+=1000;
									d6exp=true;
									d6expc=3;
								}
							}
						}
					}
				}
			}
		}
	}
}

