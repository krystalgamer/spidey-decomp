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

CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "spider - Win32 Release"

OUTDIR=.\Release
INTDIR=.\Release
# Begin Custom Macros
OutDir=.\Release
# End Custom Macros

ALL : "$(OUTDIR)\spider.exe"


CLEAN :
	-@erase "$(INTDIR)\ai.obj"
	-@erase "$(INTDIR)\algebra.obj"
	-@erase "$(INTDIR)\backgrnd.obj"
	-@erase "$(INTDIR)\baddy.obj"
	-@erase "$(INTDIR)\bit.obj"
	-@erase "$(INTDIR)\bit2.obj"
	-@erase "$(INTDIR)\bitmap256.obj"
	-@erase "$(INTDIR)\blackcat.obj"
	-@erase "$(INTDIR)\bmr.obj"
	-@erase "$(INTDIR)\bullet.obj"
	-@erase "$(INTDIR)\camera.obj"
	-@erase "$(INTDIR)\carnage.obj"
	-@erase "$(INTDIR)\chain.obj"
	-@erase "$(INTDIR)\chopper.obj"
	-@erase "$(INTDIR)\chunk.obj"
	-@erase "$(INTDIR)\cinema.obj"
	-@erase "$(INTDIR)\cop.obj"
	-@erase "$(INTDIR)\crate.obj"
	-@erase "$(INTDIR)\db.obj"
	-@erase "$(INTDIR)\dcfileio.obj"
	-@erase "$(INTDIR)\dcmemcard.obj"
	-@erase "$(INTDIR)\dcmodel.obj"
	-@erase "$(INTDIR)\dcshellutils.obj"
	-@erase "$(INTDIR)\decomp.obj"
	-@erase "$(INTDIR)\docock.obj"
	-@erase "$(INTDIR)\DXinit.obj"
	-@erase "$(INTDIR)\DXsound.obj"
	-@erase "$(INTDIR)\effects.obj"
	-@erase "$(INTDIR)\exp.obj"
	-@erase "$(INTDIR)\flash.obj"
	-@erase "$(INTDIR)\FontTools.obj"
	-@erase "$(INTDIR)\friction.obj"
	-@erase "$(INTDIR)\front.obj"
	-@erase "$(INTDIR)\hostage.obj"
	-@erase "$(INTDIR)\Image.obj"
	-@erase "$(INTDIR)\init.obj"
	-@erase "$(INTDIR)\jonah.obj"
	-@erase "$(INTDIR)\l1a3bomb.obj"
	-@erase "$(INTDIR)\l2a1lsc.obj"
	-@erase "$(INTDIR)\l5a5lsc.obj"
	-@erase "$(INTDIR)\l5a6lsc.obj"
	-@erase "$(INTDIR)\l5a7lsc.obj"
	-@erase "$(INTDIR)\l6a1lsc.obj"
	-@erase "$(INTDIR)\l6a2lsc.obj"
	-@erase "$(INTDIR)\l6a3lsc.obj"
	-@erase "$(INTDIR)\lizard.obj"
	-@erase "$(INTDIR)\lizman.obj"
	-@erase "$(INTDIR)\localtxt.obj"
	-@erase "$(INTDIR)\LThread.obj"
	-@erase "$(INTDIR)\m3d.obj"
	-@erase "$(INTDIR)\m3dcolij.obj"
	-@erase "$(INTDIR)\m3dinit.obj"
	-@erase "$(INTDIR)\m3dutils.obj"
	-@erase "$(INTDIR)\m3dzone.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\manipob.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\mess.obj"
	-@erase "$(INTDIR)\message.obj"
	-@erase "$(INTDIR)\mj.obj"
	-@erase "$(INTDIR)\music.obj"
	-@erase "$(INTDIR)\my_bink.obj"
	-@erase "$(INTDIR)\my_debug.obj"
	-@erase "$(INTDIR)\mysterio.obj"
	-@erase "$(INTDIR)\ob.obj"
	-@erase "$(INTDIR)\pack.obj"
	-@erase "$(INTDIR)\pal.obj"
	-@erase "$(INTDIR)\panel.obj"
	-@erase "$(INTDIR)\pcdcBkup.obj"
	-@erase "$(INTDIR)\pcdcFile.obj"
	-@erase "$(INTDIR)\pcdcMem.obj"
	-@erase "$(INTDIR)\pcdcPad.obj"
	-@erase "$(INTDIR)\PCGfx.obj"
	-@erase "$(INTDIR)\PCInput.obj"
	-@erase "$(INTDIR)\PCMovie.obj"
	-@erase "$(INTDIR)\PCMusic.obj"
	-@erase "$(INTDIR)\PCShell.obj"
	-@erase "$(INTDIR)\PCTex.obj"
	-@erase "$(INTDIR)\PCTimer.obj"
	-@erase "$(INTDIR)\physics.obj"
	-@erase "$(INTDIR)\pkr.obj"
	-@erase "$(INTDIR)\platform.obj"
	-@erase "$(INTDIR)\post.obj"
	-@erase "$(INTDIR)\powerup.obj"
	-@erase "$(INTDIR)\PRE.obj"
	-@erase "$(INTDIR)\ps2card.obj"
	-@erase "$(INTDIR)\ps2funcs.obj"
	-@erase "$(INTDIR)\ps2gamefmv.obj"
	-@erase "$(INTDIR)\ps2lowsfx.obj"
	-@erase "$(INTDIR)\ps2m3d.obj"
	-@erase "$(INTDIR)\ps2pad.obj"
	-@erase "$(INTDIR)\ps2redbook.obj"
	-@erase "$(INTDIR)\pshell.obj"
	-@erase "$(INTDIR)\quat.obj"
	-@erase "$(INTDIR)\reloc.obj"
	-@erase "$(INTDIR)\reloc_g.obj"
	-@erase "$(INTDIR)\rfront.obj"
	-@erase "$(INTDIR)\rhino.obj"
	-@erase "$(INTDIR)\Sbinit.obj"
	-@erase "$(INTDIR)\scorpion.obj"
	-@erase "$(INTDIR)\screen.obj"
	-@erase "$(INTDIR)\shatter.obj"
	-@erase "$(INTDIR)\shell.obj"
	-@erase "$(INTDIR)\simby.obj"
	-@erase "$(INTDIR)\smoke.obj"
	-@erase "$(INTDIR)\spclone.obj"
	-@erase "$(INTDIR)\spid_ai0.obj"
	-@erase "$(INTDIR)\spidey.obj"
	-@erase "$(INTDIR)\SpideyDX.obj"
	-@erase "$(INTDIR)\spool.obj"
	-@erase "$(INTDIR)\stubs.obj"
	-@erase "$(INTDIR)\submarin.obj"
	-@erase "$(INTDIR)\superock.obj"
	-@erase "$(INTDIR)\SwapTriggerData.obj"
	-@erase "$(INTDIR)\switch.obj"
	-@erase "$(INTDIR)\thug.obj"
	-@erase "$(INTDIR)\torch.obj"
	-@erase "$(INTDIR)\training.obj"
	-@erase "$(INTDIR)\trig.obj"
	-@erase "$(INTDIR)\turret.obj"
	-@erase "$(INTDIR)\tweak.obj"
	-@erase "$(INTDIR)\utils.obj"
	-@erase "$(INTDIR)\validate.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vector.obj"
	-@erase "$(INTDIR)\venom.obj"
	-@erase "$(INTDIR)\vram.obj"
	-@erase "$(INTDIR)\weapons.obj"
	-@erase "$(INTDIR)\web.obj"
	-@erase "$(INTDIR)\wire.obj"
	-@erase "$(INTDIR)\zrhinog.obj"
	-@erase "$(OUTDIR)\spider.exe"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /I"$(SPIDEY_DIR)\directx\include" /MT /W3 /GX /O2 /Op /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\spider.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "NDEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\spider.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib zlib.lib winmm.lib dinput8.lib dxguid.lib dsound.lib ddraw.lib /nologo /LIBPATH"$(SPIDEY_DIR)\lib" /LIBPATH"$(SPIDEY_DIR)\directx\lib" /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\spider.pdb" /machine:I386 /out:"$(OUTDIR)\spider.exe" 
