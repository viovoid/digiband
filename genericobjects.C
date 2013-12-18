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
void render_light(int x=0, int y=0, int z=0){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("render_light\n");
	#endif
	#endif
	GLfloat position[]={ x, y, z, 1.0 };
	glLightfv( GL_LIGHT0, GL_POSITION, position );
}
void render_light2(int x=0, int y=0, int z=0){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("render_light2\n");
	#endif
	#endif
	GLfloat position[]={ x, y, z, 1.0 };
	glLightfv( GL_LIGHT1, GL_POSITION, position );
}

void draw_quadt3(int ps=0, int x=0, int y=0, int z=0, double xs=10.0, double ys=10.0, int red=255, int green=255, int blue=255, int alpha=255, int angle=0, int angleb=0, int avitexture=0){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("draw_quadt3\n");
	#endif
	#endif
	GLubyte white[]  = { red,green,blue,alpha };
	static GLdouble v0[]	= { -1, -1,   0.0};
	static GLdouble v1[]	= {  1, -1,   0.0};
	static GLdouble v2[]	= {  1,  1,   0.0};
	static GLdouble v3[]	= { -1,  1,   0.0};
	glBindTexture(GL_TEXTURE_2D, avitexture);
	glPushMatrix();
	glTranslated( x, y, z );
	glRotated( angle, 0.0, 1.0, 0.0 );
	glRotated( angleb, 0.0, 0.0, 1.0 );
	glTranslated( 0, 0, ps );
	glScaled( xs, ys, 1 );
	glBegin( GL_QUADS );
		glTexCoord2d( 0, 0 );
		glColor4ubv( white );
	    glVertex3dv( v0 );
		glTexCoord2d( .99, 0 );
		glColor4ubv( white );
	    glVertex3dv( v1 );
		glTexCoord2d( .99, .99 );
		glColor4ubv( white );
	    glVertex3dv( v2 );
		glTexCoord2d( 0, .99 );
		glColor4ubv( white );
	    glVertex3dv( v3 );
	glEnd();
	glPopMatrix();
	glBindTexture(GL_TEXTURE_2D, g_Texture[51][0]);
}

void draw_quadt2(int ps=0, int x=0, int y=0, int z=0, double xs=10.0, double ys=10.0, int red=255, int green=255, int blue=255, int alpha=255, int angle=0, int angleb=0, int textnum=0){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("draw_quadt2\n");
	#endif
	#endif
	GLubyte white[]  = { red,green,blue,alpha };
	static GLdouble v0[]	= { -1, -1,   0.0};
	static GLdouble v1[]	= {  1, -1,   0.0};
	static GLdouble v2[]	= {  1,  1,   0.0};
	static GLdouble v3[]	= { -1,  1,   0.0};

	glPushMatrix();
	glTranslated( x, y, z );
	glRotated( angle, 0.0, 1.0, 0.0 );
	glRotated( angleb, 0.0, 0.0, 1.0 );
	glTranslated( 0, 0, ps );
	glScaled( xs, ys, 1 );
	
	if (textnum!=0)
		glBindTexture(GL_TEXTURE_2D, textnum);
	else
		glBindTexture(GL_TEXTURE_2D,g_Texture[51][0]);
	glBegin( GL_QUADS );
		glTexCoord2d( 0, 0 );
		glColor4ubv( white );
	    glVertex3dv( v0 );
		glTexCoord2d( 1.0-(1.0/(double)(xs*2)), 0 );
		glColor4ubv( white );
	    glVertex3dv( v1 );
		glTexCoord2d( 1.0-(1.0/(double)(xs*2)), 1.0-(1.0/(double)(ys*2)) );
		glColor4ubv( white );
	    glVertex3dv( v2 );
		glTexCoord2d( 0, 1.0-(1.0/(double)(ys*2)) );
		glColor4ubv( white );
	    glVertex3dv( v3 );
	glEnd();
	glBindTexture(GL_TEXTURE_2D, g_Texture[51][0]);
	glPopMatrix();

}

