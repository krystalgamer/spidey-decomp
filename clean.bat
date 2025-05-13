setlocal
set MSVCDir=C:\vs

set PATH=%MSDevDir%\BIN;%MSVCDir%\BIN;%PATH%

set INCLUDE=%MSVCDir%\ATL\INCLUDE;%MSVCDir%\INCLUDE;%MSVCDir%\MFC\INCLUDE;%INCLUDE%
set LIB=%MSVCDir%\LIB;%MSVCDir%\MFC\LIB;%LIB%

set "oldStr=%~dp0"
set "coolP=%oldStr:~0,-1%"
nmake /f "spider.mak" CFG="spider - Win32 Release" SPIDEY_DIR="%coolP%" clean
