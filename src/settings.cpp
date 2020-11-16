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
gamesettings::gamesettings(){}
gamesettings::~gamesettings(){}
void gamesettings::load(){
	#ifdef EXCESSIVE
	printf("gamesettings::load\n");
	#endif
	ifstream settingsfile;
	char file[21];
	snprintf(file,20,"./Data/settings.ini");
	while(fstreampotty>0){}
	fstreampotty++;
	settingsfile.open(file,ifstream::in);
    fstreampotty--;
	if (settingsfile.fail()){
		printf("Holy shit, what the fuck did you do with the settings?\nYou could try creating a new blank settings.ini file in the data directory if you want to start new, or replace the settings.ini file.\nIf all else fails, reinstall or check directory permissions.");
		appisrunning=false;return;
	}else{
		#ifdef DEBUG
		printf("Now loading your settings...\n");
		#endif
	}
	while (settingsfile.good()){
		char buffer[512];
		char variable[256];
		char varvalue[256];
		snprintf(variable,511,"");
		snprintf(varvalue,255,"");
		snprintf(buffer,255,"");
		settingsfile.getline(buffer,511,'\n');
		if (buffer[strlen(buffer)-1]=='\r'){
			buffer[strlen(buffer)-1]='\0';
		}
		bool isvalue=false;
		int n=0;
		int x=0;
		if (buffer[0]!='#'&&buffer[0]!='['){
			while (n<strlen(buffer)){
				if (!isvalue)variable[n]=buffer[n];
				if (isvalue)varvalue[n-x]=buffer[n];
				if (buffer[n]=='='){
					variable[n]='\0';
					isvalue=true;
					x=n+1;
				}
				n++;
			}
			varvalue[n-x]='\0';
		}
		//loading the settings!
		if (strcmp(strlwr2(variable),"fullscreen")==0)
			if (strcmp(strlwr2(varvalue),"true")==0)
				drumfullscreen=true;
			else
				drumfullscreen=false;
		if (strcmp(strlwr2(variable),"xres")==0)
			resx=atoi(varvalue);		
		if (strcmp(strlwr2(variable),"xres")==0)
			resx=atoi(varvalue);
		if (strcmp(strlwr2(variable),"yres")==0)
			resy=atoi(varvalue);
		if (strcmp(strlwr2(variable),"bpp")==0)
			drumbpp=atoi(varvalue);
		if (strcmp(strlwr2(variable),"theme")==0)
			snprintf(theme,255,"%s", varvalue);
		if (strcmp(strlwr2(variable),"noteskin")==0)
			snprintf(noteskin,255,"%s", varvalue);
		if (strcmp(strlwr2(variable),"hihat")==0)
			hihatkey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"snare")==0)
			snarekey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"bass")==0)
			basskey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"hitom")==0)
			hitomkey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"lotom")==0)
			lotomkey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"cymbal")==0)
			cymbalkey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"back")==0)
			backkey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"start")==0)
			startkey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"althihat")==0)
			althihatkey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"altsnare")==0)
			altsnarekey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"altbass")==0)
			altbasskey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"althitom")==0)
			althitomkey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"altlotom")==0)
			altlotomkey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"altcymbal")==0)
			altcymbalkey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar1r")==0)
			guitar1r=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar1g")==0)
			guitar1g=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar1b")==0)
			guitar1b=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar1p")==0)
			guitar1p=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar1a")==0)
			guitar1a=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar1w")==0)
			guitar1w=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar1back")==0)
			guitar1back=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar1start")==0)
			guitar1start=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar2r")==0)
			guitar2r=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar2g")==0)
			guitar2g=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar2b")==0)
			guitar2b=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar2w")==0)
			guitar2w=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar2p")==0)
			guitar2p=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar2a")==0)
			guitar2a=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar2back")==0)
			guitar2back=atoi(varvalue);
		if (strcmp(strlwr2(variable),"guitar2start")==0)
			guitar2start=atoi(varvalue);
		if (strcmp(strlwr2(variable),"debugstats")==0)
			if (strcmp(strlwr2(varvalue),"true")==0)
				debugstats=true;
		if (strcmp(strlwr2(variable),"autocymbal")==0)
			if (strcmp(strlwr2(varvalue),"true")==0)
				autocymbal=true;
		if (strcmp(strlwr2(variable),"autobass")==0)
			if (strcmp(strlwr2(varvalue),"true")==0)
				autobass=true;
		if (strcmp(strlwr2(variable),"autohihat")==0)
			if (strcmp(strlwr2(varvalue),"true")==0)
				autohihat=true;
		if (strcmp(strlwr2(variable),"autoall")==0)
			if (strcmp(strlwr2(varvalue),"true")==0)
				autoall=true;
		if (strcmp(strlwr2(variable),"stagefail")==0)
			if (strcmp(strlwr2(varvalue),"false")==0)
				stagefail=false;
		if (strcmp(strlwr2(variable),"notespeed")==0)
			notespeed=atoi(varvalue);
		if (strcmp(strlwr2(variable),"lifedifficulty")==0)
			lifedifficulty=atoi(varvalue);
		if (strcmp(strlwr2(variable),"voldrum")==0)
			voldrum=atoi(varvalue);
		if (strcmp(strlwr2(variable),"volguit")==0)
			volguit=atoi(varvalue);
		if (strcmp(strlwr2(variable),"volbass")==0)
			volbass=atoi(varvalue);
		if (strcmp(strlwr2(variable),"volbgm")==0)
			volbgm=atoi(varvalue);
		if (strcmp(strlwr2(variable),"stages")==0)
			stages=atoi(varvalue);
		if (strcmp(strlwr2(variable),"tvscale")==0)
			tvscale=atoi(varvalue);
		if (strcmp(strlwr2(variable),"rate")==0)
			audio_rate=atoi(varvalue);
		if (strcmp(strlwr2(variable),"format")==0)
			audio_format=atoi(varvalue);
		if (strcmp(strlwr2(variable),"channels")==0)
			audio_channels=atoi(varvalue);
		if (strcmp(strlwr2(variable),"refreshrate")==0)
			refreshrate=atoi(varvalue);
		if (strcmp(strlwr2(variable),"buffers")==0)
			audio_buffers=atoi(varvalue);
		if (strcmp(strlwr2(variable),"aviresolution")==0)
			avires=atoi(varvalue);
		if (strcmp(strlwr2(variable),"favordtx")==0)
			if (strcmp(strlwr2(varvalue),"true")==0)
				favordtx=true;
		if (strcmp(strlwr2(variable),"notesoundoffset")==0)
			notesoundoffset=atoi(varvalue);
		if (strcmp(strlwr2(variable),"entiresongoffset")==0)
			entiresongoffset=atoi(varvalue);
		if (strcmp(strlwr2(variable),"ratioadjust")==0)
			if (strcmp(strlwr2(varvalue),"false")==0)
				ratioadjust=false;
		if (strcmp(strlwr2(variable),"forcewide")==0)
			if (strcmp(strlwr2(varvalue),"true")==0)
				forcewide=true;
		if (strcmp(strlwr2(variable),"arcademode")==0)
			if (strcmp(strlwr2(varvalue),"true")==0)
				arcademode=true;
		if (strcmp(strlwr2(variable),"coinsperplay")==0)
			coinsperplay=atoi(varvalue);
		if (strcmp(strlwr2(variable),"menucountertime")==0)
			menucountertime=atoi(varvalue);
		if (strcmp(strlwr2(variable),"coinkey")==0)
			coinkey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"opskey")==0)
			opskey=atoi(varvalue);
		if (strcmp(strlwr2(variable),"anisotropicfiltering")==0)
			if (strcmp(strlwr2(varvalue),"false")==0)
				allowaf=false;
		if (strcmp(strlwr2(variable),"maxfilteringamount")==0)
			afamount=atoi(varvalue);
		if (strcmp(strlwr2(variable),"opskey")==0)
			opskey=atoi(varvalue);
	}
	origfullscreen=drumfullscreen;
	origresx=resx;
	origresy=resy;
	origbpp=drumbpp;
	snprintf(origtheme,255,"%s", theme);
	snprintf(orignoteskin,255,"%s", noteskin);
	settingsfile.close();
	uivars.load();
}

