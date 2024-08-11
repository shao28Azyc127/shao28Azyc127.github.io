// kamisako

#include <cstdio>
#include <algorithm>
#include <cstring>
// #include <unordered_map>
using namespace std;

int rd(){
    int x=0,f=0;char ch=getchar();
    for(;ch<'0'||ch>'9';ch=getchar())f|=(ch=='-');
    for(;'0'<=ch&&ch<='9';ch=getchar())x=x*10+ch-'0';
    return f?-x:x;
}

char rdc(){
    char ch=getchar();
    for(;ch<'A'||ch>'Z';ch=getchar()){
        if(ch=='-'||ch=='+')return ch;
    }
    return ch;
}

/*
1 v
2 +
3 -
*/

const int maxn=1e5+10;

struct stam{
    int op,x,y,v;
} s[maxn];

int cas,t,n,m;
int vl[maxn],vvl[maxn];
int fv[maxn];
int mp[1010][1010];

inline int rc(int v){
    if(v==1)return 2;
    if(v==2)return 1;
    return 3;
}

int ans;
void force(int i,int v){
    // printf("%d %d\n",i,v);
    vvl[i]=v;
    if(i==n){
        for(int j=1;j<=n;++j){
            vl[j]=vvl[j];
        }
        for(int j=1;j<=m;++j){
            if(s[j].op==1){
                vl[s[j].x]=s[j].v;
            }else if(s[j].op==2){
                vl[s[j].x]=vl[s[j].y];
            }else{
                vl[s[j].x]=rc(vl[s[j].y]);
            }
        }
        bool fl=1;
        for(int j=1;j<=n;++j){
            if(vl[j]!=vvl[j]){fl=0;break;}
        }
        if(fl){
            int cnt=0;
            for(int j=1;j<=n;++j){
                if(vl[j]==3)++cnt;
            }
            ans=min(ans,cnt);
        }
        return;
    }
    force(i+1,v);
    v=(v+1)%3+1;
    force(i+1,v);
    v=(v+1)%3+1;
    force(i+1,v);
}

int main() {
    freopen("tribool.in","r",stdin);
    freopen("tribool.out","w",stdout);
    cas=rd(),t=rd();
    while(t--){
        n=rd(),m=rd();
        ans=n;
        for(int i=1;i<=m;++i){
            char ch=rdc();
            if(ch=='T')s[i].op=1,s[i].x=rd(),s[i].v=1;
            if(ch=='F')s[i].op=1,s[i].x=rd(),s[i].v=2;
            if(ch=='U')s[i].op=1,s[i].x=rd(),s[i].v=3;
            if(ch=='+')s[i].op=2,s[i].x=rd(),s[i].y=rd();
            if(ch=='-')s[i].op=3,s[i].x=rd(),s[i].y=rd();
        }
        if(1<=cas&&cas<=2){
            // printf("8778598778\n");
            // force
            // int ans=n;
            force(1,1);
            force(1,2);
            force(1,3);
            printf("%d\n",ans);
        }
        if(3<=cas&&cas<=4){
            memset(fv,0,sizeof(fv));
            // memset(vl,0,sizeof(vl));
            int cnt=0;
            for(int i=m;i>=1;--i){
                if(fv[s[i].x]==0){
                    fv[s[i].x]=s[i].v;
                    if(s[i].v==3)++cnt;
                }
            }
            printf("%d\n",cnt);
        }
        if(cas==5){
            memset(fv,0,sizeof(fv));
            int cnt=0;
            // for(int i=1;i<=m;++i){
            //     if(s[i].op==1)fv[s[i].x]=s[i].v;
            //     // if(s[i].op==2){
            //     //     if(fv[s[i].y]==3) fv[s[i].x]=fv[s[i].y];
            //     // }
            // }
            for(int k=1;k<=10000;++k){
                for(int i=1;i<=m;++i){
                    if(s[i].op==1)fv[s[i].x]=s[i].v;
                    if(s[i].op==2){
                        fv[s[i].x]=fv[s[i].y];
                    }
                }
            }
            // for(int i=m;i>=1;--i){
            //     if(s[i].op==2){
            //         // if(fv[s[i].y]==3)fv[s[i].x]=fv[s[i].y];
            //     }
            // }
            // for(int i=1;i<=n;++i){
            //     if(fv[i]==3)++cnt;
            // }
            // for(int i=1;i<=n;++i){
            //     printf("%d ",fv[i]);
            // }
            // printf("\n");

            // for(int i=m;i>=1;i--){
            //     if(s[i].op==1){
            //         if(fv[s[i].x]==0){
            //             fv[s[i].x]=3;
            //         }
            //     } else {
            //         fv[s[i].x]=fv[s[i].y];
            //     }
            // }
            for(int i=1;i<=n;++i){
                if(fv[i]==3)++cnt;
            }

            printf("%d\n",cnt);
        }
        if(cas==6){
            memset(fv,0,sizeof(fv));
            int cnt=0;
            // for(int i=1;i<=m;++i){
            //     if(s[i].op==1)fv[s[i].x]=s[i].v;
            //     // if(s[i].op==2){
            //     //     if(fv[s[i].y]==3) fv[s[i].x]=fv[s[i].y];
            //     // }
            // }
            for(int k=1;k<=100;++k){
                for(int i=1;i<=m;++i){
                    if(s[i].op==1)fv[s[i].x]=s[i].v;
                    if(s[i].op==2){
                        fv[s[i].x]=fv[s[i].y];
                    }
                }
            }
            // for(int i=m;i>=1;--i){
            //     if(s[i].op==2){
            //         // if(fv[s[i].y]==3)fv[s[i].x]=fv[s[i].y];
            //     }
            // }
            // for(int i=1;i<=n;++i){
            //     if(fv[i]==3)++cnt;
            // }
            // for(int i=1;i<=n;++i){
            //     printf("%d ",fv[i]);
            // }
            // printf("\n");

            // for(int i=m;i>=1;i--){
            //     if(s[i].op==1){
            //         if(fv[s[i].x]==0){
            //             fv[s[i].x]=3;
            //         }
            //     } else {
            //         fv[s[i].x]=fv[s[i].y];
            //     }
            // }
            for(int i=1;i<=n;++i){
                if(fv[i]==3)++cnt;
            }

            printf("%d\n",cnt);
        }
        if(7<=cas&&cas<=8){
            int cnt=0;
            for(int i=1;i<=m;++i){
                if(mp[s[i].y][s[i].x]==1&&(!mp[s[i].x][s[i].y]))++cnt;
                mp[s[i].x][s[i].y]=1;
            }
            printf("%d\n",cnt);
        }
    }

    return 0;
}

// it's better to play genshin than do this