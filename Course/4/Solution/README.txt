Adrian Buzatu, adrian.buzatu@glasgow.ac.uk
Research Associate, University of Glasgow
28 November 2015
This is a software package that solves the modelling of the solar system. 
The folder structure explained below can be used to write your own software package.

*****************************************************************************************************************
**************************** Instructions to use ****************************************************************
*****************************************************************************************************************
1. choose Mac or Linux
emacs Makefile&

2. compile
make

3. add our current lib folder to the LD_LIBRARY_PATH, so that we can use the shared libraries we create
source setup.sh

4. run
./bin/main.exe
get a controlled crash to see example of the arguments to use
Use four arguments:
./bin/main.exe InputFile         TimeStepInSeconds TotalDurationInEarthYears Debug
./bin/main.exe ./input/input.txt 86400             1.2                       1

5. check the output files in the output folders
ls -lh ./output/
less ./output/Earth.csv

6. Check that you really get close to an ellipse for Earth.
open ./output/Earth.csv in Excel
select all (both columns with Control+A)
from the menu choose Insert
then choose Chart
then choose Scatter (if you don't see, make the window wider)
then choose Marked Scatter
If you see a straight line, it is not good. 

You can do all these in one step
make && ./bin/main.exe ./input/input.txt 86400             1.2                       1 && ls -lh ./output/ && less ./output/Earth.csv

*****************************************************************************************************************
**************************** The package description ************************************************************
*****************************************************************************************************************

input      - input files (input.txt, tasks.txt)
output     - ouput files
include    - the header files, i.e. the .h files
src        - the source files, i.e. the .cxx files 
obj        - the files obtained in compilation, i.e. the .o files
lib        - the files obtained from linking when making a shared library, i.e. the .so files
bin        - the files obtained from linking when making an executable, i.e. the .exe files
setup.sh   - the file that need to be source after compilation and before running the .exe so that the .so are taken into account
Makefile   - the makefile that does the compilation and linking of shared libraries and executables
README.txt - the file that gives the description of what the packages does, how to run it
