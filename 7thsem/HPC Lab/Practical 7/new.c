#include<mpi.h>
#include<stdio.h>

int main(int argc,char *argv[]){
    int a = 0, b=1,myId, opponentsId;
    MPI_Init(&argc,&argv);
    MPI_Comm_rank(MPI_COMM_WORLD, &myId);
    MPI_Status status;
    opponentsId = (myId+1)%2;
    int ping_pong_count = 0;
    while(ping_pong_count < 50){

        if(ping_pong_count%2 == myId){
            ping_pong_count++;
            MPI_Send(&ping_pong_count,1,MPI_INT,opponentsId,0,MPI_COMM_WORLD);
            printf("Data sent by process %d of loop %d\n", myId,ping_pong_count);
        }
        else{
            MPI_Recv(&ping_pong_count,1,MPI_INT,opponentsId,0,MPI_COMM_WORLD,&status);
            printf("Received the data from %d to %d of loop %d\n",status.MPI_SOURCE,myId,ping_pong_count);
        }
     
    }

    MPI_Finalize();

}