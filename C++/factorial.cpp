#include <iostream>
using namespace std;

int main() {
	int n;
	cout << "Enter the Number: ";
	cin >> n;

	long long fact = 1; //prevents overflow
	for (int i = 2; i <= n; i++) {
		fact *= i;
	}

	cout << "Factorial of " << n << " is: " << fact << "\n";
	
	return 0;

}