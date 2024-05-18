#include<stdio.h>
int main(){
    int i,j,n;
    printf("Enter number of jobs : ");
    scanf("%d",&n);
    printf("Enter the jobs\n");
    int p[n]; //profit array
    int d[n]; //deadline array
    int job[n]; //indexing for the jobs
    int total_profit=0;

    for(i=0;i<n;i++){
        job[i] = i+1;
        printf("Enter Deadline for job %d : ",i+1);
        scanf("%d",&d[i]);
        printf("Enter profit for job %d : ",i+1);
        scanf("%d",&p[i]);
    }

    for(i=0;i<n-1;i++){
        for(j=0;j<n-i-1;j++){
            if(p[j]<p[j+1]){
                int temp = p[j];
                p[j] = p[j+1];
                p[j+1]= temp; //decreasing order of profits
                
                temp = d[j];
                d[j] = d[j+1];
                d[j+1]= temp;  //decreasing order of deadline
                
                temp = job[j];
                job[j] = job[j+1];
                job[j+1]= temp; //changing indexes
            }
        }
    }

    int a[n+1];     
    for(i=0;i<n;i++){
        a[i]=0;
    }

    for(i=0;i<n;i++){                           // i for jobs
        for(j=n-1;j>=0;j--){                   // j for slots
            if(a[j]==0 && d[i]>=j+1){         // Check if deadline allows job to be scheduled
                a[j] = job[i];
                total_profit += p[i];
                break;                      // Move to the next job
            }
        }
    }

    printf("Scheduled jobs: ");
    for(i=0;i<n;i++){
        if(a[i] != 0){
            printf("%d ",a[i]);
        }
    }
    printf("\nTotal profit : %d\n",total_profit);
}