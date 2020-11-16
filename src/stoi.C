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

double absv(double marmot){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::absv\n");
	#endif
	#endif
	if (marmot<0)
	return -marmot;
	else
	return marmot;
}

char *strlwr2(char *marmot){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::strlwr\n");
	#endif
	#endif
	for (int a=0;a<strlen(marmot);a++){
		if (marmot[a]>='A' &&marmot[a]<='Z' ){
			marmot[a]=marmot[a]+32;
		}
	}
	return marmot;
}

void strcpylwr(char *marmot, char *ferret){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::strlwr\n");
	#endif
	#endif
	for (int a=0;a<strlen(marmot);a++){
		if (marmot[a]>='A' &&marmot[a]<='Z' ){
			ferret[a]=marmot[a]+32;
		}else{
			ferret[a]=marmot[a];
		}
	}
	return;
}

uint8_t stoh(char input[256],int value){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::stoh\n");
	#endif
	#endif
	if (value>127)
		return 0x00;
	uint8_t byte=0x00;
	if (strlen(input)==1||strlen(input)==3||strlen(input)==5||strlen(input)==7||strlen(input)==9||strlen(input)==11||strlen(input)==13){
		char temp[256];
		snprintf(temp,255, "0%s", input);
		snprintf(input,255, "%s", temp);
	}
	if ((value*2)>strlen(input)){
		return 0x00;
	}
	switch(input[(value-1)*2]){
		case '1':
			byte=byte+0x10;
			break;
		case '2':
			byte=byte+0x20;
			break;
		case '3':
			byte=byte+0x30;
			break;
		case '4':
			byte=byte+0x40;
			break;
		case '5':
			byte=byte+0x50;
			break;
		case '6':
			byte=byte+0x60;
			break;
		case '7':
			byte=byte+0x70;
			break;
		case '8':
			byte=byte+0x80;
			break;
		case '9':
			byte=byte+0x90;
			break;
		case 'a':
			byte=byte+0xA0;
			break;
		case 'b':
			byte=byte+0xB0;
			break;
		case 'c':
			byte=byte+0xC0;
			break;
		case 'd':
			byte=byte+0xD0;
			break;
		case 'e':
			byte=byte+0xE0;
			break;
		case 'f':
			byte=byte+0xF0;
			break;
	}
	switch(input[(value-1)*2+1]){
		case '1':
			byte=byte+0x01;
			break;
		case '2':
			byte=byte+0x02;
			break;
		case '3':
			byte=byte+0x03;
			break;
		case '4':
			byte=byte+0x04;
			break;
		case '5':
			byte=byte+0x05;
			break;
		case '6':
			byte=byte+0x06;
			break;
		case '7':
			byte=byte+0x07;
			break;
		case '8':
			byte=byte+0x08;
			break;
		case '9':
			byte=byte+0x09;
			break;
		case 'a':
			byte=byte+0x0A;
			break;
		case 'b':
			byte=byte+0x0B;
			break;
		case 'c':
			byte=byte+0x0C;
			break;
		case 'd':
			byte=byte+0x0D;
			break;
		case 'e':
			byte=byte+0x0E;
			break;
		case 'f':
			byte=byte+0x0F;
			break;
	}
	return byte;
}

char *btos(bool marmot){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::btos\n");
	#endif
	#endif
	char *taco;
	if (marmot)
		taco="true";
	else
		taco="false";
	return taco;
}

void deadspace(char moo[256],int start,char cow[256]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::deadspace\n");
	#endif
	#endif
	char temp[256];
	int n=0;
	for(int x=0;x<255&&x<strlen(moo);x++){
		if(moo[x]!=' ')n=x+1;
	}
	for(int x=0;x<n;x++){
		temp[x]=moo[x+start];
	}
	temp[n]='\0';
	strcpy(cow,temp);
}

void truncatet(char moo[256],char cow[256]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::truncatet\n");
	#endif
	#endif
	static char temp[255];
	int n=0;
	while (moo[n]!=' '){
		temp[n]=moo[n];
		n++;
	}
	temp[n]='\0';
	strcpy(cow,temp);
}




