#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int n;
char a[N];
int ans;
bool find(int l,int r){
    bool b=true;
    while(l<=r&&b){
        b=false;
        if(a[l]==a[l+1]){
            l+=2;
            b=true;
        }
        if(a[r]==a[r-1]){
            r-=2;
            b=true;
        }
        if(a[l]==a[r]){
            l+=1;
            r-=1;
            b=true;
        }
    }
    if(l<=r){
        for(int i=r-2;i>=l+1;i-=2){
            if(a[l]==a[i]){
                b=find(l,i)&&find(i+1,r);
            }
        }
    }
    return b;
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j+=2){
            int l=i,r=j;
            if(find(l,r)){
                //cout<<l<<" "<<r<<endl;
                ans++;
            }
        }
    }
    cout<<ans;
    return 0;
}
