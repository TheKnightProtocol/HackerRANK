#include <iostream>
#include <vector>

int main() {
    int n, q;
    std::cin >> n >> q;
    
    std::vector<std::vector<int>> arrays(n);
    
    for (int i = 0; i < n; ++i) {
        int k;
        std::cin >> k;
        arrays[i].resize(k);
        for (int j = 0; j < k; ++j) {
            std::cin >> arrays[i][j];
        }
    }
    
    for (int query = 0; query < q; ++query) {
        int i, j;
        std::cin >> i >> j;
        std::cout << arrays[i][j] << std::endl;
    }
    
    return 0;
}
