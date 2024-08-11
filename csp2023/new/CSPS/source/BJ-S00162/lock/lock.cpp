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
}int n,a[10][10],b[10],ans;
struct node{
    int x,y,z;
};vector<node>tmp;
inline bool check(node a,node b){
    if(a.z!=b.z-1) return false;
    int da1,da2,db1,db2;
    if(a.x<a.y) da1=a.y-a.x,da2=-a.x-(10-a.y);else da1=a.y-a.x,da2=a.y+(10-a.x);
    if(b.x<b.y) db1=b.y-b.x,db2=-b.x-(10-b.y);else db1=b.y-b.x,db2=b.y+(10-b.x);
    if(da1==db1||da1==db2||da2==db1||da2==db2) return true;return false;
}
int main(){
    fre("lock");
    // fre("lock//lock2");
    int cnt=0;
    qread(n);int i,j,k;for(i=1;i<=n;i++) for(j=1;j<=5;j++) qread(a[i][j]);
    for(i=0;i<=99999;i++){
        int base=1;bool f=true;
        for(j=1;j<=5;j++,base*=10) b[5-j+1]=i/base%10;
        for(j=1;j<=n;j++){
            if(!f) break;tmp.clear();
            for(k=1;k<=5;k++) if(a[j][k]!=b[k]) tmp.emplace_back(node{a[j][k],b[k],k});
            if(tmp.size()>2||tmp.empty()){f=false;break;}
            if(tmp.size()==1) continue;
            if(!check(tmp[0],tmp[1])){f=false;break;}
        }ans+=f;
        // if(b[1]==1&&b[2]==0&&b[3]==1&&b[4]==1&&b[5]==5) cout<<f<<endl;
    }
    printf("%d\n",ans);
    // cout<<cnt<<endl;
    return 0;
}