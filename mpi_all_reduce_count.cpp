#include <iostream>
#include <mpi.h>
#include <stdlib.h>

// MPI_Allreduce_c − Combines values from all processes and distributes the result back to all processes

int main(int argc, char ** argv){
    MPI_Init(NULL, NULL);
    int world_size, world_rank;

    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    
    float myrandom[5], sumrandom[5];
    for(int i=0;i<5;i++){
        myrandom[i] = (float)rand()/(float)RAND_MAX;
    }
    
    MPI_Allreduce(myrandom, sumrandom, 5, MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);

    for(int i=0;i<5;i++){
        std::cout<<sumrandom[i]<<" ";
    }
    std::cout<<std::endl;
    MPI_Finalize();
}