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
//DO NOT TOUCH UNLESS IT'S CRASHING!!!!!!
bool VIDERROR=false;
avisys::avisys(){
	#ifdef EXCESSIVE
	printf("avisys::avisys\n");
	#endif
	av_register_all();
	avitexture = 0;
	videoisloaded = false;
	waitfirstframe = false;
	firstframe_t=0;
	nextframe_t=0;
	curframe_t=0;
	framenumber=99999;
	fps=30;
 	snprintf(curfilename,255,"NULL");
	nframebuffer=0;
	pottyaccess=false;//thread safe locking.
	outhouseaccess=false;//thread safe locking.
	//declaring everything NULL just to be safe. (do this on load too).
	rz_context=NULL;
	codecContext=NULL;
	formatContext=NULL;
	frameRGB=NULL;
	resizeframe=NULL;
	theframe=NULL;
	rgbbuffer=NULL;
	framebuffer=NULL;
	resizebuffer=NULL;
}

avisys::~avisys(){
	#ifdef EXCESSIVE
	printf("avisys::~avisys\n");
	#endif
	if (videoisloaded){
		unloadvideo();
	}
}

int avisys::getnextframe(){
	/*av_freepacket is possibly not what we should be doing.. it's not a pointer so there's no need to call it.*/
	#ifdef EXCESSIVE
	printf("avisys::getnextframe\n");
	#endif
    int to=0;
    //for (int to=0;to<250||!pottyaccess;to++){
	while(pottyaccess){
		SDL_Delay(1);
		to++;
		if(to>250){
			pottyaccess=false;
			//return -1;
		}
	}
	pottyaccess=true;
		curframe_t=SDL_GetTicks()-firstframe_t;
	if(nframebuffer>FRAMEBUFFERSIZE-1){pottyaccess=false;return 1;}
	int bytesDecoded=0;
	int frameFinished=0;
	// ho-kay.  We're going to eat packets until we see our video stream index
	if (formatContext==NULL){
		#ifdef DEBUG
		    printf("format Context not loaded properly.\n");
		#endif
		pottyaccess=false;return 0;
	}
	av_read_play(formatContext);
    if (nframebuffer>7)SDL_Delay(1);
	bool readaframe=false;
	while (!readaframe){
		frameFinished=av_read_frame(formatContext, &packet);
		if (nframebuffer>5)SDL_Delay(1);
		if (frameFinished>=0){
	        if (packet.stream_index == videoStream) {
				//foundwhat we want and then continue.
				if (packet.size>0&&packet.data!=NULL){
                    //why is this crashing?
                    bytesDecoded=-1;
					if (codecContext!=NULL&&resizeframe!=NULL){
		   				bytesDecoded = avcodec_decode_video(codecContext, resizeframe, &frameFinished, packet.data, packet.size);
					}
					if (bytesDecoded < 0) {
		                av_free_packet(&packet);
						pottyaccess=false;
						//throw string("Error while decoding a frame");
						VIDERROR=true;
						#ifdef DEBUG
						printf("Error while decoding a frame");
						#endif
						return -1;
					}
					readaframe=true;
				}else{
                    readaframe=true;
				}
                if (nframebuffer>5)SDL_Delay(1);
			}else{
				//didn't find what we want.
				//av_free_packet(&packet);
				if (nframebuffer>5)SDL_Delay(1);
			}
		}else{
			//this means there's nothing else to decode...
			av_free_packet(&packet);
			pottyaccess=false;
			#ifdef DEBUG
			printf("Nothing found to decode\n");
			#endif
            return 0;
		}
	}
	if (bytesDecoded != packet.size){
		#ifdef DEBUG
		cout << "Hmm... decoded size didn't match packet size" << endl;
		#endif
	}
	av_free_packet(&packet);
    if (nframebuffer>5)SDL_Delay(1);
	//resize and prepare for render.
	if (resizeframe->data[0]!=NULL&&theframe!=NULL){
		nframebuffer++;
		if (rz_context!=NULL){
			img_resample(rz_context, (AVPicture *) theframe, (AVPicture *) resizeframe);
		}else{
			#ifdef DEBUG
			printf("what's going on with the img_resample failing.\n");
			#endif
			pottyaccess=false;
			return 0;
		}
        if (nframebuffer>3)SDL_Delay(1);
		if(theframe->data[0]!=NULL){
			img_convert((AVPicture *)frameRGB, PIX_FMT_RGB24, (AVPicture *)theframe, codecContext->pix_fmt, vidwidth, vidheight);
			if (nframebuffer>7)SDL_Delay(1);
		}
		waitfirstframe=false;
	}
	pottyaccess=false;
	return 1;
}

