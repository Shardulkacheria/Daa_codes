// Exp 6: Fractional Knapsack
#include <iostream>
#include <algorithm>
using namespace std;
// structure to store the profit, weight and index
struct Item {
    int profit, weight, index; 
};
// sorting the data based on profit/weight ratio in descending order
bool compare(Item a, Item b) {
    double r1 = (double)a.profit / a.weight;
    double r2 = (double)b.profit / b.weight;
    return r1 > r2;
}
// function to add items to the knapsack
double fractional_knapsack(int W, Item items[], int n) {
    sort(items, items + n, compare);

    double totalprofit = 0.0;

    cout << "\nItems added to the knapsack:\n";
    cout << "Item\tProfit\tWeight\tFraction\n";
    
    // if item can be added as a whole
    for (int i = 0; i < n; i++) {
        if (items[i].weight <= W) {
            W = W - items[i].weight;
            totalprofit = totalprofit + items[i].profit;
            cout << items[i].index + 1 << "\t" << items[i].profit << "\t" << items[i].weight << "\t 1.0 \n";
        }
        // if item can't be added as a whole then its fractional part is added
        else {
            double fraction = (double)W / items[i].weight;
            totalprofit = totalprofit + items[i].profit * fraction;
            cout << items[i].index + 1 << "\t" << items[i].profit << "\t" << items[i].weight << "\t" << fraction << "\n";
            break;
        }
    }

    return totalprofit;
}

int main() {
    int n, W;
    // input for the number of items that one want
    cout << "Enter the number of items: ";
    cin >> n;
    // input for corresponding value of profit and weight
    Item items[n];
    cout << "Enter weight and profit of each item:" << endl;
    for (int i = 0; i < n; i++) {
        cin >> items[i].weight >> items[i].profit;
        items[i].index = i;
    }
    // maximum capacity of the knapsack
    cout << "Enter the maximum capacity of the knapsack: ";
    cin >> W;
    // calling the function and storing the value of max profit
    double maxprofit = fractional_knapsack(W, items, n);
    cout << "\nMaximum profit of the Knapsack = " << maxprofit << endl;

    return 0;
}

