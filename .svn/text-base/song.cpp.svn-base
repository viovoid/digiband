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

/*-----------------------------------*\
notes for reading steps (for other developers and myself.):
#***|**: (eg. wav22:marmot.wave, 01012:22)
***=wav - If this is in the file, it's designating what wave file to play, this file is scripted and meant to be streamed, so this should be able to change on the fly.
***=bmp will load an image
***=avi will load an avi file
***=BGA will position the image, however will do nothing for this game.
***=BGAPAN will also be ignored by this game.

***=measure - play wav(**) on measure *** with |** being the track:
Tracks:
//song control
01-Background Music
02-time signitaure(1=4/4;.75=3/4;1.0525=17/16;) 4:4 timing basically
03-BPM (00007000=on the 3rd beat:70(hex) which is 112(dec) which means here the bpm will be 122bpm on the 3rd beat).
04-BGA (When to play specified BGA eg, 00104:01 will play bmp01 or avi01 etc.
05-(nothing)
06-(nothing)
07-BGA(same as 04)
08-BPM change period.. uses BPM** instead of 03's BPM stepping.
09-10(reserved... by?)
//drum
11-HiHatClose is also	HH
12-Snare				SN
13-BassDrum				BD
14-HighTom				HT
15-LowTom				LT
16-Cymbal				CY
17-FloorTom				FT
18-HiHatOpen			HO
19-RideCymbal			RC
//guitar(treble)
20-Open Pick
21-B
22-G
23-GB
24-R
25-RB
26-RG
27-RGB
GW/28-wail
29 n/a 
30 n/a
//Drum miss tracks: Make music sound like S**T
31-39==11-19
//
40 ???
41-46 n/a
47-49 ???
50 not going to be used, but allows cutom measures.
51 not going to be used, but allows cutom notes.
52-Midi note play... not using.
53-Cheer zone.. appearntly 01 means start the zone, 02 means end, when a full combo has gone through, "Cheering" will occur.
54-Play avi file on beat.
55-60 Layered BGA images... with 60 drawn on top, 07 being drawn on botton, (Will keep this)
61-92 Plays sound/mp3 at on the designated beat.
93-99 Nothing.

//Bass notes
A0-Open Pick
A1-B
A2-G
A3-GB
A4-R
A5-RB
A6-RG
A7-RGB
A8/BW-basswail

B1-B9 same as 31-39
BA the guitar miss
BB the bass miss
\*-------------------------------------------------------------*/

song::song(){
	#ifdef EXCESSIVE
	printf("song::song\n");
	#endif
	init();
}

void song::init() {
	#ifdef EXCESSIVE
	printf("song::init\n");
	#endif
	snprintf(name,255,"(none)");
	snprintf(title,255,"(none)");
	snprintf(artist,255,"(none)");
	snprintf(previewwave,255,"");
	snprintf(previewimg,255,"");
	snprintf(background,255,"");
	snprintf(genre,255,"");
	snprintf(cat,255,"");
	snprintf(location,255,"");
	bassounds=0;
	advsounds=0;
	extsounds=0;
	highestmeasure=0;
	basavis=0;
	advavis=0;
	extavis=0;
	basnotes=0;
	advnotes=0;
	extnotes=0;
	bpm=0;
	basebpm=0;
	drumbasdiff=0;
	drumadvdiff=0;
	drumextdiff=0;
	lowestdrumdiff=0;
	guitbasdiff=0;
	guitadvdiff=0; 
	guitextdiff=0;
	lowestguitdiff=0;
	guitbbasdiff=0;
	guitbadvdiff=0;
	guitbextdiff=0;
	drumbastrue=false;
	drumadvtrue=false;
	drumexttrue=false;
	guitbastrue=false;
	guitadvtrue=false;
	guitexttrue=false;
	basgda=false;
	advgda=false;
	extgda=false;
	hasopenpick=false;
	//extended attributes
	offset=0;
	poffset=0;
	basdrumhs=0;
	advdrumhs=0;
	extdrumhs=0;
	basguitar1hs=0;
	advguitar1hs=0;
	extguitar1hs=0;
	basguitar2hs=0;
	advguitar2hs=0;
	extguitar2hs=0;
	basdrummc=0;
	advdrummc=0;
	extdrummc=0;
	basguitar1mc=0;
	advguitar1mc=0;
	extguitar1mc=0;
	basguitar2mc=0;
	advguitar2mc=0;
	extguitar2mc=0;
	islong=false;
}

song::~song(){
	#ifdef EXCESSIVE
	printf("song::~song\n");
	#endif
}

