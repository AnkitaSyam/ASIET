#include<stdio.h>
#include<stdlib.h>

int mutex = 1;
int full = 0;
int empty = 5, x = 0;

void producer() {
    --mutex;
    ++full;
    --empty;
    x++;
    printf("Producer produces item %d\n", x);
    ++mutex;
}

void consumer() {
    --mutex;
    --full;
    ++empty;
    printf("Consumer consumes item %d\n", x);
    x--;
    ++mutex;
}

void displayBuffer() {
    if (full == 0) {
        printf("Buffer is Empty!\n");
    } else {
        printf("Buffer contains: ");
        for (int i = 1; i <= x; i++) {
            printf("%d ", i);
        }
        printf("\n");
    }
}

int main() {
    int ch;
    while (1) {
        printf("\nSelect from the menu:\n1. Producer\n2. Consumer\n3. Display Buffer\n4. Exit");
        printf("\nYour choice: ");
        scanf("%d", &ch);

        switch (ch) {
            case 1:
                if ((mutex == 1) && (empty != 0)) {
                    producer();
                } else {
                    printf("Buffer is Full!\n");
                }
                break;
            case 2:
                if ((mutex == 1) && (full != 0)) {
                    consumer();
                } else {
                    printf("Buffer is Empty!\n");
                }
                break;
            case 3:
                displayBuffer();
                break;
            case 4:
                printf("Exiting...\n");
                return 0;
            default:
                printf("Wrong Choice! Please select between 1-4.\n");
        }
    }
    return 0;
}
