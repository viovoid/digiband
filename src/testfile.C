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
bool testfile(char marmot[256]){
#ifdef DEBUG
printf("testing file: %s\n", marmot);
#endif
	bool isgood=true;
	struct stat filestat;
	if(stat(marmot,&filestat)!=0){
		if (errno==ENOENT){
			isgood=false;
		}
		#ifdef DEBUG
		if (errno==ENOTDIR){
			printf("ENOTDIR: A component of the path prefix is not a directory.\n");
		}
		if (errno==ENAMETOOLONG){
			printf("ENAMETOOLONG: A component of a pathname exceeded {NAME_MAX} charac-ters, or an entire path name exceeded {PATH_MAX} char-acters.\n");
		}
		if (errno==ENOENT){
			printf("ENOENT: The named file does not exist.\n");
		}
		if (errno==EACCES){
			printf("EACCES: Search permission is denied for a component of the path prefix.\n");
		}
		if (errno==EFAULT){
			printf("EFAULT: Sb or name points to an invalid address.\n");
		}
		if (errno==EIO){
            printf("EIO: An I/O error occurred while reading from or writing to the file system.\n");
            appisrunning=false;
            isgood=false;
		}
		#endif
	}
	return isgood;
}

bool testxa(char marmot[1024]){
	bool isgood=false;
	ifstream testfile;
    while(fstreampotty>0){}
    fstreampotty++;
	testfile.open(marmot,ifstream::in);
	fstreampotty--;
	if (testfile.good()){
		char magic[5];
		testfile.read(magic,4);
		magic[4]='\0';
		if (strcmp(magic,"KWD1")==0){
			isgood=true;
		}
	}
	testfile.close();
	return isgood;
}
