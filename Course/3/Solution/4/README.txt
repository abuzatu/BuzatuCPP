Exercise 4 adds on exercise 4 by compiling planet.C as a shared library in a new folder we create, lib. That will allow the class Planet and its functions that help for ordering to be used by more than one executable. 

Read:http://peon-developments.blogspot.co.uk/2011/07/creating-and-using-c-shared-libraries.html

Notice the changes for shared library. 
For Mac you use "-dynamiclib", for Linux you use "-shared"
For Linux one extra step is needed before running, as otherwise it will crash. You can still do it for Mac, it is not necessary, but it does not hurt. We need to add our lib folder to the LD_LIBRARY_PATH, so that the library is found at run time. At compilation time it is told from here "-L/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/4/lib -lplanet" where it is located. Notice that the library file is called libplanet.so, but here we have "-lplanet", formed by "-l" followed without space by the name of the library, but without the "lib" in front and ".so" at the end. That is the convention. 

make
export LD_LIBRARY_PATH="/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/4/lib:${LD_LIBRARY_PATH}
./bin/run.exe
make clean

Notice how the folder has to have the full path. For your package, you should change this path both in the Makefile, and above at the export command.

You are now ready to understand the Makefile from TutorialCPP, which is complex, because it compiles for both linux and Mac, both for a shared library, or for an executable. It has its own HOW_TO_RUN.txt, so please read that carefully. You have here or there an example to start your own software package for your own research. 

