#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv)
{
    int init = MPI_Init(&argc,&argv);
    int processNumber, numberID;
    init = MPI_Comm_rank(MPI_COMM_WORLD, &processNumber);
    init = MPI_Comm_size(MPI_COMM_WORLD, &numberID);

    if(processNumber % 2 == 0){
        cout<<"I am even"<<endl;
    }
    else{
        cout<<"I am odd"<<endl;
    }

    init = MPI_Finalize();
    return 0;
}