void draw_quad(int ps=0, int x=0, int y=0, int z=0, double xs=10.0, double ys=10.0, int red=255, int green=255, int blue=255, int alpha=255, int angle=0, int angleb=0, int textnum=0){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
		printf("draw_quad\n");
	#endif
	#endif
	GLubyte white[]  = { red,green,blue,alpha };
	static GLdouble v0[]	= { -1, -1,   0.0};
	static GLdouble v1[]	= {  1, -1,   0.0};
	static GLdouble v2[]	= {  1,  1,   0.0};
	static GLdouble v3[]	= { -1,  1,   0.0};

	glPushMatrix();
	glTranslated( x, y, z );
	glRotated( angle, 0.0, 1.0, 0.0 );
	glRotated( angleb, 0.0, 0.0, 1.0 );
	glTranslated( 0, 0, ps );
	glScaled( xs, ys, 1 );
	
	if (textnum!=0)
		glBindTexture(GL_TEXTURE_2D, g_Texture[textnum][int(texani[textnum][2])]);
	else
		glBindTexture(GL_TEXTURE_2D,g_Texture[51][0]);
	glBegin( GL_QUADS );
		glTexCoord2d( 0,0 );
		glColor4ubv( white );
	    glVertex3dv( v0 );
		glTexCoord2d( 1,0 );
		glColor4ubv( white );
	    glVertex3dv( v1 );
		glTexCoord2d( 1,1 );
		glColor4ubv( white );
	    glVertex3dv( v2 );
		glTexCoord2d( 0,1 );
		glColor4ubv( white );
	    glVertex3dv( v3 );
	glEnd();
	glBindTexture(GL_TEXTURE_2D, g_Texture[51][0]);
	glPopMatrix();

}

void draw_quad_frame(int ps=0, int x=0, int y=0, int z=0, double xs=10.0, double ys=10.0, int red=255, int green=255, int blue=255, int alpha=255, int angle=0, int angleb=0, int textnum=0, int framenum=0){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
		printf("draw_quad_frame\n");
	#endif
	#endif
	GLubyte white[]  = { red,green,blue,alpha };
	static GLdouble v0[]	= { -1, -1,   0.0};
	static GLdouble v1[]	= {  1, -1,   0.0};
	static GLdouble v2[]	= {  1,  1,   0.0};
	static GLdouble v3[]	= { -1,  1,   0.0};

	glPushMatrix();
	glTranslated( x, y, z );
	glRotated( angle, 0.0, 1.0, 0.0 );
	glRotated( angleb, 0.0, 0.0, 1.0 );
	glTranslated( 0, 0, ps );
	glScaled( xs, ys, 1 );
	
	if (textnum!=0)
		glBindTexture(GL_TEXTURE_2D, g_Texture[textnum][framenum]);
	else
		glBindTexture(GL_TEXTURE_2D,g_Texture[51][0]);
	glBegin( GL_QUADS );
		glTexCoord2d( 0,0 );
		glColor4ubv( white );
	    glVertex3dv( v0 );
		glTexCoord2d( 1,0 );
		glColor4ubv( white );
	    glVertex3dv( v1 );
		glTexCoord2d( 1,1 );
		glColor4ubv( white );
	    glVertex3dv( v2 );
		glTexCoord2d( 0,1 );
		glColor4ubv( white );
	    glVertex3dv( v3 );
	glEnd();
	glBindTexture(GL_TEXTURE_2D, g_Texture[51][0]);
	glPopMatrix();

}

