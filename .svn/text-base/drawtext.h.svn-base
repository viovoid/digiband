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
class drawtext{
	public:
		static void nukeAllInstances();
		static void zap();
		drawtext();
		void forceconstructor();
		~drawtext();
		void load(char[256],char[256],int,int,int,int);
		void draw(int,int,int,int=255,int=255,int=255,int=255,bool=false,bool=false,bool=false,bool=false);
		int width;
		int height;
	 	int lr;
		int lg;
		int lb;
		char thetext[256];
	private:
   		static drawtext **instances;
		static long long instancessize;
        long long instancenumber;
		void selfDestruct();
		void registerInstance();
		void setfont(char[256]);
		void gentextures(char[256]);
		FT_Face fonth; //our font handle.(was known as face).
		iconv_t converter;
		char thefont[256];
		unsigned int texture;
		int quadsize;
		int ther;
		int theg;
		int theb;
		int thes;
		bool istexture;
		bool isloaded;
		bool fontloaded;
		GLubyte white[4];
		GLdouble v0[3];
		GLdouble v1[3];
		GLdouble v2[3];
		GLdouble v3[3];
};
