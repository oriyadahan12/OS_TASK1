#include <stdio.h>



void rec() {
    rec();
}

void zna()//zero not allowed
{
    int i = 1;
    int j = i/0;
}




void files()
{
int *p = (int*)0xdeadbeef;
    *p = 42;//error because this address isn't exist//
}

int main()
{
    //rec();
    //zna();
    files();
    return 0;
}