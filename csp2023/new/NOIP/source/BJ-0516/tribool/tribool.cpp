#include<bits/stdc++.h>
using namespace std;
int c,t,n,m,x,y,ans,val[400005],fa[400005];
int xn[20],yyn[20],tarf,tarz,head[400005],tot,tmp,cr[20],cf[20];
char cc,opr[20];
bool v[400005];
struct stu{
    int to;
    int nxt;
}w[800005];
int fd(int xx){
    if(fa[xx]==xx)
        return xx;
    return fa[xx]=fd(fa[xx]);
}
void ade(int xx,int yy){
    w[++tot].to=yy;
    w[tot].nxt=head[xx];
    head[xx]=tot;
}
void dfs(int xx){
    v[xx]=true;
    if(val[xx]==-2)
        val[xx]=tarf;
    else
        val[xx]=tarz;
    for(int i=head[xx];i;i=w[i].nxt){
        if(v[w[i].to]==true)
            continue;
        dfs(w[i].to);
    }
}
void dd(int step){
    if(step>n){
        for(int i=1;i<=n;i++)
            cf[i]=cr[i];
        for(int i=1;i<=m;i++){
            if(opr[i]=='+')
                cf[xn[i]]=cf[yyn[i]];
            else if(opr[i]=='-'){
                if(cf[yyn[i]]==1)
                    cf[xn[i]]=1;
                else
                    cf[xn[i]]=0-cf[yyn[i]];
            }
            else if(opr[i]=='U')
                cf[xn[i]]=1;
            else if(opr[i]=='T')
                cf[xn[i]]=2;
            else
                cf[xn[i]]=-2;
        }
        bool flag=false;
        for(int i=1;i<=n;i++){
            if(cr[i]!=cf[i])
                flag=true;
        }
        if(flag==false){
            int cnt=0;
            for(int i=1;i<=n;i++){
                if(cr[i]==1)
                    cnt++;
            }
            ans=min(ans,cnt);
        }
        return;
    }
    cr[step]=1;
    dd(step+1);
    cr[step]=2;
    dd(step+1);
    cr[step]=-2;
    dd(step+1);
}
void wk(){
    while(t--){
        cin>>n>>m;
        for(int i=1;i<=m;i++){
            cin>>opr[i];
            if(opr[i]=='T'||opr[i]=='F'||opr[i]=='U')
                cin>>xn[i];
            else
                cin>>xn[i]>>yyn[i];
        }
        ans=n;
        dd(1);
        cout<<ans<<endl;
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cin>>c>>t;
    if(c<=2){
        wk();
        return 0;
    }
    while(t--){
        cin>>n>>m;
        tot=0;
        for(int i=1;i<=(2*n);i++){
            val[i]=0;
            v[i]=false;
            fa[i]=i;
            head[i]=0;
            w[i].to=0;
            w[i].nxt=0;
        }
        while(m--){
            cin>>cc;
            if(cc=='T'){
                cin>>x;
                if(val[x]==0)
                    val[x]=1;
                else if(val[x]==1)
                    continue;
                else if(val[x]==-2){
                    tarf=1;
                    tarz=-1;
                dfs(x);
                }
                else{
                    tarf=-1;
                    tarz=1;
                    dfs(x);
                }
            }
            else if(cc=='F'){
                cin>>x;
                if(val[x]==0)
                    val[x]=-1;
                else if(val[x]==-1)
                    continue;
                else if(val[x]==-2){
                    tarf=-1;
                    tarz=1;
                    dfs(x);
                }
                else{
                    tarf=1;
                    tarz=-1;
                    dfs(x);
                }
            }
            else if(cc=='U'){
                cin>>x;
                if(val[x]==3)
                    continue;
                if(val[x]==0)
                    val[x]=3;
                else if(val[x]==2){
                    tarf=3;
                    tarz=3;
                    dfs(x);
                }
                else{
                    tarf=3;
                    tarz=3;
                    dfs(x);
                }
            }
            else if(cc=='+'){
                cin>>x>>y;
                if(val[x]==3||val[y]==3){
                    if(val[x]==val[y])
                        continue;
                    if(val[x]==3){
                        val[y]=3;
                        tarz=3;
                        tarf=3;
                        dfs(y);
                    }
                    else{
                        val[x]=3;
                        tarz=3;
                        tarf=3;
                        dfs(x);
                    }
                    continue;
                }
                if(val[x]==0&&val[y]==0){
                    val[x]=2;
                    val[y]=2;
                    fa[fd(x)]=fd(y);
                    ade(x,y);
                    ade(y,x);
                }
                else if(val[x]==0){
                    val[x]=val[y];
                    fa[fd(x)]=fd(y);
                    ade(x,y);
                    ade(y,x);
                }
                else if(val[y]==0){
                    val[y]=val[x];
                    fa[fd(x)]=fd(y);
                    ade(x,y);
                    ade(y,x);
                }
                else{
                    if(val[x]==val[y])
                        continue;
                    if((val[x]==1&&val[y]==-1)||(val[x]==-1&&val[y]==1)){
                        if(fd(x)==fd(y)){
                            val[x]=3;
                            tarz=3;
                            tarf=3;
                            dfs(x);
                        }
                        else{
                            val[x]=3;
                            val[y]=3;
                            tarz=3;
                            tarf=3;
                            dfs(x);
                            dfs(y);
                        }
                    }
                    else{
                        if(fd(x)!=fd(y)){
                            fa[fd(x)]=fd(y);
                            ade(x,y);
                            ade(y,x);
                            if(val[x]==-1||val[x]==1||val[y]==1||val[y]==-1){
                                tarz=1;
                                tarf=-1;
                                dfs(x);
                            }
                            else{
                                tarz=val[y];
                                tarf=-val[y];
                                dfs(y);
                            }
                        }
                        else{
                            val[x]=3;
                            tarz=3;
                            tarf=3;
                            dfs(x);
                        }
                    }
                }
            }
            else{
                cin>>x>>y;
                if(val[x]==3||val[y]==3){
                    if(val[x]==val[y])
                        continue;
                    if(val[x]==3){
                        val[y]=3;
                        tarz=3;
                        tarf=3;
                        dfs(y);
                    }
                    else{
                        val[x]=3;
                        tarz=3;
                        tarf=3;
                        dfs(x);
                    }
                    continue;
                }
                if(val[x]==0&&val[y]==0){
                    val[x]=2;
                    val[y]=-2;
                    fa[fd(x)]=fd(y);
                    ade(x,y);
                    ade(y,x);
                }
                else if(val[x]==0){
                    val[x]=0-val[y];
                    fa[fd(x)]=fd(y);
                    ade(x,y);
                    ade(y,x);
                }
                else if(val[y]==0){
                    val[y]=0-val[x];
                    fa[fd(x)]=fd(y);
                    ade(x,y);
                    ade(y,x);
                }
                else{
                    if(val[x]==(0-val[y]))
                        continue;
                    if((val[x]==1&&val[y]==1)||(val[x]==-1&&val[y]==-1)){
                        if(fd(x)==fd(y)){
                            val[x]=3;
                            tarz=3;
                            tarf=3;
                            dfs(x);
                        }
                        else{
                            val[x]=3;
                            val[y]=3;
                            tarz=3;
                            tarf=3;
                            dfs(x);
                            dfs(y);
                        }
                    }
                    else{
                        if(fd(x)!=fd(y)){
                            if(val[x]==-1||val[x]==1||val[y]==1||val[y]==-1){
                                if(val[x]==1||val[x]==-1){
                                    tmp=0-val[x];
                                    if(val[y]>0){
                                        tarz=tmp;
                                        tarf=0-tmp;
                                    }
                                    else{
                                        tarz=0-tmp;
                                        tarf=tmp;
                                    }
                                    dfs(y);
                                }
                                else{
                                    tmp=0-val[y];
                                    if(val[x]>0){
                                        tarz=tmp;
                                        tarf=0-tmp;
                                    }
                                    else{
                                        tarz=0-tmp;
                                        tarf=tmp;
                                    }
                                    dfs(x);
                                }
                                tarz=1;
                                tarf=-1;
                                dfs(x);
                            }
                            else{
                                tmp=0-val[y];
                                if(val[x]>0){
                                    tarz=tmp;
                                    tarf=0-tmp;
                                }
                                else{
                                    tarz=0-tmp;
                                    tarf=tmp;
                                }
                                dfs(x);
                            }
                            fa[fd(x)]=fd(y);
                            ade(x,y);
                            ade(y,x);
                        }
                        else{
                            val[x]=3;
                            tarz=3;
                            tarf=3;
                            dfs(x);
                        }
                    }
                }
            }
        }
        ans=0;
        for(int i=1;i<=n;i++){
            if(val[i]==3)
                ans++;
        }
        cout<<ans<<endl;
    }
    return 0;
}
