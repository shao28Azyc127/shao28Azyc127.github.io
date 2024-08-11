#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int val[1000050],op[1000050];
int ans[1000050];
int n,m;
int fa[1000050];
int fnd(int p){
    if(p==fa[p])return p;
    return fa[p]=fnd(fa[p]);
}
int mer(int p,int p2){
    fa[fnd(p)]=fnd(p2);
}
int qus(int p,int p2){
    if(fnd(p)==fnd(p2))return 1;
    return 0;
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int c,t;
    cin>>c>>t;
    if(c==5||c==6)
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i)val[i]=i,op[i]=1,fa[i]=i;
        for(int i=1;i<=m;i++){
            char ch;
            cin>>ch;
            if(ch=='+'){
                int a,b;
                //cout<<a<<"-"<<b<<endl;
                scanf("%d%d",&a,&b);
                if(val[b]!=0){
                    val[a]=val[b];op[a]=op[b];
                }else{
                    val[a]=0;op[a]=op[b];
                }
            }

            if(ch=='-'){
                int a,b;
                scanf("%d%d",&a,&b);
                if(val[b]!=0){
                    val[a]=val[b];op[a]=-op[b];
                }else{
                    val[a]=0;op[a]=-op[b];
                }
            }
            if(ch=='F'){
                int a;
                scanf("%d",&a);
                val[a]=0;op[a]=-1;
            }
            if(ch=='T'){
                int a;
                scanf("%d",&a);
                val[a]=0;op[a]=1;
            }
            if(ch=='U'){
                int a;
                scanf("%d",&a);
                val[a]=0;op[a]=0;
            }
        }
        for(int i=1;i<=n;i++){
            if(op[i]==0)mer(i,n+1);
            else if(op[i]==1)mer(i,val[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
            if(qus(i,n+1))ans++;
        }
        cout<<ans<<endl;
    }
    if(c==7||c==8){
        while(t--){
        cin>>n>>m;
        for(int i=1;i<=n;++i)val[i]=i,op[i]=1,fa[i]=i;
        for(int i=1;i<=m;i++){
            char ch;
            cin>>ch;
            if(ch=='+'){
                int a,b;
                //cout<<a<<"-"<<b<<endl;
                scanf("%d%d",&a,&b);
                if(val[b]!=0){
                    val[a]=val[b];op[a]=op[b];
                }else{
                    val[a]=0;op[a]=op[b];
                }
            }

            if(ch=='-'){
                int a,b;
                scanf("%d%d",&a,&b);
                if(val[b]!=0){
                    val[a]=val[b];op[a]=-op[b];
                }else{
                    val[a]=0;op[a]=-op[b];
                }
            }
            if(ch=='F'){
                int a;
                scanf("%d",&a);
                val[a]=0;op[a]=-1;
            }
            if(ch=='T'){
                int a;
                scanf("%d",&a);
                val[a]=0;op[a]=1;
            }
            if(ch=='U'){
                int a;
                scanf("%d",&a);
                val[a]=0;op[a]=0;
            }
        }
        for(int i=1;i<=n;i++){
            if(op[i]==1)mer(n+i,n+val[i]);
            else if(op[i]==-1)mer(i,val[i]);
        }
        int ans=0;
        for(int i=1;i<=n;i++){
                if(qus(i+n,i))mer(i+n,2*n+1);
        }
        for(int i=1;i<=n;i++){
            if(qus(i,n+n+1))ans++;
        }
        cout<<ans<<endl;
    }
    }
}
