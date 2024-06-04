# Microsoft Developer Studio Project File - Name="spider" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=spider - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "spider.mak".
!MESSAGE 
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

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "spider - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /Op /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "spider - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /YX /FD /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:windows /incremental:no /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "spider - Win32 Release"
# Name "spider - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\ai.cpp
# End Source File
# Begin Source File

SOURCE=.\algebra.cpp
# End Source File
# Begin Source File

SOURCE=.\backgrnd.cpp
# End Source File
# Begin Source File

SOURCE=.\baddy.cpp
# End Source File
# Begin Source File

SOURCE=.\bit.cpp
# End Source File
# Begin Source File

SOURCE=.\bit2.cpp
# End Source File
# Begin Source File

SOURCE=.\bitmap256.cpp
# End Source File
# Begin Source File

SOURCE=.\blackcat.cpp
# End Source File
# Begin Source File

SOURCE=.\bmr.cpp
# End Source File
# Begin Source File

SOURCE=.\bullet.cpp
# End Source File
# Begin Source File

SOURCE=.\camera.cpp
# End Source File
# Begin Source File

SOURCE=.\carnage.cpp
# End Source File
# Begin Source File

SOURCE=.\chain.cpp
# End Source File
# Begin Source File

SOURCE=.\chopper.cpp
# End Source File
# Begin Source File

SOURCE=.\chunk.cpp
# End Source File
# Begin Source File

SOURCE=.\cinema.cpp
# End Source File
# Begin Source File

SOURCE=.\cop.cpp
# End Source File
# Begin Source File

SOURCE=.\crate.cpp
# End Source File
# Begin Source File

SOURCE=.\db.cpp
# End Source File
# Begin Source File

SOURCE=.\dcfileio.cpp
# End Source File
# Begin Source File

SOURCE=.\dcmemcard.cpp
# End Source File
# Begin Source File

SOURCE=.\dcmodel.cpp
# End Source File
# Begin Source File

SOURCE=.\dcshellutils.cpp
# End Source File
# Begin Source File

SOURCE=.\decomp.cpp
# End Source File
# Begin Source File

SOURCE=.\docock.cpp
# End Source File
# Begin Source File

SOURCE=.\DXinit.cpp
# End Source File
# Begin Source File

SOURCE=.\DXsound.cpp
# End Source File
# Begin Source File

SOURCE=.\effects.cpp
# End Source File
# Begin Source File

SOURCE=.\exp.cpp
# End Source File
# Begin Source File

SOURCE=.\flash.cpp
# End Source File
# Begin Source File

SOURCE=.\FontTools.cpp
# End Source File
# Begin Source File

SOURCE=.\friction.cpp
# End Source File
# Begin Source File

SOURCE=.\front.cpp
# End Source File
# Begin Source File

SOURCE=.\hostage.cpp
# End Source File
# Begin Source File

SOURCE=.\Image.cpp
# End Source File
# Begin Source File

SOURCE=.\init.cpp
# End Source File
# Begin Source File

SOURCE=.\jonah.cpp
# End Source File
# Begin Source File

SOURCE=.\l1a3bomb.cpp
# End Source File
# Begin Source File

SOURCE=.\l2a1lsc.cpp
# End Source File
# Begin Source File

SOURCE=.\l5a5lsc.cpp
# End Source File
# Begin Source File

SOURCE=.\l5a6lsc.cpp
# End Source File
# Begin Source File

SOURCE=.\l5a7lsc.cpp
# End Source File
# Begin Source File

SOURCE=.\l6a1lsc.cpp
# End Source File
# Begin Source File

SOURCE=.\l6a2lsc.cpp
# End Source File
# Begin Source File

SOURCE=.\l6a3lsc.cpp
# End Source File
# Begin Source File

SOURCE=.\lizard.cpp
# End Source File
# Begin Source File

SOURCE=.\lizman.cpp
# End Source File
# Begin Source File

SOURCE=.\localtxt.cpp
# End Source File
# Begin Source File

SOURCE=.\LThread.cpp
# End Source File
# Begin Source File

SOURCE=.\m3d.cpp
# End Source File
# Begin Source File

SOURCE=.\m3dcolij.cpp
# End Source File
# Begin Source File

SOURCE=.\m3dinit.cpp
# End Source File
# Begin Source File

SOURCE=.\m3dutils.cpp
# End Source File
# Begin Source File

SOURCE=.\m3dzone.cpp
# End Source File
# Begin Source File

SOURCE=.\main.cpp
# End Source File
# Begin Source File

SOURCE=.\manipob.cpp
# End Source File
# Begin Source File

SOURCE=.\mem.cpp
# End Source File
# Begin Source File

