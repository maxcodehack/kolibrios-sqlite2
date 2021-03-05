#include <sys/kos.h>
void __chkstk_ms() {}
#define NULL 0
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
int getpid() {return 20;} //! http://websvn.kolibrios.org/filedetails.php?repname=Kolibri+OS&path=%2Fprograms%2Fdevelop%2Flibraries%2Fmenuetlibc%2Fsrc%2Flibc%2Fposix%2Funistd%2Fgetpid.c
int getuid() {return 42;}
int getpwuid() {return 20;} //???
int fsync() {return 0;}
int ftruncate() {return -1;} //! http://websvn.kolibrios.org/filedetails.php?repname=Kolibri+OS&path=%2Fprograms%2Fdevelop%2Flibraries%2Fmenuetlibc%2Fsrc%2Flibc%2Fcompat%2Funistd%2Fftruncat.c
