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
void configuredrum(){
	#ifdef EXCESSIVE
	printf("configuredrum\n");
	#endif
	if (optionselected>14)optionselected=0;
	if (optionselected<0)optionselected=14;
	static char optionv[14][35];
	static char options[15][35];
	sprintf(options[0], "Hihat Key (back)...");
	sprintf(options[1], "Snare Key (menu up/left)...");
	sprintf(options[2], "Bass Key...");
	sprintf(options[3], "Hitom Key...");
	sprintf(options[4], "Lotom Key (menu down/right)...");
	sprintf(options[5], "Cymbal Key (start)...");
	sprintf(options[6], "Start Key (start)...");
	sprintf(options[7], "Back Key (start)...");
	sprintf(options[8], "Hihat Key (alt)...");
	sprintf(options[9], "Snare Key (alt)...");
	sprintf(options[10], "Bass Key (alt)...");
	sprintf(options[11], "Hitom Key (alt)...");
	sprintf(options[12], "Lotom Key (alt)...");
	sprintf(options[13], "Cymbal Key (alt)...");
	sprintf(options[14], "Return to Options");
	sprintf(optionv[0], "%s", keytochar(hihatkey));
	sprintf(optionv[1], "%s", keytochar(snarekey));
	sprintf(optionv[2], "%s", keytochar(basskey));
	sprintf(optionv[3], "%s", keytochar(hitomkey));
	sprintf(optionv[4], "%s", keytochar(lotomkey));
	sprintf(optionv[5], "%s", keytochar(cymbalkey));
	sprintf(optionv[6], "%s", keytochar(startkey));
	sprintf(optionv[7], "%s", keytochar(backkey));
	sprintf(optionv[8], "%s", keytochar(althihatkey));
	sprintf(optionv[9], "%s", keytochar(altsnarekey));
	sprintf(optionv[10], "%s", keytochar(altbasskey));
	sprintf(optionv[11], "%s", keytochar(althitomkey));
	sprintf(optionv[12], "%s", keytochar(altlotomkey));
	sprintf(optionv[13], "%s", keytochar(altcymbalkey));
	static drawtext optionsd[15];
	static drawtext optionvd[14];
	for (int i=0;i<15;i++){
		optionsd[i].load(options[i],"font.ttf",255,255,255,uivars.options_table_s);
		if (i<14)optionvd[i].load(optionv[i],"font.ttf",255,255,255,uivars.options_table_s);
		if (optionselected==i&&suboptionselection==false)
			optionsd[i].draw(uivars.options_table_x,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,128,128,255,true,true);
		else
			optionsd[i].draw(uivars.options_table_x,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,255,255,255,false,true);
		if (optionselected==i&&suboptionselection==true){
			if(i<14)optionvd[i].draw(uivars.options_table_x+350,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,128,128,255,true,true);}
		else{
			if(i<14)optionvd[i].draw(uivars.options_table_x+350,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,255,255,255,false,true);}
	}
}