SOURCE=.\mess.cpp
# End Source File
# Begin Source File

SOURCE=.\message.cpp
# End Source File
# Begin Source File

SOURCE=.\mj.cpp
# End Source File
# Begin Source File

SOURCE=.\music.cpp
# End Source File
# Begin Source File

SOURCE=.\mysterio.cpp
# End Source File
# Begin Source File

SOURCE=.\ob.cpp
# End Source File
# Begin Source File

SOURCE=.\pack.cpp
# End Source File
# Begin Source File

SOURCE=.\pal.cpp
# End Source File
# Begin Source File

SOURCE=.\panel.cpp
# End Source File
# Begin Source File

SOURCE=.\pcdcBkup.cpp
# End Source File
# Begin Source File

SOURCE=.\pcdcFile.cpp
# End Source File
# Begin Source File

SOURCE=.\pcdcMem.cpp
# End Source File
# Begin Source File

SOURCE=.\pcdcPad.cpp
# End Source File
# Begin Source File

SOURCE=.\PCGfx.cpp
# End Source File
# Begin Source File

SOURCE=.\PCInput.cpp
# End Source File
# Begin Source File

SOURCE=.\PCMovie.cpp
# End Source File
# Begin Source File

SOURCE=.\PCMusic.cpp
# End Source File
# Begin Source File

SOURCE=.\PCShell.cpp
# End Source File
# Begin Source File

SOURCE=.\PCTex.cpp
# End Source File
# Begin Source File

SOURCE=.\PCTimer.cpp
# End Source File
# Begin Source File

SOURCE=.\physics.cpp
# End Source File
# Begin Source File

SOURCE=.\platform.cpp
# End Source File
# Begin Source File

SOURCE=.\post.cpp
# End Source File
# Begin Source File

SOURCE=.\powerup.cpp
# End Source File
# Begin Source File

SOURCE=.\PRE.cpp
# End Source File
# Begin Source File

SOURCE=.\ps2card.cpp
# End Source File
# Begin Source File

SOURCE=.\ps2funcs.cpp
# End Source File
# Begin Source File

SOURCE=.\ps2gamefmv.cpp
# End Source File
# Begin Source File

SOURCE=.\ps2lowsfx.cpp
# End Source File
# Begin Source File

SOURCE=.\ps2m3d.cpp
# End Source File
# Begin Source File

SOURCE=.\ps2pad.cpp
# End Source File
# Begin Source File

SOURCE=.\ps2redbook.cpp
# End Source File
# Begin Source File

SOURCE=.\pshell.cpp
# End Source File
# Begin Source File

SOURCE=.\quat.cpp
# End Source File
# Begin Source File

SOURCE=.\reloc.cpp
# End Source File
# Begin Source File

SOURCE=.\reloc_g.cpp
# End Source File
# Begin Source File

SOURCE=.\rfront.cpp
# End Source File
# Begin Source File

SOURCE=.\rhino.cpp
# End Source File
# Begin Source File

SOURCE=.\Sbinit.cpp
# End Source File
# Begin Source File

SOURCE=.\scorpion.cpp
# End Source File
# Begin Source File

SOURCE=.\screen.cpp
# End Source File
# Begin Source File

SOURCE=.\shatter.cpp
# End Source File
# Begin Source File

SOURCE=.\shell.cpp
# End Source File
# Begin Source File

SOURCE=.\simby.cpp
# End Source File
# Begin Source File

SOURCE=.\smoke.cpp
# End Source File
# Begin Source File

SOURCE=.\spclone.cpp
# End Source File
# Begin Source File

SOURCE=.\spid_ai0.cpp
# End Source File
# Begin Source File

SOURCE=.\spidey.cpp
# End Source File
# Begin Source File

SOURCE=.\SpideyDX.cpp
# End Source File
# Begin Source File

SOURCE=.\spool.cpp
# End Source File
# Begin Source File

SOURCE=.\stubs.cpp
# End Source File
# Begin Source File

SOURCE=.\submarin.cpp
# End Source File
# Begin Source File

SOURCE=.\superock.cpp
# End Source File
# Begin Source File

SOURCE=.\SwapTriggerData.cpp
# End Source File
# Begin Source File

SOURCE=.\switch.cpp
# End Source File
# Begin Source File

SOURCE=.\thug.cpp
# End Source File
# Begin Source File

SOURCE=.\torch.cpp
# End Source File
# Begin Source File

SOURCE=.\training.cpp
# End Source File
# Begin Source File

SOURCE=.\trig.cpp
# End Source File
# Begin Source File

SOURCE=.\turret.cpp
# End Source File
# Begin Source File

SOURCE=.\tweak.cpp
# End Source File
# Begin Source File

