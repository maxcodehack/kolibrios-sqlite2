#include <sys/kos.h>
#include <stdlib.h>

void __chkstk_ms() {}

char *getcwd(char *buf, unsigned size)
{
    if(buf == NULL){
       if((buf = malloc(size))==NULL)
       {
            return NULL;
       }
    }
    __asm__ __volatile__(
    "int $0x40"
    ::"a"(30),"b"(2),"c"(buf), "d"(size));
    return(buf);
}
void sleep(int a) {
	kos_Delay(a);
}


struct proc_info info__;
int getpid() {
	kos_ProcessInfo((char*)&info__);
	return info__.ID;
}
int getuid() {return 42;}

int getpwuid() {return 20;} //???
int fsync(int _fd) {return 0;}
int ftruncate() {return -1;} //! http://websvn.kolibrios.org/filedetails.php?repname=Kolibri+OS&path=%2Fprograms%2Fdevelop%2Flibraries%2Fmenuetlibc%2Fsrc%2Flibc%2Fcompat%2Funistd%2Fftruncat.c
