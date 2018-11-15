#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <string.h>
#include <sys/wait.h>

int main(int argc, char *argv[])
{

	char *line; size_t buffer = 100; char *bin_ = "/bin/"; char *user = 
	"/usr/bin/"; char *the_args[100]; line = (char *)malloc(buffer * 
	sizeof(char));

    if (argc == 1)
    {
        while (1)
        {
            printf("wish> ");
            getline(&line, &buffer, stdin);

            rm_line(line);
            int i = 0;

            char *token = strtok(line, " ");
            char *array[5] = {NULL, NULL, NULL, NULL, NULL};
            while (token != NULL)
            {
                the_args[i] = token;

                i = i + 1;
                token = strtok(NULL, " ");
            }
            for (int j = 1; j < i; j++)
            {
                array[j] = the_args[j];
            }

            char *first_path = malloc(strlen(bin_) + strlen(the_args[0]) + 1);
            strcat(first_path, bin_);

            strcat(first_path, the_args[0]);
            char *path2 = malloc(strlen(user) + strlen(the_args[0]) + 1);
            strcat(path2, user);
            strcat(path2, the_args[0]);

            if (strcmp(the_args[0], "exit") == 0)
            {
                exit(0);
            }
            else if (strcmp(the_args[0], "cd") == 0)
            {
                if (chdir(the_args[1]) == 0)
                {
                    printf("%s\n", "you're here");
                }
                else
                {
                    printf("%s\n", "unavailable");
                }
            }
            else
            {
                pid_t pid = fork();
                if (pid == 0)
                {
                    if (access(first_path, X_OK) == 0)
                    {
                        array[0] = first_path;
                        execv(first_path, array);
                    }
                    else if (access(path2, X_OK) == 0)
                    {
                        array[0] = path2;
                        execv(path2, array);
                    }
                    else
                    {
                        printf("%s\n", "no access");
                    }
                }
                else
                {
                    wait(NULL);
                }
            }
        }
    }
    else if (argc == 2)
    {
        FILE *fp = fopen(argv[1], "r");
        if (fp == NULL)
        {
            printf("Empty");
            return 0;
        }
        else
        {
            while (getline(&line, &buffer, fp) != -1)
            {

                rm_line(line);
                int i = 0;

                char *token = strtok(line, " ");
                char *array[5] = {NULL, NULL, NULL, NULL, NULL};
                while (token != NULL)
                {
                    the_args[i] = token;

                    i = i + 1;
                    token = strtok(NULL, " ");
                }
                for (int j = 1; j < i; j++)
                {
                    array[j] = the_args[j];
                }

                char *first_path = malloc(strlen(bin_) + strlen(the_args[0]) + 1);
                strcat(first_path, bin_);

                strcat(first_path, the_args[0]);
                char *path2 = malloc(strlen(user) + strlen(the_args[0]) + 1);
                strcat(path2, user);
                strcat(path2, the_args[0]);

                if (strcmp(the_args[0], "exit") == 0)
                {
                    exit(0);
                }
                else if (strcmp(the_args[0], "cd") == 0)


                {
                    if (chdir(the_args[1]) == 0)
                    {
                        printf("%s\n", "you're here");
                    }
                    else


                    {
                        printf("%s\n", "unavailable");
                    }
                }
                else


                {
                    pid_t pid = fork();
                    if (pid == 0)
                    {
                        if (access(first_path, X_OK) == 0)
                        {
                            array[0] = first_path;
                            execv(first_path, array);
                        }


                        else if (access(path2, X_OK) == 0)
                        {
                            array[0] = path2;
                            execv(path2, array);
                        }


                        else
                        {
                            printf("%s\n", "no access");
                        }
                    }
                    else
                    {
                        wait(NULL);
                    }
                }
            }
        }

        fclose(fp);
    }
}

void rm_line(char *ll) { char length = strlen(ll); if (ll[length - 1] 
== '\n') { ll[length - 1] = '\0'; }
}
