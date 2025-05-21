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
    int n = t;
    vector<bool> is_prime(n+1, true);
    is_prime[0]=is_prime[1]=false;
    for (int i =2; i<=n+1; i++) {
        if (is_prime[i]) {
            for (long long j = (long long) i*i; j<=n+1; j+=i) {
                is_prime[j] = false;
            }
        }
    }
    if (t==1 || t==2) {
    cout << 1 << "\n";
    } else {
        cout << 2 << "\n";
    }
    for (int x=2; x<=t+1; x++) {
        if (x==t+1) {
       
            if (is_prime[t+1]) {
                cout << 1;
            }
            else {
                cout << 2;
            }
        } else {
        if (is_prime[x]) {
            cout << 1 << " ";
        }
        else {
            cout << 2 << " ";
        } 
    }
    }
   

  
    return 0;
 } 
