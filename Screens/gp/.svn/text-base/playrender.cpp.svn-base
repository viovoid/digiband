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
void playrender(){
	#ifdef EXCESSIVE
	printf("playrender\n");
	#endif
	if (!screenfaddingout&&!screenfaddingin){
		if (newsong){
			int temp=SDL_GetTicks();//This is only being called to reset the timer after loading the waves.
			timestamp=temp;
		}
	}
	bool hh=false;
	bool sd=false;
	bool bd=false;
	bool ht=false;
	bool lt=false;
	bool cy=false;
	
	bool gb=false;
	bool gg=false;
	bool ggb=false;
	bool gr=false;
	bool grb=false;
	bool grg=false;
	bool grgb=false;
	bool gw=false;
	bool go=false;

	bool gb2=false;
	bool gg2=false;
	bool ggb2=false;
	bool gr2=false;
	bool grb2=false;
	bool grg2=false;
	bool grgb2=false;
	bool gw2=false;
	bool go2=false;
	if (drumdiff==0||guit1diff==0||guit2diff==0){
		for (int a=0;a<songs[thesong].basnotes;a++){
            if (!screenfaddingout&&!screenfaddingin){
    			autobgm0(a);
    	   		autoplay0(a);
            }
			if (currscreen==6&&drumdiff==0)playnote_dmbas(a,hh,sd,bd,ht,lt,cy);
			if (currscreen==6&&guit1diff==0)playnote_g1bas(a,gb,gg,ggb,gr,grb,grg,grgb,gw,go);
			if (currscreen==6&&guit2diff==0)playnote_g2bas(a,gb2,gg2,ggb2,gr2,grb2,grg2,grgb2,gw2,go2);
			if (currscreen==6)draw_note_dm0(a);
			if (currscreen==6)draw_gnote0(a);
		}
	}
	if (drumdiff==1||guit1diff==1||guit2diff==1){
		for (int a=0;a<songs[thesong].advnotes;a++){
            if (!screenfaddingout&&!screenfaddingin){
    			autobgm1(a);
	       		autoplay1(a);
            }
			if (currscreen==6&&drumdiff==1)playnote_dmadv(a,hh,sd,bd,ht,lt,cy);
			if (currscreen==6&&guit1diff==1)playnote_g1adv(a,gb,gg,ggb,gr,grb,grg,grgb,gw,go);
			if (currscreen==6&&guit2diff==1)playnote_g2adv(a,gb2,gg2,ggb2,gr2,grb2,grg2,grgb2,gw2,go2);
			if (currscreen==6)draw_note_dm1(a);
			if (currscreen==6)draw_gnote1(a);
		}
	}
	if (drumdiff==2||guit1diff==2||guit2diff==2){
		for (int a=0;a<songs[thesong].extnotes;a++){
            if (!screenfaddingout&&!screenfaddingin){
    			autobgm2(a);
	       		autoplay2(a);
            }
			if (currscreen==6&&drumdiff==2)playnote_dmext(a,hh,sd,bd,ht,lt,cy);
			if (currscreen==6&&guit1diff==2)playnote_g1ext(a,gb,gg,ggb,gr,grb,grg,grgb,gw,go);
			if (currscreen==6&&guit2diff==2)playnote_g2ext(a,gb2,gg2,ggb2,gr2,grb2,grg2,grgb2,gw2,go2);
			if (currscreen==6)draw_note_dm2(a);
			if (currscreen==6)draw_gnote2(a);
		}
	}
	phihatts=hihatts;
	psnarets=snarets;
	pbassts=bassts;
	phitomts=hitomts;
	plotomts=lotomts;
	pcymbalts=cymbalts;
	hihatts=0;
	snarets=0;
	bassts=0;
	hitomts=0;
	lotomts=0;
	cymbalts=0;
}
