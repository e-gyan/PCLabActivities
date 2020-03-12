#include <iostream>
#include <mpi.h>

using namespace std;

int main(int argc, char **argv)
{
    int sum, Size, Rank, msg;

    MPI_Init(&argc, &argv);

    MPI_Comm_rank(MPI_COMM_WORLD, &Rank);
    MPI_Comm_size(MPI_COMM_WORLD, &Size);

    if(Rank != 0){
        MPI_Recv(&msg, 1, MPI_INT, Rank - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process " << Rank << " received $ " << msg << " from process " << Rank - 1 << endl;
	}

	else{
        msg = 1000;
	}

	MPI_Send(&msg, 1, MPI_INT, (Rank + 1) % Size, 0, MPI_COMM_WORLD);

	if(Rank == 0){
        MPI_Recv(&msg, 1, MPI_INT, Size - 1, 0, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        cout << "Process " << Rank << " received $ " << msg << " from process " << Size - 1 << endl;
	}

    /*if(Rank != 0){
		MPI::COMM_WORLD.Recv(&msg, 1, MPI::INT, Rank-1, 0, MPI::Status());
		cout << "Process " << Rank << " received $ " << msg << " from process "<< Rank-1 <<endl;
	}

	else{
		msg = 1000;
	}

	MPI::COMM_WORLD.Send(&msg, 1, MPI::INT, (Rank + 1) % Size, 0);

	if(Rank == 0){
		MPI::COMM_WORLD.Recv(&msg, 1, MPI::INT, Size - 1, 0, MPI::Status());
		cout << "Process " << Rank << " received $ " << msg <<" from process "<< Size - 1 << endl;
	}*/

    MPI_Finalize();
    return 0;
}
