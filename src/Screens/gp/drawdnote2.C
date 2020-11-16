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
void draw_note_dm2(int a){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("draw_note_dm2\n");
	#endif
	#endif
	if (drumdiff==2){
		int blah=int(85+((double(songs[thesong].extnotemeas[a])*100.0)+(double(songs[thesong].extnotetime[a])/100.0))*(double((double(drumnotespeed)/double(notebpm/150.0)))/3.0)-((double(songpositiondraw)+(double(songs[thesong].offset)*500.0))/2400.0)*(double((double(drumnotespeed)/double(notebpm/150.0)))/3.0));
		int alpha=255;
		if (drumfademode==1){
			alpha=blah/2-128;
			if (alpha>255)alpha=255;
			if (alpha<0)alpha=0;
		}
		if (drumfademode==2){
			alpha=blah/2;
			if (alpha>255)alpha=255;
			if (alpha<0)alpha=0;
			alpha=255-alpha;
		}
		if (drumfademode==3){
			alpha=int(blah/1.5)-256;
			alpha=255-abs(int(alpha*1.5));
			if (alpha<0)
				alpha=0;
		}
		int spin=0;
		if (drumspin){
			spin=blah-85;	
		}			
		if (blah>0&&blah<768){
			if (strcmp(songs[thesong].extnotetype[a],"11")==0||strcmp(songs[thesong].extnotetype[a],"hh")==0){
				if (!songs[thesong].extnoteplayed[a]){
					draw_quad(0,87+offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,28);
				}
			}
			if (strcmp(songs[thesong].extnotetype[a],"12")==0||strcmp(songs[thesong].extnotetype[a],"sd")==0){
				if (!songs[thesong].extnoteplayed[a]){
					draw_quad(0,134+offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,57);
				}
			}
			if (strcmp(songs[thesong].extnotetype[a],"13")==0||strcmp(songs[thesong].extnotetype[a],"bd")==0){
				if (!songs[thesong].extnoteplayed[a]){
					draw_quad(0,180+offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,58);
				}
			}
			if (strcmp(songs[thesong].extnotetype[a],"14")==0||strcmp(songs[thesong].extnotetype[a],"ht")==0){
				if (!songs[thesong].extnoteplayed[a]){
					draw_quad(0,227+offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,59);
				}
			}
			if (strcmp(songs[thesong].extnotetype[a],"15")==0||strcmp(songs[thesong].extnotetype[a],"lt")==0){
				if (!songs[thesong].extnoteplayed[a]){
					draw_quad(0,274+offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,60);
				}
			}
			if (strcmp(songs[thesong].extnotetype[a],"16")==0||strcmp(songs[thesong].extnotetype[a],"cy")==0){
				if (!songs[thesong].extnoteplayed[a]){
					draw_quad(0,320+offset,blah,-50+a,22,39,255,255,255,alpha,0,spin,61);
				}
			}
		}
	}
}
