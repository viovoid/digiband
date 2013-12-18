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

void playsound(int num, int volume){
	playsound(num,"NULL",volume);
}

void playsound(int num, char soundfile[256]="default.wav",int volume=10){
	#ifndef NOOSWEGO
	#ifdef EXCESSIVE
	printf("playsound\n");
	#endif
	if (strlen(soundfile)<1)return;
	if (num<1&&num>1552)return;
    if (isloading)return;
	//1-256 reserved for below:
	//0:reserved blank.
	//1:test.xa
	//2:selection.wav
	//3:drumstart.wav
	//4:guitarstart.wav
	//5:bassstart.wav
	//6:gamestart.wav
	//7:code.wav
	//8:gameoversound.wav
	//9:gameovervoice.wav
	//10:category.wav
	//11:guitartrebleoff.wav
	//12:guitarbassoff.wav
	//13:credit.wav
	//14:selectmode.wav
	//15:selectmusic.wav
	//16:fullcombo.wav
	//17:timer.wav
	//21-31:lnote(X-20).wav
	//sound effects loading only.
	if (strlen(soundfile)>1){
		if (num<=256){
			char thefile[256];
			snprintf(thefile,255, "./Themes/%s/%s",theme,soundfile);
			if (!testfile(thefile)){
				snprintf(thefile,255, "./Themes/Default/%s",soundfile);
			}
            if (testfile(thefile)){
				if (testxa(thefile)){
					#ifdef LINUX
					char *onlytime = (char *)malloc(strlen(thefile) + 1);
					memcpy(onlytime, thefile, strlen(thefile) + 1);
					snprintf(thefile, 255, "%s.wav", onlytime);
					free(onlytime);					
					#else
					decodexa(thefile);
					#endif
				}
				if (waves[num].get_state()==AL::STATE_CLOSED){
    				waves[num].open(thefile);
				}
			}
		}
	}
	//universal play function.
	if (waves[num].get_state()!=AL::STATE_CLOSED){
		float fvol=float(volume)/10.0f;
		waves[num].set_gain(fvol);
		waves[num].play(false);
		waves[num].set_gain(fvol);
	}
	#endif
}
