#include <bits/stdc++.h>

using namespace std;

struct Item {
    int profit;
    int weight;
};

bool comparator(Item a, Item b) {
    double r1 = (double)a.profit / (double)a.weight;
    double r2 = (double)b.profit / (double)b.weight;

    return r1 > r2;
}

void fractionalKnapsack(Item items[], int n, int w) {
    sort(items, items + n, comparator);

    int remainingWeight = w;
    double profit = 0;

    for (int i = 0; i < n; i++) {
        if (remainingWeight > 0) {
            if (items[i].weight <= remainingWeight) {
                profit += items[i].profit;
                remainingWeight -= items[i].weight;
            }
            else {
                double fraction = (double)remainingWeight / (double)items[i].weight;
                profit += (fraction * items[i].profit);
                remainingWeight -= items[i].weight;
            }
        }
    }

    cout << profit;
    
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

    fractionalKnapsack(items, n, w);
    
    return 0;
}