LINK32_OBJS= \
	"$(INTDIR)\ai.obj" \
	"$(INTDIR)\algebra.obj" \
	"$(INTDIR)\backgrnd.obj" \
	"$(INTDIR)\baddy.obj" \
	"$(INTDIR)\bit.obj" \
	"$(INTDIR)\bit2.obj" \
	"$(INTDIR)\bitmap256.obj" \
	"$(INTDIR)\blackcat.obj" \
	"$(INTDIR)\bmr.obj" \
	"$(INTDIR)\bullet.obj" \
	"$(INTDIR)\camera.obj" \
	"$(INTDIR)\carnage.obj" \
	"$(INTDIR)\chain.obj" \
	"$(INTDIR)\chopper.obj" \
	"$(INTDIR)\chunk.obj" \
	"$(INTDIR)\cinema.obj" \
	"$(INTDIR)\cop.obj" \
	"$(INTDIR)\crate.obj" \
	"$(INTDIR)\db.obj" \
	"$(INTDIR)\dcfileio.obj" \
	"$(INTDIR)\dcmemcard.obj" \
	"$(INTDIR)\dcmodel.obj" \
	"$(INTDIR)\dcshellutils.obj" \
	"$(INTDIR)\decomp.obj" \
	"$(INTDIR)\docock.obj" \
	"$(INTDIR)\DXinit.obj" \
	"$(INTDIR)\DXsound.obj" \
	"$(INTDIR)\effects.obj" \
	"$(INTDIR)\exp.obj" \
	"$(INTDIR)\flash.obj" \
	"$(INTDIR)\FontTools.obj" \
	"$(INTDIR)\friction.obj" \
	"$(INTDIR)\front.obj" \
	"$(INTDIR)\hostage.obj" \
	"$(INTDIR)\Image.obj" \
	"$(INTDIR)\init.obj" \
	"$(INTDIR)\jonah.obj" \
	"$(INTDIR)\l1a3bomb.obj" \
	"$(INTDIR)\l2a1lsc.obj" \
	"$(INTDIR)\l5a5lsc.obj" \
	"$(INTDIR)\l5a6lsc.obj" \
	"$(INTDIR)\l5a7lsc.obj" \
	"$(INTDIR)\l6a1lsc.obj" \
	"$(INTDIR)\l6a2lsc.obj" \
	"$(INTDIR)\l6a3lsc.obj" \
	"$(INTDIR)\lizard.obj" \
	"$(INTDIR)\lizman.obj" \
	"$(INTDIR)\localtxt.obj" \
	"$(INTDIR)\LThread.obj" \
	"$(INTDIR)\m3d.obj" \
	"$(INTDIR)\m3dcolij.obj" \
	"$(INTDIR)\m3dinit.obj" \
	"$(INTDIR)\m3dutils.obj" \
	"$(INTDIR)\m3dzone.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\manipob.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\mess.obj" \
	"$(INTDIR)\message.obj" \
	"$(INTDIR)\mj.obj" \
	"$(INTDIR)\music.obj" \
	"$(INTDIR)\my_bink.obj" \
	"$(INTDIR)\my_debug.obj" \
	"$(INTDIR)\mysterio.obj" \
	"$(INTDIR)\ob.obj" \
	"$(INTDIR)\pack.obj" \
	"$(INTDIR)\pal.obj" \
	"$(INTDIR)\panel.obj" \
	"$(INTDIR)\pcdcBkup.obj" \
	"$(INTDIR)\pcdcFile.obj" \
	"$(INTDIR)\pcdcMem.obj" \
	"$(INTDIR)\pcdcPad.obj" \
	"$(INTDIR)\PCGfx.obj" \
	"$(INTDIR)\PCInput.obj" \
	"$(INTDIR)\PCMovie.obj" \
	"$(INTDIR)\PCMusic.obj" \
	"$(INTDIR)\PCShell.obj" \
	"$(INTDIR)\PCTex.obj" \
	"$(INTDIR)\PCTimer.obj" \
	"$(INTDIR)\physics.obj" \
	"$(INTDIR)\pkr.obj" \
	"$(INTDIR)\platform.obj" \
	"$(INTDIR)\post.obj" \
	"$(INTDIR)\powerup.obj" \
	"$(INTDIR)\PRE.obj" \
	"$(INTDIR)\ps2card.obj" \
	"$(INTDIR)\ps2funcs.obj" \
	"$(INTDIR)\ps2gamefmv.obj" \
	"$(INTDIR)\ps2lowsfx.obj" \
	"$(INTDIR)\ps2m3d.obj" \
	"$(INTDIR)\ps2pad.obj" \
	"$(INTDIR)\ps2redbook.obj" \
	"$(INTDIR)\pshell.obj" \
	"$(INTDIR)\quat.obj" \
	"$(INTDIR)\reloc.obj" \
	"$(INTDIR)\reloc_g.obj" \
	"$(INTDIR)\rfront.obj" \
	"$(INTDIR)\rhino.obj" \
	"$(INTDIR)\Sbinit.obj" \
	"$(INTDIR)\scorpion.obj" \
	"$(INTDIR)\screen.obj" \
	"$(INTDIR)\shatter.obj" \
	"$(INTDIR)\shell.obj" \
	"$(INTDIR)\simby.obj" \
	"$(INTDIR)\smoke.obj" \
	"$(INTDIR)\spclone.obj" \
	"$(INTDIR)\spid_ai0.obj" \
	"$(INTDIR)\spidey.obj" \
	"$(INTDIR)\SpideyDX.obj" \
	"$(INTDIR)\spool.obj" \
	"$(INTDIR)\stubs.obj" \
	"$(INTDIR)\submarin.obj" \
	"$(INTDIR)\superock.obj" \
	"$(INTDIR)\SwapTriggerData.obj" \
	"$(INTDIR)\switch.obj" \
	"$(INTDIR)\thug.obj" \
	"$(INTDIR)\torch.obj" \
	"$(INTDIR)\training.obj" \
	"$(INTDIR)\trig.obj" \
	"$(INTDIR)\turret.obj" \
	"$(INTDIR)\tweak.obj" \
	"$(INTDIR)\utils.obj" \
	"$(INTDIR)\validate.obj" \
	"$(INTDIR)\vector.obj" \
	"$(INTDIR)\venom.obj" \
	"$(INTDIR)\vram.obj" \
	"$(INTDIR)\weapons.obj" \
	"$(INTDIR)\web.obj" \
	"$(INTDIR)\wire.obj" \
	"$(INTDIR)\zrhinog.obj" \
	".\font_draw.obj"

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
	-@erase "$(INTDIR)\ai.obj"
	-@erase "$(INTDIR)\algebra.obj"
	-@erase "$(INTDIR)\backgrnd.obj"
	-@erase "$(INTDIR)\baddy.obj"
	-@erase "$(INTDIR)\bit.obj"
	-@erase "$(INTDIR)\bit2.obj"
	-@erase "$(INTDIR)\bitmap256.obj"
	-@erase "$(INTDIR)\blackcat.obj"
	-@erase "$(INTDIR)\bmr.obj"
	-@erase "$(INTDIR)\bullet.obj"
	-@erase "$(INTDIR)\camera.obj"
	-@erase "$(INTDIR)\carnage.obj"
	-@erase "$(INTDIR)\chain.obj"
	-@erase "$(INTDIR)\chopper.obj"
	-@erase "$(INTDIR)\chunk.obj"
	-@erase "$(INTDIR)\cinema.obj"
	-@erase "$(INTDIR)\cop.obj"
	-@erase "$(INTDIR)\crate.obj"
	-@erase "$(INTDIR)\db.obj"
	-@erase "$(INTDIR)\dcfileio.obj"
	-@erase "$(INTDIR)\dcmemcard.obj"
	-@erase "$(INTDIR)\dcmodel.obj"
	-@erase "$(INTDIR)\dcshellutils.obj"
	-@erase "$(INTDIR)\decomp.obj"
	-@erase "$(INTDIR)\docock.obj"
	-@erase "$(INTDIR)\DXinit.obj"
	-@erase "$(INTDIR)\DXsound.obj"
	-@erase "$(INTDIR)\effects.obj"
	-@erase "$(INTDIR)\exp.obj"
	-@erase "$(INTDIR)\flash.obj"
	-@erase "$(INTDIR)\FontTools.obj"
	-@erase "$(INTDIR)\friction.obj"
	-@erase "$(INTDIR)\front.obj"
	-@erase "$(INTDIR)\hostage.obj"
	-@erase "$(INTDIR)\Image.obj"
	-@erase "$(INTDIR)\init.obj"
	-@erase "$(INTDIR)\jonah.obj"
	-@erase "$(INTDIR)\l1a3bomb.obj"
	-@erase "$(INTDIR)\l2a1lsc.obj"
	-@erase "$(INTDIR)\l5a5lsc.obj"
	-@erase "$(INTDIR)\l5a6lsc.obj"
	-@erase "$(INTDIR)\l5a7lsc.obj"
	-@erase "$(INTDIR)\l6a1lsc.obj"
	-@erase "$(INTDIR)\l6a2lsc.obj"
	-@erase "$(INTDIR)\l6a3lsc.obj"
	-@erase "$(INTDIR)\lizard.obj"
	-@erase "$(INTDIR)\lizman.obj"
	-@erase "$(INTDIR)\localtxt.obj"
	-@erase "$(INTDIR)\LThread.obj"
	-@erase "$(INTDIR)\m3d.obj"
	-@erase "$(INTDIR)\m3dcolij.obj"
	-@erase "$(INTDIR)\m3dinit.obj"
	-@erase "$(INTDIR)\m3dutils.obj"
	-@erase "$(INTDIR)\m3dzone.obj"
	-@erase "$(INTDIR)\main.obj"
	-@erase "$(INTDIR)\manipob.obj"
	-@erase "$(INTDIR)\mem.obj"
	-@erase "$(INTDIR)\mess.obj"
	-@erase "$(INTDIR)\message.obj"
	-@erase "$(INTDIR)\mj.obj"
	-@erase "$(INTDIR)\music.obj"
	-@erase "$(INTDIR)\my_bink.obj"
	-@erase "$(INTDIR)\my_debug.obj"
	-@erase "$(INTDIR)\mysterio.obj"
	-@erase "$(INTDIR)\ob.obj"
	-@erase "$(INTDIR)\pack.obj"
	-@erase "$(INTDIR)\pal.obj"
	-@erase "$(INTDIR)\panel.obj"
	-@erase "$(INTDIR)\pcdcBkup.obj"
	-@erase "$(INTDIR)\pcdcFile.obj"
	-@erase "$(INTDIR)\pcdcMem.obj"
	-@erase "$(INTDIR)\pcdcPad.obj"
	-@erase "$(INTDIR)\PCGfx.obj"
	-@erase "$(INTDIR)\PCInput.obj"
	-@erase "$(INTDIR)\PCMovie.obj"
	-@erase "$(INTDIR)\PCMusic.obj"
	-@erase "$(INTDIR)\PCShell.obj"
	-@erase "$(INTDIR)\PCTex.obj"
	-@erase "$(INTDIR)\PCTimer.obj"
	-@erase "$(INTDIR)\physics.obj"
	-@erase "$(INTDIR)\pkr.obj"
	-@erase "$(INTDIR)\platform.obj"
	-@erase "$(INTDIR)\post.obj"
	-@erase "$(INTDIR)\powerup.obj"
	-@erase "$(INTDIR)\PRE.obj"
	-@erase "$(INTDIR)\ps2card.obj"
	-@erase "$(INTDIR)\ps2funcs.obj"
	-@erase "$(INTDIR)\ps2gamefmv.obj"
	-@erase "$(INTDIR)\ps2lowsfx.obj"
	-@erase "$(INTDIR)\ps2m3d.obj"
	-@erase "$(INTDIR)\ps2pad.obj"
	-@erase "$(INTDIR)\ps2redbook.obj"
	-@erase "$(INTDIR)\pshell.obj"
	-@erase "$(INTDIR)\quat.obj"
	-@erase "$(INTDIR)\reloc.obj"
	-@erase "$(INTDIR)\reloc_g.obj"
	-@erase "$(INTDIR)\rfront.obj"
	-@erase "$(INTDIR)\rhino.obj"
	-@erase "$(INTDIR)\Sbinit.obj"
	-@erase "$(INTDIR)\scorpion.obj"
	-@erase "$(INTDIR)\screen.obj"
	-@erase "$(INTDIR)\shatter.obj"
	-@erase "$(INTDIR)\shell.obj"
	-@erase "$(INTDIR)\simby.obj"
	-@erase "$(INTDIR)\smoke.obj"
	-@erase "$(INTDIR)\spclone.obj"
	-@erase "$(INTDIR)\spid_ai0.obj"
	-@erase "$(INTDIR)\spidey.obj"
	-@erase "$(INTDIR)\SpideyDX.obj"
	-@erase "$(INTDIR)\spool.obj"
	-@erase "$(INTDIR)\stubs.obj"
	-@erase "$(INTDIR)\submarin.obj"
	-@erase "$(INTDIR)\superock.obj"
	-@erase "$(INTDIR)\SwapTriggerData.obj"
	-@erase "$(INTDIR)\switch.obj"
	-@erase "$(INTDIR)\thug.obj"
	-@erase "$(INTDIR)\torch.obj"
	-@erase "$(INTDIR)\training.obj"
	-@erase "$(INTDIR)\trig.obj"
	-@erase "$(INTDIR)\turret.obj"
	-@erase "$(INTDIR)\tweak.obj"
	-@erase "$(INTDIR)\utils.obj"
	-@erase "$(INTDIR)\validate.obj"
	-@erase "$(INTDIR)\vc60.idb"
	-@erase "$(INTDIR)\vector.obj"
	-@erase "$(INTDIR)\venom.obj"
	-@erase "$(INTDIR)\vram.obj"
	-@erase "$(INTDIR)\weapons.obj"
	-@erase "$(INTDIR)\web.obj"
	-@erase "$(INTDIR)\wire.obj"
	-@erase "$(INTDIR)\zrhinog.obj"
	-@erase "$(OUTDIR)\spider.exe"
	-@erase "$(OUTDIR)\spider.pdb"