void charlim(char marmot[256],int limit,char taco[256]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::charlim\n");
	#endif
	#endif
	static char temp[256];
	for (int i=0;i<limit;i++){
		temp[i]=marmot[i];
	}
	temp[limit]='\0';
	strcpy(taco,temp);
}




void ftos(double marmot,char taco[256]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::ftos\n");
	#endif
	#endif
	double ph=marmot;
	int len=0;
	while(ph>1){
		ph=int(ph);
		ph=ph/10;
		len=len+1;
	}
	//len=len-1;
	int step=0;
	ph=marmot;
	char temp[256];
	while(ph>1){
		ph=int(ph);
		ph=ph/10;
		int ph2=int(ph)*10;
		step=step+1;
		switch(int((ph*10)-ph2)){
			case 1:
				temp[len-step]='1';
				break;
			case 2:
				temp[len-step]='2';
				break;
			case 3:
				temp[len-step]='3';
				break;
			case 4:
				temp[len-step]='4';
				break;
			case 5:
				temp[len-step]='5';
				break;
			case 6:
				temp[len-step]='6';
				break;
			case 7:
				temp[len-step]='7';
				break;
			case 8:
				temp[len-step]='8';
				break;
			case 9:
				temp[len-step]='9';
				break;
			case 0:
				temp[len-step]='0';
				break;
		}
	}
	ph=marmot;
	ph=ph-int(ph);
	temp[step]='\0';
	strcpy(taco,temp);
}

long stoi(char marmot[256]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::stoi\n");
	#endif
	#endif
	long n=0;
	bool neg=false;
	long a=1;
	while(marmot[a]!='\0'){
		//printf("%c<",marmot[a]);
		switch(marmot[a]){
			case '-':
				neg=true;
				break;
			case '0':
				n*=10;
				n+=0;
				break;
			case '1':
				n*=10;
				n+=1;
				break;
			case '2':
				n*=10;
				n+=2;
				break;
			case '3':
				n*=10;
				n+=3;
				break;
			case '4':
				n*=10;
				n+=4;
				break;
			case '5':
				n*=10;
				n+=5;
				break;
			case '6':
				n*=10;
				n+=6;
				break;
			case '7':
				n*=10;
				n+=7;
				break;
			case '8':
				n*=10;
				n+=8;
				break;
			case '9':
				n*=10;
				n+=9;
				break;
		}
		a=a+1;
	}
	if (neg)n=0-n;
	return n;
}

int dbstoi(char marmot[256]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::dbstoi\n");
	#endif
	#endif
	int n=0;
	bool neg=false;
	int a=0;
	if (marmot!=NULL){
		while(marmot[a]!='\0'){
			if (marmot[a]<'0'||marmot[a]>'9'){
				return -1;
			}
			switch(marmot[a]){
				case '-':
					neg=true;
					break;
				case '0':
					n*=10;
					n+=0;
					break;
				case '1':
					n*=10;
					n+=1;
					break;
				case '2':
					n*=10;
					n+=2;
					break;
				case '3':
					n*=10;
					n+=3;
					break;
				case '4':
					n*=10;
					n+=4;
					break;
				case '5':
					n*=10;
					n+=5;
					break;
				case '6':
					n*=10;
					n+=6;
					break;
				case '7':
					n*=10;
					n+=7;
					break;
				case '8':
					n*=10;
					n+=8;
					break;
				case '9':
					n*=10;
					n+=9;
					break;
			}
			a=a+1;
		}
	}
	if (neg)n=0-n;
	return n;
}

