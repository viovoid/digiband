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
void sort_dif(){
	#ifdef EXCESSIVE
	printf("sort_dif\n");
	#endif
	for (int a=0;a<gbsongcount;a++){
		if (drummode&&!guitar1mode&&!guitar2mode){
			if(songs[a].drumbasdiff>0||songs[a].drumadvdiff>0||songs[a].drumextdiff>0){
				cursongcount++;
			}
		}
		if (!drummode&&(guitar1mode||guitar2mode)){
			if(songs[a].guitbasdiff>0||songs[a].guitadvdiff>0||songs[a].guitextdiff>0||songs[a].guitbbasdiff>0||songs[a].guitbadvdiff>0||songs[a].guitbextdiff>0){
				cursongcount++;
			}
		}
		if (drummode&&(guitar1mode||guitar2mode)){
			if(songs[a].drumbasdiff>0||songs[a].drumadvdiff>0||songs[a].drumextdiff>0){
				if(songs[a].guitbasdiff>0||songs[a].guitadvdiff>0||songs[a].guitextdiff>0||songs[a].guitbbasdiff>0||songs[a].guitbadvdiff>0||songs[a].guitbextdiff>0){
					cursongcount++;
				}
			}
		}
	}
	curcatcount=10;
	if (curcatcount>0){
		curcatlist=(char**)malloc(sizeof(char*)*(curcatcount));
		for (int a=0;a<curcatcount;a++){
			curcatlist[a]=(char*)malloc(sizeof(char)*256);
		}
		curcatsongcount=(int*)malloc(sizeof(int)*(curcatcount));
	}
	if (cursongcount>0){
		cursonglist=(char**)malloc(sizeof(char*)*(cursongcount));
		for (int a=0;a<cursongcount;a++){
			cursonglist[a]=(char*)malloc(sizeof(char)*256);
		}
		cursongcat=(int*)malloc(sizeof(int)*(cursongcount));
		cursongnum=(int*)malloc(sizeof(int)*(cursongcount));
	}
	snprintf(curcatlist[0],255,"drum level: 10-20");
	snprintf(curcatlist[1],255,"drum level: 21-30");
	snprintf(curcatlist[2],255,"drum level: 31-40");
	snprintf(curcatlist[3],255,"drum level: 41-50");
	snprintf(curcatlist[4],255,"drum level: 51-60");
	snprintf(curcatlist[5],255,"drum level: 61-70");
	snprintf(curcatlist[6],255,"drum level: 71-80");
	snprintf(curcatlist[7],255,"drum level: 81-90");
	snprintf(curcatlist[8],255,"drum level: 91-100");
	snprintf(curcatlist[9],255,"other/unknown");
	int n=0;
	for (int b=0;b<curcatcount;b++){
		curcatsongcount[b]=0;	
	}
	for (int a=0;a<gbsongcount;a++){
		if (drummode&&!guitar1mode&&!guitar2mode){
			if(songs[a].drumbasdiff>0||songs[a].drumadvdiff>0||songs[a].drumextdiff>0){
				int currdiff=songs[a].lowestdrumdiff;
				bool addother=true;
				if (currdiff>10&&currdiff<21){
					curcatsongcount[0]++;
					cursongcat[n]=0;	
					addother=false;				
				}
				if (currdiff>20&&currdiff<31){
					curcatsongcount[1]++;
					cursongcat[n]=1;	
					addother=false;				
				}
				if (currdiff>30&&currdiff<41){
					curcatsongcount[2]++;
					cursongcat[n]=2;	
					addother=false;				
				}
				if (currdiff>40&&currdiff<51){
					curcatsongcount[3]++;
					cursongcat[n]=3;	
					addother=false;				
				}
				if (currdiff>50&&currdiff<61){
					curcatsongcount[4]++;
					cursongcat[n]=4;	
					addother=false;				
				}
				if (currdiff>60&&currdiff<71){
					curcatsongcount[5]++;
					cursongcat[n]=5;	
					addother=false;				
				}
				if (currdiff>70&&currdiff<81){
					curcatsongcount[6]++;
					cursongcat[n]=6;	
					addother=false;				
				}
				if (currdiff>80&&currdiff<91){
					curcatsongcount[7]++;
					cursongcat[n]=7;	
					addother=false;				
				}
				if (currdiff>90&&currdiff<101){
					curcatsongcount[8]++;
					cursongcat[n]=8;	
					addother=false;				
				}
				if (currdiff>1&&currdiff<11){
					curcatsongcount[currdiff-2]++;
					cursongcat[n]=currdiff-2;	
					addother=false;				
				}
				if (currdiff==1){
					curcatsongcount[0]++;
					cursongcat[n]=0;	
					addother=false;				
				}
				if (addother){
					cursongcat[n]=9;
					curcatsongcount[9]++;
				}
				cursongnum[n]=a;
				if (strlen(songs[a].name)>0){
					snprintf(cursonglist[n],255,"%s", songs[a].title);
				}else{
					snprintf(cursonglist[n],255,"???");
				}
				n++;
			}
		}
		if (!drummode&&(guitar1mode||guitar2mode)){
			if(songs[a].guitbasdiff>0||songs[a].guitadvdiff>0||songs[a].guitextdiff>0||songs[a].guitbbasdiff>0||songs[a].guitbadvdiff>0||songs[a].guitbextdiff>0){
				int currdiff=songs[a].lowestdrumdiff;
				bool addother=true;
				if (currdiff>10&&currdiff<21){
					curcatsongcount[0]++;
					cursongcat[n]=0;	
					addother=false;				
				}
				if (currdiff>20&&currdiff<31){
					curcatsongcount[1]++;
					cursongcat[n]=1;	
					addother=false;				
				}
				if (currdiff>30&&currdiff<41){
					curcatsongcount[2]++;
					cursongcat[n]=2;	
					addother=false;				
				}
				if (currdiff>40&&currdiff<51){
					curcatsongcount[3]++;
					cursongcat[n]=3;	
					addother=false;				
				}
				if (currdiff>50&&currdiff<61){
					curcatsongcount[4]++;
					cursongcat[n]=4;	
					addother=false;				
				}
				if (currdiff>60&&currdiff<71){
					curcatsongcount[5]++;
					cursongcat[n]=5;	
					addother=false;				
				}
				if (currdiff>70&&currdiff<81){
					curcatsongcount[6]++;
					cursongcat[n]=6;	
					addother=false;				
				}
				if (currdiff>80&&currdiff<91){
					curcatsongcount[7]++;
					cursongcat[n]=7;	
					addother=false;				
				}
				if (currdiff>90&&currdiff<101){
					curcatsongcount[8]++;
					cursongcat[n]=8;	
					addother=false;				
				}
				if (currdiff>1&&currdiff<11){
					curcatsongcount[currdiff-2]++;
					cursongcat[n]=currdiff-2;	
					addother=false;				
				}
				if (currdiff==1){
					curcatsongcount[0]++;
					cursongcat[n]=0;	
					addother=false;				
				}
				if (addother){
					cursongcat[n]=9;
					curcatsongcount[9]++;
				}
				cursongnum[n]=a;
				if (strlen(songs[a].name)>0){
					snprintf(cursonglist[n],255,"%s", songs[a].title);
				}else{
					snprintf(cursonglist[n],255,"???");
				}
				n++;
			}
		}
		if (drummode&&(guitar1mode||guitar2mode)){
			if(songs[a].drumbasdiff>0||songs[a].drumadvdiff>0||songs[a].drumextdiff>0){
				if(songs[a].guitbasdiff>0||songs[a].guitadvdiff>0||songs[a].guitextdiff>0||songs[a].guitbbasdiff>0||songs[a].guitbadvdiff>0||songs[a].guitbextdiff>0){
					int currdiff=songs[a].lowestdrumdiff;
					bool addother=true;
					if (currdiff>10&&currdiff<21){
						curcatsongcount[0]++;
						cursongcat[n]=0;	
						addother=false;				
					}
					if (currdiff>20&&currdiff<31){
						curcatsongcount[1]++;
						cursongcat[n]=1;	
						addother=false;				
					}
					if (currdiff>30&&currdiff<41){
						curcatsongcount[2]++;
						cursongcat[n]=2;	
						addother=false;				
					}
					if (currdiff>40&&currdiff<51){
						curcatsongcount[3]++;
						cursongcat[n]=3;	
						addother=false;				
					}
					if (currdiff>50&&currdiff<61){
						curcatsongcount[4]++;
						cursongcat[n]=4;	
						addother=false;				
					}
					if (currdiff>60&&currdiff<71){
						curcatsongcount[5]++;
						cursongcat[n]=5;	
						addother=false;				
					}
					if (currdiff>70&&currdiff<81){
						curcatsongcount[6]++;
						cursongcat[n]=6;	
						addother=false;				
					}
					if (currdiff>80&&currdiff<91){
						curcatsongcount[7]++;
						cursongcat[n]=7;	
						addother=false;				
					}
					if (currdiff>90&&currdiff<101){
						curcatsongcount[8]++;
						cursongcat[n]=8;	
						addother=false;				
					}
					if (currdiff>1&&currdiff<11){
						curcatsongcount[currdiff-2]++;
						cursongcat[n]=currdiff-2;	
						addother=false;				
					}
					if (currdiff==1){
						curcatsongcount[0]++;
						cursongcat[n]=0;	
						addother=false;				
					}
					if (addother){
						cursongcat[n]=9;
						curcatsongcount[9]++;
					}
					cursongnum[n]=a;
					if (strlen(songs[a].name)>0){
						snprintf(cursonglist[n],255,"%s", songs[a].title);
					}else{
						snprintf(cursonglist[n],255,"???");
					}
					n++;
				}
			}
		}
	}
}
