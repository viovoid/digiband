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
void autoplayscreen(){
	#ifdef EXCESSIVE
	printf("autoplayscreen\n");
	#endif
	static int screenstart;
	if (!screenfaddingout){
		if (currscreen!=prevscreen){
			screenstart=SDL_GetTicks();
			srand(time(0));
			thesong=int((double(rand())/double(RAND_MAX))*double(gbsongcount));
			while(thesong==presong){
				thesong=int((double(rand())/double(RAND_MAX))*double(gbsongcount));
			}
			#ifdef DEBUG
			printf("I have determined song:%i will be played.\n",thesong);
			#endif
			playpreview(true);
			char playstring[512];
			jukeboxmode=true;
			guit1diff=2;
			guit2diff=2;
			drumdiff=2;
			if (drumdiff==2&&songs[thesong].drumextdiff<1)drumdiff=1;
			if (guit1diff==2&&songs[thesong].guitextdiff<1)guit1diff=1;
			if (guit2diff==2&&songs[thesong].guitextdiff<1)guit2diff=1;
			if (drumdiff==1&&songs[thesong].drumadvdiff<1)drumdiff=0;
			if (guit1diff==1&&songs[thesong].guitadvdiff<1)guit1diff=0;
			if (guit2diff==1&&songs[thesong].guitadvdiff<1)guit2diff=0;
			newsong=true;
			songs[0].reloadsong();
			songs[thesong].resetplayed();
			currbpm=songs[thesong].basebpm;
			loadscores();
		}
	}
	if (thesong<0||thesong>gbsongcount){
		printf("something changed the song var.");
		appisrunning=false;
		return;	
	}
	if (screenfaddingin||screenfaddingout){
		songposition=-240000;	
	}
	if (currbpm==0)
		currbpm=150;
	playrender();
	if (!screenfaddingin&&!screenfaddingout){
		#ifndef EXCESSIVE
		if ( songposition > ((songs[thesong].highestmeasure+3)*240000) || SDL_GetTicks()>screenstart+60000){
		#else
        if ( songposition > ((songs[thesong].highestmeasure+3)*240000) || SDL_GetTicks()>screenstart+10000){
		#endif
			//songs[thesong].resetplayed();
			nextscreen=21;
			screenfaddingout=true;
			screenchangenow=false;
			screenfaddingin=false;
		}
	}else{
		sprintf(curravi, "NULL");
	}
	draw_quadt2(0,801,601,0,223,167,255,255,255,255,0,0,backgroundtexture);
    if (songposition>0){
		if(!screenfaddingin&&!screenfaddingout){
			if (gpavi.isloaded()){
				gpavi.drawavi(289,384,8000,289,384);
			}else{
				draw_quadt2(0,289,384,0,289,384,255,255,255,255,0,0,previewtexture);
			}
		}
	}else{
		draw_quadt2(0,289,384,0,289,384,255,255,255,255,0,0,previewtexture);
	}
	draw_quad(0,512,384,1000,640,400,255,255,255,255,0,0,67);
	static char option1[256];
	sprintf(option1, "Coins %i/%i Credits (%i)", coinsinserted,coinsperplay,credits);
	static drawtext option1s;
	option1s.load(option1,"font.ttf",255,255,255,20);
	option1s.draw(400,2,5000,255,255,255,255,false,true);
	const int O1C=16;
	char osd1text[O1C][256];
	int osd1colors[O1C][3];
	static drawtext osd1[O1C];
	sprintf(osd1text[0], "Title:             %s", songs[thesong].name);
	osd1colors[0][0]=255;osd1colors[0][1]=255;osd1colors[0][2]=255;
	sprintf(osd1text[1], "Artist:            %s", songs[thesong].artist);
	osd1colors[1][0]=255;osd1colors[1][1]=255;osd1colors[1][2]=255;
	sprintf(osd1text[2], "Genre:             %s", songs[thesong].genre);
	osd1colors[2][0]=255;osd1colors[2][1]=255;osd1colors[2][2]=255;
	sprintf(osd1text[3], "From:              %s", songs[thesong].cat);
	osd1colors[3][0]=255;osd1colors[3][1]=255;osd1colors[3][2]=255;
	sprintf(osd1text[4], "Standard Stats:    (D-%i, G-%i,A-%i)",songs[thesong].drumbasdiff,songs[thesong].guitbasdiff,songs[thesong].guitbbasdiff);
	osd1colors[4][0]=0;osd1colors[4][1]=255;osd1colors[4][2]=0;
	sprintf(osd1text[5], "Drum Hi-Score:     %i (combo:%i)", songs[thesong].basdrumhs,songs[thesong].basdrummc);
	osd1colors[5][0]=192;osd1colors[5][1]=255;osd1colors[5][2]=192;
	sprintf(osd1text[6], "Guitar 1 Hi-Score: %i (combo:%i)", songs[thesong].basguitar1hs,songs[thesong].basguitar1mc);
	osd1colors[6][0]=192;osd1colors[6][1]=255;osd1colors[6][2]=192;
	sprintf(osd1text[7], "Guitar 2 Hi-Score: %i (combo:%i)", songs[thesong].basguitar2hs,songs[thesong].basguitar2mc);
	osd1colors[7][0]=192;osd1colors[7][1]=255;osd1colors[7][2]=192;
	sprintf(osd1text[8], "Advanced Stats:    (D-%i, G-%i,A-%i)",songs[thesong].drumadvdiff,songs[thesong].guitadvdiff,songs[thesong].guitbadvdiff);
	osd1colors[8][0]=255;osd1colors[8][1]=255;osd1colors[8][2]=0;
	sprintf(osd1text[9], "Drum Hi-Score:     %i (combo:%i)", songs[thesong].advdrumhs,songs[thesong].advdrummc);
	osd1colors[9][0]=255;osd1colors[9][1]=255;osd1colors[9][2]=192;
	sprintf(osd1text[10], "Guitar 1 Hi-Score: %i (combo:%i)", songs[thesong].advguitar1hs,songs[thesong].advguitar1mc);
	osd1colors[10][0]=255;osd1colors[10][1]=255;osd1colors[10][2]=192;
	sprintf(osd1text[11], "Guitar 2 Hi-Score: %i (combo:%i)", songs[thesong].advguitar2hs,songs[thesong].advguitar2mc);
	osd1colors[11][0]=255;osd1colors[11][1]=255;osd1colors[11][2]=192;
	sprintf(osd1text[12], "Extreme Stats:     (D-%i, G-%i,A-%i)",songs[thesong].drumextdiff,songs[thesong].guitextdiff,songs[thesong].guitbextdiff);
	osd1colors[12][0]=255;osd1colors[12][1]=0;osd1colors[12][2]=0;
	sprintf(osd1text[13], "Drum Hi-Score:     %i (combo:%i)", songs[thesong].extdrumhs,songs[thesong].extdrummc);
	osd1colors[13][0]=255;osd1colors[13][1]=192;osd1colors[13][2]=192;
	sprintf(osd1text[14], "Guitar 1 Hi-Score: %i (combo:%i)", songs[thesong].extguitar1hs,songs[thesong].extguitar1mc);
	osd1colors[14][0]=255;osd1colors[14][1]=192;osd1colors[14][2]=192;
	sprintf(osd1text[15], "Guitar 2 Hi-Score: %i (combo:%i)", songs[thesong].extguitar2hs,songs[thesong].extguitar2mc);
	osd1colors[15][0]=255;osd1colors[15][1]=192;osd1colors[15][2]=192;
	
	for (int a=0;a<O1C;a++){
		osd1[a].load(osd1text[a],"unicode.ttf",osd1colors[a][0],osd1colors[a][1],osd1colors[a][2],24);
		osd1[a].draw(593,735-a*19,8000,255,255,255,255,false,true);
	}	
	static double atimer=0;
	atimer+=double(steptime)/5000.0;
	int alpha=int(sin(atimer)*2048.0);
	if (alpha<0)alpha=0;
	if (alpha>255)alpha=255;
	const int O2C=11;
	static char osd2[O2C][256];
	sprintf(osd2[0], "Best Drum Players");
	for (int a=0;a<O2C-1;a++){
		sprintf(osd2[a+1], "  %s %i", dmscorenames[a],dmscores[a]);
	}
	for (int a=0;a<O2C;a++){
		int s=18;
		if (a==0)
			draw_number(osd2[a],643+s,394-(a*(s*2)),8000,s,0,255,0,alpha);
		else
			draw_number(osd2[a],643+s,394-(a*(s*2)),8000,s,255,255,255,alpha);
	}
	alpha=-int(sin(atimer)*2048.0);
	if (alpha<0)alpha=0;
	if (alpha>255)alpha=255;
	const int O3C=11;
	static char osd3[O3C][256];
	sprintf(osd3[0], "Best Guitar Players");
	for (int a=0;a<O3C-1;a++){
		sprintf(osd3[a+1], "   %s %i", gscorenames[a],gscores[a]);
	}
	for (int a=0;a<O3C;a++){
		int s=18;
		if (a==0)
			draw_number(osd3[a],625+s,394-(a*(s*2)),8000,s,255,0,0,alpha);
		else
			draw_number(osd3[a],625+s,394-(a*(s*2)),8000,s,255,255,255,alpha);
	}
}