void avisys::loadvideo(char filename[256]){
	#ifdef EXCESSIVE
	printf("avisys::loadvideo\n");
	#endif
    int to=0;
	while(outhouseaccess){
		SDL_Delay(1);to++;
		if(to>250){
			outhouseaccess=false;
			//return;
		}
	}
    outhouseaccess=true;
	if (videoisloaded){
        outhouseaccess=false;
		//throw string("A video is already loaded");
		VIDERROR=true;
		#ifdef DEBUG
		printf("A video is already loaded");
		#endif
		return;
	}
	if (!videoisloaded){
		//SDL_Delay(1);
		if (!testfile(filename)){
			snprintf(curfilename,255,"%s",filename);//if the file doesn't exist we don't want to keep trying to load the same thing over and over again.
			char marmot[512];
			snprintf(marmot,511,"%s does not exist",filename);
            outhouseaccess=false;
			//throw string(marmot);
			VIDERROR=true;
			#ifdef DEBUG
			printf("%s",marmot);
			#endif
			return;
		}
	 	//SDL_Delay(2);
	}
	#ifdef DEBUG
	printf("Now loading: (%s)\n",filename);
	printf("load step 1\n");
	#endif
	/*rz_context=NULL;
	codecContext=NULL;
	formatContext=NULL;
	frameRGB=NULL;
	resizeframe=NULL;
	theframe=NULL;
	rgbbuffer=NULL;
	framebuffer=NULL;
	resizebuffer=NULL;
	SDL_Delay(1);*/
	//The video loading code outside of the skeleton.
	to=0;
	while(fstreampotty>0){}
   	fstreampotty++;
	if (av_open_input_file(&formatContext, filename, 0, 0, 0)!=0){
        outhouseaccess=false;
        fstreampotty--;
        formatContext=NULL;
		//throw string("av_open_input_file failed");
		VIDERROR=true;
		#ifdef DEBUG
		printf("av_open_input_file failed");
		#endif
		return;
	}
    fstreampotty--;
	#ifdef DEBUG
	printf("load step 2\n");
	#endif
	SDL_Delay(1);
	if (av_find_stream_info(formatContext) < 0){
        if (formatContext!=NULL)av_close_input_file(formatContext);formatContext=NULL;
        outhouseaccess=false;
		//throw string("av_find_stream_info failed");
		VIDERROR=true;
		#ifdef DEBUG
		printf("av_find_stream_info failed");
		#endif
		return;
	}
	#ifdef DEBUG
	printf("load step 3\n");
	#endif
	SDL_Delay(1);
	//printf("Does %s read anything?\n",formatContext->filename);YES IT DOES!DO SOMETHING WITH ME!
	dump_format(formatContext, 0, filename, false);
	#ifdef DEBUG
	printf("load step 4\n");
	#endif
	SDL_Delay(1);
	videoStream=-1;
	for (int i = 0; i < formatContext->nb_streams; i++) {
		if (formatContext->streams[i]->codec->codec_type == CODEC_TYPE_VIDEO) {
			videoStream = i;
            formatContext->streams[i]->codec->workaround_bugs=true;
            break;
		}
	}
	#ifdef DEBUG
	printf("load step 5\n");
	#endif
	SDL_Delay(1);
	if (videoStream == -1){
		#ifdef DEBUG
		printf("quiterror\n");
		#endif
		if (formatContext!=NULL)av_close_input_file(formatContext);formatContext=NULL;
        outhouseaccess=false;
		//throw string("Video file has no video streams");
		VIDERROR=true;
		#ifdef DEBUG
		printf("Video file has no video streams");
		#endif
		return;
	}
	#ifdef DEBUG
	printf("load step 6\n");
	#endif
	SDL_Delay(1);
	codecContext = formatContext->streams[videoStream]->codec;
	#ifdef DEBUG
	printf("load step 7\n");
	#endif
	SDL_Delay(1);
	decoder=avcodec_find_decoder(codecContext->codec_id);
	if (decoder == NULL){
		if (formatContext!=NULL)av_close_input_file(formatContext);formatContext=NULL;
		if(codecContext!=NULL)codecContext=NULL;
        outhouseaccess=false;
		//throw string("Unable to find a video codec");
		VIDERROR=true;
		#ifdef DEBUG
		printf("Unable to find a video codec");
		#endif
		return;
	}
	#ifdef DEBUG
	printf("load step 8\n");
	#endif
	SDL_Delay(1);
	if (avcodec_open(codecContext, decoder) < 0){
		if (formatContext!=NULL)av_close_input_file(formatContext);formatContext=NULL;
		if(codecContext!=NULL)codecContext=NULL;
        outhouseaccess=false;
		//throw string("Unable to open video codec");
		VIDERROR=true;
		#ifdef DEBUG
		printf("Unable to open video codec");
		#endif
		return;
	}
	#ifdef DEBUG
	printf("load step 9\n");
	#endif
	SDL_Delay(1);
	theframe = avcodec_alloc_frame();
	if (theframe == NULL){
		if (formatContext!=NULL)av_close_input_file(formatContext);formatContext=NULL;
		if(codecContext!=NULL)avcodec_close(codecContext);codecContext=NULL;
		outhouseaccess=false;
		//throw string("Couldn't allocate the master frame");
		VIDERROR=true;
		#ifdef DEBUG
		printf("Couldn't allocate the master frame");
		#endif
		return;
	}
	#ifdef DEBUG
	printf("load step 10\n");
	#endif
	SDL_Delay(1);
	resizeframe=avcodec_alloc_frame();
	if (resizeframe == NULL){
        if (theframe!=NULL)av_free(theframe);theframe=NULL;
		if (formatContext!=NULL)av_close_input_file(formatContext);formatContext=NULL;
		if(codecContext!=NULL)avcodec_close(codecContext);codecContext=NULL;
        outhouseaccess=false;
		//throw string("Couldn't allocate the resizing frame");
		VIDERROR=true;
		#ifdef DEBUG
		printf("Couldn't allocate the resizing frame");
		#endif
		return;
	}
	#ifdef DEBUG
	printf("load step 11\n");
	#endif
	SDL_Delay(1);
	frameRGB = avcodec_alloc_frame();
	if (frameRGB == NULL){
	    if (resizeframe!=NULL)av_free(resizeframe);resizeframe=NULL;
        if (theframe!=NULL)av_free(theframe);theframe=NULL;
		if (formatContext!=NULL)av_close_input_file(formatContext);formatContext=NULL;
		if(codecContext!=NULL)avcodec_close(codecContext);codecContext=NULL;
		#ifdef DEBUG
		printf("FrameRBG == NULL detected.\n");
		#endif
		appisrunning=false;
        outhouseaccess=false;
		//throw string("Couldn't allocate the RGB frame");
		VIDERROR=true;
		#ifdef DEBUG
		printf("Couldn't allocate the RGB frame");
		#endif
		return;
	}
	#ifdef DEBUG
	printf("load step 12\n");
	#endif
	SDL_Delay(1);
	vidwidth=avires;
	vidheight=avires;
	int numBytes = 0;
	numBytes = avpicture_get_size(PIX_FMT_YUV420P, codecContext->width, codecContext->height);
	resizebuffer = (uint8_t *)malloc(sizeof(uint8_t)*numBytes);
	memset(resizebuffer, 0, numBytes);
	numBytes=avpicture_get_size(PIX_FMT_YUV420P, vidwidth, vidheight);
	framebuffer = (uint8_t *)malloc(sizeof(uint8_t)*numBytes);
	memset(framebuffer, 0, numBytes);
	numBytes=avpicture_get_size(PIX_FMT_RGB24, vidwidth, vidheight);
    rgbbuffer=(uint8_t *)malloc(sizeof(uint8_t)*numBytes);
	memset(rgbbuffer, 0, numBytes);
	#ifdef DEBUG
	printf("load step 13\n");
	#endif
	SDL_Delay(1);
	avpicture_fill((AVPicture *)resizeframe, resizebuffer, PIX_FMT_YUV420P, codecContext->width, codecContext->height);
	avpicture_fill((AVPicture *)theframe, framebuffer, PIX_FMT_YUV420P, vidwidth, vidheight);
	avpicture_fill((AVPicture *)frameRGB, rgbbuffer, PIX_FMT_RGB24, vidwidth, vidheight);
	#ifdef DEBUG
	printf("load step 14\n");
	#endif
	SDL_Delay(1);
	avcodec_flush_buffers(formatContext->streams[videoStream]->codec);
	rz_context = img_resample_init(vidwidth, vidheight, codecContext->width, codecContext->height);
	//end video loading, continuing with skeleton of the class.
	
	//determine the FPS of the video:
	fps=double(formatContext->streams[videoStream]->r_frame_rate.num)/double(formatContext->streams[videoStream]->r_frame_rate.den);
	#ifdef DEBUG
	printf("found frame rate: %f\n",fps);
	#endif
	//if (fps>29.99999999)fps=29.999999999;//(If too fast, key it to NTSC)
	//seek to the first frame to push the video initializing.
	#ifdef DEBUG
	printf("load step 15\n");
	#endif
	SDL_Delay(1);
	firstframe_t = SDL_GetTicks();
	nextframe_t = firstframe_t;
	curframe_t = firstframe_t;
	pkey_t=0;
	framenumber=999999;
	pframenumber=0;
	snprintf(curfilename,255,"%s",filename);
	videoisloaded=true;
	newvideo=true;
	waitfirstframe=true;
	avieof=false;
	nframebuffer=0;
	#ifdef DEBUG
	printf("Video Loaded: %s\n",filename);
	#endif
    outhouseaccess=false;
}

