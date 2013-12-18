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
void draw_drum_table(int tablex, int tabley){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("draw_drum_table\n");
	#endif
	#endif
	//drum table
	if (drumnotespeed<10){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,0);
	}else if(drumnotespeed==10){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,1);
	}else if(drumnotespeed>10&&drumnotespeed<100){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,2);
	}else if(drumnotespeed>=100&&drumnotespeed<200){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,3);
	}else if(drumnotespeed==200){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,4);
	}
	draw_quad_frame(0,tablex,tabley-18,2000,22,9,255,255,255,255,0,0,65,1);
	if (drumfademode==0)
		draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,1);
	if (drumfademode==1||drumfademode==2)
		draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,2);
	if (drumfademode==3)
		draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,3);
	if (!drumrandommode)
		draw_quad_frame(0,tablex,tabley-54,2000,22,9,255,255,255,255,0,0,65,1);
	else
		draw_quad_frame(0,tablex,tabley-54,2000,22,9,255,255,255,255,0,0,65,3);
	if (!drumspin)
		draw_quad_frame(0,tablex,tabley-72,2000,22,9,255,255,255,255,0,0,65,1);
	else
		draw_quad_frame(0,tablex,tabley-72,2000,22,9,255,255,255,255,0,0,65,3);		
	if (drumdiff==-1)
		draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,0);
	if (drumdiff==0)
		draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,1);
	if (drumdiff==1)
		draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,2);
	if (drumdiff==2)
		draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,3);
	//drum table text	
	static drawtext drumtp;
	static drawtext drumns;
	static drawtext drumas;
	static drawtext drumfm;
	static drawtext drumrm;
	static drawtext drumsm;
	static drawtext drumdf;
	char drumtptext[7];
	char drumnstext[7];
	char drumastext[7];
	char drumfmtext[7];
	char drumrmtext[7];
	char drumsmtext[7];
	char drumdftext[7];
	snprintf(drumtptext,6," Drm ");
	if (drumnotespeed<100){
		snprintf(drumnstext,6,"0%.1fx", double(drumnotespeed)/10.0);
	}else{
		snprintf(drumnstext,6,"%.1fx", double(drumnotespeed)/10.0);
	}
	snprintf(drumastext,6,"Norml");
	if (drumfademode==0)
		snprintf(drumfmtext,6,"NoFad");
	if (drumfademode==1)
		snprintf(drumfmtext,6,"F-Out");
	if (drumfademode==2)
		snprintf(drumfmtext,6,"F-In");
	if (drumfademode==3)
		snprintf(drumfmtext,6,"FBoth");
	if (drumrandommode)
		snprintf(drumrmtext,6,"RandN");
	else
		snprintf(drumrmtext,6,"Norml");
	if (drumspin)
		snprintf(drumsmtext,6,"SpinM");
	else
		snprintf(drumsmtext,6,"Norml");
	if (drumdiff<0||drumdiff>2)
		snprintf(drumdftext,6," N/A ");
	if (drumdiff==0)
		snprintf(drumdftext,6," Std ");
	if (drumdiff==1)
		snprintf(drumdftext,6," Adv ");
	if (drumdiff==2)
		snprintf(drumdftext,6," Ext ");
	drumtp.load(drumtptext,"mono.ttf",255,255,255,16);
	drumns.load(drumnstext,"mono.ttf",255,255,255,12);
	drumas.load(drumastext,"mono.ttf",255,255,255,12);
	drumfm.load(drumfmtext,"mono.ttf",255,255,255,12);
	drumrm.load(drumrmtext,"mono.ttf",255,255,255,12);
	drumsm.load(drumsmtext,"mono.ttf",255,255,255,12);
	drumdf.load(drumdftext,"mono.ttf",255,255,255,12);
	drumtp.draw(tablex-26,tabley-8+18,2010,255,255,255,255,false,true);
	drumns.draw(tablex-18,tabley-8,2010,255,255,255,255,false,true);
	drumas.draw(tablex-18,tabley-8-18,2010,255,255,255,255,false,true);
	drumfm.draw(tablex-18,tabley-8-36,2010,255,255,255,255,false,true);
	drumrm.draw(tablex-18,tabley-8-54,2010,255,255,255,255,false,true);
	drumsm.draw(tablex-18,tabley-8-72,2010,255,255,255,255,false,true);
	drumdf.draw(tablex-18,tabley-8-90,2010,255,255,255,255,false,true);
}

