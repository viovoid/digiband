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
struct song{
	song();
	~song();
	void init( );
	void load(char[256],char[256],char[256]);
	void resetplayed();
	void reload();
	void loadsteps();
	void unloadsteps();
	void loadextended();
	void reloadsong();
	bool loadthepreview();
	void saveextended();
	void randomize();
	char name[256];
	char title[256];
	char artist[256];
    drawtext titlet;
    drawtext artistt;
	char previewwave[256];
	char previewimg[256];
	char background[256];
	char genre[256];
	char cat[256];
	char location[256];
	bool islong;
	//note sounds/activities.
	//#WAV0E: snare_2.xa
	int bassounds;
	char **bassoundfilenum;//0E
	char **bassoundfileloc;//snare_2.xa
	int advsounds;
	char **advsoundfilenum;//0E
	char **advsoundfileloc;//snare_2.xa
	int extsounds;
	char **extsoundfilenum;//0E
	char **extsoundfileloc;//snare_2.xa
	int highestmeasure;
	//avi03: bg.avi
	int basavis;
	char **basavinum;//03
	char **basaviloc;//bg.avi
	int advavis;
	char **advavinum;//03
	char **advaviloc;//bg.avi
	int extavis;
	char **extavinum;//03
	char **extaviloc;//bg.avi
	//#011BD: 0200020002020202
	int basnotes;
	int *basnotemeas;//011
	int *basnotetime;//(1/8)..(3/8)..etc.
	char **basnotetype;//BD
	char **basnotetype2;//BD
	char **basnotesound;//02
	double *basclms;
	int advnotes;
	int *advnotemeas;//011
	int *advnotetime;//(1/8)..(3/8)..etc.
	char **advnotetype;//BD
	char **advnotetype2;//BD
	char **advnotesound;//02
	double *advclms;
	int extnotes;
	int *extnotemeas;//011
	int *extnotetime;//(1/8)..(3/8)..etc.
	char **extnotetype;//BD
	char **extnotetype2;//BD
	char **extnotesound;//02
	double *extclms;
	bool *basnoteplayed;//whether or not it's 'too late'
	bool *advnoteplayed;//whether or not it's 'too late'
	bool *extnoteplayed;//whether or not it's 'too late'
	bool *g1basnoteplayed;//whether or not it's 'too late'
	bool *g1advnoteplayed;//whether or not it's 'too late'
	bool *g1extnoteplayed;//whether or not it's 'too late'
	bool *g2basnoteplayed;//whether or not it's 'too late'
	bool *g2advnoteplayed;//whether or not it's 'too late'
	bool *g2extnoteplayed;//whether or not it's 'too late'
	int bpm;
	int basavgbpm;
	int advavgbpm;
	int extavgbpm;
	int avgbpm;
	int basebpm;
	int origbpm;
	double bpmdiff;
	int drumbasdiff;
	int drumadvdiff;
	int drumextdiff;
	int lowestdrumdiff;
	int guitbasdiff;
	int guitadvdiff; 
	int guitextdiff;
	int lowestguitdiff;
	int guitbbasdiff;
	int guitbadvdiff;
	int guitbextdiff;
	bool drumbastrue;
	bool drumadvtrue;
	bool drumexttrue;
	bool guitbastrue;
	bool guitadvtrue;
	bool guitexttrue;
	bool basgda;
	bool advgda;
	bool extgda;
	//extended attributes
	int offset;
	int poffset;
	int basdrumhs;
	int advdrumhs;
	int extdrumhs;
	int basguitar1hs;
	int advguitar1hs;
	int extguitar1hs;
	int basguitar2hs;
	int advguitar2hs;
	int extguitar2hs;
	int basdrummc;
	int advdrummc;
	int extdrummc;
	int basguitar1mc;
	int advguitar1mc;
	int extguitar1mc;
	int basguitar2mc;
	int advguitar2mc;
	int extguitar2mc;
	bool hasopenpick;
};
