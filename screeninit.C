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
#ifndef LINUX
void init_vsync(){
	#ifdef EXCESSIVE
	printf("init_vsync\n");
	#endif
	char *extensions = (char*)glGetString(GL_EXTENSIONS);
	if (strstr(extensions,"WGL_EXT_swap_control")){
		wglSwapIntervalEXT = (PFNWGLEXTSWAPCONTROLPROC)wglGetProcAddress("wglSwapIntervalEXT");
		wglGetSwapIntervalEXT = (PFNWGLEXTGETSWAPINTERVALPROC)wglGetProcAddress("wglGetSwapIntervalEXT");
	}
	if (wglGetSwapIntervalEXT()){
		if (verticlesync){
			wglSwapIntervalEXT(1);
			printf("VSync initialized\n");
		}else{
			wglSwapIntervalEXT(0);
			printf("VSync disabled\n");
		}
	}
}

void set_refresh_rate(){
	#ifdef EXCESSIVE
	printf("set_refresh_rate\n");
	#endif
	DEVMODE devMode;
	::ZeroMemory(&devMode, sizeof(devMode));
	devMode.dmDisplayFrequency = refreshrate;
	devMode.dmFields = DM_DISPLAYFREQUENCY;
	devMode.dmSize = sizeof(devMode);
	if (ChangeDisplaySettings(&devMode, 0)!=0){
		refreshrate=60;
		devMode.dmDisplayFrequency = 60;
		devMode.dmFields = DM_DISPLAYFREQUENCY;
		devMode.dmSize = sizeof(devMode);
		if (ChangeDisplaySettings(&devMode, 0)!=0){
			printf("Something is wrong with your monitor...\n");
		}
	}

}
#endif
void screeninit(int x=1024, int y=768, int depth=32, bool fullscreen=true){
//#ifndef LINUX
	//AVIFileInit();
//#endif
	//t flags = 0;
	SDL_Init ( SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_JOYSTICK );
	sdlloaded=true;
	#ifndef NOOSWEGO
	AL::Stream::class_init();
	#endif
	FT_Init_FreeType( &ftlibrary );
	#ifndef LINUX
	MIDIINCAPS mic;
	unsigned long iNumDevs, i;
	iNumDevs = midiInGetNumDevs();
	printf("Checking %i devices:\n",iNumDevs);
	for (i = 0; i < iNumDevs; i++){
		if (!midiInGetDevCaps(i, &mic, sizeof(MIDIINCAPS))){
			printf("Device ID #%u: %s\n", i, mic.szPname);
			if (!midiInOpen(&inHandle, i, (DWORD)midicbfunc, 0, CALLBACK_FUNCTION)){
				if (!midiInStart(inHandle)){
					printf("Opened device #%i...",i);
				}
			}
		}
	}
	printf("Success\n");
#endif
	SDL_ShowCursor(SDL_DISABLE);
	printf("Disabled Cursor\n");
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); 
	printf("Double Buffer Enabled\n");
	if (fullscreen){
		if (!SDL_SetVideoMode(x, y, depth, SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_FULLSCREEN)) {
			printf("Video mode set failed: %s\n",SDL_GetError());
			printf("Now trying fall back: 640x480x16\n");
			x=640;
			y=480;
			depth=16;
			resx=640;
			resy=480;
			drumbpp=16;
			if (!SDL_SetVideoMode(x, y, depth, SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_FULLSCREEN)) {
				printf("Video mode set failed: %s\n", SDL_GetError( ) );
				printf("If the fall back failed, please consult you video card manufacturer, or ensure you have support for OpenGL.\n");
				appisrunning=false;return;
			}else{
				printf("Video window initialized\n");
			}
		}else{
			printf("Video window initialized\n");
		}
	}else{
		if (!SDL_SetVideoMode(x, y, depth, SDL_OPENGL | SDL_GL_DOUBLEBUFFER  | SDL_RESIZABLE)) {
			printf( "Video mode set failed: %s\n", SDL_GetError( ) );
			printf("Now trying fall back: 640x480x16\n");
			x=640;
			y=480;
			depth=16;
			resx=640;
			resy=480;
			drumbpp=16;
			if (!SDL_SetVideoMode(x, y, depth, SDL_OPENGL | SDL_GL_DOUBLEBUFFER  | SDL_RESIZABLE)) {
				printf("Video mode set failed: %s\n", SDL_GetError( ) );
				printf("If the fall back failed, please consult you video card manufacturer, or ensure you have support for OpenGL.\n");
				appisrunning=false;return;
			}else{
				printf("Video window initialized\n");
			}
		}else{
			printf("Video window initialized\n");
		}
	}	
	//if (fullscreen)    //this will also have to set the video resolution as well..
	//set_refresh_rate();
#ifndef LINUX
	//init_vsync();
