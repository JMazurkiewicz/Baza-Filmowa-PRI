@echo off

gcc ..\*.c ..\*\*.c ..\*\*\*.c ..\*\*\*\*.c -I ..\. -std=c11 -Wall -pedantic -o BazaFilmowa

pause
