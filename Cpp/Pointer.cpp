#include <iostream>
#include <cstdlib> // for abs()
using namespace std;

void update(int *a, int *b) {
    int sum = *a + *b;
    int diff = abs(*a - *b);
    *a = sum;
    *b = diff;
}

int main() {
    int x, y;
    cin >> x >> y;
    
    update(&x, &y);
    
    cout << x << endl;
    cout << y << endl;
    
    return 0;
}
