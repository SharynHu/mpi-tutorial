#include <iostream>
#include <fstream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv){
  MPI_Comm comm = MPI_COMM_WORLD;
  ofstream myfile;
  myfile.open("test.txt");
  MPI_Init(&argc, &argv);
  int rank;
  MPI_Comm_rank(comm, &rank);
  if(rank==0){
    myfile<<"This is hello from rank 0.\n";
  }
  if(rank==1){
    myfile<<"This is hello from rank 1.\n";
  }
  myfile.close();
  MPI_Finalize();
  return 0;
}