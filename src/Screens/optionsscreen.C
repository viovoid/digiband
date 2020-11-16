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
void optionsscreen(int totalframes){
	#ifdef EXCESSIVE
	printf("optionsscreen\n");
	#endif
	draw_quad(0,512,384,-9999,640,400,255,255,255,255,0,0,1);
	if(!arcademode){
		draw_quad(0,512,384,-9995,640,400,255,255,255,255,0,0,55);
	}else{
		draw_quad(0,512,384,-9995,640,400,255,255,255,255,0,0,2);
	}
	if (lastscreen!=1&&screenfaddingin){
		screenfaddingin=false;
	}
	if (!screenfaddingin&&!screenfaddingout)
		draw_quad(0,512,384,-9990,640,400,255,255,255,255,0,0,3);

	
	char optionv[13][256];
	if (optionselected<0)optionselected=19;
	if (optionselected>19)optionselected=0;
	static char options[20][256];
	sprintf(options[0],"Fullscreen");
	sprintf(options[1],"X-Resolution");
	sprintf(options[2],"Y-Resolution");
	sprintf(options[3],"Bits Per Pixel");
	sprintf(options[4],"Theme");
	sprintf(options[5],"Life Difficulty");
	sprintf(options[6],"Arcade Style Failing");
	sprintf(options[7],"Stages Per Game");
	sprintf(options[8],"Note Speed");
	sprintf(options[9],"Noteskin");
	sprintf(options[10],"Number of Drums");
	sprintf(options[11],"Number of Frets");
	sprintf(options[12],"Guitar Wail");
	sprintf(options[13],"Configure Drum Controls...");
	sprintf(options[14],"Configure Guitar 1 Controls...");
	sprintf(options[15],"Configure Guitar 2 Controls...");
	sprintf(options[16],"Configure Sound Settings...");
	sprintf(options[17],"Configure Auto Settings...");
	sprintf(options[18],"Configure Arcade Settings...");
	sprintf(options[19],"Back");
	static drawtext optionsd[20];
	static drawtext optionvd[13];
	for (int i=0;i<20;i++){
		optionsd[i].load(options[i],"font.ttf",255,255,255,uivars.options_table_s);
	}
	if (!screenfaddingin&&!screenfaddingout){
		for (int i=0;i<20;i++){
			if (i==optionselected&&!suboptionselection)
				optionsd[i].draw(uivars.options_table_x,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,128,128,255,true,true);
			else
				optionsd[i].draw(uivars.options_table_x,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,255,255,255,false,true);
		}
		if (drumfullscreen)sprintf(optionv[0],"true");
		else sprintf(optionv[0],"false");
		if (suboptionselection&&optionselected==0)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*0)+15,-100,15,10,255,255,255,255,0,0,4);
		sprintf(optionv[1],"%i",resx);
		if (suboptionselection&&optionselected==1)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*1)+15,-100,15,10,255,255,255,255,0,0,4);
		sprintf(optionv[2],"%i",resy);
		if (suboptionselection&&optionselected==2)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*2)+15,-100,15,10,255,255,255,255,0,0,4);
		sprintf(optionv[3],"%i",drumbpp);
		if (suboptionselection&&optionselected==3)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*3)+15,-100,15,10,255,255,255,255,0,0,4);
		sprintf(optionv[4],"%s",theme);
		if (suboptionselection&&optionselected==4)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*4)+15,-100,15,10,255,255,255,255,0,0,4);
		sprintf(optionv[5],"%i",lifedifficulty);
		if (suboptionselection&&optionselected==5)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*5)+15,-100,15,10,255,255,255,255,0,0,4);
		if (stagefail){sprintf(optionv[6],"true");}
		else{ sprintf(optionv[6],"false");}
		if (suboptionselection&&optionselected==6)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*6)+15,-100,15,10,255,255,255,255,0,0,4);
		if (stages>0)
			sprintf(optionv[7],"%i",stages);
		else
			sprintf(optionv[7],"event");
		if (suboptionselection&&optionselected==7)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*7)+15,-100,15,10,255,255,255,255,0,0,4);
		sprintf(optionv[8],"%.1f",double(notespeed)/10.0);
		if (suboptionselection&&optionselected==8)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*8)+15,-100,15,10,255,255,255,255,0,0,4);
		sprintf(optionv[9],"%s",noteskin);
		if (suboptionselection&&optionselected==9)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*9)+15,-100,15,10,255,255,255,255,0,0,4);
		sprintf(optionv[10],"%i",nofdrums);
		if (suboptionselection&&optionselected==10)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*10)+15,-100,15,10,255,255,255,255,0,0,4);
		sprintf(optionv[11],"%i",noffrets);
		if (suboptionselection&&optionselected==11)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*11)+15,-100,15,10,255,255,255,255,0,0,4);
		if (enablewail)sprintf(optionv[12],"true");
		else sprintf(optionv[12],"false");
		if (suboptionselection&&optionselected==12)draw_quad(0,uivars.options_table_x+316,uivars.options_table_y-(uivars.options_table_s*12)+15,-100,15,10,255,255,255,255,0,0,4);
		for (int i=0;i<13;i++){
			optionvd[i].load(optionv[i],"font.ttf",255,255,255,uivars.options_table_s);
		}
		for (int i=0;i<13;i++){
			if (optionselected==i&&suboptionselection==true)
				optionvd[i].draw(uivars.options_table_x+350,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,128,128,255,true,true);
			else
				optionvd[i].draw(uivars.options_table_x+350,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,255,255,255,false,true);
		}
	}
	optionsscreenloaded=true;
}
