
CC = g++ -std=c++17

EXECUTABLE = pinfo

SOURCES = main.cpp \
		  core/core.cpp \
		  core/utilities/FileReader.cpp \
		  core/utilities/ProcFileReader.cpp \
		  core/utilities/StringProcessing.cpp \
		  core/InfoGetters/AbstractInfoGetter.cpp \
		  core/InfoGetters/PPIDGetter.cpp \
		  core/utilities/DirectoryChecker.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ 

.cpp.o:
	$(CC) -c $< -o $@

clean: 
	rm $(OBJECTS)