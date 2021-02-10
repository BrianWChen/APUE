#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/uio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

#define BUFSIZE 1024

int main(int argc, char **argv)
{
    int sfd, dfd = 1, len, ret, pos;
    char buf[BUFSIZE];

    if (argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }

    do
    {
        sfd = open(argv[1], O_RDONLY);
        if( sfd < 0 )
        {
            if (errno !=  EINTR)
            {
                perror("open()");
                exit(1);
            }
        }
    } while  (sfd < 0);

    while(1)
    {
        len = read(sfd, buf, BUFSIZE);
        if (len < 0)
        {
            if (errno == EINTR)
                continue;
            
            perror("read");
            break;
        }
        if (len == 0)
        {
            break;
        }
        
        pos = 0;

        while (len > 0)
        {
            ret = write(dfd, buf+pos, len);
            if (ret < 0)
            {
                if (errno == EINTR)
                    continue;

                perror("write");
                break;
            }
            pos += ret;
            len -= ret;
        }
    }

    close(sfd);

    exit(0);
}
