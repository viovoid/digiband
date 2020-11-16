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
drawtext **drawtext::instances = NULL;
long long drawtext::instancessize = 0;
bool hasbeennuked=false;

drawtext::drawtext(){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("drawtext::drawtext\n");
	#endif
	#endif
	registerInstance();
	converter=NULL;
	//converter=iconv_open("UTF-8","SHIFT_JIS");
	converter=iconv_open("UCS-4LE","SHIFT_JIS");
	ther=0;
	theg=0;
	theb=0;
	thes=0;
	istexture=false;
	isloaded=false;
	fontloaded=false;
	snprintf(thefont,255,"(NULL)");
	snprintf(thetext,255,"(NULL)");
	texture=0;
	fonth=NULL;
	#ifdef DEBUGDRAWTEXT
	printf("drawtext::Ran the constructor.\n");
	#endif
}

drawtext::~drawtext(){
	if (hasbeennuked)return;
	#ifdef EXCESSIVE
	printf("drawtext::~drawtext\n");
	#endif
	/*selfDestruct();
	for (int i = 0; i < instancessize; i++) {
		if (instances[i] == this) instances[i] = NULL;
	}*/
	if (converter){
		iconv_close(converter);
	}
	if (fontloaded){
		//FT_Done_Face( fonth );
		fontloaded=false;
	}
	#ifdef DEBUGDRAWTEXT
	printf("drawtext::Deconstructed instance.\n");
	#endif
}

void drawtext::forceconstructor(){
 	#ifdef EXCESSIVE
	printf("drawtext::forceconstructor\n");
	#endif
	//registerInstance();
	converter=NULL;
	//converter=iconv_open("UTF-8","SHIFT_JIS");
	converter=iconv_open("UCS-4LE","SHIFT_JIS");
	ther=0;
	theg=0;
	theb=0;
	thes=0;
	istexture=false;
	isloaded=false;
	fontloaded=false;
	snprintf(thefont,255,"(NULL)");
	snprintf(thetext,255,"(NULL)");
	texture=0;
	#ifdef DEBUGDRAWTEXT
	printf("drawtext::Forces constructor to set variables for global space usage.\n");
	#endif
}

void drawtext::registerInstance() {
	/*#ifdef EXCESSIVE
	printf("drawtext::registerInstance\n");
	#endif
	bool inserted = false;
	int i = 0;
	for (; i < instancessize && !inserted; i++) {
		if (instances[i] == NULL) {
			instances[i] = this;
			inserted = true;
		}
	}
	if (!inserted) {
		drawtext **newinst = (drawtext **)malloc(sizeof(drawtext *) * (instancessize * 2 + 1));
		memset(newinst, 0, sizeof(drawtext *) * (instancessize * 2 + 1));
		if (instances) {
			memcpy(newinst, instances, instancessize * sizeof(drawtext *));
			free(instances);
		}
		instances = newinst;
		instancessize = instancessize * 2 + 1;
		instances[instancessize - 1] = this;
	}
	#ifdef DEBUGDRAWTEXT
	printf("drawtext::added this drawtext to the instances of drawtext available.\n");
	#endif*/
}


void drawtext::nukeAllInstances() {
	/*
	#ifdef EXCESSIVE
	printf("drawtext::nukeAllInstances\n");
	#endif
	for (int i = 0; i < instancessize; i++) {
		if (instances[i]) (instances[i])->selfDestruct();
	}
	hasbeennuked=true;
	#ifdef DEBUGDRAWTEXT
	printf("drawtext::successfully nuked all instances of drawtext.\n");
	#endif*/
}

void drawtext::zap() {
	#ifdef EXCESSIVE
	printf("drawtext::zap\n");
	#endif
	for (int i = 0; i < instancessize; i++) {
		if (instances[i]) (instances[i])->istexture=false;
	}
	#ifdef DEBUGDRAWTEXT
	printf("drawtext::resat state of the texture(s).\n");
	#endif
}

void drawtext::selfDestruct() {
/*    if (hasbeennuked)return;
	#ifdef EXCESSIVE
	printf("drawtext::selfDestruct\n");
	#endif
	snprintf(thetext,255,"");
	texture=0;
	if (converter){
		iconv_close(converter);
	}
	if (fontloaded){
		if (fonth!=NULL){
			//FT_Done_Face( fonth );
		}
		fontloaded=false;
	}
	#ifdef DEBUGDRAWTEXT
	printf("drawtext::Self destructed.\n");
	#endif
*/
}