"$(OUTDIR)" :
    if not exist "$(OUTDIR)/$(NULL)" mkdir "$(OUTDIR)"

CPP_PROJ=/nologo /MT /W3 /GX /O2 /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /Fp"$(INTDIR)\spider.pch" /YX /Fo"$(INTDIR)\\" /Fd"$(INTDIR)\\" /FD /c 
MTL_PROJ=/nologo /D "_DEBUG" /mktyplib203 /win32 
BSC32=bscmake.exe
BSC32_FLAGS=/nologo /o"$(OUTDIR)\spider.bsc" 
BSC32_SBRS= \
	
LINK32=link.exe
LINK32_FLAGS=kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /pdb:"$(OUTDIR)\spider.pdb" /debug /machine:I386 /out:"$(OUTDIR)\spider.exe" /pdbtype:sept 
LINK32_OBJS= \
	"$(INTDIR)\ai.obj" \
	"$(INTDIR)\algebra.obj" \
	"$(INTDIR)\backgrnd.obj" \
	"$(INTDIR)\baddy.obj" \
	"$(INTDIR)\bit.obj" \
	"$(INTDIR)\bit2.obj" \
	"$(INTDIR)\bitmap256.obj" \
	"$(INTDIR)\blackcat.obj" \
	"$(INTDIR)\bmr.obj" \
	"$(INTDIR)\bullet.obj" \
	"$(INTDIR)\camera.obj" \
	"$(INTDIR)\carnage.obj" \
	"$(INTDIR)\chain.obj" \
	"$(INTDIR)\chopper.obj" \
	"$(INTDIR)\chunk.obj" \
	"$(INTDIR)\cinema.obj" \
	"$(INTDIR)\cop.obj" \
	"$(INTDIR)\crate.obj" \
	"$(INTDIR)\db.obj" \
	"$(INTDIR)\dcfileio.obj" \
	"$(INTDIR)\dcmemcard.obj" \
	"$(INTDIR)\dcmodel.obj" \
	"$(INTDIR)\dcshellutils.obj" \
	"$(INTDIR)\decomp.obj" \
	"$(INTDIR)\docock.obj" \
	"$(INTDIR)\DXinit.obj" \
	"$(INTDIR)\DXsound.obj" \
	"$(INTDIR)\effects.obj" \
	"$(INTDIR)\exp.obj" \
	"$(INTDIR)\flash.obj" \
	"$(INTDIR)\FontTools.obj" \
	"$(INTDIR)\friction.obj" \
	"$(INTDIR)\front.obj" \
	"$(INTDIR)\hostage.obj" \
	"$(INTDIR)\Image.obj" \
	"$(INTDIR)\init.obj" \
	"$(INTDIR)\jonah.obj" \
	"$(INTDIR)\l1a3bomb.obj" \
	"$(INTDIR)\l2a1lsc.obj" \
	"$(INTDIR)\l5a5lsc.obj" \
	"$(INTDIR)\l5a6lsc.obj" \
	"$(INTDIR)\l5a7lsc.obj" \
	"$(INTDIR)\l6a1lsc.obj" \
	"$(INTDIR)\l6a2lsc.obj" \
	"$(INTDIR)\l6a3lsc.obj" \
	"$(INTDIR)\lizard.obj" \
	"$(INTDIR)\lizman.obj" \
	"$(INTDIR)\localtxt.obj" \
	"$(INTDIR)\LThread.obj" \
	"$(INTDIR)\m3d.obj" \
	"$(INTDIR)\m3dcolij.obj" \
	"$(INTDIR)\m3dinit.obj" \
	"$(INTDIR)\m3dutils.obj" \
	"$(INTDIR)\m3dzone.obj" \
	"$(INTDIR)\main.obj" \
	"$(INTDIR)\manipob.obj" \
	"$(INTDIR)\mem.obj" \
	"$(INTDIR)\mess.obj" \
	"$(INTDIR)\message.obj" \
	"$(INTDIR)\mj.obj" \
	"$(INTDIR)\music.obj" \
	"$(INTDIR)\my_bink.obj" \
	"$(INTDIR)\my_debug.obj" \
	"$(INTDIR)\mysterio.obj" \
	"$(INTDIR)\ob.obj" \
	"$(INTDIR)\pack.obj" \
	"$(INTDIR)\pal.obj" \
	"$(INTDIR)\panel.obj" \
	"$(INTDIR)\pcdcBkup.obj" \
	"$(INTDIR)\pcdcFile.obj" \
	"$(INTDIR)\pcdcMem.obj" \
	"$(INTDIR)\pcdcPad.obj" \
	"$(INTDIR)\PCGfx.obj" \
	"$(INTDIR)\PCInput.obj" \
	"$(INTDIR)\PCMovie.obj" \
	"$(INTDIR)\PCMusic.obj" \
	"$(INTDIR)\PCShell.obj" \
	"$(INTDIR)\PCTex.obj" \
	"$(INTDIR)\PCTimer.obj" \
	"$(INTDIR)\physics.obj" \
	"$(INTDIR)\pkr.obj" \
	"$(INTDIR)\platform.obj" \
	"$(INTDIR)\post.obj" \
	"$(INTDIR)\powerup.obj" \
	"$(INTDIR)\PRE.obj" \
	"$(INTDIR)\ps2card.obj" \
	"$(INTDIR)\ps2funcs.obj" \
	"$(INTDIR)\ps2gamefmv.obj" \
	"$(INTDIR)\ps2lowsfx.obj" \
	"$(INTDIR)\ps2m3d.obj" \
	"$(INTDIR)\ps2pad.obj" \
	"$(INTDIR)\ps2redbook.obj" \
	"$(INTDIR)\pshell.obj" \
	"$(INTDIR)\quat.obj" \
	"$(INTDIR)\reloc.obj" \
	"$(INTDIR)\reloc_g.obj" \
	"$(INTDIR)\rfront.obj" \
	"$(INTDIR)\rhino.obj" \
	"$(INTDIR)\Sbinit.obj" \
	"$(INTDIR)\scorpion.obj" \
	"$(INTDIR)\screen.obj" \
	"$(INTDIR)\shatter.obj" \
	"$(INTDIR)\shell.obj" \
	"$(INTDIR)\simby.obj" \
	"$(INTDIR)\smoke.obj" \
	"$(INTDIR)\spclone.obj" \
	"$(INTDIR)\spid_ai0.obj" \
	"$(INTDIR)\spidey.obj" \
	"$(INTDIR)\SpideyDX.obj" \
	"$(INTDIR)\spool.obj" \
	"$(INTDIR)\stubs.obj" \
	"$(INTDIR)\submarin.obj" \
	"$(INTDIR)\superock.obj" \
	"$(INTDIR)\SwapTriggerData.obj" \
	"$(INTDIR)\switch.obj" \
	"$(INTDIR)\thug.obj" \
	"$(INTDIR)\torch.obj" \
	"$(INTDIR)\training.obj" \
	"$(INTDIR)\trig.obj" \
	"$(INTDIR)\turret.obj" \
	"$(INTDIR)\tweak.obj" \
	"$(INTDIR)\utils.obj" \
	"$(INTDIR)\validate.obj" \
	"$(INTDIR)\vector.obj" \
	"$(INTDIR)\venom.obj" \
	"$(INTDIR)\vram.obj" \
	"$(INTDIR)\weapons.obj" \
	"$(INTDIR)\web.obj" \
	"$(INTDIR)\wire.obj" \
	"$(INTDIR)\zrhinog.obj" \
	".\font_draw.obj"

