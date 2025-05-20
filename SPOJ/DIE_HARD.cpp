#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;

int dp[1005][1005];



int solve(int h, int a) {
    if (dp[h][a]!=-1) {
        return dp[h][a];
    }
    else if (h<=5) {
        return dp[h][a] = 0;
    }
    else if (a<=0) {
        return  dp[h][a] = 0;
    }
    else if (h<=20 and a<=10) {
        return  dp[h][a] = 0;
    }
    else if (h<=20 and a>10) {
        h-=2;
        a-=8;
        return dp[h+2][a+8] = 2 + solve(h, a);
    }
    else if (h>20 and a<=10) {
        h-=17;
        a+=7;
        return dp[h+17][a-7] = 2 + solve(h, a) ;
    }

    else {
        return  dp[h][a] = 2 + max(solve(h-2, a-8), solve(h-17, a+7));
    }
}

int main() {
    
    long long t;
    cin >> t;
    
    for (int x = 0; x < t; x++) {
        int h;
        int a;
        cin >> h >> a;
        int ans = 1;
        memset(dp, -1, sizeof(dp));
        h+=3;
        a+=2;
        
    
    cout << 1 + solve(h, a) << "\n";
    }
 return 0;
}