bool avisys::isloaded(){
	#ifdef EXCESSIVE
	printf("avisys::isloaded\n");
	#endif
	return videoisloaded;
}

void avisys::unloadvideomanual(){
	#ifdef EXCESSIVE
	printf("avisys::unloadvideomanual\n");
	#endif
    int to=0;
	while(outhouseaccess){
		SDL_Delay(1);
		to++;
		if(to>250){
			outhouseaccess=false;
			//return;
		}
	}
    outhouseaccess=true;
	if (!videoisloaded) {outhouseaccess=false;return;}
	videoisloaded=false;
	//the video unloaded code outside of the skeleton
	#ifdef DEBUG
	printf("Unload step 1\n");
	#endif
	snprintf(curfilename,255,"NULL");
	SDL_Delay(1);
	if(rz_context!=NULL)img_resample_close(rz_context);rz_context=NULL;
	#ifdef DEBUG
	printf("Unload step 2\n");
	#endif
	SDL_Delay(1);
	if(codecContext!=NULL)avcodec_close(codecContext);codecContext=NULL;
	#ifdef DEBUG
	printf("Unload step 3\n");
	#endif
	SDL_Delay(1);
	if (formatContext!=NULL)av_close_input_file(formatContext);formatContext=NULL;
	if (rgbbuffer!=NULL)free(rgbbuffer);rgbbuffer=NULL;
	if (framebuffer!=NULL)free(framebuffer);framebuffer=NULL;
	if (resizebuffer!=NULL)free(resizebuffer);resizebuffer=NULL;
	#ifdef DEBUG
	printf("Unload step 4\n");
	#endif
	SDL_Delay(1);
	//decoder=NULL;
	if (frameRGB!=NULL)av_free(frameRGB);frameRGB=NULL;
	if (resizeframe!=NULL)av_free(resizeframe);resizeframe;
	if (theframe!=NULL)av_free(theframe);theframe=NULL;
	#ifdef DEBUG
	printf("Unload step 5\n");
	#endif
	SDL_Delay(1);
	//end video unloaded,continuing with skeleton code.
	#ifdef DEBUG
	printf("Video Closed\n");
	#endif
    outhouseaccess=false;
}