void song::randomize(){
	#ifdef EXCESSIVE
	printf("song::randomize\n");
	#endif
	srand(SDL_GetTicks());
	for (int a=0;a<basnotes;a++){
		if (drumrandommode){
			if (strcmp(basnotetype[a],"hh")==0||strcmp(basnotetype[a],"bd")==0||strcmp(basnotetype[a],"sd")==0||strcmp(basnotetype[a],"ht")==0||strcmp(basnotetype[a],"lt")==0||strcmp(basnotetype[a],"cy")==0||
			strcmp(basnotetype[a],"11")==0||strcmp(basnotetype[a],"12")==0||strcmp(basnotetype[a],"13")==0||strcmp(basnotetype[a],"14")==0||strcmp(basnotetype[a],"15")==0||strcmp(basnotetype[a],"16")==0){
				int b=int((double(rand())/double(RAND_MAX))*6.0);
				snprintf(basnotetype[a],99,"1%i", b+1);
			}
		}		
		if (guit1randommode){
			if (strcmp(basnotetype[a],"g0")==0||strcmp(basnotetype[a],"g1")==0||strcmp(basnotetype[a],"g2")==0||strcmp(basnotetype[a],"g3")==0||strcmp(basnotetype[a],"g4")==0||strcmp(basnotetype[a],"g5")==0||strcmp(basnotetype[a],"g6")==0||strcmp(basnotetype[a],"g7")==0||
			strcmp(basnotetype[a],"20")==0||strcmp(basnotetype[a],"21")==0||strcmp(basnotetype[a],"22")==0||strcmp(basnotetype[a],"23")==0||strcmp(basnotetype[a],"24")==0||strcmp(basnotetype[a],"25")==0||strcmp(basnotetype[a],"26")==0||strcmp(basnotetype[a],"27")==0){
				int b=int((double(rand())/double(RAND_MAX))*7.0);
				snprintf(basnotetype[a],99,"2%i", b);
			}
			if (strcmp(basnotetype[a],"a0")==0||strcmp(basnotetype[a],"a1")==0||strcmp(basnotetype[a],"a2")==0||strcmp(basnotetype[a],"a3")==0||strcmp(basnotetype[a],"a4")==0||strcmp(basnotetype[a],"a5")==0||strcmp(basnotetype[a],"a6")==0||strcmp(basnotetype[a],"a7")==0||
			strcmp(basnotetype[a],"b0")==0||strcmp(basnotetype[a],"b1")==0||strcmp(basnotetype[a],"b2")==0||strcmp(basnotetype[a],"b3")==0||strcmp(basnotetype[a],"b4")==0||strcmp(basnotetype[a],"b5")==0||strcmp(basnotetype[a],"b6")==0||strcmp(basnotetype[a],"b7")==0){
				int b=int((double(rand())/double(RAND_MAX))*7.0);
				snprintf(basnotetype[a],99,"b%i", b);
			}
		}
		if (guit2randommode){
			if (strcmp(basnotetype2[a],"g0")==0||strcmp(basnotetype2[a],"g1")==0||strcmp(basnotetype2[a],"g2")==0||strcmp(basnotetype2[a],"g3")==0||strcmp(basnotetype2[a],"g4")==0||strcmp(basnotetype2[a],"g5")==0||strcmp(basnotetype2[a],"g6")==0||strcmp(basnotetype2[a],"g7")==0||
			strcmp(basnotetype2[a],"20")==0||strcmp(basnotetype2[a],"21")==0||strcmp(basnotetype2[a],"22")==0||strcmp(basnotetype2[a],"23")==0||strcmp(basnotetype2[a],"24")==0||strcmp(basnotetype2[a],"25")==0||strcmp(basnotetype2[a],"26")==0||strcmp(basnotetype2[a],"27")==0){
				int b=int((double(rand())/double(RAND_MAX))*7.0);
				snprintf(basnotetype2[a],99,"2%i", b);
			}
			if (strcmp(basnotetype2[a],"a0")==0||strcmp(basnotetype2[a],"a1")==0||strcmp(basnotetype2[a],"a2")==0||strcmp(basnotetype2[a],"a3")==0||strcmp(basnotetype2[a],"a4")==0||strcmp(basnotetype2[a],"a5")==0||strcmp(basnotetype2[a],"a6")==0||strcmp(basnotetype2[a],"a7")==0||
			strcmp(basnotetype2[a],"b0")==0||strcmp(basnotetype2[a],"b1")==0||strcmp(basnotetype2[a],"b2")==0||strcmp(basnotetype2[a],"b3")==0||strcmp(basnotetype2[a],"b4")==0||strcmp(basnotetype2[a],"b5")==0||strcmp(basnotetype2[a],"b6")==0||strcmp(basnotetype2[a],"b7")==0){
				int b=int((double(rand())/double(RAND_MAX))*7.0);
				snprintf(basnotetype2[a],99,"b%i", b);
			}
		}
	}
	for (int a=0;a<advnotes;a++){
		if (drumrandommode){
			if (strcmp(advnotetype[a],"hh")==0||strcmp(advnotetype[a],"bd")==0||strcmp(advnotetype[a],"sd")==0||strcmp(advnotetype[a],"ht")==0||strcmp(advnotetype[a],"lt")==0||strcmp(advnotetype[a],"cy")==0||
			strcmp(advnotetype[a],"11")==0||strcmp(advnotetype[a],"12")==0||strcmp(advnotetype[a],"13")==0||strcmp(advnotetype[a],"14")==0||strcmp(advnotetype[a],"15")==0||strcmp(advnotetype[a],"16")==0){
				int b=int((double(rand())/double(RAND_MAX))*6.0);
				snprintf(advnotetype[a],99,"1%i", b+1);
			}
		}
		if (guit1randommode){
			if (strcmp(advnotetype[a],"g0")==0||strcmp(advnotetype[a],"g1")==0||strcmp(advnotetype[a],"g2")==0||strcmp(advnotetype[a],"g3")==0||strcmp(advnotetype[a],"g4")==0||strcmp(advnotetype[a],"g5")==0||strcmp(advnotetype[a],"g6")==0||strcmp(advnotetype[a],"g7")==0||
			strcmp(advnotetype[a],"20")==0||strcmp(advnotetype[a],"21")==0||strcmp(advnotetype[a],"22")==0||strcmp(advnotetype[a],"23")==0||strcmp(advnotetype[a],"24")==0||strcmp(advnotetype[a],"25")==0||strcmp(advnotetype[a],"26")==0||strcmp(advnotetype[a],"27")==0){
				int b=int((double(rand())/double(RAND_MAX))*7.0);
				snprintf(advnotetype[a],99,"2%i", b);
			}
			if (strcmp(advnotetype[a],"a0")==0||strcmp(advnotetype[a],"a1")==0||strcmp(advnotetype[a],"a2")==0||strcmp(advnotetype[a],"a3")==0||strcmp(advnotetype[a],"a4")==0||strcmp(advnotetype[a],"a5")==0||strcmp(advnotetype[a],"a6")==0||strcmp(advnotetype[a],"a7")==0||
			strcmp(advnotetype[a],"b0")==0||strcmp(advnotetype[a],"b1")==0||strcmp(advnotetype[a],"b2")==0||strcmp(advnotetype[a],"b3")==0||strcmp(advnotetype[a],"b4")==0||strcmp(advnotetype[a],"b5")==0||strcmp(advnotetype[a],"b6")==0||strcmp(advnotetype[a],"b7")==0){
				int b=int((double(rand())/double(RAND_MAX))*7.0);
				snprintf(advnotetype[a],99,"b%i", b);
			}
		}
		if (guit2randommode){
			if (strcmp(advnotetype2[a],"g0")==0||strcmp(advnotetype2[a],"g1")==0||strcmp(advnotetype2[a],"g2")==0||strcmp(advnotetype2[a],"g3")==0||strcmp(advnotetype2[a],"g4")==0||strcmp(advnotetype2[a],"g5")==0||strcmp(advnotetype2[a],"g6")==0||strcmp(advnotetype2[a],"g7")==0||
			strcmp(advnotetype2[a],"20")==0||strcmp(advnotetype2[a],"21")==0||strcmp(advnotetype2[a],"22")==0||strcmp(advnotetype2[a],"23")==0||strcmp(advnotetype2[a],"24")==0||strcmp(advnotetype2[a],"25")==0||strcmp(advnotetype2[a],"26")==0||strcmp(advnotetype2[a],"27")==0){
				int b=int((double(rand())/double(RAND_MAX))*7.0);
				snprintf(advnotetype2[a],99,"2%i", b);
			}
			if (strcmp(advnotetype2[a],"a0")==0||strcmp(advnotetype2[a],"a1")==0||strcmp(advnotetype2[a],"a2")==0||strcmp(advnotetype2[a],"a3")==0||strcmp(advnotetype2[a],"a4")==0||strcmp(advnotetype2[a],"a5")==0||strcmp(advnotetype2[a],"a6")==0||strcmp(advnotetype2[a],"a7")==0||
			strcmp(advnotetype2[a],"b0")==0||strcmp(advnotetype2[a],"b1")==0||strcmp(advnotetype2[a],"b2")==0||strcmp(advnotetype2[a],"b3")==0||strcmp(advnotetype2[a],"b4")==0||strcmp(advnotetype2[a],"b5")==0||strcmp(advnotetype2[a],"b6")==0||strcmp(advnotetype2[a],"b7")==0){
				int b=int((double(rand())/double(RAND_MAX))*7.0);
				snprintf(advnotetype2[a],99,"b%i", b);
			}
		}
	}
	for (int a=0;a<extnotes;a++){
		if (drumrandommode){
			if (strcmp(extnotetype[a],"hh")==0||strcmp(extnotetype[a],"bd")==0||strcmp(extnotetype[a],"sd")==0||strcmp(extnotetype[a],"ht")==0||strcmp(extnotetype[a],"lt")==0||strcmp(extnotetype[a],"cy")==0||
			strcmp(extnotetype[a],"11")==0||strcmp(extnotetype[a],"12")==0||strcmp(extnotetype[a],"13")==0||strcmp(extnotetype[a],"14")==0||strcmp(extnotetype[a],"15")==0||strcmp(extnotetype[a],"16")==0){
				int b=int((double(rand())/double(RAND_MAX))*6.0);
				snprintf(extnotetype[a],99,"1%i", b+1);
			}
		}
		if (guit1randommode){
			if (strcmp(extnotetype[a],"g0")==0||strcmp(extnotetype[a],"g1")==0||strcmp(extnotetype[a],"g2")==0||strcmp(extnotetype[a],"g3")==0||strcmp(extnotetype[a],"g4")==0||strcmp(extnotetype[a],"g5")==0||strcmp(extnotetype[a],"g6")==0||strcmp(extnotetype[a],"g7")==0||
			strcmp(extnotetype[a],"20")==0||strcmp(extnotetype[a],"21")==0||strcmp(extnotetype[a],"22")==0||strcmp(extnotetype[a],"23")==0||strcmp(extnotetype[a],"24")==0||strcmp(extnotetype[a],"25")==0||strcmp(extnotetype[a],"26")==0||strcmp(extnotetype[a],"27")==0){
				int b=int((double(rand())/double(RAND_MAX))*7.0);
				snprintf(extnotetype[a],99,"2%i", b);
			}
			if (strcmp(extnotetype[a],"a0")==0||strcmp(extnotetype[a],"a1")==0||strcmp(extnotetype[a],"a2")==0||strcmp(extnotetype[a],"a3")==0||strcmp(extnotetype[a],"a4")==0||strcmp(extnotetype[a],"a5")==0||strcmp(extnotetype[a],"a6")==0||strcmp(extnotetype[a],"a7")==0||
			strcmp(extnotetype[a],"b0")==0||strcmp(extnotetype[a],"b1")==0||strcmp(extnotetype[a],"b2")==0||strcmp(extnotetype[a],"b3")==0||strcmp(extnotetype[a],"b4")==0||strcmp(extnotetype[a],"b5")==0||strcmp(extnotetype[a],"b6")==0||strcmp(extnotetype[a],"b7")==0){
				int b=int((double(rand())/double(RAND_MAX))*7.0);
				snprintf(extnotetype[a],99,"b%i", b);
			}
		}
		if (guit2randommode){
			if (strcmp(extnotetype2[a],"g0")==0||strcmp(extnotetype2[a],"g1")==0||strcmp(extnotetype2[a],"g2")==0||strcmp(extnotetype2[a],"g3")==0||strcmp(extnotetype2[a],"g4")==0||strcmp(extnotetype2[a],"g5")==0||strcmp(extnotetype2[a],"g6")==0||strcmp(extnotetype2[a],"g7")==0||
			strcmp(extnotetype2[a],"20")==0||strcmp(extnotetype2[a],"21")==0||strcmp(extnotetype2[a],"22")==0||strcmp(extnotetype2[a],"23")==0||strcmp(extnotetype2[a],"24")==0||strcmp(extnotetype2[a],"25")==0||strcmp(extnotetype2[a],"26")==0||strcmp(extnotetype2[a],"27")==0){
				int b=int((double(rand())/double(RAND_MAX))*7.0);
				snprintf(extnotetype2[a],99,"2%i", b);
			}
			if (strcmp(extnotetype2[a],"a0")==0||strcmp(extnotetype2[a],"a1")==0||strcmp(extnotetype2[a],"a2")==0||strcmp(extnotetype2[a],"a3")==0||strcmp(extnotetype2[a],"a4")==0||strcmp(extnotetype2[a],"a5")==0||strcmp(extnotetype2[a],"a6")==0||strcmp(extnotetype2[a],"a7")==0||
			strcmp(extnotetype2[a],"b0")==0||strcmp(extnotetype2[a],"b1")==0||strcmp(extnotetype2[a],"b2")==0||strcmp(extnotetype2[a],"b3")==0||strcmp(extnotetype2[a],"b4")==0||strcmp(extnotetype2[a],"b5")==0||strcmp(extnotetype2[a],"b6")==0||strcmp(extnotetype2[a],"b7")==0){
				int b=int((double(rand())/double(RAND_MAX))*7.0);
				snprintf(extnotetype2[a],99,"b%i", b);
			}
		}
	}
}

