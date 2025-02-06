// My first c program

/* Program SUM- EVEN*/
#include<stdio.h>
int main(){
    int n, i, sum , num , rem;
    printf("\nEnter the number of elements :");
    scanf("%d",&n);
    i = 1;
    sum = 0;
    while(i <=n){
        printf("\nEnter data number %d :",i);
        scanf("%d",&num);
        rem = num % 2;

        if(rem == 0)
              sum = sum + num ;
        i = i +1;
    }
    printf("\nThe sum is %d",sum);
}