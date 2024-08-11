#include <bits/stdc++.h>
using namespace std;
int n,d,l = 0,cost = 0,l1 = 0,j = 0,ly = 0;
int jl[114514],jg[114514],maxn = -1,minn = 1919810;
int main(){
    cin >> n >> d;
    for(int i = 1;i < n;i++){
        cin >> jl[i];
        l += jl[i];
    }
    for(int i = 1;i <= n;i++){
        cin >> jg[i];
        if(jg[i] > maxn){
            maxn = jg[i];
        }
        if(jg[i] < minn){
            minn = jg[i];
        }
    }
    for(int i = 1;i <=n;i++){
        for(j = 2;j <=n;j++){
            if(jg[i] > jg[j]){
                j--;
                break;
            }
        }
        for(int k = 1;k <= j;k++){
            l1 += jl[k];
        }
        if((l1-ly)%d == 0){
            cost += (l1-ly)/d*jg[i];
            ly = 0;
        }else{
            cost += ((l1-ly)/d+1)*jg[i];
            ly = d*((l1-ly)/d+1)-l1;
        }
        i += j;
    }
    cout << cost;
    return 0;
}