int dbstof5f(char marmot[256]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::dbstof5f\n");
	#endif
	#endif
	int n=0;
	bool neg=false;
	int a=0;
	double decs=-1;
	bool dec=false;
	while(marmot[a]!='\0'){
		switch(marmot[a]){
			case '-':
				neg=true;
				break;
			case '0':
				n*=10;
				break;
			case '1':
				n*=10;
				n+=1;
				break;
			case '2':
				n*=10;
				n+=2;
				break;
			case '3':
				n*=10;
				n+=3;
				break;
			case '4':
				n*=10;
				n+=4;
				break;
			case '5':
				n*=10;
				n+=5;
				break;
			case '6':
				n*=10;
				n+=6;
				break;
			case '7':
				n*=10;
				n+=7;
				break;
			case '8':
				n*=10;
				n+=8;
				break;
			case '9':
				n*=10;
				n+=9;
				break;
			case '.':
				dec=true;
				break;
		}
		a=a+1;
		if (dec)decs++;
	}
	if (neg)n=0-n;
	if (dec){
		n=n*int(pow(10.0,5-decs));
	}else{
		n=n*100000;
	}
	return n;
}

double dbstof(char marmot[256]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::dbstof\n");
	#endif
	#endif
	int n=0;
	double result=0;
	bool neg=false;
	int a=0;
	double decs=-1;
	bool dec=false;
	while(marmot[a]!='\0'){
		switch(marmot[a]){
			case '-':
				neg=true;
				break;
			case '0':
				n*=10;
				break;
			case '1':
				n*=10;
				n+=1;
				break;
			case '2':
				n*=10;
				n+=2;
				break;
			case '3':
				n*=10;
				n+=3;
				break;
			case '4':
				n*=10;
				n+=4;
				break;
			case '5':
				n*=10;
				n+=5;
				break;
			case '6':
				n*=10;
				n+=6;
				break;
			case '7':
				n*=10;
				n+=7;
				break;
			case '8':
				n*=10;
				n+=8;
				break;
			case '9':
				n*=10;
				n+=9;
				break;
			case '.':
				dec=true;
				break;
		}
		a=a+1;
		if (dec)decs++;
	}
	if (neg)n=0-n;
	result=n;
	if (dec){
		result=double(n)/pow(10.0,decs);
	}
	return result;
}

void itos(int marmot,char taco[256]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::itos\n");
	#endif
	#endif
	int ph=marmot;
	int len=0;
	while(ph>1){
		ph=int(ph);
		ph=ph/10;
		int ph2=int(ph)*10;
		len=len+1;
	}
	//len=len-1;
	int step=0;
	ph=marmot;
	static char temp[256];

	while(ph>1){
		ph=int(ph);
		ph=ph/10;
		int ph2=int(ph)*10;
		step=step+1;
		switch(int((ph*10)-ph2)){
		case 1:
			temp[len-step]='1';
			break;
		case 2:
			temp[len-step]='2';
			break;
		case 3:
			temp[len-step]='3';
			break;
		case 4:
			temp[len-step]='4';
			break;
		case 5:
			temp[len-step]='5';
			break;
		case 6:
			temp[len-step]='6';
			break;
		case 7:
			temp[len-step]='7';
			break;
		case 8:
			temp[len-step]='8';
			break;
		case 9:
			temp[len-step]='9';
			break;
		case 0:
			temp[len-step]='0';
			break;
		}
	}
	ph=marmot;
	ph=ph-int(ph);
	temp[step]='\0';
	strcpy(taco,temp);
	if (taco[0]=='\0'){
		return;
	}else{
		taco[0]='0';
	}
}

double dbstod(char marmot[256]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::dbstod\n");
	#endif
	#endif
	double n=0.00;
	bool neg=false;
	int a=0;
	while(marmot[a]!='\0'){
		//printf("%c<",marmot[a]);
		switch(marmot[a]){
			case '-':
				neg=true;
				break;
			case '0':
				n=n*10.0;
				n=n+0.00;
				break;
			case '1':
				n=n*10.00;
				n=n+1.00;
				break;
			case '2':
				n=n*10.00;
				n=n+2.00;
				break;
			case '3':
				n=n*10.00;
				n=n+3.00;
				break;
			case '4':
				n=n*10.00;
				n=n+4.00;
				break;
			case '5':
				n=n*10.00;
				n=n+5.00;
				break;
			case '6':
				n=n*10.00;
				n=n+6.00;
				break;
			case '7':
				n=n*10.00;
				n=n+7.00;
				break;
			case '8':
				n=n*10.00;
				n=n+8.00;
				break;
			case '9':
				n=n*10.00;
				n=n+9.00;
				break;
		}
		a=a+1;
	}
	if (neg)n=0-n;
	n=n/100.00;
	return n;
}

