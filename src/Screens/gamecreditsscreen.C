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
//screen number: 13
void highscore(){
	#ifdef EXCESSIVE
	printf("gamecreditsscreen\n");
	#endif
	if (currscreen!=prevscreen){
		dmpos=0;
		g1pos=0;
		g2pos=0;
		dmhs=false;
		g1hs=false;
		g2hs=false;
		loadscores();
		dmrank=11;
		g1rank=11;
		g2rank=11;
		for (int a=9;a>-1;a--){
			if (gptscore>dmscores[a]){
				dmrank=a;
				dmhs=true;
			}
			if (gpg1tscore>gscores[a]){
				g1rank=a;
				g1hs=true;
			}
			if (gpg2tscore>gscores[a]){
				g2rank=a;
				g2hs=true;
			}
		}
		sprintf(dminitials, "   ");
		sprintf(g1initials, "   ");
		sprintf(g2initials, "   ");
		dmoptionselected='A';
		g1optionselected='A';
		g2optionselected='A';
	}
	static long totalframes;
	totalframes+=int(steptime);
	static char dmsccap[60];
	if (dmrank==0)
	sprintf(dmsccap, "1st place");
	if (dmrank==1)
	sprintf(dmsccap, "2nd place");
	if (dmrank==2)
	sprintf(dmsccap, "3rd place");
	if (dmrank>2)
	sprintf(dmsccap, "%ith place", dmrank+1);
	static char g1sccap[60];
	if (g1rank==0)
	sprintf(g1sccap, "1st place");
	if (g1rank==1)
	sprintf(g1sccap, "2nd place");
	if (g1rank==2)
	sprintf(g1sccap, "3rd place");
	if (g1rank>2)
	sprintf(g1sccap, "%ith place", g1rank+1);
	static char g2sccap[60];
	if (g2rank==0)
	sprintf(g2sccap, "1st place");
	if (g2rank==1)
	sprintf(g2sccap, "2nd place");
	if (g2rank==2)
	sprintf(g2sccap, "3rd place");
	if (g2rank>2)
	sprintf(g2sccap, "%ith place", g2rank+1);
	
	static drawtext dmrankt;
	static drawtext g1rankt;
	static drawtext g2rankt;
	dmrankt.load(dmsccap,"grade.ttf",255,255,255,20);
	g1rankt.load(g1sccap,"grade.ttf",255,255,255,20);
	g2rankt.load(g2sccap,"grade.ttf",255,255,255,20);
	if (dmrank<10)dmrankt.draw(733,552,100,255,255,255,255,true,true);//52px apart.
	if (g1rank<10)g1rankt.draw(733,352,100,255,255,255,255,true,true);
	if (g2rank<10)g2rankt.draw(733,152,100,255,255,255,255,true,true);
	if (dmoptionselected<'A')
		dmoptionselected='Z'+2;
	if (dmoptionselected>'Z'+2)
		dmoptionselected='A';
	if (dmpos>2){
		if (dmoptionselected<'Z'+1)
			dmoptionselected='Z'+2;						
		if (dmoptionselected>'Z'+2)
			dmoptionselected='Z'+1;								
	}
	if (g1optionselected<'A')
		g1optionselected='Z'+2;
	if (g1optionselected>'Z'+2)
		g1optionselected='A';
	if (g1pos>2){
		if (g1optionselected<'Z'+1)
			g1optionselected='Z'+2;						
		if (g1optionselected>'Z'+2)
			g1optionselected='Z'+1;								
	}
	if (g2optionselected<'A')
		g2optionselected='Z'+2;
	if (g2optionselected>'Z'+2)
		g2optionselected='A';
	if (g2pos>2){
		if (g2optionselected<'Z'+1)
			g2optionselected='Z'+2;						
		if (g2optionselected>'Z'+2)
			g2optionselected='Z'+1;								
	}
	if (dmhs)dminitials[dmpos]=dmoptionselected;
	if (g1hs)g1initials[g1pos]=g1optionselected;
	if (g2hs)g2initials[g2pos]=g2optionselected;
	if (dmrank<10)draw_number(dminitials,753,492,8000,50);
	if (g1rank<10)draw_number(g1initials,753,292,8000,50);
	if (g2rank<10)draw_number(g2initials,753,92,8000,50);
}

