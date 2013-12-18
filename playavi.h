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
// file: playavi.h

#ifndef avisys_H
#define avisys_H

#include <string>
using namespace std;

// libavcodec
#ifndef LINUX
#else 
#include <ffmpeg/avcodec.h>
#include <ffmpeg/avformat.h>
#endif

#include <SDL.h>
#include <GL/gl.h>
const int FRAMEBUFFERSIZE=10;
class avisys {
	public:
		avisys();
		~avisys();
		void drawavi(int, int,int, int, int);
		bool playavi(char [256], bool=false);
		GLuint avitexture;
		bool isloaded();
		void unloadvideomanual();
	private:
		int nframebuffer;
        bool pottyaccess;//thread safe locking.
		bool outhouseaccess;//thread safe locking.
		int getnextframe();
		void loadvideo(char filename[256]);
		void unloadvideo();

		//flag to tell if something has been loaded yet or not.
		bool videoisloaded;
		bool waitfirstframe;

		//for drawavi function:
		bool newvideo;
		bool okaytodraw;

		//avineeded material
		unsigned int bufw, bufh;
		Uint32 firstframe_t;
  		Uint32 nextframe_t;
		Uint32 curframe_t;
		Uint32 pkey_t;
		double fps;
		Uint32 framenumber;
		Uint32 pframenumber;
		int framecount;
		bool avieof;
		int videoStream;
		int audioStream;
		AVFormatContext *formatContext;
		AVCodecContext *codecContext;
		ImgReSampleContext *rz_context;
		AVPacket packet;
		AVCodec *decoder;
		AVFrame *theframe;
		AVFrame *resizeframe;
		AVFrame *frameRGB;
		uint8_t *resizebuffer;
		uint8_t *framebuffer;
		uint8_t *rgbbuffer;
		char curfilename[256];
		int vidwidth;
		int vidheight;
};
#endif
