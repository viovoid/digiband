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
//THIS IS SOME FUCKED UP SHIT!!!!
int playbgavi(void *wtf){
	//return 0;
	#ifdef EXCESSIVE
	printf("playbgavi\n");
	#endif
	for (int a=0;a<99;a++){
		hasavi[a]=true;	
		checked[a]=false;
	}
	snprintf(curravi,255, "NULL");
	while (appisrunning){
        #ifdef EXCESSIVE
		printf("(bg master aviloop)\n");
		#endif
		bool bgplayed=false,gpplayed=false;
		static bool logoisdefault=false;
        static char avifile[128];
        snprintf(avifile,128, "NULL");
		if (currscreen==1||currscreen==2||currscreen==7||currscreen==8||currscreen==9||currscreen==10||currscreen==11||currscreen==17)snprintf(avifile,127, "./Themes/%s/titlescreen.avi", theme);
		if (currscreen==4||currscreen==5)snprintf(avifile,127, "./Themes/%s/songselection-bottom.avi", theme);
		if (currscreen==6)snprintf(avifile,127, "./Themes/%s/gm.avi", theme);
		if (currscreen==12)snprintf(avifile,127, "./Themes/%s/gameresult.avi", theme);
		if (currscreen==13)snprintf(avifile,127, "./Themes/%s/ending.avi", theme);
		if (currscreen==21){
			if (!logoisdefault)snprintf(avifile,127, "./Themes/%s/logo.avi", theme);
			if (logoisdefault)snprintf(avifile,127, "./Themes/Default/logo.avi", theme);
		}
		if (!checked[currscreen]){
			hasavi[currscreen]=testfile(avifile);
			checked[currscreen]=true;
			if (currscreen==21){
				if (!hasavi[currscreen]){
                	snprintf(avifile,127, "./Themes/Default/logo.avi", theme);
                	hasavi[currscreen]=testfile(avifile);
                	logoisdefault=true;
				}
			}
		}
		if (hasavi[currscreen]){
			bgavi.playavi(avifile,true);
			bgplayed=true;
		}else{
			bgavi.unloadvideomanual();
		}
		if (strcmp(curravi,"NULL")==0||strcmp(curravi,"KILL")==0){
			gpavi.unloadvideomanual();
		}else{
			if (currscreen==5||currscreen==6||currscreen==20){
				char thefile[256];
				if (thesong>-1&&thesong<gbsongcount){
	                if (strlen(curravi)>0){
					    snprintf(thefile,255, "%s%s", songs[thesong].location,curravi);
	                }else{
						snprintf(curravi,255, "NULL");
						snprintf(thefile,255, "%s%s", songs[thesong].location,curravi);
					}
				}else{
					snprintf(curravi,255,"NULL");
					snprintf(thefile,255,"%s", curravi);
				}
				if (strlen(curravi)>0&&strcmp(curravi,"NULL")!=0){
					gpavi.playavi(thefile,false);
					gpplayed=true;
	            }else{
					gpavi.unloadvideomanual();
				}
			}else{
				snprintf(curravi,255, "NULL");
				gpavi.unloadvideomanual();
			}
		}
		SDL_Delay(1);
		if (!bgplayed&&!gpplayed)SDL_Delay(14);
	}	
 	#ifdef DEBUG
	printf("songpos thread ended\n");
	#endif
 	return(0);
}

void drawbgavi(){
	#ifdef EXCESSIVE
	printf("drawbgavi\n");
	#endif
	if (hasavi[currscreen]){
        bgavi.drawavi(512,384,-9999,640,400);
	}
}
