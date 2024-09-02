/**

    https://www.spoj.com/problems/TDPRIMES/

*/

#include "bits/stdc++.h"
const int SIZE  = 100000000;
bool ciur[SIZE + 5];
void Precompute(){
        for(int i = 1; i <= SIZE; i++){
                ciur[i] = true;
        }
        ciur[0] = ciur[1] = false;
        for(int i = 2; i * i <= SIZE; i++){
             if(ciur[i]){
                    for(int j = i * i; j <= SIZE; j = j + i){
                           ciur[j] = false;
                    }
             }
        }
}
void Solve(){
       Precompute();
       int cnt  = 0;
       for(int i = 1; i <= SIZE; i++){
             if(ciur[i] == true){

                        if(cnt % 100 == 0){
                               std :: cout << i << '\n';
                        }
                        cnt++;
             }
       }
}
signed main(){
      std :: ios_base :: sync_with_stdio(false);
      std :: cin.tie(0);
      Solve();
      return 0;
}
