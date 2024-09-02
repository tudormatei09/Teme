/**
    https://leetcode.com/problems/count-primes/description/
*/
#include "bits/stdc++.h"
#define ll long long int
const int SIZE = 5000001;
void Solve(){
           int n;
           std :: cin >> n;
           ll res = n;
           if(n == 1){
                  std :: cout << 0;
                  return;
           }
           for(int i  = 2; i  * i <= n; i++){
                    if(n % i == 0){
                            res = res / i * (i-1);
                            while(n % i == 0){
                                  n = n / i;
                            }
                    }
           }
           if(n > 1){
                res = res / n * (n - 1);
           }
           std :: cout << res;
}
signed main(){
      std :: ios_base :: sync_with_stdio(false);
      std :: cin.tie(0);
      Solve();
      return 0;
}
