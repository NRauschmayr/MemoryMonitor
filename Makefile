.PHONY: clean
INCLUDES=-I/cvmfs/atlas.cern.ch/repo/sw/python/2.6.5p2/x86_64-slc5-gcc43-opt/python/include/python2.6 -I./rapidjson-master/include
CXXFLAGS=-Wl,--no-as-needed -std=c++0x -fPIC

all: PyMemoryMonitor.so MemoryMonitor

clean:
	rm -f *~ PyMemoryMonitor MemoryMonitor *.o

PyMemoryMonitor.so: MemoryMonitor.cc PyGetMemoryValues.cc
	g++ $(CXXFLAGS) -shared $(INCLUDES) -o $@ $^

MemoryMonitor: MemoryMonitor.cc
	g++  $(CXXFLAGS) -lpthread $(INCLUDES) -o $@ $^
 