"$(OUTDIR)\spider.exe" : "$(OUTDIR)" $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

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


!IF "$(NO_EXTERNAL_DEPS)" != "1"
!IF EXISTS("spider.dep")
!INCLUDE "spider.dep"
!ELSE 
!MESSAGE Warning: cannot find "spider.dep"
!ENDIF 
!ENDIF 


!IF "$(CFG)" == "spider - Win32 Release" || "$(CFG)" == "spider - Win32 Debug"
SOURCE=.\ai.cpp

"$(INTDIR)\ai.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\algebra.cpp

"$(INTDIR)\algebra.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\backgrnd.cpp

"$(INTDIR)\backgrnd.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\baddy.cpp

"$(INTDIR)\baddy.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\bit.cpp

"$(INTDIR)\bit.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\bit2.cpp

"$(INTDIR)\bit2.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\bitmap256.cpp

"$(INTDIR)\bitmap256.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\blackcat.cpp

"$(INTDIR)\blackcat.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\bmr.cpp

"$(INTDIR)\bmr.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\bullet.cpp

"$(INTDIR)\bullet.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\camera.cpp

"$(INTDIR)\camera.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\carnage.cpp

"$(INTDIR)\carnage.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\chain.cpp

"$(INTDIR)\chain.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\chopper.cpp

