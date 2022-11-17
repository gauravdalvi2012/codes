#include <bits/stdc++.h>

using namespace std;

struct Job {
    char id;
    int deadline;
    int profit;
};

bool comparator(Job a, Job b) {
    return a.profit > b.profit;
}

void jobSequencing(Job jobs[], int n) {
    sort(jobs, jobs + n, comparator);

    int maxDeadline = jobs[0].deadline;
    for (int i = 1; i < n; i++) {
        maxDeadline = max(maxDeadline, jobs[i].deadline);
    }

    vector<char> slot(maxDeadline + 1, '0');

    int maxProfit = 0, countJobs = 0;

    for (int i = 0; i < n; i++) {
        for (int j = jobs[i].deadline; j > 0; j--) {
            if (slot[j] == '0') {
                slot[j] = jobs[i].id;
                maxProfit += jobs[i].profit;
                countJobs++;
                break;
            }
        }
    }

    cout << maxProfit << " " << countJobs << "\n";

    for (char c : slot) {
        if (c != '0') {
            cout << c << " ";
        }
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

    Job jobs[n];

    for (int i = 0; i < n; i++) {
        char id;
        int deadline;
        int profit;
        cin >> id >> deadline >> profit;
        jobs[i].id = id;
        jobs[i].deadline = deadline;
        jobs[i].profit = profit;
    }

    jobSequencing(jobs, n);
    
    return 0;
}