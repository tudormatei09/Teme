/**

    https://www.spoj.com/problems/NFACTOR/

*/
#include "bits/stdc++.h"
const int SIZE = 1000000;
int  cntfact[SIZE + 5];
int sum[15][SIZE + 5];
void Precompute(){
        for(int i = 2; i <= SIZE; i++){
                if(cntfact[i] == 0){
                       for(int j = i; j <= SIZE; j = j + i){
                               cntfact[j]++;
                       }
                }
        }
}
void Solve(){
       Precompute();
       for(int i = 0; i <= 10; i++){
            for(int j = 1; j <= SIZE; j++){
                   if(cntfact[j] == i)
                     sum[i][j] =  sum[i][j - 1] + 1;
                    else{
                         sum[i][j] = sum[i][j - 1];
                    }
            }
       }
       int q;
       std :: cin >> q;
       while(q -- ){
            int l, r, x;
            std :: cin >> l >> r >> x;
            std :: cout << sum[x][r] - sum[x][l - 1] << '\n';
       }
}
signed main(){
      std :: ios_base :: sync_with_stdio(false);
      std :: cin.tie(0);
      Solve();
      return 0;
}
