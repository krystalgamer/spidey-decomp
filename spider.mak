# Microsoft Developer Studio Generated NMAKE File, Based on spider.dsp
!IF "$(CFG)" == ""
CFG=spider - Win32 Debug
!MESSAGE No configuration specified. Defaulting to spider - Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "spider - Win32 Release" && "$(CFG)" != "spider - Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "spider.mak" CFG="spider - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "spider - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "spider - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

!IF "$(OS)" == "Windows_NT"
NULL=
!ELSE 
NULL=nul
!ENDIF 

!IF  "$(CFG)" == "spider - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\spider.exe"


CLEAN :
	-@erase "$(INTDIR)\baddy.obj"
	-@erase "$(INTDIR)\bit.obj"
	-@erase "$(INTDIR)\blackcat.obj"
	-@erase "$(INTDIR)\carnage.obj"
	-@erase "$(INTDIR)\chopper.obj"
	-@erase "$(INTDIR)\cop.obj"
	-@erase "$(INTDIR)\docock.obj"
	-@erase "$(INTDIR)\friction.obj"
	-@erase "$(INTDIR)\front.obj"
	-@erase "$(INTDIR)\hostage.obj"
	-@erase "$(INTDIR)\jonah.obj"
	-@erase "$(INTDIR)\lizard.obj"
	-@erase "$(INTDIR)\lizman.obj"
	-@erase "$(INTDIR)\m3d.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\mj.obj"
	-@erase "$(INTDIR)\mysterio.obj"
	-@erase "$(INTDIR)\ob.obj"
	-@erase "$(INTDIR)\platform.obj"
	-@erase "$(INTDIR)\ps2funcs.obj"
	-@erase "$(INTDIR)\ps2m3d.obj"
	-@erase "$(INTDIR)\pshell.obj"
	-@erase "$(INTDIR)\rhino.obj"
	-@erase "$(INTDIR)\scorpion.obj"
	-@erase "$(INTDIR)\shell.obj"
	-@erase "$(INTDIR)\simby.obj"
	-@erase "$(INTDIR)\spclone.obj"
	-@erase "$(INTDIR)\submarin.obj"
	-@erase "$(INTDIR)\superock.obj"
	-@erase "$(INTDIR)\thug.obj"
	-@erase "$(INTDIR)\torch.obj"
	-@erase "$(INTDIR)\turret.obj"
	-@erase "$(INTDIR)\utils.obj"
	-@erase "$(INTDIR)\validate.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vector.obj"
	-@erase "$(INTDIR)\venom.obj"
	-@erase "$(INTDIR)\web.obj"
	-@erase "$(OUTDIR)\spider.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /Op /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\spider.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\spider.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\spider.pdb" /machine:I386 /out:"$(OUTDIR)\spider.exe" 
LINK32_OBJS= \
	"$(INTDIR)\baddy.obj" \
	"$(INTDIR)\bit.obj" \
	"$(INTDIR)\blackcat.obj" \
	"$(INTDIR)\carnage.obj" \
	"$(INTDIR)\chopper.obj" \
	"$(INTDIR)\cop.obj" \
	"$(INTDIR)\docock.obj" \
	"$(INTDIR)\friction.obj" \
	"$(INTDIR)\front.obj" \
	"$(INTDIR)\hostage.obj" \
	"$(INTDIR)\jonah.obj" \
	"$(INTDIR)\lizard.obj" \
	"$(INTDIR)\lizman.obj" \
	"$(INTDIR)\m3d.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\mj.obj" \
	"$(INTDIR)\mysterio.obj" \
	"$(INTDIR)\ob.obj" \
	"$(INTDIR)\platform.obj" \
	"$(INTDIR)\ps2funcs.obj" \
	"$(INTDIR)\ps2m3d.obj" \
	"$(INTDIR)\pshell.obj" \
	"$(INTDIR)\rhino.obj" \
	"$(INTDIR)\scorpion.obj" \
	"$(INTDIR)\shell.obj" \
	"$(INTDIR)\simby.obj" \
	"$(INTDIR)\spclone.obj" \
	"$(INTDIR)\submarin.obj" \
	"$(INTDIR)\superock.obj" \
	"$(INTDIR)\thug.obj" \
	"$(INTDIR)\torch.obj" \
	"$(INTDIR)\turret.obj" \
	"$(INTDIR)\utils.obj" \
	"$(INTDIR)\validate.obj" \
	"$(INTDIR)\vector.obj" \
	"$(INTDIR)\venom.obj" \
	"$(INTDIR)\web.obj"

"$(OUTDIR)\spider.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "spider - Win32 Debug"

OUTDIR=.\Debug
INTDIR=.\Debug
# Begin Custom Macros
OutDir=.\Debug
# End Custom Macros

ALL : "$(OUTDIR)\spider.exe"


