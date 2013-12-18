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
const char VERSION[128]="1.0.1";

FT_Library ftlibrary;

#ifdef VISUALSTUDIO
const double M_PI=3.1415926535897932384626433832795;
#endif
const int numoftexs=74;
double texani[numoftexs][4];//frames,timing,currframe,currtime;
char texstoload[numoftexs][256];
unsigned int g_Texture[100][100];
int offset=0;
int goffset=0;
int g2offset=0;
//threads and locking.
SDL_Thread *thread;
int fstreampotty=0;
//misc
char textureframe[128];
int tvscale=0;
double frameholder;
bool sdlloaded=false;

//Song selection Screen
bool ratioadjust=true;
bool freeplaymode=false;

//vsync & refresh rate
bool verticlesync=true;
typedef void (APIENTRY *PFNWGLEXTSWAPCONTROLPROC) (int);
typedef int (*PFNWGLEXTGETSWAPINTERVALPROC) (void);
PFNWGLEXTSWAPCONTROLPROC wglSwapIntervalEXT = NULL;
PFNWGLEXTGETSWAPINTERVALPROC wglGetSwapIntervalEXT = NULL;
int refreshrate=60;
int currtime=0;
int lasttime=0;
int steptime=0;

//explosion animations
bool d1exp=false;
bool d2exp=false;
bool d3exp=false;
bool d4exp=false;
bool d5exp=false;
bool d6exp=false;
bool g11exp=false;
bool g12exp=false;
bool g13exp=false;
bool g21exp=false;
bool g22exp=false;
bool g23exp=false;
double d1expt=0;
double d2expt=0;
double d3expt=0;
double d4expt=0;
double d5expt=0;
double d6expt=0;
double g11expt=0;
double g12expt=0;
double g13expt=0;
double g21expt=0;
double g22expt=0;
double g23expt=0;
int d1expc=0;
int d2expc=0;
int d3expc=0;
int d4expc=0;
int d5expc=0;
int d6expc=0;
int g11expc=0;
int g12expc=0;
int g13expc=0;
int g21expc=0;
int g22expc=0;
int g23expc=0;
//songs
char **cursonglist=NULL;
bool forcepaoff=false;
int sssloptionselected=0;
int *cursongcat=NULL;
int *cursongnum=NULL;
int cursongcount=0;
char **curcatlist=NULL;
drawtext songtext[11];
int *curcatsongcount=NULL;
int curcatcount=0;
int gbcatcount=0;
int catselected=0;
int gbsongcount=0;
char **catlist=NULL;
int *catsongs=NULL;
song *songs;
int songsloaded=0;
static int songselected=-1;
static int prevsongselected=-1;
const int LISTMODES=5;
int listmode=1;
int prevlistmode=0;
int thesong=-1;
int presong=-1;
bool firstboot=true;
#ifndef NOOSWEGO
AL::Stream waves[1554];
AL::Stream bgmmp3;
#endif

//screen control vars.
int nextscreen=1;
int currscreen=1;
int prevscreen=0;
int lastscreen=1;
bool isloading=true;
bool appisrunning=true;
bool screenfaddingout=false;
double screenfaddingouttime=0.0;
bool screenfaddingin=true;
double screenfaddingintime=255.0;
bool screenchangenow=false;
unsigned int previewtexture=0;
unsigned int tempbackgroundtexture=0;
unsigned int backgroundtexture=0;

//ui controls
bool optionsscreenloaded=false;
bool suboptionselection=false;
int suboptionselected=0;
int optionselected=0;
int ssoptionselected=0;
bool upanimation=false;
bool downanimation=false;

