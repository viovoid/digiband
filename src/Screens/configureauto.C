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
void configureauto(){
	#ifdef EXCESSIVE
	printf("configureauto\n");
	#endif
	if (optionselected>4)optionselected=0;
	if (optionselected<0)optionselected=4;
	static char optionv[4][35];
	static char options[5][35];
	sprintf(options[0], "Auto Hihat");
	sprintf(options[1], "Auto Bass");
	sprintf(options[2], "Auto Cymbal");
	sprintf(options[3], "Auto Hihat/Bass/Cymbal");
	sprintf(options[4], "return to options");
	if (autohihat)sprintf(optionv[0], "true");
	if (!autohihat)sprintf(optionv[0], "false");
	if (autobass)sprintf(optionv[1], "true");
	if (!autobass)sprintf(optionv[1], "false");
	if (autocymbal)sprintf(optionv[2], "true");
	if (!autocymbal)sprintf(optionv[2], "false");
	if (autoall)sprintf(optionv[3], "true");
	if (!autoall)sprintf(optionv[3], "false");
	static drawtext optionsd[8];
	static drawtext optionvd[7];
	for (int i=0;i<5;i++){
		optionsd[i].load(options[i],"font.ttf",255,255,255,uivars.options_table_s);
		if (i<4)optionvd[i].load(optionv[i],"font.ttf",255,255,255,uivars.options_table_s);
		if (optionselected==i&&suboptionselection==false)
			optionsd[i].draw(uivars.options_table_x,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,128,128,255,true,true);
		else
			optionsd[i].draw(uivars.options_table_x,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,255,255,255,false,true);
		if (optionselected==i&&suboptionselection==true){
			if(i<4)optionvd[i].draw(uivars.options_table_x+350,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,128,128,255,true,true);}
		else{
			if(i<4)optionvd[i].draw(uivars.options_table_x+350,uivars.options_table_y-(uivars.options_table_s*i),i*10);}
	}
}
