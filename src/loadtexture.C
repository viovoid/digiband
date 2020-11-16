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
int LoadTransTexture2( SDL_Surface *sdlimage,int currpos, int size){
	#ifdef EXCESSIVE
	printf("LoadTransTexture2\n");
	#endif
	if (size<1)size=1;
	if (currpos>=size)currpos=size-1;
	if (currpos<0)currpos=0;
	GLuint retval;
	void *raw;
	int w, h, i, j, bpp;
	Uint8 *srcPixel, *dstPixel;
	Uint32 truePixel;
	GLenum errorCode;
	
	bpp = sdlimage->format->BytesPerPixel;
	if (bpp < 2 || bpp > 4) {
		printf("VideoDriver::LoadSurface passed SDL_Surface * has an unusable bpp.\n");
	}
	
	w=sdlimage->w;
	h=sdlimage->h;
	int width=w/size;
	int ores=0;
	int tres=1;
	if (width<h){
		ores=h;
	}else{
		ores=width;
	}
	while (tres<ores){
		tres=tres*2;	
	}
	int xstart=currpos*tres;
	w = xstart + tres;
	
	raw = (void *)malloc(tres*tres * 4);
	dstPixel = (Uint8 *)raw;
	
	SDL_LockSurface(sdlimage);

	for (i = tres - 1; i >= 0; i--) {
		for (j = xstart; j < w; j++) {
			if (i*(h/tres) >= sdlimage->h || j*(width/tres) >= sdlimage->w) {
				memset(dstPixel, 0, 4);
			} else {
				srcPixel = (Uint8 *)sdlimage->pixels + (i*h/tres) * sdlimage->pitch + (j*width/tres) * bpp;
				switch(bpp){
					case 1:
						truePixel=*srcPixel;
						break;
					case 2:
						truePixel=*(Uint16 *)srcPixel;
						break;
					case 3:
						if (SDL_BYTEORDER == SDL_BIG_ENDIAN) {
							truePixel = srcPixel[0] << 16 | srcPixel[1]<<8 | srcPixel[2];
						}else{
							truePixel= srcPixel[0] | srcPixel[1]<<8 | srcPixel[2] << 16;
						}
						break;
					case 4:
						truePixel= *(Uint32 *)srcPixel;
						break;
					default:
						SDL_UnlockSurface(sdlimage);
      					if (sdlimage!=NULL)SDL_FreeSurface(sdlimage);
						free (raw);
						//free(srcPixel);
						//free(dstPixel);
						return 0;
						break;
				}
				SDL_GetRGBA(truePixel, sdlimage->format, &(dstPixel[0]), &(dstPixel[1]), & (dstPixel[2]), &(dstPixel[3]));
			}
			dstPixel += 4;
		}
	}

	SDL_UnlockSurface(sdlimage);

	while (glGetError()) { ; }	// eat any gl errors before we cause some of our own

	glGenTextures(1, &retval);

	errorCode = glGetError();
	if (errorCode != 0) {
		if (glIsTexture(retval)){
			glDeleteTextures(1, &retval);
		}
		free(raw);
		if (errorCode == GL_OUT_OF_MEMORY) {
   			if (sdlimage!=NULL)SDL_FreeSurface(sdlimage);
			printf("Out of Memory...");
			appisrunning=false;
			return 0;
		} else {
			return 0;
		}
	}
	glBindTexture(GL_TEXTURE_2D, retval);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	//gluBuild2DMipmaps( GL_TEXTURE_2D, 4, width, h, GL_RGBA, GL_UNSIGNED_BYTE, (Uint8 *)raw);
    if(allowanisotropic)glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxanisotropy);
	glTexImage2D(GL_TEXTURE_2D, 0, 4, tres, tres, 0, GL_RGBA, GL_UNSIGNED_BYTE, (Uint8 *)raw);
	
	free(raw);
	//free(nimage);
	return retval;
}

bool loadtexture(int a, char *filename, int size=1){
	#ifdef EXCESSIVE
	printf("loadtexture(3)\n");
	#endif
	if (strlen(filename)<1)return false;
	if (!testfile(filename)){
		return false;
	}
	SDL_Surface *sdlimage;
	sdlimage=NULL;
	sdlimage=IMG_Load(filename);
	if (sdlimage==NULL){
		return false;
	}
	if (sdlimage->format->BytesPerPixel < 2){
		if (sdlimage!=NULL)SDL_FreeSurface(sdlimage);
		return false;
	}
	for (int b=0;b<size;b++){
		g_Texture[a][b]=LoadTransTexture2(sdlimage,b,size);
		if (g_Texture[a][b]==0){
			if (sdlimage!=NULL)SDL_FreeSurface(sdlimage);
			return false;
		}
	}
	if (sdlimage!=NULL)SDL_FreeSurface(sdlimage);
	return true;
}

int loadtexture(char *filename){
	#ifdef EXCESSIVE
	printf("loadtexture(1)\n");
	#endif
	if (!testfile(filename)){
		return 0;
	}
	SDL_Surface *sdlimage;
	sdlimage=NULL;
	sdlimage=IMG_Load(filename);
	if (sdlimage==NULL){
		return 0;
	}
	if (sdlimage->format->BytesPerPixel < 2){
		if (sdlimage!=NULL)SDL_FreeSurface(sdlimage);
		return 0;
	}
	int retval=LoadTransTexture2(sdlimage,0,1);
	if (retval==0){
		if (sdlimage!=NULL)SDL_FreeSurface(sdlimage);
		return 0;
	}
	if (sdlimage!=NULL)SDL_FreeSurface(sdlimage);
	return retval;
}

