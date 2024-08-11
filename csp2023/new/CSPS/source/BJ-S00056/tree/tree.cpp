#include<bits/stdc++.h>
using namespace std;
int a[1000],b[1000],c[1000],u[1000],v[1000];
int minnnn(int x,int y){
    int tmp,tmp_ans;
    for(int i=1;i<=n;i++){
        if(u[i]==x){
            tmp=v[i];
            tmp_ans++;
        }
    }
    if(tmp_ans<y) return tmp_ans;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n,ans;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<=n-1;i++){
        cin>>u[i]>>v[i];
    }
    for(int i=1;i<=n;i++){
        ans=max(b[i]+i*c[i],1);
    }
    cout<<ans;
    return 0;
}
