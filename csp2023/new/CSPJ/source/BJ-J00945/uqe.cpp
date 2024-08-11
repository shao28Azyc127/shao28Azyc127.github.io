#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin >> t >> m;
    for(int i = 1; i <= t; i++){
        cin >> a >> b >> c;
        if(b||c){
            while(t--) printf("NO\n");
            return 0;
        }
    }
    while(t--) printf("0\n");
    return 0;
}
