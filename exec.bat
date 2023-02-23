set mainFile=main
set libList=files
set libOutList=files.o
(for %%l in (%libList%) do  gcc -c %%l.c)
gcc -c %mainFile%.c -lm
gcc -o %mainFile%.exe %mainFile%.o %libOutList%
.\%mainFile%.exe