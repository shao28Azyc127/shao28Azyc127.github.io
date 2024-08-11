#include <bits/stdc++.h>
using namespace std;
const int N=1e5;
inline int read(){
    char c=getchar();int s=0,f=1;
    while(c<'0'||c>'9'){if(c=='-'){f=-1;}c=getchar();}
    while(isdigit(c)){s=(s<<3)+(s<<1)+(c^48);c=getchar();}
    return s*f;
}
int n,d;
int v[N],a[N];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    n=read();d=read();
    for(int i=1;i<n;i++){v[i]=read();v[i]+=v[i-1];}
    for(int i=1;i<=n;i++){a[i]=read();}
    long long ans=0,sum=0;
    int tmp=1;
    for(int i=1;i<n;i++){
        for(int j=i;j<n;j++){
            if(a[i]>a[j]){
                ans+=(ceil((double)(v[j]-v[i])/d))*a[i];
                sum+=(v[j]-v[i]);
                i=j;tmp=j;
            }
        }
    }
    int x=v[n-1]-sum;
    ans=ans+ceil((double)(x/d))*a[tmp];
    cout<<ans;
    return 0;
}
