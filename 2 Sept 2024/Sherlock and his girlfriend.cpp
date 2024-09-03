/**
        https://codeforces.com/contest/776/problem/B
*/

#include "bits/stdc++.h"
const int SIZE = 100000;
bool ciur[SIZE + 5];
std :: vector < int > res;
void Precompute(){
         for(int i = 1; i <= SIZE; i++){
                    ciur[i] = true;
         }
         ciur[0] = ciur[1] = false;
         for(int i = 2; i * i <= SIZE; i++){
                    if(ciur[i]){
                          for(int j = i * i; j <= SIZE;  j  = j + i){
                                ciur[j] = false;
                          }
                    }
         }
}
void Solve(){
            Precompute();
            int n;
            std :: cin >> n;
            int p,c;
            p = c = 0;
            for(int i = 1; i <= n; i++){
                        if(ciur[i + 1] == true){
                               p++;
                        }else{
                               c++;
                        }
            }
            for(int i = 1; i <= n; i++){
                    if(ciur[i + 1] == true){
                         res.push_back(1);
                    }else{
                         res.push_back(2);
                    }
                }

            if(c == 0){
                  std :: cout << 1 << '\n';
            }else{
                 std :: cout << 2 << '\n';
            }

            for(int i  : res){
                    std :: cout << i << ' ';
            }

}
signed main(){
      std :: ios_base :: sync_with_stdio(false);
      std :: cin.tie(0);
      Solve();
      return 0;
}
