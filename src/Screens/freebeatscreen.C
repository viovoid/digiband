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
void freebeatscreen(){
	#ifdef EXCESSIVE
	printf("freebeatscreen\n");
	#endif
	draw_quad(0,512,384,-5000,640,400,255,255,255,255,0,0,17);
	int hihatts=0;
	int snarets=0;
	int bassts=0;
	int hitomts=0;
	int lotomts=0;
	int cymbalts=0;
	int offset=-36;
	int goffset=51;
	int g2offset=166;
	
}
