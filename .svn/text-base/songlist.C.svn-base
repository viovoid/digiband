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
#include "sorts/sort_default.C"
#include "sorts/sort_abc.C"
#include "sorts/sort_dif.C"
#include "sorts/sort_gdl.C"
#include "sorts/sort_bpm.C"


void deleteempty(){
	#ifdef EXCESSIVE
	printf("deleteempty\n");
	#endif
	int precatcount=curcatcount;
	for (int a=0;a<curcatcount;a++){
		if (curcatsongcount[a]<1) {
			for (int b = a; b < (curcatcount - 1); b++) {
				strcpy(curcatlist[b], curcatlist[b + 1]);
			}
			
			for (int c = 0; c < cursongcount; c++){
				if (cursongcat[c] > a) {
					cursongcat[c] -= 1;
				}
			}

			a -= 1;
			curcatcount -= 1;
			
			free(curcatlist[curcatcount]);
			curcatlist = (char **)realloc(curcatlist, sizeof(char *) * curcatcount);
			curcatsongcount = (int *)realloc(curcatsongcount, sizeof(int) * curcatcount);
		}		
	}
}

void alphabetize(){
	#ifdef EXCESSIVE
	printf("alphabetize\n");
	#endif
	char tsl[256];
	int tsn=0;
	int tsc=0;
	for (int a=0;a<cursongcount;a++){
		snprintf(tsl,255,"%s", cursonglist[a]);
		tsn=cursongnum[a];
		tsc=cursongcat[a];
		for (int b=a+1;b<cursongcount;b++){
			if (strcmp(strlwr2(tsl),strlwr2(cursonglist[b]))>0){
				//move smaller to top
				snprintf(cursonglist[a],255,"%s", cursonglist[b]);
				cursongnum[a]=cursongnum[b];
				cursongcat[a]=cursongcat[b];
				//copy temp to smallers location.
				snprintf(cursonglist[b],255,"%s", tsl);
				cursongnum[b]=tsn;
				cursongcat[b]=tsc;
				//make temp match smallest
				snprintf(tsl,255,"%s", cursonglist[a]);
				tsn=cursongnum[a];
				tsc=cursongcat[a];
			}
		}	
	}
}

void drumdiffitize(){//that's right I made it up! What're gonna do about it?
	#ifdef EXCESSIVE
	printf("drumdiffitize\n");
	#endif
	char tsl[256];
	int tsn=0;
	int tsc=0;
	for (int a=0;a<cursongcount;a++){
		snprintf(tsl,255,"%s", cursonglist[a]);
		tsn=cursongnum[a];
		tsc=cursongcat[a];
		for (int b=a+1;b<cursongcount;b++){
			if (songs[tsn].lowestdrumdiff>songs[cursongnum[b]].lowestdrumdiff){
				//move smaller to top
				snprintf(cursonglist[a],255,"%s", cursonglist[b]);
				cursongnum[a]=cursongnum[b];
				cursongcat[a]=cursongcat[b];
				//copy temp to smallers location.
				snprintf(cursonglist[b],255,"%s", tsl);
				cursongnum[b]=tsn;
				cursongcat[b]=tsc;
				//make temp match smallest
				snprintf(tsl,255,"%s", cursonglist[a]);
				tsn=cursongnum[a];
				tsc=cursongcat[a];
			}
		}	
	}
}

void guitdiffitize(){//that's right I made it up! What're gonna do about it?
	#ifdef EXCESSIVE
	printf("guitdiffitize\n");
	#endif
	char tsl[256];
	int tsn=0;
	int tsc=0;
	for (int a=0;a<cursongcount;a++){
		snprintf(tsl,255,"%s", cursonglist[a]);
		tsn=cursongnum[a];
		tsc=cursongcat[a];
		for (int b=a+1;b<cursongcount;b++){
			if (songs[tsn].lowestguitdiff>songs[cursongnum[b]].lowestguitdiff){
				//move smaller to top
				snprintf(cursonglist[a],255,"%s", cursonglist[b]);
				cursongnum[a]=cursongnum[b];
				cursongcat[a]=cursongcat[b];
				//copy temp to smallers location.
				snprintf(cursonglist[b],255,"%s", tsl);
				cursongnum[b]=tsn;
				cursongcat[b]=tsc;
				//make temp match smallest
				snprintf(tsl,255,"%s", cursonglist[a]);
				tsn=cursongnum[a];
				tsc=cursongcat[a];
			}
		}	
	}
}

