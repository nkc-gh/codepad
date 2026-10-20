#include <stdio.h>

int main() {
    int n, originalNum, remainder;
    long long reverse = 0;
    printf("Enter Number: ");
    scanf("%d", &n);

    originalNum = n;

    while(n != 0){
        remainder = n % 10;
        reverse = (reverse * 10) + remainder;
        n = n / 10;
    }

    printf("Original Number : %d\n",originalNum);
    printf("Reversed Number : %lld\n",reverse);
    return 0;
}
