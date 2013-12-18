# Project: DigiBand
# Makefile created by Dev-C++ 4.9.9.2

CPP  = g++.exe
CC   = gcc.exe
WINDRES = windres.exe
RES  = DigiBand_private.res
OBJ  = DigiBand.o $(RES)
LINKOBJ  = DigiBand.o $(RES)
LIBS =  -L"C:/MinGW/lib" -lgdi32 -lmingw32 -lwinmm -lvfw32 -lSDL_image -lSDLmain -lSDL_ttf -lSDL -lxadec -lSDL_mixer -lopenGL32 -lGLU32 -lavformat -lavcodec -lavutil -liconv -mwindows  
INCS =  -I"C:/MinGW/include" 
CXXINCS =  -I"C:/MinGW/include" 
BIN  = DigiBand.exe
CXXFLAGS = $(CXXINCS)   DigiBand.cpp -DDEBUG -D_CONSOLE -D_MBCS -Dmain=SDL_main -Wno-deprecated  -g -O2 -oDigiBand.exe -fverbose-asm
RM = rm -f

.PHONY: all all-before all-after clean clean-custom

all: all-before DigiBand.exe all-after


clean: clean-custom
	${RM} $(OBJ) $(BIN)

$(BIN): $(OBJ)
	$(CPP) $(LINKOBJ) -o "DigiBand.exe" $(LIBS)

DigiBand.o: DigiBand.cpp
	$(CPP) -c DigiBand.cpp -o DigiBand.o $(CXXFLAGS)

DigiBand_private.res: DigiBand_private.rc 
	$(WINDRES) -i DigiBand_private.rc --input-format=rc -o DigiBand_private.res -O coff 
