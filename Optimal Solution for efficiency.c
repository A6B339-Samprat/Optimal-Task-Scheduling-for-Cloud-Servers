#include <string.h>
#include <math.h>

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
        for (int j = 0; j < n; j++) {
            subset[j] = (i >> j) & 1;
        }

        int profit = calcProfit(subset, n, jobs);
        if (profit > bestProfit) {
            bestProfit = profit;
            memcpy(bestSubset, subset, sizeof(subset));
        }
    }

    printf("\n--- Job Scheduling (Brute Force) ---\nJobs Selected: ");
    for (int i = 0; i < n; i++)
        if (bestSubset[i]) printf("%s ", jobs[i].id);

    printf("\n Total Profit (Brute Force): %d\n", bestProfit);
}
