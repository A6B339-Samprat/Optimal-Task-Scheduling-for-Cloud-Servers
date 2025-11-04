#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 30

typedef struct {
    char id[5];
    int deadline;
    int profit;
} Job;

Job jobs[MAX];
int jobCount = 0;

int compare(const void *a, const void *b) {
    Job *j1 = (Job *)a;
    Job *j2 = (Job *)b;
    return (j2->profit - j1->profit);
}

int findMaxDeadline() {
    int max = 0;
    for (int i = 0; i < jobCount; i++)
        if (jobs[i].deadline > max)
            max = jobs[i].deadline;
    return max;
}

void greedyScheduling() {
    if (jobCount == 0) {
        printf("\n Add jobs first before scheduling!\n");
        return;
    }

    qsort(jobs, jobCount, sizeof(Job), compare);
    int maxDeadline = findMaxDeadline();
    int slot[MAX] = {0};
    char jobOrder[MAX][5];
    int totalProfit = 0;

    for (int i = 0; i <= maxDeadline; i++) strcpy(jobOrder[i], "-");

    for (int i = 0; i < jobCount; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == 0) {
                slot[j] = 1;
                strcpy(jobOrder[j], jobs[i].id);
                totalProfit += jobs[i].profit;
                break;
            }
        }
    }

    printf("\n--- Job Scheduling (Greedy Method) ---\n");
    for (int i = 1; i <= maxDeadline; i++)
        printf("Time Slot %d: %s\n", i, jobOrder[i]);

    printf("\n Total Profit (Greedy): %d\n", totalProfit);
}