void guitbpmitize(){//more me making shit up.
	#ifdef EXCESSIVE
	printf("guitbpmitize\n");
	#endif
	char tsl[256];
	int tsn=0;
	int tsc=0;
	for (int a=0;a<cursongcount;a++){
		snprintf(tsl,255,"%s", cursonglist[a]);
		tsn=cursongnum[a];
		tsc=cursongcat[a];
		for (int b=a+1;b<cursongcount;b++){
			if (songs[tsn].bpm>songs[cursongnum[b]].bpm){
				//move smaller to top
				snprintf(cursonglist[a],255,"%s", cursonglist[b]);
				cursongnum[a]=cursongnum[b];
				cursongcat[a]=cursongcat[b];
				//copy temp to smallers location.
				snprintf(cursonglist[b],255,"%s", tsl);
				cursongnum[b]=tsn;
				cursongcat[b]=tsc;
				//make temp match smallest
				snprintf(tsl,255,"%s", cursonglist[a]);
				tsn=cursongnum[a];
				tsc=cursongcat[a];
			}
		}	
	}
}

void genlist(){
	#ifdef EXCESSIVE
	printf("genlist\n");
	#endif
	if (listmode>LISTMODES)
	listmode=1;
	catselected=0;
	if (curcatcount>0){
		for (int a=0;a<curcatcount;a++){
			free(curcatlist[a]);
		}
		free(curcatlist);
		free(curcatsongcount);
	}
	if (cursongcount>0){
		for (int a=0;a<cursongcount;a++){
			free(cursonglist[a]);	
		}
		free(cursonglist);
		free(cursongcat);
		free(cursongnum);
	}
	
	curcatcount=0;
	cursongcount=0;
	
	if (listmode==1)sort_default();
	if (listmode==2)sort_abc();
	if (listmode==3)sort_dif();
	if (listmode==4)sort_gdl();
	if (listmode==5)sort_bpm();
	catselected=0;
	
	//deleteempty();
	if (listmode==1||listmode==2)alphabetize();
	if (listmode==3)drumdiffitize();
	if (listmode==4)guitdiffitize();
	if (listmode==5)guitbpmitize();
	int a=0;
	//thesong=0;
	//while(a<cursongcount||cursongcat[a]==0){
	//	if (cursongcat[a]==0){
		//	thesong=cursongnum[a];
		//}
		//a++;
	//}
	songselected=cursongnum[0];
	optionselected=1;
	#ifdef DEBUG
	printf("I've reloaded (%i,%i)\n",thesong,presong);
	#endif
	forcepaoff=true;
}

void loadlisttext(){
    #ifdef EXCESSIVE
	printf("loadlisttext\n");
	#endif
	static int pa=-10;
	if (forcepaoff)pa=-10;
	    forcepaoff=false;
	if (optionselected>curcatsongcount[catselected])
		optionselected=-curcatcount+1;
	if (optionselected<-curcatcount+1)
		optionselected=curcatsongcount[catselected];
    if (pa!=optionselected){
		for (int b=-5;b<6;b++){
			int optionselected2=optionselected;
			for(int c=0;c<abs(b);c++){
				if (b>0)optionselected2--;
				if (b<0)optionselected2++;
				if (optionselected2>curcatsongcount[catselected])
					optionselected2=-curcatcount+1;
				if (optionselected2<-curcatcount+1)
					optionselected2=curcatsongcount[catselected];
			}
			if (optionselected2<0){
				int tempos2=catselected-optionselected2;
				if (tempos2>=curcatcount)
				tempos2-=curcatcount;
		        songtext[b+5].lr=0;
		        songtext[b+5].lg=192;
		        songtext[b+5].lb=0;
		        songtext[b+5].load(curcatlist[tempos2],"unicode.ttf",255,0,0,24);
                //songtext[b+5].load(curcatlistt[tempos2].thetext,"unicode.ttf",255,0,0,24);
			}
			if (optionselected2==0){
		        songtext[b+5].lr=192;
		        songtext[b+5].lg=0;
		        songtext[b+5].lb=255;
		        songtext[b+5].load(curcatlist[catselected],"unicode.ttf",0,255,0,24);
    	        //songtext[b+5].load(selcatlistt[catselected].thetext,"unicode.ttf",0,255,0,24);
			}
			int step=0;
			int a=-1;
			if (optionselected2>0){
				while (step<optionselected2){
					a++;
					if (catselected==cursongcat[a]){
						step++;
					}
				}
				if (b==0){
					prevsongselected=songselected;
					songselected=cursongnum[a];
				}
		    	if (a>-1&&a<cursongcount){
					if (strlen(cursonglist[a])>0){
						if (songs[cursongnum[a]].islong){
		                    songtext[b+5].lr=128;
		                    songtext[b+5].lg=128;
		                    songtext[b+5].lb=255;
							songtext[b+5].load(songs[cursongnum[a]].title,"unicode.ttf",64,64,255,24);
							
						}else{
		                    songtext[b+5].lr=255;
		                    songtext[b+5].lg=255;
		                    songtext[b+5].lb=255;
							songtext[b+5].load(songs[cursongnum[a]].title,"unicode.ttf",255,255,255,24);
		                }
					}
				}
			}
		}
		#ifdef DEBUG
		printf("I've updated the list text, should look different now.\n");
		#endif
	}
    pa=optionselected;
}
