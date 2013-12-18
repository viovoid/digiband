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
void gameoverscreen(){
	#ifdef EXCESSIVE
	printf("gameoverscreen\n");
	#endif
	if (currscreen!=prevscreen){
		songs[0].reloadsong();
		playsound(9,"gameovervoice.wav");
		playpreview();
	}
	draw_quad(0,512,384,-8000,640,400,255,255,255,255,0,0,46);
	draw_quad(0,512,384,-7900,640,400,255,255,255,255,0,0,47);
	if (arcademode){
		if (menucountertime>0){
			static long timer=0;
			if (currscreen!=prevscreen)
				timer=SDL_GetTicks();
			int timeleft=int(double(10)-((double(SDL_GetTicks())-double(timer))/1000.0));
			if (timeleft==0){
				nextscreen=1;
				screenfaddingout=true;
				screenchangenow=false;
				screenfaddingin=false;
			}
		}
	}
}
