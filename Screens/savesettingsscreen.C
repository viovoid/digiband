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
void savesettingsscreen(){
	#ifdef EXCESSIVE
	printf("savesettingsscreen\n");
	#endif
	if (optionselected>1)
		optionselected=0;
	if (optionselected<0)
		optionselected=1;
	draw_quad(0,512,384,-9000,640,400,0,0,0,128,0,0,51);
	char caption1t[256];
	char caption2t[256];
	char option1t[5];
	char option2t[5];
	static int temp;
	if (currscreen!=prevscreen)
		temp=songs[thesong].offset;
	else
		songs[thesong].offset=temp;
	snprintf(caption1t,255,"You've changed the offset from %i to %i",songs[thesong].poffset,songs[thesong].offset);
	snprintf(caption2t,255,"Would you like to save these changes?");
	snprintf(option1t,4,"Yes");
	snprintf(option2t,4,"No");
	static drawtext caption1;
	caption1.load(caption1t,"font.ttf",200,200,255,40);
	static drawtext caption2;
	caption2.load(caption2t,"font.ttf",200,200,255,40);
	static drawtext option1;
	if (optionselected==0)
		option1.load(option1t,"font.ttf",255,255,255,40);
	else
		option1.load(option1t,"font.ttf",128,128,128,40);
	static drawtext option2;
	if (optionselected==1)
		option2.load(option2t,"font.ttf",255,255,255,40);
	else
		option2.load(option2t,"font.ttf",128,128,128,40);
	caption1.draw(195,555,0,255,255,255,255);
	caption1.draw(190,550,10,128,128,128,255);
	caption2.draw(195,505,0,255,255,255,255);
	caption2.draw(190,500,10,128,128,128,255);
	option1.draw(475,455,0,255,255,255,255);
	option1.draw(470,450,10,128,128,128,255);
	option2.draw(575,455,0,255,255,255,255);
	option2.draw(570,450,10,128,128,128,255);
}
