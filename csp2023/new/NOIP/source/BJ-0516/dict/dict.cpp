#include<bits/stdc++.h>
using namespace std;
int n,m,nm[3005],ni[3005],tmp,ans[3005],ind;
string s;
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>s;
        nm[i]=-1;
        ni[i]=1000000;
        for(int j=0;j<m;j++){
            tmp=int(s[j])-96;
            if(tmp<ni[i])
                ni[i]=tmp;
            if(tmp>nm[i])
                nm[i]=tmp;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            if(i==j)
                continue;
            if(ni[i]<nm[j])
                ans[i]=1;
            else{
                ans[i]=0;
                break;
            }
        }
    }
    for(int i=1;i<=n;i++)
        cout<<ans[i];
    return 0;
}
