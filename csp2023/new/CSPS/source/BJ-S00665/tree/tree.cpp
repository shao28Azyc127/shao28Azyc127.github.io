//霸道总裁jp8和他的小娇妻jbh关于pvz的爱情故事
//在一个阳光明媚的下午，jbh点进了他所热爱的《植物大战僵尸2》，他要为学校的艺术节寻找灵感。游戏里有人向他发来了一条好友申请，那人的姓名是jb8。
//jp8帅气的头像贾果迅速吸引了jbh，jbh通过了jp8的好友申请。他们开始闲聊，逐渐了解对方，jbh愈发觉得自己开始喜欢jp8，jp8也开始对jbh有了兴趣。
//闲聊中，jbh得知了jp8是同城的一名学生，于是他们决定见一面。一个星期后，在一个傍晚的广场上，他们见到了对方。
//夕阳照映着他们二人的背影，他们的头在彩霞的衬托下越来越近……
//（后续在代码后面）
//    |
//    |
//    v
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int MAXN=100010;
int n;
struct point{
    int a,b,c;
}p[MAXN];
struct Edge{
    int v,nx;
}edge[MAXN];
int h[MAXN],CNT;
void init(){
    memset(h,-1,sizeof(h));
    CNT=0;
}
void add_side(int u,int v){
    edge[++CNT].v=v;
    edge[CNT].nx=h[u];
    h[u]=CNT;
    edge[++CNT].v=u;
    edge[CNT].nx=h[v];
    h[v]=CNT;
}
int d[MAXN],ans=1e18;
bool cs[MAXN];
bool check(int now,int x){
    if(p[now].c>=0){
        return (x-d[now]+1)*p[now].b+(d[now]+x)*(x-d[now]+1)*p[now].c/2>=p[now].a;
    }
    else{
        int stm=p[now].b/(-p[now].c);
        return (stm-d[now]+1)*p[now].b+(d[now]+stm)*(stm-d[now]+1)*p[now].c/2+x-stm+1>=p[now].a;
    }
}
void dfs(int now,int pt){
    if(now==1){
        d[now]=1;
        dfs(now+1,1);
        return;
    }
    if(now==n+1){
        int tmp=0;
        for(int i=1;i<=n;i++){
            if(p[i].c==0){
                tmp=max(tmp,(p[i].a-1)/p[i].b+1+d[i]-1);
            }
            else{
                int l=d[i],r=p[i].a;
                while(l<r){
                    int mid=(l+r)>>1;
                    if(check(i,mid)){
                        r=mid;
                    }
                    else {
                        l=mid+1;
                    }
                }
                tmp=max(tmp,l);
            }
        }
        ans=min(ans,tmp);
        return;
    }
    for(int j=h[pt];j!=-1;j=edge[j].nx){
        cs[edge[j].v]=1;
    }
    for(int i=1;i<=n;i++){
        if(cs[i]&&!d[i]){
            d[i]=now;
            dfs(now+1,i);
            d[i]=0;

        }
    }
    for(int j=h[pt];j!=-1;j=edge[j].nx){
        cs[edge[j].v]=0;
    }
}
bool B=1;
signed main(){init();
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    scanf("%lld",&n);
    for(int i=1;i<=n;i++){
        scanf("%lld%lld%lld",&p[i].a,&p[i].b,&p[i].c);
    }
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%lld%lld",&u,&v);
        add_side(u,v);
        if(u!=i||v!=i+1)B=0;
    }
    if(B){
        for(int i=1;i<=n;i++)d[i]=i;
        int tmp=0;
        for(int i=1;i<=n;i++){
            if(p[i].c==0){//zycakioi
                tmp=max(tmp,(p[i].a-1)/p[i].b+1+d[i]-1);
            }
            else{
                int l=d[i],r=p[i].a;
                while(l<r){
                    int mid=(l+r)>>1;
                    if(check(i,mid)){
                        r=mid;
                    }
                    else {
                        l=mid+1;//lylakioi
                    }
                }
                tmp=max(tmp,l);
            }
        }
        printf("%lld",tmp);
        fclose(stdin);
        fclose(stdout);
        return 0;
    }
    dfs(1,1);
    printf("%lld",ans);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
//jbh吃掉了jp8的头，并退出了游戏