//settings vars.
themeini uivars;
bool drumfullscreen=true;
bool displaysakura=true;
bool widemode=false;
int NOS=100;
int resx=800;
int resy=600;
int drumbpp=32;
char theme[256]="Default";
char noteskin[256]="Default";
bool origfullscreen=true;
int origresx=640;
int origresy=480;
int origbpp=32;
char origtheme[256]="Default";
char orignoteskin[256]="Default";
char themes[100][256];
char noteskins[100][256];
int themenumber=1;
int themecount=1;
int noteskinnumber=1;
int noteskincount=1;	
int hihatkey=122;  //controls.
int snarekey=120;
int basskey=99;
int hitomkey=118;
int lotomkey=98;
int cymbalkey=110;
int backkey=27;
int startkey=13;
int althihatkey=97;  //controls.
int altsnarekey=115;
int altbasskey=100;
int althitomkey=102;
int altlotomkey=103;
int altcymbalkey=104;

int guitar1r=113;
int guitar1g=119;
int guitar1b=101;
int guitar1w=304;
int guitar1p=32;
int guitar1a=32;
int guitar1back=50;
int guitar1start=49;
int guitar2r=117;
int guitar2g=105;
int guitar2b=111;
int guitar2w=57;
int guitar2p=112;
int guitar2a=112;

int guitar2back=56;
int guitar2start=55;
bool debugstats=false;
bool autocymbal=false;
bool autobass=false;
bool autohihat=false;
bool autoall=false;
int notespeed=10;
int lifedifficulty=3;
int voldrum=10;
int volguit=10;
int volbass=10;
int volbgm=7;
int stages=3;
bool stagefail=true;
bool gameover=false;
int currstage=1;
gamesettings settings;
int REINIT=0;

//audio system
static Uint32 decoded_bytes = 0;
static Uint8 *decoded_ptr = NULL;
int audio_rate = 44100;
Uint16 audio_format = AUDIO_S16; /* 16-bit stereo */
int audio_channels = 2;
int audio_buffers = 2048;
bool favordtx=true;
int notesoundoffset=0;
int entiresongoffset=0;
double holdtime=0;

//grading difficulty:
const int almostlv=25000;
const int goodlv=20000;
const int greatlv=10000;
const int perfectlv=5000;
const double pldiff=.6;
const double gldiff=.3;


//game modes
bool drummode=false;
bool guitar1mode=false;
bool guitar2mode=false;
bool okaytoload=false;
bool okaytodraw=false;
bool jukeboxmode=false;
bool newsong=false;
int lastsongloaded=-1;
int currsongloaded=-1;
double beenidle=0;
int drumnotespeed=10;
int guitar1notespeed=10;
int guitar2notespeed=10;
int drumdiff=-1;
int guit1diff=-1;
int guit2diff=-1;
bool guitar1treb=true;
bool guitar2treb=true;
long int songposition=0;
long int songpositiondraw=0;
long int timestamp=0;
int currbpm=0;
double notebpm=0;
double currclm=1.0;

//code timing
double codetime=0;
double codetime2=0;

//note animation & timing
int hihatani=1;
int snareani=1;
int bassani=1;
int hitomani=1;
int lotomani=1;
int cymbalani=1;
int hihatts=0;
int snarets=0;
int bassts=0;
int hitomts=0;
int lotomts=0;
int cymbalts=0;
int phihatts=0;
int psnarets=0;
int pbassts=0;
int phitomts=0;
int plotomts=0;
int pcymbalts=0;
int g1bts=0;
int g1gts=0;
int g1gbts=0;
int g1rts=0;
int g1rbts=0;
int g1rgts=0;
int g1rgbts=0;
int g1wts=0;
int g1ots=0;
int g2bts=0;
int g2gts=0;
int g2gbts=0;
int g2rts=0;
int g2rbts=0;
int g2rgts=0;
int g2rgbts=0;
int g2wts=0;
int g2ots=0;

//stats
char dmscorenames[10][256];
char gscorenames[10][256];
long dmscores[10];
long gscores[10];
char dminitials[5];
char g1initials[5];
char g2initials[5];
int dmpos=0;
int g1pos=0;
int g2pos=0;
int dmrank=11;
int g1rank=11;
int g2rank=11;
bool dmhs=false;
bool g1hs=false;
bool g2hs=false;
int dmoptionselected=0;
int g1optionselected=0;
int g2optionselected=0;


