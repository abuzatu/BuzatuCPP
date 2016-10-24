WHERETORUN=Mac
#WHERETORUN=Linux

ifeq ($(WHERETORUN),Mac)
	PACKAGE=/Users/abuzatu/Work/Code/TutorialCPP/Course/4/Solution
	# create .o file means compilation (here appears the -I for the location of the headers)
	# so use these flags
	CFLAGS=-fPIC -O2 -pipe -Wall -W -Woverloaded-virtual -std=c++11
	# create .exe or .so means linking (here appears -L when using shared libraries)
	# these are the two stages of what we call compilation 
	# so use these flags
	#LFLAGS=-O2 -mmacosx-version-min=10.10 -m64 -lm -ldl -rdynamic
	LFLAGS=-O2 -mmacosx-version-min=10.10 -m64 -lm # -lm to include the library math
	# when creating a shared object for mac you use this
	SOFLAGS=-dynamiclib -single_module
	COMPILER=clang++
else ifeq ($(WHERETORUN),Linux)
	# for Glasgow with Linux
	PACKAGE=/afs/phas.gla.ac.uk/user/a/abuzatu/code/TutorialCPP/Course/4/Solution
	CFLAGS=-fPIC # -O2 -Wall -fPIC -Wno-deprecated-declarations -m64
	LFLAGS= # -O2 -m64  -pthread -lm -ldl -rdynamic
	SOFLAGS=-shared # -rdynamic 
	COMPILER=g++
else
	COMPILER=changeCompiler
endif

all: ./bin/main.exe 

# main
./bin/main.exe: ./lib/libVector3D.so ./lib/libBody.so ./lib/libSystem.so ./lib/libOutput.so ./obj/main.o
	@echo "Start ./bin/main.exe"
	@${COMPILER} ./obj/main.o ${LFLAGS} -L${PACKAGE}/lib -lVector3D -lBody -lSystem -lOutput -o ./bin/main.exe
	@echo "End   ./bin/main.exe"

./obj/main.o: ./include/main.h ./src/main.cxx
	@echo "Start ./obj/main.o"
	@${COMPILER} -c ./src/main.cxx ${CFLAGS} -I${PACKAGE}/include -o ./obj/main.o
	@echo "End   ./obj/main.o"

# Vector3D
./lib/libVector3D.so: ./obj/Vector3D.o
	@echo "Start ./lib/libVector3D.so"
	@${COMPILER} ./obj/Vector3D.o ${SOFLAGS} -o ./lib/libVector3D.so
	@echo "End   ./lib/libVector3D.so"

./obj/Vector3D.o: ./include/Vector3D.h ./src/Vector3D.cxx
	@echo "Start ./obj/Vector3D.o"
	@${COMPILER} -c ./src/Vector3D.cxx ${CFLAGS} -I${PACKAGE}/include -o ./obj/Vector3D.o
	@echo "End   ./obj/Vector3D.o"

# Body
./lib/libBody.so: ./obj/Body.o
	@echo "Start ./lib/libBody.so"
	@${COMPILER} ./obj/Body.o ${LFLAGS} ${SOFLAGS} -L${PACKAGE}/lib -lVector3D -o ./lib/libBody.so
	@echo "End   ./lib/libBody.so"

./obj/Body.o: ./include/Body.h ./src/Body.cxx
	@echo "Start ./obj/Body.o"
	@${COMPILER} -c ./src/Body.cxx ${CFLAGS} -I${PACKAGE}/include -o ./obj/Body.o
	@echo "End   ./obj/Body.o"

# System
./lib/libSystem.so: ./obj/System.o
	@echo "Start ./lib/libSystem.so"
	@${COMPILER} ./obj/System.o ${LFLAGS} ${SOFLAGS} -L${PACKAGE}/lib -lVector3D -lBody -o ./lib/libSystem.so
	@echo "End   ./lib/libSystem.so"

./obj/System.o: ./include/System.h ./src/System.cxx
	@echo "Start ./obj/System.o"
	@${COMPILER} -c ./src/System.cxx ${CFLAGS} -I${PACKAGE}/include -o ./obj/System.o
	@echo "End   ./obj/System.o"

# Output
./lib/libOutput.so: ./obj/Output.o
	@echo "Start ./lib/libOutput.so"
	@${COMPILER} ./obj/Output.o ${LFLAGS} ${SOFLAGS} -L${PACKAGE}/lib -lVector3D -lBody -lSystem -o ./lib/libOutput.so
	@echo "End   ./lib/libOutput.so"

./obj/Output.o: ./include/Output.h ./src/Output.cxx
	@echo "Start ./obj/Output.o"
	@${COMPILER} -c ./src/Output.cxx ${CFLAGS} -I${PACKAGE}/include -o ./obj/Output.o
	@echo "End   ./obj/Output.o"

clean:
	@echo "Start clean"
	@rm -f ./obj/*.o
	@rm -f ./bin/*.exe
	@rm -f ./lib/*.so
	@rm -f ./C/*~
	@rm -f ./include/*~
	@rm -f *~
	@echo "End   clean"
