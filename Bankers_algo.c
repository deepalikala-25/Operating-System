
#include<stdio.h>
int main(){
    int n,r,count=0,safe_found=0;
    printf("Enter number of process : \n");
    scanf("%d",&n);
    printf("Enter number of resources : \n");
    scanf("%d",&r);

    int allocated[n][r];
    int maximum[n][r];
    int need[n][r];
    int available[r];
    int done[n];
    int safe_sequence[n];

    printf("Enter the allocated matrix : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            scanf("%d",&allocated[i][j]);
        }
    }

    printf("Enter the maximum matrix : \n");
    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            scanf("%d",&maximum[i][j]);
        }
    }

    printf("Enter the available resources : \n");
    for(int j=0;j<r;j++){
        scanf("%d",&available[j]);
    }

    for(int i=0;i<n;i++){
        done[i]=0;
    }

    for(int i=0;i<n;i++){
        for(int j=0;j<r;j++){
            need[i][j]=maximum[i][j]-allocated[i][j];
        }
    }

    while(count<n){
        safe_found=0;

        for(int i=0;i<n;i++){
            if(done[i]==0){
                int safe=1;

                for(int j=0;j<r;j++){
                    if(need[i][j]>available[j]){
                        safe=0;
                        break;
                    }
                }

                if(safe){
                    for(int z=0;z<r;z++){
                        available[z]=available[z]+allocated[i][z];
                    }

                    safe_sequence[count++]=i;
                    done[i]=1;
                    safe_found=1;
                }
            }
        }

        if(!safe_found){
            printf("\nSystem is not in a safe state or deadlock may occur\n");
            return 0;
        }
    }

    printf("\nSystem is in a safe state\nSafe Sequence : ");
    for(int i=0;i<n;i++){
        printf("P%d ",safe_sequence[i]);
    }

    printf("\n");
    return 0;
}
