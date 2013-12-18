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
tileeffect::tileeffect(){
	tileeffect("seijinohki",50);
}

tileeffect::tileeffect(char text[256],int depth){
	strcpylwr(text,thetext);
	tilesleft=depth;
	scrambledepth=depth;
	tilesx=(strlen(thetext)*5)+strlen(thetext)+1;
	tilesy=7;
	tiles=(int **)malloc(sizeof(int*) * tilesx);
	for (int a=0;a<tilesx;a++){
		tiles[a]=(int *)malloc(sizeof(int)*tilesy);
		for (int b=0;b<tilesy;b++){
			tiles[a][b]=0;
		}
	}
	//0=off 1=on 2=the hole
	for (int b=0;b<strlen(thetext);b++){
		int c=b*6;
		switch(thetext[b]){
			case 'a':
				tiles[c+1][1]=1;
				tiles[c+1][2]=1;
				tiles[c+1][3]=1;
				tiles[c+1][4]=1;
				tiles[c+2][5]=1;
				tiles[c+3][5]=1;
				tiles[c+4][5]=1;
				tiles[c+2][3]=1;
				tiles[c+3][3]=1;
				tiles[c+4][3]=1;
				break;
			case 'e':
				tiles[c+1][1]=1;
				tiles[c+1][2]=1;
				tiles[c+1][3]=1;
				tiles[c+1][4]=1;
				tiles[c+1][5]=1;
				tiles[c+2][1]=1;
				tiles[c+2][3]=1;
				tiles[c+2][5]=1;
				tiles[c+3][1]=1;
				tiles[c+3][3]=1;
				tiles[c+3][5]=1;
				tiles[c+4][1]=1;
				tiles[c+4][3]=1;
				tiles[c+4][5]=1;
				tiles[c+5][1]=1;
				tiles[c+5][3]=1;
				tiles[c+5][5]=1;
				break;
			case 'h':
				tiles[c+1][1]=1;
				tiles[c+1][2]=1;
				tiles[c+1][3]=1;
				tiles[c+1][4]=1;
				tiles[c+1][5]=1;
				tiles[c+5][1]=1;
				tiles[c+5][2]=1;
				tiles[c+5][3]=1;
				tiles[c+5][4]=1;
				tiles[c+5][5]=1;
				tiles[c+2][3]=1;
				tiles[c+3][3]=1;
				tiles[c+4][3]=1;
				break;
			case 'i':
   				tiles[c+1][1]=1;
   				tiles[c+2][1]=1;
   				tiles[c+3][1]=1;
   				tiles[c+4][1]=1;
   				tiles[c+5][1]=1;
   				tiles[c+1][5]=1;
   				tiles[c+2][5]=1;
   				tiles[c+3][5]=1;
   				tiles[c+4][5]=1;
   				tiles[c+5][5]=1;
   				tiles[c+3][2]=1;
   				tiles[c+3][3]=1;
   				tiles[c+3][4]=1;
   				break;
			case 'j':
   				tiles[c+1][2]=1;
   				tiles[c+1][1]=1;
   				tiles[c+2][1]=1;
   				tiles[c+3][1]=1;
   				tiles[c+3][2]=1;
   				tiles[c+3][3]=1;
   				tiles[c+3][4]=1;
   				tiles[c+3][5]=1;
   				tiles[c+2][5]=1;
   				tiles[c+1][5]=1;
   				tiles[c+4][5]=1;
   				tiles[c+5][5]=1;
   				break;
			case 'k':
   				tiles[c+1][1]=1;
   				tiles[c+1][2]=1;
   				tiles[c+1][3]=1;
   				tiles[c+1][4]=1;
   				tiles[c+1][5]=1;
   				tiles[c+2][3]=1;
   				tiles[c+3][3]=1;
   				tiles[c+4][4]=1;
   				tiles[c+4][2]=1;
   				tiles[c+5][5]=1;
   				tiles[c+5][1]=1;
   				break;
			case 'n':
   				tiles[c+1][1]=1;
   				tiles[c+1][2]=1;
   				tiles[c+1][3]=1;
   				tiles[c+1][4]=1;
   				tiles[c+1][5]=1;
   				tiles[c+2][4]=1;
   				tiles[c+3][3]=1;
   				tiles[c+4][2]=1;
   				tiles[c+5][1]=1;
   				tiles[c+5][2]=1;
   				tiles[c+5][3]=1;
   				tiles[c+5][4]=1;
   				tiles[c+5][5]=1;
   				break;
			case 'o':
   				tiles[c+2][1]=1;
   				tiles[c+3][1]=1;
   				tiles[c+4][1]=1;
   				tiles[c+2][5]=1;
   				tiles[c+3][5]=1;
   				tiles[c+4][5]=1;
   				tiles[c+1][2]=1;
   				tiles[c+1][3]=1;
   				tiles[c+1][4]=1;
   				tiles[c+5][2]=1;
   				tiles[c+5][3]=1;
   				tiles[c+5][4]=1;
   				break;
			case 's':
   				tiles[c+1][1]=1;
   				tiles[c+2][1]=1;
   				tiles[c+3][1]=1;
   				tiles[c+4][1]=1;
   				tiles[c+5][2]=1;
   				tiles[c+4][3]=1;
   				tiles[c+3][3]=1;
   				tiles[c+2][3]=1;
   				tiles[c+1][4]=1;
   				tiles[c+2][5]=1;
   				tiles[c+3][5]=1;
   				tiles[c+4][5]=1;
   				tiles[c+5][5]=1;
   				break;
		}
	}
	for (int a=0;a<3;a++){
		moves[a]=(int*)malloc(sizeof(int)*scrambledepth);
		for (int b=0;b<scrambledepth;b++){
			moves[a][b]=0;
		}
	}
	tiles[0][0]=2;
	okaytomove=false;
}

