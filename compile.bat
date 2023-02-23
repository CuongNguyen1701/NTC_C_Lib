@echo off
break>libOutList.txt
set mainFile=main
set libList=adstring
(for %%l in (%libList%) do  gcc -c %%l.c)
(for %%l in (%libList%) do  (
    echo | set /p=%%l.o >> libOutList.txt
))
for /F "delims=" %%x in (libOutList.txt) do (
     set libOutList=%%x
)
gcc -c %mainFile%.c 
gcc -o %mainFile%.exe %mainFile%.o %libOutList%
rem .\%mainFile%.exe