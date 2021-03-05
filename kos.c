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
int getpid() {return 20;}
int getuid() {return 20;}
int getpwuid() {return 20;}
int fsync() {return -1;}
int ftruncate() {return -1;}
