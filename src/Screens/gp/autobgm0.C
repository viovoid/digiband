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
void autobgm0(int a){
   	#ifdef EXCESSIVE
	printf("autobgm0\n");
	#endif
	if (thesong<0)return;
	char playstring[256];
	long int testmeasure=99999999;//to ignore the next line.
	if (songs[thesong].basnotetime[a]>=0&&songs[thesong].basnotetime[a]<=100000){
		if (songs[thesong].basnotemeas[a]>=0&&songs[thesong].basnotemeas[a]<=999){
			testmeasure=(songs[thesong].basnotemeas[a]*240000)+long((double(songs[thesong].basnotetime[a])/10000.0)*240000.0);
		}
	}
	if (testmeasure<(double(songposition)+(double(entiresongoffset)*double(currbpm)))){//yes.. all this crap is for note timing.
		if (!songs[thesong].basnoteplayed[a]){
			for (int i=0;i<songs[thesong].bassounds;i++){
				if (songs[thesong].basnotesound [a]!=NULL){
					if (strcmp(songs[thesong].basnotetype[a],"tc")==0&&songs[thesong].basgda){
						if(!songs[thesong].basnoteplayed[a]){
							currbpm=hextoi2(songs[thesong].basnotesound[a]);
							songs[thesong].basnoteplayed[a]=true;
							printf("BPM Changing: %s  %i:%i\n",songs[thesong].basnotetype[a],songs[thesong].basnotemeas[a],currbpm);
						}
					}
					if (strcmp(songs[thesong].basnotetype[a],"03")==0&&!songs[thesong].basgda){
						if(!songs[thesong].basnoteplayed[a]){
       						currbpm=hextoi2(songs[thesong].basnotesound[a]);
							songs[thesong].basnoteplayed[a]=true;
							printf("BPM Changing: %s  %i:%i\n",songs[thesong].basnotetype[a],songs[thesong].basnotemeas[a],currbpm);
						}
					}
					if (strcmp(songs[thesong].basnotetype[a],"54")==0){
						if(!songs[thesong].basnoteplayed[a]){
							for (int i=0;i<songs[thesong].basavis;i++){
								if (strcmp(songs[thesong].basnotesound[a],songs[thesong].basavinum[i])==0){
									snprintf(curravi,255,songs[thesong].basaviloc[i]);
									songs[thesong].basnoteplayed[a]=true;
								}
							}
						}
					}
					if (strcmp(songs[thesong].basnotetype[a],"02")==0||strcmp(songs[thesong].basnotetype[a],"bl")==0){
						if(!songs[thesong].basnoteplayed[a]){
							if (songs[thesong].basclms[a]>0.0&&songs[thesong].basclms[a]<=100.0){
								currclm=songs[thesong].basclms[a];
								//printf("clm change:%i(%i), %.2f, %.2f\n",songs[thesong].basnotemeas[a],a,currclm,songs[thesong].basclms[a]);
								songs[thesong].basnoteplayed[a]=true;
							}
						}
					}
					if (drummode&&(guitar1mode||guitar2mode)&&strcmp(songs[thesong].basnotetype[a],"hh")!=0&&strcmp(songs[thesong].basnotetype[a],"sd")!=0&&strcmp(songs[thesong].basnotetype[a],"bd")!=0&&strcmp(songs[thesong].basnotetype[a],"ht")!=0&&strcmp(songs[thesong].basnotetype[a],"lt")!=0&&strcmp(songs[thesong].basnotetype[a],"cy")!=0&&strcmp(songs[thesong].basnotetype[a],"11")!=0&&strcmp(songs[thesong].basnotetype[a],"12")!=0&&strcmp(songs[thesong].basnotetype[a],"13")!=0&&strcmp(songs[thesong].basnotetype[a],"14")!=0&&strcmp(songs[thesong].basnotetype[a],"15")!=0&&strcmp(songs[thesong].basnotetype[a],"16")!=0&&strcmp(songs[thesong].basnotetype[a],"g1")!=0&&strcmp(songs[thesong].basnotetype[a],"g2")!=0&&strcmp(songs[thesong].basnotetype[a],"g3")!=0&&strcmp(songs[thesong].basnotetype[a],"g4")!=0&&strcmp(songs[thesong].basnotetype[a],"g5")!=0&&strcmp(songs[thesong].basnotetype[a],"g6")!=0&&strcmp(songs[thesong].basnotetype[a],"gw")!=0&&strcmp(songs[thesong].basnotetype[a],"g7")!=0&&strcmp(songs[thesong].basnotetype[a],"gw")!=0&&strcmp(songs[thesong].basnotetype[a],"a0")!=0&&strcmp(songs[thesong].basnotetype[a],"a1")!=0&&strcmp(songs[thesong].basnotetype[a],"a2")!=0&&strcmp(songs[thesong].basnotetype[a],"a3")!=0&&strcmp(songs[thesong].basnotetype[a],"a4")!=0&&strcmp(songs[thesong].basnotetype[a],"a5")!=0&&strcmp(songs[thesong].basnotetype[a],"a6")!=0&&strcmp(songs[thesong].basnotetype[a],"a7")!=0&&strcmp(songs[thesong].basnotetype[a],"a8")!=0&&strcmp(songs[thesong].basnotetype[a],"a0")!=0&&strcmp(songs[thesong].basnotetype[a],"g0")!=0){
						if (strcmp(songs[thesong].basnotesound[a],songs[thesong].bassoundfilenum[i])==0){
							int marmot=alphatoi(songs[thesong].bassoundfilenum[i]);
							playsound(marmot+256,volbgm);
							songs[thesong].basnoteplayed[a]=true;
						}
					}
				}
			}
		}
	}
}