"$(INTDIR)\chopper.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\chunk.cpp

"$(INTDIR)\chunk.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\cinema.cpp

"$(INTDIR)\cinema.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\cop.cpp

"$(INTDIR)\cop.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\crate.cpp

"$(INTDIR)\crate.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\db.cpp

"$(INTDIR)\db.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\dcfileio.cpp

"$(INTDIR)\dcfileio.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\dcmemcard.cpp

"$(INTDIR)\dcmemcard.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\dcmodel.cpp

"$(INTDIR)\dcmodel.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\dcshellutils.cpp

"$(INTDIR)\dcshellutils.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\decomp.cpp

"$(INTDIR)\decomp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\docock.cpp

"$(INTDIR)\docock.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\DXinit.cpp

"$(INTDIR)\DXinit.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\DXsound.cpp

"$(INTDIR)\DXsound.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\effects.cpp

"$(INTDIR)\effects.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\exp.cpp

"$(INTDIR)\exp.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\flash.cpp

"$(INTDIR)\flash.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\FontTools.cpp

"$(INTDIR)\FontTools.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\friction.cpp

"$(INTDIR)\friction.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\front.cpp

"$(INTDIR)\front.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\hostage.cpp

"$(INTDIR)\hostage.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Image.cpp

"$(INTDIR)\Image.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\init.cpp

