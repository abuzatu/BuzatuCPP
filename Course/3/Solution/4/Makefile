all: ./bin/run.exe

./bin/run.exe: ./lib/libplanet.so ./obj/main.o
	@echo "Start g++ ./obj/main.o -L/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/4/lib -lplanet -o ./bin/run.exe"
	@g++ ./obj/main.o -L/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/4/lib -lplanet -o ./bin/run.exe
	@echo "End   g++ ./obj/main.o -L/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/4/lib -lplanet -o ./bin/run.exe"

./lib/libplanet.so: ./obj/planet.o
	@echo "Start g++ ./obj/planet.o -dynamiclib -o ./lib/libplanet.so"
	@g++ ./obj/planet.o -dynamiclib -o ./lib/libplanet.so
	@echo "End   g++ ./obj/planet.o -dynamiclib -o ./lib/libplanet.so"

./obj/planet.o: ./h/planet.h ./C/planet.C
	@echo "Start g++ -c ./C/planet.C -I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o ./obj/planet.o"
	@g++ -c ./C/planet.C -I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o ./obj/planet.o
	@echo "End   g++ -c ./C/planet.C -I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o ./obj/planet.o"

./obj/main.o: ./h/main.h ./C/main.C
	@echo "Start g++ -c ./C/main.C -I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o ./obj/main.o"
	@g++ -c ./C/main.C -I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o ./obj/main.o
	@echo "End   g++ -c ./C/main.C -I/Users/abuzatu/Work/Code/TutorialCPP/Course/3/Solution/3/h -o ./obj/main.o"

clean:
	@echo "Start clean"
	@rm -f ./obj/*.o
	@rm -f ./bin/*.exe
	@rm -f ./lib/*.so
	@rm -f ./C/*~
	@rm -f ./h/*~
	@rm -f *~
	@echo "End   clean"
