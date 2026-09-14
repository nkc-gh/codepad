#include <stdio.h>

int main() {
    int n, originalNum, remainder;
    long long reverse = 0; // prevents the overflow condition of int
    printf("Enter Number: ");
    scanf("%d", &n);

    originalNum = n;

    while(n != 0){
        remainder = n % 10; // Takes Last digit
        reverse = (reverse * 10) + remainder; // Adds the last digit to the reverse number
        n = n / 10; // removes last digit from the number
    }

    if(originalNum == reverse){ // original num is here promoted to long long to match reverse so both side match perfectly
        printf("%d is Palindrome", originalNum);
    }
    else{
        printf("%d is not Palindrome", originalNum);
    }

    return 0;
}
