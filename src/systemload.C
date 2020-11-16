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
void scantextures(){
	#ifdef EXCESSIVE
	printf("scantextures\n");
	#endif
	int songcount=0;
	DIR *d;
	dirent *dir;
	int t=0;
	int s=0;
	char themedir[256];
	for (int a=0;a<numoftexs;a++){
		texani[a][0]=1.0;
		texani[a][1]=1.0;
		texani[a][2]=0.0;
		texani[a][3]=0.0;
		snprintf(texstoload[a],255,"");
	}
	snprintf(themedir,255,"./Themes/%s", theme);
	d=opendir(themedir);
	if (d==NULL){
		printf("Security settings for %s Themes directory incorrect.\n", theme);
		appisrunning=false;return;
	}
	while(dir=readdir(d)){
		if (strcmp(strlwr2(dir->d_name+strlen(dir->d_name)-3),"png")==0){
			char temp[256];
			#ifdef DEBUG
   			printf("scanning:%s\n",dir->d_name);
			#endif
			t=13;
			s=9;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"statusbar")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=11;
			t=1;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"titlescreen")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=17;
			t=2;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"titlescreenarcade")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=13;
			t=3;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"optionsscreen")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=9;
			t=4;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"selection")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=16;//IMPORTANT: Exact length of the string that contains the name of the texture.
			t=5;//IMPORTANT: The number that matches the texture for usuage.
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modeselection-bg")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=18;
			t=8;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modeselection-drum")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=21;
			t=9;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modeselection-guitar1")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=21;
			t=10;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modeselection-guitar2")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=20;
			t=11;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modeselection-bottom")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=17;
			t=12;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modeselection-top")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=20;
			t=14;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"songselection-bottom")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=22;
			t=15;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"songselection-selected")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=24;
			t=16;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"songselection-deselected")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=16;
			t=17;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gm-drumguitlayer")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=20;
			t=18;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gm-drumguitlayerwide")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=10;
			t=19;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"diffselect")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=12;
			t=20;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gm-drumlayer")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=12;
			t=21;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gm-guitlayer")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=7;
			t=33;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"perfect")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=34;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"great")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=4;
			t=35;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"good")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=36;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"almost")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=4;
			t=37;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"miss")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=8;
			t=40;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"scorenum")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=41;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"combo")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=10;
			t=46;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gameover-l")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=10;
			t=47;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gameover-r")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=11;
			t=48;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gameresult1")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=11;
			t=49;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gameresult2")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=8;
			t=50;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"particle")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=51;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"white")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=9;
			t=53;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"scrollbar")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=9;
			t=54;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"scrollbox")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=9;
			t=55;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gametitle")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=63;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"danger")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=64;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"death")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=66;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"timer")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=8;
			t=67;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"autoplay")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}	
			s=7;
			t=68;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"longver")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}							
			s=12;
			t=69;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gm-backlayer")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=71;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"logobg")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=72;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"openal")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=73;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"opengl")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/%s/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
		}
	}
	snprintf(themedir,255,"./Noteskins/%s", noteskin);
	d=opendir(themedir);
	if (d==NULL){
		printf("Security settings for Noteskins directory incorrect.\n");
		appisrunning=false;return;
	}
	while(dir=readdir(d)){
		if (strcmp(strlwr2(dir->d_name+strlen(dir->d_name)-3),"png")==0){
			char temp[256];
			s=9;//IMPORTANT: Exact length of the string that contains the name of the texture.
			t=22;//IMPORTANT: The number that matches the texture for usuage.
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"drumtrack")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=23;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"hihat")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=24;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"snare")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=25;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"hitom")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=26;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"lotom")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=27;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"cymbal")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=28;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"note1")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=57;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"note2")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=58;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"note3")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=59;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"note4")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=60;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"note5")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=61;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"note6")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=4;
			t=29;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"bass")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=9;
			t=30;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"guittrack")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=7;
			t=31;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"lifebar")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=8;
			t=32;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"scorebar")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=7;
			t=38;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"measure")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=7;
			t=39;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"quarter")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=4;
			t=42;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"wail")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=4;
			t=43;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gred")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=44;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"ggreen")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=45;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gblue")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=9;
			t=52;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"explosion")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=62;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"petal")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=8;
			t=65;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modifier")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/%s/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
		}
	}
	snprintf(themedir,255,"./Themes/Default");
	d=opendir(themedir);
	if (d==NULL){
		printf("Security settings for Themes directory incorrect.\n");
		appisrunning = false;
		return;
	}
	while(dir=readdir(d)){
		if (strcmp(strlwr2(dir->d_name+strlen(dir->d_name)-3),"png")==0){
			char temp[256];
			t=13;
			s=9;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"statusbar")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=11;
			t=1;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"titlescreen")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=17;
			t=2;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"titlescreenarcade")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=13;
			t=3;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"optionsscreen")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=9;
			t=4;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"selection")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=16;//IMPORTANT: Exact length of the string that contains the name of the texture.
			t=5;//IMPORTANT: The number that matches the texture for usuage.
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modeselection-bg")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=18;
			t=8;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modeselection-drum")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=21;
			t=9;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modeselection-guitar1")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=21;
			t=10;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modeselection-guitar2")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=20;
			t=11;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modeselection-bottom")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=17;
			t=12;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modeselection-top")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=20;
			t=14;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"songselection-bottom")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=22;
			t=15;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"songselection-selected")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=24;
			t=16;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"songselection-deselected")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=16;
			t=17;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gm-drumguitlayer")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=20;
			t=18;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gm-drumguitlayerwide")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=10;
			t=19;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"diffselect")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=12;
			t=20;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gm-drumlayer")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=12;
			t=21;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gm-guitlayer")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=7;
			t=33;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"perfect")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=34;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"great")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=4;
			t=35;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"good")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=36;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"almost")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=4;
			t=37;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"miss")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=8;
			t=40;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"scorenum")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=41;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"combo")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=10;
			t=46;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gameover-l")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=10;
			t=47;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gameover-r")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=11;
			t=48;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gameresult1")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=11;
			t=49;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gameresult2")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=8;
			t=50;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"particle")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=51;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"white")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=9;
			t=53;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"scrollbar")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=9;
			t=54;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"scrollbox")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=9;
			t=55;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gametitle")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=63;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"danger")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=64;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"death")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=66;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"timer")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=8;
			t=67;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"autoplay")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}	
			s=7;
			t=68;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"longver")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}							
			s=12;
			t=69;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gm-backlayer")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=71;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"logobg")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=72;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"openal")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=73;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"opengl")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Themes/Default/%s", theme,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
		}
	}
	snprintf(themedir,255,"./Noteskins/Default");
	d=opendir(themedir);
	if (d==NULL){
		printf("Security settings for Noteskins directory incorrect.\n");
		appisrunning = false;
		return;
	}
	while(dir=readdir(d)){
		if (strcmp(strlwr2(dir->d_name+strlen(dir->d_name)-3),"png")==0){
			char temp[256];
			s=9;//IMPORTANT: Exact length of the string that contains the name of the texture.
			t=22;//IMPORTANT: The number that matches the texture for usuage.
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"drumtrack")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=23;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"hihat")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=24;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"snare")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=25;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"hitom")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=26;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"lotom")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=27;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"cymbal")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=28;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"note1")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=57;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"note2")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=58;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"note3")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=59;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"note4")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=60;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"note5")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=61;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"note6")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=4;
			t=29;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"bass")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=9;
			t=30;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"guittrack")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=7;
			t=31;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"lifebar")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=8;
			t=32;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"scorebar")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=7;
			t=38;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"measure")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=7;
			t=39;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"quarter")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=4;
			t=42;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"wail")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=4;
			t=43;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gred")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=6;
			t=44;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"ggreen")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=45;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"gblue")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=9;
			t=52;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"explosion")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=5;
			t=62;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"petal")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
			s=8;
			t=65;
			charlim(dir->d_name,s,temp);
			if (strcmp(strlwr2(temp),"modifier")==0){
				if (strlen(texstoload[t])<2){
					if (dir->d_name[s]=='-'){
						snprintf(texstoload[t],255,"./Noteskins/Default/%s", noteskin,dir->d_name);
						texani[t][0]=double(dbstoi(strtok((dir->d_name+s+1),"x")));
						texani[t][1]=double(dbstoi(strtok(NULL,".")));
						//printf("found data: %s (%fx%f) #%i\n",texstoload[t],texani[t][0],texani[t][1],t);
					}
				}
			}
		}
	}
	for (int a=0;a<100;a++){
		for (int b=0;b<100;b++){
			g_Texture[a][b]=0;
		}
	}
}

