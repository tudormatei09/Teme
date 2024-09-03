/**
    https://codeforces.com/contest/26/problem/A
*/
#include "bits/stdc++.h"
const int SIZE = 3000;
bool ciur[SIZE + 5];
int cntfact[SIZE + 5];
void Precompute(){
           for(int i = 2; i <= SIZE; i++){
                 if(ciur[i] == false){
                        for(int j = i; j <= SIZE; j = j + i){
                               ciur[j] = true;
                               cntfact[j]++;
                        }
                 }
           }
}
void Solve(){
        Precompute();
            int n;
            std :: cin >> n;
            int cnt = 0;
            for(int i = 1; i <= n; i++){
                   if(cntfact[i] == 2){
                        cnt++;
                   }
            }
            std :: cout << cnt;
}
signed main(){
         std :: ios_base :: sync_with_stdio(false);
         std :: cin.tie(0);
         Precompute();
         Solve();
         return 0;
}
