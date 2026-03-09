#include<stdio.h>

struct process
{
    int pid;
    int at;
    int bt;
    int ct;
    int tat;
    int wt;
};

void sjf_np(struct process p[], int n){
    for(int i=0; i<n; i++){
        printf("Enter the process id, arrival time and burst time of process %d: ", i+1);
        scanf("%d %d %d",&p[i].pid, &p[i].at, &p[i].bt);
    }

    int completed = 0, time = 0;
    float total_tat = 0, total_wt = 0;
    int done[n];
    for(int i=0; i<n; i++) done[i] = 0;

while(completed < n) {
    int idx = -1, min_bt = 9999;

    for(int i=0; i<n; i++) {
        if(!done[i] && p[i].at <= time && p[i].bt < min_bt) {
            min_bt = p[i].bt;
            idx = i;
        }
    }

    if(idx != -1) {
        time += p[idx].bt;
        p[idx].ct = time;
        p[idx].tat = p[idx].ct - p[idx].at;
        p[idx].wt = p[idx].tat - p[idx].bt;
        total_tat += p[idx].tat;
        total_wt += p[idx].wt;
        done[idx] = 1;
        completed++;
    } else {
        time++;
    }
}
        printf("\nPID\tAT\tBT\tCT\tTAT\tWT\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t%d\t%d\t%d\t%d\n",
               p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt);
    }


    printf("\nAverage Turnaround Time: %.2f\n", total_tat/n);
    printf("Average Waiting Time: %.2f\n", total_wt/n);


}

int main(){
    int n;
    printf("Enter number of processes: ");
    scanf("%d", &n);
    struct process p[n];
    sjf_np(p, n);
    return 0;
}
