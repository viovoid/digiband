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
void logoscreen(){
    #ifdef EXCESSIVE
	printf("logoscreen\n");
	#endif
	//static int logolength=15;//this is the actual time.
	static int logolength=5; //this is we want it to switch screens a shit load of times.
	draw_quad(0,512,384,-9000,640,400,255,255,255,255,0,0,71);
	if (currscreen!=prevscreen){
		if (presong>-1&&presong<gbsongcount){
			if(songsloaded>0)unloadwaves();
		}
		if (thesong>-1&&thesong<gbsongcount){
			if(songsloaded>0)loadwaves();
		}
		playpreview(false);
	}
	static char option1[256];
	snprintf(option1,255,"Coins %i/%i Credits (%i)",coinsinserted,coinsperplay,credits);
	static drawtext option1s;
	option1s.load(option1,"font.ttf",255,255,255,20);
	option1s.draw(400,0,0,255,255,255,255,false,true);


	/*That there new fancy logo and stuff.*/
	static tileeffect theeffect("seijinohki",600);
	if (currscreen!=prevscreen)theeffect.reset();
	theeffect.draw(20,330,0,13);
	/*and stuff*/


	if (theeffect.isdone){
		nextscreen=1;
		//nextscreen=21;
		screenfaddingout=true;
		screenchangenow=false;
		screenfaddingin=false;
	}
}