void dollarize(char input[256],char output[256]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::dollarize\n");
	#endif
	#endif
	char temp[256];
	for(int x=0;x<256;x++)temp[x]='\0';
	int a=0;
	int n=0;
	int decimals=0;
	bool period=false;
	while(input[a]!='\0'){
		temp[a]=input[a];
		if (temp[n]=='.')period=true;
		if (period)decimals++;
		if (!period)n++;
		a++;
	}
	if (decimals==2){
		temp[n+decimals]='0';
		temp[n+decimals+1]='\0';
	}
	if (decimals>3){
		for(int x=3;x<(a+1);x++)temp[n+x]='\0';
	}
	if (decimals==0){
		temp[n]='.';
		temp[n+1]='0';
		temp[n+2]='0';
		temp[n+3]='\0';
	}
	strcpy(output,temp);
}


int wavetoi(char temp[256]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::wavetoi\n");
	#endif
	#endif
	int output=0;
	switch(temp[5]){
		case '1':
			output=1;
			break;
		case '2':
			output=2;
			break;
		case '3':
			output=3;
			break;
		case '4':
			output=4;
			break;
		case '5':
			output=5;
			break;
		case '6':
			output=6;
			break;
		case '7':
			output=7;
			break;
		case '8':
			output=8;
			break;
		case '9':
			output=9;
			break;
		case 'a':
			output=10;
			break;
		case 'b':
			output=11;
			break;
		case 'c':
			output=12;
			break;
		case 'd':
			output=13;
			break;
		case 'e':
			output=14;
			break;
		case 'f':
			output=15;
			break;
	}
	switch (temp[4]){
		case '1':
			output=output+(16 * 1);
			break;
		case '2':
			output=output+(16 * 2);
			break;
		case '3':
			output=output+(16 * 3);
			break;
		case '4':
			output=output+(16 * 4);
			break;
		case '5':
			output=output+(16 * 5);
			break;
		case '6':
			output=output+(16 * 6);
			break;
		case '7':
			output=output+(16 * 7);
			break;
		case '8':
			output=output+(16 * 8);
			break;
		case '9':
			output=output+(16 * 9);
			break;
		case 'a':
			output=output+(16 * 10);
			break;
		case 'b':
			output=output+(16 * 11);
			break;
		case 'c':
			output=output+(16 * 12);
			break;
		case 'd':
			output=output+(16 * 13);
			break;
		case 'e':
			output=output+(16 * 14);
			break;
		case 'f':
			output=output+(16 * 15);
			break;
	}
	return output;
}

int hextoi(char moo){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::hextoi\n");
	#endif
	#endif
	int output=0;
	switch(moo){
		case '1':
			output=1;
			break;
		case '2':
			output=2;
			break;
		case '3':
			output=3;
			break;
		case '4':
			output=4;
			break;
		case '5':
			output=5;
			break;
		case '6':
			output=6;
			break;
		case '7':
			output=7;
			break;
		case '8':
			output=8;
			break;
		case '9':
			output=9;
			break;
		case 'a':
			output=10;
			break;
		case 'b':
			output=11;
			break;
		case 'c':
			output=12;
			break;
		case 'd':
			output=13;
			break;
		case 'e':
			output=14;
			break;
		case 'f':
			output=15;
			break;
	}
	return output;
}

