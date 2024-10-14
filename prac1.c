#include<stdio.h>

void knapsack(int num, float weights[], float profits[], float maxCapacity) {
    float totalProfit = 0;
    int i, availableCapacity = maxCapacity;

    for (i = 0; i < num; i++) {
        if (weights[i] > availableCapacity)
            break;
        else {
            totalProfit += profits[i];
            availableCapacity -= weights[i];
        }
    }

    if (i < num)
        totalProfit += (availableCapacity / weights[i]) * profits[i];

    printf("\nMaximum profit is: %f\n", totalProfit);
}

int main() {
    float weights[20], profits[20], maxCapacity;
    int num, i, j;
    float ratios[20], temp;

    printf("\nEnter the number of items: ");
    scanf("%d", &num);

    printf("\nEnter the weights and profits of each item: ");
    for (i = 0; i < num; i++) {
        scanf("%f %f", &weights[i], &profits[i]);
    }

    printf("\nEnter the capacity of the knapsack: ");
    scanf("%f", &maxCapacity);

    for (i = 0; i < num; i++) {
        ratios[i] = profits[i] / weights[i];
    }

    for (i = 0; i < num; i++) {
        for (j = i + 1; j < num; j++) {
            if (ratios[i] < ratios[j]) {
                temp = ratios[j];
                ratios[j] = ratios[i];
                ratios[i] = temp;

                temp = weights[j];
                weights[j] = weights[i];
                weights[i] = temp;

                temp = profits[j];
                profits[j] = profits[i];
                profits[i] = temp;
            }
        }
    }

    knapsack(num, weights, profits, maxCapacity);
    return 0;
}
