#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],cur,b[1000010],f[1000010],t=0;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) a[i]=i;
    while(cur!=1){
            t++;
        cur=0;
        for(int i=1;i<=n;i+=3){
            f[a[i]]=t;
            a[i]=0;
        }
        for(int i=1;i<=n;i++)
            if(a[i]!=0){
                cur++;
                b[cur]=a[i];
            }
        for(int i=cur;i<=n;i++)a[i]=0;
        for(int i=1;i<=cur;i++)
            a[i]=b[i];
    }
    f[a[cur]]=t+1;
    cout<<t+1<<" "<<f[n];
    return 0;
}
