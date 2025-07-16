#include<stdio.h>
#include<conio.h>

struct process {
    int pid;
    int bt; // burst time
    int wt; // waiting time
    int tt; // turnaround time
};
int main(){
    struct process x[10],p[30];
    int i,j,k,tot=0,m,n;
    float wttime=0, tottime=0, a1, a2;
    //clrscr();
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        x[i].pid=i;
        printf("Enter the burst time of process");
        scanf("%d",&x[i].bt);
        tot=tot+x[i].bt;
    }
    printf("\nTotal burst time is %d\n", tot);
    p[0].tt=0;
    k=1;
    printf("\nEnter the Time Slice:\t");
    scanf("%d",&m);
    for(j=0;j<tot/m;j++){
        for(i=0;i<n;i++){
            if(x[i].bt !=0){
                p[k].pid=i;
                if(x[i].bt-m<0){
                    p[k].wt=p[k-1].tt;
                    p[k].bt=x[i].bt;
                    p[k].wt+x[i].bt;
                    x[i].bt=0;
                    k++;
                }
                else{
                    p[k].wt=p[k-1].tt;
                    p[k].tt=p[k].wt+m;
                    x[i].bt=x[i].bt-m;
                    k++;
                }
                printf("\nProcess id \twt\ttt");
                for(int i=1;i<k;i++){
                    printf("\n%d\t\t%d\t%d", p[i].pid, p[i].wt, p[i].tt);
                    wttime=wttime+p[i].wt;
                    tottime=tottime+p[i].tt;
                    a1=wttime/n;
                    a2=tottime/n;
                }
                printf("\nAverage waiting time is %f", a1);
                printf("\nAverage turnaround time is %f", a2);
                getch();
                return 0;
            }
        }
    }
}
