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
void loadwaves(){
	#ifndef NOOSWEGO
	#ifdef EXCESSIVE
	printf("loadwaves\n");
	#endif
	static char temp[1024];
	for (int a=256;a<1554;a++){
		waves[a].close();
	}
	if (drumdiff==0){
		for (int j=0;j<songs[thesong].bassounds;j++){
			int marmot=alphatoi(songs[thesong].bassoundfilenum[j]);
			if (marmot>=1297||marmot<0){
				#ifdef DEBUG
				printf("your marmot var is out of wack.");
				#endif
				if(marmot>=1297)marmot=1296;
				if(marmot<0)marmot=0;
			}
			if (marmot>-1&&marmot<1297){
				char file[1024];
				snprintf(file,1023,"%s%s", songs[thesong].location,songs[thesong].bassoundfileloc[j]);
				#ifdef SHOWWAVES
				printf("%s : ",file);
				#endif
				if (testfile(file)){
					if (testxa(file)){
						#ifdef LINUX
						char *onlytime = (char *)malloc(strlen(file) + 1);
						memcpy(onlytime, file, strlen(file) + 1);
						snprintf(file, 255, "%s.wav", onlytime);
						free(onlytime);
						#else
						decodexa(file);
						#endif
					}
					#ifdef SHOWWAVES
					printf("opened\n",file);
					#endif
					waves[marmot+256].open(file);
				}
				#ifdef SHOWWAVES
				else{printf("failed\n",file);}
				#endif
			}
		}
	}
	if (drumdiff==1){
		for (int j=0;j<songs[thesong].advsounds;j++){
			int marmot=alphatoi(songs[thesong].advsoundfilenum[j]);
			if (marmot>=1297||marmot<0){
				printf("your marmot var is out of wack.");
				//appisrunning=false;
				if(marmot>=1297)marmot=1296;
				if(marmot<0)marmot=0;
			}
			if (marmot>-1&&marmot<1297){
				char file[1024];
				snprintf(file,1023,"%s%s", songs[thesong].location,songs[thesong].advsoundfileloc[j]);
				#ifdef SHOWWAVES
				printf("%s : ",file);
				#endif
				if (testfile(file)){
					if (testxa(file)){
						#ifdef LINUX
						char *onlytime = (char *)malloc(strlen(file) + 1);
						memcpy(onlytime, file, strlen(file) + 1);
						snprintf(file, 255, "%s.wav", onlytime);
						free(onlytime);
						#else
						decodexa(file);
						#endif
					}
					#ifdef SHOWWAVES
					printf("opened\n",file);
					#endif
					waves[marmot+256].open(file);
				}
				#ifdef SHOWWAVES
				else{printf("failed\n",file);}
				#endif
			}
		}
	}
	if (drumdiff==2){
		for (int j=0;j<songs[thesong].extsounds;j++){
			int marmot=alphatoi(songs[thesong].extsoundfilenum[j]);
			if (marmot>=1297||marmot<0){
				printf("your marmot var is out of wack.");
				if(marmot>=1297)marmot=1296;
				if(marmot<0)marmot=0;
				//appisrunning=false;
			}
			char file[256];
			if (marmot>-1&&marmot<1297){
				char file[1024];
				snprintf(file,1023,"%s%s", songs[thesong].location,songs[thesong].extsoundfileloc[j]);
				#ifdef SHOWWAVES
				printf("%s : ",file);
				#endif
				if (testfile(file)){
					if (testxa(file)){
						#ifdef LINUX
						char *onlytime = (char *)malloc(strlen(file) + 1);
						memcpy(onlytime, file, strlen(file) + 1);
						snprintf(file, 255, "%s.wav", onlytime);
						free(onlytime);
						#else
						decodexa(file);
						#endif
					}
					#ifdef SHOWWAVES
					printf("opened\n",file);
					#endif
					waves[marmot+256].open(file);
				}
				#ifdef SHOWWAVES
				else{printf("failed\n",file);}
				#endif
			}
		}
	}
	#endif
}



//end load waves
//end load waves
//end load waves


void unloadwaves(){
	#ifndef NOOSWEGO
	#ifdef EXCESSIVE
	printf("unloadwaves\n");
	#endif
	for (int a=256;a<1554;a++){
		if (waves[a].get_state()!=AL::STATE_CLOSED&&waves[a].get_state()!=AL::STATE_STOPPED){
			waves[a].stop();
		}
	}
	#endif
}

void closewaves(){
	#ifndef NOOSWEGO
	#ifdef EXCESSIVE
	printf("unloadwaves\n");
	#endif
	for (int a=0;a<1554;a++){
		if (waves[a].get_state()!=AL::STATE_CLOSED&&waves[a].get_state()!=AL::STATE_STOPPED){
			waves[a].stop();
		}
	}
	for (int a=0;a<1554;a++){
		if (waves[a].get_state()!=AL::STATE_CLOSED){
			waves[a].close();
		}
	}
	#endif
}

//end load waves
//end load waves
//end load waves
