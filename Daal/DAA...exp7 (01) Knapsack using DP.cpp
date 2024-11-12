// EXP 7: 0/1 Knapsack using dynamic programming
#include <iostream>
#include <algorithm> // For sorting
using namespace std;

// Structure to store the weight and profit of items
struct Item {
    int weight, profit;
};

// Function to solve 0/1 Knapsack problem using dynamic programming
int knapsack(int W, Item items[], int n) {
    // Create a DP array where dp[i][j] represents the maximum profit for i items and a knapsack capacity of j
    int dp[n + 1][W + 1];

    // Initialize the DP table
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (items[i - 1].weight <= w) {
                dp[i][w] = max(dp[i - 1][w], items[i - 1].profit + dp[i - 1][w - items[i - 1].weight]);
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    // Display the DP matrix
    cout << "\nDP Matrix:" << endl;
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            cout << dp[i][w] << "\t";
        }
        cout << endl;
    }

    // Finding which items are included in the knapsack
    int res = dp[n][W];
    cout << "\nItems included in the knapsack:\n";
    int w = W;
    for (int i = n; i > 0 && res > 0; i--) {
        if (res != dp[i - 1][w]) {
            cout << "Item " << i << " (Profit: " << items[i - 1].profit << ", Weight: " << items[i - 1].weight << ")\n";
            res -= items[i - 1].profit;
            w -= items[i - 1].weight;
        }
    }

    return dp[n][W];
}

int main() {
    int n, W;
    // Input for the number of items
    cout << "Enter the number of items: ";
    cin >> n;

    Item items[n];
    // Input for corresponding value of profit and weight
    cout << "Enter the weight and profit of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
    }

    // Sort items based on their weights in ascending order
    sort(items, items + n, [](Item a, Item b) {
        return a.weight < b.weight;
    });

    // Input for the maximum capacity of the knapsack
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;

    // Calling the function and storing the value of max profit
    int maxProfit = knapsack(W, items, n);
    cout << "\nMaximum profit of the Knapsack = " << maxProfit << endl;

    return 0;
}

