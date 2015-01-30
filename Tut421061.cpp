#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
int main() {
int n = 1 ;
int childpid ;
childpid = fork() ;
printf("In process %d, n=%d\n", getpid(), n) ;
if ( childpid > 0 ) {
n = 10 ;
sleep(1) ; // try removing this line
}
else n = 20 ;
printf("In process %d, n=%d\n", getpid(), n) ;
if ( childpid > 0 )
wait(NULL) ;
return 0 ; }
