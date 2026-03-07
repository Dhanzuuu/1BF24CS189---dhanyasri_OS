#include <stdio.h>

struct process {
    int pid, at, bt, rt;
    int ct, tat, wt, start;
    int completed;
};

int main() {
    int n, i, time = 0, completed = 0, min_index;
    float avg_tat = 0, avg_wt = 0, avg_rt = 0;
    struct process p[20];

    printf("enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        p[i].pid = i + 1;
        printf("enter at and bt for P%d: ", p[i].pid);
        scanf("%d %d", &p[i].at, &p[i].bt);

        p[i].rt = p[i].bt;
        p[i].completed = 0;
        p[i].start = -1;
    }
    while(completed < n) {
        min_index = -1;
        int min_rt = 100000;

        for(i = 0; i < n; i++) {
            if(p[i].at <= time && !p[i].completed && p[i].rt < min_rt && p[i].rt > 0) {
                min_rt = p[i].rt;
                min_index = i;
            }
        }

        if(min_index == -1) {
            time++;
            continue;
        }

        if(p[min_index].start == -1) {
            p[min_index].start = time;
        }

        p[min_index].rt--;
        time++;

        if(p[min_index].rt == 0) {
            p[min_index].completed = 1;
            completed++;

            p[min_index].ct = time;
            p[min_index].tat = p[min_index].ct - p[min_index].at;
            p[min_index].wt = p[min_index].tat - p[min_index].bt;
            p[min_index].rt = p[min_index].start - p[min_index].at;
        }
    }

    printf("\npid\tat\tbt\tct\ttat\twt\trt\n");
    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
            p[i].pid, p[i].at, p[i].bt, p[i].ct, p[i].tat, p[i].wt, p[i].rt);

        avg_tat += p[i].tat;
        avg_wt += p[i].wt;
        avg_rt += p[i].rt;
    }

    printf("\naverage tat= %.2f", avg_tat / n);
    printf("\naverage wt = %.2f", avg_wt / n);
    printf("\naverage rt = %.2f\n", avg_rt / n);

    return 0;
}
