#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e9+10;
const int maxm=1e5+10;
ll l,sum,ans,l2,vv,len;
struct node{
    int x,y;
    ll v;
}a[maxm];

inline int read(){
    int x=0,f=1;
    char ch=getchar();
    while(ch<'0' || ch>'9'){if(ch == '-1') f=-1;ch=getchar();}
    while(ch>='0' && ch<='9'){x=x*10+ch-48;ch=getchar();}
    return x*f;
}

bool cmp(node a,node b){
    return a.x<b.x;
}


int main(){
    freopen("run.in","r",stdin);
    freopen("run.out","w",stdout);
    int c=read(),t=read();

    if(c==17 || c==18){
        while(t--){
            ans=0;
            int n=read(),m=read(),k=read(),d=read();
            for(int i=1;i<=m;i++){
                cin>>a[i].x>>a[i].y>>a[i].v;
                l = a[i].x-a[i].y+1;
                if(l < 1) continue;
                if(a[i].y > k) continue;
                sum=d*a[i].y;
                if(a[i].v > sum) ans = ans+a[i].v-sum;
            }
            cout<<ans<<endl;
        }
        return 0;
    }


    while(t--){
        ans=0;
        int n=read(),m=read(),k=read(),d=read();
        for(int i=1;i<=m;i++){
            cin>>a[i].x>>a[i].y>>a[i].v;
        }
        sort(a+1,a+1+n,cmp);
        for(int i=m;i>=1;i--){
            vv=a[i].v;
            l = a[i].x-a[i].y+1;
            len=a[i].y;
            if(l < 1) continue;
            if(a[i].y > k) continue;
            sum = d*a[i].y;

            for(int j=i-1;j>=1;j--){
                if(l>a[j].x) break;
                if(len+a[j].y > k) break;
                l2=a[j].x-a[j].y+1;
                l=min(l2,l);
                len=a[i].x-l+1;
                sum=d*len;
                if(sum < vv+a[j].v){
                    vv += a[j].v;
                    i--;
                }
            }
            if(vv > sum) ans = ans+vv-sum;
        }
        cout<<ans<<endl;
    }
}
