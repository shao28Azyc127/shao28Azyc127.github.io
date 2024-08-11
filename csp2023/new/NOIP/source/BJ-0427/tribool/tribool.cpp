#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
struct node{
    char u;
    int x;
};
struct node1{
    int xx,yy;
}d[100005];
node a[100005];
int b[100005],w[100005],e[100005];
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    scanf("%d%d",&c,&t);
    if(c==3||c==4){
        while(t--){
            memset(b,0,sizeof(b));
            int n,m;
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                char ch;
                int tmp1;
                cin>>ch>>tmp1;
                a[i].u=ch;
                a[i].x=tmp1;
            }
            int ans1=0;
            for(int i=m;i>=1;i--){
                if(b[a[i].x]==0){
                    b[a[i].x]=1;
                    if(a[i].u=='U'){
                        ans1++;
                    }
                }
            }
            cout<<ans1<<endl;
        }
        return 0;
    }
    else{
        while(t--){
            long long ans1=0;
            memset(b,0,sizeof(b));
            memset(d,0,sizeof(d));
            memset(w,0,sizeof(w));
            memset(e,0,sizeof(e));
            int n,m;
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                char ch;
                int tmp1;
                cin>>ch;
                if(ch=='U'){
                    cin>>tmp1;
                    d[i].xx=-1;
                    d[i].yy=tmp1;
                    w[i]=1;
                }
                else{
                    if(ch=='+'){
                        w[i]=0;
                        int x1,y1;
                        cin>>x1>>y1;
                        d[i].xx=y1;
                        d[i].yy=x1;
                    }
                }
            }
            for(int i=m;i>=1;i--){
                if(e[d[i].yy]==0){
                    if(w[i]==1){
                        b[d[i].yy]=1;
                    }
                    e[d[i].yy]=d[i].xx;
                }
                else{
                    continue;
                }
            }
            for(int i=1;i<=n;i++){
                if(b[e[i]]==1){
                    b[i]=1;
                }
            }
            for(int i=1;i<=m;i++){
                if(w[i]==1){
                    continue;
                }
                if(b[d[i].xx]==1){
                    b[d[i].yy]=1;
                }
            }
                for(int i=1;i<=m;i++){
                if(w[i]==1){
                    continue;
                }
                if(b[d[i].xx]==1){
                    b[d[i].yy]=1;
                }
            }
            for(int i=1;i<=m;i++){
                if(w[i]==1){
                    continue;
                }
                if(b[d[i].xx]==1){
                    b[d[i].yy]=1;
                }
            }
            ans1=0;
            for(int i=1;i<=n;i++){
                if(b[i]==1){
                    ans1++;
                }
            }
            cout<<ans1<<endl;
        }
    }
    return 0;
}
