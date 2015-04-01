@echo off
call :sub > execution.txt
exit /b

:sub
".\\x64\\Release\\product.exe" 600 600 2 
echo --------------------- 
".\\x64\\Release\\product.exe" 1000 1000 2 
echo ---------------------
".\\x64\\Release\\product.exe" 1400 1400 2
echo ---------------------
".\\x64\\Release\\product.exe" 1800 1800 2
echo ---------------------
".\\x64\\Release\\product.exe" 2200 2200 2
echo ---------------------
".\\x64\\Release\\product.exe" 2600 2600 2
echo ---------------------
".\\x64\\Release\\product.exe" 3000 3000 2
echo ---------------------
".\\x64\\Release\\product.exe" 4000 4000 2
echo ---------------------
".\\x64\\Release\\product.exe" 4000 4000 2
echo ---------------------
".\\x64\\Release\\product.exe" 8000 8000 2
echo ---------------------
".\\x64\\Release\\product.exe" 10000 10000 2