#include <bits/stdc++.h>
using namespace std;
#define LL long long
#define pb push_back
#define spc putchar(' ')
#define Enter putchar('\n')
void read(int &number){
    bool f=0;
    number=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number=number*10+(ch^48);
        ch=getchar();
    }
    if(f)number=-number;
}
void lread(LL &number){
    bool f=0;
    number=0;
    char ch=getchar();
    while(ch<'0'||ch>'9'){
        if(ch=='-')f=1;
        ch=getchar();
    }
    while(ch>='0'&&ch<='9'){
        number=number*10+(ch^48);
        ch=getchar();
    }
    if(f)number=-number;
}
void print(LL number){
    if(number<0){
        putchar('-');
        number=-number;
    }
    if(number>=10){
        print(number/10);
    }
    putchar((number%10)^48);
}
const int N=1e5+9;
struct node{
    int a,b;
}f[N];
void tr(node &x,node &y,int g){
    if(y.a==2){
        x.a=2;
        return;
    }
    if(y.a<=1){
        x.a=y.a^g;
        return;
    }
    x.a=3;
    if(g)x.b=-y.b;
    else x.b=y.b;
}
int vis[N];
int vt[N];
void dfs(int x,int y){
    if(vis[x]<=2)return;
    if(vt[x]!=2){
        if(y==vt[x]){
            vis[x]=1;
            return;
        }
        else{
            vis[x]=2;
            return;
        }
    }
    int s=abs(f[x].b);
    if(s==x){
        if(f[x].b<0)vis[x]=2;
        else vis[x]=1;
        return;
    }
    vt[x]=y;
    if(f[x].b<0)dfs(s,y^1);
    else dfs(s,y);
    vt[x]=2;
    if(vis[s]==2){
        vis[x]=2;
        return;
    }
    if(f[x].b<0){
        vis[x]=vis[s]^1;
    }
    else{
        vis[x]=vis[s];
    }
}
int main(){
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    int t,x,y,n,m;
    char ch;
    scanf("%d",&n),scanf("%d",&t);
    for(int svp=1;svp<=t;svp++){
        scanf("%d %d ",&n,&m);
        for(int i=1;i<=n;i++){
            f[i].a=3;
            f[i].b=i;
            vis[i]=3;
            vt[i]=2;
        }
        for(int i=1;i<=m;i++){
            cin>>ch;
            switch(ch){
                case '-':{
                    scanf("%d %d",&x,&y);
                    tr(f[x],f[y],1);
                    break;
                }
                case '+':{
                    scanf("%d %d",&x,&y);
                    tr(f[x],f[y],0);
                    break;
                }
                case 'U':{
                    scanf("%d",&x);
                    f[x].a=2;
                    break;
                }
                case 'T':{
                    scanf("%d",&x);
                    f[x].a=1;
                    break;
                }
                case 'F':{
                    scanf("%d",&x);
                    f[x].a=0;
                    break;
                }
            }
        }
        // for(int i=1;i<=n;i++){
        //     print(f[i].a),spc;
        //     if(f[i].a==3)print(f[i].b);
        //     Enter;
        // }
        // Enter;
        int ans=0;
        for(int i=1;i<=n;i++){
            if(f[i].a<=2){
                vis[i]=f[i].a;
                if(vis[i]==2)++ans;
            }
        }
        // for(int i=1;i<=n;i++)print(vis[i]),spc;
        // Enter;
        for(int i=1;i<=n;i++){
			if(f[i].a<3)continue;
            dfs(i,1);
            if(vis[i]==2)++ans;
        }
        print(ans),Enter;
    }
    return 0;
}
