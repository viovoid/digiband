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
void sort_default(){
	#ifdef EXCESSIVE
	printf("sort_default\n");
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
	curcatcount=gbcatcount;
	if (curcatcount>0){
		curcatlist=(char**)malloc(sizeof(char*)*(curcatcount));
		for (int a=0;a<curcatcount;a++){
			curcatlist[a]=(char*)malloc(sizeof(char)*256);
			snprintf(curcatlist[a],255,"%s", catlist[a]);
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
	
	int n=0;
	for (int b=0;b<curcatcount;b++){
		curcatsongcount[b]=0;	
	}
	for (int a=0;a<gbsongcount;a++){
		if (drummode&&!guitar1mode&&!guitar2mode){
			if(songs[a].drumbasdiff>0||songs[a].drumadvdiff>0||songs[a].drumextdiff>0){
				for (int b=0;b<curcatcount;b++){
					if (strcmp(songs[a].cat,curcatlist[b])==0){
						curcatsongcount[b]++;
						cursongcat[n]=b;	
					}
				}
				cursongnum[n]=a;
				if (strlen(songs[a].name)>0){
					snprintf(cursonglist[n],255,"%s",songs[a].title);
				}else{
					snprintf(cursonglist[n],255,"???");
				}
				n++;
			}
		}
		if (!drummode&&(guitar1mode||guitar2mode)){
			if(songs[a].guitbasdiff>0||songs[a].guitadvdiff>0||songs[a].guitextdiff>0||songs[a].guitbbasdiff>0||songs[a].guitbadvdiff>0||songs[a].guitbextdiff>0){
				for (int b=0;b<curcatcount;b++){
					if (strcmp(songs[a].cat,curcatlist[b])==0){
						curcatsongcount[b]++;
						cursongcat[n]=b;	
					}
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
					for (int b=0;b<curcatcount;b++){
						if (strcmp(songs[a].cat,curcatlist[b])==0){
							curcatsongcount[b]++;
							cursongcat[n]=b;	
						}
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
