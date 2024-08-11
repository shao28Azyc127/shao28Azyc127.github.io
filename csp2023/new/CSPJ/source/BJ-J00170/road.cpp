#include<bits/stdc++.h>
using namespace std;

int v[100001],a[100001];

int you(int s,int d){
    int a=s/d;
    if(s%d)
        a++;
    return a;
}
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);

    int n,d;
    int ans=0,els=0; //π´¿Ô ˝
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>v[i];
    }
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }

    a[0]=0x3f3f3f3f;
    for(int i=1;i<n;i++){
        if(els>v[i]){
            els-=v[i];
            v[i]=0;
        }
        else{
            v[i]-=els;
            els=0;
        }
        if(a[i]>a[i-1])
            a[i]=a[i-1];
        int l=you(v[i],d);//”Õ
        ans+=l*a[i];
        els+=l*d-v[i];
    }
    cout<<ans;
    return 0;
}