void song::saveextended(){
	#ifdef EXCESSIVE
	printf("song::saveextended\n");
	#endif
	#ifdef DEBUG
	printf("saving extended data...\n");
	#endif
	ofstream settingsfile;
	char file[256];
	char thefile[2000];
	snprintf(file,255,"%sextended.dgb", location);
	while(fstreampotty>0){}
    fstreampotty--;
	settingsfile.open(file,ofstream::out);
	fstreampotty++;
	if (!settingsfile.fail()){
		//here we structure extended.dgb for writing.
		snprintf(thefile,1999,"[Digiband extended song settings]\n");
		settingsfile << thefile;
		snprintf(thefile,1999,"offset=%i\n",offset);
		settingsfile << thefile;
		snprintf(thefile,1999,"basdrumhs=%i\n",basdrumhs);
		settingsfile << thefile;
		snprintf(thefile,1999,"advdrumhs=%i\n",advdrumhs);
		settingsfile << thefile;
		snprintf(thefile,1999,"extdrumhs=%i\n",extdrumhs);
		settingsfile << thefile;
		snprintf(thefile,1999,"basguitar1hs=%i\n",basguitar1hs);
		settingsfile << thefile;
		snprintf(thefile,1999,"advguitar1hs=%i\n",advguitar1hs);
		settingsfile << thefile;
		snprintf(thefile,1999,"extguitar1hs=%i\n",extguitar1hs);
		settingsfile << thefile;
		snprintf(thefile,1999,"basguitar2hs=%i\n",basguitar2hs);
		settingsfile << thefile;
		snprintf(thefile,1999,"advguitar2hs=%i\n",advguitar2hs);
		settingsfile << thefile;
		snprintf(thefile,1999,"extguitar2hs=%i\n",extguitar2hs);
		settingsfile << thefile;
		snprintf(thefile,1999,"basdrummc=%i\n",basdrummc);
		settingsfile << thefile;
		snprintf(thefile,1999,"advdrummc=%i\n",advdrummc);
		settingsfile << thefile;
		snprintf(thefile,1999,"extdrummc=%i\n",extdrummc);
		settingsfile << thefile;
		snprintf(thefile,1999,"basguitar1mc=%i\n",basguitar1mc);
		settingsfile << thefile;
		snprintf(thefile,1999,"advguitar1mc=%i\n",advguitar1mc);
		settingsfile << thefile;
		snprintf(thefile,1999,"extguitar1mc=%i\n",extguitar1mc);
		settingsfile << thefile;
		snprintf(thefile,1999,"basguitar2mc=%i\n",basguitar2mc);
		settingsfile << thefile;
		snprintf(thefile,1999,"advguitar2mc=%i\n",advguitar2mc);
		settingsfile << thefile;
		snprintf(thefile,1999,"extguitar2mc=%i\n",extguitar2mc);
		settingsfile << thefile;
		settingsfile.close();	
		#ifdef DEBUG
		printf("Extended data saved\n");
		#endif
	}
}

void song::loadextended(){
	#ifdef EXCESSIVE
	printf("song::loadextended\n");
	#endif
	ifstream settingsfile;
	char file[256];
	snprintf(file,255, "%sextended.dgb", location);
	while(fstreampotty>0){}
	fstreampotty++;
	settingsfile.open(file,ifstream::in);
	fstreampotty--;
	if (!settingsfile.fail()){
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
			if (strcmp(strlwr2(variable),"offset")==0)
				offset=atoi(varvalue);
			if (strcmp(strlwr2(variable),"basdrumhs")==0)
				basdrumhs=atoi(varvalue);
			if (strcmp(strlwr2(variable),"advdrumhs")==0)
				advdrumhs=atoi(varvalue);
			if (strcmp(strlwr2(variable),"extdrumhs")==0)
				extdrumhs=atoi(varvalue);
			if (strcmp(strlwr2(variable),"basguitar1hs")==0)
				basguitar1hs=atoi(varvalue);
			if (strcmp(strlwr2(variable),"advguitar1hs")==0)
				advguitar1hs=atoi(varvalue);
			if (strcmp(strlwr2(variable),"extguitar1hs")==0)
				extguitar1hs=atoi(varvalue);
			if (strcmp(strlwr2(variable),"basguitar2hs")==0)
				basguitar2hs=atoi(varvalue);
			if (strcmp(strlwr2(variable),"advguitar2hs")==0)
				advguitar2hs=atoi(varvalue);
			if (strcmp(strlwr2(variable),"extguitar2hs")==0)
				extguitar2hs=atoi(varvalue);	
			if (strcmp(strlwr2(variable),"basdrummc")==0)
				basdrummc=atoi(varvalue);
			if (strcmp(strlwr2(variable),"advdrummc")==0)
				advdrummc=atoi(varvalue);
			if (strcmp(strlwr2(variable),"extdrummc")==0)
				extdrummc=atoi(varvalue);
			if (strcmp(strlwr2(variable),"basguitar1mc")==0)
				basguitar1mc=atoi(varvalue);
			if (strcmp(strlwr2(variable),"advguitar1mc")==0)
				advguitar1mc=atoi(varvalue);
			if (strcmp(strlwr2(variable),"extguitar1mc")==0)
				extguitar1mc=atoi(varvalue);
			if (strcmp(strlwr2(variable),"basguitar2mc")==0)
				basguitar2mc=atoi(varvalue);
			if (strcmp(strlwr2(variable),"advguitar2mc")==0)
				advguitar2mc=atoi(varvalue);
			if (strcmp(strlwr2(variable),"extguitar2mc")==0)
				extguitar2mc=atoi(varvalue);	
		}
	}
	poffset=offset;
}

