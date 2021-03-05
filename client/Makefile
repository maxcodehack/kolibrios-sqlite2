### Writed by maxcodehack

CC = kos32-gcc
LD = kos32-ld

## Path to /contrib/sdk
SDK_DIR = /media/maxim/E22406D62406AE1B/SVNKOS/contrib/sdk

CFLAGS = -c -fno-ident -O2 -fomit-frame-pointer -fno-ident -U__WIN32__ -U_Win32 -U_WIN32 -U__MINGW32__ -UWIN32  
LDFLAGS = -static -S -nostdlib -T $(SDK_DIR)/sources/newlib/app.lds --image-base 0

INCLUDES = -I$(SDK_DIR)/sources/newlib/libc/include -I..
LIBPATH = -L$(SDK_DIR)/lib -L/home/autobuild/tools/win32/mingw32/lib -L..

OBJS = shell.o

default: $(OBJS)
	kos32-ld $(LDFLAGS) $(LIBPATH) --subsystem console -o sqlite $(OBJS) -lgcc -lsqlite -lc.dll 
	objcopy sqlite -O binary

%.o : %.c Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $<

clean:
	rm -rf $(OBJS)
