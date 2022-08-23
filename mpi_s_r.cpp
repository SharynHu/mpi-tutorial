#include <iostream>
#include <mpi.h>

int main(int argc, char ** argv){
    MPI_Init(NULL, NULL);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int * data = (int *)malloc(sizeof(int)*world_size);

    data[world_rank] = world_rank;

    std::cout<<world_rank<<":";

    for(int i=0;i<world_size;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;

    int dest1 = (world_rank-1+world_size)%world_size;
	int dest2 = (world_rank+1)%world_size;
    MPI_Send(data+world_rank,1, MPI_FLOAT, dest1, 0, MPI_COMM_WORLD);
    MPI_Send(data+world_rank,1, MPI_FLOAT, dest2, 0, MPI_COMM_WORLD);
    int source1 = (world_rank-1+world_size)%world_size;
    int source2 = (world_rank+1)%world_size;
	MPI_Recv(data+source1, 1, MPI_FLOAT, source1, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
	MPI_Recv(data+source2, 1, MPI_FLOAT, source2, MPI_ANY_TAG, MPI_COMM_WORLD, MPI_STATUS_IGNORE);

    std::cout<<world_rank<<":";
    for(int i=0;i<world_size;i++){
        std::cout<<data[i]<<" ";
    }
    
    std::cout<<std::endl;
    MPI_Finalize(); 
    return 0;
}