#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv)
{
    /*int init = MPI_Init(&argc, &argv);
    int processNumber, number;
    er = MPI_Comm_rank(MPI_COMM_WORLD,&processID);
    er = MPI_Comm_size(MPI_COMM_WORLD,&numberProcess);
    cout<<"I am process "<<processID<<" of "<<numberProcess<<endl;
    er = MPI_Finalize();*/

    int rank, size;

    MPI::Init(argc, argv);
    rank = MPI::COMM_WORLD.Get_rank();
    size = MPI::COMM_WORLD.Get_size();

    cout << "I am a process of " << rank << " and size " << size << endl;

    MPI::Finalize();
    return 0;
}
