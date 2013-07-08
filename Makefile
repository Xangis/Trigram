# PixelSwapper makefile.  Requires wxWidgets.
# by default, wx-config from the PATH is used
WX_CONFIG := wx-config

# Main executable file
PROGRAM = TrigramGenerator

# Object files
OBJECTS = maindlg.o wxapp.o

CXX = $(shell $(WX_CONFIG) --cxx)

.SUFFIXES:	.o .cpp

.cpp.o :
	$(CXX) -c `$(WX_CONFIG) --cxxflags` -o $@ $<

all:    $(PROGRAM)

$(PROGRAM):	$(OBJECTS)
	$(CXX) -o $(PROGRAM) $(OBJECTS) `$(WX_CONFIG) --libs`

clean: 
	rm -f *.o $(PROGRAM)
