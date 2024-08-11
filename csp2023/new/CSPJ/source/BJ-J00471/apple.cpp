#include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<iomanip>
#include<list>
#include<queue>
#include<stack>>
#include<list>
#include<vector>
#include<map>
using namespace std;
int n,ans=0,fi=1e9;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    while(n!=0){
        ans++;
        if((n-1)%3==0){
            fi=min(ans,fi);
        }
        n=n-1-(n-1)/3;
    }
    cout<<ans<<" "<<fi;
    return 0;
}
