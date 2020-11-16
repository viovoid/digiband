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
void autobgm1(int a){
	#ifdef EXCESSIVE
	printf("autobgm1\n");
	#endif
	if (thesong<0)return;
	char playstring[256];
	//currentmeasure = songposition/240000;
	long int testmeasure=99999999;//to ignore the next line.
	if (songs[thesong].advnotetime[a]>=0&&songs[thesong].advnotetime[a]<=100000){
		if (songs[thesong].advnotemeas[a]>=0&&songs[thesong].advnotemeas[a]<=999){
			testmeasure=int(double(songs[thesong].advnotemeas[a])*240000.0+(double(songs[thesong].advnotetime[a])/10000.0)*240000.0);
		}
	}
	if (testmeasure<int(double(songposition)+(double(entiresongoffset)*double(currbpm)))){//yes.. all this crap is for note timing.
		if (!songs[thesong].advnoteplayed[a]){
			for (int i=0;i<songs[thesong].advsounds;i++){
				if (songs[thesong].advnotesound[a]!=NULL){
					if (strcmp(songs[thesong].advnotetype[a],"tc")==0&&songs[thesong].advgda){
						if(!songs[thesong].advnoteplayed[a]){
					    	currbpm=hextoi2(songs[thesong].advnotesound[a]);
							songs[thesong].advnoteplayed[a]=true;
							//printf("BPM Changing: %s  %i:%i\n",songs[thesong].advnotetype[a],songs[thesong].advnotemeas[a],currbpm);
						}
					}
					if (!songs[thesong].advgda&&strcmp(songs[thesong].advnotetype[a],"03")==0){
						if(!songs[thesong].advnoteplayed[a]){
       						currbpm=hextoi2(songs[thesong].advnotesound[a]);
							songs[thesong].advnoteplayed[a]=true;
							//printf("BPM Changing: %s  %i:%i\n",songs[thesong].advnotetype[a],songs[thesong].advnotemeas[a],currbpm);
						}
					}
					if (strcmp(songs[thesong].advnotetype[a],"54")==0){
						if(!songs[thesong].advnoteplayed[a]){
							for (int i=0;i<songs[thesong].advavis;i++){
								if (strcmp(songs[thesong].advnotesound[a],songs[thesong].advavinum[i])==0){
									snprintf(curravi,255,songs[thesong].advaviloc[i]);
									songs[thesong].advnoteplayed[a]=true;
								}
							}
						}
					}
					if (strcmp(songs[thesong].advnotetype[a],"02")==0||strcmp(songs[thesong].advnotetype[a],"bl")==0){
						if(!songs[thesong].advnoteplayed[a]){
							if (songs[thesong].advclms[a]>0.0&&songs[thesong].advclms[a]<=100.0){
								currclm=songs[thesong].advclms[a];
								songs[thesong].advnoteplayed[a]=true;
							}
						}
					}
					if (drummode&&(guitar1mode||guitar2mode)
					&& strcmp(songs[thesong].advnotetype[a],"hh")!=0
					&& strcmp(songs[thesong].advnotetype[a],"sd")!=0
					&& strcmp(songs[thesong].advnotetype[a],"bd")!=0
					&& strcmp(songs[thesong].advnotetype[a],"ht")!=0
					&& strcmp(songs[thesong].advnotetype[a],"lt")!=0
					&& strcmp(songs[thesong].advnotetype[a],"cy")!=0
					&& strcmp(songs[thesong].advnotetype[a],"11")!=0
					&& strcmp(songs[thesong].advnotetype[a],"12")!=0
					&& strcmp(songs[thesong].advnotetype[a],"13")!=0
					&& strcmp(songs[thesong].advnotetype[a],"14")!=0
					&& strcmp(songs[thesong].advnotetype[a],"15")!=0
					&& strcmp(songs[thesong].advnotetype[a],"16")!=0
					&& strcmp(songs[thesong].advnotetype[a],"g1")!=0
					&& strcmp(songs[thesong].advnotetype[a],"g2")!=0
					&& strcmp(songs[thesong].advnotetype[a],"g3")!=0
					&& strcmp(songs[thesong].advnotetype[a],"g4")!=0
					&& strcmp(songs[thesong].advnotetype[a],"g5")!=0
					&& strcmp(songs[thesong].advnotetype[a],"g6")!=0
					&& strcmp(songs[thesong].advnotetype[a],"gw")!=0
					&& strcmp(songs[thesong].advnotetype[a],"g7")!=0
					&& strcmp(songs[thesong].advnotetype[a],"gw")!=0
					&& strcmp(songs[thesong].advnotetype[a],"a0")!=0
					&& strcmp(songs[thesong].advnotetype[a],"a1")!=0
					&& strcmp(songs[thesong].advnotetype[a],"a2")!=0
					&& strcmp(songs[thesong].advnotetype[a],"a3")!=0
					&& strcmp(songs[thesong].advnotetype[a],"a4")!=0
					&& strcmp(songs[thesong].advnotetype[a],"a5")!=0
					&& strcmp(songs[thesong].advnotetype[a],"a6")!=0
					&& strcmp(songs[thesong].advnotetype[a],"a7")!=0
					&& strcmp(songs[thesong].advnotetype[a],"a8")!=0
					&& strcmp(songs[thesong].advnotetype[a],"a0")!=0
					&& strcmp(songs[thesong].advnotetype[a],"g0")!=0){
						if(strcmp(songs[thesong].advnotesound[a],songs[thesong].advsoundfilenum[i])==0){
							int marmot=alphatoi(songs[thesong].advsoundfilenum[i]);
							playsound(marmot+256,volbgm);
							songs[thesong].advnoteplayed[a]=true;
						}
					}
				}
			}
		}
	}
}
