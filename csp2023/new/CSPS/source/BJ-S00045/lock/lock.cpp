#include<bits/stdc++.h>
using namespace std;
#define int long long
const int INF=-2147483647;
struct CSP{
    int a,b,c,d,e;
}l[9];
bool h[100000];
int n;
bool eq(CSP j,CSP s) {return (j.a==s.a)+(j.b==s.b)+(j.c==s.c)+(j.d==s.d)+(j.e==s.e)==5;}
bool t1(CSP j,CSP s) {return (j.a==s.a)+(j.b==s.b)+(j.c==s.c)+(j.d==s.d)+(j.e==s.e)==4;}
bool t2(CSP j,CSP s) {
    if((j.a==s.a)+(j.b==s.b)+(j.c==s.c)+(j.d==s.d)+(j.e==s.e)!=3) return false;
    int a1,a2,b1,b2,c1,c2,d1,d2,e1,e2,csp[4]={0,0,0,0},in=0;a1=a2=b1=b2=c1=c2=d1=d2=e1=e2=INF;
    if(j.a!=s.a) a1=j.a,a2=s.a;
    if(j.b!=s.b) b1=j.b,b2=s.b;
    if(j.c!=s.c) c1=j.c,c2=s.c;
    if(j.d!=s.d) d1=j.d,d2=s.d;
    if(j.e!=s.e) e1=j.e,e2=s.e;
    if(a1!=INF && a2!=INF && b1!=INF && b2!=INF) csp[0]=a1,csp[2]=a2,csp[1]=b1,csp[3]=b2;
    else if(b1!=INF && b2!=INF && c1!=INF && c2!=INF) csp[0]=b1,csp[2]=b2,csp[1]=c1,csp[3]=c2;
    else if(c1!=INF && c2!=INF && d1!=INF && d2!=INF) csp[0]=c1,csp[2]=c2,csp[1]=d1,csp[3]=d2;
    else if(d1!=INF && d2!=INF && e1!=INF && e2!=INF) csp[0]=d1,csp[2]=d2,csp[1]=e1,csp[3]=e2;
    else return false;
    if(csp[1]-csp[0]==csp[3]-csp[2]) return true;
    if((csp[1]<csp[0] && csp[3]-csp[2]==10+csp[1]-csp[0]) || (csp[3]<csp[2] && csp[1]-csp[0]==10+csp[3]-csp[2])) return true;
    return false;
}
bool check(CSP j,CSP s) {
    if(eq(j,s)) return false;
    if(t1(j,s)) return true;
    if(t2(j,s)) return true;
    return false;
}
void debug(int i) {cout<<i/10000<<i/1000%10<<i/100%10<<i/10%10<<i%10<<endl;}
int ans() {
    int cnt=0;
    for(int i=0;i<100000;i++)
        if(h[i]==true)
            cnt++;//,debug(i);
    return cnt;
}
signed main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    for(int i=0;i<100000;i++) h[i]=true;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>l[i].a>>l[i].b>>l[i].c>>l[i].d>>l[i].e;
    for(int i=1;i<=n;i++)
        for(int j=0;j<100000;j++)
            if(!check(l[i],{j/10000,j/1000%10,j/100%10,j/10%10,j%10}))
                h[j]=false;
    cout<<ans()<<endl;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
