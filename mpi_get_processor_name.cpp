#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char** argv){

  cout<<"Initialize...\n";
  MPI_Init(&argc, &argv);
  int resultlen = 128;
  char* name = new char[resultlen];
  MPI_Get_processor_name(name, &resultlen);
  cout<<"This process is running on node "<<name<<".\n";
  free(name);
  MPI_Finalize();
  cout<<"Finished.\n";
  return 0;
}