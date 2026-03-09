#include<stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int pr;
    int ct;
    int tat;
    int wt;
    int completed;
};

void priority_nonpre(struct process p[], int n){

    for(int i=0;i<n;i++){
        printf("Enter process id, arrival time, burst time and priority for process %d: ",i+1);
        scanf("%d %d %d %d",&p[i].pid,&p[i].at,&p[i].bt,&p[i].pr);
        p[i].completed = 0;
    }

    int time = 0, completed = 0;
    float total_tat = 0, total_wt = 0;

    while(completed < n){

        int idx = -1;
        int highest_pr = 9999;

        for(int i=0;i<n;i++){
            if(p[i].at <= time && p[i].completed == 0 && p[i].pr < highest_pr){
                highest_pr = p[i].pr;
                idx = i;
            }
        }

        if(idx != -1){
            time += p[idx].bt;

            p[idx].ct = time;
            p[idx].tat = p[idx].ct - p[idx].at;
            p[idx].wt = p[idx].tat - p[idx].bt;

            total_tat += p[idx].tat;
            total_wt += p[idx].wt;

            p[idx].completed = 1;
            completed++;
        }
        else{
            time++;
        }
    }

    printf("\nPID\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    for(int i=0;i<n;i++){
        printf("%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].pr,p[i].ct,p[i].tat,p[i].wt);
    }

    printf("\nAverage Turnaround Time: %.2f\n", total_tat/n);
    printf("Average Waiting Time: %.2f\n", total_wt/n);
}

int main(){

    int n;
    printf("Enter number of processes: ");
    scanf("%d",&n);

    struct process p[n];

    priority_nonpre(p,n);

    return 0;
}