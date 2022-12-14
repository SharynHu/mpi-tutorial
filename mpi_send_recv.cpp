#include <stdio.h>
#include <mpi.h>

int main(int argc, char **argv){
    // Find out rank, size
    printf("This is an MPI program.\n");
    MPI_Init(&argc, &argv);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    int world_size;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int number;
    if(world_rank == 0) {
        number = -1;
        MPI_Send(&number, 1, MPI_INT, 1, 0, MPI_COMM_WORLD);
    } else if (world_rank == 1) {
        MPI_Recv(&number, 1, MPI_INT, 0, 0, MPI_COMM_WORLD,
            MPI_STATUS_IGNORE);
        printf("Process 1 received number %d from process 0\n",
           number);
    }
    MPI_Finalize();
    printf("Terminated.\n");
}


/*
This is an MPI program.
This is an MPI program.
Process 1 received number -1 from process 0
Terminated.
Terminated.
*/

/*
The MPI_Send() and MPI_Recv() are synchronous communication primitives :
MPI_Send will not return until the destination processor has received the message.
MPI_Recv will not return a message has been received.
*/