#include <bits/stdc++.h>

using namespace std;

void print(vector<vector<char>> board) {
    for (int i = 0; i < 8; i++) {
        for (int j = 0; j < 8; j++) {
            cout << board[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isSafe(vector<vector<char>> board, int x, int y) {
    int i = x, j = y;
    while (i >= 0) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i--;
    }

    i = x;
    j = y;
    while (i < 8) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i++;
    }

    i = x;
    j = y;
    while (i >= 0 && j >= 0) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i--;
        j--;
    }

    i = x;
    j = y;
    while (i < 8 && j < 8) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i++;
        j++;
    }

    i = x;
    j = y;
    while (i >= 0 && j < 8) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i--;
        j++;
    }

    i = x;
    j = y;
    while (i < 8 && j >= 0) {
        if (board[i][j] == 'Q') {
            return false;
        }
        i++;
        j--;
    }

    return true;
}

bool placeQueen(vector<vector<char>> &board, int i, int alreadyPlacedRow) {
    if (i == 8) {
        print(board);
        return true;
    }

    if (i == alreadyPlacedRow) {
        i++;
    }

    for (int j = 0; j < 8; j++) {
        if (isSafe(board, i, j)) {
            board[i][j] = 'Q';
            if (placeQueen(board, i+1, alreadyPlacedRow)) {
                return true;
            }
            board[i][j] = '.';
        }
    }

    return false;
}

int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    vector<vector<char>> board(8, vector<char> (8, '.'));
    int x, y;
    cin >> x >> y;

    board[x][y] = 'Q';

    bool flag = placeQueen(board, 0, x);

    if (!flag) {
        cout << "Cannot place Queens";
    }
    
    return 0;
}