void avisys::unloadvideo(){
	#ifdef EXCESSIVE
	printf("avisys::unloadvideo\n");
	#endif
    int to=0;
	while(outhouseaccess){
		SDL_Delay(1);
		to++;if(to>250){
			outhouseaccess=false;
			//return;
		}
	}
    outhouseaccess=true;
	if (!videoisloaded) {outhouseaccess=false;return;}
	videoisloaded=false;
	//the video unloaded code outside of the skeleton
	#ifdef DEBUG
	printf("Unload step 1\n");
	#endif
	snprintf(curfilename,255,"NULL");
	SDL_Delay(1);
	if(rz_context!=NULL)img_resample_close(rz_context);rz_context=NULL;
	#ifdef DEBUG
	printf("Unload step 2\n");
	#endif
	SDL_Delay(1);
	if(codecContext!=NULL)avcodec_close(codecContext);codecContext=NULL;
	#ifdef DEBUG
	printf("Unload step 3\n");
	#endif
	SDL_Delay(1);
	if (formatContext!=NULL)av_close_input_file(formatContext);formatContext=NULL;
	if (rgbbuffer!=NULL)free(rgbbuffer);rgbbuffer=NULL;
	if (framebuffer!=NULL)free(framebuffer);framebuffer=NULL;
	if (resizebuffer!=NULL)free(resizebuffer);resizebuffer=NULL;
	#ifdef DEBUG
	printf("Unload step 4\n");
	#endif
	SDL_Delay(1);
	//decoder=NULL;
	if (frameRGB!=NULL)av_free(frameRGB);frameRGB=NULL;
	if (resizeframe!=NULL)av_free(resizeframe);resizeframe;
	if (theframe!=NULL)av_free(theframe);theframe=NULL;
	#ifdef DEBUG
	printf("Unload step 5\n");
	#endif
	SDL_Delay(1);
	//end video unloaded,continuing with skeleton code.
	#ifdef DEBUG
	printf("Video Closed\n");
	#endif
    outhouseaccess=false;
}

