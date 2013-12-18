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
void getthemelist(){
    #ifdef EXCESSIVE
	printf("getthemelist\n");
	#endif
	int a=0;
	char themedir[256];
	DIR *d;
	dirent *dir;
	d=opendir("./Themes");
	if (d==NULL){
		printf("Security settings for theme directory incorrect.");
		exit(1);
	}
	while(dir=readdir(d)){
		if (strcmp(dir->d_name,".")==0 || strcmp(dir->d_name,"..")==0){
			continue;
		}
		snprintf(themes[a],255, "%s", dir->d_name);
		if (strcmp(themes[a],theme)==0)
			themenumber=a;
		themecount=a;
		a++;
	}
	
	a=0;
	d=opendir("./Noteskins");
	if (d==NULL){
		printf("Security settings for noteskin directory incorrect.");
		exit(1);
	}
	while(dir=readdir(d)){
		if (strcmp(dir->d_name,".")==0 || strcmp(dir->d_name,"..")==0){
			continue;
		}
		snprintf(noteskins[a],255, "%s", dir->d_name);
		if (strcmp(noteskins[a],noteskin)==0)
			noteskinnumber=a;
		noteskincount=a;
		a++;
	}
}
void cachesong(char songfolder[512], char songname[512], char catname[256]){
    #ifdef EXCESSIVE
	printf("cachesong\n");
	#endif
	if (strlen(songfolder)<1)return;
	if (strlen(songname)<1)return;
	if (strlen(catname)<1)return;
	static int songnum=0;
	songs[songnum].load(songfolder,songname,catname);
	songnum++;
}

void cachesongs(){
	#ifdef EXCESSIVE
	printf("cachesongs\n");
	#endif
	char songdir[512];
	for (int a=0;a<gbcatcount;a++){
		catsongs[a]=0;
	}
	songs=new song[gbsongcount];
	int songcount=0;
	int catcount=0;
	DIR *d;
	DIR *d2;
	dirent *dir;
	dirent *cat;
	d=opendir("./Songs");
	char dircat[256];
	if (d==NULL){
		printf("Security settings for songs directory incorrect.");
		exit(1);
	}
	while(dir=readdir(d)){
		if (!appisrunning)break;
		if (strcmp( dir->d_name, ".")==0 ||strcmp(dir->d_name,"..")==0){
			continue;
		}
		struct stat idiots;
		char fuckingidiots[1024];
		snprintf(fuckingidiots,1023, "./Songs/%s", dir->d_name);
		stat(fuckingidiots,&idiots);
		if (!S_ISDIR(idiots.st_mode)){
			continue;
		}
		snprintf(dircat,255, "./Songs/%s", dir->d_name);
		snprintf(catlist[catcount],255, "%s", dir->d_name);
		d2=opendir(dircat);
		while(cat=readdir(d2)){
			if (!appisrunning)break;
			if (strcmp( cat->d_name, ".")==0 ||strcmp(cat->d_name,"..")==0){
				continue;
			}
			struct stat grumblegrumble;
			char fuckinggrr[1024];
			snprintf (fuckinggrr,1023,"./Songs/%s/%s",dir->d_name,cat->d_name);
			stat(fuckinggrr,&grumblegrumble);
			if (!S_ISDIR(grumblegrumble.st_mode)){
				continue;
			};
			catsongs[catcount]++;
			static drawtext songloading;
			songloading.load(cat->d_name,"font.ttf",255,255,255,24);
			songloading.draw(0,25,0);
			static drawtext catloading;
			catloading.load(dir->d_name,"font.ttf",255,255,255,24);
			catloading.draw(0,50,0);
			nextobject();
			snprintf(songdir,511, "./Songs/%s/%s/", dir->d_name,cat->d_name);
			cachesong(songdir,cat->d_name,dir->d_name);
		}
		catcount++;
	}
}
