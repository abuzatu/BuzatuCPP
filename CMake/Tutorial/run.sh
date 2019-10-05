#!/usr/bin/env bash
# it can only be executed, do not allow to source
# and crash in a controlled way if some unbound variable is used

[[ $- == *i* ]] && echo "Shell Interactive" || echo "Shell Not interactive"
if [[ $0 != "$BASH_SOURCE" ]]; then
    echo "ERROR: I'm a script forcing you to execute. Don't source me!" >&2
    return 1
else
    # if I am OK to execute, force that the script stops if variables are not defined
    # this catches bugs in the code when you think a variable has value, but it is empty
    set -eu
fi

#############################################################################################
### Configuration
#############################################################################################

DEBUG="0"
VERBOSE="0"

# build
DO_CMAKE_AND_MAKE="1"
DO_ONLY_MAKE="0"
DO_EXIT_AFTER_COMPILATION="0"

# run
DO_RUN="1"
DO_CTEST="1"
DO_CTEST_D_EXPERIMENTAL="0"

# install
DO_INSTALL="0"
DO_BUILD_BINARY_DISTRIBUTION="0"
DO_BUILD_SOURCE_DISTRIBUTION="0"

#############################################################################################
### Compilation
#############################################################################################

# cmake + make
if [[ ${DO_CMAKE_AND_MAKE} == "1" ]]; then
    COMMAND="cd code && rm -rf build && mkdir build && cd build && pwd && cmake ../source && make && ls -lh && cd .. && cd .."
    echo ""
    echo "COMMAND=${COMMAND}"
    eval ${COMMAND}    
fi

# only make
if [[ ${DO_ONLY_MAKE} == "1" ]]; then
    COMMAND="make -C code/build"
    echo ""
    echo "COMMAND=${COMMAND}"
    eval ${COMMAND}
fi

# exit, safer to be on while we are compiling for the first time, to move to running only once we expect compilation to work
if [[ ${DO_EXIT_AFTER_COMPILATION} == "1" ]]; then
    COMMAND="exit"
    echo ""
    echo "COMMAND=${COMMAND}"
    eval ${COMMAND}
fi

#############################################################################################
### Run and Test
#############################################################################################

# run our executable once
if [[ ${DO_RUN} == "1" ]]; then
    COMMAND="./code/build/Tutorial 3.0"
    echo ""
    echo "COMMAND=${COMMAND}"
    eval ${COMMAND}
fi

# run tests by running our executable several times as defined in CMakeLists.txt
if [[ ${DO_CTEST} == "1" ]]; then
    COMMAND="cd code && cd build && ctest && cd .. && cd .."
    echo ""
    echo "COMMAND=${COMMAND}"
    eval ${COMMAND}
fi

# run tests and put the dashboard on Kitware's public dashboard (but was not able to publish there for me)
if [[ ${DO_CTEST_D_EXPERIMENTAL} == "1" ]]; then
    COMMAND="cd code && cd build && ctest -D Experimental && cd .. && cd .."
    echo ""
    echo "COMMAND=${COMMAND}"
    eval ${COMMAND}
fi

#############################################################################################
### Install (locally) and build distributions to install on other machines (binary or source)
#############################################################################################

# install locally
if [[ ${DO_INSTALL} == "1" ]]; then
    COMMAND="cd code && cd build && make install && cd .. && cd .."
    echo ""
    echo "COMMAND=${COMMAND}"
    eval ${COMMAND}
fi

# do build binary distribution
if [[ ${DO_BUILD_BINARY_DISTRIBUTION} == "1" ]]; then
    COMMAND="cd code && cd build && cpack --config CPackConfig.cmake && cd .. && cd .."
    echo ""
    echo "COMMAND=${COMMAND}"
    eval ${COMMAND}
fi

# do build binary distribution
if [[ ${DO_BUILD_SOURCE_DISTRIBUTION} == "1" ]]; then
    COMMAND="cd code && cd build && cpack --config CPackSourceConfig.cmake && cd .. && cd .."
    echo ""
    echo "COMMAND=${COMMAND}"
    eval ${COMMAND}
fi

#############################################################################################
### Done
#############################################################################################

echo "Done ./run.sh!"