bool avisys::playavi(char filename[256], bool repeat){
	#ifdef EXCESSIVE
	printf("avisys::playavi\n");
	#endif
    if (strlen(filename)<4){
        SDL_Delay(1);
        #ifdef DEBUG
        printf("returning, you gave me garbage\n");
        #endif
        return false;
    }
	//loading and unloading handling.
	char message[5];
	message[0]=filename[strlen(filename)-4];
	message[1]=filename[strlen(filename)-3];
	message[2]=filename[strlen(filename)-2];
	message[3]=filename[strlen(filename)-1];
	message[4]='\0';
	if (strcmp(message,"KILL")==0||strcmp(message,"NULL")==0){
		if (videoisloaded){
			unloadvideo();
		}
	}
	if (strcmp(filename,curfilename)!=0){
		if (videoisloaded){
			unloadvideo();
		}
  		//try{
            loadvideo(filename);
		//}catch (string &err) {
		if (VIDERROR){
			#ifdef DEBUG
			//cout<<"Video failed to load: "<<err<<endl;
			#endif
			VIDERROR=false;
			return false;
		}
	}
	if (nframebuffer>8)SDL_Delay(1);
	if (videoisloaded&&!avieof){
		int errlev=0;
		errlev=getnextframe();
        if (VIDERROR==true){
			#ifdef DEBUG
			//cout<<"Failed to pull frame ("<<errlev<<"):"<<err<<endl;
			#endif
			errlev=-1;
			VIDERROR=false;
		}
		if (errlev==0){
            #ifdef DEBUG
            printf("Video EOF\n");
            #endif
			if (repeat){
				av_seek_frame(formatContext, -1, 1,AVSEEK_FLAG_ANY);
				firstframe_t = SDL_GetTicks();
				nextframe_t = firstframe_t;
				curframe_t = firstframe_t;
				framenumber=999999;
				pframenumber=0;
            }else{
				avieof=true;
				unloadvideo();
			}
		}//else{
		//	avieof=true;
		//	unloadvideo();
		//}
	}
	if (nframebuffer>9)SDL_Delay(1);
	return true;
}


