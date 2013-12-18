#ifndef STOI
#define STOI

#ifndef LINUX
char *strlwr(char *marmot);
#endif

double absv(double marmot);
uint8_t stoh(char input[256],int value);
char *btos(bool marmot);
void deadspace(char moo[256],int start,char cow[256]);
void truncatet(char moo[256],char cow[256]);
void charlim(char marmot[256],int limit,char taco[256]);
void ftos(double marmot,char taco[256]);
long stoi(char marmot[256]);
int dbstoi(char marmot[256]);
int dbstof5f(char marmot[256]);
double dbstof(char marmot[256]);
void itos(int marmot,char taco[256]);
double dbstod(char marmot[256]);
void dollarize(char input[256],char output[256]);
int wavetoi(char temp[256]);
int hextoi(char moo);
int hextoi2(char moo[10]);
long alphatoi(char moo[10]);
char *keytochar(int key);


#endif
