#include <bits/stdc++.h>

using namespace std;

void binomialCoefficient(int n, int r) {
    int c[n+1][r+1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= min(i, r); j++) {
            cout << i << " " << j << "\n";
            if (j == 0 || j == i) {
                c[i][j] = 1;
            }
            else {
                c[i][j] = c[i - 1][j] + c[i - 1][j - 1];
            }
        }
    }

    cout << c[n][r];
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, r;
    cin >> n >> r;

    binomialCoefficient(n, r);
    
    return 0;
}