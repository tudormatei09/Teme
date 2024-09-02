/**

        https://www.spoj.com/problems/HS08PAUL/

*/

#include "bits/stdc++.h"
#define ll long long int
const int SIZE = 10000000;
bool ciur[SIZE + 5];
int prefix[SIZE + 5];
int n;
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
        std :: cin >> n;
        for(int i = 1; i * i <= SIZE; i++){
               for(int j = 1; j * j * j * j <= SIZE; j++){
                        int x = i * i + j * j * j * j;
                        if(x <= SIZE and ciur[x] == true){
                               prefix[x] = 1;
                        }
               }
        }
        for(int i = 1; i <= SIZE; i++){
                prefix[i] = prefix[i] + prefix[i - 1];
        }
        while(n -- ){
              int x;
              std :: cin >> x;
              std :: cout << prefix[x] << '\n';
        }
}
signed main(){
     std :: ios_base :: sync_with_stdio(false);
     std :: cin.tie(0);
     Solve();
     return 0;
}
