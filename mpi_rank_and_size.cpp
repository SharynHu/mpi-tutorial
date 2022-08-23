#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv){
  MPI_Comm comm = MPI_COMM_WORLD;
  MPI_Init(&argc, &argv);
  int size;
  MPI_Comm_size(comm, &size);
  int rank;
  MPI_Comm_rank(comm, &rank);
  int resultlen = 128;
  char* name = new char[resultlen];
  MPI_Get_processor_name(name, &resultlen);
  cout<<"node "<<name<<"is rank "<<rank<<" out of size "<<size<<"\n";
  MPI_Finalize();
  return 0;
}