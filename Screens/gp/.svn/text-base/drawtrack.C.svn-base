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
void draw_track(){
	#ifdef EXCESSIVE
	printf("draw_track\n");
	#endif
	for (int a=int((double(songpositiondraw)/2400.0)/25)*25+25;a<double(songpositiondraw)/2400.0+1000;a+=25){
		if (guitar1mode){
			if (double(a)/100.0==double(a/100)){
				draw_quad(0,713+goffset,int(679-a*(double((double(guitar1notespeed)/double(notebpm/150.0)))/3.0)+(double(songpositiondraw)/2400.0)*(double((double(guitar1notespeed)/double(notebpm/150.0)))/3.0)),-75,70,2,255,255,255,255,0,0,38);
			}else{
				draw_quad(0,713+goffset,int(679-a*(double((double(guitar1notespeed)/double(notebpm/150.0)))/3.0)+(double(songpositiondraw)/2400.0)*(double((double(guitar1notespeed)/double(notebpm/150.0)))/3.0)),-75,70,2,255,255,255,128,0,0,38);
			}
		}	
		if (guitar2mode){
			if (double(a)/100.0==double(a/100)){
				draw_quad(0,713+goffset+g2offset,int(679-a*(double((double(guitar2notespeed)/double(notebpm/150.0)))/3.0)+(double(songpositiondraw)/2400.0)*(double((double(guitar2notespeed)/double(notebpm/150.0)))/3.0)),-75,70,3,255,255,255,255,0,0,38);
			}else{
				draw_quad(0,713+goffset+g2offset,int(679-a*(double((double(guitar2notespeed)/double(notebpm/150.0)))/3.0)+(double(songpositiondraw)/2400.0)*(double((double(guitar2notespeed)/double(notebpm/150.0)))/3.0)),-75,70,2,255,255,255,128,0,0,38);
			}
		}
	}	
	for (int a=int((double(songpositiondraw)/2400.0)/25)*25+25;a<double(songpositiondraw)/2400.0+4000;a+=25){
		if (drummode){
			if (double(a)/100.0==double(a/100)){
				draw_quad(0,204+offset,int(85+a*(double((double(drumnotespeed)/double(notebpm/150.0)))/3.0)-(double(songpositiondraw)/2400.0)*(double((double(drumnotespeed)/double(notebpm/150.0)))/3.0)),-75,140,3,255,255,255,255,0,0,38);
			}else{
				draw_quad(0,204+offset,int(85+a*(double((double(drumnotespeed)/double(notebpm/150.0)))/3.0)-(double(songpositiondraw)/2400.0)*(double((double(drumnotespeed)/double(notebpm/150.0)))/3.0)),-75,140,2,255,255,255,128,0,0,39);
			}
		}
	}
}
