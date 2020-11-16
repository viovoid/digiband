# Project: DigiBand
# Makefile created by Joe Wall and Velex Loutzenhiser
# Extra optional CXXFLAGS: -DDEBUGSONGLOAD -DDEBUG -DEXCESSIVE -DSHOWWAVES -DDEBUGDRAWTEXT
CPP  = g++
CC   = gcc
LDFLAGS :=  `sdl-config --libs` -lSDL_image -lSDL -lGL -lGLU -lopenal `pkg-config --libs vorbisfile` `pkg-config --libs sndfile` -lmad -L../usr/lib -lavformat -lavutil -lavcodec -lfreetype -lopenal -pthread
CXXFLAGS := `pkg-config freetype2 --cflags` `sdl-config --cflags` `pkg-config --cflags sndfile` `pkg-config --cflags libavformat` -I../usr/include -DLINUX -Wno-deprecated -Wno-write-strings -Wno-narrowing -O2 -fverbose-asm -Wno-deprecated
#append to prev line -DDEBUG -DEXCESSIVE -g
RM = rm -f
OBJ = DigiBand.o codec.o madcodec.o sndfilecodec.o stream.o vorbisfilecodec.o alsubsys.o

.PHONY: all all-before all-after clean clean-custom

all: DigiBand

clean: clean-custom
	${RM} $(OBJ) $(BIN)

DigiBand: $(OBJ)
	$(CPP) $(LDFLAGS) $^ -o $@
