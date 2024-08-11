#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<ctime>
#include<cstdlib>
#include<vector>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<unordered_map>
#define fup(i,l,r) for(int i=l;i<=r;i++)
#define fdn(i,l,r) for(int i=r;i>=l;i--)
#define ll long long
#define ull unsigned long long
#define ld long double
#define mod 998244353
#define pii pair<int,int>
#define pil pair<int,ll>
#define pli pair<ll,int>
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define maxn 3010
using namespace std;

bool up(int &x,int y) { return (x<y?x=y,1:0); }
bool down(int &x,int y) { return (x>y?x=y,1:0); }
int read()
{
    int x=0,f=1;
    char ch=getchar();
    while(!isdigit(ch)) f=(ch=='-'?-f:f),ch=getchar();
    while(isdigit(ch)) x=x*10+ch-'0',ch=getchar();
    return x*f;
}

int n,m;
string a[maxn],b[maxn];

int main()
{
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);

    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    cin>>n>>m;

    string mn="#",cn="#";
    int idx=-1;
    fup(o,1,n)
    {
        string s;
        cin>>s;
        int cnt[30]; memset(cnt,0,sizeof(cnt));
        fup(i,0,m-1) cnt[s[i]-'a']++;
        fup(i,0,25) fup(j,1,cnt[i]) a[o]+=(char)(i+'a');
        fdn(i,0,25) fup(j,1,cnt[i]) b[o]+=(char)(i+'a');
        if(mn=="#"||mn>b[o]) cn=mn,mn=b[o],idx=o;
        else if(cn=="#"||cn>b[o]) cn=b[o];
        //cout<<mn<<' '<<cn<<endl;
    }
    fup(i,1,n)
        if(i==idx) printf("%d",(a[i]<cn));
        else printf("%d",(a[i]<mn));
    puts("");

    return 0;
}
