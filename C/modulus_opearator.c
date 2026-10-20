#include <stdio.h>

int main() {
    int n;
    printf("Enter Number: ");
    scanf("%d",&n);

    int operator;
    printf("Enter Modulus Operator: ");
    scanf("%d",&operator);

    printf("Modulus of number is : %d\n",n%operator);
    return 0;
}