void song::resetplayed(){
	#ifdef EXCESSIVE
	printf("song::resetplayed\n");
	#endif
    snprintf(curravi,255, "NULL");
	if (songsloaded<1)return;
	if (thesong>0){
		for (int i=0;i<basnotes;i++){
			basnoteplayed[i]=false;
			g1basnoteplayed[i]=false;
			g2basnoteplayed[i]=false;
		}
		for (int i=0;i<advnotes;i++){
			advnoteplayed[i]=false;
			g1advnoteplayed[i]=false;
			g2advnoteplayed[i]=false;
		}
		for (int i=0;i<extnotes;i++){
			extnoteplayed[i]=false;
			g1extnoteplayed[i]=false;
			g2extnoteplayed[i]=false;
		}
	}
}


void song::load(char songlocation[512], char songname[512], char catname[256]){
	#ifdef EXCESSIVE
	printf("song::load\n");
	#endif
	snprintf(curravi,255,"NULL");
	if (strlen(songlocation)<1)return;
	if (strlen(songname)<1)return;
	if (strlen(catname)<1)return;
	snprintf(cat,255,"%s", catname);
	ifstream songfile;
	char buffer[10256];
	char file[768];
	snprintf(name,255,"%s", songname);
	snprintf(location,255,"%s", songlocation);
	bool basloaded=false;
	bool advloaded=false;
	bool extloaded=false;
	bool skipthisrun=false;
	for (int fn=1;fn<7;fn++){
		if (favordtx){
			if (fn==1){
				snprintf(file,765,"%sbas.dtx", location);
			}
			if (fn==2){
				snprintf(file,765,"%sadv.dtx", location);
			}
			if (fn==3){
				snprintf(file,765,"%sext.dtx", location);
			}
			if (fn==4){
				snprintf(file,765,"%sbas.gda", location);
			}
			if (fn==5){
				snprintf(file,765,"%sadv.gda", location);
			}
			if (fn==6){
				snprintf(file,765,"%sext.gda", location);
			}
		}else{
			if (fn==1){
				snprintf(file,765,"%sbas.gda", location);
			}
			if (fn==2){
				snprintf(file,765,"%sadv.gda", location);
			}
			if (fn==3){
				snprintf(file,765,"%sext.gda", location);
			}
			if (fn==4){
				snprintf(file,765,"%sbas.dtx", location);
			}
			if (fn==5){
				snprintf(file,765,"%sadv.dtx", location);
			}
			if (fn==6){
				snprintf(file,765,"%sext.dtx", location);
			}
		}
		while(fstreampotty>0){}
    	fstreampotty++;
		songfile.open(file,ifstream::in);
		fstreampotty--;
		if (songfile.good()){
			if (fn==1){
				basloaded=true;
				if (favordtx)
					basgda=false;
				else
					basgda=true;
			}
			if (fn==2){
				advloaded=true;
				if (favordtx)
					advgda=false;
				else
					advgda=true;
			}
			if (fn==3){
				extloaded=true;
				if (favordtx)
					extgda=false;
				else
					extgda=true;
			}
		}
		if (fn==4&&basloaded){
			skipthisrun=true;
		}else if (fn==4&&!basloaded){
			if (favordtx)
				basgda=true;
			else
				basgda=false;
		}
		if (fn==5&&advloaded){
			skipthisrun=true;
		}else if (fn==5&&!advloaded){
			if (favordtx)
				advgda=true;
			else
				advgda=false;
		}
		if (fn==6&&extloaded){
			skipthisrun=true;
		}else if (fn==6&&!extloaded){
			if (favordtx)
				extgda=true;
			else
				extgda=false;
		}
		while(songfile.good()&&!skipthisrun){
			char command[256];
			char value[10000];
			int n=0;
			bool getcommand=true;
			bool spaceokay=false;
			int x=0;
			songfile.getline(buffer,10255);
			if (buffer[strlen(buffer)-1]=='\r'){
				buffer[strlen(buffer)-1]='\0';
			}
			snprintf(command,255,"");
			snprintf(value,9999,"");
			spaceokay=false;
			while ( strlen(buffer) > n ){
				if (getcommand){
					command[n]=buffer[n];
				}
				if (!getcommand){
					if (buffer[n]==' '){
						if (spaceokay){
							value[x]=buffer[n];
							x++;
						}
					}else{
						value[x]=buffer[n];
						spaceokay=true;
						x++;
					}
				}
				if (buffer[n]==' '||buffer[n]==':'){
					if (getcommand){
						getcommand=false;
						command[n]='\0';
					}
				}
				n++;
			}
			value[x]='\0';
			if (strcmp(strlwr2(command),"#artist")==0){
				snprintf(artist,255,"%s", value);
			}
			if (strcmp(strlwr2(command),"#title")==0){
				snprintf(title,255,"%s", value);
			}
			if (strcmp(strlwr2(command),"#bpm")==0){
				origbpm=atoi(value);
				bpm=atoi(value);
				basavgbpm=atoi(value);
				advavgbpm=atoi(value);
				extavgbpm=atoi(value);
				
			}
			if (strcmp(strlwr2(command),"#basebpm")==0){
				basebpm=atoi(value);
			}
			if (strcmp(strlwr2(command),"#dlevel")==0){
				if (fn==1||fn==4){
					if (atoi(value)!=0)drumbasdiff=atoi(value);
				}
				if(fn==2||fn==5){
					if (atoi(value)!=0)drumadvdiff=atoi(value);
				}
				if(fn==3||fn==6){
					if (atoi(value)!=0)drumextdiff=atoi(value);
				}
			}
			if (strcmp(strlwr2(command),"#glevel")==0){
				if (fn==1||fn==4){
					if (atoi(value)!=0)guitbasdiff=atoi(value);
				}else if(fn==2||fn==5){
					if (atoi(value)!=0)guitadvdiff=atoi(value);
				}else if(fn==3||fn==6){
					if (atoi(value)!=0)guitextdiff=atoi(value);
				}
			}
			if (strcmp(strlwr2(command),"#blevel")==0){
				if (fn==1||fn==4){
					if (atoi(value)!=0)guitbbasdiff=atoi(value);
				}else if(fn==2||fn==5){
					if (atoi(value)!=0)guitbadvdiff=atoi(value);
				}else if(fn==3||fn==6){
					if (atoi(value)!=0)guitbextdiff=atoi(value);
				}
			}
			if (strcmp(strlwr2(command),"#preview")==0){
				snprintf(previewwave,255,"%s", value);
			}
			if (strcmp(strlwr2(command),"#wall")==0){
				snprintf(background,255,"%s", value);
			}
			if (strcmp(strlwr2(command),"#preimage")==0){
				snprintf(previewimg,255,"%s", value);
			}
			if (strcmp(strlwr2(command),"#genre")==0){
				snprintf(genre,255,"%s", value);
			}
			bool wave=false;
			char temp[256];
			charlim(command,4,temp);
			if (strcmp(strlwr2(temp),"#wav")==0){
				if (fn==1||fn==4){
					bassounds++;
				}else if(fn==2||fn==5){
					advsounds++;
				}else if(fn==3||fn==6){
					extsounds++;
				}
			}
			if (strcmp(strlwr2(temp),"#avi")==0){
				if (fn==1||fn==4){
					basavis++;
				}else if(fn==2||fn==5){
					advavis++;
				}else if(fn==3||fn==6){
					extavis++;
				}
			}
			char temp2[256];
			charlim(command,4,temp2);
			deadspace(temp2,1,temp);
			if (dbstoi(temp)>-1&&strlen(command)>0){
				char temp3[3];
				snprintf(temp3,2, "%c%c", command[4],command[5]);
				if (strcmp(temp3,"g0")==0||strcmp(temp3,"g0")==0){
					hasopenpick=true;	
				}
				if (strcmp(temp3,"g0")==0||strcmp(temp3,"g1")==0||strcmp(temp3,"g2")==0||strcmp(temp3,"g3")==0||strcmp(temp3,"g4")==0||strcmp(temp3,"g5")==0||strcmp(temp3,"g6")==0||strcmp(temp3,"g7")==0||strcmp(temp3,"gw")==0
					||strcmp(temp3,"20")==0||strcmp(temp3,"21")==0||strcmp(temp3,"22")==0||strcmp(temp3,"23")==0||strcmp(temp3,"24")==0||strcmp(temp3,"25")==0||strcmp(temp3,"26")==0||strcmp(temp3,"27")==0||strcmp(temp3,"28")==0){
					if (fn==1||fn==4){
						if (guitbasdiff==0)guitbasdiff=101;
					}else if (fn==2||fn==5){
						if (guitadvdiff==0)guitadvdiff=101;
					}else if (fn==3||fn==6){
						if (guitextdiff==0)guitextdiff=101;
					}
				}
				if (strcmp(temp3,"11")==0||strcmp(temp3,"12")==0||strcmp(temp3,"13")==0||strcmp(temp3,"14")==0||strcmp(temp3,"15")==0||strcmp(temp3,"16")==0||strcmp(temp3,"17")==0||strcmp(temp3,"18")==0||strcmp(temp3,"19")==0
					||strcmp(temp3,"hh")==0||strcmp(temp3,"sd")==0||strcmp(temp3,"bd")==0||strcmp(temp3,"ht")==0||strcmp(temp3,"lt")==0||strcmp(temp3,"cy")==0||strcmp(temp3,"ft")==0||strcmp(temp3,"ho")==0||strcmp(temp3,"rc")==0){
					if (fn==1||fn==4){
						if (drumbasdiff==0)drumbasdiff=101;
					}else if (fn==2||fn==5){
						if (drumadvdiff==0)drumadvdiff=101;
					}else if (fn==3||fn==6){
						if (drumextdiff==0)drumextdiff=101;
					}
				}
				if (strcmp(temp3,"a0")==0||strcmp(temp3,"a1")==0||strcmp(temp3,"a2")==0||strcmp(temp3,"a3")==0||strcmp(temp3,"a4")==0||strcmp(temp3,"a5")==0||strcmp(temp3,"a6")==0||strcmp(temp3,"a7")==0||strcmp(temp3,"a8")==0
					||strcmp(temp3,"b0")==0||strcmp(temp3,"b1")==0||strcmp(temp3,"b2")==0||strcmp(temp3,"b3")==0||strcmp(temp3,"b4")==0||strcmp(temp3,"b5")==0||strcmp(temp3,"b6")==0||strcmp(temp3,"b7")==0||strcmp(temp3,"bw")==0){
					if (fn==1||fn==4){
						if (guitbbasdiff==0)guitbbasdiff=101;
					}else if (fn==2||fn==5){
						if (guitbadvdiff==0)guitbadvdiff=101;
					}else if (fn==3||fn==6){
						if (guitbextdiff==0)guitbextdiff=101;
					}
				}
				for (int m=0;m<strlen(value);m+=2){
					if (m+1<strlen(value)){
						char temp3[3];
						temp3[0]=value[m];
						temp3[1]=value[m+1];
						temp3[2]='\0';
						if (strcmp(temp3,"00")!=0){
							if (fn==1||fn==4){
								basnotes++;
							}else if (fn==2||fn==5){
								advnotes++;
							}else if (fn==3||fn==6){
								extnotes++;
							}
						}
					}
				}
				if (fn==1||fn==4){
					char marmot[10];
					char marmot2[10];
					charlim(command,4,marmot2);
					deadspace(marmot2,1,marmot2);
					if (atoi(marmot2)>highestmeasure)highestmeasure=atoi(marmot2);
					
					charlim(command,6,marmot);
					deadspace(marmot,4,marmot);
					if (strcmp(strlwr2(marmot),"02")==0||strcmp(strlwr2(marmot),"bl")==0){
                        if (strcmp(strlwr2(marmot),"02")==0&&basgda){
                        }else{
    						if (atof(value)>=0){
    							basavgbpm=int((double(bpm)+(double(bpm)*dbstod(value)))/2.0);
    							basnotes++;
    						}
                        }
					}
				}
				if (fn==2||fn==5){
					char marmot[10];
					char marmot2[10];
					charlim(command,4,marmot2);
					deadspace(marmot2,1,marmot2);
					if (atoi(marmot2)>highestmeasure)highestmeasure=atoi(marmot2);
					charlim(command,6,marmot);
					deadspace(marmot,4,marmot);
					if (strcmp(strlwr2(marmot),"02")==0||strcmp(strlwr2(marmot),"bl")==0){
                        if (strcmp(strlwr2(marmot),"02")==0&&advgda){
                        }else{
    						if (atof(value)>=0){
    							advavgbpm=int((double(bpm)+(double(bpm)*dbstod(value)))/2.0);
    							advnotes++;
    						}
                        }
					}
				}
				if (fn==3||fn==6){
					char marmot[10];
					char marmot2[10];
					charlim(command,4,marmot2);
					deadspace(marmot2,1,marmot2);
					if (atoi(marmot2)>highestmeasure)highestmeasure=atoi(marmot2);
					charlim(command,6,marmot);
					deadspace(marmot,4,marmot);
					if (strcmp(strlwr2(marmot),"02")==0||strcmp(strlwr2(marmot),"bl")==0){
                        if (strcmp(strlwr2(marmot),"02")==0&&extgda){
                        }else{
    						if (atof(value)>=0){
    							extavgbpm=int((double(bpm)+(double(bpm)*dbstod(value)))/2.0);
    							extnotes++;
    						}
                        }
					}
				}
			}	
		}
		bpm=origbpm;
		if (basebpm>0){
            bpmdiff=double(origbpm)/double(basebpm);
		}else{
			bpmdiff=1.0;
			basebpm=bpm;
		}
		if (bpm!=basavgbpm)
			avgbpm=basavgbpm;
		else if (bpm!=advavgbpm)
			avgbpm=advavgbpm;
		else if (bpm!=extavgbpm)
			avgbpm=extavgbpm;
		else
			avgbpm=bpm;
		if (double(highestmeasure)/double(bpm)>.9)
			islong=true;
		songfile.close();
		songfile.clear();
	}
	lowestdrumdiff=drumbasdiff;
	if (lowestdrumdiff<1)lowestdrumdiff=drumadvdiff;
	if (lowestdrumdiff<1)lowestdrumdiff=drumextdiff;
	lowestguitdiff=guitbasdiff;
	if (lowestguitdiff<1)lowestguitdiff=guitadvdiff;
	if (lowestguitdiff<1)lowestguitdiff=guitextdiff;
	//artistt.fastestload(artist,"unicode.ttf",255,255,255,30);
	//titlet.fastestload(title,"unicode.ttf",255,255,255,30);
	if (strlen(title)<2){
		if (strlen(name)>2)snprintf(title,255, name);
	}
	if (strlen(artist)>2){
        //artistt.load(artist,"unicode.ttf",255,255,255,30);
		//artistt.cache(location,artist,"unicode.ttf",255,255,255,30);
		//artistt.loadcache();
	}
	if (strlen(title)>2){
        //titlet.load(title,"unicode.ttf",255,255,255,30);
		//titlet.cache(location,title,"unicode.ttf",255,255,255,30);
		//titlet.loadcache();
	}
}



