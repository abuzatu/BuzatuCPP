Exercise 2 simply moves code in different files, so that it is easier to follow. The class will be defined in its own file. That will change our compilation process. 

What was done before in one command now needs to be down in two steps, the first step is compiling, the second step is linking. 

First we compile planet.C and obtain a .o file, an object. Notice the "-c" flag for this step.

g++ -c planet.C 

This will produce planet.o.

Next we compile main.C This is done after planet.C, since the main function uses the class Planet and the functions of type compare that are in planet.C. 

g++ -c main.C 

This will produce main.o

Now we are ready to link the two .o files to produce the output that we can execute. Now there is no "-c", just as before when we were producing the output.

g++ planet.o main.o

This produces a.out, just as before, which we can execute with 

./a.out

If we want to have our own name for the executable:
g++ planet.o main.o -o run.exe
./run.exe

We can also run them on one line

g++ planet.o main.o -o run.exe && ./run.exe

We can also print the output to a text file

g++ planet.o main.o -o run.exe && ./run.exe >& run.log

We can read the log file with 

*********

If we change one of these four input files, we need to run again the entire chaing to compile, which has three steps.

g++ -c planet.C 
g++ -c main.C 
g++ planet.o main.o -o run.exe 

Can we automatize the process? Yes, that is where Makefile comes into play.
Watch video about Makefile at Software Carpentry.
https://www.youtube.com/watch?v=buxd7FcyAU4

When run the contents of Makefile, we just type make
make

Now open Makefile and read step by step what it does. The syntax of Make is

output_file: input_file_1 input_file_2 ...
	     comand_to_run

If any of the inputs does not exist, or has a newer timestamp than the desired output file (i.e. has been changed in the meantime), then the command_to_run is executed, which usually produces the output_file. But before that, and here is the key of make, it checks if there is a rule for input_file_1 and if it depends on other files and if those have been changed, and if so, it first updates input_file_1 and then updates output_file. That allows that with one command to update the entire structure, as exemplified below. 

all:run.exe

if the file all does not exist, create it. Actually it is not created, as there is no command_to_run. But before I run the command that does not exist, let me know on what file "all" depends. It is "run.exe". Does it exist? If not, let us create it. Or if it is exists, maybe it must be updated? How can I decide that? In both cases, I need a rule for run.exe and files that it depends on. 

run.exe: planet.o main.o
	@g++ planet.o main.o -o run.exe

We can add printing to know when a compilation is actually done.
run.exe: planet.o main.o
	@echo "Start: g++ planet.o main.o -o run.exe"
	@g++ planet.o main.o -o run.exe
	@echo "End  : g++ planet.o main.o -o run.exe"

Notice for the command we first need a tab, and then @.

But before we run this command, we check the two input files, so we need rules for each.

planet.o: planet.h planet.C
	@echo "Start: g++ -c planet.C"
	@g++ -c planet.C
	@echo "End  : g++ -c planet.C"

main.o: main.h main.C
	@echo "Start: g++ -c main.C"
	@g++ -c main.C
	@echo "End  : g++ -c main.C"


Let's remove run.exe

rm -f run.exe
ls

It's gone. Now let's compile again everthing.

make

We see it has appeared again.
ls
./run.exe

It all runs well.

We we run make again.
make

Nothing happens. make has seen that nothing has changed. That is the power of make. It changes only when needed.

Now let's go and make simulate we made a change to 2plenet.C. We simulate that by touching the file, which changes its timestamp to current.

touch planet.C

Start: g++ -c planet.C
End  : g++ -c planet.C
Start: g++ planet.o main.o -o run.exe
End  : g++ planet.o main.o -o run.exe

Notice how only planet and run.exe have been recreated, but there was no need for main. 

Now we want to remove the files produces. We add a new action called clean, and when we run make clean, it will do the actions shown there. It will not depend on any file. The actions there would be to romove our .o, .exe, *~ files.

make clean
make
./run.exe