SOURCE=.\utils.cpp
# End Source File
# Begin Source File

SOURCE=.\validate.cpp
# End Source File
# Begin Source File

SOURCE=.\vector.cpp
# End Source File
# Begin Source File

SOURCE=.\venom.cpp
# End Source File
# Begin Source File

SOURCE=.\vram.cpp
# End Source File
# Begin Source File

SOURCE=.\weapons.cpp
# End Source File
# Begin Source File

SOURCE=.\web.cpp
# End Source File
# Begin Source File

SOURCE=.\wire.cpp
# End Source File
# Begin Source File

SOURCE=.\zrhinog.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\ai.h
# End Source File
# Begin Source File

SOURCE=.\algebra.h
# End Source File
# Begin Source File

SOURCE=.\backgrnd.h
# End Source File
# Begin Source File

SOURCE=.\baddy.h
# End Source File
# Begin Source File

SOURCE=.\bit.h
# End Source File
# Begin Source File

SOURCE=.\bit2.h
# End Source File
# Begin Source File

SOURCE=.\bitmap256.h
# End Source File
# Begin Source File

SOURCE=.\blackcat.h
# End Source File
# Begin Source File

SOURCE=.\bmr.h
# End Source File
# Begin Source File

SOURCE=.\bullet.h
# End Source File
# Begin Source File

SOURCE=.\camera.h
# End Source File
# Begin Source File

SOURCE=.\carnage.h
# End Source File
# Begin Source File

SOURCE=.\chain.h
# End Source File
# Begin Source File

SOURCE=.\chopper.h
# End Source File
# Begin Source File

SOURCE=.\chunk.h
# End Source File
# Begin Source File

SOURCE=.\cinema.h
# End Source File
# Begin Source File

SOURCE=.\cop.h
# End Source File
# Begin Source File

SOURCE=.\crate.h
# End Source File
# Begin Source File

SOURCE=.\db.h
# End Source File
# Begin Source File

SOURCE=.\dcfileio.h
# End Source File
# Begin Source File

SOURCE=.\dcmemcard.h
# End Source File
# Begin Source File

SOURCE=.\dcmodel.h
# End Source File
# Begin Source File

SOURCE=.\dcshellutils.h
# End Source File
# Begin Source File

SOURCE=.\decomp.h
# End Source File
# Begin Source File

SOURCE=.\docock.h
# End Source File
# Begin Source File

SOURCE=.\DXinit.h
# End Source File
# Begin Source File

SOURCE=.\DXsound.h
# End Source File
# Begin Source File

SOURCE=.\effects.h
# End Source File
# Begin Source File

SOURCE=.\exp.h
# End Source File
# Begin Source File

SOURCE=.\export.h
# End Source File
# Begin Source File

SOURCE=.\flash.h
# End Source File
# Begin Source File

SOURCE=.\FontTools.h
# End Source File
# Begin Source File

SOURCE=.\friction.h
# End Source File
# Begin Source File

SOURCE=.\front.h
# End Source File
# Begin Source File

SOURCE=.\hostage.h
# End Source File
# Begin Source File

SOURCE=.\Image.h
# End Source File
# Begin Source File

SOURCE=.\init.h
# End Source File
# Begin Source File

SOURCE=.\jonah.h
# End Source File
# Begin Source File

SOURCE=.\l1a3bomb.h
# End Source File
# Begin Source File

SOURCE=.\l2a1lsc.h
# End Source File
# Begin Source File

SOURCE=.\l5a5lsc.h
# End Source File
# Begin Source File

SOURCE=.\l5a6lsc.h
# End Source File
# Begin Source File

SOURCE=.\l5a7lsc.h
# End Source File
# Begin Source File

SOURCE=.\l6a1lsc.h
# End Source File
# Begin Source File

SOURCE=.\l6a2lsc.h
# End Source File
# Begin Source File

SOURCE=.\l6a3lsc.h
# End Source File
# Begin Source File

SOURCE=.\lizard.h
# End Source File
# Begin Source File

SOURCE=.\lizman.h
# End Source File
# Begin Source File

SOURCE=.\localtxt.h
# End Source File
# Begin Source File

SOURCE=.\LThread.h
# End Source File
# Begin Source File

SOURCE=.\m3d.h
# End Source File
# Begin Source File

SOURCE=.\m3dcolij.h
# End Source File
# Begin Source File

SOURCE=.\m3dinit.h
# End Source File
# Begin Source File

SOURCE=.\m3dutils.h
# End Source File
# Begin Source File

SOURCE=.\m3dzone.h
# End Source File
# Begin Source File

SOURCE=.\main.h
# End Source File
# Begin Source File

