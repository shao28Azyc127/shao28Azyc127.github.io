#include<bits/stdc++.h>
#define fr(xx,yy,zz) for(int xx=yy;xx<=zz;xx++)
#define ll long long
#define pii pair<int,int>
#define pt printf
#define eb emplace_back
using namespace std;
//const int N=1e6+33,inf=0x3f3f3f3f;////////////////////////
void rd() {} template<typename T,typename...args>void rd(T&x,args&...y) {
    bool f=0;
    char ch=getchar();
    for(; ch<'0'||'9'<ch; ch=getchar())if(ch=='-')f=1;
    for(x=0; '0'<=ch&&ch<='9'; ch=getchar() )x=(x<<1)+(x<<3)+ch-'0';
    if(f)x=-x;
    rd(y...);
}
int n,a[10][10],b[10];
int Q[10]= {1,
            10,
            100,
            1000,
            10000,
            100000
           };
int getbit(int s,int p) {
    return s/Q[5-p]%10;
}
int C1(int s,int p,int v) {
    int cur=getbit(s,p);
    s-=cur*Q[5-p];
    s+=v*Q[5-p];
    return s;
}
int F2(int s,int p,int dt) {
    int v1=(getbit(s,p)+dt)%10;
    int v2=(getbit(s,p+1)+dt)%10;
    return C1(C1(s,p,v1),p+1,v2);
}
bool valid(int res) {
    bool isAns=1;
    fr(k,1,5) {
        isAns&=(res!=b[k]);
    }
    return isAns;
}
map<int,int> mp;
int main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    rd(n);
    fr(i,1,n) {
        fr(j,1,5) {
            rd(a[i][j]);
            b[i]=b[i]*10+a[i][j];
        }
    }
    fr(i,1,n) {
        fr(j,1,5) {
            int bit=getbit(b[i],j);
            fr(d,1,9) {
                int nw=bit+d;
                nw%=10;
                int res=C1(b[i],j,nw);
                if(valid(res)) {
                    mp[res]++;
                }
            }
            if(j==5)continue;// not valid
            fr(d,1,9) {
                int res=F2(b[i],j,d);
                if(valid(res)) {
                    mp[res]++;
                }
            }
        }
    }
    int ans=0;
    for(pii t:mp) {
        if(t.second>=n) {
            ans++;
            //pt("666 %05d\n",t);
        }
    }
    pt("%d\n",ans);
    return 0;
}