tileeffect::~tileeffect(){
	for (int a=0;a<tilesy;a++){
		free(tiles[a]);
	}
	for (int a=0;a<3;a++){
		free(moves[a]);
	}
	free(tiles);
}

void tileeffect::draw(int x, int y, int z, int s){
	static int tilespin=0;
	tilespin+=steptime;
	okaytomove+=steptime;
	if (tilesleft<=0&&tilesleft>-128){
		for (int a=0;a<tilesx;a++){
			for (int b=0;b<tilesy;b++){
				if (tiles[a][b]==1){
                    draw_quad(0,x+int(a*(s*1.25)),y+int(b*(s*1.25)),z,s/2+abs(int(tilesleft)),s/2+abs(int(tilesleft)),255,0,0,127+tilesleft,0,0,51);
				}
				if (tiles[a][b]==0){
					draw_quad(0,x+int(a*(s*1.25)),y+int(b*(s*1.25)),z,s/2+abs(int(tilesleft)),s/2+abs(int(tilesleft)),0,0,255,(127+tilesleft)/4,0,0,51);
				}
			}
		}
	}
	for (int a=0;a<tilesx;a++){
		for (int b=0;b<tilesy;b++){
			bool spin=false;
			for (int c=0;c<tilesleft;c++){
				if (moves[0][c]==a&&moves[1][c]==b)
				    spin=true;
			}
			if (tiles[a][b]==1){
				if (spin){
					draw_quad(0,x+int(a*(s*1.25)),y+int(b*(s*1.1)),z,s/2,s/2,255,0,0,255,0,tilespin,51);
                }else{
					draw_quad(0,x+int(a*(s*1.25)),y+int(b*(s*1.1)),z,s/2,s/2,255,0,0,255,0,0,51);
				}
			}
			if (tiles[a][b]==0){
				if (spin){
					draw_quad(0,x+int(a*(s*1.25)),y+int(b*(s*1.1)),z,s/2,s/2,0,0,255,63,0,tilespin,51);
				}else{
					draw_quad(0,x+int(a*(s*1.25)),y+int(b*(s*1.1)),z,s/2,s/2,0,0,255,63,0,0,51);
				}
			}
		}
	}
	while (okaytomove>16){
		okaytomove-=16;
		tilesleft--;
		if (tilesleft>-1){
			int color=tiles[moves[0][tilesleft]][moves[1][tilesleft]];
			tiles[moves[0][tilesleft]][moves[1][tilesleft]]=tiles[curspos[0]][curspos[1]];
			tiles[curspos[0]][curspos[1]]=color;
			//0=up, 1=left, 2=down, 3=right
			if (moves[2][tilesleft]==0){
				curspos[1]++;
			}
			if (moves[2][tilesleft]==2){
				curspos[1]--;
			}
			if (moves[2][tilesleft]==1){
				curspos[0]--;
			}
			if (moves[2][tilesleft]==3){
				curspos[0]++;
			}
			if (curspos[0]<0)curspos[0]=0;
			if (curspos[0]>tilesx)curspos[0]=tilesx;
			if (curspos[1]<0)curspos[1]=0;
			if (curspos[1]>tilesy)curspos[0]=tilesy;
 		}
	}
	if (tilesleft<-138){
		isdone=true;
	}
}

void tileeffect::reset(){
	scramble();
	tilesleft=scrambledepth;
	isdone=false;
}

void tileeffect::scramble(){
	curspos[0]=0;
	curspos[1]=0;
	bool favorright=true;
	for (int a=0;a<scrambledepth;a++){
		moves[0][a]=curspos[0];
		moves[1][a]=curspos[1];
		moves[2][a]=int(5*(double(rand())/double(RAND_MAX)));
		//0=down, 1=right, 2=up, 3=left.
		if (moves[2][a]<0){
			if (favorright)moves[2][a]=1;
			else moves[2][a]=3;
		}
		if (moves[2][a]>3){
			if (favorright)moves[2][a]=1;
			else moves[2][a]=3;
		}
		if (moves[0][a]<=0&&moves[2][a]==3){
			if (favorright){
				moves[2][a]=1;
   			}else{
				favorright=true;
				moves[2][a]=1;
			}
		}
		if (moves[1][a]<=0&&moves[2][a]==0){
			if (favorright)moves[2][a]=1;
			else moves[2][a]=3;
		}
		if (moves[1][a]>=tilesy-1&&moves[2][a]==2){
			if (favorright)moves[2][a]=1;
			else moves[2][a]=3;
		}
		if (moves[0][a]>=tilesx-1&&moves[2][a]==1){
			if (favorright){
				favorright=false;
				moves[2][a]=3;
			}else{
				moves[2][a]=3;
			}
		}
		if (moves[2][a]==0){
			curspos[1]--;
		}
		if (moves[2][a]==2){
			curspos[1]++;
		}
		if (moves[2][a]==1){
			curspos[0]++;
		}
		if (moves[2][a]==3){
			curspos[0]--;
		}
		if (curspos[0]<0){
			curspos[0]=0;
			moves[2][a]=4;
		}
		if (curspos[0]>tilesx){
			curspos[0]=tilesx;
			moves[2][a]=4;
		}
		if (curspos[1]<0){
			curspos[1]=0;
			moves[2][a]=4;
		}
		if (curspos[1]>tilesy){
			curspos[0]=tilesy;
			moves[2][a]=4;
		}
		int swap=tiles[moves[0][a]][moves[1][a]];
		tiles[moves[0][a]][moves[1][a]]=tiles[curspos[0]][curspos[1]];
		tiles[curspos[0]][curspos[1]]=swap;
	}
}
