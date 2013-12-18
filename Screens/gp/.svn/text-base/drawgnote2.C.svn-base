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
void draw_gnote2(int a){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("draw_gnote2\n");
	#endif
	#endif
	if (guitar1mode&&guit1diff==2){
		//Guitar1:
		//red:666
		//green:713
		//blue:760
		int blah=int(679.0+(-(double(songs[thesong].extnotemeas[a])*100.0)-(double(songs[thesong].extnotetime[a])/100.0))*(double((double(guitar1notespeed)/double(notebpm/150.0)))/3.0)+((double(songpositiondraw)+(double(songs[thesong].offset)*500.0))/2400.0)*(double((double(guitar1notespeed)/double(notebpm/150.0)))/3.0));
		int alpha=255;
		if (guit1fademode==2){
			alpha=blah/2-128;
			if (alpha>255)alpha=255;
			if (alpha<0)alpha=0;
		}
		if (guit1fademode==1){
			alpha=blah/2;
			if (alpha>255)alpha=255;
			if (alpha<0)alpha=0;
			alpha=255-alpha;
		}
		if (guit1fademode==3){
			alpha=int(blah/1.5)-256;
			alpha=255-abs(int(alpha*1.5));
			if (alpha<0)
				alpha=0;
		}
		int spin=0;
		if (guit1spin){
			spin=blah+89;	
		}			
		if (blah>0&&blah<768){
			if (guitar1treb){	
				if (strcmp(songs[thesong].extnotetype[a],"20")==0||strcmp(songs[thesong].extnotetype[a],"g0")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,713+goffset,blah,-50+a,66,39,255,255,255,alpha,0,spin,58);
				}
				if (strcmp(songs[thesong].extnotetype[a],"21")==0||strcmp(songs[thesong].extnotetype[a],"g1")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,760+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
				if (strcmp(songs[thesong].extnotetype[a],"22")==0||strcmp(songs[thesong].extnotetype[a],"g2")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,713+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
				}
				if (strcmp(songs[thesong].extnotetype[a],"23")==0||strcmp(songs[thesong].extnotetype[a],"g3")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,713+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,760+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
				if (strcmp(songs[thesong].extnotetype[a],"24")==0||strcmp(songs[thesong].extnotetype[a],"g4")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,666+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
				}
				if (strcmp(songs[thesong].extnotetype[a],"25")==0||strcmp(songs[thesong].extnotetype[a],"g5")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,666+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,760+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
				if (strcmp(songs[thesong].extnotetype[a],"26")==0||strcmp(songs[thesong].extnotetype[a],"g6")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,713+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,666+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
				}
				if (strcmp(songs[thesong].extnotetype[a],"27")==0||strcmp(songs[thesong].extnotetype[a],"g7")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,760+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,666+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,713+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
				}
				if (strcmp(songs[thesong].extnotetype[a],"28")==0||strcmp(songs[thesong].extnotetype[a],"gw")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,792+goffset,blah,-50+a,8,20,255,255,255,alpha,0,spin,42);
				}
			}else{
				if (strcmp(songs[thesong].extnotetype[a],"a0")==0||strcmp(songs[thesong].extnotetype[a],"b0")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,713+goffset,blah,-50+a,66,3,255,255,255,alpha,0,spin,58);				
				}
				if (strcmp(songs[thesong].extnotetype[a],"a1")==0||strcmp(songs[thesong].extnotetype[a],"b1")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,760+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
				if (strcmp(songs[thesong].extnotetype[a],"a2")==0||strcmp(songs[thesong].extnotetype[a],"b2")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,713+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
				}
				if (strcmp(songs[thesong].extnotetype[a],"a3")==0||strcmp(songs[thesong].extnotetype[a],"b3")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,713+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,760+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
				if (strcmp(songs[thesong].extnotetype[a],"a4")==0||strcmp(songs[thesong].extnotetype[a],"b4")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,666+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
				}
				if (strcmp(songs[thesong].extnotetype[a],"a5")==0||strcmp(songs[thesong].extnotetype[a],"b5")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,666+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,760+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
				if (strcmp(songs[thesong].extnotetype[a],"a6")==0||strcmp(songs[thesong].extnotetype[a],"b6")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,713+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,666+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
				}
				if (strcmp(songs[thesong].extnotetype[a],"a7")==0||strcmp(songs[thesong].extnotetype[a],"b7")==0){
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,760+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,666+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
					if (!songs[thesong].g1extnoteplayed[a])draw_quad(0,713+goffset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
				}
				if (strcmp(songs[thesong].extnotetype[a],"a8")==0||strcmp(songs[thesong].extnotetype[a],"bw")==0){
					draw_quad(0,792+goffset,blah,-50+a,8,20,255,255,255,alpha,0,spin,42);
				}
			}
		}
	}
	if (guitar2mode&&guit2diff==2){
		//Guitar1:
		//red:666
		//green:713
		//blue:760
		int blah=int(679.0+(-(double(songs[thesong].extnotemeas[a])*100.0)-(double(songs[thesong].extnotetime[a])/100.0))*(double((double(guitar2notespeed)/double(notebpm/150.0)))/3.0)+((double(songpositiondraw)+(double(songs[thesong].offset)*500.0))/2400.0)*(double((double(guitar2notespeed)/double(notebpm/150.0)))/3.0));
		int alpha=255;
		if (guit2fademode==2){
			alpha=blah/2-128;
			if (alpha>255)alpha=255;
			if (alpha<0)alpha=0;
		}
		if (guit2fademode==1){
			alpha=blah/2;
			if (alpha>255)alpha=255;
			if (alpha<0)alpha=0;
			alpha=255-alpha;
		}
		if (guit2fademode==3){
			alpha=int(blah/1.5)-256;
			alpha=255-abs(int(alpha*1.5));
			if (alpha<0)
				alpha=0;
		}
		int spin=0;
		if (guit2spin){
			spin=blah+89;	
		}			
		if (blah>0&&blah<768){
			if (guitar2treb){
				if (strcmp(songs[thesong].extnotetype2[a],"20")==0||strcmp(songs[thesong].extnotetype2[a],"g0")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,713+goffset+g2offset,blah,-50+a,66,39,255,255,255,alpha,0,spin,58);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"21")==0||strcmp(songs[thesong].extnotetype2[a],"g1")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,760+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"22")==0||strcmp(songs[thesong].extnotetype2[a],"g2")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,713+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"23")==0||strcmp(songs[thesong].extnotetype2[a],"g3")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,713+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,760+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"24")==0||strcmp(songs[thesong].extnotetype2[a],"g4")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,666+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"25")==0||strcmp(songs[thesong].extnotetype2[a],"g5")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,666+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,760+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"26")==0||strcmp(songs[thesong].extnotetype2[a],"g6")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,713+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,666+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"27")==0||strcmp(songs[thesong].extnotetype2[a],"g7")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,760+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,666+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,713+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"28")==0||strcmp(songs[thesong].extnotetype2[a],"gw")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,792+goffset+g2offset,blah,-50+a,8,20,255,255,255,alpha,0,spin,42);
				}
			}else{
				if (strcmp(songs[thesong].extnotetype2[a],"a0")==0||strcmp(songs[thesong].extnotetype2[a],"b0")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,713+goffset+g2offset,blah,-50+a,66,39,255,255,255,alpha,0,spin,58);				
				}
				if (strcmp(songs[thesong].extnotetype2[a],"a1")==0||strcmp(songs[thesong].extnotetype2[a],"b1")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,760+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"a2")==0||strcmp(songs[thesong].extnotetype2[a],"b2")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,713+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"a3")==0||strcmp(songs[thesong].extnotetype2[a],"b3")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,713+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,760+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"a4")==0||strcmp(songs[thesong].extnotetype2[a],"b4")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,666+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"a5")==0||strcmp(songs[thesong].extnotetype2[a],"b5")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,666+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,760+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"a6")==0||strcmp(songs[thesong].extnotetype2[a],"b6")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,713+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,666+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"a7")==0||strcmp(songs[thesong].extnotetype2[a],"b7")==0){
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,760+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,666+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
					if (!songs[thesong].g2extnoteplayed[a])draw_quad(0,713+goffset+g2offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
				}
				if (strcmp(songs[thesong].extnotetype2[a],"a8")==0||strcmp(songs[thesong].extnotetype2[a],"bw")==0){
					draw_quad(0,792+goffset+g2offset,blah,-50+a,8,20,255,255,255,alpha,0,spin,42);
				}
			}
		}
	}
}
