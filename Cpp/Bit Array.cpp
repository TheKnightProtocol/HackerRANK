#include <iostream>
using namespace std;

int main() {
    long long N, S, P, Q;
    cin >> N >> S >> P >> Q;
    const long long MASK = (1LL << 31) - 1;
    if (N == 1) { cout << 1; return 0; }
    long long a0 = S & MASK;
    long long slow = a0, fast = a0;
    long long steps = 0;
    do {
        slow = (slow * P + Q) & MASK;
        fast = (fast * P + Q) & MASK;
        fast = (fast * P + Q) & MASK;
        steps++;
        if (steps >= N) { cout << N; return 0; }
    } while (slow != fast);
    long long mu = 0;
    slow = a0;
    while (slow != fast) {
        slow = (slow * P + Q) & MASK;
        fast = (fast * P + Q) & MASK;
        mu++;
    }
    long long lambda = 1;
    fast = (slow * P + Q) & MASK;
    while (slow != fast) {
        fast = (fast * P + Q) & MASK;
        lambda++;
    }
    long long distinct = mu + lambda;
    cout << (N < distinct ? N : distinct);
    return 0;
}