"$(INTDIR)\init.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\jonah.cpp

"$(INTDIR)\jonah.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\l1a3bomb.cpp

"$(INTDIR)\l1a3bomb.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\l2a1lsc.cpp

"$(INTDIR)\l2a1lsc.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\l5a5lsc.cpp

"$(INTDIR)\l5a5lsc.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\l5a6lsc.cpp

"$(INTDIR)\l5a6lsc.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\l5a7lsc.cpp

"$(INTDIR)\l5a7lsc.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\l6a1lsc.cpp

"$(INTDIR)\l6a1lsc.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\l6a2lsc.cpp

"$(INTDIR)\l6a2lsc.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\l6a3lsc.cpp

"$(INTDIR)\l6a3lsc.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\lizard.cpp

"$(INTDIR)\lizard.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\lizman.cpp

"$(INTDIR)\lizman.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\localtxt.cpp

"$(INTDIR)\localtxt.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\LThread.cpp

"$(INTDIR)\LThread.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\m3d.cpp

"$(INTDIR)\m3d.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\m3dcolij.cpp

"$(INTDIR)\m3dcolij.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\m3dinit.cpp

"$(INTDIR)\m3dinit.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\m3dutils.cpp

"$(INTDIR)\m3dutils.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\m3dzone.cpp

