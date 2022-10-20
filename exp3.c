#include<stdio.h>
#include<stdlib.h>

//fcfs
void fcfs(){
    int i,n,rq[100],totalHeadMov=0,initial;
    printf("enter the no of request : ");
    scanf("%d",&n);
    printf("enter the request sequence : \n");
    for(i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }
    printf("enter the initial head position : ");
    scanf("%d",&initial);
    for(i=0;i<n;i++){
        totalHeadMov=totalHeadMov + abs(rq[i]-initial);
        initial=rq[i];
    }
    printf("The total head movement is : %d",totalHeadMov);
}

//scan
void scan(){
    int i,j,n,rq[100],thm=0,initial,size,prev;
    printf("enter the no of request : ");
    scanf("%d",&n);
    printf("enter the request sequence : \n");
    for(i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }
    printf("enter the initial head position : ");
    scanf("%d",&initial);
    printf("enter the previous head position : ");
    scanf("%d",&prev);
    printf("enter total disk size : ");
    scanf("%d",&size);

    

    //sorting rq[]
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(rq[j]>rq[j+1]){
                int temp;
                temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
        }
    }
    int index;
    for(i=0;i<n;i++){
        if(initial<rq[i]){
            index=i;
            break;
        }
    }

    //logic

    if(initial>prev){
        for(i=index;i<n;i++){
            thm=thm+abs(rq[i]-initial);
            initial=rq[i];
        }
        thm=thm+abs(size-rq[i-1]-1);
        initial=size-1;
        for(i=index-1;i>=0;i--){
            thm=thm+abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    else{
        for(i=index-1;i>=0;i--){
            thm=thm+abs(rq[i]-initial);
            initial=rq[i];
        }
        thm=thm+abs(rq[i+1]-0);
        initial=0;
        for(i=index;i<n;i++){
            thm=thm+abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    printf("total head movement is : %d",thm);
}

//cscan
void cscan(){
    int i,j,n,rq[100],thm=0,initial,size,prev;
    printf("enter the no of request : ");
    scanf("%d",&n);
    printf("enter the request sequence : \n");
    for(i=0;i<n;i++){
        scanf("%d",&rq[i]);
    }
    printf("enter the initial head position : ");
    scanf("%d",&initial);
    printf("enter the prev head position : ");
    scanf("%d",&prev);
    printf("enter total disk size : ");
    scanf("%d",&size);
    

    //sorting rq[]
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            if(rq[j]>rq[j+1]){
                int temp;
                temp=rq[j];
                rq[j]=rq[j+1];
                rq[j+1]=temp;
            }
        }
    }
    int index;
    for(i=0;i<n;i++){
        if(initial<rq[i]){
            index=i;
            break;
        }
    }

    //logic

    if(initial>prev){
        for(i=index;i<n;i++){
            thm=thm+abs(rq[i]-initial);
            initial=rq[i];
        }
        thm=thm+abs(size-rq[i-1]-1);

        initial=0;
        thm=thm+abs(size-1-0);
        for(i=0;i<=index-1;i++){
            thm=thm+abs(rq[i]-initial);
            initial=rq[i];
        }
        
    }
    else{
        for(i=index-1;i>=0;i--){
            thm=thm+abs(rq[i]-initial);
            initial=rq[i];
        }
        thm=thm+abs(rq[i+1]-0);

        initial=size-1;
        thm=thm+abs(size-1-0);
        for(i=n-1;i>=index;i--){
            thm=thm+abs(rq[i]-initial);
            initial=rq[i];
        }
    }
    printf("total head movement is : %d",thm);
}


int main(){
    int i,j,n;
    printf("CPU SHEDULING");
    printf("\n**************");
    while(1){
        printf("\n1.FCFS\n2.SCAN\n3.CSCAN\n4.EXIT");
        printf("\nenter your choice : ");
        scanf("%d",&n);
        switch(n){
            case 1:
            fcfs();
            break;

            case 2:
            scan();
            break;

            case 3:
            cscan();
            break;

            case 4: 
            exit(0);
            break;
        }
    }
    return 0;
}