void draw_quad_g(int ps=0, int x=0, int y=0, int z=0, double xs=10.0, double ys=10.0, int red=255, int green=255, int blue=255, int alpha=255, int angle=0, int angleb=0, int textnum=0){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
		printf("draw_quad_g\n");
	#endif
	#endif
	GLubyte white[]  = { red,green,blue,alpha };
	GLubyte black[] = {0,0,0,0};
	static GLdouble v0[]	= { -1, -1,   0.0};
	static GLdouble v1[]	= {  1, -1,   0.0};
	static GLdouble v2[]	= {  1,  1,   0.0};
	static GLdouble v3[]	= { -1,  1,   0.0};

	glPushMatrix();
	glTranslated( x, y, z );
	glRotated( angle, 0.0, 1.0, 0.0 );
	glRotated( angleb, 0.0, 0.0, 1.0 );
	glTranslated( 0, 0, ps );
	glScaled( xs, ys, 1 );
	
	if (textnum!=0)
		glBindTexture(GL_TEXTURE_2D, g_Texture[textnum][0]);
	else
		glBindTexture(GL_TEXTURE_2D,g_Texture[51][0]);
	glBegin( GL_QUADS );
		glTexCoord2d( 0, 0 );
		glColor4ubv( white );
	    glVertex3dv( v0 );
		glTexCoord2d( 1.0 - (1.0/(double)(xs*2)), 0 );
		glColor4ubv( white );
	    glVertex3dv( v1 );
		glTexCoord2d( 1.0 - (1.0/(double)(xs*2)), 1.0-(1.0/(double)(ys*2)) );
		glColor4ubv( black );
	    glVertex3dv( v2 );
		glTexCoord2d( 0, 1.0-(1.0/(double)(ys*2)) );
		glColor4ubv( black );
	    glVertex3dv( v3 );
	glEnd();
	glBindTexture(GL_TEXTURE_2D, g_Texture[51][0]);
	glPopMatrix();

}


void draw_triangle(int x=0,int y=0,int z=0, int angle=0){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
		printf("draw_triangle\n");
	#endif
	#endif
	static GLubyte red[]    = { 255,   0,   0, 255 };
	static GLubyte blue[]   = { 0,   0,   255, 255 };
	static GLubyte green[]  = { 0,   255,   0, 255 };
	static GLubyte purple[]	= { 255, 0,	  255, 255 };
	static GLdouble v0[] = { -100.0, -100.0, 100.0 };
    static GLdouble v1[] = {  100.0, -100.0, 0.0 };
    static GLdouble v2[] = {  0.0,  100.0, 0.0 };
	static GLdouble v3[] = { -100.0, -100.0, -100.0 };
    static GLdouble v4[] = {  100.0, -100.0, 0.0 };
    static GLdouble v5[] = {  0.0,  100.0, 0.0 };

	glPushMatrix();
	glTranslated( x,y,z );
	glRotated( angle, 0.0, 1.0, 0.0 );
		
	glBegin( GL_TRIANGLES );
		glColor4ubv( green );
	    glVertex3dv( v0 );
	    glColor4ubv( red );
	    glVertex3dv( v1 );
	    glColor4ubv( blue );
		glVertex3dv( v2 );

		glColor4ubv( purple );
	    glVertex3dv( v3 );
	    glColor4ubv( red );
	    glVertex3dv( v4 );
	    glColor4ubv( blue );
		glVertex3dv( v5 );
		
		glVertex3dv( v5 );
		glColor4ubv( purple );
	    glVertex3dv( v3 );
	    glColor4ubv( green );
	    glVertex3dv( v0 );

		glColor4ubv( red );
	    glVertex3dv( v1 );
	    glColor4ubv( green );
	    glVertex3dv( v0 );
		glColor4ubv( purple );
	    glVertex3dv( v3 );
		
	    
		
	glEnd();
	glPopMatrix();

}