int hextoi2(char moo[10]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::hextoi2\n");
	#endif
	#endif
	int output=0;
	switch(moo[0]){
		case '1':
			output=1*16;
			break;
		case '2':
			output=2*16;
			break;
		case '3':
			output=3*16;
			break;
		case '4':
			output=4*16;
			break;
		case '5':
			output=5*16;
			break;
		case '6':
			output=6*16;
			break;
		case '7':
			output=7*16;
			break;
		case '8':
			output=8*16;
			break;
		case '9':
			output=9*16;
			break;
		case 'a':
			output=10*16;
			break;
		case 'b':
			output=11*16;
			break;
		case 'c':
			output=12*16;
			break;
		case 'd':
			output=13*16;
			break;
		case 'e':
			output=14*16;
			break;
		case 'f':
			output=15*16;
			break;
	}
	switch(moo[1]){
		case '1':
			output=output+1;
			break;
		case '2':
			output=output+2;
			break;
		case '3':
			output=output+3;
			break;
		case '4':
			output=output+4;
			break;
		case '5':
			output=output+5;
			break;
		case '6':
			output=output+6;
			break;
		case '7':
			output=output+7;
			break;
		case '8':
			output=output+8;
			break;
		case '9':
			output=output+9;
			break;
		case 'a':
			output=output+10;
			break;
		case 'b':
			output=output+11;
			break;
		case 'c':
			output=output+12;
			break;
		case 'd':
			output=output+13;
			break;
		case 'e':
			output=output+14;
			break;
		case 'f':
			output=output+15;
			break;
	}
	return output;
}

long alphatoi(char moo[10]){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::alphatoi\n");
	#endif
	#endif
	long output=0;
	switch(moo[0]){
		case '1':
			output=1*36;
			break;
		case '2':
			output=2*36;
			break;
		case '3':
			output=3*36;
			break;
		case '4':
			output=4*36;
			break;
		case '5':
			output=5*36;
			break;
		case '6':
			output=6*36;
			break;
		case '7':
			output=7*36;
			break;
		case '8':
			output=8*36;
			break;
		case '9':
			output=9*36;
			break;
		case 'a':
			output=10*36;
			break;
		case 'b':
			output=11*36;
			break;
		case 'c':
			output=12*36;
			break;
		case 'd':
			output=13*36;
			break;
		case 'e':
			output=14*36;
			break;
		case 'f':
			output=15*36;
			break;
		case 'g':
			output=16*36;
			break;
		case 'h':
			output=17*36;
			break;
		case 'i':
			output=18*36;
			break;
		case 'j':
			output=19*36;
			break;
		case 'k':
			output=20*36;
			break;
		case 'l':
			output=21*36;
			break;
		case 'm':
			output=22*36;
			break;
		case 'n':
			output=23*36;
			break;
		case 'o':
			output=24*36;
			break;
		case 'p':
			output=25*36;
			break;
		case 'q':
			output=26*36;
			break;
		case 'r':
			output=27*36;
			break;
		case 's':
			output=28*36;
			break;
		case 't':
			output=29*36;
			break;
		case 'u':
			output=30*36;
			break;
		case 'v':
			output=31*36;
			break;
		case 'w':
			output=32*36;
			break;
		case 'x':
			output=33*36;
			break;
		case 'y':
			output=34*36;
			break;
		case 'z':
			output=35*36;
			break;
	}
	switch(moo[1]){
		case '1':
			output=output+1;
			break;
		case '2':
			output=output+2;
			break;
		case '3':
			output=output+3;
			break;
		case '4':
			output=output+4;
			break;
		case '5':
			output=output+5;
			break;
		case '6':
			output=output+6;
			break;
		case '7':
			output=output+7;
			break;
		case '8':
			output=output+8;
			break;
		case '9':
			output=output+9;
			break;
		case 'a':
			output=output+10;
			break;
		case 'b':
			output=output+11;
			break;
		case 'c':
			output=output+12;
			break;
		case 'd':
			output=output+13;
			break;
		case 'e':
			output=output+14;
			break;
		case 'f':
			output=output+15;
			break;
		case 'g':
			output=output+16;
			break;
		case 'h':
			output=output+17;
			break;
		case 'i':
			output=output+18;
			break;
		case 'j':
			output=output+19;
			break;
		case 'k':
			output=output+20;
			break;
		case 'l':
			output=output+21;
			break;
		case 'm':
			output=output+22;
			break;
		case 'n':
			output=output+23;
			break;
		case 'o':
			output=output+24;
			break;
		case 'p':
			output=output+25;
			break;
		case 'q':
			output=output+26;
			break;
		case 'r':
			output=output+27;
			break;
		case 's':
			output=output+28;
			break;
		case 't':
			output=output+29;
			break;
		case 'u':
			output=output+30;
			break;
		case 'v':
			output=output+31;
			break;
		case 'w':
			output=output+32;
			break;
		case 'x':
			output=output+33;
			break;
		case 'y':
			output=output+34;
			break;
		case 'z':
			output=output+35;
			break;
	}
	return output;
}

