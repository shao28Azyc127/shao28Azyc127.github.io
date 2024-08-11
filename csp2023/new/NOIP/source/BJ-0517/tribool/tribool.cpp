#include<bits/stdc++.h>
using namespace std;
const int Nmax=1e5+7;
int S,L,n,m;
int jl[Nmax];
int fa[Nmax],ffa[Nmax];
int tfu[Nmax],vis[Nmax],vviiss[Nmax],di[Nmax];
int fei(int x){
    if(x==1)return 2;
    if(x==2)return 1;
    if(x==3)return 3;
    return 0;
}
void init(){
    for(int yyy=1;yyy<=n;yyy++){
        fa[yyy]=yyy;
        vis[yyy]=0;
    }
}
int len;
int cnt;
int ffind(int x){
    if(ffa[x]!=x)ffa[x]=ffind(ffa[x]);
    return ffa[x];
}
void fiind(int x){
    if(fa[fa[x]]!=fa[x]){
        fiind(fa[x]);
    }
    if(jl[fa[x]]!=0){
        vis[x]=1;
        if(tfu[x]=='-'){
            jl[x]=fei(jl[fa[x]]);
        }
        else{
            jl[x]=jl[fa[x]];
        }
    }
}
int ans;
void dfs(int k,int cp){
    int ansc=999999;
    if(k==len+1){
        ansc=0;
        for(int uo=1;uo<=n;uo++){
            if(jl[uo]==3)ansc++;
        }
    }
    if(cp>ansc){
        cp=ansc;
        ans=ansc;
    }
    for(int po=1;po<=3;po++){
        jl[di[k]]=po;
        for(int ip=1;ip<=n;ip++){
            if(fa[ip]!=ip){
                fiind(ip);
            }
        }
        dfs(k+1,cp);
    }
    return;
}
int main(){//T-1 F-2 U-3
    freopen("tribool.in","r",stdin);
    cin>>S>>L;
    freopen("tribool.out","w",stdout);
    for(int pp=1;pp<=L;pp++){
        init();
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            char c;
            scanf("%c",&c);
            if(c=='+'||c=='-'){
                int a,b;
                scanf("%d %d",&a,&b);
                tfu[a]=c;
                fa[a]=b;
                ffa[a]=b;
            }
            else{
                int aa;
                scanf("%d",&aa);
                tfu[aa]=c;
            }
        }
        for(int i=1;i<=n;i++){
            if(fa[i]!=i&&vis[i]==0){
                fiind(i);
            }
        }
        for(int i=1;i<=n;i++){
            if(jl[i]==0){
                int fafa=ffind(i);
                int bbo=1;
                for(int j=1;j<=len;j++){
                    if(di[j]==fafa){
                        bbo=0;
                    }
                }
                if(bbo==1){
                    di[++len]=fafa;
                }
            }
        }
        dfs(1,999999);
        cnt=0;
        len=0;
        cout<<ans<<endl;
        ans=0;
    }
    return 0;
}
