#include<bits/stdc++.h>
using namespace std;
struct gl{
    int v,b;
}a[100005];
int f[100005];
int main(){
    int n;
    double d;
    //freopen("apple.in","r",strdin);
    //freopen("apple.out","w",stdout);
    cin>>n>>d;
    for(int i=0;i<n-1;i++){
        cin>>a[i].v;
    }
    for(int i=0;i<n;i++){
        cin>>a[i].b;
    }
    f[0]=0;
    f[1]=ceil(a[0].b/d)*a[0].b;
    for(int i=2;i<=n;i++){
        long long  m=1<<60;
        long long ans=0;
        for(int j=i-1;j>=0;j--){
            ans=ans+a[i].v;
            p=ceil(d/ans)*a[j].b
            m=max(m,p);
        }
        f[i]=m;
    }
    cout<<f[n-1];
    //frcolse(strin);
    //frcolse(stdout);
    return 0;
}