//load steps
void song::loadsteps(){
	#ifdef EXCESSIVE
	printf("song::loadsteps\n");
	#endif
    snprintf(curravi,255, "NULL");
	if (songsloaded>0){
		#ifdef DEBUG
			printf("You cannot load more than 1 song at a time Joe...\n");
		#else
			SDL_Delay(1);
		#endif
		return;
	}
	#ifdef SONGLOADDEBUG
	printf("pos 1\n");
	#endif
	songsloaded++;
	char file[256];
	char buffer[10256];
	int bassoundline=0;
	int advsoundline=0;
	int extsoundline=0;
	int basaviline=0;
	int advaviline=0;
	int extaviline=0;
	int basnoteline=0;
	int advnoteline=0;
	int extnoteline=0;
	ifstream songfile;
	#ifdef SONGLOADDEBUG
	printf("pos 2\n");
	#endif
	bassoundfilenum=(char **)malloc(sizeof(char *) * bassounds);
	bassoundfileloc=(char **)malloc(sizeof(char *) * bassounds);
	advsoundfilenum=(char **)malloc(sizeof(char *) * advsounds);
	advsoundfileloc=(char **)malloc(sizeof(char *) * advsounds);
	extsoundfilenum=(char **)malloc(sizeof(char *) * extsounds);
	extsoundfileloc=(char **)malloc(sizeof(char *) * extsounds);
	for (int i=0;i<bassounds;i++){
		bassoundfilenum[i]=(char *)malloc(sizeof(char)*100);
		bassoundfileloc[i]=(char *)malloc(sizeof(char)*100);
		bassoundfilenum[i][99]='\0';
		bassoundfileloc[i][99]='\0';
	}
	for (int i=0;i<advsounds;i++){
		advsoundfilenum[i]=(char *)malloc(sizeof(char)*100);
		advsoundfileloc[i]=(char *)malloc(sizeof(char)*100);
		advsoundfilenum[i][99]='\0';
		advsoundfileloc[i][99]='\0';
	}
	for (int i=0;i<extsounds;i++){
		extsoundfilenum[i]=(char *)malloc(sizeof(char)*100);
		extsoundfileloc[i]=(char *)malloc(sizeof(char)*100);
		extsoundfilenum[i][99]='\0';
		extsoundfileloc[i][99]='\0';
	}
	//set avi
	basavinum=(char **)malloc(sizeof(char *) * basavis);
	basaviloc=(char **)malloc(sizeof(char *) * basavis);
	advavinum=(char **)malloc(sizeof(char *) * advavis);
	advaviloc=(char **)malloc(sizeof(char *) * advavis);
	extavinum=(char **)malloc(sizeof(char *) * extavis);
	extaviloc=(char **)malloc(sizeof(char *) * extavis);
	for (int i=0;i<basavis;i++){
		basavinum[i]=(char *)malloc(sizeof(char)*100);
		basaviloc[i]=(char *)malloc(sizeof(char)*100);
		basavinum[i][99]='\0';
		basaviloc[i][99]='\0';
	}
	for (int i=0;i<advavis;i++){
		advavinum[i]=(char *)malloc(sizeof(char)*100);
		advaviloc[i]=(char *)malloc(sizeof(char)*100);
		advavinum[i][99]='\0';
		advaviloc[i][99]='\0';
	}
	for (int i=0;i<extavis;i++){
		extavinum[i]=(char *)malloc(sizeof(char)*100);
		extaviloc[i]=(char *)malloc(sizeof(char)*100);
		extavinum[i][99]='\0';
		extaviloc[i][99]='\0';
	}
	#ifdef SONGLOADDEBUG
	printf("pos 3\n");
	#endif
	//set steps
	basnotemeas=(int *)malloc(sizeof(int)*basnotes);
	basnotetime=(int *)malloc(sizeof(int)*basnotes);//  3/8 (*10000)
	basnotetype=(char **)malloc(sizeof(char *) * basnotes);
	basnotetype2=(char **)malloc(sizeof(char *) * basnotes);
	basnotesound=(char **)malloc(sizeof(char*) * basnotes);
	for (int i=0;i<basnotes;i++){
		basnotetype[i]=(char *)malloc(sizeof(char)*100);
		basnotetype2[i]=(char *)malloc(sizeof(char)*100);
		basnotesound[i]=(char *)malloc(sizeof(char)*100);
		basnotetype[i][99]='\0';
		basnotetype2[i][99]='\0';
		basnotesound[i][99]='\0';
	}
	advnotemeas=(int*)malloc(sizeof(int)*advnotes);
	advnotetime=(int*)malloc(sizeof(int)*advnotes);
	advnotetype=(char **)malloc(sizeof(char *) * advnotes);
	advnotetype2=(char **)malloc(sizeof(char *) * advnotes);
	advnotesound=(char **)malloc(sizeof(char *) * advnotes);
	for (int i=0;i<advnotes;i++){
		advnotetype[i]=(char *)malloc(sizeof(char)*100);
		advnotetype2[i]=(char *)malloc(sizeof(char)*100);
		advnotesound[i]=(char *)malloc(sizeof(char)*100);
		advnotetype[i][99]='\0';
		advnotetype2[i][99]='\0';
		advnotesound[i][99]='\0';
	}
	extnotemeas=(int*)malloc(sizeof(int)*extnotes);
	extnotetime=(int*)malloc(sizeof(int)*extnotes);
	extnotetype=(char **)malloc(sizeof(char *) * extnotes);
	extnotetype2=(char **)malloc(sizeof(char *) * extnotes);
	extnotesound=(char **)malloc(sizeof(char *) * extnotes);
	for (int i=0;i<extnotes;i++){
		extnotetype[i]=(char *)malloc(sizeof(char)*100);
		extnotetype2[i]=(char *)malloc(sizeof(char)*100);
		extnotesound[i]=(char *)malloc(sizeof(char)*100);
		extnotetype[i][99]='\0';
		extnotetype2[i][99]='\0';
		extnotesound[i][99]='\0';
	}
	basnoteplayed=(bool*)malloc(sizeof(bool)*basnotes);
	advnoteplayed=(bool*)malloc(sizeof(bool)*advnotes);
	extnoteplayed=(bool*)malloc(sizeof(bool)*extnotes);
	g1basnoteplayed=(bool*)malloc(sizeof(bool)*basnotes);
	g1advnoteplayed=(bool*)malloc(sizeof(bool)*advnotes);
	g1extnoteplayed=(bool*)malloc(sizeof(bool)*extnotes);
	g2basnoteplayed=(bool*)malloc(sizeof(bool)*basnotes);
	g2advnoteplayed=(bool*)malloc(sizeof(bool)*advnotes);
	g2extnoteplayed=(bool*)malloc(sizeof(bool)*extnotes);
	for (int i=0;i<basnotes;i++){
		basnoteplayed[i]=false;
		g1basnoteplayed[i]=false;
		g2basnoteplayed[i]=false;
	}
	for (int i=0;i<advnotes;i++){
		advnoteplayed[i]=false;
		g1advnoteplayed[i]=false;
		g2advnoteplayed[i]=false;
	}
	for (int i=0;i<extnotes;i++){
		extnoteplayed[i]=false;
		g1extnoteplayed[i]=false;
		g2extnoteplayed[i]=false;
	}
	#ifdef SONGLOADDEBUG
	printf("pos 4\n");
	#endif
	//load stuff:
	bool basloaded=false;
	bool advloaded=false;
	bool extloaded=false;
	basclms=(double*)malloc(sizeof(double)*basnotes);
	advclms=(double*)malloc(sizeof(double)*advnotes);
	extclms=(double*)malloc(sizeof(double)*extnotes);
	for (int i=0;i<basnotes;i++){
		basclms[i]=0.0;
	}
	for (int i=0;i<advnotes;i++){
		advclms[i]=0.0;
	}
	for (int i=0;i<extnotes;i++){
		extclms[i]=0.0;
	}
	for (int fn=1;fn<7;fn++){
        #ifdef SONGLOADDEBUG
		printf("pos 5\n");
		#endif
		bool skipthisrun=false;
		if (favordtx){
			if (fn==1)
				snprintf(file,255, "%sbas.dtx", location);
			if (fn==2)
				snprintf(file,255, "%sadv.dtx", location);
			if (fn==3)
				snprintf(file,255, "%sext.dtx", location);
			if (fn==4)
				snprintf(file,255, "%sbas.gda", location);
			if (fn==5)
				snprintf(file,255, "%sadv.gda", location);
			if (fn==6)
				snprintf(file,255, "%sext.gda", location);
		}else{
			if (fn==1)
				snprintf(file,255, "%sbas.gda", location);
			if (fn==2)
				snprintf(file,255, "%sadv.gda", location);
			if (fn==3)
				snprintf(file,255, "%sext.gda", location);
			if (fn==4)
				snprintf(file,255, "%sbas.dtx", location);
			if (fn==5)
				snprintf(file,255, "%sadv.dtx", location);
			if (fn==6)
				snprintf(file,255, "%sext.dtx", location);
		}
		#ifdef SONGLOADDEBUG
		printf("pos 6 %s\n",file);
		#endif
		songfile.close();
		songfile.clear();
		while(fstreampotty>0){}
		fstreampotty++;
		songfile.open(file,ifstream::in);
		fstreampotty--;
		if (songfile.good()){
			if (fn==1)
				basloaded=true;
			if (fn==2)
				advloaded=true;
			if (fn==3)
				extloaded=true;
		}
		if (fn==4&&basloaded){
			skipthisrun=true;
		}
		if (fn==5&&advloaded){
			skipthisrun=true;
		}
		if (fn==6&&extloaded){
			skipthisrun=true;
		}
		#ifdef SONGLOADDEBUG
		printf("pos 7\n");
		#endif
		while(songfile.good() && !skipthisrun){
			char command[256];
			char value[10000];
			int n=0;
			int n2=0;
			bool getcommand=true;
			bool isnote=false;
			bool spaceokay=false;
			int x=0;
			songfile.getline(buffer,10255);
			if (buffer[strlen(buffer)-1]=='\r'){
				buffer[strlen(buffer)-1]='\0';
			}
			snprintf(command,255," ");
			snprintf(value,9999," ");
			#ifdef SONGLOADDEBUG
			printf("pos 8 %s\n",buffer);
			#endif
			while ( n<strlen(buffer)){
				if (getcommand){
					if(n<256)command[n]=buffer[n];
				}
				if (buffer[n]==' '||buffer[n]==':'){
					getcommand=false;
					if(n<256)command[n]='\0';
					else command[255]='\0';
					if(!spaceokay){
                        n++;
                    	n2=0;
						continue;
					}
				}
				if(!getcommand){
					if (n2<10000)value[n2]=buffer[n];
				}
				n++;
				n2++;
				if (!getcommand)spaceokay=true;
				if (getcommand)x++;
			}
			if (n2<10000)value[n2]='\0';
			bool wave=false;
			char temp[256];
			charlim(command,4,temp);
			#ifdef SONGLOADDEBUG
			printf("pos 9 (%s) %s:%s\n",temp,command,value);
			#endif
			if (strcmp(strlwr2(temp),"#wav")==0){
				if (fn==1||fn==4){
					if (bassoundline<bassounds){
						char marmot[10];
						deadspace(command,4,marmot);
						snprintf(bassoundfilenum[bassoundline],99,"%s", strlwr2(marmot));
						snprintf(bassoundfileloc[bassoundline],99,"%s", value);
						bassoundline++;
					}
				}else if(fn==2||fn==5){
					if (advsoundline<advsounds){
						char marmot[10];
						deadspace(command,4,marmot);
						snprintf(advsoundfilenum[advsoundline],99,"%s", strlwr2(marmot));
						snprintf(advsoundfileloc[advsoundline],99,"%s", value);
						advsoundline++;
					}
				}else if(fn==3||fn==6){
					if (extsoundline<extsounds){
						char marmot[10];
						deadspace(command,4,marmot);
						snprintf(extsoundfilenum[extsoundline],99,"%s", strlwr2(marmot));
						snprintf(extsoundfileloc[extsoundline],99,"%s", value);
						extsoundline++;
					}
				}
			}
			if (strcmp(strlwr2(temp),"#avi")==0){
				if (fn==1||fn==4){
					if (basaviline<basavis){
						char marmot[10];
						deadspace(command	,4,marmot);
						snprintf(basavinum[basaviline],99,"%s", strlwr2(marmot));
						snprintf(basaviloc[basaviline],99,"%s", value);
						basaviline++;
					}
				}else if(fn==2||fn==5){
					if (advaviline<advavis){
						char marmot[10];
						deadspace(command,4,marmot);
						snprintf(advavinum[advaviline],99,"%s", strlwr2(marmot));
						snprintf(advaviloc[advaviline],99,"%s", value);
						advaviline++;
					}
				}else if(fn==3||fn==6){
					if (extaviline<extavis){
						char marmot[10];
						deadspace(command,4,marmot);
						snprintf(extavinum[extaviline],99,"%s", strlwr2(marmot));
						snprintf(extaviloc[extaviline],99,"%s", value);
						extaviline++;
					}
				}
			}
			char temp2[256];
			charlim(command,4,temp2);
			deadspace(temp2,1,temp);
			#ifdef SONGLOADDEBUG
			printf("pos 10 %s\n",command);
			#endif
			if (dbstoi(temp)>-1&&strlen(command)>0){
				for (int m=0;m<strlen(value);m+=2){
					if (m+1<strlen(value)){
						char temp3[3];
						temp3[0]=value[m];
						temp3[1]=value[m+1];
						temp3[2]='\0';
						if (strcmp(temp3,"00")!=0){
							if (fn==1||fn==4){
								if (basnoteline<basnotes){
									basnotemeas[basnoteline]=dbstoi(temp);
									basnotetime[basnoteline]=int( (double(m)/double(strlen(value)))*10000.0);
									char marmot[10];
									snprintf(marmot,9,"%s", temp3);
									snprintf(this->basnotesound[basnoteline],99,"%s", strlwr2(marmot));
									charlim(command,6,marmot);
									deadspace(marmot,4,marmot);
									snprintf(this->basnotetype[basnoteline],99,"%s", strlwr2(marmot));
									snprintf(this->basnotetype2[basnoteline],99,"%s", strlwr2(marmot));
									basnoteline++;
								}
							}else if (fn==2||fn==5){
								if (advnoteline<advnotes){
									advnotemeas[advnoteline]=dbstoi(temp);
									advnotetime[advnoteline]=int( (double(m)/double(strlen(value))) *10000.0);
									char marmot[10];
									snprintf(marmot,9,"%s", temp3);
									snprintf(advnotesound[advnoteline],99,"%s", strlwr2(marmot));
									charlim(command,6,marmot);
									deadspace(marmot,4,marmot);
									snprintf(advnotetype[advnoteline],99,"%s", strlwr2(marmot));
									snprintf(advnotetype2[advnoteline],99,"%s", strlwr2(marmot));
									advnoteline++;
								}
							}else if (fn==3||fn==6){
								if (extnoteline<extnotes){
									extnotemeas[extnoteline]=dbstoi(temp);
									extnotetime[extnoteline]=int( (double(m)/double(strlen(value))) *10000.0);
									char marmot[10];
									snprintf(marmot,9,"%s", temp3);
									snprintf(extnotesound[extnoteline],99,"%s", strlwr2(marmot));
									charlim(command,6,marmot);
									deadspace(marmot,4,marmot);
									snprintf(extnotetype[extnoteline],99,"%s", strlwr2(marmot));
									snprintf(extnotetype2[extnoteline],99,"%s", strlwr2(marmot));
									extnoteline++;
								}
							}
						}
					}
				}
				#ifdef SONGLOADDEBUG
				printf("pos 11\n");
				#endif
				if (fn==1||fn==4){
					char marmot[10];
					charlim(command,6,marmot);
					deadspace(marmot,4,marmot);
					if (strcmp(strlwr2(marmot),"02")==0||strcmp(strlwr2(marmot),"bl")==0){
						if (strcmp(strlwr2(marmot),"02")==0&&basgda){
						}else{
							if (atof(value)>=0){
								basnotemeas[basnoteline]=dbstoi(temp);
								basnotetime[basnoteline]=0;
								snprintf(basnotetype[basnoteline],99,"%s", marmot);
								snprintf(basnotetype2[basnoteline],99,"%s", marmot);
								snprintf(basnotesound[basnoteline],99,"%s", marmot);
								basclms[basnoteline]=atof(value);
								basnoteline++;
							}
						}
					}
				}else if(fn==2||fn==5){
					char marmot[10];
					charlim(command,6,marmot);
					deadspace(marmot,4,marmot);
					if (strcmp(strlwr2(marmot),"02")==0||strcmp(strlwr2(marmot),"bl")==0){
						if (strcmp(strlwr2(marmot),"02")==0&&advgda){
						}else{
							if (atof(value)>=0){
								advnotemeas[advnoteline]=dbstoi(temp);
								advnotetime[advnoteline]=0;
								snprintf(advnotetype[advnoteline],99,"%s", marmot);
								snprintf(advnotetype2[advnoteline],99,"%s", marmot);
								snprintf(advnotesound[advnoteline],99,"%s", marmot);
								advclms[advnoteline]=atof(value);
								advnoteline++;
							}
						}
					}
				}else if(fn==3||fn==6){
					char marmot[10];
					charlim(command,6,marmot);
					deadspace(marmot,4,marmot);
					if (strcmp(strlwr2(marmot),"02")==0||strcmp(strlwr2(marmot),"bl")==0){
						if (strcmp(strlwr2(marmot),"02")==0&&extgda){
						}else{
							if (atof(value)>=0){
								extnotemeas[extnoteline]=dbstoi(temp);
								extnotetime[extnoteline]=0;
								snprintf(extnotetype[extnoteline],99,"%s", marmot);
								snprintf(extnotetype2[extnoteline],99,"%s", marmot);
								snprintf(extnotesound[extnoteline],99,"%s", marmot);
								extclms[extnoteline]=atof(value);
								extnoteline++;
							}
						}
					}
				}
				#ifdef SONGLOADDEBUG
				printf("pos 11.5\n");
				#endif
			}
		}
	}
	#ifdef SONGLOADDEBUG
	printf("pos 12\n");
	#endif
	loadextended();
	randomize();
}

