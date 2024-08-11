#include<iostream>
#include<vector>
#include<cstring>
using namespace std;
int a[100005];
int ind[100005];
struct E{
    int to,c;
};
int fa[100005];
vector<E> v[100005];
int getfa(int x,int f){
    if(fa[x]==x){
        return x;
    }else{
        if(f==-1){
            return fa[x]=-1*(getfa(fa[x],1));
        }else{
            return fa[x]=(getfa(fa[x],f));
        }
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==3||c==4){
        while(t--){
            memset(a,0,sizeof(a));
            int n,m;
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                char op;
                cin>>op;
                if(op=='U'){
                    int x;
                    cin>>x;
                    a[x]=3;
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==3)
                    cnt++;
            }
            cout<<cnt<<endl;
        }
        return 0;
    }
    if(c==5||c==6){
        while(t--){
            memset(a,0,sizeof(a));
            int n,m;
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                char op;
                cin>>op;
                if(op=='U'){
                    int x;
                    cin>>x;
                    a[x]=-3;
                }
                if(op=='+'){
                    int x,y;
                    cin>>x>>y;
                    a[x]=a[y];
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==-3)
                    cnt++;
            }
            cout<<cnt<<endl;
        }
        return 0;
    }
    if(c==7||c==8){
        while(t--){
            memset(a,0,sizeof(a));
            int n,m;
            cin>>n>>m;
            for(int i=1;i<=m;i++){
                char op;
                cin>>op;
                if(op=='+'){
                    int x,y;
                    cin>>x>>y;
                    v[x].push_back({y,1});
                }
                if(op=='-'){
                    int x,y;
                    cin>>x>>y;
                    a[x]=a[y];
                }
            }
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(a[i]==-3)
                    cnt++;
            }
            cout<<cnt<<endl;
        }
        return 0;
    }
    while(t--){
        memset(a,0,sizeof(t));
        int n,m;
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            char op;
            cin>>op;
            if(op=='-'){
                int x,y;
                cin>>x>>y;
                fa[x]=getfa(y,-1);
            }
            if(op=='+'){
                int x,y;
                cin>>x>>y;
                fa[x]=getfa(y,1);
            }
            if(op=='F'){
                int x,y;
                cin>>x>>y;
                a[x]=1;
            }
            if(op=='T'){
                int x,y;
                cin>>x>>y;
                a[x]=1;

            }
        }
    }
    return 0;
}
