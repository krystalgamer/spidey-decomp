setlocal
set MSVCDir=C:\vs

set PATH=%MSDevDir%\BIN;%MSVCDir%\BIN;%PATH%

set INCLUDE=%MSVCDir%\ATL\INCLUDE;%MSVCDir%\INCLUDE;%MSVCDir%\MFC\INCLUDE;%INCLUDE%
set LIB=%MSVCDir%\LIB;%MSVCDir%\MFC\LIB;%LIB%

nmake /f "spider.mak" CFG="spider - Win32 Release" SPIDEY_DIR="C:\spidey-decomp" clean
