#include <stdio.h>
void towerOfHanoi(int n, char A, char B, char C) 
{
    if (n > 0) 
    {
        towerOfHanoi(n - 1, A, C, B);

        printf("\nMove disk %d from rod %c to rod %c \n", n, A, C);

        towerOfHanoi(n - 1, B, A, C);
    }
}

int main() 
{
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n);
    printf("Sequence of moves:\n");
    towerOfHanoi(n, 'A', 'B', 'C');
    return 0;
}
