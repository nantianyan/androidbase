
CC = g++
AR = ar
CFLAGS =-g -I../include -I../include/media/stagefright/foundation/ -I../../sysbase/include/
LDFLAGS =-L../../sysbase/ -lsysbase -pthread

objects= AString.o ABitReader.o AStringUtils.o AHandler.o ALooperRoster.o ALooper.o hexdump.o AMessage.o ABuffer.o base64.o ParsedMessage.o ANetworkSession.o

test:test.o libfoundation.a
	    $(CC) -o test test.o libfoundation.a $(LDFLAGS)

test.o:test.cpp
	    $(CC) -c $(CFLAGS) $< -o $@

libfoundation.a:$(objects)
	    $(AR) r $@ $(objects)

$(objects):%.o:%.cpp
	    $(CC) -c $(CFLAGS) $< -o $@

clean:
	    -rm -f *.o libfoundation.a test