void systemload(){
	#ifdef EXCESSIVE
	printf("systemload\n");
	#endif
    snprintf(curravi,255,"NULL");
	scantextures();
	//if(TTF_Init()==-1) {
	//	printf("\nTTF_Init: %s\n", TTF_GetError());
	//	exit(2);
	//}
    loadtexture(13,texstoload[13],int(texani[13][0]));
	fadein();
	nextobject();
	snprintf(textureframe,127,"");
	getthemelist();
	cachesongs();
	fadout();
	char previewfile[128];
	snprintf(previewfile,127,"./Themes/%s/q.png", theme);
	if (!testfile(previewfile)){
		snprintf(previewfile,127,"./Themes/Default/q.png");
	}
	previewtexture=loadtexture(previewfile);
}

void reloadtheme(){
	#ifdef EXCESSIVE
	printf("reloadtheme\n");
	#endif
	resettextures();
	scantextures();
	resettextures();
	//if(TTF_Init()==-1) {
	//	printf("\nTTF_Init: %s\n", TTF_GetError());
	//	exit(2);
	//}
	getkey();
	uivars.load();
	if (currscreen==5)drawtext::zap();
	if (currscreen==5)genlist();
	
	char previewfile[128];
	snprintf(previewfile,127,"./Themes/%s/q.png", theme);
	if (!testfile(previewfile)){
		snprintf(previewfile,127,"./Themes/Default/q.png");
	}
	previewtexture=loadtexture(previewfile);
	char backgroundfile[128];
	snprintf(backgroundfile,127,"./Themes/%s/wall.png", theme);
	if (!testfile(backgroundfile)){
		snprintf(backgroundfile,127,"./Themes/Default/wall.png");
	}
	backgroundtexture=loadtexture(backgroundfile);
}