void gamesettings::save(){
	#ifdef EXCESSIVE
	printf("gamesettings::save\n");
	#endif
	ofstream settingsfile;
	char file[21];
	char thefile[1024];
	snprintf(file,20,"./Data/settings.ini");
	while(fstreampotty>0){}
	fstreampotty++;
	settingsfile.open(file,ofstream::out);
	fstreampotty--;
	if (settingsfile.fail()){
		printf("Holy shit, what the fuck did you do with the settings?\nYou could try creating a new blank settings.ini file in the data directory if you want to start new, or replace the settings.ini file.\nIf all else fails, reinstall or check directory permissions.");
	}

	//here we structure setting.ini for writing.
	snprintf(thefile,1023,"[DigiBand Settings]\n[graphics]\nfullscreen=");
	settingsfile << thefile;
	if (drumfullscreen)
		snprintf(thefile,1023,"true\n");
	else
		snprintf(thefile,1023,"false\n");
	settingsfile << thefile;
	snprintf(thefile,1023,"xres=%i\n",resx);
	settingsfile << thefile;
	snprintf(thefile,1023,"yres=%i\n",resy);
	settingsfile << thefile;
	snprintf(thefile,1023,"bpp=%i\n",drumbpp);
	settingsfile << thefile;
	snprintf(thefile,1023,"refreshrate=%i\n",refreshrate);
	settingsfile << thefile;
	snprintf(thefile,1023,"tvscale=%i\n",tvscale);
	settingsfile << thefile;
	snprintf(thefile,1023,"theme=%s\n",theme);
	settingsfile << thefile;
	snprintf(thefile,1023,"noteskin=%s\n",noteskin);
	settingsfile << thefile;
	snprintf(thefile,1023,"AVIresolution=%i\n",avires);
	settingsfile << thefile;
	if (ratioadjust)
		snprintf(thefile,1023,"ratioadjust=true\n");
	else
		snprintf(thefile,1023,"ratioadjust=false\n");
	settingsfile << thefile;
	if (debugstats)
		snprintf(thefile,1023,"debugstats=true\n");
	else
		snprintf(thefile,1023,"debugstats=false\n");
	settingsfile << thefile;
	if (allowaf)
		snprintf(thefile,1023,"anisotropicfiltering=true\n");
	else
		snprintf(thefile,1023,"anisotropicfiltering=false\n");
	settingsfile << thefile;
	snprintf(thefile,1023,"maxfilteringamount=%i\n",afamount);
	settingsfile << thefile;
	if (forcewide)
		snprintf(thefile,1023,"forcewide=true\n");
	else
		snprintf(thefile,1023,"forcewide=false\n\n");
 	settingsfile << thefile;
	snprintf(thefile,1023,"[gameplay]\n");
	settingsfile << thefile;
	snprintf(thefile,1023,"notespeed=%i\n",notespeed);
	settingsfile << thefile;
	snprintf(thefile,1023,"lifedifficulty=%i\n",lifedifficulty);
	settingsfile << thefile;
	snprintf(thefile,1023,"stages=%i\n",stages);
	settingsfile << thefile;
	if (stagefail)
		snprintf(thefile,1023,"stagefail=true\n\n");
	else
		snprintf(thefile,1023,"stagefail=false\n\n");
	settingsfile << thefile;
	snprintf(thefile,1023,"[Sound Options]\n");
	settingsfile << thefile;
	snprintf(thefile,1023,"voldrum=%i\n",voldrum);
	settingsfile << thefile;
	snprintf(thefile,1023,"volguit=%i\n",volguit);
	settingsfile << thefile;
	snprintf(thefile,1023,"volbass=%i\n",volbass);
	settingsfile << thefile;
	snprintf(thefile,1023,"volbgm=%i\n\n",volbgm);
	settingsfile << thefile;
	snprintf(thefile,1023,"[auto settings]\n");
	settingsfile << thefile;
	if (autocymbal)
		snprintf(thefile,1023,"autocymbal=true\n");
	else
		snprintf(thefile,1023,"autocymbal=false\n");
	settingsfile << thefile;
	if (autobass)
		snprintf(thefile,1023,"autobass=true\n");
	else
		snprintf(thefile,1023,"autobass=false\n");
	settingsfile << thefile;
	if (autohihat)
		snprintf(thefile,1023,"autohihat=true\n");
	else
		snprintf(thefile,1023,"autohihat=false\n");
	settingsfile << thefile;
	if (autoall)
		snprintf(thefile,1023,"autoall=true\n\n");
	else
		snprintf(thefile,1023,"autoall=false\n\n");
	settingsfile << thefile;
	snprintf(thefile,1023,"[Drum Controls]\n");
	settingsfile << thefile;
	snprintf(thefile,1023,"hihat=%i\n",hihatkey);
	settingsfile << thefile;
	snprintf(thefile,1023,"snare=%i\n",snarekey);
	settingsfile << thefile;
	snprintf(thefile,1023,"bass=%i\n",basskey);
	settingsfile << thefile;
	snprintf(thefile,1023,"hitom=%i\n",hitomkey);
	settingsfile << thefile;
	snprintf(thefile,1023,"lotom=%i\n",lotomkey);
	settingsfile << thefile;
	snprintf(thefile,1023,"cymbal=%i\n",cymbalkey);
	settingsfile << thefile;
	snprintf(thefile,1023,"althihat=%i\n",althihatkey);
	settingsfile << thefile;
	snprintf(thefile,1023,"altsnare=%i\n",altsnarekey);
	settingsfile << thefile;
	snprintf(thefile,1023,"altbass=%i\n",altbasskey);
	settingsfile << thefile;
	snprintf(thefile,1023,"althitom=%i\n",althitomkey);
	settingsfile << thefile;
	snprintf(thefile,1023,"altlotom=%i\n",altlotomkey);
	settingsfile << thefile;
	snprintf(thefile,1023,"altcymbal=%i\n",altcymbalkey);
	settingsfile << thefile;
	snprintf(thefile,1023,"back=%i\n",backkey);
	settingsfile << thefile;
	snprintf(thefile,1023,"start=%i\n\n",startkey);
	settingsfile << thefile;
	snprintf(thefile,1023,"[Guitar 1 Controls]\n");
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar1r=%i\n",guitar1r);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar1g=%i\n",guitar1g);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar1b=%i\n",guitar1b);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar1w=%i\n",guitar1w);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar1p=%i\n",guitar1p);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar1a=%i\n",guitar1a);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar1back=%i\n",guitar1back);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar1start=%i\n\n",guitar1start);
	settingsfile << thefile;
	snprintf(thefile,1023,"[Guitar 2 Controls]\n");
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar2r=%i\n",guitar2r);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar2g=%i\n",guitar2g);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar2b=%i\n",guitar2b);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar2w=%i\n",guitar2w);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar2p=%i\n",guitar2p);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar2a=%i\n",guitar2p);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar2back=%i\n",guitar2back);
	settingsfile << thefile;
	snprintf(thefile,1023,"guitar2start=%i\n\n",guitar2start);
	settingsfile << thefile;
	snprintf(thefile,1023,"[Audio System]\n");
	settingsfile << thefile;
	snprintf(thefile,1023,"rate=%i\n",audio_rate);
	settingsfile << thefile;
	snprintf(thefile,1023,"format=%i\n",audio_format);
	settingsfile << thefile;
	snprintf(thefile,1023,"channels=%i\n",audio_channels);
	settingsfile << thefile;
	snprintf(thefile,1023,"buffers=%i\n\n",audio_buffers);
	settingsfile << thefile;
	snprintf(thefile,1023,"[Arcade]\n");
	settingsfile << thefile;
	if (arcademode)
		snprintf(thefile,1023,"arcademode=true\n");
	else
		snprintf(thefile,1023,"arcademode=false\n");
	settingsfile << thefile;
	snprintf(thefile,1023,"coinsperplay=%i\n",coinsperplay);
	settingsfile << thefile;
	snprintf(thefile,1023,"menucountertime=%i\n",menucountertime);
	settingsfile << thefile;
	snprintf(thefile,1023,"coinkey=%i\n",coinkey);
	settingsfile << thefile;
	snprintf(thefile,1023,"opskey=%i\n\n",opskey);
	settingsfile << thefile;
	snprintf(thefile,1023,"[Misc]\n");
	settingsfile << thefile;
	if (favordtx)
		snprintf(thefile,1023,"favordtx=true\n");
	else
		snprintf(thefile,1023,"favordtx=false\n");
	settingsfile << thefile;
	snprintf(thefile,1023,"notesoundoffset=%i\n",notesoundoffset);
	settingsfile << thefile;
	snprintf(thefile,1023,"entiresongoffset=%i\n",entiresongoffset);
	settingsfile << thefile;
	snprintf(thefile,1023,"#These offsets are measured via miliseconds.\n\n");
	settingsfile << thefile;
			
	if (drumfullscreen!=origfullscreen ||
		resx!=origresx ||
		resy!=origresy ||
		drumbpp!=origbpp){
  		screenreinit(resx,resy,drumbpp,drumfullscreen);
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity( );
		static drawtext message;
		message.load("Please Wait...","font.ttf",255,255,255,60);
		message.draw(350,350,0);
		//fat bastard isn't it? All of this is just to display, "Please wait.."
		SDL_GL_SwapBuffers();
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity( );
        reloadtheme();
	}else if (strcmp(origtheme,theme)!=0 || strcmp(orignoteskin,noteskin)!=0){
        SDL_GL_SwapBuffers();
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity( );
		static drawtext message;
		message.load("Please Wait...","font.ttf",255,255,255,60);
		message.draw(350,350,0);
		//fat bastard isn't it? All of this is just to display, "Please wait.."
		SDL_GL_SwapBuffers();
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity( );
        reloadtheme();
	}
	settingsfile.close();
	origfullscreen=drumfullscreen;
	origresx=resx;
	origresy=resy;
	origbpp=drumbpp;
	snprintf(origtheme,255,"%s", theme);
}