void draw_guit1_table(int tablex, int tabley){
	if (guitar1notespeed<10){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,0);
	}else if(guitar1notespeed==10){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,1);
	}else if(guitar1notespeed>10&&guitar1notespeed<100){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,2);
	}else if(guitar1notespeed>=100&&guitar1notespeed<200){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,3);
	}else if(guitar1notespeed==200){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,4);
	}
	if (guitar1treb)
		draw_quad_frame(0,tablex,tabley-18,2000,22,9,255,255,255,255,0,0,65,1);
	else
		draw_quad_frame(0,tablex,tabley-18,2000,22,9,255,255,255,255,0,0,65,2);
	if (guit1fademode==0)
		draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,1);
	if (guit1fademode==1||guit1fademode==2)
		draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,2);
	if (guit1fademode==3)
		draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,3);
	if (!guit1randommode)
		draw_quad_frame(0,tablex,tabley-54,2000,22,9,255,255,255,255,0,0,65,1);
	else
		draw_quad_frame(0,tablex,tabley-54,2000,22,9,255,255,255,255,0,0,65,3);
	if (!guit1spin)
		draw_quad_frame(0,tablex,tabley-72,2000,22,9,255,255,255,255,0,0,65,1);
	else
		draw_quad_frame(0,tablex,tabley-72,2000,22,9,255,255,255,255,0,0,65,3);
	if (guit1diff==-1)
		draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,0);
	if (guit1diff==0)
		draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,1);
	if (guit1diff==1)
		draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,2);
	if (guit1diff==2)
		draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,3);
	//guitar 1 table text
	static drawtext guitar1tp;
	static drawtext guitar1ns;
	static drawtext guitar1as;
	static drawtext guitar1fm;
	static drawtext guitar1rm;
	static drawtext guitar1sm;
	static drawtext guitar1df;
	char guitar1tptext[7];
	char guitar1nstext[7];
	char guitar1astext[7];
	char guitar1fmtext[7];
	char guitar1rmtext[7];
	char guitar1smtext[7];
	char guitar1dftext[7];
	snprintf(guitar1tptext,6," G-1 ");
	if (guitar1notespeed<100){
		snprintf(guitar1nstext,6,"0%.1fx", double(guitar1notespeed)/10.0);
	}else{
		snprintf(guitar1nstext,6,"%.1fx", double(guitar1notespeed)/10.0);
	}
	if (guitar1treb)
		snprintf(guitar1astext,6,"Norml");
	else
		snprintf(guitar1astext,6," Alt ");
	if (guit1fademode==0)
		snprintf(guitar1fmtext,6,"NoFad");
	if (guit1fademode==1)
		snprintf(guitar1fmtext,6,"F-Out");
	if (guit1fademode==2)
		snprintf(guitar1fmtext,6,"F-In");
	if (guit1fademode==3)
		snprintf(guitar1fmtext,6,"FBoth");
	if (guit1randommode)
		snprintf(guitar1rmtext,6,"RandN");
	else
		snprintf(guitar1rmtext,6,"Norml");
	if (guit1spin)
		snprintf(guitar1smtext,6,"SpinM");
	else
		snprintf(guitar1smtext,6,"Norml");
	if (guit1diff<0||guit1diff>2)
		snprintf(guitar1dftext,6," N/A ");
	if (guit1diff==0)
		snprintf(guitar1dftext,6," Std ");
	if (guit1diff==1)
		snprintf(guitar1dftext,6," Adv ");
	if (guit1diff==2)
		snprintf(guitar1dftext,6," Ext ");
	guitar1tp.load(guitar1tptext,"mono.ttf",255,255,255,16);
	guitar1ns.load(guitar1nstext,"mono.ttf",255,255,255,12);
	guitar1as.load(guitar1astext,"mono.ttf",255,255,255,12);
	guitar1fm.load(guitar1fmtext,"mono.ttf",255,255,255,12);
	guitar1rm.load(guitar1rmtext,"mono.ttf",255,255,255,12);
	guitar1sm.load(guitar1smtext,"mono.ttf",255,255,255,12);
	guitar1df.load(guitar1dftext,"mono.ttf",255,255,255,12);
	guitar1tp.draw(tablex-26,tabley-8+18,2010,255,255,255,255,false,true);
	guitar1ns.draw(tablex-18,tabley-8,2010,255,255,255,255,false,true);
	guitar1as.draw(tablex-18,tabley-8-18,2010,255,255,255,255,false,true);
	guitar1fm.draw(tablex-18,tabley-8-36,2010,255,255,255,255,false,true);
	guitar1rm.draw(tablex-18,tabley-8-54,2010,255,255,255,255,false,true);
	guitar1sm.draw(tablex-18,tabley-8-72,2010,255,255,255,255,false,true);
	guitar1df.draw(tablex-18,tabley-8-90,2010,255,255,255,255,false,true);
}

