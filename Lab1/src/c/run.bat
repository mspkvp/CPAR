@echo off
set threads=2
set test=echo Test
set time=time /T
call :sub > execution.txt
exit /b

:sub
%time% > CON
".\\x64\\Release\\product.exe" 600 600 %threads%
%time% > CON
%test% 600 DONE > CON
echo --------------------- 

%time% > CON
".\\x64\\Release\\product.exe" 1000 1000 %threads%
%time% > CON
%test% 1000 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 1400 1400 %threads%
%time% > CON
%test% 1400 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 1800 1800 %threads%
%time% > CON
%test% 1800 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 2200 2200 %threads%
%time% > CON
%test% 2200 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 2600 2600 %threads%
%time% > CON
%test% 2600 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 3000 3000 %threads%
%time% > CON
%test% 3000 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 4000 4000 %threads%
%time% > CON
%test% 4000 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 6000 6000 %threads%
%time% > CON
%test% 6000 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 8000 8000 %threads%
%time% > CON
%test% 8000 DONE > CON
echo ---------------------

%time% > CON
".\\x64\\Release\\product.exe" 10000 10000 %threads%
%time% > CON
%test% 10000 DONE > CON