#include<bits/stdc++.h>
using namespace std;
int a[500005];
int b[500005];
//int stk_min[500005],stk_max[500005];
int c,n,m,q;
//int r_min,r_max;
//int pos_min[500005],pos_max[500005];
//int ans[65];
struct node{
    int pos,val;
}xga[500005],xgb[500005];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("expand.in","r",stdin);
   freopen("expand.out","w",stdout);
    cin>>c>>n>>m>>q;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=m;i++){
        cin>>b[i];
    }
    if(a[1]==b[1]){
        cout<<0;
    }
    else if(a[1]>b[1]){
        bool flag=1;
        if(a[n]<=b[m])cout<<0;
        else{
              //  cout<<"afas"<<endl;
            int now=0;
            for(int i=1;i<=n;i++){
                if(a[i]>a[i-1]||i==1){
                    while(a[i]>b[now+1] && now<m)now++;
                }
                if(a[i]<a[i-1]){
                    while(a[i]<b[now]&& now!=0)now--;
                }
                if(now==0){
                    cout<<0,flag=0;
                    break;
                }
            }
            if(flag)cout<<(now==m?1:0);
        }
    }
    else{
        bool flag=1;
        if(a[n]>=b[m])cout<<0;
        else{
            int now=0;
            for(int i=1;i<=m;i++){
                if(b[i]>b[i-1]||i==1){
                    while(b[i]>a[now+1] && now<n)now++;
                }
                if(b[i]<b[i-1]){
                    while(b[i]<a[now]&& now!=0)now--;
                }
                if(now==0){
                    cout<<0,flag=0;
                    break;
                }
            }
            if(flag)cout<<(now==n?1:0);
        }
    }
    while(q--){
         //   cout<<q<<endl;
        //now=0;
        int kx,ky;
        cin>>kx>>ky;
        //cout<<q<<endl;
        for(int i=1;i<=kx;i++){
            int x,y;
            cin>>x>>y;
            //cout<<i<<" "<<x<<endl;
            xga[i].pos=x,xga[i].val=a[x];
            a[x]=y;
        }
        //cout<<q<<endl;
        for(int i=1;i<=ky;i++){
            int x,y;
            cin>>x>>y;
            xgb[i].pos=x,xgb[i].val=b[x];
            b[x]=y;
        }
        //cout<<q<<endl;
        if(a[1]==b[1]){
            cout<<0;
        }
        else if(a[1]>b[1]){
            bool flag=1;
            if(a[n]<=b[m])cout<<0;
            else{
                  //  cout<<"afas"<<endl;
                int now=0;
                for(int i=1;i<=n;i++){
                    if(a[i]>a[i-1]||i==1){
                        while(a[i]>b[now+1] && now<m)now++;
                    }
                    if(a[i]<a[i-1]){
                        while(a[i]<b[now]&& now!=0)now--;
                    }
                    if(now==0){
                        cout<<0,flag=0;
                    break;
                    }
                }
                if(flag)cout<<(now==m?1:0);
            }
        }
        else{
            bool flag=1;
            if(a[n]>=b[m])cout<<0;
            else{
                int now=0;
                for(int i=1;i<=m;i++){
                    if(b[i]>b[i-1]||i==1){
                        while(b[i]>a[now+1] && now<n)now++;
                    }
                    if(b[i]<b[i-1]){
                        while(b[i]<a[now]&& now!=0)now--;
                    }
                    if(now==0){
                        cout<<0,flag=0;
                        break;
                    }
                }
                if(flag)cout<<(now==n?1:0);
            }
        }
        for(int i=1;i<=kx;i++){
            a[xga[i].pos]=xga[i].val;
        }
        for(int i=1;i<=ky;i++){
            b[xgb[i].pos]=xgb[i].val;
        }
        //cout<<q<<endl;
    }
}
