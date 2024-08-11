#include<bits/stdc++.h>
#define ll long long
#define mp make_pair
#define y1 yyyyyyyyy
#define l(x) lson[x]
#define r(x) rson[x]
using namespace std;
template<typename T>void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<1)+(x<<3)+(c-'0');
    x=x*f;
}

const int N=3e3+5;
const int M=9e6+5;
const int inf=1e9+5;

char a[N][N],b[N][N];
int n,m;

bool cmp(char x,char y){
    return x>y;
}

struct trie{
    int cnt,nxt[M],las[M],top[M];
    int siz[M],v[M];
    void insert(int id){
        int p=1;
        for(int i=1;i<=m;i++){
            int x=b[id][i]-'a'+1;
            if(!top[p]){
                v[++cnt]=x,top[p]=cnt,p=cnt;
                nxt[cnt]=inf,las[cnt]=0;
            }
            else if(top[p]){
                int pos=top[p];
                if(x<v[pos]){
                    v[++cnt]=x,top[p]=cnt,p=cnt;
                    las[cnt]=0,nxt[cnt]=pos,las[pos]=cnt;
                }
                else if(x>=v[pos]){
                    while(v[pos]<x&&nxt[pos]!=inf)
                        pos=nxt[pos];
                    if(v[pos]!=x){
                        pos=las[pos],v[++cnt]=x,p=cnt;
                        las[cnt]=pos,nxt[cnt]=nxt[pos];
                        las[nxt[pos]]=cnt,nxt[pos]=cnt;
                    }
                    else p=pos;
                }
            }
            siz[p]++;
        }
        //cout<<cnt<<endl;
        /*for(int i=1;i<=cnt;i++)
            cout<<siz[i]<<" ";
        cout<<endl;*/
    }
    int query(int id){
        int p=1,res=0;
        for(int i=1;i<=m;i++){
            int x=a[id][i]-'a'+1;
            int pos=top[p];
            //cout<<pos<<" "<<v[pos]<<endl;
            if(!pos) return res;
            while(v[pos]<x){
                res+=siz[pos];
                if(nxt[pos]==inf) break;
                else pos=nxt[pos];
            }
            if(v[pos]!=x) return res;
            else p=pos;
        }
        //cout<<res<<endl;
        return res;
    }
}t;

signed main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    read(n),read(m);
    for(int i=1;i<=n;i++){
        scanf("%s",a[i]+1);
        for(int j=1;j<=m;j++)
            b[i][j]=a[i][j];
    }
    for(int i=1;i<=n;i++){
        sort(a[i]+1,a[i]+m+1);
        sort(b[i]+1,b[i]+m+1,cmp);
    }
    t.cnt=1;
    for(int i=1;i<=n;i++)
        t.insert(i);
    for(int i=1;i<=n;i++)
        printf("%c",t.query(i)>0?'0':'1');
    printf("\n");
    return 0;
}
