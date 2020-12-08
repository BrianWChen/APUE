#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define LEFT    30000000
#define RIGHT   30000200

int main()
{
    //pid_t pid;
    int i, j, mark;

    for (i = LEFT; i <= RIGHT; i++)
    {
        mark = 1;
        for (j = 2; j < i / 2; j++)
        {
            if (i % j == 0)
            {
                mark = 0;
                break;
            }
        }
        if (mark)
            printf("%d is a primer\n", i);
    }

    /*pid = fork();

    if (pid < 0)
    {
        perror("fork()");
        exit(1);
    }

    if (pid == 0)
    {
        printf("[%d]Child is working!\n", getpid());
    }
    else
    {
        printf("[%d]Parent is working!\n", getpid());
    }

    printf("[%d]End!\n", getpid());*/

    exit(0);
}
