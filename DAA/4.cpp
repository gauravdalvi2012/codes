#include <bits/stdc++.h>

using namespace std;

struct Item {
    int profit;
    int weight;
};

int knapsack(Item items[], int w, int n) {
    if (n == 0 || w == 0) {
        return 0;
    }

    if (items[n-1].weight > w) {
        return knapsack(items, w, n - 1);
    }   
    else {
        return max(items[n-1].profit + knapsack(items, w - items[n-1].weight, n-1), knapsack(items, w, n - 1));
    }
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    int w;
    cin >> w;

    Item items[n];
    for (int i = 0; i < n; i++) {
        int p, w;
        cin >> p >> w;
        items[i].profit = p;
        items[i].weight = w;
    }

    int result = knapsack(items, w, n);

    cout << result;
    
    return 0;
}