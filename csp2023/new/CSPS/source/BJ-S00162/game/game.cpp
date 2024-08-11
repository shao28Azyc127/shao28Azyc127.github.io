#include <bits/stdc++.h>
#define fre(z) freopen(z".in","r",stdin),freopen(z".out","w",stdout)
#define mem(a,b) memset(a,b,sizeof(a))
using namespace std;
typedef pair<int,int> Pair;
template<class T>inline T qmax(const T &x,const T &y){return x>y?x:y;}
template<class T>inline T qmin(const T &x,const T &y){return x<y?x:y;}
inline void qread(){}template<class T1,class ...T2>
inline void qread(T1 &a,T2 &...b){
    register int x=0;register bool f=false;char ch=getchar();
    while(ch<'0') f|=(ch=='-'),ch=getchar();
    while(ch>='0') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
    x=(f?-x:x);a=x;qread(b...);
}const int MAXN=2e6+7;
int n,rt[MAXN],tot=1;long long cnt[MAXN],ans;char s[MAXN];
struct node{
    int lson,rson;bool v,o;
}tr[MAXN*20];
#define ls tr[p].lson
#define rs tr[p].rson
#define mid ((l+r)>>1)
inline void pup(int p){tr[p].o=tr[ls].o|tr[rs].o;}
void bld(int &p,int l,int r){
    if(!p) p=++tot;if(l==r)return;bld(ls,l,mid);bld(rs,mid+1,r);
}void upd(int &p,int pre,int l,int r,int x,int c){
    if(!p) p=++tot,tr[p]=tr[pre];
    if(l==r) return tr[p].v=c,void();
    if(x<=mid) upd(ls,tr[pre].lson,l,mid,x,c);
    else upd(rs,tr[pre].rson,mid+1,r,x,c);pup(p);
}int que(int p,int l,int r,int x){
    if(!p) return 0;if(l==r) return tr[p].v;
    if(x<=mid) return que(ls,l,mid,x);return que(rs,mid+1,r,x);
}int que1(int p,int l,int r){
    if(!p) return -1;if(l==r) return tr[p].v?l:-1;
    if(tr[rs].o) return que1(rs,mid+1,r);return que1(ls,l,mid);
}
vector<int>pos[26];
int main(){
    fre("game");
    // fre("game//game3");
    qread(n);int i,j;scanf("%s",s+1);int ans=0;rt[0]=1;
    for(i=1;i<=n;i++) pos[s[i]-'a'].emplace_back(i);int lim=20000000/n;
    for(i=1;i<=n;i++){
        int p=-1;
        if(s[i-1]==s[i]) p=i-2;else{
            int t=lower_bound(pos[s[i]-'a'].begin(),pos[s[i]-'a'].end(),i)-pos[s[i]-'a'].begin()-1;
            // if(que(rt[i-1],1,n,t+1)) p=t-1,puts("#");
            // else{
            // int tmp=que1(rt[t],1,n);
            // if(tmp==-1) p=-1;
            // else{
            //     p=pos[s[i]-'a'][lower_bound(pos[s[i]-'a'].begin(),pos[s[i]-'a'].end(),t)-pos[s[i]-'a'].begin()-1];
            //     if(que(rt[i-1],1,n,p+1)) p=p-1;else p=-1;
            // }}
            for(j=1;j<=lim&&t>=0;j++,t--) 
                if(que(rt[i-1],1,n,pos[s[i]-'a'][t]+1)){p=pos[s[i]-'a'][t]-1;break;}
        }if(p==-1){rt[i]=rt[0];continue;}
        upd(rt[i],rt[p],1,n,p+1,1);cnt[i]=cnt[p]+1;ans+=cnt[i];
        // int p=-1;
        // for(j=i-1;j>=1;j--) if(s[i]==s[j]&&(f[i-1][j+1]||i==j+1)){p=j;f[i][j]=1;break;}
        // for(j=p-1;j>=1;j--) f[i][j]=f[p-1][j];ans+=f[i].count();
    }printf("%lld\n",ans);
    return 0;
}