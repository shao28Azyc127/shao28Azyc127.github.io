#include<bits/stdc++.h>
using namespace std;
struct node{
    string s,maxs,mins;
    int id;
}dat[3005],newdat[3005];
bool cmp(node a,node b){
    return a.s<b.s;
}
bool cmp1(node a,node b){
    return a.id<b.id;
}
int n,m;
bool can[3005];
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>dat[i].s;
        dat[i].id=i;
    }
    if(m==1){
        sort(dat+1,dat+n+1,cmp);
        can[dat[1].id]=1;
    }else if(m==2){
        for(int i=0;i<(1<<n);i++){
            for(int j=0;j<n;j++){
                if(i&(1<<j)) reverse(dat[j+1].s.begin(),dat[j+1].s.end());
            }
            for(int j=1;j<=n;j++) cout<<dat[j].s<<" ";
            cout<<i<<endl;
            sort(dat+1,dat+n+1,cmp);
            can[dat[1].id]=1;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) reverse(dat[j+1].s.begin(),dat[j+1].s.end());
            }
        }
    }else{
        //cout<<1<<endl;
        for(int i=1;i<=n;i++){
            dat[i].maxs=dat[i].s;
            dat[i].mins=dat[i].s;
            sort(dat[i].mins.begin(),dat[i].mins.end());
            sort(dat[i].maxs.begin(),dat[i].maxs.end(),greater<char>());
            //cout<<i<<endl;
            dat[i].s=dat[i].maxs;
        }
        for(int i=1;i<=n;i++){
            dat[i].s=dat[i].mins;
            sort(dat+1,dat+n+1,cmp);
            if(dat[1].id==i) can[i]=1;
            sort(dat+1,dat+n+1,cmp1);
            //cout<<i<<endl;
            dat[i].s=dat[i].maxs;
        }
    }
    for(int i=1;i<=n;i++)
        if(can[i]) cout<<1;
        else cout<<0;
    return 0;
}