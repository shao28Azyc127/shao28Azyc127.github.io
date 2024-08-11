//#define dbg
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+2;
int a[N];
int v[N];
int qzh[N];
int add[N];
long long ans=0;
long long nowv=0;
long long pnowv=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    qzh[1]=0;
    for(int i=1;i<n;i++){
        cin>>v[i];
        qzh[i+1]=qzh[i]+v[i];
    }
    int min1=N+2;
    //cout<<min1<<endl;
    int p1=0;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        if(i==n){
            a[i]=-1;
        }
        add[i]=i;
        if(a[i]<min1){
            min1=a[i];
            add[p1]=i;
            p1=i;
        }
    }
    int now=1;
    while(now<n){
        #ifdef dbg
        cout<<now<<endl;
        cout<<" nowv:"<<nowv<<endl;
        #endif
        nowv=(qzh[add[now]]-qzh[now])/d;
        #ifdef dbg
        cout<<nowv<<" "<<qzh[add[now]]-qzh[now]<<endl;
        #endif
        if(nowv*d<(qzh[add[now]]-qzh[now])){
            if(nowv*d+pnowv>=qzh[add[now]]-qzh[now]){
                pnowv=pnowv-(nowv*d+pnowv-qzh[add[now]]-qzh[now]);
            }
            else{
                nowv++;
            }
        }
        nowv=nowv*d;
        ans=ans+(nowv/d)*a[now];
        #ifdef dbg
        cout<<nowv<<" "<<ans<<endl;
        #endif
        pnowv=pnowv+nowv-(qzh[add[now]]-qzh[now]);
        now=add[now];
    }
    cout<<ans;
    return 0;
}