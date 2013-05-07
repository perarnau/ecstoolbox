 /* Execute a program, passing it its rank and comm_worl_size as parameters.
 */
#include <stdio.h>
#include <unistd.h>
#include <mpi.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
	MPI_Init(&argc, &argv);
	int comm_size, comm_rank;
	MPI_Comm_size(MPI_COMM_WORLD, &comm_size);
	MPI_Comm_rank(MPI_COMM_WORLD, &comm_rank);
	// execute argv[1], with comm_rank, comm_size as argument
	char rankstr[80];
	char sizestr[80];
	snprintf(rankstr,80,"%d",comm_rank);
	snprintf(sizestr,80,"%d",comm_size);
	pid_t pid = fork();
	if(pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}
	
	if(pid == 0)
	{
		return execlp(argv[1],argv[1],rankstr,sizestr,(char *)NULL);
	}
	else 
	{	
		int status;
		pid_t child = waitpid(pid,&status,0);
		if(child == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		MPI_Finalize();
		return 0;
	}
}
