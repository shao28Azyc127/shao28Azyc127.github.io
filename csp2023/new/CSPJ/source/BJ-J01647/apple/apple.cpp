#include <bits/stdc++.h>
#define int long long
using namespace std;
vector<int>v;
signed main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin>>n;
    int cnt=0,n1=n;
    while(n){
        n-=ceil(1.0*n/3.0);
        cnt++;
    }
    cout<<cnt<<" ";
    if(n1%3==1)cout<<"1";
    else{
        for(int i=1;i<=n1;++i)v.push_back(i);
        for(int i=1;i<=cnt;++i){
            int cnt1=0;
            for(int j=0;j<v.size();++j){
                if(v[j]!=-1){
                    if(cnt1==0){
                        if(v[j]==n1){
                            cout<<i;
                            return 0;
                        }
                        v[j]=-1;
                    }
                    cnt1=(cnt1+1)%3;
                }
            }
        }
    }
    return 0;
}
