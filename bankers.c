#include <stdio.h>

#define P 5
#define R 3

int main()
{
    int i, j, k;

    int allocation[P][R] = {
        {0, 1, 0},
        {2, 0, 0},
        {3, 0, 2},
        {2, 1, 1},
        {0, 0, 2}
    };

    int max[P][R] = {
        {7, 5, 3},
        {3, 2, 2},
        {9, 0, 2},
        {2, 2, 2},
        {4, 3, 3}
    };

    int available[R] = {3, 3, 2};

    int need[P][R];
    int finish[P] = {0};
    int safeSequence[P];
    int work[R];

    /* Calculate Need Matrix */
    for (i = 0; i < P; i++)
    {
        for (j = 0; j < R; j++)
        {
            need[i][j] = max[i][j] - allocation[i][j];
        }
    }

    /* Initialize Work with Available */
    for (i = 0; i < R; i++)
    {
        work[i] = available[i];
    }

    /* Find Safe Sequence */
    int count = 0;

    while (count < P)
    {
        int found = 0;

        for (i = 0; i < P; i++)
        {
            if (finish[i] == 0)
            {
                int canExecute = 1;

                for (j = 0; j < R; j++)
                {
                    if (need[i][j] > work[j])
                    {
                        canExecute = 0;
                        break;
                    }
                }

                if (canExecute)
                {
                    for (k = 0; k < R; k++)
                    {
                        work[k] += allocation[i][k];
                    }

                    safeSequence[count] = i;
                    count++;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
        {
            printf("\nSystem is NOT in a safe state.\n");
            return 0;
        }
    }

    /* Display Need Matrix */
    printf("\nNeed Matrix:\n");

    for (i = 0; i < P; i++)
    {
        for (j = 0; j < R; j++)
        {
            printf("%d ", need[i][j]);
        }
        printf("\n");
    }

    /* Display Safe Sequence */
    printf("\nSystem is in a SAFE state.\n");

    printf("Safe Sequence: ");

    for (i = 0; i < P; i++)
    {
        printf("P%d", safeSequence[i]);

        if (i != P - 1)
        {
            printf(" -> ");
        }
    }

    printf("\n");

    return 0;
}
