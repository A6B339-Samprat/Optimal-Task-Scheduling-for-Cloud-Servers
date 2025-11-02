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
                printf("\nID\tDeadline\tProfit\n");
                for (int i = 0; i < jobCount; i++)
                    printf("%s\t%d\t\t%d\n", jobs[i].id, jobs[i].deadline, jobs[i].profit);
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
                printf("\nInvalid choice!\n");
        }
    }
    return 0;
}
