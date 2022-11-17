#include <bits/stdc++.h>

using namespace std;

class FiboIterative{
    public:
    int fibo(int n){
        if(n <= 2){
            return n-1;
        }
        int prev1 = 0, prev2 = 1;
        for(int i=3; i<=n; i++){
            int c = prev1 + prev2;
            prev1 = prev2;
            prev2 = c;
        }
        return prev2;
    }
};


class FiboRecursive{
    public:
    int fibo(int n){
        if(n <= 2){
            return n-1;
        }
        return fibo(n-1) + fibo(n-2);
    }
};


class FiboDynamicProgramming{
    private:
        vector<int> dp;

    public:
    FiboDynamicProgramming(){
        dp.resize(1000000, 0);
    }

    int fibo(int n){
        dp[1] = 0;
        dp[2] = 1;
        for(int i=3; i<=n; i++){
            dp[i] = dp[i-1] + dp[i-2];
        }
        return dp[n];
    }
};

int main()
{

    cout<<"Enter Number: ";
    int n;
    cin>>n;

    FiboIterative fiboI;
    cout<<"Fibo using Iteration: "<<fiboI.fibo(n)<<endl;

    FiboRecursive fiboR;
    cout<<"Fibo using Recursion: "<<fiboR.fibo(n)<<endl;

    FiboDynamicProgramming fiboDP;
    cout<<"Fibo using DP: "<<fiboDP.fibo(n)<<endl;
    
    
    return 0;
}