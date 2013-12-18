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
#ifndef GENERICOBJECTS
#define GENERICOBJECTS

void render_light(int x, int y, int z);
void render_light2(int x, int y, int z);
void draw_quadt3(int ps, int x, int y, int z, double xs, double ys, int red, int green, int blue, int alpha, int angle, int angleb, int avitexture);
void draw_quadt2(int ps, int x, int y, int z, double xs, double ys, int red, int green, int blue, int alpha, int angle, int angleb, int textnum);
void draw_quad(int ps, int x, int y, int z, double xs, double ys, int red, int green, int blue, int alpha, int angle, int angleb, int textnum);
void draw_quad_frame(int ps, int x, int y, int z, double xs, double ys, int red, int green, int blue, int alpha, int angle, int angleb, int textnum, int framenum);
void draw_quad_g(int ps, int x, int y, int z, double xs, double ys, int red, int green, int blue, int alpha, int angle, int angleb, int textnum);
void draw_triangle(int x,int y,int z, int angle);
void draw_number(char number[256], int x, int y, int z,int s,int r, int g, int b, int a);
void draw_quad_text(int ps, double x, double y, double z, double xs, double ys, double angle, double angleb, int textnum, double charcol, double charrow,int r, int g, int b);
void draw_quad3(int ps, int x, int y, int z, double xs, double ys, int red, int green, int blue, int alpha, int angle, int angleb, int textnum);

#endif
