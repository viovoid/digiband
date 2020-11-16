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
int songpos(void *wtf){
   	#ifdef EXCESSIVE
	printf("songpos\n");
	#endif
	while(appisrunning){
        #ifdef EXCESSIVE
        #ifndef EXCESSIVELITE
		printf("(song position loop)\n");
		#endif
		#endif
		int temp=SDL_GetTicks();
		if (currscreen!=prevscreen)
			timestamp=temp;
		if (thesong>-1&&gbsongcount){
			songposition+=int( double(temp-timestamp) * ((double(currbpm)*songs[thesong].bpmdiff)*(1.0/currclm)) );
		}
		timestamp=temp;
		SDL_Delay(1);
	}
 	#ifdef DEBUG
	printf("songpos thread ended\n");
	#endif
	return 0;
}

void gameloop(){//is basically the program after it's done loading.
	#ifdef EXCESSIVE
	printf("gameloop\n");
	#endif
	SDL_Thread *bgvidthread;
	SDL_Thread *songposthread;
	bgvidthread=SDL_CreateThread(playbgavi,NULL);
	songposthread=SDL_CreateThread(songpos,NULL);
	
	while(appisrunning){
		#ifdef EXCESSIVE
		#ifndef EXCESSIVELITE
		printf("(master game loop)\n");
		#endif
		#endif
		if (bgavi.isloaded()||gpavi.isloaded())
            while(SDL_GetTicks()-lasttime<32){SDL_Delay(1);}//we want to eat any extra time to give it to video rendering.
		SDL_GL_SwapBuffers();
		glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
		glMatrixMode( GL_MODELVIEW );
		glLoadIdentity( );
		lasttime=currtime;
		currtime=SDL_GetTicks();
		steptime=currtime-lasttime;
		if (steptime>16)
			steptime=16;
		codetime+=double(steptime)/16.0;
		codetime2+=double(steptime)/16.0;
		frameholder+=double(steptime)/16.0;
		catchangewait-=steptime;
		if (catchangewait<0)catchangewait=0;
		newsong=false;
		getkey();
		getjoy();
		if (thesong!=presong||newsong==true){
			songs[0].reloadsong();
		}
		if (!appisrunning)
			return;
		if (screenchangenow){
			lastscreen=currscreen;
			currscreen=nextscreen;
			screenchangenow=false;
			screenfaddingin=true;
		}
		if (currscreen!=prevscreen)
			loadtextureondemand();
		for (int a=0;a<numoftexs;a++){//frames,timing,currframe,currtime;
		    if (texani[a][0]>1){
				texani[a][3]+=int(  (1.0/double(texani[a][1]))*double(steptime)*double(steptime)*100.0);
				while (texani[a][3]>1000.0){
					texani[a][3]=texani[a][3]-1000.0;
					texani[a][2]++;
				}
				if (texani[a][2]>=texani[a][0]){
					texani[a][2]=0;
				}
			}
		}
		songpositiondraw=songposition;
		renderscreen();
/*		int temp=SDL_GetTicks();
		if (currscreen!=prevscreen)
			timestamp=temp;
		songposition+=int( double(temp-timestamp) * (double(currbpm)*(1.0/currclm)) );
		timestamp=temp;     */
	}
	SDL_WaitThread(bgvidthread, NULL);
	SDL_WaitThread(songposthread, NULL);
	SDL_GL_SwapBuffers();
}
