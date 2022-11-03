#include<stdio.h>
int main(){
    int n,m,i,j,k,y,alloc[20][20],max[20][20],avail[50],ind=0;
    printf("enter the no of process : ");
    scanf("%d",&n);
    printf("\nenter the no of resorces : ");
    scanf("%d",&m);
    printf("enter the alloacation matrix :\n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&alloc[i][j]);
        }
    }
    printf("enter the max matrix : \n");
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            scanf("%d",&max[i][j]);
        }
    }
    printf("enter the available matrix : \n");
    for(i=0;i<m;i++){
        scanf("%d",&avail[i]);
    }


    int finish[20],safesequence[20],work[20],need[20][20];
    //calculating need matrix 
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            need[i][j]=max[i][j]-alloc[i][j];
        }
    }
    printf("The NEED MATRIX is : \n");
    for(i=0;i<n;i++){
        printf("\n");
        for(j=0;j<m;j++){
            printf("%d  ",need[i][j]);
        }
    }

    for(i=0;i<m;i++){
        work[i]=avail[i];
    }

    for(i=0;i<n;i++){
        finish[i]=0;
    }

    for(k=0;k<n;k++){
        for(i=0;i<n;i++){
            if(finish[i]==0){
                int flag=0;
                for(j=0;j<m;j++){
                    if(need[i][j]>work[j]){
                        flag=1;
                        break;
                    }
                }
                if(flag==0){
                    safesequence[ind++]=i;
                    for(y=0;y<m;y++){
                        work[y]+=alloc[i][y];
                    }
                    finish[i]=1;
                }
            }
        }
    }
    printf("\nthe following safe sequence is : \n");
    for(i=0;i<n;i++){
        printf("p%d\t",safesequence[i]);
    }


    return 0;
}