void gamecreditsscreen(){
	if (currscreen!=prevscreen)playpreview();
	const int creds=37;
	static double scroll;
	static drawtext marmots[creds];
	static char marmotscon[creds][256];
	static drawtext tyfp;
	static drawtext dmtscore1;
	static drawtext g1tscore1;
	static drawtext g2tscore1;
	static drawtext dmtscoren;
	static drawtext g1tscoren;
	static drawtext g2tscoren;
	static drawtext dmtscore2;
	static drawtext g1tscore2;
	static drawtext g2tscore2;
	static char dmtscorecon[256];
	static char g1tscorecon[256];
	static char g2tscorecon[256];
	//heh cool.
	const int parts=75;
	static double lspeed[parts];
	static int parx[parts];
	static int pary[parts];
	static int color[parts];
	static int size[parts];
	char avifile[128];
	static bool hasavi=false;
	srand(time(0));
	scroll+=.5f*double(steptime)/16.0;
	if (currscreen!=prevscreen){
		for (int a=0;a<parts;a++){
			lspeed[a]=double( (double)rand()/(double)(RAND_MAX/2)-1 );
			//pary[a]=int( (double)rand()/(double)RAND_MAX *768);
			pary[a]=a*10;
			parx[a]=int( (double)pary[a]*lspeed[a] ) + 512;
			color[a]=int( (double)rand()/(double)RAND_MAX *10);
			size[a]=int( (double)rand()/(double)RAND_MAX *50)+62;
			//printf("Particle %i will be drawn at: (%i,%i) with speed (%.2f) and color (%i)\n",a,parx[a],pary[a],lspeed[a],color[a]);
		}
		sprintf(dmtscorecon, "Thank You For Playing!");
		tyfp.load(dmtscorecon,"grade.ttf",255,255,255,20);
		sprintf(dmtscorecon, "Drum Player Score:");
		dmtscoren.load(dmtscorecon,"grade.ttf",128,128,0,20);
		sprintf(g1tscorecon, "Guitar Player 1 Score:");
		g1tscoren.load(g1tscorecon,"grade.ttf",128,0,0,20);
		sprintf(g2tscorecon, "Guitar Player 2 Score:");
		g2tscoren.load(g2tscorecon,"grade.ttf",0,0,128,20);
		sprintf(dmtscorecon, "%i", gptscore);
		dmtscore1.load(dmtscorecon,"grade.ttf",255,255,0,40);
		dmtscore2.load(dmtscorecon,"grade.ttf",128,128,0,40);
		sprintf(g1tscorecon, "%i", gpg1tscore);
		g1tscore1.load(g1tscorecon,"grade.ttf",255,0,0,40);
		g1tscore2.load(g1tscorecon,"grade.ttf",128,0,0,40);
		sprintf(g2tscorecon, "%i", gpg2tscore);
		g2tscore1.load(g2tscorecon,"grade.ttf",0,0,255,40);
		g2tscore2.load(g2tscorecon,"grade.ttf",0,0,128,40);
		
		scroll=-20;
		sprintf(marmotscon[0], "Lead Developer/Producer/Director/Head Marmot:");
		marmots[0].load(marmotscon[0],"font.ttf",128,0,255,20);
		sprintf(marmotscon[1], "Joe Wall");
		marmots[1].load(marmotscon[1],"font.ttf",255,255,255,20);
		sprintf(marmotscon[2], "    ");
		marmots[2].load(marmotscon[2],"font.ttf",255,255,255,20);
		sprintf(marmotscon[3], "Assistant Develepor/Sound Engineer (Oswego AL):");
		marmots[3].load(marmotscon[3],"font.ttf",255,128,192,20);
		sprintf(marmotscon[4], "Velex Loutzenhiser");
		marmots[4].load(marmotscon[4],"font.ttf",255,255,255,20);
		sprintf(marmotscon[5], "    ");
		marmots[5].load(marmotscon[5],"font.ttf",255,255,255,20);
		sprintf(marmotscon[6], "Assistant Graphic Designer:");
		marmots[6].load(marmotscon[6],"font.ttf",0,0,192,20);
		sprintf(marmotscon[7], "Michael Culver");
		marmots[7].load(marmotscon[7],"font.ttf",255,255,255,20);
		sprintf(marmotscon[8], "    ");
		sprintf(marmotscon[9], "DigiBand Named by:");
		marmots[9].load(marmotscon[9],"font.ttf",0,0,192,20);
		sprintf(marmotscon[10], "Dave Britten");
		marmots[10].load(marmotscon[10],"font.ttf",255,255,255,20);
		sprintf(marmotscon[11], "    ");
		marmots[11].load(marmotscon[11],"font.ttf",255,255,255,20);
		sprintf(marmotscon[12], "Developed with the Following Tools and Libraries:");
		marmots[12].load(marmotscon[12],"font.ttf",0,255,0,20);
		sprintf(marmotscon[13], "Simple Direct-media Layer (SDL)");
		marmots[13].load(marmotscon[13],"font.ttf",255,255,255,20);
		sprintf(marmotscon[14], "Minimum GNU for Windows (Mingw)");
		marmots[14].load(marmotscon[14],"font.ttf",255,255,255,20);
		sprintf(marmotscon[15], "   ");
		marmots[15].load(marmotscon[15],"font.ttf",255,255,255,20);
		sprintf(marmotscon[16], "Music Credits:");
		marmots[16].load(marmotscon[16],"font.ttf",0,255,255,20);
		sprintf(marmotscon[17], "\"After the Fall\" - Dave De Jong");
		marmots[17].load(marmotscon[17],"font.ttf",255,255,255,20);
		sprintf(marmotscon[18], "\"Blue Matter\" - John Scofield");
		marmots[18].load(marmotscon[18],"font.ttf",255,255,255,20);
		sprintf(marmotscon[19], "\"Blue Train\" - Josef Huber (Orig. by John Coltrane)");
		marmots[19].load(marmotscon[19],"font.ttf",255,255,255,20);
		sprintf(marmotscon[20], "\"Chicago Days\" - Eric M. Vigeland");
		marmots[20].load(marmotscon[20],"font.ttf",255,255,255,20);
		sprintf(marmotscon[21], "\"A Casual Emergency\" - Rob Dewey Trio");
		marmots[21].load(marmotscon[21],"font.ttf",255,255,255,20);
		sprintf(marmotscon[22], "\"Aicha\" - Hot Club de Frank");
		marmots[22].load(marmotscon[22],"font.ttf",255,255,255,20);
		sprintf(marmotscon[23], "Original content can be found at www.digiband.org");
		marmots[23].load(marmotscon[23],"font.ttf",255,255,255,20);
		sprintf(marmotscon[24], "    ");
		marmots[24].load(marmotscon[24],"font.ttf",255,255,255,20);
		sprintf(marmotscon[25], "Game Testers:");
		marmots[25].load(marmotscon[25],"font.ttf",255,0,0,20);
		sprintf(marmotscon[26], "Ryan Van Alstine");
		marmots[26].load(marmotscon[26],"font.ttf",255,255,255,20);
		sprintf(marmotscon[27], "Chad \"Tanaalethan\" Grutter");
		marmots[27].load(marmotscon[27],"font.ttf",255,255,255,20);
		sprintf(marmotscon[28], "\"BLueSS\"");
		marmots[28].load(marmotscon[28],"font.ttf",255,255,255,20);
		sprintf(marmotscon[29], "Susan Mumma");
		marmots[29].load(marmotscon[29],"font.ttf",255,255,255,20);
		sprintf(marmotscon[30], "    ");
		marmots[30].load(marmotscon[30],"font.ttf",255,255,255,20);
		sprintf(marmotscon[31], "Special Thanks:");
		marmots[31].load(marmotscon[31],"font.ttf",255,0,0,20);
		sprintf(marmotscon[32], "Sam Latinga for Creating SDL");
		marmots[32].load(marmotscon[32],"font.ttf",255,255,255,20);
		sprintf(marmotscon[33], "To the Kuribo Shoe for being able to stomp Spineys");
		marmots[33].load(marmotscon[33],"font.ttf",255,255,255,20);
		sprintf(marmotscon[34], "The Computer Club of WMU - For putting up with me while making this game");
		marmots[34].load(marmotscon[34],"font.ttf",255,255,255,20);
		sprintf(marmotscon[35], "    ");
		marmots[35].load(marmotscon[35],"font.ttf",255,255,255,20);
		sprintf(marmotscon[36], "And to all of you for supporting our game");
		marmots[36].load(marmotscon[36],"font.ttf",255,255,255,20);
	}
	for (int a=0;a<parts;a++){
		pary[a]+=3;
		if (pary[a]>800){
			pary[a]=0;
		}
		parx[a]=int( (double)pary[a]*lspeed[a] ) + 512;
		if (color[a]==0)
			draw_quad3(0,parx[a],pary[a],-8000+(a*10),size[a],size[a],255,255,255,255,0,int(scroll*5.0)+20,50);
		if (color[a]==1)
			draw_quad3(0,parx[a],pary[a],-8000+(a*10),size[a],size[a],255,0,0,255,0,int(scroll*5.0)+40,50);
		if (color[a]==2)
			draw_quad3(0,parx[a],pary[a],-8000+(a*10),size[a],size[a],0,255,0,255,0,int(scroll*5.0)+60,50);
		if (color[a]==3)
			draw_quad3(0,parx[a],pary[a],-8000+(a*10),size[a],size[a],0,0,255,255,0,int(scroll*5.0)+80,50);
		if (color[a]==4)
			draw_quad3(0,parx[a],pary[a],-8000+(a*10),size[a],size[a],255,255,0,255,0,int(scroll*5.0)+100,50);
		if (color[a]==5)
			draw_quad3(0,parx[a],pary[a],-8000+(a*10),size[a],size[a],255,0,255,255,0,int(scroll*5.0)+120,50);
		if (color[a]==6)
			draw_quad3(0,parx[a],pary[a],-8000+(a*10),size[a],size[a],0,255,255,255,0,int(scroll*5.0),50);
		if (color[a]==7)
			draw_quad3(0,parx[a],pary[a],-8000+(a*10),size[a],size[a],255,255,255,255,0,0-int(scroll*5.0)+20,50);
		if (color[a]==8)
			draw_quad3(0,parx[a],pary[a],-8000+(a*10),size[a],size[a],255,255,255,255,0,int(scroll*5.0)+140,50);
		if (color[a]==9)
			draw_quad3(0,parx[a],pary[a],-8000+(a*10),size[a],size[a],255,255,255,255,0,0-int(scroll*5.0)+160,50);
	}
	for (int a=0;a<creds;a++){
		marmots[a].draw(52,-2-(24*a)+int(scroll),-10,255,0,0,0);
		marmots[a].draw(50,0-(24*a)+int(scroll),0);
	}
	draw_quad(0,170,-1014+int(scroll),9000,150,68,255,255,255,255,0,0,72);
	draw_quad(0,468,-1014+int(scroll),9000,138,75,255,255,255,255,0,0,73);

	tyfp.draw(733,652,100);
	if (drummode){
		dmtscoren.draw(733,632,100);
		dmtscore2.draw(733,579,50);
		dmtscore1.draw(738,584,100);
	}
	if (guitar1mode){
		g1tscoren.draw(733,432,100);
		g1tscore2.draw(733,379,50);
		g1tscore1.draw(738,384,100);
	}
	if (guitar2mode){
		g2tscoren.draw(733,232,100);
		g2tscore2.draw(733,179,50);
		g2tscore1.draw(738,184,100);
	}
	//counter
	if (arcademode){
		if (menucountertime>0){
			static long timer=0;
			if (currscreen!=prevscreen)
				timer=SDL_GetTicks();
			int timeleft=int(double(99)-((double(SDL_GetTicks())-double(timer))/1000.0));
			char disptime[10];
			sprintf(disptime, "%i", timeleft);
			static drawtext timerdisp;
			timerdisp.load(disptime,"font.ttf",255,255,255,uivars.timer_s);
			draw_quad(0,27,743,9800,25,25,255,255,255,255,0,0,66);
			if (timeleft>5){
				timerdisp.draw(uivars.timer_x-(timerdisp.width/2),uivars.timer_y-(timerdisp.height/2),9900,255,255,255,255,false,true);
			}else{
				if (timeleft==5)playsound(17,"timer.wav");
				timerdisp.draw(uivars.timer_x-(timerdisp.width/2),uivars.timer_y-(timerdisp.height/2),9900,255,128,128,255,true,true);
			}
			if (timeleft==0){
				nextscreen=1;
				screenfaddingout=true;
				screenchangenow=false;
				screenfaddingin=false;
			}
		}
	}
	highscore();
}
