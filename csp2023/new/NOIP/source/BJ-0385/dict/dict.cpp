#include<bits/stdc++.h>
using namespace std;
template<typename T>
inline void read(T &x){
    x=0;int f=1;char c=getchar();
    for(;!isdigit(c);c=getchar()) if(c=='-') f=-1;
    for(;isdigit(c);c=getchar()) x=(x<<3)+(x<<1)+c-'0';
    x*=f;
}
const int N=3e3+10;
char c[N][N],bg[N][N],sm[N][N];
int n,m,ans[N];
bool cmpb(char a,char b){return (a-'a')>(b-'a');}
bool cmps(char a,char b){return (a-'a')<(b-'a');}
inline void change(int x){
    sort(bg[x]+1,bg[x]+m+1,cmpb);
    sort(sm[x]+1,sm[x]+m+1,cmps);
}
struct node{
    int id,now;
    string s;
}s[N],mn[N];
inline bool ck(string x,string y){
    if(x==y) return 0;
    for(int i=0;i<m;++i){
        if(x[i]==y[i]) continue;
        if(x[i]<y[i]) return 0;
        if(x[i]>y[i]) return 1;
    }
    return 1;
}
bool cmp(node a,node b){
    if(!ck(a.s,b.s)) return 1;
    return 0;
}
bool cmp2(node a,node b){
    return ck(a.s,b.s);
}
int main(){
    freopen("dict.in","r",stdin);
    freopen("dict.out","w",stdout);
    read(n);read(m);
    for(int i=1;i<=n;++i) for(int j=1;j<=m;++j){
        while(!(c[i][j]>='a'&&c[i][j]<='z')) c[i][j]=getchar();
        //cin>>c[i][j];
        bg[i][j]=c[i][j];
        sm[i][j]=c[i][j];
    }
    for(int i=1;i<=n;++i){
        change(i);s[i].id=i;mn[i].id=i;
        for(int j=1;j<=m;++j) s[i].s+=bg[i][j],mn[i].s+=sm[i][j];
    }
    sort(s+1,s+n+1,cmp);
    sort(mn+1,mn+n+1,cmp2);
    int l=n;
    for(int i=1;i<=n;++i){
        int L=0,R=l;
        while(L<=R){
            int mid=(L+R)>>1;
            if(ck(mn[i].s,s[mid].s)) L=mid+1,l=mid;
            else R=mid-1;
        }
        if(l!=0) ans[mn[i].id]=0;
        else ans[mn[i].id]=1;
    }
    for(int i=1;i<=n;++i) printf("%d",ans[i]);
    return 0;
}
/*
* this is my first NOIp
*
* i wrote an O(nlogn) program this time
*
* but it cost 2.5s to run the 10th task
*
* i hope i can get all points
*/
