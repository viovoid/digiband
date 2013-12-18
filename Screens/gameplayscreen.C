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
void animateexps(){
	#ifdef EXCESSIVE
	printf("animateexps\n");
	#endif
	double expstep=32.0*double(steptime)/16.0;
	if (d1exp){
		d1expt+=expstep;
		if (d1expt>=255){
			d1expt=255;
			d1exp=false;
		}
	}else{
		d1expt-=expstep;
		if (d1expt<=255){
			d1expt=0;
			d1exp=false;
		}
	}
	if (d2exp){
		d2expt+=expstep;
		if (d2expt>=255){
			d2expt=255;
			d2exp=false;
		}
	}else{
		d2expt-=expstep;
		if (d2expt<=255){
			d2expt=0;
			d2exp=false;
		}
	}
	if (d3exp){
		d3expt+=expstep;
		if (d3expt>=255){
			d3expt=255;
			d3exp=false;
		}
	}else{
		d3expt-=expstep;
		if (d3expt<=255){
			d3expt=0;
			d3exp=false;
		}
	}
	if (d4exp){
		d4expt+=expstep;
		if (d4expt>=255){
			d4expt=255;
			d4exp=false;
		}
	}else{
		d4expt-=expstep;
		if (d4expt<=255){
			d4expt=0;
			d4exp=false;
		}
	}
	if (d5exp){
		d5expt+=expstep;
		if (d5expt>=255){
			d5expt=255;
			d5exp=false;
		}
	}else{
		d5expt-=expstep;
		if (d5expt<=255){
			d5expt=0;
			d5exp=false;
		}
	}
	if (d6exp){
		d6expt+=expstep;
		if (d6expt>=255){
			d6expt=255;
			d6exp=false;
		}
	}else{
		d6expt-=expstep;
		if (d6expt<=255){
			d6expt=0;
			d6exp=false;
		}
	}
	if (g11exp){
		g11expt+=expstep;
		if (g11expt>=255){
			g11expt=255;
			g11exp=false;
		}
	}else{
		g11expt-=expstep;
		if (g11expt<=255){
			g11expt=0;
			g11exp=false;
		}
	}
	if (g12exp){
		g12expt+=expstep;
		if (g12expt>=255){
			g12expt=255;
			g12exp=false;
		}
	}else{
		g12expt-=expstep;
		if (g12expt<=255){
			g12expt=0;
			g12exp=false;
		}
	}
	if (g13exp){
		g13expt+=expstep;
		if (g13expt>=255){
			g13expt=255;
			g13exp=false;
		}
	}else{
		g13expt-=expstep;
		if (g13expt<=255){
			g13expt=0;
			g13exp=false;
		}
	}
	if (g21exp){
		g21expt+=expstep;
		if (g21expt>=255){
			g21expt=255;
			g21exp=false;
		}
	}else{
		g21expt-=expstep;
		if (g21expt<=255){
			g21expt=0;
			g21exp=false;
		}
	}
	if (g22exp){
		g22expt+=expstep;
		if (g22expt>=255){
			g22expt=255;
			g22exp=false;
		}
	}else{
		g22expt-=expstep;
		if (g22expt<=255){
			g22expt=0;	
			g22exp=false;
		}
	}
	if (g23exp){
		g23expt+=expstep;
		if (g23expt>=255){
			g23expt=255;
			g23exp=false;
		}
	}else{
		g23expt-=expstep;
		if (g23expt<=255){
			g23expt=0;
			g23exp=false;
		}
	}
	
}

void doobject(){
	if (currscreen!=prevscreen){
		if (currbpm==0)
			currbpm=150;
	}
	if (screenfaddingin)
		songposition=-240000;
	if (!screenfaddingin){
		if ( songposition > ((songs[thesong].highestmeasure+3)*240000) ){
			nextscreen=12;
			screenfaddingout=true;
			screenfaddingin=false;
			screenchangenow=false;
		}
	}
	if (songs[thesong].origbpm==0){
		notebpm=150;
	}else{
		notebpm=songs[thesong].origbpm;
	}
	draw_track();
	playrender();
	playoffbeat();
	if (gpmaxcombo<gpcurrcombo){
		gpmaxcombo=gpcurrcombo;
	}
	if (gpg1maxcombo<gpg1currcombo){
		gpg1maxcombo=gpg1currcombo;
	}
	if (gpg2maxcombo<gpg2currcombo){
		gpg2maxcombo=gpg2currcombo;
	}
}	

