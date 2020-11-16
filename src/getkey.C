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
void getkey(){
	#ifdef EXCESSIVE
		printf("getkey\n");
	#endif
	bool joystickcheck=true;
	int marmot=0;
	static double uptime=0;
	static double downtime=0;
	static bool downpressed=false;
	static bool uppressed=false;
	static drawtext message;
	static drawtext message2;
	static unsigned int lastkeypressed=0;
	static SDL_Joystick *joystick;
	lastkeypressed=0;
	int n=10;
	SDL_Event event;
	int joy=0;
	int axi=0;
	int but=0;
	while( SDL_PollEvent( &event )){
		marmot=event.type;
		if (event.type==SDL_VIDEORESIZE){
			resx=event.resize.w;
			resy=event.resize.h;
            int addx=0;
			int corx=0;
			int addy=0;
			int cory=0;
			#ifndef LINUX
			SDL_Surface *surface = SDL_GetVideoSurface();
			surface->w = resx;
			surface->h = resy;
			#endif
            if((double(resx)/double(resy))>=1.599999999999)widemode=true;
			else widemode=false;
			if (forcewide)widemode=true;
		    double ratio=(double(resx)/double(resy));
			if (!widemode){
				if (ratio>(4.0/3.0)){//x is larger than it's suppose to be.
					corx=int(double(resy)*(4.0/3.0));
					addx=(resx-corx);
				}
				if (ratio<(4.0/3.0)){//y is larger than it's suppose to be.
					cory=int(double(resx)*(3.0/4.0));
					addy=(resy-cory);
				}
			}else{
				if (ratio>(16.0/10.0)){//x is larger than it's suppose to be.
					corx=int(double(resy)*(16.0/10.0));
					addx=(resx-corx);
				}
				if (ratio<(16.0/10.0)){//y is larger than it's suppose to be.
					cory=int(double(resx)*(10.0/16.0));
					addy=(resy-cory);
				}
			}
            if (ratioadjust){
				glViewport(addx/2, addy/2, resx-addx, resy-addy);
			}else{
        		glViewport(0,0, resx, resy);
			}
			SDL_GL_SwapBuffers();
			glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
            glMatrixMode( GL_PROJECTION );
			glLoadIdentity( );
			if(!widemode){
	            glOrtho(1.0-tvscale,1024.0+tvscale,1.0-tvscale,768.0+tvscale,-15000.0,10000.0);
			}else{
				glOrtho(-127.0-tvscale,1152.0+tvscale,-15.0-tvscale,784.0+tvscale,-15000.0,10000.0);
			}
            glMatrixMode( GL_MODELVIEW );
            loadtextureresize();
		}
		if (event.type == SDL_KEYUP){
            if (event.key.keysym.sym==guitar1p){
				g1pp=false;
			}
			if (event.key.keysym.sym==guitar1r){
				g1rp=false;
			}
			if (event.key.keysym.sym==guitar1g){
				g1gp=false;
			}
			if (event.key.keysym.sym==guitar1b){
				g1bp=false;
			}
			if (event.key.keysym.sym==guitar1w){
				g1wp=false;
			}
			if (event.key.keysym.sym==guitar2p){
				g2pp=false;
			}
			if (event.key.keysym.sym==guitar2r){
				g2rp=false;
			}
			if (event.key.keysym.sym==guitar2g){
				g2gp=false;
			}
			if (event.key.keysym.sym==guitar2b){
				g2bp=false;
			}
			if (event.key.keysym.sym==guitar2w){
				g2wp=false;
			}
			downpressed=false;
			uppressed=false;
			uptime=0;
			downtime=0;
		}
		if (event.type == SDL_KEYDOWN){
			if (event.key.keysym.sym>0)
				lastkeypressed=event.key.keysym.sym;
            if(event.key.keysym.sym == SDLK_F4 && event.key.keysym.mod & KMOD_ALT){
                #ifdef DEBUG
				printf("quit detected.\n");
				#endif
                appisrunning=false;
            }
            if(event.key.keysym.sym == SDLK_F4 && event.key.keysym.mod & KMOD_ALT && event.key.keysym.mod & KMOD_CTRL){
                exit(0);
            }
			if(event.key.keysym.sym == SDLK_RETURN && event.key.keysym.mod & KMOD_ALT){
				if (!isloading){
	                if (drumfullscreen){
	                    origfullscreen=false;
	                    drumfullscreen=false;
	                }else{
	                    origfullscreen=true;
	                    drumfullscreen=true;
	                }
	                resx=origresx;
	                resy=origresy;
	                screenreinit(resx,resy,32,drumfullscreen);
	                reloadtheme();
	                loadtextureondemand();
	                return;
				}
            }
		}else{
			lastkeypressed=0;
		}
		if (lastkeypressed>0){
			if (!screenfaddingin&&!screenfaddingout&&!screenchangenow){
				parsekey(lastkeypressed,uppressed,downpressed);
			}else{
				if (lastkeypressed==coinkey||lastkeypressed==opskey){
                    parsekey(lastkeypressed,uppressed,downpressed);
				}
			}
		}
		if (event.type==SDL_QUIT){
			#ifdef DEBUG
			printf("quit detected.\n");
			#endif
			appisrunning=false;
			break;
		}	
	}
	if (debugstats){
		char themessage[256];
		if(!suboptionselection)snprintf(themessage,255, "Key pressed:%i Option selected:%i suboptions: false sym:%i", lastkeypressed,optionselected,marmot);
		if(suboptionselection)snprintf(themessage,255, "Key pressed:%i Option selected:%i suboptions: true sym:%i", lastkeypressed,optionselected,marmot);
		message.load(themessage,"font.ttf",255,255,255,24);
		message.draw(0,740,9000);
		snprintf(themessage,255,"Next: %i Curr: %i Prev:%i Last:%i fadin:%f fadout:%f",nextscreen, prevscreen, lastscreen, screenfaddingintime, screenfaddingouttime);
		message2.load(themessage,"font.ttf",255,255,255,24);
		message2.draw(0,700,9000);
	}
	
	if (downpressed){
		if(currscreen==5){
			if(!downanimation&&!upanimation){
				upanimation=true;
			}
		}
	}
	if (uppressed){
		if(currscreen==5){
			if(!upanimation&&!downanimation){
				downanimation=true;
			}
		}
	}
	if (downpressed){
		downtime+=double(steptime)/16.0;
		if (currscreen==2)
			downtime+=double(steptime)/16.0;
		if (downtime>89){
			if(!suboptionselection){
				if (currscreen!=5){
					downtime=80;
					optionselected++;
				}
				if(currscreen<11&&currscreen!=4&&currscreen!=5&&currscreen!=6)playsound(2,"selection.wav");
			}
		}
		if (downtime>89){
			if(suboptionselection){
				downtime=80;
				if (optionselected==1)
					resx+=10;
				if (optionselected==2)
					resy+=10;
				if (optionselected==8)
					notespeed+=5;
				if(currscreen<11&&currscreen!=4&&currscreen!=5&&currscreen!=6)playsound(2,"selection.wav");
			}
		}
	}
	if (uppressed){
		uptime+=double(steptime)/16.0;
		if (currscreen==2)
			uptime+=double(steptime)/16.0;
		if (uptime>89){
			if(!suboptionselection){
				if (currscreen!=5){
					optionselected--;
					uptime=80;
				}
				if(currscreen<11&&currscreen!=4&&currscreen!=5&&currscreen!=6)playsound(2,"selection.wav");
			}
		}
		if (uptime>89){
			if(suboptionselection){
				uptime=80;
				if (optionselected==1)
					resx-=10;
				if (optionselected==2)
					resy-=10;
				if (optionselected==8)
					notespeed-=5;
				if(currscreen<11&&currscreen!=4&&currscreen!=5&&currscreen!=6)playsound(2,"selection.wav");
			}
		}
	}
	if (resx>2048)resx=2048;
	if (resx<160)resx=160;
	if (resy>1536)resy=1536;
	if (resy<120)resy=120;
	if (notespeed<1)notespeed=99;
	if (notespeed>200)notespeed=1;
	if (arcademode&&currscreen!=20)jukeboxmode=false;
}
