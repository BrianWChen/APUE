#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <shadow.h>

int main(int argc, char **argv)
{
    char *input_pass;
    char *crypted_pass;
    struct spwd *shadowline;

    if (argc < 2)
    {
        fprintf(stderr, "Usage...\n");
        exit(1);
    }

    input_pass = getpass("Password:");

    shadowline = getspnam(argv[1]);

    crypted_pass = crypt(input_pass, shadowline->sp_pwdp);

    if (strcmp(shadowline->sp_pwdp, crypted_pass) == 0)
		puts("ok!");
    else
    	puts("failed!");

    exit(0);
}

