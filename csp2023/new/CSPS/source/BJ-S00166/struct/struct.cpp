#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int maxn=1e4+10;
const int maxm=100+10;
int t,tot,cnt,s;
struct node{
    char c[10];
    int k,mx;
    char ty[maxm][20];
    int sz[maxm];
}a[maxm];
struct vertex{
    int l,r,len;
    char pos[30];
}e[maxn];
inline void solve(){
    scanf("%d",&t);
    while(t--){
        int op;;
        scanf("%d",&op);
        if(op==1){
            ++tot;
            scanf("%s",a[tot].c);
            scanf("%d",&a[tot].k);
            int sr=0;
            for(int i=1;i<=a[tot].k;i++){
                char x[20];
                scanf("%s",x);
                scanf("%s",a[tot].ty[i]);
                int lenx=strlen(x);
                if(lenx==3){
                    a[tot].sz[i]=4;
                    if(sr%4)sr=sr+4-(sr%4);
                    sr+=4;
                }
                else if(lenx==4){
                    if(x[0]=='b'){
                        a[tot].sz[i]=1;
                        ++sr;
                    }
                    else {
                        a[tot].sz[i]=8;
                        if(sr%8)sr=sr+8-(sr%8);
                        sr+=8;
                    }
                }
                else {
                    a[tot].sz[i]=2;
                    if(sr%2)sr=sr+2-(sr%2);
                    sr+=2;
                }
                a[tot].mx=max(a[tot].mx,a[tot].sz[i]);
            }  
            printf("%d %d\n",sr,a[tot].mx);
        }
        else if(op==2){
            char x[20],y[20];
            scanf("%s",x);
            scanf("%s",y);
            int ans;
            int lens=strlen(x);
            if(x[0]=='b'&&x[1]=='y'&&x[2]=='t'&&x[3]=='e'&&lens==4){
                int leny=strlen(y);
                ++cnt;
                e[cnt].len=leny;
                for(int i=0;i<leny;i++)e[cnt].pos[i]=y[i];
                e[cnt].l=e[cnt].r=s;
                ++s;
                ans=e[cnt].l;
            }
            else if(x[0]=='l'&&x[1]=='o'&&x[2]=='n'&&x[3]=='g'&&lens==4){
                int leny=strlen(y);
                ++cnt;
                e[cnt].len=leny;
                for(int i=0;i<leny;i++)e[cnt].pos[i]=y[i];
                if(s%8)s=s+8-(s%8);
                e[cnt].l=s,e[cnt].r=s+7;
                s+=8;
                ans=e[cnt].l;
            }
            else if(x[0]=='i'&&x[1]=='n'&&x[2]=='t'&&lens==3){
                int leny=strlen(y);
                ++cnt;
                e[cnt].len=leny;
                for(int i=0;i<leny;i++)e[cnt].pos[i]=y[i];
                if(s%4)s=s+4-(s%4);
                e[cnt].l=s,e[cnt].r=s+3;
                s+=4;
                ans=e[cnt].l;
            }
            else if(x[0]=='s'&&x[1]=='h'&&x[2]=='o'&&x[3]=='r'&&x[4]=='t'&&lens==5){
                int leny=strlen(y);
                ++cnt;
                e[cnt].len=leny;
                for(int i=0;i<leny;i++)e[cnt].pos[i]=y[i];
                if(s%2)s=s+2-(s%2);
                e[cnt].l=s,e[cnt].r=s+1;
                s+=2;
                ans=e[cnt].l;
            }
            else {
                for(int i=1;i<=tot;i++){
                    int lena=strlen(a[i].c);
                    if(lena!=lens)continue;
                    bool flag=true;
                    for(int j=0;j<lena;j++){
                        if(a[i].c[j]!=x[j]){
                            flag=false;
                            break;
                        }
                    }
                    if(!flag)continue;
                    for(int j=1;j<=a[i].k;j++){
                        if(a[i].sz[j]==1){
                            int leny=strlen(y);
                            ++cnt;
                            int p=strlen(a[i].ty[j]);
                            e[cnt].len=leny+p+1;
                            for(int l=0;l<leny;l++)e[cnt].pos[l]=y[l];
                            e[cnt].pos[leny]='.';
                            for(int l=leny+1;l<leny+p+1;l++)e[cnt].pos[l]=a[i].ty[j][l-leny-1];
                            e[cnt].l=e[cnt].r=s;
                            ++s;
                        }
                        else if(a[i].sz[j]==8){
                            int leny=strlen(y);
                            ++cnt;
                            int p=strlen(a[i].ty[j]);
                            e[cnt].len=leny+p+1;
                            for(int l=0;l<leny;l++)e[cnt].pos[l]=y[l];
                            e[cnt].pos[leny]='.';
                            for(int l=leny+1;l<leny+p+1;l++)e[cnt].pos[l]=a[i].ty[j][l-leny-1];
                            if(s%8)s=s+8-(s%8);
                            e[cnt].l=s,e[cnt].r=s+7;
                            s+=8;
                        }
                        else if(a[i].sz[j]==4){
                            int leny=strlen(y);
                            ++cnt;
                            int p=strlen(a[i].ty[j]);
                            e[cnt].len=leny+p+1;
                            for(int l=0;l<leny;l++)e[cnt].pos[l]=y[l];
                            e[cnt].pos[leny]='.';
                            for(int l=leny+1;l<leny+p+1;l++)e[cnt].pos[l]=a[i].ty[j][l-leny-1];
                            if(s%4)s=s+4-(s%4);
                            e[cnt].l=s,e[cnt].r=s+3;
                            s+=4;
                        }
                        else if(a[i].sz[j]==2){
                            int leny=strlen(y);
                            ++cnt;
                            int p=strlen(a[i].ty[j]);
                            e[cnt].len=leny+p+1;
                            for(int l=0;l<leny;l++)e[cnt].pos[l]=y[l];
                            e[cnt].pos[leny]='.';
                            for(int l=leny+1;l<leny+p+1;l++)e[cnt].pos[l]=a[i].ty[j][l-leny-1];
                            if(s%2)s=s+2-(s%2);
                            e[cnt].l=s,e[cnt].r=s+1;
                            s+=2;
                        }
                    }
                    // ++cnt;
                    // e[cnt].l=e[cnt-a[i].k].l;
                    if(s%a[i].mx)s=s+a[i].mx-(s%a[i].mx);
                    // e[cnt].r=s;
                    // int leny=strlen(y);
                    // e[cnt].len=leny;
                    // for(int j=0;j<leny;j++)e[cnt].pos[j]=y[j];
                    ++s;
                    ans=e[cnt+1-a[i].k].l;
                }
                printf("%d\n",ans);
            }
        }
        else if(op==3){
            char x[20];
            scanf("%s",x);
            int lenx=strlen(x);
            for(int i=1;i<=cnt;i++){
                if(e[i].len!=lenx)continue;
                bool flag=true;
                for(int j=0;j<lenx;j++){
                    if(e[i].pos[j]!=x[j]){
                        flag=false;
                        break;
                    }
                }
                if(!flag)continue;
                printf("%d\n",e[i].l);
                break;
            }
        }
        else {
            int u;
            scanf("%d",&u);
            bool have=false;
            for(int i=1;i<=cnt;i++){
                if(e[i].l<=u&&u<=e[i].r){
                    // printf("IAKIOI\n");
                    have=true;
                    for(int j=0;j<e[i].len;j++)printf("%c",e[i].pos[j]);
                    printf("\n");
                    break;
                }
            }
            if(!have)printf("ERR\n");
        }
    }
}
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    solve();
    return 0;
}