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
void configureguitar2(){
	#ifdef EXCESSIVE
	printf("configureguitar2\n");
	#endif
	if (optionselected>8)optionselected=0;
	if (optionselected<0)optionselected=8;
	static char optionv[8][35];
	static char options[9][35];
	sprintf(options[0], "Red Key (menu up/left)...");
	sprintf(options[1], "Green Key (back)...");
	sprintf(options[2], "Blue Key (menu down/right)...");
	sprintf(options[3], "Wail Key...");
	sprintf(options[4], "Pick Key...");
	sprintf(options[5], "Start Key (dedicated)...");
	sprintf(options[6], "Back Key (dedicated)...");
	sprintf(options[7], "Pick Key (alternate)...");
	sprintf(options[8], "Return to Options");
	sprintf(optionv[0], "%s", keytochar(guitar2r));
	sprintf(optionv[1], "%s", keytochar(guitar2g));
	sprintf(optionv[2], "%s", keytochar(guitar2b));
	sprintf(optionv[3], "%s", keytochar(guitar2w));
	sprintf(optionv[4], "%s", keytochar(guitar2p));
	sprintf(optionv[5], "%s", keytochar(guitar2start));
	sprintf(optionv[6], "%s", keytochar(guitar2back));
	sprintf(optionv[7], "%s", keytochar(guitar2a));
	static drawtext optionsd[9];
	static drawtext optionvd[8];
	for (int i=0;i<9;i++){
		optionsd[i].load(options[i],"font.ttf",255,255,255,uivars.options_table_s);
		if (i<8)optionvd[i].load(optionv[i],"font.ttf",255,255,255,uivars.options_table_s);
		if (optionselected==i&&suboptionselection==false)
			optionsd[i].draw(uivars.options_table_x,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,128,128,255,true,true);
		else
			optionsd[i].draw(uivars.options_table_x,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,255,255,255,false,true);
		if (optionselected==i&&suboptionselection==true){
			if(i<8)optionvd[i].draw(uivars.options_table_x+350,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,128,128,255,true,true);}
		else{
			if(i<8)optionvd[i].draw(uivars.options_table_x+350,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,255,255,255,false,true);}
	}
}
