//Orz dls
//Orz wsc
//Orz lhk
//Orz lzc
//Orz xht
//Orz dyh
//Orz xhr
//Orz dhx
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,a[100005],b[100005],c[100005],flag=1,flag1=1;
vector<int> Adj[100005];
int suma[100005],sumb[100005],sumc[100005];
void solve(){

}
int calc(int A,int B,int C){
    int l=0,ans=0,r=1000000000;
    while(l<=r){
            int mid=l+r>>1;
        if(mid*C+B>1){
            ans=mid;l=mid+1;
        }else r=mid-1;
    }
    int SSum=ans*B-C*(ans*(ans+1))/2;
    if(SSum>=A){
        int l=0,r=ans,Ans=0;
        while(l<=r){
            int mid=l+r>>1;
            if(ans*B-C*(ans*(ans+1))/2>=A) Ans=mid,r=mid-1;
            else l=mid+1;
        }
        return Ans;
    }else{
        return ans+(A-ans);
    }
    return 0;
}
void solve2(){
    int Day=-2e9,Next=1;
    Day=max(Day,calc(a[Next],b[Next],c[Next])+1);
    for(int i=2;i<=n;++i){
        int Now=0;
        for(int j=0;j<Adj[Next].size();++j){
            if(Adj[i][j]!=Next){Now=Adj[i][j];break;}
        }
        Day=max(Day,calc(a[Now],b[Now],c[Now])+i);
        Now=Next;

    }
    cout<<Day<<'\n';
}
signed main(){
     //freopen("tree.in","r",stdin);
    //freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>a[i]>>b[i]>>c[i];
        suma[i]=suma[i-1]+a[i];
        sumb[i]=sumb[i-1]+b[i];
        sumc[i]=sumb[i-1]+c[i];
    }
    for(int i=1,u,v;i<n;++i){
        cin>>u>>v;
        Adj[u].push_back(v);
        Adj[v].push_back(u);
        if(u!=1) flag=0;
        if(v!=i+1&&u!=i) flag1=0;
    }
    if(flag) solve();
    else if(flag1) solve2();
    else cout<<n;
    return 0;
}
/*
5
1 1 1
1 1 1
2 1 1
2 1 1
2 1 -1
1 2
2 3
3 4
4 5
*/
