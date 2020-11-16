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
//formula= 1000*joystick, 100*axi+direction, +button
void getjoy(){
	#ifdef EXCESSIVE
		printf("getjoy\n");
	#endif
	static double uptime=0;
	static double downtime=0;
	bool uppressed=false;
	bool downpressed=false;
	static bool uppressed2=false;
	static bool downpressed2=false;
	int lastkeypressed=0;
	static int menuhold=0;
	static bool thebuttons[10][40];
	static SDL_Joystick *joystick;
	static bool startheld=false;
	for (int joy=0;joy<SDL_NumJoysticks();joy++){
		joystick=SDL_JoystickOpen(joy);
		for (int but=0;but<20;but++){
			if (SDL_JoystickGetButton(joystick,but)!=0){
				if (!thebuttons[joy][but]){
					if(joy<10)thebuttons[joy][but]=true;
					lastkeypressed=(1000*joy)+but+1000;
					if (lastkeypressed!=guitar1start&&lastkeypressed!=guitar1start){
						if (!screenfaddingin&&!screenfaddingout&&!screenchangenow){
							parsekey(lastkeypressed,uppressed,downpressed);
						}else{
							if (lastkeypressed==coinkey||lastkeypressed==opskey){
	                            parsekey(lastkeypressed,uppressed,downpressed);
							}
						}
					}else{
						if(!startheld){
		                    if (!screenfaddingin&&!screenfaddingout&&!screenchangenow){
								parsekey(lastkeypressed,uppressed,downpressed);
							}else{
								if (lastkeypressed==coinkey||lastkeypressed==opskey){
		                            parsekey(lastkeypressed,uppressed,downpressed);
								}
							}
						}
					}
					if (lastkeypressed==guitar1r||lastkeypressed==guitar2r)uppressed2=true;
					if (lastkeypressed==guitar1b||lastkeypressed==guitar2b)downpressed2=true;
					if (lastkeypressed==guitar1start)startheld=true;
				}
			}else{
				if(joy<10)thebuttons[joy][but]=false;
				lastkeypressed=(1000*joy)+but+1000;
				if (lastkeypressed==guitar1r||lastkeypressed==guitar2r)uppressed2=false;
				if (lastkeypressed==guitar1b||lastkeypressed==guitar2b)downpressed2=false;
				if (lastkeypressed==guitar1start)startheld=false;
				if (lastkeypressed==guitar1p){
					g1pp=false;
				}
				if (lastkeypressed==guitar1a){
					g1pp=false;
				}
				if (lastkeypressed==guitar1r){
					g1rp=false;
				}
				if (lastkeypressed==guitar1g){
					g1gp=false;
				}
				if (lastkeypressed==guitar1b){
					g1bp=false;
				}
				if (lastkeypressed==guitar1w){
					g1wp=false;
				}
				if (lastkeypressed==guitar2p){
					g2pp=false;
				}
				if (lastkeypressed==guitar2a){
					g2pp=false;
				}
				if (lastkeypressed==guitar2r){
					g2rp=false;
				}
				if (lastkeypressed==guitar2g){
					g2gp=false;
				}
				if (lastkeypressed==guitar2b){
					g2bp=false;
				}
				if (lastkeypressed==guitar2w){
					g2wp=false;
				}
			}
			if (downpressed){
				if(currscreen==5){
					if(!downanimation&&!upanimation)upanimation=true;
				}
			}
			if (uppressed){
				if(currscreen==5){
					if(!upanimation&&!downanimation)downanimation=true;
				}
			}
		}
		for (int but=20;but<30;but++){
			int b=SDL_JoystickGetAxis(joystick,but-20);
			if (b<-1000||b>1000){
				if (!thebuttons[joy][but]){
					if(joy<10)thebuttons[joy][but]=true;
					lastkeypressed=(1000*joy)+but+1000;
                    if (!screenfaddingin&&!screenfaddingout&&!screenchangenow){
						parsekey(lastkeypressed,uppressed,downpressed);
					}else{
						if (lastkeypressed==coinkey||lastkeypressed==opskey){
                            parsekey(lastkeypressed,uppressed,downpressed);
						}
					}
				}
			}else{
				if(joy<10)thebuttons[joy][but]=false;
				lastkeypressed=(1000*joy)+but+1000;
				if (lastkeypressed==guitar1p){
					g1pp=false;
				}
				if (lastkeypressed==guitar1a){
					g1pp=false;
				}
				if (lastkeypressed==guitar1r){
					g1rp=false;
				}
				if (lastkeypressed==guitar1g){
					g1gp=false;
				}
				if (lastkeypressed==guitar1b){
					g1bp=false;
				}
				if (lastkeypressed==guitar1w){
					g1wp=false;
				}
				if (lastkeypressed==guitar2p){
					g2pp=false;
				}
				if (lastkeypressed==guitar2a){
					g2pp=false;
				}
				if (lastkeypressed==guitar2r){
					g2rp=false;
				}
				if (lastkeypressed==guitar2g){
					g2gp=false;
				}
				if (lastkeypressed==guitar2b){
					g2bp=false;
				}
				if (lastkeypressed==guitar2w){
					g2wp=false;
				}
			}
			if (downpressed){
				if(currscreen==5){
					if(!downanimation&&!upanimation)upanimation=true;
				}
			}
			if (uppressed){
				if(currscreen==5){
					if(!upanimation&&!downanimation)downanimation=true;
				}
			}
		}
		for (int but=30;but<40;but++){
			int b=SDL_JoystickGetHat(joystick, but-30);
			if (b!=0){
				if (!thebuttons[joy][but]){
					if(joy<10)thebuttons[joy][but]=true;
					lastkeypressed=(1000*joy)+but+b+1000;
                    if (!screenfaddingin&&!screenfaddingout&&!screenchangenow){
						parsekey(lastkeypressed,uppressed,downpressed);
					}else{
						if (lastkeypressed==coinkey||lastkeypressed==opskey){
                            parsekey(lastkeypressed,uppressed,downpressed);
						}
					}
				}
			}else{
				if(joy<10)thebuttons[joy][but]=false;
				lastkeypressed=(1000*joy)+but+1000;
				if (lastkeypressed==guitar1p){
					g1pp=false;
				}
				if (lastkeypressed==guitar1a){
					g1pp=false;
				}
				if (lastkeypressed==guitar1r){
					g1rp=false;
				}
				if (lastkeypressed==guitar1g){
					g1gp=false;
				}
				if (lastkeypressed==guitar1b){
					g1bp=false;
				}
				if (lastkeypressed==guitar1w){
					g1wp=false;
				}
				if (lastkeypressed==guitar2p){
					g2pp=false;
				}
				if (lastkeypressed==guitar2a){
					g2pp=false;
				}
				if (lastkeypressed==guitar2r){
					g2rp=false;
				}
				if (lastkeypressed==guitar2g){
					g2gp=false;
				}
				if (lastkeypressed==guitar2b){
					g2bp=false;
				}
				if (lastkeypressed==guitar2w){
					g2wp=false;
				}
			}
			if (downpressed){
				if(currscreen==5){
					if(!downanimation&&!upanimation)upanimation=true;
				}
			}
			if (uppressed){
				if(currscreen==5){
					if(!upanimation&&!downanimation)downanimation=true;
				}
			}
		}
	}
	if (downpressed2){
		if(currscreen==5){
			if(!downanimation&&!upanimation)upanimation=true;
		}
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
	if (uppressed2){
		if(currscreen==5){
			if(!upanimation&&!downanimation)downanimation=true;
		}
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
	if (!downpressed2)downtime=0;
	if (!uppressed2)uptime=0;
}
