CC = g++
AR = ar
#CC = arm-linux-gnueabi-g++
#AR = arm-linux-gnueabi-ar

CFLAGS=-I.

libsafe_iop.a:safe_iop.o
	$(AR) r $@ $(objects)

safe_iop.o:safe_iop.c
	$(CC) -c $(CFLAGS) $< -o $@

clean:
	-rm -f *.o libsafe_iop.a
