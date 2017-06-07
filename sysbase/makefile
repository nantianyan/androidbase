objects = RefBase.o Threads.o  Timers.o sched_policy.o SharedBuffer.o Unicode.o String16.o String8.o Static.o VectorImpl.o

#SRC = $(wildcard ${DIR_SRC}/*.c)  
#OBJ = $(patsubst %.c,${DIR_OBJ}/%.o,$(notdir ${SRC})) 
#headfiles = AndroidThreads.h Compat.h Mutex.h RefBase.h stdatomic.h thread_defs.h Thread.h Timers.h atomic.h Condition.h graphics.h mylog.h sched_policy.h StrongPointer.h ThreadDefs.h threads.h TypeHelpers.h SharedBuffer.h String16.h Unicode.h String8.h

CC = g++
AR = ar
#CC = arm-linux-gnueabi-g++
#AR = arm-linux-gnueabi-ar

#CFLAGS =-fPIC
CFLAGS =-g -I./include -I./safe-iop #for gdb
# note that pthread is not lpthread !!
LDFLAGS =-pthread -lsysbase -L. -L./safe-iop

test:test.o libsysbase.a
	$(CC) -o test test.o $(LDFLAGS)

libsysbase.a:$(objects) $(headfiles)
	$(AR) r $@ $(objects)

#libsysbase.so:$(objects) $(headfiles)
#	$(CC) -shared -o $@ $(objects)

test.o:test.cpp
	$(CC) -c $(CFLAGS) $< -o $@


$(objects):%.o:%.cpp
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	-rm -f *.o libsysbase.a test
