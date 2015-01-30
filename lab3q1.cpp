
// Compute the factorial of a number by spawning new
// processes instead of performing recursive calls.
// Each child sends its partial result to the parent
// via a pipe.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <errno.h>
int main(int argc, char **argv)
{
    int n = atoi(argv[1]) ; // read argument from command line
    int superdaddy = getpid() ;
    int p[2] ; // pipe
    int output, savedoutput, result1, result, cpid ;
    output = STDOUT_FILENO ;
    while ( 1 )
        { // every new child must go through the while body again
            if ( n == 1 )
            { // base case
                if ( write(output,&n,sizeof(n)) < 0 ) {
                    perror(NULL) ;
                    return 1 ;
                }
                return 0 ;
            }
            savedoutput = output ; // useful when 2 parent spawns two children
            n -- ; // argument for child
            if ( pipe(p) < 0 )
            { // build pipe to return result
                perror(NULL) ;
                return 1 ;
            }
            output = p[1] ; // useful when parent spawns 2 children
            cpid = fork() ; // create child to compute factorial(n-1)
            if ( cpid == 0 )
            {
                if (close(p[0])<0)
                { // close unused pipe ends
                    perror(NULL) ;
                    return 1 ;
                }
                continue ;
            }
            else if (cpid<0)
            {
                perror(NULL) ;
                return 1 ;
            }
            if (close(p[1])<0)
            { // close unused pipe ends
                perror(NULL) ;
                return 1 ;
            }
            break ;
        }
    if ( read(p[0],&result1,sizeof(result1)) < 0 )
    {
        perror(NULL) ;
        return 1 ;
    }
    result = result1*(n+1) ; // factorial(n) = n*factorial(n-1)
    if ( getpid()==superdaddy ) // the original parent prints the result
    printf("Result: %d\n", result) ;
    else if ( write(savedoutput,&result,sizeof(result)) < 0 ) {
        // each process will send the computed partial result to its own parent
        perror(NULL) ;
        return 1 ;
    }
    wait(NULL) ; // wait for the child to terminate (avoid zombies)
    return 0 ;
}
