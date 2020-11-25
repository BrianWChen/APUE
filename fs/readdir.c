#include <stdio.h>
#include <stdlib.h>
#include <glob.h>
#include <dirent.h>

#define PAT "/etc"

int main()
{
	DIR *dp;
	struct dirent *cur;

    dp = opendir(PAT);
    if (dp == NULL)
    {
    	perror("opendir()");
    }

    while((cur = readdir(dp)) != NULL)
    {
    	puts(cur->d_name);
    }

    closedir(dp);

	exit(0);
}