"$(INTDIR)\m3dzone.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\main.cpp

"$(INTDIR)\main.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\manipob.cpp

"$(INTDIR)\manipob.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\mem.cpp

"$(INTDIR)\mem.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\mess.cpp

"$(INTDIR)\mess.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\message.cpp

"$(INTDIR)\message.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\mj.cpp

"$(INTDIR)\mj.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\music.cpp

"$(INTDIR)\music.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\my_bink.cpp

"$(INTDIR)\my_bink.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\my_debug.cpp

"$(INTDIR)\my_debug.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\mysterio.cpp

"$(INTDIR)\mysterio.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ob.cpp

"$(INTDIR)\ob.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\pack.cpp

"$(INTDIR)\pack.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\pal.cpp

"$(INTDIR)\pal.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\panel.cpp

"$(INTDIR)\panel.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\pcdcBkup.cpp

"$(INTDIR)\pcdcBkup.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\pcdcFile.cpp

"$(INTDIR)\pcdcFile.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\pcdcMem.cpp

"$(INTDIR)\pcdcMem.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\pcdcPad.cpp

"$(INTDIR)\pcdcPad.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\PCGfx.cpp

"$(INTDIR)\PCGfx.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\PCInput.cpp

"$(INTDIR)\PCInput.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\PCMovie.cpp

