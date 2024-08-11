#include<bits/stdc++.h>
using namespace std;
struct q{
    int a,b,c;
}s[1000005];
bool cmp(q x,q y){
    return x.b<x.b;
}
int main(){
    freopen("road.in", "r",stdin);
    freopen("road.out", "w",stdout);
    long long n,d,ans=0,sum=0,f[1000005]={1};
    cin >> n >> d;
    for(int i=1;i<n;i++){
        cin >> s[i].a;
        sum+=s[i].a;
        s[i].c=i;
    }
    for(int i=1;i<=n;i++){
        cin >> s[i].b;
    }
    sort(s+1,s+n,cmp);
    for(int i=1;i<n;i++){
        if(s[i].c==1&&i==1){
            cout << s[i].b*sum/d;
            return 0;
        }
        int w=0;
        for(int j=s[i].c+1;j<=n;j++){
            if(f[j]==0){
                break;
            }
            f[j]=0;
            for(int k=i+1;k<=n;k++){
                if(s[k].c==j){
                    w+=s[k].a;
                }
            }
        }
        ans+=w/d*s[i].b;
    }
    for(int i=1;i<=n;i++){
        if(f[i]==1){
            ans+=s[i].b*s[i].c/d;
        }
    }
    cout << ans;
    return 0;
}