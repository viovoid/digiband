@echo off
SET DEBUG=
SET EXCESSIVE=
SET EXCESSIVELITE=
SET ARCADE=
SET DEBUGDRAWTEXT=
SET DIGIBAND=
SET DEBUGSONGLOAD=
SET OPTIMIZE=
SET NOOSWEGO=
SET CONSOLE=-mwindows
:MAINMENU
cls
echo     Preparing to compile Seijinohki Softs' DigiBand
echo     -----------------------------------------------
echo     Choose which flags to enable
echo     -----------------------------------------------
if "%DEBUG%"=="-DDEBUG -ggdb" (
echo a. +DEBUG
) ELSE (
echo a.  DEBUG
)
if "%EXCESSIVE%"=="-DEXCESSIVE" (
echo b. +EXCESSIVE
) ELSE (
echo b.  EXCESSIVE
)
if "%EXCESSIVELITE%"=="-DEXCESSIVELITE" (
echo c. +EXCESSIVELITE - requires EXCESSIVE
) ELSE (
echo c.  EXCESSIVELITE - requires EXCESSIVE
)
if "%ARCADE%"=="-DARCADE" (
echo d. +ARCADE
) ELSE (
echo d.  ARCADE
)
if "%DEBUGDRAWTEXT%"=="-DDEBUGDRAWTEXT" (
echo e. +DEBUGDRAWTEXT
) ELSE (
echo e.  DEBUGDRAWTEXT
)
if "%DIGIBAND%"=="-DDIGIBAND" (
echo f. +DIGIBAND - Deprecated
) ELSE (
echo f.  DIGIBAND - Deprecated
)
if "%DEBUGSONGLOAD%"=="-DDEBUGSONGLOAD" (
echo g. +DEBUGSONGLOAD
) ELSE (
echo g.  DEBUGSONGLOAD
)
if "%OPTIMIZE%"=="-traditional-cpp -fno-access-control -fexceptions -fverbose-asm -fexpensive-optimizations -march=i386 -O2 -m3dnow" (
echo h. +OPTIMIZE/RELEASE
) ELSE (
echo h.  OPTIMIZE/RELEASE
)
if "%CONSOLE%"=="-D_CONSOLE -D_MBCS" (
echo i. +_CONSOLE/_MBCS - Enable STD out
) ELSE (
echo i.  _CONSOLE/_MBCS - Enable STD out
)
if "%NOOSWEGO%"=="-DNOOSWEGO" (
echo j. +NOOSWEGO - Disable sound system
) ELSE (
echo j.  NOOSWEGO - Disable sound system
)
echo k.  Compile DigiBand Now
echo l.  Do Nothing
SET CHOICE=
echo     -----------------------------------------------
SET /P CHOICE=    Your Option:
if "%CHOICE%"=="a" GOTO SETDEBUG
if "%CHOICE%"=="b" GOTO SETEXCESSIVE
if "%CHOICE%"=="c" GOTO SETEXCESSIVELITE
if "%CHOICE%"=="d" GOTO SETARCADE
if "%CHOICE%"=="e" GOTO SETDEBUGDRAWTEXT
if "%CHOICE%"=="f" GOTO SETDIGIBAND
if "%CHOICE%"=="g" GOTO SETDEBUGSONGLOAD
if "%CHOICE%"=="h" GOTO SETOPTIMIZE
if "%CHOICE%"=="i" GOTO SETCONSOLE
if "%CHOICE%"=="j" GOTO SETNOOSWEGO
if "%CHOICE%"=="k" GOTO COMPILE
if "%CHOICE%"=="l" GOTO QUIT
GOTO MAINMENU


:SETDEBUG
if "%DEBUG%"=="-DDEBUG -ggdb" (
SET DEBUG=
) ELSE (
SET DEBUG=-DDEBUG -ggdb
)
GOTO MAINMENU


:SETEXCESSIVE
if "%EXCESSIVE%"=="-DEXCESSIVE" (
SET EXCESSIVE=
) ELSE (
SET EXCESSIVE=-DEXCESSIVE
)
GOTO MAINMENU


:SETEXCESSIVELITE
if "%EXCESSIVELITE%"=="-DEXCESSIVELITE" (
SET EXCESSIVELITE=
) ELSE (
SET EXCESSIVELITE=-DEXCESSIVELITE
)
GOTO MAINMENU


:SETARCADE
if "%ARCADE%"=="-DARCADE" (
SET ARCADE=
) ELSE (
SET ARCADE=-DARCADE
)
GOTO MAINMENU


:SETDEBUGDRAWTEXT
if "%DEBUGDRAWTEXT%"=="-DDEBUGDRAWTEXT" (
SET DEBUGDRAWTEXT=
) ELSE (
SET DEBUGDRAWTEXT=-DDEBUGDRAWTEXT
)
GOTO MAINMENU


:SETDIGIBAND
if "%DIGIBAND%"=="-DDIGIBAND" (
SET DIGIBAND=
) ELSE (
SET DIGIBAND=-DDIGIBAND
)
GOTO MAINMENU


:SETDEBUGSONGLOAD
if "%DEBUGSONGLOAD%"=="-DDEBUGSONGLOAD" (
SET DEBUGSONGLOAD=
) ELSE (
SET DEBUGSONGLOAD=-DDEBUGSONGLOAD
)
GOTO MAINMENU


:SETCONSOLE
if "%CONSOLE%"=="-D_CONSOLE -D_MBCS" (
SET CONSOLE=-mwindows
) ELSE (
SET CONSOLE=-D_CONSOLE -D_MBCS
)
GOTO MAINMENU


:SETOPTIMIZE
if "%OPTIMIZE%"=="-traditional-cpp -fno-access-control -fexceptions -fverbose-asm -fexpensive-optimizations -march=i386 -O2 -m3dnow" (
SET OPTIMIZE=
) ELSE (
SET OPTIMIZE=-traditional-cpp -fno-access-control -fexceptions -fverbose-asm -fexpensive-optimizations -march=i386 -O2 -m3dnow
)
GOTO MAINMENU


:SETNOOSWEGO
if "%NOOSWEGO%"=="-DNOOSWEGO" (
SET NOOSWEGO=
) ELSE (
SET NOOSWEGO=-DNOOSWEGO
)
GOTO MAINMENU


:COMPILE
echo Now Compiling...
windres.exe -i DigiBand_private.rc --input-format=rc -o DigiBand_private.res -O coff 
g++ DigiBand.cpp DigiBand_private.res -Wno-deprecated %NOOSWEGO% %DEBUG% %ARCADE% %DEBUGDRAWTEXT% %DIGIBAND% %CONSOLE% %EXCESSIVE% %EXCESSIVELITE% %DEBUGSONGLOAD% -Dmain=SDL_main -Wno-deprecated -IC:\MinGW\include\freetype2 -IC:\MinGW\include -lmingw32 -lSDLmain -lSDL -lSDL_image -lopenGL32 -lGLU32 -lgdi32  -liconv -lwinmm -lfreetype -lxadec -lavformat -lavcodec -lavutil -lOpenAL32 -logg -lvorbisfile -lmad -lsndfile -lpthread -o../DigiBand.exe %OPTIMIZE%
echo Done
pause
:QUIT