"$(INTDIR)\PCMovie.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\PCMusic.cpp

"$(INTDIR)\PCMusic.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\PCShell.cpp

"$(INTDIR)\PCShell.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\PCTex.cpp

"$(INTDIR)\PCTex.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\PCTimer.cpp

"$(INTDIR)\PCTimer.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\physics.cpp

"$(INTDIR)\physics.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\pkr.cpp

"$(INTDIR)\pkr.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\platform.cpp

"$(INTDIR)\platform.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\post.cpp

"$(INTDIR)\post.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\powerup.cpp

"$(INTDIR)\powerup.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\PRE.cpp

"$(INTDIR)\PRE.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ps2card.cpp

"$(INTDIR)\ps2card.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ps2funcs.cpp

"$(INTDIR)\ps2funcs.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ps2gamefmv.cpp

"$(INTDIR)\ps2gamefmv.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ps2lowsfx.cpp

"$(INTDIR)\ps2lowsfx.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ps2m3d.cpp

"$(INTDIR)\ps2m3d.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ps2pad.cpp

"$(INTDIR)\ps2pad.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\ps2redbook.cpp

"$(INTDIR)\ps2redbook.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\pshell.cpp

"$(INTDIR)\pshell.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\quat.cpp

"$(INTDIR)\quat.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\reloc.cpp

"$(INTDIR)\reloc.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\reloc_g.cpp

"$(INTDIR)\reloc_g.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\rfront.cpp

"$(INTDIR)\rfront.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\rhino.cpp

"$(INTDIR)\rhino.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\Sbinit.cpp

"$(INTDIR)\Sbinit.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\scorpion.cpp

"$(INTDIR)\scorpion.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\screen.cpp

"$(INTDIR)\screen.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\shatter.cpp

"$(INTDIR)\shatter.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\shell.cpp

"$(INTDIR)\shell.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\simby.cpp

"$(INTDIR)\simby.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\smoke.cpp

"$(INTDIR)\smoke.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\spclone.cpp

"$(INTDIR)\spclone.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\spid_ai0.cpp

"$(INTDIR)\spid_ai0.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\spidey.cpp

"$(INTDIR)\spidey.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SpideyDX.cpp

"$(INTDIR)\SpideyDX.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\spool.cpp

"$(INTDIR)\spool.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\stubs.cpp

"$(INTDIR)\stubs.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\submarin.cpp

"$(INTDIR)\submarin.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\superock.cpp

"$(INTDIR)\superock.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\SwapTriggerData.cpp

"$(INTDIR)\SwapTriggerData.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\switch.cpp

"$(INTDIR)\switch.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\thug.cpp

"$(INTDIR)\thug.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\torch.cpp

"$(INTDIR)\torch.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\training.cpp

"$(INTDIR)\training.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\trig.cpp

"$(INTDIR)\trig.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\turret.cpp

"$(INTDIR)\turret.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\tweak.cpp

"$(INTDIR)\tweak.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\utils.cpp

"$(INTDIR)\utils.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\validate.cpp

"$(INTDIR)\validate.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\vector.cpp

"$(INTDIR)\vector.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\venom.cpp

"$(INTDIR)\venom.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\vram.cpp

"$(INTDIR)\vram.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\weapons.cpp

"$(INTDIR)\weapons.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\web.cpp

"$(INTDIR)\web.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\wire.cpp

"$(INTDIR)\wire.obj" : $(SOURCE) "$(INTDIR)"


SOURCE=.\zrhinog.cpp

"$(INTDIR)\zrhinog.obj" : $(SOURCE) "$(INTDIR)"



!ENDIF 

