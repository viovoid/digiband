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
void getmidi(int lastmidipressed){
    #ifdef EXCESSIVE
	printf("draw_getmidi\n");
	#endif
	static bool uppressed=false;
	static bool downpressed=false;
	parsekey(lastmidipressed,uppressed,downpressed);
}

#ifndef LINUX
void CALLBACK midicbfunc(HMIDIIN handle, UINT uMsg, DWORD dwInstance, DWORD dwParam1, DWORD dwParam2){
	#ifdef EXCESSIVE
	printf("CALLBACK midicbfunc\n");
	#endif
	if (dwParam1>1000){
		getmidi(dwParam1);
	}
}
#endif