void drawtext::setfont(char font[256]){
	#ifdef EXCESSIVE
	printf("drawtext::setfont\n");
	#endif
	if (fontloaded){
		if (fonth!=NULL){
			FT_Done_Face( fonth );
			fonth=NULL;
		}
		fontloaded=false;
	}
	char filename[256];
	snprintf(filename,255,"Themes/%s/%s",theme,font);
	if (!testfile(filename)){
		snprintf(filename,255,"Themes/Default/%s",font);
		if (!testfile(filename)){
			#ifdef DEBUGDRAWTEXT
			printf("DRAWTEXT:Cannot find font %s\n",filename);
			#endif
			return;
		}
	}
	int err=FT_New_Face( ftlibrary, filename, 0, &fonth );//open a font.
	if (err){
		#ifdef DEBUGDRAWTEXT
		printf("FT_NEW_Face:%i\n",err);
		#endif
		return;
	}
	FT_Set_Char_Size( fonth, 0, thes * 64, 74, 74 );
	fontloaded=true;
}

void drawtext::gentextures(char text[256]){
	#ifdef EXCESSIVE
	printf("drawtext::gentextures\n");
	#endif
	if (!fontloaded){
		#ifdef DEBUGDRAWTEXT
		printf("DRAWTEXT:Cannot generate without a font.\n");
		#endif
		return;
	}
	if (strlen(text)<1)return;
	//i-convert
	char thetext[256];
	snprintf(thetext,255,"%s", text);
	#ifndef LINUX
	const char *textptr=thetext;
	#else
	char *textptr=thetext;
	#endif
	uint32_t finaltext[256];
	char *finaltextptr=(char *)finaltext;
	size_t marmot1=sizeof(char)*strlen(thetext);
	size_t marmot2=sizeof(uint32_t)*strlen(thetext);
	size_t slength;
	if (converter==NULL){
		printf("where's the converter?");
		printf("drawtext::fastestload(5), %i, %s \n",strlen(text),text);
		appisrunning=false;
		return;
	}
	iconv(converter,&textptr,&marmot1,&finaltextptr,&marmot2);
	slength=(uint32_t *)finaltextptr-finaltext;

	//begin doing stuff to text.
	int swidth=0;//data width.
	int sheight=0;//data height.
	int sb=0;//the top of our font.
	FT_UInt glyph_index;

	//calculate y_max and y_min based on n distance from the baseline of our font.
	int y_max = (int)ceil((double)fonth->bbox.yMax * (double)fonth->size->metrics.y_ppem / (double)fonth->units_per_EM);
	int y_min = (int)floor((double)fonth->bbox.yMin * (double)fonth->size->metrics.y_ppem / (double)fonth->units_per_EM);

	sheight=y_max-y_min;
	int theight=2;
	int hoff=theight-sheight;
	sb=y_max;
	uint32_t tchar;
	
	for (int X=0;X<slength;X++){
    	tchar=finaltext[X];//our test text.
		glyph_index = FT_Get_Char_Index( fonth, tchar );//get where our "T" is in the font.
		FT_Load_Glyph( fonth, glyph_index, FT_LOAD_NO_BITMAP ); //Get our dimensions of a "T".
		int w=fonth->glyph->metrics.horiAdvance;
		swidth+=w/64;//this is the size of our data.
	}
	//determine our texture quad size based on the larger of width or height of our string.
	if (sheight>swidth){
		while (theight<sheight){
			theight*=2;
		}
	}else{
		while (theight<swidth){
			theight*=2;
		}
	}
	#ifdef DEBUGDRAWTEXT
	printf("Font loaded with texture size: %i\n",theight);
	if (theight>512){
		printf("EE::THAT'S A BIG BITCH!!!\n");
	}
	#endif
	unsigned char *data=(unsigned char *)malloc(sizeof(unsigned char)*swidth*sheight);
	for (int a=0;a<swidth*sheight;a++){
		#ifndef DEBUGDRAWTEXT
		data[a]=0;
		#else
		data[a]=16; //boundry box display, neat huh?
		#endif
	}
	int swidthf=0;
	for (int X=0;X<slength;X++){
    	tchar=finaltext[X];//our test text.
		glyph_index = FT_Get_Char_Index( fonth, tchar );//get where our "T" is in the font.
		FT_Load_Glyph( fonth, glyph_index, FT_LOAD_DEFAULT ); //Get our "T".
		FT_Render_Glyph( fonth->glyph, FT_RENDER_MODE_NORMAL ); //RENDER IT!!!! XD
		int m=(fonth->glyph->metrics.horiBearingY>>6);
		int w=fonth->glyph->metrics.horiAdvance;
		int w2=fonth->glyph->metrics.horiBearingX;
		for (int a=0;a < fonth->glyph->bitmap.rows;a++){
			for (int b=0;b<fonth->glyph->bitmap.width;b++){
				int h=(a+(sb-m));
				if (h>=0&&h<sheight){
					if (h*swidth+b+swidthf+(w2/64)<swidth*sheight){
                		data[h*swidth+b+swidthf+(w2/64)]=fonth->glyph->bitmap.buffer[a*fonth->glyph->bitmap.width+b];
					}
				}
			}
		}
		//swidthf+=fonth->glyph->bitmap.width+fonth->glyph->advance.x/64;
		swidthf+=w/64;
	}
	//delete any textures if they already exist.
	if (istexture){
        if (glIsTexture(texture)){
			glDeleteTextures(1, &texture);
		}
		istexture=false;
		texture=0;
	}
	//all data is in place, now we put it into texture.
	GLuint retval=0;
	int errorCode=0;
	unsigned char *tex=(unsigned char *)malloc(sizeof(unsigned char)*theight*theight);
	for (int y=0;y<theight;y++){//a quick pass and flip around.
		for (int x=0;x<theight;x++){
			if (x<swidth&&y<sheight){
				tex[y*theight+x]=data[(sheight-y-1)*swidth+x];
			}else{
				#ifndef DEBUGDRAWTEXT
				tex[y*theight+x]=0;
				#else
				tex[y*theight+x]=16;
				#endif
			}
		}
	}
	glGenTextures( 1, &retval );
	texture=retval;
	glBindTexture( GL_TEXTURE_2D, retval );
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
	if ( errorCode != 0 ) {
		if ( errorCode == GL_OUT_OF_MEMORY ) {
			printf("Out of texture memory!\n");
			exit(0);
		}else{
			glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		}
	}
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	if(allowanisotropic)glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxanisotropy);
	errorCode = glGetError();
	if ( errorCode != 0 ) {
		if ( errorCode == GL_OUT_OF_MEMORY ) {
			printf("Out of texture memory!\n");
			free (tex);
			free (data);
			exit(0);
		}else if(errorCode == GL_INVALID_OPERATION){
			printf("You appear to not have support for a function in DigiBand.\n");
		}else{
			printf("Open GL reported an irregular error while setting filters (%i).\n",errorCode);
			if (allowanisotropic)printf("Anisotropic filtering is enabled.\n");
		}
	}
	glTexImage2D(GL_TEXTURE_2D, 0, GL_ALPHA, theight, theight, 0, GL_ALPHA, GL_UNSIGNED_BYTE, (Uint8 *)tex);
	errorCode = glGetError();
	if ( errorCode != 0 ) {
		if ( errorCode == GL_OUT_OF_MEMORY ) {
			printf("Out of texture memory!\n");
			free(data);
			free(tex);
			exit(0);
		}else if (errorCode == GL_INVALID_OPERATION){
			printf("You appear to not have support for a function in DigiBand.\n");
		}else{
			printf("Open GL reported an irregular error while generating the texture (%i).\n",errorCode);
		}
	}
	free(tex);//and now clean up after ourselves.
	free(data);
	quadsize=theight;
	white[0]=255;
	white[1]=255;
	white[2]=255;
	white[3]=255;
	v0[0]=0;
	v0[1]=0;
	v0[2]=0;
	v1[0]=quadsize;
	v1[1]=0;
	v1[2]=0;
	v2[0]=quadsize;
	v2[1]=quadsize;
	v2[2]=0;
	v3[1]=quadsize;
	v3[1]=quadsize;
	v3[2]=0;
	width=swidth;
	istexture=true;
}

