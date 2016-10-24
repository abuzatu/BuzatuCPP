#all: run.exe
all: ./bin/run.exe

run.exe: 2planet.o 2main.o
	@echo "Start: g++ 2planet.o 2main.o -o run.exe"
	@g++ 2planet.o 2main.o -o run.exe
	@echo "End  : g++ 2planet.o 2main.o -o run.exe"

2planet.o: 2planet.h 2planet.C
	@echo "Start: g++ -c 2planet.C"
	@g++ -c 2planet.C
	@echo "End  : g++ -c 2planet.C"

2main.o: 2main.h 2main.C
	@echo "Start: g++ -c 2main.C"
	@g++ -c 2main.C
	@echo "End  : g++ -c 2main.C"

clean:
	@rm -f *.o
	@rm -f *.exe
	@rm -f *~

./bin/run.exe: ./lib/lib2planet.so ./obj/2main.o
	@clang++ ./obj/2main.o -O2 -mmacosx-version-min=10.10  -L/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/lib -l2planet  -o ./bin/run.exe

./lib/lib2planet.so: ./obj/2planet.o
	@clang++ ./obj/2planet.o -O2 -mmacosx-version-min=10.10 -dynamiclib -single_module  -o ./lib/lib2planet.so

./obj/2planet.o: 2planet.C 2planet.h
	@clang++ -c 2planet.C -O2 -pipe -Wall -W -Woverloaded-virtual -std=c++11 -o ./obj/2planet.o

./obj/2main.o: 2main.C 2main.h
	@clang++  -c 2main.C -O2 -pipe -Wall -W -Woverloaded-virtual -std=c++11 -o ./obj/2main.o

