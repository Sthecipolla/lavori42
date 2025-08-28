#include <unistd.h>


int child_do(char *string, int *pipe, char **argv)
{
    close(pipe[0]);
    dup2(pipe[1], 1);
    close(pipe[1]);
    execvp(string, argv);
}

int father_do(char *string)
{
    close(pipe[1]);
    dup2(pipe[0], 0);
    close(pipe[0]);
}

void picoshell(char **argv)
{
    int i;
    int fd[2];
    int pipe[2];
    int id;
    int std_out;

    i = 0;
    while(argv[i] != NULL)
    {
        pipe(pipe);
        id = fork();
        if (id == 0)
        {
            child_do(argv[i], pipe, argv);
        }
        else
        {
            father_do();
        }
        i++;
    }
    id = fork();
    if (id == 0)
    {
        child_do(argv[i], pipe, argv);
    }
    else
    {
        father_do();
    }
}

int main()
{

}