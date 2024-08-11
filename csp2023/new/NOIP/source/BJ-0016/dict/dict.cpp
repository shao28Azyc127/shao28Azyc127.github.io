# include <bits/stdc++.h>

using namespace std;

const int N=3005;

# define Rep(i,a,b) for(int i=a;i<=b;i++)
# define _Rep(i,a,b) for(int i=a;i>=b;i--)
# define RepG(i,u) for(int i=head[u];~i;i=e[i].next)

typedef long long ll;

# define chkmin(a,b) (a=min(a,b))
# define chkmax(a,b) (a=max(a,b))
# define PII pair<int,int>
# define mkp make_pair
# define ull unsigned long long

template<typename T> void read(T &x){
    x=0;int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-')f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}

int n,m;
int low[N],hig[N];
char s[N];

int main()
{
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    read(n),read(m);
    Rep(i,1,n){
        scanf("%s",s+1);
        low[i]=26;
        Rep(j,1,m)chkmin(low[i],s[j]-'a'),chkmax(hig[i],s[j]-'a');
    }
    Rep(i,1,n){
        bool flag=true;
        Rep(j,1,n){
            if(i==j)continue;
            if(low[i]>=hig[j]){
                flag=false;
                break;
            }
        }
        if(flag)printf("1");
        else printf("0");
    }
    puts("");
    return 0;
}