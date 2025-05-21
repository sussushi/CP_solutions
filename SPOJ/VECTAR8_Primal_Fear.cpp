#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;




int main() {
    
    int t;
    cin >> t;
    vector<int> values;
    int max1 = 0;
    for (int x=0; x<t;x++) {
        int m;
        cin >> m;
        values.push_back(m);
        max1 = max(m, max1);
    }
    int n = max1;
    vector<bool> is_prime(n+1, true);
    is_prime[0]=is_prime[1]=false;
    for (int i=2; i*i<=n; i++) {
        if (is_prime[i]){
        for (int j=i*i; j<=n; j+=i){
            is_prime[j]=false;
        }
        }
    }

    vector<int> dp_of_form(n+1, 2);
    dp_of_form[0]=dp_of_form[1]=0;
    dp_of_form[2]=1;
    for (int x=3; x<=n; x++) {
        bool flag = true;
        int t = 1;
        int num_digits = floor(log10(x)+1);
        while (flag and t<=num_digits) {
            
            int num = x%(int) pow(10, t);
            if (t<num_digits) {
                int num2 = x%(int) pow(10, t+1);
                if (num==num2) {
                    dp_of_form[x]=false;
                    break;
                } }
              
            if (is_prime[num]) {
                dp_of_form[num]=1;
                t+=1;
            }
            else {
                dp_of_form[x] = 0;
                dp_of_form[num]=0;
                flag = false;
            
        }

        }

    }

    
    vector<int> dp(n+1, 0);
    dp[2]=1;
    for (int x=3; x<=n; x++) {
        if (dp_of_form[x]==1){
            dp[x]=dp[x-1]+1;
        }
        else {
            dp[x] = dp[x-1];
        }
    }

    for (int x=0; x<t;x++) {
        cout << dp[values[x]] << "\n";
    }
    return 0;
}
