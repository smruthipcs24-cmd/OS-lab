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
    int rbt;
};

void priority_pre(struct process p[], int n){

    for(int i=0;i<n;i++){
        printf("Enter process id, arrival time, burst time and priority for process %d: ", i+1);
        scanf("%d %d %d %d",&p[i].pid,&p[i].at,&p[i].bt,&p[i].pr);
        p[i].rbt = p[i].bt;
    }

    int completed = 0, time = 0;
    float total_tat = 0, total_wt = 0;

    while(completed < n){
        int idx = -1;
        int highest_pr = 9999;

        for(int i=0;i<n;i++){
            if(p[i].at <= time && p[i].rbt > 0 && p[i].pr < highest_pr){
                highest_pr = p[i].pr;
                idx = i;
            }
        }

        if(idx != -1){
            p[idx].rbt--;
            time++;

            if(p[idx].rbt == 0){
                p[idx].ct = time;
                p[idx].tat = p[idx].ct - p[idx].at;
                p[idx].wt = p[idx].tat - p[idx].bt;

                total_tat += p[idx].tat;
                total_wt += p[idx].wt;
                completed++;
            }
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

    priority_pre(p,n);

    return 0;
}