#include <iostream>
#include <unordered_set>
using namespace std;

int main() {
    int N;
    cin >> N;

    unordered_set<int> seen;

    for (int i = 0; i < N; i++) {
        int x;
        cin >> x;
        seen.insert(x);
    }

    cout << "Total Unique Elements are: " << seen.size() << '\n';
    return 0;
}