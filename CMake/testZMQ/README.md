On MacOS Mojave this worked:
brew install zmq
brew install cppzmq

But On MacOS Catalina this did not work: brew install cppzmq.
So compiled with CMake following the instructions from
https://github.com/zeromq/cppzmq
so compiled and installed libzmq and then cppzmq

and in this repo we test that indeed ZMQ is present on a MacOS
