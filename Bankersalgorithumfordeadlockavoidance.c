#include<stdio.h>
#include<conio.h>

struct da
{
    int max[10],al[10],need[10],before[10],after[10];
}
p[10];

void main(){
    int i,j,k,l,r,n,tot[10],av[10],cn=0,cz=0,temp=0,c=0;
    //clrscr();
    printf("\nEnter the number of processes: ");
    scanf("%d",&n);
    printf("\nEnter the number of resources: ");
    scanf("%d",&r);
    for(i=0;i<n;i++){
        printf("PROCESS %d\n",i+1);
        for(j=0;j<r;j++){
           printf("MAXIMUM VALUE FOR RESOURCE%d:",j+1);
           scanf("%d",&p[i].max[j]);
        }
        for(j=0;j<r;j++){
            printf("ALLOCATION FOR RESOURCE %d:",j+1);
            scanf("%d",&p[i].al[j]);
            p[i].need[j] = p[i].max[j] - p[i].al[j];
        }
    }
    for(i=0;i<r;i++){
        printf("TOTAL NUMBER OF RESOURCE %d:",i+1);
        scanf("%d",&tot[i]);
    }
    for(i=0;i<r;i++){
        for(j=0;j<n;j++)
        temp=temp+p[j].al[i];
        av[i]=tot[i]-temp;
        temp=0;
    }
    printf("\n\tRESOURCEALLOCATEDNEEDTOAVAILABLE");
    for(i=0;i<n;i++){
        printf("\n p%d\t",i+1);
        for(j=0;j<r;j++)
        printf("%d",p[i].max[j]);
        printf("\t");
        for(j=0;j<r;j++)
        printf("%d",p[i].al[j]);
        printf("\t");
        for(j=0;j<r;j++)
        printf("%d",p[i].need[j]);
        printf("\t");
        for(j=0;j<r;j++){
            if(i==0)
            printf("%d",tot[j]);
        }
        printf("\t");
        for(j=0;j<r;j++){
            if(i==0)
            printf("%d",av[j]);
        }
    }
    printf("\n\n\t AVAILABLE BEFORE\t AVAILABLE AFTER");
    for(l=0;l<n;l++){
        for(i=0;i<n;i++){
            for(j=0;j<r;j++){
                if(p[i].need[j]>av[j])cn++;
                if(p[i].max[j]==0)cz++;
            }
            if(cn==0&&cz!=r){
                for(j=0;j<r;j++){
                    p[i].before[j]=av[j]-p[i].need[j];
                    p[i].after[j]=p[i].before[j]+p[i].max[j];
                    av[j]=p[i].after[j];
                    p[i].max[j]=0;
                }
                printf("\nP%d\t",i+1);
                for(j=0;j<r;j++)
                printf("%d",p[i].before[j]);
                printf("\t");
                for(j=0;j<r;j++)
                printf("%d",p[i].after[j]);
                cn=0;
                cz=0;
                c++;
                break;
            }else{
                cn=0;
                cz=0;
            }
        }
    }
    if(c==n)
    printf("\nTHE ABOVE SEQUENCE IS SAFE SEQUENCE");
    else
    printf("\nDEADLOCK OCCURRED");
    getch();
}