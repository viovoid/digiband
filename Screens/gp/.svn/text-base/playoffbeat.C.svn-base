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
void playoffbeat(){
	#ifdef EXCESSIVE
	printf("playoffbeat\n");
	#endif
	if (hihatpressed){
		if (lasthihat>0){
			playsound(lasthihat+256,voldrum);
		}
		hihatpressed=false;
	}
	if (snarepressed){
		if (lastsnare>0){
			playsound(lastsnare+256,voldrum);
		}
		snarepressed=false;
	}
	if (basspressed){
		if (lastbass>0){
			playsound(lastbass+256,voldrum);
		}
		basspressed=false;
	}
	if (hitompressed){
		if (lasthitom>0){
			playsound(lasthitom+256,voldrum);
		}
		hitompressed=false;
	}
	if (lotompressed){
		if (lastlotom>0){
			playsound(lastlotom+256,voldrum);
		}
		lotompressed=false;
	}
	if (cymbalpressed){
		if (lastcymbal>0){
			playsound(lastcymbal+256,voldrum);
		}
		cymbalpressed=false;
	}
	if (g1ots>0||g1rts>0||g1gts>0||g1bts>0||g1rbts>0||g1rgts>0||g1gbts>0||g1rgbts>0){
		if (guitar1mode){
			if (guitar1treb)
				playsound(11,"guitartrebleoff.wav",volguit);
			else
				playsound(12,"guitarbassoff.wav",volguit);
			gpg1miss++;
			gpg1currcombo=0;
			snprintf(gpg1ograde,24,"Miss");
			gpg1lifebar-=lifedifficulty/2.0;
			gpg1ogradetime=0;
		}
	}
	if (g2ots>0||g2rts>0||g2gts>0||g2bts>0||g2rbts>0||g2rgts>0||g2gbts>0||g2rgbts>0){
		if (guitar2mode){
			if (guitar2treb)
				playsound(11,"guitartrebleoff.wav",volbass);
			else
				playsound(12,"guitarbassoff.wav",volbass);
			gpg2miss++;
			gpg2currcombo=0;
			snprintf(gpg1ograde,24,"Miss");
			gpg2lifebar-=lifedifficulty/2.0;
			gpg2ogradetime=0;
		}
	}
	g1ots=0;
	g1rts=0;
	g1gts=0;
	g1bts=0;
	g1rgts=0;
	g1gbts=0;
	g1rbts=0;
	g1rgbts=0;
	g1wts=0;
	g2ots=0;
	g2rts=0;
	g2gts=0;
	g2bts=0;
	g2rgts=0;
	g2gbts=0;
	g2rbts=0;
	g2rgbts=0;
	g2wts=0;
}
