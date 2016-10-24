all: ./bin/run.exe

./bin/run.exe: ./obj/planet.o ./obj/main.o
	@echo "Start: g++ ./obj/planet.o ./obj/main.o -o ./bin/run.exe"
	@g++ ./obj/planet.o ./obj/main.o -o ./bin/run.exe
	@echo "End  : g++ ./obj/planet.o ./obj/main.o -o ./bin/run.exe"

./obj/planet.o: ./h/planet.h ./C/planet.C
	@echo "Start: g++ -c ./C/planet.C -I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o ./obj/planet.o" 
	@g++ -c ./C/planet.C -I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o ./obj/planet.o
	@echo "End  : g++ -c ./C/planet.C -I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o ./obj/planet.o"

./obj/main.o: ./h/main.h ./C/main.C
	@echo "Start: g++ -c ./C/main.C -I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o ./obj/main.o"
	@g++ -c ./C/main.C -I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o ./obj/main.o
	@echo "End  : g++ -c ./C/main.C -I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o ./obj/main.o"

clean:
	@rm -f ./obj/*.o
	@rm -f ./bin/*.exe
	@rm -f ./C/*~
	@rm -f ./h/*~
	@rm -f *~