CLEAN :
	-@erase "$(INTDIR)\baddy.obj"
	-@erase "$(INTDIR)\bit.obj"
	-@erase "$(INTDIR)\blackcat.obj"
	-@erase "$(INTDIR)\carnage.obj"
	-@erase "$(INTDIR)\chopper.obj"
	-@erase "$(INTDIR)\cop.obj"
	-@erase "$(INTDIR)\docock.obj"
	-@erase "$(INTDIR)\friction.obj"
	-@erase "$(INTDIR)\front.obj"
	-@erase "$(INTDIR)\hostage.obj"
	-@erase "$(INTDIR)\jonah.obj"
	-@erase "$(INTDIR)\lizard.obj"
	-@erase "$(INTDIR)\lizman.obj"
	-@erase "$(INTDIR)\m3d.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\mj.obj"
	-@erase "$(INTDIR)\mysterio.obj"
	-@erase "$(INTDIR)\ob.obj"
	-@erase "$(INTDIR)\platform.obj"
	-@erase "$(INTDIR)\ps2funcs.obj"
	-@erase "$(INTDIR)\ps2m3d.obj"
	-@erase "$(INTDIR)\pshell.obj"
	-@erase "$(INTDIR)\rhino.obj"
	-@erase "$(INTDIR)\scorpion.obj"
	-@erase "$(INTDIR)\shell.obj"
	-@erase "$(INTDIR)\simby.obj"
	-@erase "$(INTDIR)\spclone.obj"
	-@erase "$(INTDIR)\submarin.obj"
	-@erase "$(INTDIR)\superock.obj"
	-@erase "$(INTDIR)\thug.obj"
	-@erase "$(INTDIR)\torch.obj"
	-@erase "$(INTDIR)\turret.obj"
	-@erase "$(INTDIR)\utils.obj"
	-@erase "$(INTDIR)\validate.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vector.obj"
	-@erase "$(INTDIR)\venom.obj"
	-@erase "$(INTDIR)\web.obj"
	-@erase "$(OUTDIR)\spider.exe"
	-@erase "$(OUTDIR)\spider.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP=cl.exe
CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\spider.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 

.c{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.obj::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.c{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cpp{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

.cxx{$(INTDIR)}.sbr::
   $(CPP) @<<
   $(CPP_PROJ) $< 
<<

MTL=midl.exe
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
RSC=rc.exe
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\spider.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\spider.pdb" /debug /machine:I386 /out:"$(OUTDIR)\spider.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\baddy.obj" \
	"$(INTDIR)\bit.obj" \
	"$(INTDIR)\blackcat.obj" \
	"$(INTDIR)\carnage.obj" \
	"$(INTDIR)\chopper.obj" \
	"$(INTDIR)\cop.obj" \
	"$(INTDIR)\docock.obj" \
	"$(INTDIR)\friction.obj" \
	"$(INTDIR)\front.obj" \
	"$(INTDIR)\hostage.obj" \
	"$(INTDIR)\jonah.obj" \
	"$(INTDIR)\lizard.obj" \
	"$(INTDIR)\lizman.obj" \
	"$(INTDIR)\m3d.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\mj.obj" \
	"$(INTDIR)\mysterio.obj" \
	"$(INTDIR)\ob.obj" \
	"$(INTDIR)\platform.obj" \
	"$(INTDIR)\ps2funcs.obj" \
	"$(INTDIR)\ps2m3d.obj" \
	"$(INTDIR)\pshell.obj" \
	"$(INTDIR)\rhino.obj" \
	"$(INTDIR)\scorpion.obj" \
	"$(INTDIR)\shell.obj" \
	"$(INTDIR)\simby.obj" \
	"$(INTDIR)\spclone.obj" \
	"$(INTDIR)\submarin.obj" \
	"$(INTDIR)\superock.obj" \
	"$(INTDIR)\thug.obj" \
	"$(INTDIR)\torch.obj" \
	"$(INTDIR)\turret.obj" \
	"$(INTDIR)\utils.obj" \
	"$(INTDIR)\validate.obj" \
	"$(INTDIR)\vector.obj" \
	"$(INTDIR)\venom.obj" \
	"$(INTDIR)\web.obj"

"$(OUTDIR)\spider.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("spider.dep")
!INCLUDE "spider.dep"
!ELSE 
!MESSAGE Warning: cannot find "spider.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "spider - Win32 Release" || "$(CFG)" == "spider - Win32 Debug"
SOURCE=.\baddy.cpp

"$(INTDIR)\baddy.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\bit.cpp

"$(INTDIR)\bit.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\blackcat.cpp

"$(INTDIR)\blackcat.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\carnage.cpp

"$(INTDIR)\carnage.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\chopper.cpp

"$(INTDIR)\chopper.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\cop.cpp

"$(INTDIR)\cop.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\docock.cpp

"$(INTDIR)\docock.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\friction.cpp

"$(INTDIR)\friction.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\front.cpp

"$(INTDIR)\front.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\hostage.cpp

"$(INTDIR)\hostage.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jonah.cpp

"$(INTDIR)\jonah.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\lizard.cpp

"$(INTDIR)\lizard.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\lizman.cpp

"$(INTDIR)\lizman.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\m3d.cpp

"$(INTDIR)\m3d.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\main.cpp

"$(INTDIR)\main.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\mem.cpp

"$(INTDIR)\mem.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\mj.cpp

"$(INTDIR)\mj.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\mysterio.cpp

"$(INTDIR)\mysterio.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ob.cpp

"$(INTDIR)\ob.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\platform.cpp

"$(INTDIR)\platform.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ps2funcs.cpp

"$(INTDIR)\ps2funcs.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ps2m3d.cpp

"$(INTDIR)\ps2m3d.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\pshell.cpp

"$(INTDIR)\pshell.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\rhino.cpp

"$(INTDIR)\rhino.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\scorpion.cpp

"$(INTDIR)\scorpion.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\shell.cpp

"$(INTDIR)\shell.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\simby.cpp

"$(INTDIR)\simby.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\spclone.cpp

"$(INTDIR)\spclone.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\submarin.cpp

"$(INTDIR)\submarin.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\superock.cpp

"$(INTDIR)\superock.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\thug.cpp

"$(INTDIR)\thug.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\torch.cpp

"$(INTDIR)\torch.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\turret.cpp

"$(INTDIR)\turret.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\utils.cpp

"$(INTDIR)\utils.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\validate.cpp

"$(INTDIR)\validate.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\vector.cpp

"$(INTDIR)\vector.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\venom.cpp

"$(INTDIR)\venom.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\web.cpp

"$(INTDIR)\web.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

