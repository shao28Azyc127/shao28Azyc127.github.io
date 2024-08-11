#include <bits/stdc++.h>
using namespace std;
const int N=1e5+5;
int n;
long long a[N];
int b[N],c[N];

int h[N];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        scanf("%lld%d%d",&a[i],&b[i],&c[i]);
    }
    int u,v;
    for(int i=1;i<n;i++){
        scanf("%d%d",&u,&v);
    }
    int cnt=0;
    while(1){
        cnt++;
        bool flg=0;
        if(cnt<=n){
            for(int i=1;i<=cnt;i++){
                h[i]+=max(b[i]+cnt*c[i],1);
            }
            if(cnt==n){
                for(int i=1;i<=n;i++){
                    if(h[i]<a[i]){
                        flg=1;
                        break;
                    }
                }
                if(!flg) break;
            }
        }else{
            for(int i=1;i<=n;i++){
                h[i]+=max(b[i]+cnt*c[i],1);
                if(h[i]<a[i]) {
                    flg=1;
                    break;
                } 
            }
             if(!flg) break;
        }
       
    }
    cout<<cnt;
    return 0;
}