void song::reloadsong(){
	#ifdef EXCESSIVE
	printf("song::reloadsong\n");
	#endif
	snprintf(curravi,255, "NULL");
	lasthihat=0;
	lastsnare=0;
	lastbass=0;
	lasthitom=0;
	lastlotom=0;
	lastcymbal=0;
	if (presong>-1&&presong<gbsongcount){
		if(songsloaded>0)unloadwaves();
		songs[presong].unloadsteps();
	}
	if (thesong>-1&&thesong<gbsongcount){
		if (currscreen==5){
			if (jukeboxmode){
				songs[thesong].loadsteps();
			}
		}else{
            songs[thesong].loadsteps();
		}
		songs[thesong].loadextended();
        if (songsloaded>0)songs[thesong].resetplayed();
		newsong=true;
		if (songsloaded>0){
			loadwaves();
		}
		currbpm=songs[thesong].basebpm;
		if (currbpm==0)
			currbpm=150;
	}
	songposition=-240000;
	presong=thesong;
	loadthepreview();//image not audio.
	playpreview(true);//audio.
	songs[thesong].resetplayed();
}

void song::unloadsteps(){
	#ifdef EXCESSIVE
	printf("song::unloadsteps\n");
	#endif
	snprintf(curravi,255, "NULL");
	if (songsloaded<1){
		#ifdef DEBUG
		printf("what song are you trying to unload...\n");
		#else
			SDL_Delay(1);
		#endif
		return;
	}
	songsloaded--;
	int a=0;
	for (int i=0;i<bassounds;i++){
		free(bassoundfilenum[i]);
		free(bassoundfileloc[i]);
	}
	for (int i=0;i<advsounds;i++){
		free(advsoundfilenum[i]);
		free(advsoundfileloc[i]);
	}
	for (int i=0;i<extsounds;i++){
		free(extsoundfilenum[i]);
		free(extsoundfileloc[i]);
	}
	free(bassoundfilenum);//0E
	free(bassoundfileloc);//snare_2.xa
	free(advsoundfilenum);//0E
	free(advsoundfileloc);//snare_2.xa
	free(extsoundfilenum);//0E
	free(extsoundfileloc);//snare_2.xa
	//avi bg.avi
	for (int i=0;i<basavis;i++){
		free(basavinum[i]);
		free(basaviloc[i]);
	}
	for (int i=0;i<advavis;i++){
		free(advavinum[i]);
		free(advaviloc[i]);
	}
	for (int i=0;i<extavis;i++){
		free(extavinum[i]);
		free(extaviloc[i]);
	}
	free(basavinum);//03
	free(basaviloc);//bg.avi
	free(advavinum);//03
	free(advaviloc);//bg.avi
	free(extavinum);//03
	free(extaviloc);//bg.avi
	//#011BD: 0200020002020202
	free(basnotemeas);//011
	free(basnotetime);//(1/8)..(3/8)..etc.
	if (basnotetype!=NULL){
		for (int i=0;i<basnotes;i++){
			free(basnotetype[i]);
			free(basnotetype2[i]);
			free(basnotesound[i]);
		}
	}
	free(basnotetype);//BD
	free(basnotetype2);//BD
	free(basnotesound);//02
	free(advnotemeas);//011
	free(advnotetime);//(1/8)..(3/8)..etc.
	if (advnotetype!=NULL){
		for (int i=0;i<advnotes;i++){
			free(advnotetype[i]);
			free(advnotetype2[i]);
			free(advnotesound[i]);
		}
	}
	free(advnotetype);//BD
	free(advnotetype2);//BD
	free(advnotesound);//02
	free(extnotemeas);//011
	free(extnotetime);//(1/8)..(3/8)..etc.
	if (extnotetype!=NULL){
		for (int i=0;i<extnotes;i++){
			free(extnotetype[i]);
			free(extnotetype2[i]);
			free(extnotesound[i]);
		}
	}
	free(extnotetype);//BD
	free(extnotetype2);//BD
	free(extnotesound);//02
	free(basnoteplayed);
	free(advnoteplayed);
	free(extnoteplayed);
	free(g1basnoteplayed);
	free(g1advnoteplayed);
	free(g1extnoteplayed);
	free(g2basnoteplayed);
	free(g2advnoteplayed);
	free(g2extnoteplayed);
	currclm=1.0;
	free(basclms);
	free(advclms);
	free(extclms);
	offset=0;
}

