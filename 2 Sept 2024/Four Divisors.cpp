/**
https://leetcode.com/problems/four-divisors/description/
*/
#include "bits/stdc++.h"
#define ull unsigned long long int
const int SIZE = 100000;
int v[SIZE + 5], sum[SIZE + 5], cnt[SIZE + 5];
int n;
void Precalc_sum(){
            for(int i = 1; i <= SIZE; i++){
                    for(int j = i; j <= SIZE; j = j + i){
                            sum[j] += i;
                    }
            }
}
void Precalc_cnt(){
            for(int i = 1; i <= SIZE; i++){
                        for(int j = i; j <= SIZE; j = j + i){
                                  cnt[j]++;
                        }
            }
}
void Solve(){
            Precalc_cnt();
            Precalc_sum();
            std :: cin >> n;
            ull sumofsums = 0;
            for(int i = 1; i <= n; i++){
                    int x;
                    std :: cin >> x;
                    if(cnt[x] == 4){
                            sumofsums = sumofsums + sum[x];
                    }
            }
            std :: cout << sumofsums;
}
signed main(){
        std :: ios_base :: sync_with_stdio(false);
        std :: cin.tie(0);
        Solve();
        return 0;
}
