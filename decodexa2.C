#ifndef LINUX
bool decodexa(char *soundfile){
	int n=strlen(soundfile);
	while (soundfile[n]!='.'){
		n--;
	if(n<0)
		return false;
	}
	if (soundfile[n+1]!='x'&&soundfile[n+1]!='X')
		return false;
	if (soundfile[n+2]!='a'&&soundfile[n+2]!='A')
		return false;
	if(!testfile(soundfile))
		return false;
	
		
	/*char *theproduct;
	int taco;
	FILE *fp;
	char temp[256];
	char *ps, *pd;
	XAHEADER xah;
	HXASTREAM hxas;
	WAVEFORMATEX wfx;
	XASTREAMHExADER xash;
	ULONG dlen;
	ULONG datalen;
	byte marmot;
	marmot=10;
	fp = fopen(soundfile, "rb");
		fread(&xah, 1, sizeof(XAHEADER), fp);
		if ( xah.id != _XAID )
			return false;
		ps = (char *)malloc(sizeof(char)*xah.nDataLen);
		fread(ps, 1, xah.nDataLen, fp);
	fclose(fp);
	sprintf(soundfile,"%s.wav",soundfile);
	if(testfile(soundfile))return true;
	hxas = xaDecodeOpen(&xah, &wfx);
	if ( hxas == NULL )
		return false;
	xaDecodeSize(hxas, xah.nDataLen, &dlen);
	datalen=xah.nDataLen;
	pd = (char *)malloc(sizeof(char)*dlen);
	theproduct=(char *)malloc((sizeof(char)*dlen)+(sizeof(char)*44));
	xash.pSrc = (UCHAR *)ps;
	xash.nSrcLen = xah.nDataLen;
	xash.nSrcUsed = 0;
	xash.pDst = (UCHAR *)pd;
	xash.nDstLen = dlen;
	xash.nDstUsed = 0;
	xaDecodeConvert(hxas, &xash);
	xaDecodeClose(hxas);*
	fp = fopen(soundfile, "wb");
		theproduct[0]='R';//good ol' RIFF!
		theproduct[1]='I';//good ol' RIFF!
		theproduct[2]='F';//good ol' RIFF!
		theproduct[3]='F';//good ol' RIFF!
		sprintf(temp,"%x",44+(sizeof(char)*dlen)-8);	
		theproduct[4]=stoh(temp,1);//file size 1
		theproduct[5]=stoh(temp,2);//file size 2
		theproduct[6]=stoh(temp,3);//file size 3
		theproduct[7]=stoh(temp,4);//file size 4
		theproduct[8]='W';//WAVEfmt(Wave Format)
		theproduct[9]='A';//WAVEfmt(Wave Format)
		theproduct[10]='V';//WAVEfmt(Wave Format)
		theproduct[11]='E';//WAVEfmt(Wave Format)
		theproduct[12]='f';//WAVEfmt(Wave Format)
		theproduct[13]='m';//WAVEfmt(Wave Format)
		theproduct[14]='t';//WAVEfmt(Wave Format)
		theproduct[15]=' ';//WAVEfmt(Wave Format)
		theproduct[16]=0x10;//file type
		theproduct[17]=0x00;//file type
		theproduct[18]=0x00;//file type
		theproduct[19]=0x00;//file type
		theproduct[20]=0x01;//compression type
		theproduct[21]=0x00;//compression type
		//Channels
		if (int(xah.nChannels)==1)
			theproduct[22]=0x01;//channels
		else
			theproduct[22]=0x02;//channels
		theproduct[23]=0x00;//channels
		sprintf(temp,"%x",xah.nSamplesPerSec);
				theproduct[24]=stoh(temp,2);//Frequency
				theproduct[25]=stoh(temp,1);//Frequency
				theproduct[26]=0x00;//Frequency
				theproduct[27]=0x00;//Frequency
		sprintf(temp,"%x",xah.nSamplesPerSec*xah.nChannels);
		theproduct[28]=stoh(temp,2);//bytes per second
		theproduct[29]=stoh(temp,1);//bytes per second
		theproduct[30]=0x00;//bytes per second
		theproduct[31]=0x00;//bytes per second
		theproduct[32]=0x02;//bytes by capture?
		theproduct[33]=0x00;//bytes by capture?
		theproduct[34]=0x10;//bps
		theproduct[35]=0x00;//bps
		//data
		theproduct[36]='d';//data
		theproduct[37]='a';//data
		theproduct[38]='t';//data
		theproduct[39]='a';//data
		sprintf(temp,"%x",sizeof(char)*(dlen));//sometimes off by 16
		#ifdef DEBUG
			printf("Now exporting wave file with attributes:\n");
			printf("file size:%i\n",44+(sizeof(char)*dlen)-8);
			printf("samples per second:%i\n",xah.nSamplesPerSec);
			printf("Channels:%i\n",xah.nChannels);
			printf("Data size:%s - %i\n",temp,sizeof(char)*(dlen));
			printf("What our data should be?:%i\n",strlen(pd));
		#endif
		if (strlen(temp)<=2){//data size stuff.
			theproduct[40]=stoh(temp,1);
			theproduct[41]=0x00;
			theproduct[42]=0x00;
			theproduct[43]=0x00;
		}else if (strlen(temp)<=4&&strlen(temp)>=3){
			theproduct[40]=stoh(temp,2);
			theproduct[41]=stoh(temp,1);
			theproduct[42]=0x00;
			theproduct[43]=0x00;
		}else if (strlen(temp)>=5&&strlen(temp)<=6){
			theproduct[40]=stoh(temp,3);
			theproduct[41]=stoh(temp,2);
			theproduct[42]=stoh(temp,1);
			theproduct[43]=0x00;
		}else if (strlen(temp)>=7){
			theproduct[40]=stoh(temp,4);
			theproduct[41]=stoh(temp,3);
			theproduct[42]=stoh(temp,2);
			theproduct[43]=stoh(temp,1);
		}
		for (int a=0;a<dlen;a++){
			theproduct[44+a]=pd[a];
		}
		if (dlen>20){
			fwrite(theproduct, 1, 44+dlen, fp);
		}
	fclose(fp);
	SDL_RWops *rw;
	free(pd);
	free(ps);
	free(theproduct);
	return true;
}
#endif
