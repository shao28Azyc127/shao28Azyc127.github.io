#include <bits/stdc++.h>
using namespace std;
const int N=5e5+5,T=0.94*CLOCKS_PER_SEC;
int c,n,m,q,p,v,kx,ky;
long long maxx,maxy,x[N],y[N],px[N],py[N];
inline void file(){
    freopen("expand.in","r",stdin);
    freopen("expand.out","w",stdout);
    //火大！！现在感冒的劲上来了。嗓子疼，浑身无力，头昏脑胀。
    //好在在之前的大概2h里我写了170pts的程序。这道t3又写了10pts的水，看起来现在能拿180pts。
    //t3好像有一个结论但是不知道对不对。
    //刚才睡了0.5h，感觉精神好了一些。但还是要变loser了。
    //by BJ-0363,2023.11.18 11:11
}
int main(){
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    file();
    cin >> c >> n >> m >> q;
    if(c==1){
        for(int i=1;i<=q+1;++i) cout << 1;
        return 0;
    }
    for(int i=1;i<=n;++i) cin >> x[i],maxx=max(maxx,x[i]);
    for(int i=1;i<=m;++i) cin >> y[i],maxy=max(maxy,y[i]);
    if(((x[1]-y[1])*(x[n]-y[m])>0)&&((maxx-maxy)*(x[1]-y[1])>0)) cout << 1;
    while(q--){
        cin >> kx >> ky,maxx=0,maxy=0;
        for(int i=1;i<=n;++i) px[i]=x[i];
        for(int i=1;i<=m;++i) py[i]=y[i];
        for(int i=1;i<=kx;++i) cin >> p >> v,px[p]=v;
        for(int i=1;i<=ky;++i) cin >> p >> v,py[p]=v;
        for(int i=1;i<=n;++i) maxx=max(maxx,px[i]);
        for(int i=1;i<=m;++i) maxy=max(maxy,py[i]);
        if(((px[1]-py[1])*(px[n]-py[m])>0)&&((maxx-maxy)*(px[1]-py[1])>0)) cout << 1;
        else cout << 0;
    }
    return 0;
}