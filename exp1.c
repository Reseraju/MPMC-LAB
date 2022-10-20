#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 30
void fcfs(){
    int i,n,at[max],bt[max],wt[max],tat[max],temp[max];
    float awt=0,atat=0;
    printf("enter the no of processes in order of arrival time : ");
    scanf("%d",&n);
    printf("enter the AT & BT of proceses :\n");
    printf("AT BT\n");
    for(i=0;i<n;i++){
        scanf("%d%d",&at[i],&bt[i]);
    }
    temp[0]=0;
    printf("process\tAT\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        temp[i+1]=temp[i]+bt[i];
        wt[i]=temp[i]-at[i];
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("%d\t %d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
    }
    printf("printing garn chart : \n\n");
    for(i=0;i<n;i++){
        printf("     p%d\t",i+1);
    }
    printf("\n");
    for(i=0;i<=n;i++){
        printf("%d\t",temp[i]);
    }
    
    awt=awt/n;
    atat=atat/n;
    printf("\n\naverage waiting time is : %f\n",awt);
    printf("average turn around time : %f",atat);

}


void sjf(){
    int i,j,n,p[max],bt[max],wt[max],tat[max],pos,t,temp,sum=0;
    float awt=0,atat=0;
    printf("enter the no of processes : ");
    scanf("%d",&n);
    printf("enter the bust time :\n");
    for(i=0;i<n;i++){
        printf("p%d\t",i+1);
        scanf("%d",&bt[i]);
        p[i]=i+1;
    }
    //sum of burst time for printing last value of gantt chart :)
    for(i=0;i<n;i++){
        sum+=bt[i];
    }

    // sorting acc to burst time 
    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(bt[j]<bt[pos]){
                pos = j;
            }
        }

        temp = bt[i];
        bt[i]= bt[pos];
        bt[pos]= temp;

        temp = p[i];
        p[i]= p[pos];
        p[pos]= temp;

    }

    printf("process\tBT\tWT\tTAT\n");
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
            
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("p%d\t%d\t%d\t%d\t\n",p[i],bt[i],wt[i],tat[i]);

    }


    //gantt chart
    printf("printing gantt chart : \n\n");
    for(i=0;i<n;i++){
        printf("   p%d\t",p[i]);
    }
    printf("\n");
    for(i=0;i<=n;i++){
        if(i==n){
            printf("%d\t",sum);
        }
        else{
            printf("%d\t",wt[i]);
        }
    }



    awt=awt/n;
    atat=atat/n;
    printf("\n\naverage waiting time is : %f\n",awt);
    printf("average turn around time : %f",atat);
}


void roundrobin(){
    int i,n,qt,count=0,temp,sq=0,bt[10],wt[10],tat[10],rem_bt[10],sum=0;
    float awt=0,atat=0;
    printf("Enter the no of processes : ");
    scanf("%d",&n);
    printf("Enter the burst time : ");
    for(i=0;i<n;i++){
        printf("p[%d] : ",i+1);
        scanf("%d",&bt[i]);
        rem_bt[i]=bt[i];
    }
    printf("enter the quantum time : ");
    scanf("%d",&qt);
    printf("\nGantt chart : \n");
    while(1){
        for(i=0,count=0;i<n;i++){
            temp=qt;
            if(rem_bt[i]==0){
                count++;
                continue;

            }
            if(rem_bt[i]>qt){
                rem_bt[i]=rem_bt[i]-qt;
            }
            else{
                if(rem_bt[i]>=0){
                    temp=rem_bt[i];
                    rem_bt[i]=0;
                }
            }
            sq=sq+temp;
            tat[i]=sq;

            //printing gantt chart

            printf("%d\t",sq);
        }
        if(n==count){
            break;
        }
    }
    

    printf("\nprocess\tBT\tWT\tTAT\t");
    for(i=0;i<n;i++){
        wt[i]=tat[i]-bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("\np%d\t%d\t%d\t%d",i+1,bt[i],wt[i],tat[i]);
    }

    awt=awt/n;
    atat=atat/n;
    printf("\n\nthe average waiting time is : %f\n",awt);
    printf("the average turnaround time is : %f\n",atat);
}


void priority(){
    int i,j,n,bt[20],wt[20],pr[20],p[20],tat[20],temp,pos,t[20],sum=0;
    float atat=0,awt=0;
    printf("enter the no. of processes : ");
    scanf("%d",&n);
    printf("enter the burst time and priority :\n");
    printf("process BT Priority\n");
    for(i=0;i<n;i++){
        printf("p%d    ",i+1);
        scanf("%d%d",&bt[i],&pr[i]);
        p[i]=i+1;
    }

    //sum of burst time for printing last value of gantt chart :)
    for(i=0;i<n;i++){
        sum+=bt[i];
    }

    for(i=0;i<n;i++){
        pos=i;
        for(j=i+1;j<n;j++){
            if(pr[j]<pr[pos]){
                pos=j;
            }
        }
        temp=pr[i];
        pr[i]=pr[pos];
        pr[pos]=temp;

        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;

        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;

        
    }

    printf("process\tBT\tWT\tTAT\n");
    wt[0]=0;
    for(i=0;i<n;i++){
        wt[i]=0;
        tat[i]=0;
        for(j=0;j<i;j++){
            wt[i]=wt[i]+bt[j];
        }
        tat[i]=wt[i]+bt[i];
        awt=awt+wt[i];
        atat=atat+tat[i];
        printf("p%d\t%d\t%d\t%d\t\n",p[i],bt[i],wt[i],tat[i]);

    }

    //gantt chart
    printf("\nGantt chart : \n\n");
    for(i=0;i<n;i++){
        printf("   p%d\t",p[i]);
    }
    printf("\n");
    for(i=0;i<=n;i++){
        if(i==n){
            printf("%d\t",sum);
        }
        else{
            printf("%d\t",wt[i]);
        }
    }


    awt=awt/n;
    atat=atat/n;
    printf("\n\naverage WT : %f\n",awt);
    printf("average TAT : %f",atat);
}


int main(){
    int n;
    printf("CPU SHEDULING ALGORITHMS");
    printf("\n****************************");
    while(1){
        printf("\n1.FCFS\n2.SJF\n3.ROUND ROBIN\n4.PRIORITY\n5.EXIT");
        printf("\nEnter your choice : ");
        scanf("%d",&n);
        switch(n){
            case 1:
                fcfs();
                break;

            case 2:
                sjf();
                break;
            case 3:
                roundrobin();
                break;
            case 4:
                priority();
                break;
            case 5:
                exit(0);
                break;
        }
    }
    return 0;
}