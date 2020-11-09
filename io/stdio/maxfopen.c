#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main ()
{
    int count = 0;
    FILE *fp = NULL;

    while(1)
    {
        fp = fopen("tmp", "w");
        if (fp == NULL) {
            perror("fopen()");
            break;
        }
        count++;
    }
    fprintf(stderr, "max files: %d", count);
    exit(0);
}
