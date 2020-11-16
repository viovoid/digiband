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
void autobgm2(int a){
	#ifdef EXCESSIVE
	printf("autobgm2\n");
	#endif
	if (thesong<0)return;
	char playstring[256];
	//currentmeasure = songposition/240000;
	long int testmeasure=99999999;//to ignore the next line.
	if (songs[thesong].extnotetime[a]>=0&&songs[thesong].extnotetime[a]<=100000){
		if (songs[thesong].extnotemeas[a]>=0&&songs[thesong].extnotemeas[a]<=999){
			testmeasure=int(double(songs[thesong].extnotemeas[a])*240000.0+(double(songs[thesong].extnotetime[a])/10000.0)*240000.0);
		}
	}
	if (testmeasure<int(double(songposition)+(double(entiresongoffset)*double(currbpm)))){//yes.. all this crap is for note timing.
		if (!songs[thesong].extnoteplayed[a]){
			for (int i=0;i<songs[thesong].extsounds;i++){
				if (songs[thesong].extnotesound[a]!=NULL){
					if (strcmp(songs[thesong].extnotetype[a],"tc")==0&&songs[thesong].extgda){
						if(!songs[thesong].extnoteplayed[a]){
       						currbpm=hextoi2(songs[thesong].extnotesound[a]);
							songs[thesong].extnoteplayed[a]=true;
							//printf("BPM Changing: %s  %i:%i\n",songs[thesong].extnotetype[a],songs[thesong].extnotemeas[a],currbpm);
						}
					}
					if (!songs[thesong].extgda&&strcmp(songs[thesong].extnotetype[a],"03")==0){
						if(!songs[thesong].extnoteplayed[a]){
       						currbpm=hextoi2(songs[thesong].extnotesound[a]);
							songs[thesong].extnoteplayed[a]=true;
							//printf("BPM Changing: %s  %i:%i\n",songs[thesong].extnotetype[a],songs[thesong].extnotemeas[a],currbpm);
						}
					}
					if (strcmp(songs[thesong].extnotetype[a],"54")==0){
						if(!songs[thesong].extnoteplayed[a]){
							for (int i=0;i<songs[thesong].extavis;i++){
								if (strcmp(songs[thesong].extnotesound[a],songs[thesong].extavinum[i])==0){
									//printf("now playing %s\n",songs[thesong].extaviloc[i]);
									snprintf(curravi,255,songs[thesong].extaviloc[i]);
									songs[thesong].extnoteplayed[a]=true;
								}
							}
						}
					}
					if (strcmp(songs[thesong].extnotetype[a],"02")==0||strcmp(songs[thesong].extnotetype[a],"bl")==0){
						if(!songs[thesong].extnoteplayed[a]){
							if (songs[thesong].extclms[a]>0.0&&songs[thesong].extclms[a]<=100.0){
								currclm=songs[thesong].extclms[a];
								songs[thesong].extnoteplayed[a]=true;
							}
						}
					}
					if (drummode&&(guitar1mode||guitar2mode)&&strcmp(songs[thesong].extnotetype[a],"hh")!=0&&strcmp(songs[thesong].extnotetype[a],"sd")!=0&&strcmp(songs[thesong].extnotetype[a],"bd")!=0&&strcmp(songs[thesong].extnotetype[a],"ht")!=0&&strcmp(songs[thesong].extnotetype[a],"lt")!=0&&strcmp(songs[thesong].extnotetype[a],"cy")!=0&&strcmp(songs[thesong].extnotetype[a],"11")!=0&&strcmp(songs[thesong].extnotetype[a],"12")!=0&&strcmp(songs[thesong].extnotetype[a],"13")!=0&&strcmp(songs[thesong].extnotetype[a],"14")!=0&&strcmp(songs[thesong].extnotetype[a],"15")!=0&&strcmp(songs[thesong].extnotetype[a],"16")!=0&&strcmp(songs[thesong].extnotetype[a],"g1")!=0&&strcmp(songs[thesong].extnotetype[a],"g2")!=0&&strcmp(songs[thesong].extnotetype[a],"g3")!=0&&strcmp(songs[thesong].extnotetype[a],"g4")!=0&&strcmp(songs[thesong].extnotetype[a],"g5")!=0&&strcmp(songs[thesong].extnotetype[a],"g6")!=0&&strcmp(songs[thesong].extnotetype[a],"gw")!=0&&strcmp(songs[thesong].extnotetype[a],"g7")!=0&&strcmp(songs[thesong].extnotetype[a],"gw")!=0&&strcmp(songs[thesong].extnotetype[a],"a0")!=0&&strcmp(songs[thesong].extnotetype[a],"a1")!=0&&strcmp(songs[thesong].extnotetype[a],"a2")!=0&&strcmp(songs[thesong].extnotetype[a],"a3")!=0&&strcmp(songs[thesong].extnotetype[a],"a4")!=0&&strcmp(songs[thesong].extnotetype[a],"a5")!=0&&strcmp(songs[thesong].extnotetype[a],"a6")!=0&&strcmp(songs[thesong].extnotetype[a],"a7")!=0&&strcmp(songs[thesong].extnotetype[a],"a8")!=0&&strcmp(songs[thesong].extnotetype[a],"a0")!=0&&strcmp(songs[thesong].extnotetype[a],"g0")!=0){
						if (strcmp(songs[thesong].extnotesound[a],songs[thesong].extsoundfilenum[i])==0){
							int marmot=alphatoi(songs[thesong].extsoundfilenum[i]);
							playsound(marmot+256,volbgm);
							songs[thesong].extnoteplayed[a]=true;
						}
					}
				}
			}
		}
	}
}
