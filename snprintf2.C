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
int sprintf(char *buffer, const char *format, ...) {
	va_list ap;
	/*
	int cur_int;
	char cur_char;
	char *cur_string;
	double cur_double;
	*/

	va_start(ap, format);
	// we're going to assume that buffer was actually malloc'd for bufsize + 1 bytes
	memset(buffer, 0, bufsize + 1);
	int retval = vsprintf(buffer, ap);
	va_end(ap);
	return retval;
}
