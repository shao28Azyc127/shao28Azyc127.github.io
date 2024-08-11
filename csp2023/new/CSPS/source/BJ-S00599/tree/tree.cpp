#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct Node{
    int a,b,c;
}t[maxn];
struct e{
    int u,v;
}g[maxn];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(false);
    int n,flaga=0,flagb=0,flagd=0;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t[i].a>>t[i].b>>t[i].c;
        if(t[i].c!=0) flaga=1;
    }
    for(int i=1;i<=n-1;i++){
        cin>>g[i].u>>g[i].v;
        if(g[i].u!=i||g[i].v!=i+1) flagb=1;
        if(g[i].u!=1) flagd=1;
    }
    if(flaga==0){

    }
    if(flagb==0){
        int ans=0;
        for(int i=1;i<=n;i++){
            double x=i;
            x=sqrt((t[i].c+t[i].b)*(t[i].c+t[i].b)-4*t[i].c*(t[i].c*i-i*i*t[i].c+t[i].b-t[i].b*i-t[i].a))-t[i].c-t[i].b;
            x=x/2.0;
            x/=t[i].c;
            cout<<x<<endl;
            ans=max(ans,(int)(ceil(x)));
        }
        cout<<ans<<endl;
    }
    if(flagd==0){

    }
}
//bruh no time to write partial pts. Estimate 0+0+0+0=0
//these OI problems might be the last ones im gonna do
//Goodbye OI.
//thanks to gdy and all classmates who helped me
//thanks to lxy zzz and shx for helping my OI
//if i dont pass the mid term test im gonna die, so rp++ for midterm test
//326 213 235 635 309 109 536 334 330 116 615 314 4040
//219(bushi