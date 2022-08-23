#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv){
  MPI_Comm comm = MPI_COMM_WORLD;
  MPI_Init(&argc, &argv);
  int rank;
  MPI_Comm_rank(comm, &rank);
  if(rank==0){
    cout<<"This is hello from rank 0.\n";
  }
  MPI_Finalize();
  return 0;
}