void song::reload(){
	#ifdef EXCESSIVE
	printf("song::reload\n");
	#endif
	snprintf(curravi,255,"NULL");
	char savloc[256];
	char savname[256];
	char savcat[256];
	//don't change these from sprintf to snprintf, there is no need.
	sprintf(savloc, location);
	sprintf(savname, name);
	sprintf(savcat, cat);
	//don't change these from sprintf to snprintf, there is no need.
	init();		// this nukes the contents of the original vars
	load(savloc,savname,savcat);
	loadextended();
}

bool song::loadthepreview(){
	#ifdef EXCESSIVE
	printf("song::loadthepreview\n");
	#endif
	snprintf(curravi,255, "NULL");
	//code for alternate song list.
	char previewfile[256];
	char backgroundfile[256];
	if (previewtexture!=0){
		glDeleteTextures(1,&previewtexture);
		previewtexture=0;
	}
	if (backgroundtexture!=0){
		glDeleteTextures(1,&backgroundtexture);
		backgroundtexture=0;
	}
	if (thesong>-1&&thesong<gbsongcount){
		snprintf(backgroundfile,255,"./Songs/%s/%s/%s", songs[thesong].cat,songs[thesong].name,songs[thesong].background);
		snprintf(previewfile,255,"./Songs/%s/%s/%s", songs[thesong].cat,songs[thesong].name,songs[thesong].previewimg);
		backgroundtexture=loadtexture(backgroundfile);
		if (backgroundtexture==0){
			snprintf(backgroundfile,255, "./Songs/%s/%s/image.bmp", songs[thesong].cat,songs[thesong].name);
			backgroundtexture=loadtexture(backgroundfile);
		}
		if (backgroundtexture==0){
			snprintf(backgroundfile,255, "./Songs/%s/%s/wall.jpg", songs[thesong].cat,songs[thesong].name);
			backgroundtexture=loadtexture(backgroundfile);
		}
	}
	if (backgroundtexture==0){
		snprintf(backgroundfile,255, "./Themes/%s/wall.png", theme);
		if (!testfile(backgroundfile)){
			snprintf(backgroundfile,255, "./Themes/Default/wall.png");
			if (!testfile(backgroundfile)){
				printf("Could not find any wall files.. Do you have a default theme (%s)?\n",theme);
				printf("%s\n",songs[thesong].name);
				appisrunning=false;
			}
		}
		backgroundtexture=loadtexture(backgroundfile);
	}
	previewtexture=loadtexture(previewfile);
	if (thesong>-1&&thesong<gbsongcount){
		if (previewtexture==0){
			snprintf(previewfile,255, "./Songs/%s/%s/q.png", songs[thesong].cat,songs[thesong].name);
			previewtexture=loadtexture(previewfile);
		}
		if (previewtexture==0){
			snprintf(previewfile,255, "./Songs/%s/%s/q.jpg", songs[thesong].cat,songs[thesong].name);
			previewtexture=loadtexture(previewfile);
		}
		if (previewtexture==0){
			snprintf(previewfile,255, "./Songs/%s/%s/pre.jpg", songs[thesong].cat,songs[thesong].name);
			previewtexture=loadtexture(previewfile);
		}
	}
	if (previewtexture==0){
		snprintf(previewfile,255, "./Themes/%s/q.png", theme);
		if (!testfile(previewfile)){
			snprintf(previewfile,255, "./Themes/Default/q.png");
			printf("error: can't find default theme file q.png\n");
			appisrunning=false;
		}
		previewtexture=loadtexture(previewfile);
	}
	return true;
}
