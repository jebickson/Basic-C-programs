#include<stdio.h>
#include<conio.h>
#define max 25
void main(){
    int frag[max],b[max],i,j,nb,nf,temp,lowest=10000;
    static int bf[max],ff[max];
    //clrscr();
    printf("\nEnter the number of blocks:");
    scanf("%d",&nb);
    printf("Enter the number of files:");
    scanf("%d",&nf);
    printf("\nEnter the size of the blocks:\n");
    for(i=1;i<=nb;i++){
        printf("Block %d:",i);
        scanf("%d",&b[i]);
    }
    printf("\nEnter the size of the files:\n");
    for(i=1;i<=nf;i++){
        printf("File %d:",i);
        scanf("%d",&ff[i]);
    }
    for(i=1;i<=nb;j++){
        for(j=1;j<-nb;j++){
            if(bf[j]!=1){
                temp=b[j]-ff[i];
                if(temp>=0)
                if(lowest>temp){
                    ff[i]=j;
                    lowest=temp;
                }
            }
        }
        frag[i]=lowest;
        bf[ff[i]]=1;
        lowest=10000; // Reset lowest for the next file
    }
    printf("\nFile No\tFile Size\tBlock No\tBlock Size\tFragment");
    for(i=1;i<=nf&&ff[i]!=0;i++)
        printf("\n%d\t%d\t\t%d\t\t%d\t\t%d", i, ff[i], ff[i], b[ff[i]], frag[i]);
    
}