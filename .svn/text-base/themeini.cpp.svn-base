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
themeini::themeini(){
	#ifdef EXCESSIVE
	printf("themeini::themeini\n");
	#endif
	timer_x=25;
	timer_y=743;
	timer_s=30;
	load_status_x=485;
	load_status_y=2;
	load_status_s=20;
	load_version_x=0;
	load_version_y=114;
	load_version_s=30;
	load_message1_x=0;
	load_message1_y=78;
	load_message1_s=30;
	load_message2_x=0;
	load_message2_y=40;
	load_message2_s=30;
	load_logotext1_x=370;
	load_logotext1_y=420;
	load_logotext1_s=30;
	load_logotext2_x=430;
	load_logotext2_y=330;
	load_logotext2_s=70;
	options_screenname_x=175;
	options_screenname_y=688;
	options_screenname_s=40;
	options_table_x=300;
	options_table_y=600;
	options_table_s=24;
	title_start_x=160;
	title_start_y=5;
	title_start_s=40;
	title_options_x=480;
	title_options_y=5;
	title_options_s=40;
	title_quit_x=760;
	title_quit_y=5;
	title_quit_s=40;
	title_version_x=790;
	title_version_y=698;
	title_version_s=24;
	mode_drumtext1_x=75;
	mode_drumtext1_y=500;
	mode_drumtext1_s=42;
	mode_drumtext2_x=102;
	mode_drumtext2_y=445;
	mode_drumtext2_s=42;
	mode_drumgraphic_x=182;
	mode_drumgraphic_y=453;
	mode_guitar1text1_x=400;
	mode_guitar1text1_y=500;
	mode_guitar1text1_s=42;
	mode_guitar1text2_x=440;
	mode_guitar1text2_y=445;
	mode_guitar1graphic_x=515;
	mode_guitar1graphic_y=453;
	mode_guitar2text1_x=730;
	mode_guitar2text1_y=500;
	mode_guitar2text1_s=42;
	mode_guitar2text2_x=770;
	mode_guitar2text2_y=445;
	mode_guitar2graphic_x=847;
	mode_guitar2graphic_y=453;
	mode_message_x=100;
	mode_message_y=100;
	mode_message_s=42;
	mode_start_x=375;
	mode_start_y=0;
	mode_start_s=42;
	mode_screenname_x=655;
	mode_screenname_y=690;
	mode_screenname_s=40;
	song_selector_x=500;
	song_selector_y=506;
	song_sort_x=850;
	song_sort_y=666;
	song_sort_s=30;
	song_previewimage_x=249;
	song_previewimage_y=585;
	song_difficulties_x=250;
	song_difficulties_y=5;
	song_difficultymarker_x=276;
	song_difficultymarker_y=222;
	song_bpmtext_x=30;
	song_bpmtext_y=270;
	song_bpmtext_s=50;
	song_artitist_x=542;
	song_artitist_y=285;
	song_artitist_s=24;
	song_options_x=542;
	song_options_y=60;
	song_stages_x=800;
	song_stages_y=0;
	song_stages_s=46;
	song_screenname_x=150;
	song_screenname_y=698;
	song_screenname_s=24;
	song_drum_x=236;
	song_drum_y=274;
	song_drum_s=30;
	song_normal_x=333;
	song_normal_y=274;
	song_normal_s=30;
	song_bass_x=441;
	song_bass_y=274;
	song_bass_s=30;
	song_standard_x=29;
	song_standard_y=192;
	song_standard_s=40;
	song_advanced_x=29;
	song_advanced_y=101;
	song_advanced_s=40;
	song_extreme_x=29;
	song_extreme_y=10;	
	song_extreme_s=40;	
	song_highscoretable_x=30;
	song_highscoretable_y=352;
	song_highscoretable_s=22;
	game_drumwideoffset=-138;
	game_guitar1wideoffset=158;
	game_guitar2wideoffset=160;
	game_drumsessionoffset=-32;
	game_guitar1sessionoffset=51;
	game_guitar2sessionoffset=166;
	game_drumonlyoffset=2;
	game_offset=-998;
	game_guitar1onlyoffset=0;
	game_guitar2onlyoffset=201;
	game_vidd_x=718;
	game_vidd_y=384;
	game_vidg_x=300;
	game_vidg_y=384;
	game_viddg_x=500;
	game_viddg_y=398;
	game_viddgw_x=500;
	game_viddgw_y=398;
	result_leftdrum=232;
	result_bottomdrum=0;
	result_leftg1=569;
	result_bottomg1=0;
	result_leftg2=914;
	result_bottomg2=0;
	result_screenname_x=652;
	result_screenname_y=698;
	result_screenname_s=24;
}

