#include<stdio.h>

int main(){
    int bt[10],at[10],tat[10],wt[10],ct[10];
    int n,sum=0;

    float totTAT=0,totWT=0;

    printf("Enter the number of process:");
    scanf("%d",&n);
    printf("Enter the total arrival times and burst times\n");
    for (int i = 0; i < n; i++)
    {
       printf("Enter the arrival time of process[%d]: ",i+1);
       scanf("%d",&at[i]);
       printf("Enter the burst time of process[%d]",i+1);
       scanf("%d",&bt[i]);
    }
    // find ct 
    for (int i = 0; i < n; i++)
    {
        sum= sum+bt[i];
        ct[i] =sum;
    }
    // find tat 
    for (int i = 0; i < n; i++)
    {
        tat[i]=ct[i]-at[i];
        totTAT += tat[i];
    }
    // find wt 
    for (int i = 0; i < n; i++)
    {
        wt[i] = tat[i]-bt[i];
        totWT += wt[i];
    }
    printf("SOlution......\n");
    printf("P#\tAT\tBT\tCT\tTAT\tWT\n\n");
    // result print 
    for (int i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t",i+1,at[i],bt[i],ct[i],tat[i],wt[i]);
        printf("\n");
    }
    
}