void drawtext::load(char text[256],char fontname[256]="arial.ttf", int red=255, int green=255, int blue=255,int size=24){
	#ifdef EXCESSIVE
	printf("drawtext::load\n");
	#endif
	if (strlen(fontname)<1)return;
	if (strlen(text)<1)return;
	if (size<2||size>300)return;
	ther=red;
	theg=green;
	theb=blue;
	thes=size;
	if (strcmp(thefont,fontname)!=0){
		snprintf(thefont,255,"%s",fontname);
		setfont(fontname);
	}
	if (strcmp(thetext,text)!=0){
		gentextures(text);
		snprintf(thetext,255,"%s",text);
	}
	if (istexture&&fontloaded)isloaded=true;
}

void drawtext::draw(int x, int y, int z,int a,int r, int g, int b, bool blink, bool shade, bool center,bool usel){
	if (!isloaded&&!istexture)
	    return;
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("drawtext::draw\n");
	#endif
	#endif
	if (texture==0||!istexture){
		#ifdef DEBUGDRAWTEXT
		printf("WARNING: returning no texture was generated to display your font.\n");
		#endif
		return;
	}
	if (glIsTexture(texture)){
		glBindTexture(GL_TEXTURE_2D, texture);
	}else{
		//attempt to reload the texture.
		istexture=false;
		texture=0;
        gentextures(thetext);
		#ifdef DEBUG
		printf("You must have full screened, this texture is false. reseting.\n");
		#endif
	}
	r=int(double(ther)*(double(r)/255.0));
	g=int(double(theg)*(double(g)/255.0));
	b=int(double(theb)*(double(b)/255.0));
	static GLubyte shadec[4];
	double cent=0.0;
	int a2=a;
	int px=x;
	if (center)cent=width/2.0;
	if (strcmp(thetext,"")!=0){
		if (shade){
			glPushMatrix();
			glTranslated( int(x-cent), y, z );

			shadec[0]=0;
			shadec[1]=0;
			shadec[2]=0;
			shadec[3]=a;

			for (double a=0;a<6.283185307179586476925286766559;a+=0.52359877559829887307710723054658){
				glTranslatef(cos(a)*2,sin(a)*2,1.0);
				glBegin( GL_QUADS );
					glTexCoord2d( 0.0, 0.0 );
					glColor4ubv( shadec );
					glVertex3dv( v0 );
					glTexCoord2d( 1.0, 0.0 );
					glColor4ubv( shadec );
					glVertex3dv( v1 );
					glTexCoord2d( 1.0, 1.0 );
					glColor4ubv( shadec );
					glVertex3dv( v2 );
					glTexCoord2d( 0.0, 1.0 );
					glColor4ubv( shadec );
					glVertex3dv( v3 );
				glEnd();
				glTranslatef(-cos(a)*2,-sin(a)*2,1.0);
			}
			glPopMatrix();
			x+=quadsize;
		}
		x=px;
		if (!blink){
			white[0]=r;
			white[1]=g;
			white[2]=b;
			white[3]=a;
			if (a2>192)a2=192;
		}else{
			white[0]=255-int(double(255-r)*absv(cos(frameholder/20.0)));
			white[1]=255-int(double(255-g)*absv(cos(frameholder/20.0)));
			white[2]=255-int(double(255-b)*absv(cos(frameholder/20.0)));
			white[3]=a;
			if (a2>192)a2=192;
		}
		glPushMatrix();
		glTranslated( int(x-cent), y, z );
		glBindTexture(GL_TEXTURE_2D, texture);
		glBegin( GL_QUADS );
			glTexCoord2d( 0.0, 0.0 );
			glColor4ubv( white );
			glVertex3dv( v0 );
			glTexCoord2d( 1.0, 0.0 );
			glColor4ubv( white );
			glVertex3dv( v1 );
			glTexCoord2d( 1.0, 1.0 );
			glColor4ubv( white );
			glVertex3dv( v2 );
			glTexCoord2d( 0.0, 1.0 );
			glColor4ubv( white );
			glVertex3dv( v3 );
		glEnd();
		glPopMatrix();
		x+=quadsize;
	}else{
		#ifdef DEBUGDRAWTEXT
		printf("drawtext::draw, you have no text\n");
		#endif
	}
}