void gameplayscreen(int totalframes){
	static drawtext score;
	if (currscreen!=prevscreen){
		songs[0].reloadsong();
		sprintf(gphhgrade, "");
		sprintf(gpbdgrade, "");
		sprintf(gpsdgrade, "");
		sprintf(gphtgrade, "");
		sprintf(gpltgrade, "");
		sprintf(gpcygrade, "");
		sprintf(gpg1rgrade, "");
		sprintf(gpg1ggrade, "");
		sprintf(gpg1bgrade, "");
		sprintf(gpg2rgrade, "");
		sprintf(gpg2ggrade, "");
		sprintf(gpg2bgrade, "");
		gpmiss=0;
		gpalmost=0;
		gpgood=0;
		gpgreat=0;
		gpperfect=0;
		gpmaxcombo=0;
		gpcurrcombo=0;
		gpscore=0;
		gplifebar=50;
		gpg1miss=0;
		gpg1almost=0;
		gpg1good=0;
		gpg1great=0;
		gpg1perfect=0;
		gpg1maxcombo=0;
		gpg1currcombo=0;
		gpg1score=0;
		gpg1lifebar=50;
		gpg2miss=0;
		gpg2almost=0;
		gpg2good=0;
		gpg2great=0;
		gpg2perfect=0;
		gpg2maxcombo=0;
		gpg2currcombo=0;
		gpg2score=0;
		gpg2lifebar=50;
		songs[thesong].resetplayed();
	}
	double step=10*double(steptime)/16.0;
	gphhgradetime+=step;
	gpsdgradetime+=step;
	gpbdgradetime+=step;
	gphtgradetime+=step;
	gpltgradetime+=step;
	gpcygradetime+=step;
	gpg1ogradetime+=step;
	gpg1rgradetime+=step;
	gpg1ggradetime+=step;
	gpg1bgradetime+=step;
	gpg1wgradetime+=step;
	gpg2ogradetime+=step;
	gpg2rgradetime+=step;
	gpg2ggradetime+=step;
	gpg2bgradetime+=step;
	gpg2wgradetime+=step;
	if (gphhgradetime>255.0)
		gphhgradetime=255.0;
	if (gpsdgradetime>255.0)
		gpsdgradetime=255.0;
	if (gpbdgradetime>255.0)
		gpbdgradetime=255.0;
	if (gphtgradetime>255.0)
		gphtgradetime=255.0;
	if (gpltgradetime>255.0)
		gpltgradetime=255.0;
	if (gpcygradetime>255.0)
		gpcygradetime=255.0;
	if (gpg1ogradetime>255.0)
		gpg1ogradetime=255.0;
	if (gpg1rgradetime>255.0)
		gpg1rgradetime=255.0;
	if (gpg1ggradetime>255.0)
		gpg1ggradetime=255.0;
	if (gpg1bgradetime>255.0)
		gpg1bgradetime=255.0;
	if (gpg1wgradetime>255.0)
		gpg1wgradetime=255.0;
	if (gpg2ogradetime>255.0)
		gpg2ogradetime=255.0;
	if (gpg2rgradetime>255.0)
		gpg2rgradetime=255.0;
	if (gpg2ggradetime>255.0)
		gpg2ggradetime=255.0;
	if (gpg2bgradetime>255.0)
		gpg2bgradetime=255.0;
	if (gpg2wgradetime>255.0)
		gpg2wgradetime=255.0;
	char thetime[256];

	//Mode specific stuff
	//Mode specific stuff
	//Mode specific stuff
	//Mode specific stuff
	
	static double lifestep;
	lifestep+=steptime;
	if (gplifebar>100)
		gplifebar=100;
	if (gplifebar<0){
		gplifebar=0;
	}
	if (gpg1lifebar>100)
		gpg1lifebar=100;
	if (gpg1lifebar<0){
		gpg1lifebar=0;
	}
	if (gpg2lifebar>100)
		gpg2lifebar=100;
	if (gpg2lifebar<0){
		gpg2lifebar=0;
	}
	if (!drummode){
		gplifebar=0;
	}
	if (!guitar1mode){
		gpg1lifebar=0;
	}
	if (!guitar2mode){
		gpg2lifebar=0;
	}
	if (!screenfaddingin&&!screenfaddingout){
		if (gplifebar==0&&gpg1lifebar==0&&gpg2lifebar==0){
			if (stagefail){
				nextscreen=14;
				gameover=true;
				playsound(8,"gameoversound.wav");
				screenfaddingout=true;
				screenfaddingin=false;
				screenchangenow=false;
			}
		}
	}else{
		songposition=-240000;
		gplifebar=50;
		gpg1lifebar=50;
		gpg2lifebar=50;
	}
	double tstep=int( 30.0 * double(steptime)/16.0 );
	if (g1rp)
		g1ra+=tstep;
	else
		g1ra-=tstep;
	if (g1gp)
		g1ga+=tstep;
	else
		g1ga-=tstep;
	if (g1bp)
		g1ba+=tstep;
	else
		g1ba-=tstep;
	if (g1wp)
		g1wa+=tstep;
	else
		g1wa-=tstep;
	if (g2rp)
		g2ra+=tstep;
	else
		g2ra-=tstep;
	if (g2gp)
		g2ga+=tstep;
	else
		g2ga-=tstep;
	if (g2bp)
		g2ba+=tstep;
	else
		g2ba-=tstep;
	if (g2wp)
		g2wa+=tstep;
	else
		g2wa-=tstep;
	if (g1ra>127)
		g1ra=127;
	if (g1ra<0)
		g1ra=0;
	if (g1ga>127)
		g1ga=127;
	if (g1ga<0)
		g1ga=0;
	if (g1ba>127)
		g1ba=127;
	if (g1ba<0)
		g1ba=0;
	if (g1wa>127)
		g1wa=127;
	if (g1wa<0)
		g1wa=0;
	if (g2ra>127)
		g2ra=127;
	if (g2ra<0)
		g2ra=0;
	if (g2ga>127)
		g2ga=127;
	if (g2ga<0)
		g2ga=0;
	if (g2ba>127)
		g2ba=127;
	if (g2ba<0)
		g2ba=0;
	if (g2wa>127)
		g2wa=127;
	if (g2wa<0)
		g2wa=0;
	//the sakura petal :)
	draw_quad(0,512,384,-4050,640,400,255,255,255,255,0,0,69);
    if (displaysakura){
		int PETALS=NOS;
		static bool firstpetal=true;
		static double **xyrrp=NULL;
		if (xyrrp==NULL){
			xyrrp=(double **)malloc(sizeof(double *)*NOS);
			for (int a=0;a<NOS;a++){
				xyrrp[a]=(double *)malloc(sizeof(double)*5);
			}
		}
		srand(SDL_GetTicks());
		if (firstpetal){
			for (int a=0;a<PETALS;a++){
				xyrrp[a][0]=rand()/(RAND_MAX/1280);
				xyrrp[a][1]=rand()/(RAND_MAX/1060);
				xyrrp[a][2]=rand()/(RAND_MAX/360);
				xyrrp[a][3]=rand()/(RAND_MAX/360);
				xyrrp[a][4]=rand()/(RAND_MAX/100);
			}
			firstpetal=false;
		}
		for (int a=0;a<PETALS;a++){
			draw_quad(0,int(xyrrp[a][0]+cos(double(xyrrp[a][4])/16.0)*100.0),int(xyrrp[a][1]),-8000+(10*a),32,32,255,255,255,255,int(xyrrp[a][2]),int(xyrrp[a][3]),62);
			xyrrp[a][1]-=steptime/16.0;
			xyrrp[a][2]+=steptime/64.0;
			xyrrp[a][3]+=steptime/64.0;
			xyrrp[a][4]+=steptime/64.0;
			if (xyrrp[a][1]<-130)xyrrp[a][1]=930;
			if (xyrrp[a][4]>100)xyrrp[a][4]=0;
			if (xyrrp[a][4]<0)xyrrp[a][4]=100;
		}
	}
	//end the sakura petal.
	if((drummode&&guitar1mode)||(drummode&&guitar2mode)){
		if(widemode){
			draw_quad(0,512,384,-4050,620,384,255,255,255,255,0,0,18);
			offset=uivars.game_drumwideoffset;
			goffset=uivars.game_guitar1wideoffset;
			g2offset=uivars.game_guitar2wideoffset;
		}else{
			draw_quad(0,512,384,-4050,512,384,255,255,255,255,0,0,17);
			offset=uivars.game_drumsessionoffset;
			goffset=uivars.game_guitar1sessionoffset;
			g2offset=uivars.game_guitar2sessionoffset;
		}
	}
	if (drummode&&(!guitar1mode&&!guitar2mode)){
		draw_quad(0,512,384,-4050,512,384,255,255,255,255,0,0,20);
		offset=uivars.game_drumonlyoffset;
		goffset=1000;
		g2offset=0;
	}
	if ((guitar1mode||guitar2mode)&&!drummode){
		draw_quad(0,512,384,-4050,512,384,255,255,255,255,0,0,21);
		offset=-998;
		goffset=uivars.game_guitar1onlyoffset;
		g2offset=uivars.game_guitar2onlyoffset;
	}
	doobject();
	if (guitar1mode||guitar2mode){
		draw_quad_g(0,666+goffset,339,-100,22,333,255,0,0,int(g1ra),180,180,51);
		draw_quad_g(0,713+goffset,339,-100,22,333,0,255,0,int(g1ga),180,180,51);
		draw_quad_g(0,760+goffset,339,-100,22,333,0,0,255,int(g1ba),180,180,51);
		draw_quad_g(0,791+goffset,339,-100,7,333,255,255,255,int(g1wa),180,180,51);
		draw_quad_g(0,666+goffset+g2offset,339,-100,22,333,255,0,0,int(g2ra),180,180,51);
		draw_quad_g(0,713+goffset+g2offset,339,-100,22,333,0,255,0,int(g2ga),180,180,51);
		draw_quad_g(0,760+goffset+g2offset,339,-100,22,333,0,0,255,int(g2ba),180,180,51);
		draw_quad_g(0,791+goffset+g2offset,339,-100,7,333,255,255,255,int(g2wa),180,180,51);
		draw_quad(0,713+goffset,357,2000,71,335,255,255,255,255,0,0,30);
		draw_quad(0,713+goffset+g2offset,357,2000,71,335,255,255,255,255,0,0,30);
		draw_quad(0,666+goffset,733-int(g1ra/4),3000,21,14,255,255-(int(g1ra)*2),255-(int(g1ra)*2),255,180,0,43);
		draw_quad(0,713+goffset,733-int(g1ga/4),3000,21,14,255-(int(g1ga)*2),255,255-(int(g1ga)*2),255,180,0,44);
		draw_quad(0,760+goffset,733-int(g1ba/4),3000,21,14,255-(int(g1ba)*2),255-(int(g1ba)*2),255,255,180,0,45);
		draw_quad(0,666+goffset+g2offset,733-int(g2ra/4),3000,21,14,255,255-(int(g2ra)*2),255-(int(g2ra)*2),255,180,0,43);
		draw_quad(0,713+goffset+g2offset,733-int(g2ga/4),3000,21,14,255-(int(g2ga*2)),255,255-(int(g2ga)*2),255,180,0,44);
		draw_quad(0,760+goffset+g2offset,733-int(g2ba/4),3000,21,14,255-(int(g2ba*2)),255-(int(g2ba)*2),255,255,180,0,45);
		//g1
		if (guitar1mode){
			if (strcmp(gpg1rgrade,"Perfect")==0)
				draw_quad(0,666+goffset,740,3500,45+(cos(gpg1rgradetime/40.0)*10),12+(sin(gpg1rgradetime/40.0)*10),255,255,255,255-int(gpg1rgradetime),0,45,33);
			if (strcmp(gpg1ggrade,"Perfect")==0)
				draw_quad(0,713+goffset,740,3510,45+(cos(gpg1ggradetime/40.0)*10),12+(sin(gpg1ggradetime/40.0)*10),255,255,255,255-int(gpg1ggradetime),0,45,33);
			if (strcmp(gpg1bgrade,"Perfect")==0)
				draw_quad(0,760+goffset,740,3520,45+(cos(gpg1bgradetime/40.0)*10),12+(sin(gpg1bgradetime/40.0)*10),255,255,255,255-int(gpg1bgradetime),0,45,33);
			if (strcmp(gpg1rgrade,"Great")==0)
				draw_quad(0,666+goffset,740,3500,45+(cos(gpg1rgradetime/40.0)*10),12+(sin(gpg1rgradetime/40.0)*10),255,255,255,255-int(gpg1rgradetime),0,45,34);
			if (strcmp(gpg1ggrade,"Great")==0)
				draw_quad(0,713+goffset,740,3510,45+(cos(gpg1ggradetime/40.0)*10),12+(sin(gpg1ggradetime/40.0)*10),255,255,255,255-int(gpg1ggradetime),0,45,34);
			if (strcmp(gpg1bgrade,"Great")==0)
				draw_quad(0,760+goffset,740,3520,45+(cos(gpg1bgradetime/40.0)*10),12+(sin(gpg1bgradetime/40.0)*10),255,255,255,255-int(gpg1bgradetime),0,45,34);
			if (strcmp(gpg1rgrade,"Good")==0)
				draw_quad(0,666+goffset,740,3500,45+(cos(gpg1rgradetime/40.0)*10),12+(sin(gpg1rgradetime/40.0)*10),255,255,255,255-int(gpg1rgradetime),0,45,35);
			if (strcmp(gpg1ggrade,"Good")==0)
				draw_quad(0,713+goffset,740,3510,45+(cos(gpg1ggradetime/40.0)*10),12+(sin(gpg1ggradetime/40.0)*10),255,255,255,255-int(gpg1ggradetime),0,45,35);
			if (strcmp(gpg1bgrade,"Good")==0)
				draw_quad(0,760+goffset,740,3520,45+(cos(gpg1bgradetime/40.0)*10),12+(sin(gpg1bgradetime/40.0)*10),255,255,255,255-int(gpg1bgradetime),0,45,35);
			if (strcmp(gpg1rgrade,"Almost")==0)
				draw_quad(0,666+goffset,740,3500,45+(cos(gpg1rgradetime/40.0)*10),12+(sin(gpg1rgradetime/40.0)*10),255,255,255,255-int(gpg1rgradetime),0,45,36);
			if (strcmp(gpg1ggrade,"Almost")==0)
				draw_quad(0,713+goffset,740,3510,45+(cos(gpg1ggradetime/40.0)*10),12+(sin(gpg1ggradetime/40.0)*10),255,255,255,255-int(gpg1ggradetime),0,45,36);
			if (strcmp(gpg1bgrade,"Almost")==0)
				draw_quad(0,760+goffset,740,3520,45+(cos(gpg1bgradetime/40.0)*10),12+(sin(gpg1bgradetime/40.0)*10),255,255,255,255-int(gpg1bgradetime),0,45,36);
			if (strcmp(gpg1rgrade,"Miss")==0)
				draw_quad(0,666+goffset,740,3500,45+(cos(gpg1rgradetime/40.0)*10),12+(sin(gpg1rgradetime/40.0)*10),255,255,255,255-int(gpg1rgradetime),0,45,37);
			if (strcmp(gpg1ggrade,"Miss")==0)
				draw_quad(0,713+goffset,740,3510,45+(cos(gpg1ggradetime/40.0)*10),12+(sin(gpg1ggradetime/40.0)*10),255,255,255,255-int(gpg1ggradetime),0,45,37);
			if (strcmp(gpg1bgrade,"Miss")==0)
				draw_quad(0,760+goffset,740,3520,45+(cos(gpg1bgradetime/40.0)*10),12+(sin(gpg1bgradetime/40.0)*10),255,255,255,255-int(gpg1bgradetime),0,45,37);
			if (strcmp(gpg1ograde,"Perfect")==0)
				draw_quad(0,713+goffset,700,3530,45+(cos(gpg1ggradetime/40.0)*10),12+(sin(gpg1ogradetime/40.0)*10),255,255,255,255-int(gpg1ogradetime),0,0,33);
			if (strcmp(gpg1ograde,"Great")==0)
				draw_quad(0,713+goffset,700,3530,45+(cos(gpg1ggradetime/40.0)*10),12+(sin(gpg1ogradetime/40.0)*10),255,255,255,255-int(gpg1ogradetime),0,0,34);
			if (strcmp(gpg1ograde,"Good")==0)
				draw_quad(0,713+goffset,700,3530,45+(cos(gpg1ggradetime/40.0)*10),12+(sin(gpg1ogradetime/40.0)*10),255,255,255,255-int(gpg1ogradetime),0,0,35);
			if (strcmp(gpg1ograde,"Almost")==0)
				draw_quad(0,713+goffset,700,3530,45+(cos(gpg1ggradetime/40.0)*10),12+(sin(gpg1ogradetime/40.0)*10),255,255,255,255-int(gpg1ogradetime),0,0,36);
			if (strcmp(gpg1ograde,"Miss")==0)
				draw_quad(0,713+goffset,700,3530,45+(cos(gpg1ggradetime/40.0)*10),12+(sin(gpg1ogradetime/40.0)*10),255,255,255,255-int(gpg1ogradetime),0,0,37);
			draw_quad(0,720+goffset,10,3500,100,32,255,255,255,255,0,0,32);
			if (gpg1lifebar<100){
				draw_quad(0,640+goffset,64+int((3.2f*double(gpg1lifebar))),3520,10,int(3.2f*double(gpg1lifebar)),255-int(2.55*gpg1lifebar),int(2.55*gpg1lifebar),0,int(cos(lifestep/128.0)*63)+191,0,0,51);
			}else{
				draw_quad(0,640+goffset,64+int((3.2f*double(gpg1lifebar))),3520,10,int(3.2f*double(gpg1lifebar)),255,255,0,int(cos(lifestep/128.0)*63)+191,0,0,51);
			}		
			draw_quad(0,640+goffset,374,3600,20,350,255,255,255,255,0,0,31);
			if (g11expc==0)
				draw_quad3(0,666+goffset,680,4500,100,100,255,255,128,int(g11expt),0,0,52);
			if (g11expc==1)
				draw_quad3(0,666+goffset,680,4500,100,100,64,255,64,int(g11expt),0,0,52);
			if (g11expc==2)
				draw_quad3(0,666+goffset,680,4500,100,100,64,64,255,int(g11expt),0,0,52);
			if (g11expc==3)
				draw_quad3(0,666+goffset,680,4500,100,100,255,0,255,int(g11expt),0,0,52);
			if (g12expc==0)
				draw_quad3(0,713+goffset,680,4600,100,100,255,255,128,int(g12expt),0,0,52);
			if (g12expc==1)
				draw_quad3(0,713+goffset,680,4600,100,100,64,255,64,int(g12expt),0,0,52);
			if (g12expc==2)
				draw_quad3(0,713+goffset,680,4600,100,100,64,64,255,int(g12expt),0,0,52);
			if (g12expc==3)
				draw_quad3(0,713+goffset,680,4600,100,100,255,0,255,int(g12expt),0,0,52);
			if (g13expc==0)
				draw_quad3(0,760+goffset,680,4700,100,100,255,255,128,int(g13expt),0,0,52);
			if (g13expc==1)
				draw_quad3(0,760+goffset,680,4700,100,100,64,255,64,int(g13expt),0,0,52);
			if (g13expc==2)
				draw_quad3(0,760+goffset,680,4700,100,100,64,64,255,int(g13expt),0,0,52);
			if (g13expc==3)
				draw_quad3(0,760+goffset,680,4700,100,100,255,0,255,int(g13expt),0,0,52);
			if (gpg1currcombo>10){
				sprintf(thetime, "%i", gpg1currcombo);
				draw_number(thetime,goffset+666,140,5000,30,255,255,255);
				sprintf(thetime, "combo");
				draw_number(thetime,goffset+666,190,5000,30,255,255,255);
			}	
			sprintf(thetime, "%i", gpg1score);
			draw_number(thetime,goffset+653,14,7500,20);
		}
		//g2
		if (guitar2mode){
			if (strcmp(gpg2rgrade,"Perfect")==0)
				draw_quad(0,666+goffset+g2offset,740,5000,45+(cos(gpg2rgradetime/40.0)*10),12+(sin(gpg2rgradetime/40.0)*10),255,255,255,255-int(gpg2rgradetime),0,45,33);
			if (strcmp(gpg2ggrade,"Perfect")==0)
				draw_quad(0,713+goffset+g2offset,740,5000,45+(cos(gpg2ggradetime/40.0)*10),12+(sin(gpg2ggradetime/40.0)*10),255,255,255,255-int(gpg2ggradetime),0,45,33);
			if (strcmp(gpg2bgrade,"Perfect")==0)
				draw_quad(0,760+goffset+g2offset,740,5000,45+(cos(gpg2bgradetime/40.0)*10),12+(sin(gpg2bgradetime/40.0)*10),255,255,255,255-int(gpg2bgradetime),0,45,33);
			if (strcmp(gpg2rgrade,"Great")==0)
				draw_quad(0,666+goffset+g2offset,740,5000,45+(cos(gpg2rgradetime/40.0)*10),12+(sin(gpg2rgradetime/40.0)*10),255,255,255,255-int(gpg2rgradetime),0,45,34);
			if (strcmp(gpg2ggrade,"Great")==0)
				draw_quad(0,713+goffset+g2offset,740,5000,45+(cos(gpg2ggradetime/40.0)*10),12+(sin(gpg2ggradetime/40.0)*10),255,255,255,255-int(gpg2ggradetime),0,45,34);
			if (strcmp(gpg2bgrade,"Great")==0)
				draw_quad(0,760+goffset+g2offset,740,5000,45+(cos(gpg2bgradetime/40.0)*10),12+(sin(gpg2bgradetime/40.0)*10),255,255,255,255-int(gpg2bgradetime),0,45,34);
			if (strcmp(gpg2rgrade,"Good")==0)
				draw_quad(0,666+goffset+g2offset,740,5000,45+(cos(gpg2rgradetime/40.0)*10),12+(sin(gpg2rgradetime/40.0)*10),255,255,255,255-int(gpg2rgradetime),0,45,35);
			if (strcmp(gpg2ggrade,"Good")==0)
				draw_quad(0,713+goffset+g2offset,740,5000,45+(cos(gpg2ggradetime/40.0)*10),12+(sin(gpg2ggradetime/40.0)*10),255,255,255,255-int(gpg2ggradetime),0,45,35);
			if (strcmp(gpg2bgrade,"Good")==0)
				draw_quad(0,760+goffset+g2offset,740,5000,45+(cos(gpg2bgradetime/40.0)*10),12+(sin(gpg2bgradetime/40.0)*10),255,255,255,255-int(gpg2bgradetime),0,45,35);
			if (strcmp(gpg2rgrade,"Almost")==0)
				draw_quad(0,666+goffset+g2offset,740,5000,45+(cos(gpg2rgradetime/40.0)*10),12+(sin(gpg2rgradetime/40.0)*10),255,255,255,255-int(gpg2rgradetime),0,45,36);
			if (strcmp(gpg2ggrade,"Almost")==0)
				draw_quad(0,713+goffset+g2offset,740,5000,45+(cos(gpg2ggradetime/40.0)*10),12+(sin(gpg2ggradetime/40.0)*10),255,255,255,255-int(gpg2ggradetime),0,45,36);
			if (strcmp(gpg2bgrade,"Almost")==0)
				draw_quad(0,760+goffset+g2offset,740,5000,45+(cos(gpg2bgradetime/40.0)*10),12+(sin(gpg2bgradetime/40.0)*10),255,255,255,255-int(gpg2bgradetime),0,45,36);
			if (strcmp(gpg2rgrade,"Miss")==0)
				draw_quad(0,666+goffset+g2offset,740,5000,45+(cos(gpg2rgradetime/40.0)*10),12+(sin(gpg2rgradetime/40.0)*10),255,255,255,255-int(gpg2rgradetime),0,45,37);
			if (strcmp(gpg2ggrade,"Miss")==0)
				draw_quad(0,713+goffset+g2offset,740,5000,45+(cos(gpg2ggradetime/40.0)*10),12+(sin(gpg2ggradetime/40.0)*10),255,255,255,255-int(gpg2ggradetime),0,45,37);
			if (strcmp(gpg2bgrade,"Miss")==0)
				draw_quad(0,760+goffset+g2offset,740,5000,45+(cos(gpg2bgradetime/40.0)*10),12+(sin(gpg2bgradetime/40.0)*10),255,255,255,255-int(gpg2bgradetime),0,45,37);
			draw_quad(0,720+goffset+g2offset,10,6810,100,32,255,255,255,255,0,0,32);
			if (gpg2lifebar<100){
				draw_quad(0,640+goffset+g2offset,64+int((3.2f*double(gpg2lifebar))),6820,10,int(3.2f*double(gpg2lifebar)),255-int(2.55*gpg2lifebar),int(2.55*gpg2lifebar),0,int(cos(lifestep/128.0)*63)+191,0,0,51);
			}else{
				draw_quad(0,640+goffset+g2offset,64+int((3.2f*double(gpg2lifebar))),6820,10,int(3.2f*double(gpg2lifebar)),255,255,0,int(cos(lifestep/128.0)*63)+191,0,0,51);
			}

			draw_quad(0,640+goffset+g2offset,374,6900,20,350,255,255,255,255,0,0,31);
			if (g21expc==0)
				draw_quad3(0,666+goffset+g2offset,680,7000,100,100,255,255,128,int(g21expt),0,0,52);
			if (g21expc==1)
				draw_quad3(0,666+goffset+g2offset,680,7000,100,100,64,255,64,int(g21expt),0,0,52);
			if (g21expc==2)
				draw_quad3(0,666+goffset+g2offset,680,7000,100,100,64,64,255,int(g21expt),0,0,52);
			if (g21expc==3)
				draw_quad3(0,666+goffset+g2offset,680,7000,100,100,255,0,255,int(g21expt),0,0,52);
			if (g22expc==0)
				draw_quad3(0,713+goffset+g2offset,680,7200,100,100,255,255,128,int(g22expt),0,0,52);
			if (g22expc==1)
				draw_quad3(0,713+goffset+g2offset,680,7200,100,100,64,255,64,int(g22expt),0,0,52);
			if (g22expc==2)
				draw_quad3(0,713+goffset+g2offset,680,7200,100,100,64,64,255,int(g22expt),0,0,52);
			if (g22expc==3)
				draw_quad3(0,713+goffset+g2offset,680,7200,100,100,255,0,255,int(g22expt),0,0,52);
			if (g23expc==0)
				draw_quad3(0,760+goffset+g2offset,680,7300,100,100,255,255,128,int(g23expt),0,0,52);
			if (g23expc==1)
				draw_quad3(0,760+goffset+g2offset,680,7300,100,100,64,255,64,int(g23expt),0,0,52);
			if (g23expc==2)
				draw_quad3(0,760+goffset+g2offset,680,7300,100,100,64,64,255,int(g23expt),0,0,52);
			if (g23expc==3)
				draw_quad3(0,760+goffset+g2offset,680,7300,100,100,255,0,255,int(g23expt),0,0,52);
			if (gpg2currcombo>10){
				sprintf(thetime, "%i", gpg2currcombo);
				draw_number(thetime,goffset+g2offset+666,140,8100,30,255,255,255);
				sprintf(thetime, "combo");
				draw_number(thetime,goffset+g2offset+666,190,8100,30,255,255,255);
			}						
			sprintf(thetime, "%i", gpg2score);
			draw_number(thetime,goffset+g2offset+653,14,8000,20);
		}
	}	
	if (drummode){
		draw_quad_g(0,87+offset,416,-100,22,334,0,255,255,int(sin(hihatani/100.0)*128),0,0,51);
		draw_quad_g(0,134+offset,416,-100,22,334,255,255,0,int(sin(snareani/100.0)*128),0,0,51);
		draw_quad_g(0,181+offset,416,-100,22,334,255,0,255,int(sin(bassani/100.0)*128),0,0,51);
		draw_quad_g(0,228+offset,416,-100,22,334,128,255,0,int(sin(hitomani/100.0)*128),0,0,51);
		draw_quad_g(0,275+offset,416,-100,22,334,255,0,0,int(sin(lotomani/100.0)*128),0,0,51);
		draw_quad_g(0,322+offset,416,-100,22,334,0,0,255,int(sin(cymbalani/100.0)*128),0,0,51);
		draw_quad(0,206+offset,416,2000,142,335,255,255,255,255,0,0,22);
		draw_quad(0,230+offset,54-int(sin(hitomani/100.0)*25),2700,40,27,255,255,255,255,0,0,25);
		draw_quad(0,130+offset,55-int(sin(snareani/100.0)*25),2800,40,25,255,255,255,255,0,0,24);
		draw_quad(0,280+offset,54-int(sin(lotomani/100.0)*25),2850,40,27,255,255,255,255,0,0,26);
		draw_quad(0,180+offset,51-int(sin(bassani/100.0)*25),2900,29,33,255,255,255,255,0,0,29);
		draw_quad(0,80+offset,55-int(sin(hihatani/100.0)*25),3050,37,25,255,255,255,255,0,0,23);
		draw_quad(0,330+offset,55-int(sin(cymbalani/100.0)*25),3000,37,25,255,255,255,255,0,0,27);

		if (strcmp(gphhgrade,"Perfect")==0)
		draw_quad(0,70+offset,50,4000,45+(cos(gphhgradetime/40.0)*10),12+(sin(gphhgradetime/40.0)*10),255,255,255,255-int(gphhgradetime),0,0,33);
		if (strcmp(gphhgrade,"Great")==0)
		draw_quad(0,70+offset,50,4000,45+(cos(gphhgradetime/40.0)*10),12+(sin(gphhgradetime/40.0)*10),255,255,255,255-int(gphhgradetime),0,0,34);
		if (strcmp(gphhgrade,"Good")==0)
		draw_quad(0,70+offset,50,4000,45+(cos(gphhgradetime/40.0)*10),12+(sin(gphhgradetime/40.0)*10),255,255,255,255-int(gphhgradetime),0,0,35);
		if (strcmp(gphhgrade,"Almost")==0)
		draw_quad(0,70+offset,50,4000,45+(cos(gphhgradetime/40.0)*10),12+(sin(gphhgradetime/40.0)*10),255,255,255,255-int(gphhgradetime),0,0,36);
		if (strcmp(gphhgrade,"Miss")==0)
		draw_quad(0,70+offset,50,4000,45+(cos(gphhgradetime/40.0)*10),12+(sin(gphhgradetime/40.0)*10),255,255,255,255-int(gphhgradetime),0,0,37);
		if (strcmp(gpsdgrade,"Perfect")==0)
		draw_quad(0,120+offset,20,4010,45+(cos(gpsdgradetime/40.0)*10),12+(sin(gpsdgradetime/40.0)*10),255,255,255,255-int(gpsdgradetime),0,0,33);
		if (strcmp(gpsdgrade,"Great")==0)
		draw_quad(0,120+offset,20,4010,45+(cos(gpsdgradetime/40.0)*10),12+(sin(gpsdgradetime/40.0)*10),255,255,255,255-int(gpsdgradetime),0,0,34);
		if (strcmp(gpsdgrade,"Good")==0)
		draw_quad(0,120+offset,20,4000,45+(cos(gpsdgradetime/40.0)*10),12+(sin(gpsdgradetime/40.0)*10),255,255,255,255-int(gpsdgradetime),0,0,35);
		if (strcmp(gpsdgrade,"Almost")==0)
		draw_quad(0,120+offset,20,4010,45+(cos(gpsdgradetime/40.0)*10),12+(sin(gpsdgradetime/40.0)*10),255,255,255,255-int(gpsdgradetime),0,0,36);
		if (strcmp(gpsdgrade,"Miss")==0)
		draw_quad(0,120+offset,20,4010,45+(cos(gpsdgradetime/40.0)*10),12+(sin(gpsdgradetime/40.0)*10),255,255,255,255-int(gpsdgradetime),0,0,37);
		if (strcmp(gpbdgrade,"Perfect")==0)
		draw_quad(0,170+offset,50,4020,45+(cos(gpbdgradetime/40.0)*10),12+(sin(gpbdgradetime/40.0)*10),255,255,255,255-int(gpbdgradetime),0,0,33);
		if (strcmp(gpbdgrade,"Great")==0)
		draw_quad(0,170+offset,50,4020,45+(cos(gpbdgradetime/40.0)*10),12+(sin(gpbdgradetime/40.0)*10),255,255,255,255-int(gpbdgradetime),0,0,34);
		if (strcmp(gpbdgrade,"Good")==0)
		draw_quad(0,170+offset,50,4020,45+(cos(gpbdgradetime/40.0)*10),12+(sin(gpbdgradetime/40.0)*10),255,255,255,255-int(gpbdgradetime),0,0,35);
		if (strcmp(gpbdgrade,"Almost")==0)
		draw_quad(0,170+offset,50,4020,45+(cos(gpbdgradetime/40.0)*10),12+(sin(gpbdgradetime/40.0)*10),255,255,255,255-int(gpbdgradetime),0,0,36);
		if (strcmp(gpbdgrade,"Miss")==0)
		draw_quad(0,170+offset,50,4020,45+(cos(gpbdgradetime/40.0)*10),12+(sin(gpbdgradetime/40.0)*10),255,255,255,255-int(gpbdgradetime),0,0,37);
		if (strcmp(gphtgrade,"Perfect")==0)
		draw_quad(0,220+offset,20,4030,45+(cos(gphtgradetime/40.0)*10),12+(sin(gphtgradetime/40.0)*10),255,255,255,255-int(gphtgradetime),0,0,33);
		if (strcmp(gphtgrade,"Great")==0)
		draw_quad(0,220+offset,20,4030,45+(cos(gphtgradetime/40.0)*10),12+(sin(gphtgradetime/40.0)*10),255,255,255,255-int(gphtgradetime),0,0,34);
		if (strcmp(gphtgrade,"Good")==0)
		draw_quad(0,220+offset,20,4030,45+(cos(gphtgradetime/40.0)*10),12+(sin(gphtgradetime/40.0)*10),255,255,255,255-int(gphtgradetime),0,0,35);
		if (strcmp(gphtgrade,"Almost")==0)
		draw_quad(0,220+offset,20,4030,45+(cos(gphtgradetime/40.0)*10),12+(sin(gphtgradetime/40.0)*10),255,255,255,255-int(gphtgradetime),0,0,36);
		if (strcmp(gphtgrade,"Miss")==0)
		draw_quad(0,220+offset,20,4030,45+(cos(gphtgradetime/40.0)*10),12+(sin(gphtgradetime/40.0)*10),255,255,255,255-int(gphtgradetime),0,0,37);
		if (strcmp(gpltgrade,"Perfect")==0)
		draw_quad(0,270+offset,50,4040,45+(cos(gpltgradetime/40.0)*10),12+(sin(gpltgradetime/40.0)*10),255,255,255,255-int(gpltgradetime),0,0,33);
		if (strcmp(gpltgrade,"Great")==0)
		draw_quad(0,270+offset,50,4040,45+(cos(gpltgradetime/40.0)*10),12+(sin(gpltgradetime/40.0)*10),255,255,255,255-int(gpltgradetime),0,0,34);
		if (strcmp(gpltgrade,"Good")==0)
		draw_quad(0,270+offset,50,4040,45+(cos(gpltgradetime/40.0)*10),12+(sin(gpltgradetime/40.0)*10),255,255,255,255-int(gpltgradetime),0,0,35);
		if (strcmp(gpltgrade,"Almost")==0)
		draw_quad(0,270+offset,50,4040,45+(cos(gpltgradetime/40.0)*10),12+(sin(gpltgradetime/40.0)*10),255,255,255,255-int(gpltgradetime),0,0,36);
		if (strcmp(gpltgrade,"Miss")==0)
		draw_quad(0,270+offset,50,4040,45+(cos(gpltgradetime/40.0)*10),12+(sin(gpltgradetime/40.0)*10),255,255,255,255-int(gpltgradetime),0,0,37);
		if (strcmp(gpcygrade,"Perfect")==0)
		draw_quad(0,320+offset,20,4050,45+(cos(gpcygradetime/40.0)*10),12+(sin(gpcygradetime/40.0)*10),255,255,255,255-int(gpcygradetime),0,0,33);
		if (strcmp(gpcygrade,"Great")==0)
		draw_quad(0,320+offset,20,4050,45+(cos(gpcygradetime/40.0)*10),12+(sin(gpcygradetime/40.0)*10),255,255,255,255-int(gpcygradetime),0,0,34);
		if (strcmp(gpcygrade,"Good")==0)
		draw_quad(0,320+offset,20,4050,45+(cos(gpcygradetime/40.0)*10),12+(sin(gpcygradetime/40.0)*10),255,255,255,255-int(gpcygradetime),0,0,35);
		if (strcmp(gpcygrade,"Almost")==0)
		draw_quad(0,320+offset,20,4050,45+(cos(gpcygradetime/40.0)*10),12+(sin(gpcygradetime/40.0)*10),255,255,255,255-int(gpcygradetime),0,0,36);
		if (strcmp(gpcygrade,"Miss")==0)
		draw_quad(0,320+offset,20,4050,45+(cos(gpcygradetime/40.0)*10),12+(sin(gpcygradetime/40.0)*10),255,255,255,255-int(gpcygradetime),0,0,37);
		draw_quad(0,210+offset,742,4000,162,32,255,255,255,255,0,0,32);
		draw_quad(0,45+offset,420,4010,10,320,0,0,0,255,0,0,0);
		if (gplifebar<100){
			draw_quad(0,45+offset,100+int((3.2f*double(gplifebar))),4020,10,int(3.2f*double(gplifebar)),255-int(2.55*gplifebar),int(2.55*gplifebar),0,int(cos(lifestep/128.0)*63)+191,0,0,51);
		}else{
			draw_quad(0,45+offset,100+int((3.2f*double(gplifebar))),4020,10,int(3.2f*double(gplifebar)),255,255,0,int(cos(lifestep/128.0)*63)+191,0,0,51);
		}
		draw_quad(0,45+offset,410,4100,37,350,255,255,255,255,0,0,31);
		//drum note explosions
		//87,134,181,228,275,322
		if (d1expc==0)
			draw_quad3(0,87+offset,85,7000,100,100,255,255,128,int(d1expt),0,int(d1expt/2),52);
		if (d1expc==1)
			draw_quad3(0,87+offset,85,7000,100,100,64,255,64,int(d1expt),0,int(d1expt/2),52);
		if (d1expc==2)
			draw_quad3(0,87+offset,85,7000,100,100,64,64,255,int(d1expt),0,int(d1expt/2),52);
		if (d1expc==3)
			draw_quad3(0,87+offset,85,7000,100,100,255,0,255,int(d1expt),0,int(d1expt/2),52);
		if (d2expc==0)
			draw_quad3(0,134+offset,85,7100,100,100,255,255,128,int(d2expt),0,int(d2expt/2),52);
		if (d2expc==1)
			draw_quad3(0,134+offset,85,7100,100,100,64,255,64,int(d2expt),0,int(d2expt/2),52);
		if (d2expc==2)
			draw_quad3(0,134+offset,85,7100,100,100,64,64,255,int(d2expt),0,int(d2expt/2),52);
		if (d2expc==3)
			draw_quad3(0,134+offset,85,7100,100,100,255,0,255,int(d2expt),0,int(d2expt/2),52);
		if (d3expc==0)
			draw_quad3(0,181+offset,85,7200,100,100,255,255,128,int(d3expt),0,int(d3expt/2),52);
		if (d3expc==1)
			draw_quad3(0,181+offset,85,7200,100,100,64,255,64,int(d3expt),0,int(d3expt/2),52);
		if (d3expc==2)
			draw_quad3(0,181+offset,85,7200,100,100,64,64,255,int(d3expt),0,int(d3expt/2),52);
		if (d3expc==3)
			draw_quad3(0,181+offset,85,7200,100,100,255,0,255,int(d3expt),0,int(d3expt/2),52);
		if (d4expc==0)
			draw_quad3(0,228+offset,85,7300,100,100,255,255,128,int(d4expt),0,int(d4expt/2),52);
		if (d4expc==1)
			draw_quad3(0,228+offset,85,7300,100,100,64,255,64,int(d4expt),0,int(d4expt/2),52);
		if (d4expc==2)
			draw_quad3(0,228+offset,85,7300,100,100,64,64,255,int(d4expt),0,int(d4expt/2),52);
		if (d4expc==3)
			draw_quad3(0,228+offset,85,7300,100,100,255,0,255,int(d4expt),0,int(d4expt/2),52);
		if (d5expc==0)
			draw_quad3(0,275+offset,85,7400,100,100,255,255,128,int(d5expt),0,int(d5expt/2),52);
		if (d5expc==1)
			draw_quad3(0,275+offset,85,7400,100,100,64,255,64,int(d5expt),0,int(d5expt/2),52);
		if (d5expc==2)
			draw_quad3(0,275+offset,85,7400,100,100,64,64,255,int(d5expt),0,int(d5expt/2),52);
		if (d5expc==3)
			draw_quad3(0,275+offset,85,7400,100,100,255,0,255,int(d5expt),0,int(d5expt/2),52);
		if (d6expc==0)
			draw_quad3(0,322+offset,85,7500,100,100,255,255,128,int(d6expt),0,int(d6expt/2),52);
		if (d6expc==1)
			draw_quad3(0,322+offset,85,7500,100,100,64,255,64,int(d6expt),0,int(d6expt/2),52);
		if (d6expc==2)
			draw_quad3(0,322+offset,85,7500,100,100,64,64,255,int(d6expt),0,int(d6expt/2),52);
		if (d6expc==3)
			draw_quad3(0,322+offset,85,7500,100,100,255,0,255,int(d6expt),0,int(d6expt/2),52);
		sprintf(thetime, "%i", gpscore);
		draw_number(thetime,offset+100,747,8000,20);
		if (gpcurrcombo>10){
			sprintf(thetime, "%icombo", gpcurrcombo);
			draw_number(thetime,offset+80,650,8000,30,255,255,255);
		}
	}
	if (drummode&&(!guitar1mode&&!guitar2mode)){
		if (gpavi.isloaded()&&strcmp(curravi,"NULL")!=0){
			gpavi.drawavi(uivars.game_vidd_x,uivars.game_vidd_y,8000,274,354);
		}else{
			draw_quadt2(0,uivars.game_vidd_x,uivars.game_vidd_y,8000,274,352,255,255,255,255,0,0,previewtexture);
		}
	}
	if (!drummode&&(guitar1mode||guitar2mode)){
		if (gpavi.isloaded()){
			gpavi.drawavi(uivars.game_vidg_x,uivars.game_vidg_y,8000,274,354);
		}else{
			draw_quadt2(0,uivars.game_vidg_x,uivars.game_vidg_y,8000,274,352,255,255,255,255,0,0,previewtexture);
		}
	}
	if (drummode&&(guitar1mode||guitar2mode)){
		if(widemode){
			if (gpavi.isloaded()){
				gpavi.drawavi(uivars.game_viddgw_x,uivars.game_viddgw_y,8000,274,354);
			}else{
				draw_quadt2 ( 0, uivars.game_viddgw_x,uivars.game_viddgw_y,8000,274,352,255,255,255,255,0,0,previewtexture);
			}
		}else{
			if (gpavi.isloaded()){
				gpavi.drawavi(uivars.game_viddg_x,uivars.game_viddg_y,8000,135,177);
			}else{
				draw_quadt2( 0, uivars.game_viddg_x,uivars.game_viddg_y,8000,135,177,255,255,255,255,0,0,previewtexture);
			}
		}
	}
	animateexps();
	//OSD for song info.
	static char OSD[5][128];
	static drawtext OSDTEXT[5];
	int diff1=0;int diff2=0;int diff3=0;
	if (drumdiff==0){diff1=songs[thesong].drumbasdiff;}
	if (drumdiff==1){diff1=songs[thesong].drumadvdiff;}
	if (drumdiff==2){diff1=songs[thesong].drumextdiff;}
	if (guitar1treb){
	if (guit1diff==0){diff2=songs[thesong].guitbasdiff;}
	if (guit1diff==1){diff2=songs[thesong].guitadvdiff;}
	if (guit1diff==2){diff2=songs[thesong].guitextdiff;}
	}else{
	if (guit1diff==0){diff2=songs[thesong].guitbbasdiff;}
	if (guit1diff==1){diff2=songs[thesong].guitbadvdiff;}
	if (guit1diff==2){diff2=songs[thesong].guitbextdiff;}
	}
	if (guitar2treb){
	if (guit2diff==0){diff3=songs[thesong].guitbasdiff;}
	if (guit2diff==1){diff3=songs[thesong].guitadvdiff;}
	if (guit2diff==2){diff3=songs[thesong].guitextdiff;}
	}else{
	if (guit2diff==0){diff3=songs[thesong].guitbbasdiff;}
	if (guit2diff==1){diff3=songs[thesong].guitbadvdiff;}
	if (guit2diff==2){diff3=songs[thesong].guitbextdiff;}
	}
	if (currscreen!=prevscreen){
    	sprintf(OSD[0], "%s", songs[thesong].title);
    	sprintf(OSD[1], "Artist: %s", songs[thesong].artist);
    	sprintf(OSD[2], "Genre: %s", songs[thesong].artist);
    	sprintf(OSD[3], "Difficulty: %i/%i/%i", diff1,diff2,diff3);
    	sprintf(OSD[4], "BPM: %i", songs[thesong].bpm);
    	char duh1[15];
    	if (guitar1treb)sprintf(duh1, "G1:treble");
    	else sprintf(duh1, "G1:bass");
    	char duh2[15];
    	if (guitar1treb)sprintf(duh2, "G2:treble");
    	else sprintf(duh1, "G2:bass");
    	if (!guitar1mode)sprintf(duh1, "");
    	if (!guitar2mode)sprintf(duh2, "");
    	char duh3[15];
    	if (stages>0)
    		sprintf(duh3, "Stage:%i/%i", currstage,stages);
    	else
    		sprintf(duh3, "Stage:%i", currstage);
    	for (int a=0;a<5;a++){
    		OSDTEXT[a].load(OSD[a],"unicode.ttf",255,255,255,24);
    	}
    }
	static int OSDTime;
	OSDTime+=steptime/2;
	if (OSDTime>=5000)OSDTime=0;
	int alpha=abs(int(255.0* sin( double(OSDTime)/(1000.0/M_PI) ))) ;
	if (drummode&&(!guitar1mode&&!guitar2mode)){
		OSDTEXT[int(OSDTime/1000)].draw(uivars.game_vidd_x,uivars.game_vidd_y-380,8000,alpha,255,255,255,false,true,true);
	}
	if (!drummode&&(guitar1mode||guitar2mode)){
		OSDTEXT[int(OSDTime/1000)].draw(uivars.game_vidg_x,uivars.game_vidg_y-380,8000,alpha,255,255,255,false,true,true);
	}
	if (drummode&&(guitar1mode||guitar2mode)){
		if(widemode){
			OSDTEXT[int(OSDTime/1000)].draw(uivars.game_viddgw_x,uivars.game_viddgw_y-380,8000,alpha,255,255,255,false,true,true);
		}else{
			OSDTEXT[int(OSDTime/1000)].draw(uivars.game_viddg_x,uivars.game_viddg_y-380,8000,alpha,255,255,255,false,true,true);
		}
	}
	//death animation
	static double hstep=0;
	hstep+=2.0*(double(steptime)/16.0);
	if (hstep>230.0){
		hstep-=230.0;
	}
	if (drummode&&(!guitar1mode&&!guitar2mode)){
		draw_drum_table(uivars.game_drumonlymod_x,uivars.game_drumonlymod_y);		
	}
	if (!drummode){
		if (guitar1mode){
			draw_guit1_table(uivars.game_guit1onlymod_x,uivars.game_guit1onlymod_y);
		}
		if (guitar2mode){
			draw_guit2_table(uivars.game_guit2onlymod_x,uivars.game_guit2onlymod_y);
		}
	}
	if (drummode&&(guitar1mode||guitar2mode)){
		if(widemode){
			draw_drum_table(uivars.game_drumwidemod_x,uivars.game_drumwidemod_y);
			if (guitar1mode){
				draw_guit1_table(uivars.game_guit1widemod_x,uivars.game_guit1widemod_y);
			}
			if (guitar2mode){
				draw_guit2_table(uivars.game_guit2widemod_x,uivars.game_guit2widemod_y);
			}
		}else{
			draw_drum_table(uivars.game_drummod_x,uivars.game_drummod_y);
			if (guitar1mode){
				draw_guit1_table(uivars.game_guit1mod_x,uivars.game_guit1mod_y);
			}
			if (guitar2mode){
				draw_guit2_table(uivars.game_guit2mod_x,uivars.game_guit2mod_y);
			}
		}
	}
	int b=0;
    int lifeaverage=0;
	if (drummode){lifeaverage+=int(gplifebar);b++;}
	if (guitar1mode){lifeaverage+=int(gpg1lifebar);b++;}
	if (guitar2mode){lifeaverage+=int(gpg2lifebar);b++;}
	if (b!=0)lifeaverage=int(double(lifeaverage)/double(b));
	if (lifeaverage<20){
		if (lifeaverage<0)lifeaverage=0;
		draw_quad(0,512,384,8005,640,400,255,255,255,200-lifeaverage*10,0,0,64);
		for(int a=-230;a<998;a+=230){
			draw_quad(0,23,int(a+hstep),8010,115,30,255,255,255,240-lifeaverage*12,0,90,63);
		}
		for(int a=998;a>-230;a-=230){
			draw_quad(0,1001,int(a-hstep),8010,115,30,255,255,255,240-lifeaverage*12,0,-90,63);
		}
	}
	//the rest.
	int anispeed=int(60.0*double(steptime)/16.0);
	if (hitomani>1){
		hitomani+=anispeed;
		if (hitomani>314){
			hitomani=1;
		}
	}
	if (lotomani>1){
		lotomani+=anispeed;
		if (lotomani>314){
			lotomani=1;
		}
	}
	if (bassani>1){
		bassani+=anispeed;
		if (bassani>314){
			bassani=1;
		}
	}
	if (snareani>1){
		snareani+=anispeed;
		if (snareani>314){
			snareani=1;
		}
	}
	if (cymbalani>1){
		cymbalani+=anispeed;
		if (cymbalani>314){
			cymbalani=1;
		}
	}
	if (hihatani>1){
		hihatani+=anispeed;
		if (hihatani>314){
			hihatani=1;
		}
	}
}
