TARGET=stack
CC=g++
DEBUG=-g
OPT=-O0
WARN=-Wall
PTHREAD=-pthread
CCFLAGS=$(DEBUG) $(OPT) $(WARN) $(PTHREAD) -pipe
LD=g++
LDFLAGS=$(PTHREAD) -export-dynamic
OBJS= main.o controller.o region.o testdriver.o
all: $(OBJS)
	$(LD) -o $(TARGET) $(OBJS) $(LDFLAGS)
 
main.o: src/main.cpp
	$(CC) -c $(CCFLAGS) src/main.cpp -o main.o

controller.o: src/controller/controller.cpp
	$(CC) -c $(CCFLAGS) src/controller/controller.cpp  -o controller.o
 
region.o: src/TestDriver/Region.cpp
	$(CC) -c $(CCFLAGS) src/TestDriver/Region.cpp  -o region.o

testdriver.o: src/TestDriver/TestDriver.cpp
	$(CC) -c $(CCFLAGS) src/TestDriver/TestDriver.cpp  -o testdriver.o

delete:
	rm -vf $(TARGET)

clean:
	rm -vf *.o