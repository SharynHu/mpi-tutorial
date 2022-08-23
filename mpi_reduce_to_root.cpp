#include <iostream>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char ** argv){
    MPI_Init(NULL, NULL);
    int world_size, world_rank;

    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    
    float myrandom, sumrandom;

    myrandom = (float)rand()/(float)RAND_MAX;
    std::cout<<"The random number is "<<myrandom<<".\n";
    MPI_Reduce(&myrandom, &sumrandom, 1, MPI_FLOAT, MPI_SUM, 1, MPI_COMM_WORLD);
    
    if(world_rank==1) {
        std::cout<<"The reduced sum is "<<sumrandom<<".\n";
    }

    MPI_Finalize();
}