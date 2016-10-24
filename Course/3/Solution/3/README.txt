Exercise 3 does the same thing as before, but organises the files in folders.
obj - the object .o files
bin - the binary (executable) .exe files
input - the input .txt files
h - the header .h files
C - the implemenetations .C files

Compare the new Makefile with the Makefile from folder 2.

We need to tell where the .h files are located, as they are not in the local folder any more. This is why we add "-I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o". 

Since the .o files are in a certain folder, it means we want to give them a certain name that contains the path as well, so we need to add the "-o" option, which was not necessary before. 

make
./bin/run.exe
make clean