int gpmiss=0;
int gpalmost=0;
int gpgood=0;
int gpgreat=0;
int gpperfect=0;
int gpmaxcombo=0;
int gpcurrcombo=0;
int gpscore=0;
int gptscore=0;
double gplifebar=50;
int gpg1miss=0;
int gpg1almost=0;
int gpg1good=0;
int gpg1great=0;
int gpg1perfect=0;
int gpg1maxcombo=0;
int gpg1currcombo=0;
int gpg1score=0;
int gpg1tscore=0;
double gpg1lifebar=50;
int gpg2miss=0;
int gpg2almost=0;
int gpg2good=0;
int gpg2great=0;
int gpg2perfect=0;
int gpg2maxcombo=0;
int gpg2currcombo=0;
int gpg2score=0;
int gpg2tscore=0;
double gpg2lifebar=50;
//grades.
char gphhgrade[25];
char gpsdgrade[25];
char gpbdgrade[25];
char gphtgrade[25];
char gpltgrade[25];
char gpcygrade[25];
double gphhgradetime;
double gpsdgradetime;
double gpbdgradetime;
double gphtgradetime;
double gpltgradetime;
double gpcygradetime;
char gpg1ograde[25];
char gpg1rgrade[25];
char gpg1ggrade[25];
char gpg1bgrade[25];
char gpg1wgrade[25];
char gpg2ograde[25];
char gpg2rgrade[25];
char gpg2ggrade[25];
char gpg2bgrade[25];
char gpg2wgrade[25];
double gpg1ogradetime;
double gpg1rgradetime;
double gpg1ggradetime;
double gpg1bgradetime;
double gpg1wgradetime;
double gpg2ogradetime;
double gpg2rgradetime;
double gpg2ggradetime;
double gpg2bgradetime;
double gpg2wgradetime;
//others
bool g1pp=false;
bool g1rp=false;
bool g1gp=false;
bool g1bp=false;
bool g1wp=false;
bool g2pp=false;
bool g2rp=false;
bool g2gp=false;
bool g2bp=false;
bool g2wp=false;
int catchangewait=0;
double g1ra=0;
double g1ga=0;
double g1ba=0;
double g1wa=0;
double g2ra=0;
double g2ga=0;
double g2ba=0;
double g2wa=0;

//AVI Data stuff:
char curravi[256];
int avires=256;
avisys bgavi;
avisys gpavi;
int openedavis;
bool hasavi[99];
bool checked[99];

#ifndef LINUX
//MIDI stuff
HMIDIIN inHandle;
DWORD midiInputEvt = 0;
bool midicapable=true;
#endif

//offbeat stuff
bool hihatpressed=false;
bool snarepressed=false;
bool hitompressed=false;
bool lotompressed=false;
bool cymbalpressed=false;
bool basspressed=false;
int lastsnare=0;
int lastbass=0;
int lasthihat=0;
int lasthitom=0;
int lastlotom=0;
int lastcymbal=0;

//modifiers;
int drumfademode=0;
bool drumrandommode=false;
bool drumspin=false;
int guit1fademode=0;
bool guit1randommode=false;
bool guit1spin=false;
int guit2fademode=0;
bool guit2randommode=false;
bool guit2spin=false;

//arcade options
bool arcademode=false;
int coinsperplay=3;
int coinsinserted=0;
int credits=0;
int menucountertime=50;
int coinkey=302;
int opskey=19;
//mmm sexy textures
#define GL_TEXTURE_MAX_ANISOTROPY_EXT 0x84FE
#define GL_MAX_TEXTURE_MAX_ANISOTROPY_EXT 0x84FF
bool allowanisotropic=true;
float maxanisotropy=1.0f;
//alowed anisotropy:
bool allowaf=true;
int afamount=4;

bool forcewide=false;