void loadscores(){
	#ifdef EXCESSIVE
	printf("gamesettings::loadscores\n");
	#endif
	ifstream settingsfile;
	char file[21];
	snprintf(file,20,"./Data/hiscores.dat");
	if (!testfile(file)){
        printf("Holy shit, what the fuck did you do with the high scores?\nYou could try creating a new blank hiscores.dat file in the data directory if you want to start new, or replace the settings.ini file.\nIf all else fails, reinstall or check directory permissions.\n");
		appisrunning=false;
		return;
	}
	while(fstreampotty>0){}
    fstreampotty++;
	settingsfile.open(file,ifstream::in);
	fstreampotty--;
	int sn=0;
	if (settingsfile.fail())return;
	for (int a=0;a<10;a++){
		snprintf(dmscorenames[a],255,"DGB");
		snprintf(gscorenames[a],255,"DGB");
		dmscores[a]=(10-a)*5000000;
		gscores[a]=(10-a)*5000000;
	}
	while (!settingsfile.eof()){
		char buffer[512];
		char variable[256];
		char varvalue[256];
		snprintf(variable,255,"");
		snprintf(varvalue,255,"");
		snprintf(buffer,511,"");
		settingsfile.getline(buffer,511,'\n');
		if (buffer[strlen(buffer)-1]=='\r'){
			buffer[strlen(buffer)-1]='\0';
		}
		bool isvalue=false;
		int n=0;
		int x=0;
		if (buffer[0]!='#'&&buffer[0]!='['){
			while (n<strlen(buffer)){
				if (!isvalue)variable[n]=buffer[n];
				if (isvalue)varvalue[n-x]=buffer[n];
				if (buffer[n]=='='){
					variable[n]='\0';
					isvalue=true;
					x=n+1;
				}
				n++;
			}
			varvalue[n-x]='\0';
		}
		if (isvalue){
			//pull highscore
			if (sn<10){
				snprintf(dmscorenames[sn],255,"%s", variable);
				dmscores[sn]=atol(varvalue);
			}else if(sn<20){
				snprintf(gscorenames[sn-10],255,"%s", variable);
				gscores[sn-10]=atol(varvalue);
			}		
			sn++;
		}
	}
	settingsfile.close();
	settingsfile.clear();
}

