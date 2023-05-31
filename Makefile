
CC = g++ -std=c++17

EXECUTABLE = pinfo

SOURCES = main.cpp \
		  core/core.cpp \
		  core/GetterMaster.cpp \
		  core/utilities/FileReader.cpp \
		  core/utilities/ProcFileReader.cpp \
		  core/utilities/StringProcessing.cpp \
		  core/utilities/DirectoryChecker.cpp \
		  core/InfoGetters/PPIDGetter.cpp \
		  core/InfoGetters/AbstractInfoGetter.cpp \
		  core/InfoGetters/NameGetter.cpp \
		  core/InfoGetters/StateGetter.cpp \
		  core/InfoGetters/UIDGetter.cpp \
		  core/InfoGetters/ThreadsGetter.cpp \
		  core/InfoGetters/ThreadsPIDGetter.cpp \
		  core/InfoGetters/PriorityGetter.cpp \
		  core/InfoGetters/PolicyGetter.cpp \
		  core/InfoGetters/IsSystemGetter.cpp \
		  core/InfoGetters/DaemonGetter.cpp \
		  core/InfoGetters/FlagsGetter.cpp

OBJECTS = $(SOURCES:.cpp=.o)

all: $(SOURCES) $(EXECUTABLE)
	
$(EXECUTABLE): $(OBJECTS) 
	$(CC) $(OBJECTS) -o $@ 

.cpp.o:
	$(CC) -c $< -o $@

clean: 
	rm $(OBJECTS)