@echo off
set threads=4
set option=3
set test=echo Test
set time=time /T
call :sub > execution.txt
exit /b

:sub
%time% > CON
".\\x64\\Release\\product.exe" 600 600 %option% %threads%
%time% > CON
%test% 600 DONE > CON
echo --------------------- 

%time% > CON
".\\x64\\Release\\product.exe" 1000 1000 %option% %threads%
%time% > CON
%test% 1000 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 1400 1400 %option% %threads%
%time% > CON
%test% 1400 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 1800 1800 %option% %threads%
%time% > CON
%test% 1800 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 2200 2200 %option% %threads%
%time% > CON
%test% 2200 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 2600 2600 %option% %threads%
%time% > CON
%test% 2600 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 3000 3000 %option% %threads%
%time% > CON
%test% 3000 DONE > CON
echo ---------------------