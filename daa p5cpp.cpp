#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    vector<int> weight = {10, 20, 30};
    vector<int> value = {60, 100, 120};

    int capacity = 50;
    int n = weight.size();

    vector<vector<int>> dp(n + 1, vector<int>(capacity + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int w = 1; w <= capacity; w++) {
            if (weight[i - 1] <= w) {
                dp[i][w] = max(
                    value[i - 1] + dp[i - 1][w - weight[i - 1]],
                    dp[i - 1][w]
                );
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    cout << "Maximum value = " << dp[n][capacity] << endl;

    return 0;
}