#endif
	SDL_WM_SetCaption("Seijinohki DigiBand", "DIGIBAND");
	SDL_Surface *theicon;
	char icon[256];
	snprintf(icon,255,"./Themes/%s/Icon.png",theme);
	theicon=IMG_Load(icon);
	if (theicon==NULL){
		snprintf(icon,255, "./Themes/Default/Icon.png");
		theicon=IMG_Load(icon);
		if (theicon==NULL){
			printf("Uh... I can't do that.\n");
		}
	}
	SDL_WM_SetIcon(theicon, NULL);
	
    int addx=0;
	int corx=0;
	int addy=0;
	int cory=0;
	if((double(resx)/double(resy))>=1.599999999999)widemode=true;
	else widemode=false;
	if(forcewide)widemode=true;
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
	glFrontFace( GL_CCW );
	glClearColor( 0, 0, 0, 0 );
	glLoadIdentity( );
	glMatrixMode( GL_PROJECTION );
	if(!widemode){
        glOrtho(1.0-tvscale,1024.0+tvscale,1.0-tvscale,768.0+tvscale,-15000.0,10000.0);
	}else{
		glOrtho(-127.0-tvscale,1152.0+tvscale,-15.0-tvscale,784.0+tvscale,-15000.0,10000.0);
	}
  	glEnable( GL_COLOR_MATERIAL );
	glTexEnvi(GL_TEXTURE_ENV_MODE,GL_MODULATE,1);
	//mmm sexy texture filters:
	glEnable( GL_TEXTURE_2D );
    if (strstr((char*)glGetString(GL_EXTENSIONS),"GL_EXT_texture_filter_anisotropic")){
        allowanisotropic=true;
        glGetFloatv(GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT, &maxanisotropy);
        glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxanisotropy);
        if (!allowaf)allowanisotropic=false;
		if (maxanisotropy>float(afamount)){
			maxanisotropy=float(afamount);
		}
        #ifdef DEBUG
        printf("Anisotropic Filtering Enabled at %.0fx\n",maxanisotropy);
        #endif
    }
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_FASTEST );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	glEnable(GL_BLEND);
	return;
}

void screenuninit(){
	//glDisable( GL_DEPTH_TEST );
	//glDisable( GL_COLOR_MATERIAL );
	glDisable( GL_LIGHTING );
	glDisable( GL_LIGHT0 );
}

void screenreinit(int x=1024, int y=768, int depth=32, bool fullscreen=true){
	//glDisable( GL_DEPTH_TEST );
	//glDisable( GL_COLOR_MATERIAL );
	glDisable( GL_LIGHTING );
	glDisable( GL_LIGHT0 );
	//drawtext::nukeAllInstances();
	previewtexture=0;
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glFlush();
	glFinish();
	//destructors done.
    /*#ifndef LINUX
	AVIFileInit();
    #endif*/
	int flags = 0;
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1); 
	if (fullscreen){
		if (!SDL_SetVideoMode(x, y, depth, SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_FULLSCREEN)) {
			printf("Video mode set failed: %s\n",SDL_GetError());
			printf("Now trying fall back: 640x480x16\n");
			x=640;
			y=480;
			depth=16;
			resx=640;
			resy=480;
			drumbpp=16;
			if (!SDL_SetVideoMode(x, y, depth, SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_FULLSCREEN)) {
				printf("Video mode set failed: %s\n", SDL_GetError( ) );
				printf("If the fall back failed, please consult you video card manufacturer, or ensure you have support for OpenGL.\n");
				appisrunning=false;return;
			}
		}
	}else{
		if (!SDL_SetVideoMode(x, y, depth, SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_RESIZABLE)) {
			printf( "Video mode set failed: %s\n", SDL_GetError( ) );
			printf("Now trying fall back: 640x480x16\n");
			x=640;
			y=480;
			depth=16;
			resx=640;
			resy=480;
			drumbpp=16;
			if (!SDL_SetVideoMode(x, y, depth, SDL_OPENGL | SDL_GL_DOUBLEBUFFER | SDL_RESIZABLE )) {
				printf("Video mode set failed: %s\n", SDL_GetError( ) );
				printf("If the fall back failed, please consult you video card manufacturer, or ensure you have support for OpenGL.\n");
				appisrunning=false;return;
			}
		}
	}
	bgavi.avitexture=0;
	gpavi.avitexture=0;
	//if (fullscreen)
	//	set_refresh_rate();
#ifndef LINUX
	init_vsync();
#endif
	SDL_WM_SetCaption("Seijinohki DigiBand", "DigiBand");
	SDL_Surface *theicon;
	char icon[256];
	snprintf(icon,255,"./Themes/%s/Icon.png", theme);
	theicon=IMG_Load(icon);
	if (theicon==NULL){
		snprintf(icon,255,"./Themes/Default/Icon.png");
		theicon=IMG_Load(icon);
		if (theicon==NULL){
			printf("Uh... I can't do that.");
		}
	}
	SDL_WM_SetIcon(theicon, NULL);
		
    int addx=0;
	int corx=0;
	int addy=0;
	int cory=0;
	if((double(resx)/double(resy))>=1.599999999999)widemode=true;
	else widemode=false;
	if(forcewide)widemode=true;
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
	glFrontFace( GL_CCW );
	glClearColor( 0, 0, 0, 0 );
	glLoadIdentity( );
	glMatrixMode( GL_PROJECTION );
	if(!widemode){
        glOrtho(1.0-tvscale,1024.0+tvscale,1.0-tvscale,768.0+tvscale,-15000.0,10000.0);
	}else{
		glOrtho(-127.0-tvscale,1152.0+tvscale,-15.0-tvscale,784.0+tvscale,-15000.0,10000.0);
	}
	glEnable( GL_COLOR_MATERIAL );
	glTexEnvi(GL_TEXTURE_ENV_MODE,GL_MODULATE,1);
	glEnable( GL_TEXTURE_2D );
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_S,GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D,GL_TEXTURE_WRAP_T,GL_CLAMP);
	glTexGeni(GL_S, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glTexGeni(GL_T, GL_TEXTURE_GEN_MODE, GL_SPHERE_MAP);
	glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT );
	glHint( GL_PERSPECTIVE_CORRECTION_HINT, GL_NICEST );
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
	glEnable(GL_BLEND);
	return;
}
