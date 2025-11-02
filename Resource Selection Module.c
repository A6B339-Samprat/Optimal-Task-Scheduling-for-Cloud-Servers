#include <stdio.h>

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
        printf("\n⚠️ No suitable VM available!\n");
}
