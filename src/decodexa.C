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

/*Oh... nothing like using a library that you have no idea how it works and no idea what
to do with the data it gives you and the only documentation you have is a example program.
Well at least this way I was able to 'hack' it and figure out how it works by poking its
header file.  Thank you bandjam.net for allowing public use of the codec.  It's just
to bad the codec has a round about usage.
*/
#ifndef LINUX
bool decodexa(char soundfile[300]){
	#ifdef EXCESSIVE
	printf("decodexa\n");
	#endif
	int n=strlen(soundfile);
	if (n<1)return false;
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
	char soundfile2[256];
	snprintf(soundfile2,255, "%s.wav", soundfile);
	if(testfile(soundfile2)){
		snprintf(soundfile,299, "%s", soundfile2);
		return true;
	}
	
	//files needed:
	FILE *ip;//input file
	FILE *fp;//output file
	char temp[256];
	
	//pull data from the XA file
	XAHEADER xah;//the header data for the xa file
	char *xad;//the xa file data
	ip = fopen(soundfile, "rb");
		fread(&xah, 1, sizeof(XAHEADER), ip);//put data into the header.
		if (sizeof(char)*xah.nDataLen<1){
			fclose(ip);
			return false;
		}
		xad = (char *)malloc(sizeof(char)*xah.nDataLen);//size xad to data length
		if (ip==NULL)
			return false;
		if (feof(ip)){
			fclose(ip);
			return false;
		}
		fread(xad, sizeof(char), xah.nDataLen, ip);//read data into data 
	fclose(ip);//this leaves us with the header:xah and data:xad
	
	//open the stream
	HXASTREAM xas;//the xa stream
	WAVEFORMATEX wfx;//not sure why we need a wave format object...
	xas = xaDecodeOpen(&xah, &wfx);//open the decoder and..*ugh*..putting header information needed in the wfx.
		if (xas==NULL){
			free(xad);
			return false;	
		}
		
		//determine the datalength of the final product
		ULONG dlen;
		xaDecodeSize(xas, xah.nDataLen, &dlen);//supposedly returns number of bytes the encoding will be.
		
		//size or out data to dlen
		char *wad;
		wad = (char *)malloc(sizeof(char)*dlen);
		
		//the decoding using a stream header.
		XASTREAMHEADER xash;//the xa stream header
		xash.pSrc = (UCHAR *)xad;//set the source to our xa data
		xash.nSrcLen = xah.nDataLen;//the length of data to pull from.
		xash.nSrcUsed = 0; //number of sources used?
		xash.pDst = (UCHAR *)wad;//set the destination to our wav data
		xash.nDstLen = dlen;//the length of data to pull to.
		xash.nDstUsed = 0; //number of destinations used?
		xaDecodeConvert(xas, &xash);//FINALLY, we tell it to convert
	xaDecodeClose(xas);//close the stream
	
	char *theproduct;//the wave file
	theproduct=(char *)malloc((sizeof(char)*dlen)+(sizeof(char)*44));//size our wave file
	theproduct[dlen+43]='\0';
	fp = fopen(soundfile2, "wb");
		theproduct[0]='R';//good ol' RIFF!
		theproduct[1]='I';//good ol' RIFF!
		theproduct[2]='F';//good ol' RIFF!
		theproduct[3]='F';//good ol' RIFF!
		snprintf(temp,255, "%x", 44+(sizeof(char)*dlen)-8);
		if (strlen(temp)<=2){//appearntly files size is reverse notation as well.
			theproduct[4]=stoh(temp,1);
			theproduct[5]=0x00;
			theproduct[6]=0x00;
			theproduct[7]=0x00;
		}else if (strlen(temp)<=4&&strlen(temp)>=3){
			theproduct[4]=stoh(temp,2);
			theproduct[5]=stoh(temp,1);
			theproduct[6]=0x00;
			theproduct[7]=0x00;
		}else if (strlen(temp)>=5&&strlen(temp)<=6){
			theproduct[4]=stoh(temp,3);
			theproduct[5]=stoh(temp,2);
			theproduct[6]=stoh(temp,1);
			theproduct[7]=0x00;
		}else if (strlen(temp)>=7){
			theproduct[4]=stoh(temp,4);
			theproduct[5]=stoh(temp,3);
			theproduct[6]=stoh(temp,2);
			theproduct[7]=stoh(temp,1);
		}
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
		if (int(wfx.nChannels)==1)
			theproduct[22]=0x01;//channels
		else
			theproduct[22]=0x02;//channels
		theproduct[23]=0x00;//channels
		snprintf(temp,255, "%x", wfx.nSamplesPerSec);
		if (strlen(temp)<=2){//appearntly files size is reverse notation as well.
			theproduct[24]=stoh(temp,1);//frequency
			theproduct[25]=0x00;
			theproduct[26]=0x00;
			theproduct[27]=0x00;
		}else if (strlen(temp)<=4&&strlen(temp)>=3){
			theproduct[24]=stoh(temp,2);
			theproduct[25]=stoh(temp,1);
			theproduct[26]=0x00;
			theproduct[27]=0x00;
		}else if (strlen(temp)>=5&&strlen(temp)<=6){
			theproduct[24]=stoh(temp,3);
			theproduct[25]=stoh(temp,2);
			theproduct[26]=stoh(temp,1);
			theproduct[27]=0x00;
		}else if (strlen(temp)>=7){
			theproduct[24]=stoh(temp,4);
			theproduct[25]=stoh(temp,3);
			theproduct[26]=stoh(temp,2);
			theproduct[27]=stoh(temp,1);
		}
		snprintf(temp,255, "%x", wfx.nAvgBytesPerSec);
		if (strlen(temp)<=2){//appearntly files size is reverse notation as well.
			theproduct[28]=stoh(temp,1);//kbps
			theproduct[29]=0x00;
			theproduct[30]=0x00;
			theproduct[31]=0x00;
		}else if (strlen(temp)<=4&&strlen(temp)>=3){
			theproduct[28]=stoh(temp,2);
			theproduct[29]=stoh(temp,1);
			theproduct[30]=0x00;
			theproduct[31]=0x00;
		}else if (strlen(temp)>=5&&strlen(temp)<=6){
			theproduct[28]=stoh(temp,3);
			theproduct[29]=stoh(temp,2);
			theproduct[30]=stoh(temp,1);
			theproduct[31]=0x00;
		}else if (strlen(temp)>=7){
			theproduct[28]=stoh(temp,4);
			theproduct[29]=stoh(temp,3);
			theproduct[30]=stoh(temp,2);
			theproduct[31]=stoh(temp,1);
		}
		snprintf(temp,255, "%x", wfx.nBlockAlign);
		theproduct[32]=stoh(temp,1);//block align
		theproduct[33]=0x00;//block align
		snprintf(temp,255, "%x", wfx.wBitsPerSample);
		theproduct[34]=stoh(temp,1);//bps
		theproduct[35]=0x00;//bps
		//data
		theproduct[36]='d';//data
		theproduct[37]='a';//data
		theproduct[38]='t';//data
		theproduct[39]='a';//data
		snprintf(temp,255, "%x", sizeof(char)*(dlen));//sometimes off by 16  //37631
		#ifdef DEBUG
			printf("Now exporting wave file with attributes:\n");
			printf("file size:%i\n",44+(sizeof(char)*dlen)-8);
			printf("samples per second: %i\n",wfx.nSamplesPerSec);//
			printf("Channels:%i  ||  %i\n",xah.nChannels,wfx.nChannels);//
			printf("Data size: %i\n",sizeof(char)*(dlen));//
			printf("average Bps: %i\n",wfx.nAvgBytesPerSec);//
			printf("average bps: %i\n",wfx.wBitsPerSample);//
			printf("block align: %i\n\n",wfx.nBlockAlign);//
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
			theproduct[44+a]=wad[a];
		}
		//anti pop/click
		for (int a=1;a<80;a++){
			theproduct[44+dlen-a]=0x00;
		}
		if (dlen>20){
			fwrite(theproduct, 1, 44+dlen, fp);
		}
	fclose(fp);
	free(theproduct);
	free(wad);
	free(xad);
	snprintf(soundfile,299, "%s", soundfile2);//remember soundfile is a pointer and screwy.
	return true;
}
#endif
