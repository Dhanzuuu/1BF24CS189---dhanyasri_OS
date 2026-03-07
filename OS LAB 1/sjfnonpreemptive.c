#include <stdio.h>

struct process
{
    int pid, at, bt;
    int ct, tat, wt, rt;
    int completed;
};

int main()
{
    int n,i,time=0,completed=0,idx;
    float avg_tat=0,avg_wt=0,avg_rt=0;

    struct process p[20];

    printf("enter number of processes: ");
    scanf("%d",&n);

    for(i=0;i<n;i++)
    {
        p[i].pid=i+1;

        printf("enter at and bt for P%d: ",p[i].pid);
        scanf("%d %d",&p[i].at,&p[i].bt);

        p[i].completed=0;
    }

    while(completed<n)
    {
        int min_bt=9999;
        idx=-1;

        for(i=0;i<n;i++)
        {
            if(p[i].at<=time && p[i].completed==0)
            {
                if(p[i].bt < min_bt)
                {
                    min_bt=p[i].bt;
                    idx=i;
                }
            }
        }

        if(idx!=-1)
        {
            time += p[idx].bt;

            p[idx].ct = time;

            p[idx].tat = p[idx].ct - p[idx].at;

            p[idx].wt = p[idx].tat - p[idx].bt;

            p[idx].rt = p[idx].wt;

            p[idx].completed = 1;
            completed++;
        }
        else
        {
            time++;
        }
    }

    printf("\npid\tat\tbt\tct\ttat\twt\trt\n");

    for(i=0;i<n;i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
        p[i].pid,p[i].at,p[i].bt,p[i].ct,p[i].tat,p[i].wt,p[i].rt);

        avg_tat+=p[i].tat;
        avg_wt+=p[i].wt;
        avg_rt+=p[i].rt;
    }


    printf("\naverage tat= %.2f", avg_tat/n);
    printf("\naverage wt = %.2f", avg_wt/n);
    printf("\naverage rt = %.2f\n", avg_rt/n);


    return 0;
}
