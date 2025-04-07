#include <stdio.h>
#include <stdlib.h>

void first_fit(int blocks, int blockSize[], int processes, int processSize[]) {
    int i, j;
    int allocation[10];

    for (i = 0; i < processes; i++) allocation[i] = -1;

    for (i = 0; i < processes; i++) {
        for (j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nFirst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\tFree Block Size\n");
    for (i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, processSize[i], allocation[i]+1, blockSize[allocation[i]]);
        else
            printf("%d\t\t%d\t\tNot Allocated\t--\n", i+1, processSize[i]);
    }
}

void best_fit(int blocks, int blockSize[], int processes, int processSize[]) {
    int i, j, bestIdx;
    int allocation[10];

    for (i = 0; i < processes; i++) allocation[i] = -1;

    for (i = 0; i < processes; i++) {
        bestIdx = -1;
        for (j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    bestIdx = j;
            }
        }

        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }

    printf("\nBest Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\tFree Block Size\n");
    for (i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, processSize[i], allocation[i]+1, blockSize[allocation[i]]);
        else
            printf("%d\t\t%d\t\tNot Allocated\t--\n", i+1, processSize[i]);
    }
}

void worst_fit(int blocks, int blockSize[], int processes, int processSize[]) {
    int i, j, worstIdx;
    int allocation[10];

    for (i = 0; i < processes; i++) allocation[i] = -1;

    for (i = 0; i < processes; i++) {
        worstIdx = -1;
        for (j = 0; j < blocks; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx])
                    worstIdx = j;
            }
        }

        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }

    printf("\nWorst Fit Allocation:\n");
    printf("Process No.\tProcess Size\tBlock No.\tFree Block Size\n");
    for (i = 0; i < processes; i++) {
        if (allocation[i] != -1)
            printf("%d\t\t%d\t\t%d\t\t%d\n", i+1, processSize[i], allocation[i]+1, blockSize[allocation[i]]);
        else
            printf("%d\t\t%d\t\tNot Allocated\t--\n", i+1, processSize[i]);
    }
}

void main() {
    int blockSize[10], processSize[10], tempBlockSize[10];
    int blocks, processes, choice;
    int i;

    printf("\nEnter the number of memory blocks: ");
    scanf("%d", &blocks);
    printf("Enter the size of each block: ");
    for(i = 0; i < blocks; i++) {
        scanf("%d", &blockSize[i]);
    }

    printf("\nEnter the number of processes: ");
    scanf("%d", &processes);
    printf("Enter the size of each process: ");
    for(i = 0; i < processes; i++) {
        scanf("%d", &processSize[i]);
    }

    while (1) {
        printf("\n\nMENU\n1. First Fit\n2. Best Fit\n3. Worst Fit\n4. Exit");
        printf("\nEnter Choice: ");
        scanf("%d", &choice);

        // Copy blockSize to tempBlockSize to reset memory before each method
        for (i = 0; i < blocks; i++) {
            tempBlockSize[i] = blockSize[i];
        }

        switch (choice) {
            case 1:
                first_fit(blocks, tempBlockSize, processes, processSize);
                break;
            case 2:
                best_fit(blocks, tempBlockSize, processes, processSize);
                break;
            case 3:
                worst_fit(blocks, tempBlockSize, processes, processSize);
                break;
            case 4:
                printf("Exiting...\n");
                exit(0);
            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}
