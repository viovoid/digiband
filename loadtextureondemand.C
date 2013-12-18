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
void resettextures(){
	#ifdef EXCESSIVE
	printf("resettextures\n");
	#endif
    for (int a=0;a<numoftexs;a++){
		for (int b=0;b<int(texani[a][0]);b++){
			if (g_Texture[a][b]>0){
				g_Texture[a][b]=0;
			}
		}
	}
}

void loadtextureresize(){
	#ifdef EXCESSIVE
	printf("loadtexturesize\n");
	#endif
	if (currscreen!=6)return;
    for (int b=0;b<int(texani[17][0]);b++){
		if (g_Texture[17][b]>0){
			glDeleteTextures(1,&g_Texture[17][b]);
			g_Texture[17][b]=0;
		}
	}
    for (int b=0;b<int(texani[18][0]);b++){
		if (g_Texture[18][b]>0){
			glDeleteTextures(1,&g_Texture[18][b]);
			g_Texture[18][b]=0;
		}
	}
    for (int b=0;b<int(texani[20][0]);b++){
		if (g_Texture[20][b]>0){
			glDeleteTextures(1,&g_Texture[20][b]);
			g_Texture[20][b]=0;
		}
	}
    for (int b=0;b<int(texani[21][0]);b++){
		if (g_Texture[21][b]>0){
			glDeleteTextures(1,&g_Texture[21][b]);
			g_Texture[21][b]=0;
		}
	}
	if (currscreen==6){
		if (drummode&&!widemode){
			if (guitar1mode||guitar2mode){
				if (strlen(texstoload[17])>2)loadtexture(17,texstoload[17],int(texani[17][0]));
			}
		}
		if (drummode&&widemode){
			if (guitar1mode||guitar2mode){
				if (strlen(texstoload[18])>2)loadtexture(18,texstoload[18],int(texani[18][0]));
			}
		}
		if (drummode&&!guitar1mode&&!guitar2mode){
			if (strlen(texstoload[20])>2)loadtexture(20,texstoload[20],int(texani[20][0]));
		}
		if (!drummode){
			if (strlen(texstoload[21])>2)loadtexture(21,texstoload[21],int(texani[21][0]));
		}
	}
}

