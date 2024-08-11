#include <bits/stdc++.h>
#define mem(a,b) memset(a,b,sizeof(a))
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
using namespace std;
typedef pair<int,int> Pair;
template<class T>inline T qmax(const T &x,const T &y){return x>y?x:y;}
template<class T>inline T qmin(const T &x,const T &y){return x<y?x:y;}
inline void qread(){}template<class T1,class ...T2>
inline void qread(T1 &a,T2 &...b){
    register T1 x=0;register bool f=false;char ch=getchar();
    while(ch<'0') f|=(ch=='-'),ch=getchar();
    while(ch>='0') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    x=(f?-x:x);a=x;qread(b...);
}const int MAXN=3007;
int n,m,rnk[MAXN];string s[MAXN];
struct node{
    string s;int id;node(){;}
    node(string _s,int _id){s=_s,id=_id;}
    bool operator < (const node &o)const{
        for(int i=0;i<m;i++) if(s[i]<o.s[i]) return 1;else if(s[i]>o.s[i]) return 0;
        if(id==o.id+n) return 0;
        if(id+n==o.id) return 1;
        // if(id==8&&o.id==23) puts("#");
        return id>o.id;
        // return id>o.id&&id!=o.id+n;
    }
};vector<node>a;
int main(){
    fre("dict");
    // fre("dict//dict4");
    ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
    cin>>n>>m;int i,j;
    for(i=1;i<=n;i++){
        cin>>s[i];sort(s[i].begin(),s[i].end());
        a.emplace_back(node{s[i],i});
        sort(s[i].begin(),s[i].end(),greater<char>());
        a.emplace_back(node{s[i],i+n});
    }sort(a.begin(),a.end());int mn=2*n;
    // puts("----------");
    // for(auto i:a) cout<<i.s<<endl;
    if(n==1) return puts("1"),0;
    for(i=0;i<a.size();i++) if(a[i].id<=n) rnk[a[i].id]=i;else mn=qmin(mn,i);
    for(i=1;i<=n;i++) if(rnk[i]<mn) putchar('1');else putchar('0');
    // cout<<rnk[8]<<endl;
    // cout<<mn<<endl;
    return 0;
}