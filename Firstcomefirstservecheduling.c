#include<stdio.h>

struct process {
    int pid;
    int bt; // burst time
    int wt; // waiting time
    int tt; // turnaround time
} 
p[10];
int main(){
    int i,n,totwt,tottt,avg1,avg2;
    //clrscr();
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
         p[i].pid=i;
         printf("Enter the burst time of process");
         scanf("%d",&p[i].bt);
     }
     p[1].wt=0;
     p[1].tt=p[1].bt+p[1].wt;
     i=2;
        while(i<=n){
            p[i].wt=p[i-1].bt+p[i-1].wt;
            p[i].tt=p[i].bt+p[i].wt;
            i++;
        }
    i=1;
    totwt=tottt=0;
    printf("\nProcess id\tbt\twt\ttt\n");
    while(i<=n){
        printf("%d\t\t%d\t%d\t%d\n",p[i].pid,p[i].bt,p[i].wt,p[i].tt);
        totwt=p[i].wt+totwt;
        tottt=p[i].tt+tottt;
        i++;
    }
    avg1=totwt/n;
    avg2=tottt/n;
    printf("\nAVG1=%d\tAVG2=%d\n",avg1,avg2);
    //getch();
    return 0;
}