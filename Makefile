### Writed by maxcodehack

CC = kos32-gcc
LD = kos32-ld

## Path to /contrib/sdk
SDK_DIR = /media/maxim/E22406D62406AE1B/SVNKOS/contrib/sdk

CFLAGS = -c -fno-ident -O2 -fomit-frame-pointer -fno-ident -U__WIN32__ -U_Win32 -U_WIN32 -U__MINGW32__ -UWIN32  
LDFLAGS = -static -S -nostdlib -T $(SDK_DIR)/sources/newlib/app.lds --image-base 0

INCLUDES = -I$(SDK_DIR)/sources/newlib/libc/include -I.
LIBPATH = -L$(SDK_DIR)/lib -L/home/autobuild/tools/win32/mingw32/lib


##########################

OBJS = kos.o attach.o auth.o btree.o btree_rb.o build.o copy.o date.o delete.o encode.o expr.o func.o hash.o insert.o main.o opcodes.o os.o pager.o parse.o pragma.o printf.o random.o select.o table.o tokenize.o trigger.o update.o util.o vacuum.o vdbeaux.o vdbe.o where.o

##########################

default: $(OBJS)
	ar rcs libsqlite.a $(OBJS)

%.o : %.c Makefile
	$(CC) $(CFLAGS) $(INCLUDES) -o $@ $<

clean:
	rm -rf $(OBJS)