void avisys::drawavi(int x, int y,int z, int w, int h){
	#ifdef EXCESSIVE
	#ifndef EXCESSIVELITE
	printf("avisys::drawavi\n");
	#endif
	#endif
	if (!videoisloaded)
	    return;
	if (outhouseaccess)
		return;
	outhouseaccess=true;
	if (avitexture==0){
		glGenTextures(1, &avitexture);
		if (avitexture>0){
			glBindTexture(GL_TEXTURE_2D, avitexture);
			Uint32 blackframe=0;//hehe crappy trick to make the 1st frame black.
			glTexImage2D(GL_TEXTURE_2D, 0, 3,1,1, 0, GL_RGB, GL_UNSIGNED_BYTE, &blackframe);
		}
	}
	
	if (newvideo){
		if (avitexture>0){
			glBindTexture(GL_TEXTURE_2D, avitexture);
			Uint32 blackframe=0;//hehe crappy trick to make the 1st frame black.
			glTexImage2D(GL_TEXTURE_2D, 0, 3,1,1, 0, GL_RGB, GL_UNSIGNED_BYTE, &blackframe);
		}
    	newvideo=false;
	}
	glBindTexture(GL_TEXTURE_2D, avitexture);
	framenumber=Uint32(double(curframe_t)/(1000.0/fps));
    if (nframebuffer>0&&pframenumber<framenumber){
        int to=0;
		while(pottyaccess){
			SDL_Delay(1);
			to++;
			if(to>250){
				pottyaccess=false;
				//return;
			}
		}
        pottyaccess=true;
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
    	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
        if(allowanisotropic)glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAX_ANISOTROPY_EXT, maxanisotropy);
		glTexImage2D(GL_TEXTURE_2D, 0, 3, vidwidth, vidheight, 0, GL_RGB, GL_UNSIGNED_BYTE, frameRGB->data[0]);
        nframebuffer--;
		pframenumber++;
		pottyaccess=false;
	}

	glBegin(GL_QUADS);
	glColor3d(1.0, 1.0, 1.0);

	glTexCoord2d(0.0, 1.0);
	glVertex3i(x-w, y-h, z);

	glTexCoord2d(0.0, 0.0);
	glVertex3i(x-w, y + h, z);

	glTexCoord2d(1.0, 0.0);
	glVertex3i(x + w, y + h, z);

	glTexCoord2d(1.0, 1.0);
	glVertex3i(x + w, y-h, z);
	glEnd();
	#ifdef DEBUG
	char thetime[256];
	snprintf(thetime,255,"%i %i",framenumber,nframebuffer);
	draw_number(thetime,x,y-(h/3),z+10,20,255,255,255);
	#endif
	outhouseaccess=false;
}
