all: run.exe

run.exe: planet.o main.o
	@echo "Start: g++ planet.o main.o -o run.exe"
	@g++ planet.o main.o -o run.exe
	@echo "End  : g++ planet.o main.o -o run.exe"

planet.o: planet.h planet.C
	@echo "Start: g++ -c planet.C"
	@g++ -c planet.C
	@echo "End  : g++ -c planet.C"

main.o: main.h main.C
	@echo "Start: g++ -c main.C"
	@g++ -c main.C
	@echo "End  : g++ -c main.C"

clean:
	@rm -f *.o
	@rm -f *.exe
	@rm -f *~
