#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

static int64_t mydu(const char *path)
{
	struct stat statres;

	if (lstat(path, &statres) < 0)
	{
		perror("lstat()");
		exit(1);
	}

	if (!S_ISDIR(statres.st_mode))
	{
		return statres.st_blocks / 2;
	}

	return 0;
}

int main(int argc, char **argv)
{
	if (argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }

    printf("%ll\n", mydu(argv[1]));

    exit(0);
}