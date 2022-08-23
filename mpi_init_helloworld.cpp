#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv){
  
  cout<<"Initialize...\n";
  MPI_Init(&argc, &argv);
  cout<<"hello!\n";
  MPI_Finalize();
  cout<<"Finished.\n";
  return 0;
}