themeini::~themeini(){
	#ifdef EXCESSIVE
	printf("themeini::~themeini\n");
	#endif
}

void themeini::load(){
	#ifdef EXCESSIVE
	printf("themeini::load\n");
	#endif
	ifstream themefile[2];
	char file[256];
	for (int a=0;a<2;a++){
		if (a==0)snprintf(file,255,"./Themes/Default/theme.ini");
		if (a==1)snprintf(file,255,"./Themes/%s/theme.ini", theme);
		if (!testfile(file)){
			printf("%s theme file not open, cannot find or other error.\n",file);
			if (a==0)appisrunning=false;
			return;
		}
		while(fstreampotty>0){}
    	fstreampotty++;
		themefile[a].open(file);
	    fstreampotty--;
	    while(!themefile[a].good()){
            themefile[a].close();
            #ifdef DEBUG
			printf("%s issues opening file, cannot gain access.\n",file);
			testfile(file);
			#endif
			SDL_Delay(100);
			themefile[a].clear();
			themefile[a].open(file);
		}
		#ifdef DEBUG
		if (themefile[a].good()){
	        #ifdef DEBUG
				printf("%s theme file has been opened.\n",file);
   			#endif
		}
		#endif
		while (themefile[a].good()){
			char buffer[512];
			char variable[256];
			char varvalue[256];
			snprintf(variable,255,"");
			snprintf(varvalue,255,"");
			snprintf(buffer,511,"");
			themefile[a].getline(buffer,511,'\n');
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
			//loading the ini!
			if (strcmp(strlwr2(variable),"timer-x")==0)
				timer_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"timer-y")==0)
				timer_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"timer-s")==0)
				timer_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-status-x")==0)
				load_status_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-status-y")==0)
				load_status_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-status-s")==0)
				load_status_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-version-x")==0)
				load_version_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-version-y")==0)
				load_version_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-version-s")==0)
				load_version_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-message1-x")==0)
				load_message1_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-message1-y")==0)
				load_message1_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"numberofsakura")==0)
				NOS=atoi(varvalue);
			if (strcmp(strlwr2(variable),"displaysakura")==0)
				if (strcmp(strlwr2(varvalue),"true")==0)
					displaysakura=true;
				else
					displaysakura=false;
			if (strcmp(strlwr2(variable),"load-message1-s")==0)
				load_message1_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-message2-x")==0)
				load_message2_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-message2-y")==0)
				load_message2_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-message2-s")==0)
				load_message2_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-logotext1-x")==0)
				load_logotext1_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-logotext1-y")==0)
				load_logotext1_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-logotext1-s")==0)
				load_logotext1_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-logotext2-x")==0)
				load_logotext2_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-logotext2-y")==0)
				load_logotext2_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"load-logotext2-s")==0)
				load_logotext2_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"title-options-x")==0)
				title_options_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"title-options-y")==0)
				title_options_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"title-options-s")==0)
				title_options_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"title-start-x")==0)
				title_start_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"title-start-y")==0)
				title_start_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"title-start-s")==0)
				title_start_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"title-quit-x")==0)
				title_quit_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"title-quit-y")==0)
				title_quit_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"title-quit-s")==0)
				title_quit_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"title-version-x")==0)
				title_version_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"title-version-y")==0)
				title_version_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"title-version-s")==0)
				title_version_s=atoi(varvalue);
   			if (strcmp(strlwr2(variable),"options-screenname-x")==0)
				options_screenname_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"options-screenname-y")==0)
				options_screenname_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"options-screenname-s")==0)
				options_screenname_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"options-table-x")==0)
				options_table_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"options-table-y")==0)
				options_table_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"options-table-s")==0)
				options_table_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-drumtext1-x")==0)
				mode_drumtext1_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-drumtext1-y")==0)
				mode_drumtext1_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-drumtext1-s")==0)
				mode_drumtext1_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-drumtext2-x")==0)
				mode_drumtext2_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-drumtext2-y")==0)
				mode_drumtext2_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-drumtext2-s")==0)
				mode_drumtext2_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-drumgraphic-x")==0)
				mode_drumgraphic_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-drumgraphic-y")==0)
				mode_drumgraphic_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-drumgraphic-s")==0)
				mode_drumgraphic_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar1text1-x")==0)
				mode_guitar1text1_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar1text1-y")==0)
				mode_guitar1text1_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar1text1-s")==0)
				mode_guitar1text1_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar1text2-x")==0)
				mode_guitar1text2_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar1text2-y")==0)
				mode_guitar1text2_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar1text2-s")==0)
				mode_guitar1text2_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar1graphic-x")==0)
				mode_guitar1graphic_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar1graphic-y")==0)
				mode_guitar1graphic_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar1graphic-s")==0)
				mode_guitar1graphic_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar2text1-x")==0)
				mode_guitar2text1_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar2text1-y")==0)
				mode_guitar2text1_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar2text1-s")==0)
				mode_guitar2text1_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar2text2-x")==0)
				mode_guitar2text2_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar2text2-y")==0)
				mode_guitar2text2_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar2text2-s")==0)
				mode_guitar2text2_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar2graphic-x")==0)
				mode_guitar2graphic_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar2graphic-y")==0)
				mode_guitar2graphic_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-guitar2graphic-s")==0)
				mode_guitar2graphic_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-message-x")==0)
				mode_message_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-message-y")==0)
				mode_message_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-message-s")==0)
				mode_message_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-start-x")==0)
				mode_start_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-start-y")==0)
				mode_start_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-start-s")==0)
				mode_start_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-screenname-x")==0)
				mode_screenname_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-screenname-y")==0)
				mode_screenname_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"mode-screenname-s")==0)
				mode_screenname_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-selector-x")==0)
				song_selector_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-selector-y")==0)
				song_selector_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-selector-s")==0)
				song_selector_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-sort-x")==0)
				song_sort_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-sort-y")==0)
				song_sort_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-sort-s")==0)
				song_sort_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-previewimage-x")==0)
				song_previewimage_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-previewimage-y")==0)
				song_previewimage_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-previewimage-s")==0)
				song_previewimage_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-difficulties-x")==0)
				song_difficulties_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-difficulties-y")==0)
				song_difficulties_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-difficulties-s")==0)
				song_difficulties_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-difficultymarker-x")==0)
				song_difficultymarker_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-difficultymarker-y")==0)
				song_difficultymarker_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-bpmtext-x")==0)
				song_bpmtext_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-bpmtext-y")==0)
				song_bpmtext_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-bpmtext-s")==0)
				song_bpmtext_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-artitist-x")==0)
				song_artitist_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-artitist-y")==0)
				song_artitist_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-artitist-s")==0)
				song_artitist_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-options-x")==0)
				song_options_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-options-y")==0)
				song_options_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-options-s")==0)
				song_options_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-stages-x")==0)
				song_stages_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-stages-y")==0)
				song_stages_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-stages-s")==0)
				song_stages_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-screenname-x")==0)
				song_screenname_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-screenname-y")==0)
				song_screenname_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-screenname-s")==0)
				song_screenname_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-drum-x")==0)
				song_drum_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-drum-y")==0)
				song_drum_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-drum-s")==0)
				song_drum_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-normal-x")==0)
				song_normal_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-normal-y")==0)
				song_normal_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-normal-s")==0)
				song_normal_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-bass-x")==0)
				song_bass_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-bass-y")==0)
				song_bass_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-bass-s")==0)
				song_bass_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-standard-x")==0)
				song_standard_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-standard-y")==0)
				song_standard_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-standard-s")==0)
				song_standard_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-advanced-x")==0)
				song_advanced_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-advanced-y")==0)
				song_advanced_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-advanced-s")==0)
				song_advanced_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-extreme-x")==0)
				song_extreme_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-extreme-y")==0)
				song_extreme_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-extreme-s")==0)
				song_extreme_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-highscoretable-x")==0)
				song_highscoretable_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-highscoretable-y")==0)
				song_highscoretable_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"song-highscoretable-s")==0)
				song_highscoretable_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-drumwideoffset")==0)
				game_drumwideoffset=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guitar1wideoffset")==0)
				game_guitar1wideoffset=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guitar2wideoffset")==0)
				game_guitar2wideoffset=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guitar1sessionoffset")==0)
				game_guitar1sessionoffset=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guitar2sessionoffset")==0)
				game_guitar2sessionoffset=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-drumsessionoffset")==0)
				game_drumsessionoffset=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-drumonlyoffset")==0)
				game_drumonlyoffset=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guitar1onlyoffset")==0)
				game_guitar1onlyoffset=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guitar2onlyoffset")==0)
				game_guitar2onlyoffset=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-vidd-x")==0)
				game_vidd_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-vidd-y")==0)
				game_vidd_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-vidd-s")==0)
				game_vidd_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-vidg-x")==0)
				game_vidg_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-vidg-y")==0)
				game_vidg_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-vidg-s")==0)
				game_vidg_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-viddg-x")==0)
				game_viddg_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-viddg-y")==0)
				game_viddg_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-viddg-s")==0)
				game_viddg_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-viddgw-x")==0)
				game_viddgw_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-viddgw-y")==0)
				game_viddgw_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-viddgw-s")==0)
				game_viddgw_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"result-leftdrum")==0)
				result_leftdrum=atoi(varvalue);
			if (strcmp(strlwr2(variable),"result-bottomdrum")==0)
				result_bottomdrum=atoi(varvalue);
			if (strcmp(strlwr2(variable),"result-leftg1")==0)
				result_leftg1=atoi(varvalue);
			if (strcmp(strlwr2(variable),"result-bottomg1")==0)
				result_bottomg1=atoi(varvalue);
			if (strcmp(strlwr2(variable),"result-leftg2")==0)
				result_leftg2=atoi(varvalue);
			if (strcmp(strlwr2(variable),"result-bottomg2")==0)
				result_bottomg2=atoi(varvalue);
			if (strcmp(strlwr2(variable),"result-screenname-x")==0)
				result_screenname_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"result-screenname-y")==0)
				result_screenname_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"result-screenname-s")==0)
				result_screenname_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-drumonlymod-x")==0)
				game_drumonlymod_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-drumonlymod-y")==0)
				game_drumonlymod_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-drumonlymod-s")==0)
				game_drumonlymod_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit1onlymod-x")==0)
				game_guit1onlymod_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit1onlymod-y")==0)
				game_guit1onlymod_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit1onlymod-s")==0)
				game_guit1onlymod_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit2onlymod-x")==0)
				game_guit2onlymod_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit2onlymod-y")==0)
				game_guit2onlymod_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit2onlymod-s")==0)
				game_guit2onlymod_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-drummod-x")==0)
				game_drummod_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-drummod-y")==0)
				game_drummod_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-drummod-s")==0)
				game_drummod_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit1mod-x")==0)
				game_guit1mod_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit1mod-y")==0)
				game_guit1mod_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit1mod-s")==0)
				game_guit1mod_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit2mod-x")==0)
				game_guit2mod_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit2mod-y")==0)
				game_guit2mod_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit2mod-s")==0)
				game_guit2mod_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-drumwidemod-x")==0)
				game_drumwidemod_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-drumwidemod-y")==0)
				game_drumwidemod_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-drumwidemod-s")==0)
				game_drumwidemod_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit1widemod-x")==0)
				game_guit1widemod_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit1widemod-y")==0)
				game_guit1widemod_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit1widemod-s")==0)
				game_guit1widemod_s=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit2widemod-x")==0)
				game_guit2widemod_x=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit2widemod-y")==0)
				game_guit2widemod_y=atoi(varvalue);
			if (strcmp(strlwr2(variable),"game-guit2widemod-s")==0)
				game_guit2widemod_s=atoi(varvalue);
		}
		themefile[a].close();
	}
}
