#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAX 30


typedef struct {
    char id[5];
    int deadline;
    int profit;
} Job;

Job jobs[MAX];
int jobCount = 0;


typedef struct {
    char id[5];
    int cpu;
    int mem;
    int cost;
} VM;

VM vms[] = {
    {"VM1", 4, 8, 5},
    {"VM2", 2, 4, 3},
    {"VM3", 8, 16, 10},
    {"VM4", 1, 2, 1}
};
int vmCount = 4;


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

    for (int i = 0; i <= maxDeadline; i++)
        strcpy(jobOrder[i], "-");

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


int calcProfit(int *subset, int n, Job jobs[]) {
    int usedSlots[MAX] = {0};
    int profit = 0;

    for (int i = 0; i < n; i++) {
        if (subset[i]) {
            int d = jobs[i].deadline;
            for (int j = d; j > 0; j--) {
                if (!usedSlots[j]) {
                    usedSlots[j] = 1;
                    profit += jobs[i].profit;
                    break;
                }
            }
        }
    }
    return profit;
}

void bruteForceScheduling() {
    if (jobCount == 0) {
        printf("\n Add jobs first before scheduling!\n");
        return;
    }

    int n = jobCount;
    int bestProfit = 0;
    int bestSubset[MAX] = {0};
    int totalComb = (1 << n);

    for (int i = 0; i < totalComb; i++) {
        int subset[MAX] = {0};
        for (int j = 0; j < n; j++)
            subset[j] = (i >> j) & 1;

        int profit = calcProfit(subset, n, jobs);
        if (profit > bestProfit) {
            bestProfit = profit;
            memcpy(bestSubset, subset, sizeof(subset));
        }
    }

    printf("\n--- Job Scheduling (Brute Force Method) ---\nJobs Selected: ");
    for (int i = 0; i < n; i++)
        if (bestSubset[i]) printf("%s ", jobs[i].id);

    printf("\n Total Profit (Brute Force): %d\n", bestProfit);
}

void resourceSelection(int requiredCPU, int requiredMem) {
    int bestIdx = -1;
    for (int i = 0; i < vmCount; i++) {
        if (vms[i].cpu >= requiredCPU && vms[i].mem >= requiredMem) {
            if (bestIdx == -1 || vms[i].cost < vms[bestIdx].cost)
                bestIdx = i;
        }
    }

    if (bestIdx != -1)
        printf("\n💻 Selected Resource: %s (Cost: %d)\n", vms[bestIdx].id, vms[bestIdx].cost);
    else
        printf("\n No suitable VM available!\n");
}


int main() {
    int choice;
    int cpuReq, memReq;

    while (1) {
        printf("\n===== OPTIMAL RESOURCE ALLOCATION SYSTEM =====\n");
        printf("1. Add Job\n");
        printf("2. View All Jobs\n");
        printf("3. Run Greedy Scheduling\n");
        printf("4. Run Brute Force Scheduling\n");
        printf("5. Resource Selection Module\n");
        printf("6. Compare Both Methods\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("\nEnter Job ID: ");
                scanf("%s", jobs[jobCount].id);
                printf("Enter Deadline: ");
                scanf("%d", &jobs[jobCount].deadline);
                printf("Enter Profit: ");
                scanf("%d", &jobs[jobCount].profit);
                jobCount++;
                break;

            case 2:
                if (jobCount == 0) {
                    printf("\n No jobs available!\n");
                } else {
                    printf("\nID\tDeadline\tProfit\n");
                    for (int i = 0; i < jobCount; i++)
                        printf("%s\t%d\t\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
                }
                break;

            case 3:
                greedyScheduling();
                break;

            case 4:
                bruteForceScheduling();
                break;

            case 5:
                printf("\nEnter required CPU: ");
                scanf("%d", &cpuReq);
                printf("Enter required Memory: ");
                scanf("%d", &memReq);
                resourceSelection(cpuReq, memReq);
                break;

            case 6:
                greedyScheduling();
                bruteForceScheduling();
                break;

            case 7:
                printf("\nThank you! Exiting system.\n");
                exit(0);

            default:
                printf("\n Invalid choice! Please try again.\n");
        }
    }
    return 0;
}