void savescores(){
	#ifdef EXCESSIVE
	printf("gamesettings::savescores\n");
	#endif
  	#ifdef DEBUG
	printf("saving Hi-score data...\n");
	#endif
	int a=0;
	while (a<11&&gptscore<=dmscores[a]){
		a++;	
	}
	if (a<9){
		for (int b=9;b>a;b--){
			snprintf(dmscorenames[b],255,"%s",dmscorenames[b-1]);
			dmscores[b]=dmscores[b-1];
		}
		dmscores[a]=gptscore;
		snprintf(dmscorenames[a],255, "%s", dminitials);
	}
	a=0;
	while (a<11&&gpg1tscore<=gscores[a]){
		a++;	
	}
	if (a<9){
		for (int b=9;b>a;b--){
			snprintf(gscorenames[b],255,"%s", gscorenames[b-1]);
			gscores[b]=gscores[b-1];
		}
		gscores[a]=gpg1tscore;
		snprintf(gscorenames[a],255,"%s", g1initials);
	}
	a=0;
	while (a<11&&gpg2tscore<=gscores[a]){
		a++;	
	}
	if (a<9){
		for (int b=9;b>a;b--){
			snprintf(gscorenames[b],255,"%s", gscorenames[b-1]);
			gscores[b]=gscores[b-1];
		}
		gscores[a]=gpg2tscore;
		snprintf(gscorenames[a],255,"%s", g2initials);
	}

	
	ofstream settingsfile;
	char file[21];
	snprintf(file,20,"./Data/hiscores.dat");
  	if (!testfile(file)){
        printf("Holy shit, what the fuck did you do with the hiscores?\nYou could try creating a new blank hiscores.dat file in the data directory if you want to start new, or replace the settings.ini file.\nIf all else fails, reinstall or check directory permissions.\n");
		appisrunning=false;
		return;
	}
	while(fstreampotty>0){}
    	fstreampotty++;
	settingsfile.open(file,ofstream::out);
	fstreampotty--;
	if (settingsfile.fail())return;
	char thefile[1024];
	snprintf(thefile,1023,"[DRUM SCORES]\n");
	settingsfile << thefile;
	for (int b=0;b<10;b++){
		snprintf(thefile,1023,"%s=%i\n",dmscorenames[b],dmscores[b]);
		settingsfile << thefile;
	}
	snprintf(thefile,1023,"[GUITAR SCORES]\n");
	settingsfile << thefile;
	for (int b=0;b<10;b++){
		snprintf(thefile,1023,"%s=%i\n",gscorenames[b],gscores[b]);
		settingsfile << thefile;
	}
	settingsfile.close();
   	#ifdef DEBUG
	printf("Hi-score data saved.\n");
	#endif
}
