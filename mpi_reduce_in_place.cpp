#include <iostream>
#include <mpi.h>
#include <stdlib.h>

int main(int argc, char ** argv){
    MPI_Init(NULL, NULL);
    int world_size, world_rank;

    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    
    int nrandoms = 5;
    float myrandoms[nrandoms];
    for(int i=0;i<nrandoms;i++){
        myrandoms[i] = (float)rand()/(float)RAND_MAX;
    }
    
    // MPI_IN_PLACE takes place of the send buffer 
    MPI_Allreduce(MPI_IN_PLACE, myrandoms, nrandoms, MPI_FLOAT, MPI_SUM, MPI_COMM_WORLD);
    
    if(world_rank==0){
        for(int i=0;i<nrandoms;i++){
            std::cout<<"The "<<i<<"th reduced sum is "<<myrandoms[i]<<".\n";
        }
    }
    MPI_Finalize();
}