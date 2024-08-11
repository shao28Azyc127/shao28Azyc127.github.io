#include<bits/stdc++.h>
#include<iostream>
#include<cstdio>
#include<iomanip>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,ans=1,ans2=1,gt=0;
    cin>>n;
    bool b[n+2];
    for(int i=1;i<=n;i++)
        if(i%3==1)b[i]=0,gt++;
        else b[i]=1;
    while(b[n]||gt<n){
        if(b[n])ans++;
        ans2++;
        int cnt=2;
        for(int i=1;i<=n;i++){
            if(cnt==2&&b[i])b[i]=0,cnt=0,gt++;
            if(b[i])cnt++;
        }
        //for(int i=0;i<=n;i++)if(b[i])cout<<i<<' ';
        //cout<<endl;
    }
    cout<<ans2<<' '<<ans;
    return 0;
}
