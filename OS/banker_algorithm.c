#include<stdio.h>

void main() {
    int i,j;
    int process, resources, alloc[20][20], max[20][20], avail[20], need[20][20];
    int finish[20], work[20], safeSeq[20];

    printf("\nEnter the number of process: ");
    scanf("%d", &process);
    printf("\nEnter the number of resources: ");
    scanf("%d", &resources);

    printf("Enter allocation matrix: ");
    for(i=0; i<process; i++) {
        for(j=0; j<resources; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    printf("Enter max matrix: ");
    for(i=0; i<process; i++) {
        for(j=0; j<resources; j++) {
            scanf("%d", &max[i][j]);
        }
    }

    printf("\nEnter available matrix: ");
    for(i=0; i<resources; i++) {
        scanf("%d", avail[i]);
    }

    //calculate need matrix
    for(i=0; i<process; i++) {
        for(j=0; j<resources; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    printf("Need matrix is: ");
    for(i=0; i<process; i++) {
        printf("\n");
        for(j=0; j<resources; j++) {
            printf("%d", need[i][j]);
        }
    }

    for(i=0; i<resources; i++) {
        work[i] = avail[i];
    }

    for(i=0; i<process; i++) {
        finish[i] = 0;
    }

    int count = 0;

    while(count < process) {
        int found = 0;
        for(i = 0; i < process; i++) {
            if(finish[i] == 0) {
                int canAllocate = 1;
                for(j = 0; j < resources; j++) {
                    if(need[i][j] > work[j]) {
                        canAllocate = 0;
                        break;
                    }
                }

                if(canAllocate) {
                    for(j = 0; j < resources; j++) {
                        work[j] += alloc[i][j];
                    }
                    safeSeq[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if(!found) {
            break;
        }
    }

    if(count == process) {
        printf("\nSystem is in a safe state.\nSafe sequence: ");
        for(i = 0; i < process; i++) {
            printf("P%d ", safeSeq[i]);
        }
        printf("\n");
    } else {
        printf("\nSystem is NOT in a safe state.\n");
    }
}