void loadtextureondemand(){
	#ifdef EXCESSIVE
	printf("loadtextureondemand\n");
	#endif
	if (currscreen==4&&prevscreen==5)
	return;
	if (currscreen==5&&prevscreen==4)
	return;
	if (currscreen==7||currscreen==8||currscreen==9||currscreen==10||currscreen==17){
		if (prevscreen==2){
			return;
		}
	}
	if (currscreen==2){
		if (prevscreen==7||prevscreen==8||prevscreen==9||prevscreen==10||prevscreen==17){
			return;
		}
	}
	for (int a=0;a<numoftexs;a++){
		for (int b=0;b<int(texani[a][0]);b++){
			if (g_Texture[a][b]>0){
				glDeleteTextures(1,&g_Texture[a][b]);
				g_Texture[a][b]=0;
			}
		}
	}
	if (currscreen==21){
		if (strlen(texstoload[71])>2)loadtexture(71,texstoload[71],int(texani[71][0]));
	}
	if (currscreen==1||currscreen==2||currscreen==7||currscreen==8||currscreen==9||currscreen==10||currscreen==17){
		if (strlen(texstoload[1])>2)loadtexture(1,texstoload[1],int(texani[1][0]));
		if (strlen(texstoload[2])>2)loadtexture(2,texstoload[2],int(texani[2][0]));
		if (strlen(texstoload[55])>2)loadtexture(55,texstoload[55],int(texani[55][0]));				
	}
	if (currscreen==2||currscreen==7||currscreen==8||currscreen==9||currscreen==10||currscreen==17){
		if (strlen(texstoload[3])>2)loadtexture(3,texstoload[3],int(texani[3][0]));
		if (strlen(texstoload[4])>2)loadtexture(4,texstoload[4],int(texani[4][0]));
	}
	if (currscreen==4||currscreen==5){
		if (strlen(texstoload[5])>2)loadtexture(5,texstoload[5],int(texani[5][0]));
		if (strlen(texstoload[8])>2)loadtexture(8,texstoload[8],int(texani[8][0]));		
		if (strlen(texstoload[9])>2)loadtexture(9,texstoload[9],int(texani[9][0]));		
		if (strlen(texstoload[10])>2)loadtexture(10,texstoload[10],int(texani[10][0]));		
		if (strlen(texstoload[11])>2)loadtexture(11,texstoload[11],int(texani[11][0]));		
		if (strlen(texstoload[12])>2)loadtexture(12,texstoload[12],int(texani[12][0]));		
		if (strlen(texstoload[14])>2)loadtexture(14,texstoload[14],int(texani[14][0]));
		if (strlen(texstoload[15])>2)loadtexture(15,texstoload[15],int(texani[15][0]));					
		if (strlen(texstoload[16])>2)loadtexture(16,texstoload[16],int(texani[16][0]));
		if (strlen(texstoload[19])>2)loadtexture(19,texstoload[19],int(texani[19][0]));					
		if (strlen(texstoload[53])>2)loadtexture(53,texstoload[53],int(texani[53][0]));
		if (strlen(texstoload[54])>2)loadtexture(54,texstoload[54],int(texani[54][0]));					
		if (strlen(texstoload[68])>2)loadtexture(68,texstoload[68],int(texani[68][0]));									
	}
	if (currscreen==14){
		if (strlen(texstoload[46])>2)loadtexture(46,texstoload[46],int(texani[46][0]));							
		if (strlen(texstoload[47])>2)loadtexture(47,texstoload[47],int(texani[47][0]));							
	}
	if (currscreen==12){
		if (strlen(texstoload[48])>2)loadtexture(48,texstoload[48],int(texani[48][0]));
		if (strlen(texstoload[49])>2)loadtexture(49,texstoload[49],int(texani[49][0]));
	}
	if (currscreen==13){
		if (strlen(texstoload[72])>2)loadtexture(72,texstoload[72],int(texani[72][0]));
		if (strlen(texstoload[73])>2)loadtexture(73,texstoload[73],int(texani[73][0]));
		if (strlen(texstoload[50])>2)loadtexture(50,texstoload[50],int(texani[50][0]));
        #ifndef DEBUG
		if (strlen(texstoload[40])>2)loadtexture(40,texstoload[40],int(texani[40][0]));
		#endif
	}
	if (currscreen==20){
		if (strlen(texstoload[67])>2)loadtexture(67,texstoload[67],int(texani[67][0]));
        #ifndef DEBUG
		if (strlen(texstoload[40])>2)loadtexture(40,texstoload[40],int(texani[40][0]));
		#endif
	}
	if (currscreen==6){
		if (drummode&&!widemode){
			if (guitar1mode||guitar2mode){
				if (strlen(texstoload[17])>2)loadtexture(17,texstoload[17],int(texani[17][0]));
			}
		}
		if (drummode&&widemode){
			if (guitar1mode||guitar2mode){
				if (strlen(texstoload[18])>2)loadtexture(18,texstoload[18],int(texani[18][0]));					
			}
		}
		if (drummode&&!guitar1mode&&!guitar2mode){
			if (strlen(texstoload[20])>2)loadtexture(20,texstoload[20],int(texani[20][0]));					
		}
		if (!drummode){
			if (strlen(texstoload[21])>2)loadtexture(21,texstoload[21],int(texani[21][0]));					
		}
		if (strlen(texstoload[33])>2)loadtexture(33,texstoload[33],int(texani[33][0]));					
		if (strlen(texstoload[34])>2)loadtexture(34,texstoload[34],int(texani[34][0]));					
		if (strlen(texstoload[35])>2)loadtexture(35,texstoload[35],int(texani[35][0]));					
		if (strlen(texstoload[36])>2)loadtexture(36,texstoload[36],int(texani[36][0]));					
		if (strlen(texstoload[37])>2)loadtexture(37,texstoload[37],int(texani[37][0]));					
        //#ifndef DEBUG
		if (strlen(texstoload[40])>2)loadtexture(40,texstoload[40],int(texani[40][0]));
		//#endif
		if (strlen(texstoload[41])>2)loadtexture(41,texstoload[41],int(texani[41][0]));
		if (strlen(texstoload[63])>2)loadtexture(63,texstoload[63],int(texani[63][0]));					
		if (strlen(texstoload[64])>2)loadtexture(64,texstoload[64],int(texani[64][0]));					
		if (strlen(texstoload[42])>2)loadtexture(42,texstoload[42],int(texani[42][0]));					
		if (strlen(texstoload[43])>2)loadtexture(43,texstoload[43],int(texani[43][0]));					
		if (strlen(texstoload[44])>2)loadtexture(44,texstoload[44],int(texani[44][0]));					
		if (strlen(texstoload[45])>2)loadtexture(45,texstoload[45],int(texani[45][0]));					
		if (strlen(texstoload[52])>2)loadtexture(52,texstoload[52],int(texani[52][0]));					
		if (strlen(texstoload[62])>2)loadtexture(62,texstoload[62],int(texani[62][0]));	
		if (strlen(texstoload[69])>2)loadtexture(69,texstoload[69],int(texani[69][0]));	
		for (int a=22;a<=39;a++){
			if (strlen(texstoload[a])>2)loadtexture(a,texstoload[a],int(texani[a][0]));	
		}
		for (int a=57;a<=61;a++){
			if (strlen(texstoload[a])>2)loadtexture(a,texstoload[a],int(texani[a][0]));	
		}
		if (strlen(texstoload[46])>2)loadtexture(46,texstoload[46],int(texani[46][0]));							
		if (strlen(texstoload[47])>2)loadtexture(47,texstoload[47],int(texani[47][0]));							
		if (strlen(texstoload[48])>2)loadtexture(48,texstoload[48],int(texani[48][0]));
		if (strlen(texstoload[49])>2)loadtexture(49,texstoload[49],int(texani[49][0]));
	}
	#ifdef DEBUG
	if (strlen(texstoload[40])>2)loadtexture(40,texstoload[40],int(texani[40][0]));
	#endif
	if (strlen(texstoload[13])>2)loadtexture(13,texstoload[13],int(texani[13][0]));
	if (strlen(texstoload[65])>2)loadtexture(65,texstoload[65],int(texani[65][0]));
	if (strlen(texstoload[66])>2)loadtexture(66,texstoload[66],int(texani[66][0]));					
	if (strlen(texstoload[51])>2)loadtexture(51,texstoload[51],int(texani[51][0]));						
}
