#include <iostream>
#include <unistd.h>
#include <dirent.h>

using namespace std;

int main()
{
    DIR *Dir;
    struct dirent *DirEntry;
    Dir = opendir("C:/");

    while(DirEntry=readdir(Dir))
       cout << DirEntry->d_name <<endl;

}
