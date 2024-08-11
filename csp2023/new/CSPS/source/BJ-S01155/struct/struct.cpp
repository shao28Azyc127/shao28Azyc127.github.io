# include <bits/stdc++.h>

using namespace std;

const int N=105;

typedef long long ll;

# define Rep(i,a,b) for(int i=a;i<=b;i++)
# define _Rep(i,a,b) for(int i=a;i>=b;i--)
# define RepG(i,u) for(int i=head[u];~i;i=e[i].next)
# define chkmax(a,b) (a=max(a,b))
# define chkmin(a,b) (a=min(a,b))
# define PII pair<int,int>
# define mkp make_pair

template<typename T> void read(T &x){
    x=0;int f=1;
    char c=getchar();
    for(;!isdigit(c);c=getchar())if(c=='-') f=-1;
    for(;isdigit(c);c=getchar())x=x*10+c-'0';
    x*=f;
}

int q;
map<string,int> var;

struct node{
    int n;
    ll a[N],s[N],o[N];
    map<string,int> dir;
    map<string,int> loc;
    string nos[N];
}a[N*N+100];
int tot;
string Q;
int Ql;

string rect(string s){
    string t="";
    int len=s.size();
    for(int i=0;i<len;i++)
        if(s[i]=='.'||(s[i]>='a'&&s[i]<='z'))t+=s[i];
        else break;
    return t;
}

ll fact(ll x,ll y){
    if(x%y==0)return x;
    else return (x/y+1)*y;
}

ll dfs1(int x,int st){
    string s="";
    while(st<Ql&&Q[st]!='.')s+=Q[st],st++;
    // cout<<s<<endl;
    // printf("???%d %d\n",st,Ql);
    if(st>=Ql)return a[x].o[a[x].loc[s]];
    else return a[x].o[a[x].loc[s]]+dfs1(a[x].dir[s],st+1);
}

bool dfs2(int x,ll k){
    if(1<=x&&x<=4)return true;
    int l=1,r=a[x].n,p=0;
    while(l<=r){
        int mid=l+r>>1;
        if(a[x].o[mid]<=k)p=mid,l=mid+1;
        else r=mid-1;
    }
    if(a[x].o[p]<=k&&k<a[x].o[p]+a[x].s[p]){
        if(x!=0)Q+='.';
        Q+=a[x].nos[p];
        return dfs2(a[x].dir[a[x].nos[p]],k-a[x].o[p]);
    }
    else{
        Q="ERR";
        return false;
    }
}

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    a[1].a[0]=a[1].s[0]=1;
    a[2].a[0]=a[2].s[0]=2;
    a[3].a[0]=a[3].s[0]=4;
    a[4].a[0]=a[4].s[0]=8;
    var["byte"]=var["byte"]=1;
    var["short"]=var["short"]=2;
    var["int"]=var["int"]=3;
    var["long"]=var["long"]=4;
    tot=4;
    cin>>q;
    string tmp;
    while(q--){
        int opt;
        cin>>opt;
        if(opt==1){
            string name;
            cin>>tmp;
            name=rect(tmp);
            var[name]=++tot;
            cin>>a[tot].n;
            Rep(i,1,a[tot].n){
                string type,deno;
                cin>>tmp;type=rect(tmp);
                cin>>tmp;deno=rect(tmp);
                a[tot].dir[deno]=var[type];
                a[tot].loc[deno]=i;
                a[tot].nos[i]=deno;
                a[tot].a[i]=a[var[type]].a[0];
                chkmax(a[tot].a[0],a[tot].a[i]);
                a[tot].s[i]=a[var[type]].s[0];
                a[tot].o[i]=fact(a[tot].o[i-1]+a[tot].s[i-1],a[tot].a[i]);
            }
            a[tot].s[0]=fact(a[tot].o[a[tot].n]+a[tot].s[a[tot].n],a[tot].a[0]);
            printf("%lld %lld\n",a[tot].s[0],a[tot].a[0]);
        }
        if(opt==2){
            string type,deno;
            cin>>tmp;type=rect(tmp);
            cin>>tmp;deno=rect(tmp);
            a[0].n++;
            a[0].dir[deno]=var[type];
            a[0].loc[deno]=a[0].n;
            a[0].nos[a[0].n]=deno;
            int x=a[0].n;
            a[0].a[x]=a[var[type]].a[0];
            a[0].s[x]=a[var[type]].s[0];
            a[0].o[x]=fact(a[0].o[x-1]+a[0].s[x-1],a[0].a[x]);
            printf("%lld\n",a[0].o[x]);
        }
        if(opt==3){
            cin>>tmp;Q=rect(tmp),Ql=Q.size();
            cout<<dfs1(0,0)<<endl;
        }
        if(opt==4){
            ll addr;
            cin>>addr;
            Q="";
            dfs2(0,addr);
            cout<<Q<<endl;
        }
    }
    return 0;
}