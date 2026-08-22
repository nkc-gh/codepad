// Finite Geometric progression sum (1 + x + x^2 + x^3..... + x^n)
// Method - Formula

#include <stdio.h>
#include <math.h> // used for power function

int main() {
float x,result;
int n;

printf("Enter x: ");
scanf("%f",&x);

printf("Enter n: ");
scanf("%d",&n);

if(x!=1){
    result = (pow(x,n+1) - 1)/(x-1); // when x is not equal to 1 we can use the formula (x^(n+1) - 1)/(x-1)
}

else{
    result = n+1; // when x = 1 the formula will give 0/0 which is an indeterminate form
}

printf("Result = %.4f",result); // .4f prints 4 digits after the decimal point

return 0;
}

// Method - Single Loop

#include <stdio.h>

int main() {
float x,final,current;
int n;

printf("Enter x: ");
scanf("%f",&x);

printf("Enter n: ");
scanf("%d",&n);

final = 1;
current = 1;

for(int i=1;i<=n;i++){
    // current keeps track of the previous power to calculate the next power without pow()
    current = current * x;

    // final starts with 1 and updates by adding current to the previous final after each iteration
    final += current;
}

printf("Result = %.4f",final);

return 0;
}

// Method - Nested Loop

#include <stdio.h>

int main() {
float x,mul,final;
int n;

printf("Enter x: ");
scanf("%f",&x);

printf("Enter n: ");
scanf("%d",&n);

final = 1;

for(int i=1;i<=n;i++){
    mul = 1; // after every iteration of o, mul resets to 1 otherwise mul will keep its previous value

    for(int o=1;o<=i;o++){ // helps in calculating the power
        mul *= x;
    }

    final += mul;
}

printf("Result = %.4f",final);

return 0;
}

// Method - Recursion + Loop

#include <stdio.h>

float mul(float x,int n){ // recursive method for finding power
    if(n == 0){
        return 1;
    }
    else{
        return x * mul(x,n-1);
    }
}

int main() {
float x,final;
int n;

printf("Enter x: ");
scanf("%f",&x);

printf("Enter n: ");
scanf("%d",&n);

final = 1;

for(int i=1;i<=n;i++){
    final += mul(x,i);
}

printf("Result = %.4f",final);

return 0;
}