char *keytochar(int key){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("stoi::keytochar\n");
	#endif
	#endif
	static char marmot[256];
	if (key>=33&&key<=126){
		marmot[0]=(char)key;
		marmot[1]='\0';
	}
	if (key==32)
		snprintf(marmot,255,"spacebar");
	if (key==13)
		snprintf(marmot,255,"enter");
	if (key==304)
		snprintf(marmot,255,"left shift");
	if (key==306)
		snprintf(marmot,255,"left ctrl");
	if (key==308)
		snprintf(marmot,255,"left alt");
	if (key==310)
		snprintf(marmot,255,"win key");
	if (key==319)
		snprintf(marmot,255,"menu key");
	if (key==9)
		snprintf(marmot,255,"tab");
	if (key==301)
		snprintf(marmot,255,"caps lock");
	if (key==27)
		snprintf(marmot,255,"escape");
	if (key>=282&&key<=293)
		snprintf(marmot,255,"F%i", 283-key);
	if (key==302)
		snprintf(marmot,255,"scroll");
	if (key==19)
		snprintf(marmot,255,"pause");
	if (key==277)
		snprintf(marmot,255,"insert");
	if (key==127)
		snprintf(marmot,255,"delete");
	if (key==300)
		snprintf(marmot,255,"numlock");
	if (key==306)
		snprintf(marmot,255,"break");
	if (key==317)
		snprintf(marmot,255,"print screen");
	if (key==278)
		snprintf(marmot,255,"home");
	if (key==280)
		snprintf(marmot,255,"page up");
	if (key==281)
		snprintf(marmot,255,"page down");
	if (key==279)
		snprintf(marmot,255,"end");
	if (key==8)
		snprintf(marmot,255,"backspace");
	if (key==303)
		snprintf(marmot,255,"right shift");
	if (key==305)
		snprintf(marmot,255,"right ctrl");
	if (key==307)
		snprintf(marmot,255,"right alt");
	if (key==276)
		snprintf(marmot,255,"left");
	if (key==275)
		snprintf(marmot,255,"right");
	if (key==274)
		snprintf(marmot,255,"down");
	if (key==273)
		snprintf(marmot,255,"up");
	if (key>=256&&key<=265)
		snprintf(marmot,255,"num pad %i", key-256);
	if (key==266)
		snprintf(marmot,255,"num pad .");
	if (key==270)
		snprintf(marmot,255,"num pad +");
	if (key==267)
		snprintf(marmot,255,"num pad /");
	if (key==268)
		snprintf(marmot,255,"num pad *");
	if (key==269)
		snprintf(marmot,255,"num pad -");
	if (key==271)
		snprintf(marmot,255,"num pad enter");
	if (key>=1000&&key<100000){
		int joy=key/1000;
		int button=key-(joy*1000);
		snprintf(marmot,255,"joy %i button %i", joy,button);
	}
	if (key>=100000)
		snprintf(marmot,255,"midi %i", key-100000);
	return marmot;
}
