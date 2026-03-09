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

void fcfs(struct process p[], int n){
    for(int i=0; i<n; i++){
        printf("Enter process id, arrival time and burst time for process %d: ", i+1);
        scanf("%d %d %d", &p[i].pid, &p[i].at, &p[i].bt);
    }

    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            if(p[i].at > p[j].at){
                struct process temp = p[i];
                p[i] = p[j];
                p[j] = temp;
            }
        }
    }

    int time=0;
    float total_tat=0, total_wt=0;
    for(int i=0; i<n; i++){
        if(time<p[i].at){
            time = p[i].at;
        }

        time+=p[i].bt;
        p[i].ct = time;
        p[i].tat = p[i].ct - p[i].at;
        p[i].wt = p[i].tat - p[i].bt;

        total_tat+=p[i].tat;
        total_wt+=p[i].wt;
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
    fcfs(p, n);
    return 0;
}