void draw_guit2_table(int tablex, int tabley){
	if (guitar2notespeed<10){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,0);
	}else if(guitar2notespeed==10){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,1);
	}else if(guitar2notespeed>10&&guitar2notespeed<100){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,2);
	}else if(guitar2notespeed>=100&&guitar2notespeed<200){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,3);
	}else if(guitar2notespeed==200){
		draw_quad_frame(0,tablex,tabley,2000,22,9,255,255,255,255,0,0,65,4);
	}
	if (guitar2treb)
		draw_quad_frame(0,tablex,tabley-18,2000,22,9,255,255,255,255,0,0,65,1);
	else
		draw_quad_frame(0,tablex,tabley-18,2000,22,9,255,255,255,255,0,0,65,2);
	if (guit2fademode==0)
		draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,1);
	if (guit2fademode==1||guit2fademode==2)
		draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,2);
	if (guit2fademode==3)
		draw_quad_frame(0,tablex,tabley-36,2000,22,9,255,255,255,255,0,0,65,3);
	if (!guit2randommode)
		draw_quad_frame(0,tablex,tabley-54,2000,22,9,255,255,255,255,0,0,65,1);
	else
		draw_quad_frame(0,tablex,tabley-54,2000,22,9,255,255,255,255,0,0,65,3);
	if (!guit2spin)
		draw_quad_frame(0,tablex,tabley-72,2000,22,9,255,255,255,255,0,0,65,1);
	else
		draw_quad_frame(0,tablex,tabley-72,2000,22,9,255,255,255,255,0,0,65,3);
	if (guit2diff==-1)
		draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,0);
	if (guit2diff==0)
		draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,1);
	if (guit2diff==1)
		draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,2);
	if (guit2diff==2)
		draw_quad_frame(0,tablex,tabley-90,2000,22,9,255,255,255,255,0,0,65,3);
	//guitar 1 table text
	static drawtext guitar2tp;
	static drawtext guitar2ns;
	static drawtext guitar2as;
	static drawtext guitar2fm;
	static drawtext guitar2rm;
	static drawtext guitar2sm;
	static drawtext guitar2df;
	char guitar2tptext[7];
	char guitar2nstext[7];
	char guitar2astext[7];
	char guitar2fmtext[7];
	char guitar2rmtext[7];
	char guitar2smtext[7];
	char guitar2dftext[7];
	snprintf(guitar2tptext,6," G-2 ");
	if (guitar2notespeed<100){
		snprintf(guitar2nstext,6,"0%.1fx", double(guitar2notespeed)/10.0);
	}else{
		snprintf(guitar2nstext,6,"%.1fx", double(guitar2notespeed)/10.0);
	}
	if (guitar2treb)
		snprintf(guitar2astext,6,"Norml");
	else
		snprintf(guitar2astext,6," Alt ");
	if (guit2fademode==0)
		snprintf(guitar2fmtext,6,"NoFad");
	if (guit2fademode==1)
		snprintf(guitar2fmtext,6,"F-Out");
	if (guit2fademode==2)
		snprintf(guitar2fmtext,6,"F-In");
	if (guit2fademode==3)
		snprintf(guitar2fmtext,6,"FBoth");
	if (guit2randommode)
		snprintf(guitar2rmtext,6,"RandN");
	else
		snprintf(guitar2rmtext,6,"Norml");
	if (guit2spin)
		snprintf(guitar2smtext,6,"SpinM");
	else
		snprintf(guitar2smtext,6,"Norml");
	if (guit2diff<0||guit2diff>2)
		snprintf(guitar2dftext,6, " N/A ");
	if (guit2diff==0)
		snprintf(guitar2dftext,6," Std ");
	if (guit2diff==1)
		snprintf(guitar2dftext,6," Adv ");
	if (guit2diff==2)
		snprintf(guitar2dftext,6," Ext ");
	guitar2tp.load(guitar2tptext,"mono.ttf",255,255,255,16);
	guitar2ns.load(guitar2nstext,"mono.ttf",255,255,255,12);
	guitar2as.load(guitar2astext,"mono.ttf",255,255,255,12);
	guitar2fm.load(guitar2fmtext,"mono.ttf",255,255,255,12);
	guitar2rm.load(guitar2rmtext,"mono.ttf",255,255,255,12);
	guitar2sm.load(guitar2smtext,"mono.ttf",255,255,255,12);
	guitar2df.load(guitar2dftext,"mono.ttf",255,255,255,12);
	guitar2tp.draw(tablex-26,tabley-8+18,2010,255,255,255,255,false,true);
	guitar2ns.draw(tablex-18,tabley-8,2010,255,255,255,255,false,true);
	guitar2as.draw(tablex-18,tabley-8-18,2010,255,255,255,255,false,true);
	guitar2fm.draw(tablex-18,tabley-8-36,2010,255,255,255,255,false,true);
	guitar2rm.draw(tablex-18,tabley-8-54,2010,255,255,255,255,false,true);
	guitar2sm.draw(tablex-18,tabley-8-72,2010,255,255,255,255,false,true);
	guitar2df.draw(tablex-18,tabley-8-90,2010,255,255,255,255,false,true);
}
