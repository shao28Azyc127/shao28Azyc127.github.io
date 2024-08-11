#include<iostream>
#include<cstdio>
using namespace std;
long long v[100010],a[100010];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    long long youjia=a[1],kezou=0,huaqian=0;
    for(int i=1;i<=n;i++){
        if(a[i]<youjia)youjia=a[i];
        long long xuzou=v[i]-kezou;
        long long yaomai=(xuzou+d-1)/d;
        huaqian+=yaomai*youjia;
        kezou+=yaomai*d;
        kezou-=v[i];
    }
    cout<<huaqian;
    return 0;
}
