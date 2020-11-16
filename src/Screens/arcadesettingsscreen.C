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
void arcadesettingsscreen(){
   	#ifdef EXCESSIVE
	printf("arcadesettingsscrreen\n");
	#endif
	if (optionselected>5)optionselected=0;
	if (optionselected<0)optionselected=5;
	static char options[6][35];
	static char optionv[5][35];
	sprintf(options[0], "Arcade Mode");
	sprintf(options[1], "Coins Per Play");
	sprintf(options[2], "Menu Counter Time");
	sprintf(options[3], "Coin Key");
	sprintf(options[4], "Option Key");
	sprintf(options[5], "Return to Options");
	if (arcademode){
		sprintf(optionv[0], "true");
	}else{
		sprintf(optionv[0], "false");
	}
	sprintf(optionv[1], "%i ", coinsperplay);
	sprintf(optionv[2], "%i ", menucountertime);
	sprintf(optionv[3], "%s ", keytochar(coinkey));
	sprintf(optionv[4], "%s ", keytochar(opskey));
	static drawtext optionsd[6];
	static drawtext optionvd[5];
	for (int i=0;i<6;i++){
		optionsd[i].load(options[i],"font.ttf",255,255,255,uivars.options_table_s);
		if (optionselected==i&&suboptionselection==false)
			optionsd[i].draw(uivars.options_table_x,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,128,128,255,true,true);
		else
			optionsd[i].draw(uivars.options_table_x,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,255,255,255,false,true);
		if (i<5)optionvd[i].load(optionv[i],"font.ttf",255,255,255,uivars.options_table_s);
		if (optionselected==i&&suboptionselection==true){
			if(i<5)optionvd[i].draw(uivars.options_table_x+350,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,128,128,255,true,true);
		}else{
			if(i<5)optionvd[i].draw(uivars.options_table_x+350,uivars.options_table_y-(uivars.options_table_s*i),i*10,255,255,255,255,false,true);
		}		
	}
}
