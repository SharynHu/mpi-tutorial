#include <iostream>
#include <mpi.h>

int main(int argc, char ** argv){
    MPI_Init(NULL, NULL);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int * data = (int *)malloc(sizeof(int)*world_size*2);

    data[2*world_rank] = 2*world_rank;
    data[2*world_rank+1] = 2*world_rank+1;
    std::cout<<world_rank<<":";

    for(int i=0;i<2*world_size;i++){
        std::cout<<data[i]<<" ";
    }
    std::cout<<std::endl;
    for(int i=0;i<world_size;i++){
        MPI_Bcast(data+2*i, 2, MPI_INT, i, MPI_COMM_WORLD);
    }
    MPI_Barrier(MPI_COMM_WORLD);
    std::cout<<world_rank<<":";
    for(int i=0;i<2*world_size;i++){
        std::cout<<data[i]<<" ";
    }
    
    std::cout<<std::endl;
    MPI_Finalize(); 
    return 0;
}