SOURCE=.\manipob.h
# End Source File
# Begin Source File

SOURCE=.\mem.h
# End Source File
# Begin Source File

SOURCE=.\mess.h
# End Source File
# Begin Source File

SOURCE=.\message.h
# End Source File
# Begin Source File

SOURCE=.\mj.h
# End Source File
# Begin Source File

SOURCE=.\music.h
# End Source File
# Begin Source File

SOURCE=.\mysterio.h
# End Source File
# Begin Source File

SOURCE=.\ob.h
# End Source File
# Begin Source File

SOURCE=.\pack.h
# End Source File
# Begin Source File

SOURCE=.\pal.h
# End Source File
# Begin Source File

SOURCE=.\panel.h
# End Source File
# Begin Source File

SOURCE=.\pcdcBkup.h
# End Source File
# Begin Source File

SOURCE=.\pcdcFile.h
# End Source File
# Begin Source File

SOURCE=.\pcdcMem.h
# End Source File
# Begin Source File

SOURCE=.\pcdcPad.h
# End Source File
# Begin Source File

SOURCE=.\PCGfx.h
# End Source File
# Begin Source File

SOURCE=.\PCInput.h
# End Source File
# Begin Source File

SOURCE=.\PCMovie.h
# End Source File
# Begin Source File

SOURCE=.\PCMusic.h
# End Source File
# Begin Source File

SOURCE=.\PCShell.h
# End Source File
# Begin Source File

SOURCE=.\PCTex.h
# End Source File
# Begin Source File

SOURCE=.\PCTimer.h
# End Source File
# Begin Source File

SOURCE=.\physics.h
# End Source File
# Begin Source File

SOURCE=.\platform.h
# End Source File
# Begin Source File

SOURCE=.\post.h
# End Source File
# Begin Source File

SOURCE=.\powerup.h
# End Source File
# Begin Source File

SOURCE=.\PRE.h
# End Source File
# Begin Source File

SOURCE=.\ps2card.h
# End Source File
# Begin Source File

SOURCE=.\ps2funcs.h
# End Source File
# Begin Source File

SOURCE=.\ps2gamefmv.h
# End Source File
# Begin Source File

SOURCE=.\ps2lowsfx.h
# End Source File
# Begin Source File

SOURCE=.\ps2m3d.h
# End Source File
# Begin Source File

SOURCE=.\ps2pad.h
# End Source File
# Begin Source File

SOURCE=.\ps2redbook.h
# End Source File
# Begin Source File

SOURCE=.\pshell.h
# End Source File
# Begin Source File

SOURCE=.\quat.h
# End Source File
# Begin Source File

SOURCE=.\reloc.h
# End Source File
# Begin Source File

SOURCE=.\reloc_g.h
# End Source File
# Begin Source File

SOURCE=.\rfront.h
# End Source File
# Begin Source File

SOURCE=.\rhino.h
# End Source File
# Begin Source File

SOURCE=.\Sbinit.h
# End Source File
# Begin Source File

SOURCE=.\scorpion.h
# End Source File
# Begin Source File

SOURCE=.\screen.h
# End Source File
# Begin Source File

SOURCE=.\shatter.h
# End Source File
# Begin Source File

SOURCE=.\shell.h
# End Source File
# Begin Source File

SOURCE=.\simby.h
# End Source File
# Begin Source File

SOURCE=.\smoke.h
# End Source File
# Begin Source File

SOURCE=.\spclone.h
# End Source File
# Begin Source File

SOURCE=.\spid_ai0.h
# End Source File
# Begin Source File

SOURCE=.\spidey.h
# End Source File
# Begin Source File

SOURCE=.\SpideyDX.h
# End Source File
# Begin Source File

SOURCE=.\spool.h
# End Source File
# Begin Source File

SOURCE=.\stateflags.h
# End Source File
# Begin Source File

SOURCE=.\submarin.h
# End Source File
# Begin Source File

SOURCE=.\superock.h
# End Source File
# Begin Source File

SOURCE=.\texture.h
# End Source File
# Begin Source File

SOURCE=.\thug.h
# End Source File
# Begin Source File

SOURCE=.\torch.h
# End Source File
# Begin Source File

SOURCE=.\trig.h
# End Source File
# Begin Source File

SOURCE=.\turret.h
# End Source File
# Begin Source File

SOURCE=.\utils.h
# End Source File
# Begin Source File

SOURCE=.\validate.h
# End Source File
# Begin Source File

SOURCE=.\vector.h
# End Source File
# Begin Source File

SOURCE=.\venom.h
# End Source File
# Begin Source File

SOURCE=.\web.h
# End Source File
# Begin Source File

SOURCE=.\wire.h
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