void draw_number(char number[256], int x, int y, int z,int s=10,int r=255, int g=255, int b=255, int a=255){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
		printf("draw_number\n");
	#endif
	#endif
	char temp[256];
	for (int i=0;i<strlen(number);i++){
		int frame=(int)number[i];
		int newframe=-1;
		if (frame==91||frame==92){
			newframe=frame-29;
		}
		if (frame>64&&frame<91){
			newframe=frame-64;
			newframe=(newframe*2)-2;
		}
		if (frame>96&&frame<123){
			newframe=frame-96;
			newframe=(newframe*2)-1;	
		}
		if (frame>47&&frame<58){
			newframe=(frame-48)+52;
		}
		frame=newframe;
		//frame number needed.
		if (frame>-1&&frame<64){
			draw_quad_frame(0, x+(i*s),y,z+(i*10),s/2,s, r,g,b,a,0,0,40,frame);
		}
	}
}
void draw_quad_text(int ps=0, double x=0, double y=0, double z=0, double xs=10.0, double ys=10.0, double angle=0.0, double angleb=0.0, int textnum=0, double charcol=0, double charrow=0,int r=0, int g=0, int b=0){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
		printf("draw_quad_text\n");
	#endif
	#endif
	GLubyte white[]  = { r, g, b, 255 };
	GLdouble v0[]	= { -xs, -ys,   0.0};
	GLdouble v1[]	= {  xs, -ys,   0.0};
	GLdouble v2[]	= {  xs,  ys,   0.0};
	GLdouble v3[]	= { -xs,  ys,   0.0};
	charcol=charcol/50.0;
	charrow=charrow/2.0;

	glPushMatrix();
	glTranslated( x, y, z );
	glRotated( angle, 0.0, 1.0, 0.0 );
	glRotated( angleb, 0.0, 0.0, 1.0 );
	glTranslated( 0, 0, ps );
	//glScaled( xs, ys, zs );

	glBindTexture(GL_TEXTURE_2D, g_Texture[textnum][0]);
	glBegin( GL_QUADS );
		glTexCoord2f( charcol,charrow +.02f);
		glColor4ubv( white );
	    glVertex3dv( v0 );
		glTexCoord2f( charcol+.019f, charrow+.02f);
		glColor4ubv( white );
	    glVertex3dv( v1 );
		glTexCoord2f( charcol+.019f, charrow+.5f );
		glColor4ubv( white );
	    glVertex3dv( v2 );
		glTexCoord2f( charcol, charrow+.5f );
		glColor4ubv( white );
	    glVertex3dv( v3 );
	glEnd();
	glBindTexture(GL_TEXTURE_2D, g_Texture[51][0]);
	glPopMatrix();

}



void draw_quad3(int ps=0, int x=0, int y=0, int z=0, double xs=10.0, double ys=10.0, int red=255, int green=255, int blue=255, int alpha=255, int angle=0, int angleb=0, int textnum=0){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("draw_quad3\n");
	#endif
	#endif
	GLubyte white[]  = { red,green,blue,alpha };
	static GLdouble v0[]	= { -1, -1,   0.0};
	static GLdouble v1[]	= {  1, -1,   0.0};
	static GLdouble v2[]	= {  1,  1,   0.0};
	static GLdouble v3[]	= { -1,  1,   0.0};

	glPushMatrix();
	glTranslated( x, y, z );
	glRotated( angle, 0.0, 1.0, 0.0 );
	glRotated( angleb, 0.0, 0.0, 1.0 );
	glTranslated( 0, 0, ps );
	glScaled( xs, ys, 1 );
	
	if (textnum!=0)
		glBindTexture(GL_TEXTURE_2D, g_Texture[textnum][0]);
	else
		glBindTexture(GL_TEXTURE_2D,g_Texture[51][0]);
	glBlendFunc( GL_SRC_ALPHA, GL_ONE );
	glBegin( GL_QUADS );
		glTexCoord2d( texani[textnum][2]/texani[textnum][0]+(1.0/(double)(xs*2)), 0 );
		glColor4ubv( white );
	    glVertex3dv( v0 );
		glTexCoord2d( texani[textnum][2]/texani[textnum][0] + 1/texani[textnum][0] - (1.0/(double)(xs*2)), 0 );
		glColor4ubv( white );
	    glVertex3dv( v1 );
		glTexCoord2d( texani[textnum][2]/texani[textnum][0] + 1/texani[textnum][0] - (1.0/(double)(xs*2)), 1.0-(1.0/(double)(ys*2)) );
		glColor4ubv( white );
	    glVertex3dv( v2 );
		glTexCoord2d( texani[textnum][2]/texani[textnum][0]+(1.0/(double)(xs*2)), 1.0-(1.0/(double)(ys*2)) );
		glColor4ubv( white );
	    glVertex3dv( v3 );
	glEnd();
	glBindTexture(GL_TEXTURE_2D, g_Texture[51][0]);
	glPopMatrix();
	glBlendFunc( GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA );
}

