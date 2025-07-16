#include<stdio.h>
#include<conio.h>
struct process
{
    int pid;
    int bt;
    int wt;
    int tt;
}
p[10],temp;
int main(){
    int i,j,n,totwt,tottt;
    float avg1,avg2;
    //clrscr();
    printf("Enter the number of processes: ");
    scanf("%d",&n);
    for(i=0;i<n;i++){
       p[i].pid=i;
       printf("Enter the burst time of process %d: ",i+1);
       scanf("%d",&p[i].bt);
    }
    for(i=0;i<n-1;i++){
        for(j=i+1;j<n;j++){
            if(p[i].bt>p[j].bt){
                temp.pid=p[i].pid;
                p[i].pid=p[j].pid;
                p[j].pid=temp.pid;
                temp.bt=p[i].bt;
                p[i].bt=p[j].bt;
                p[j].bt=temp.bt;
            }
        }
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
        avg1=totwt/n;
        avg2=tottt/n;
        printf("\nAVG1=%f\tAVG2=%f\n",avg1,avg2);
        getch();
        return 0;
    }
}
