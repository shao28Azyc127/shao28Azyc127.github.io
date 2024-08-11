#include<iostream>
using namespace std;
long long a[100005],b[100005],f[100005],mins[100005],fm[100005];
int sy[100005],scnt=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long n,d;
    cin>>n>>d;
    for(int i=2;i<=n;i++){
        cin>>b[i];
        a[i]=a[i-1]+b[i];
    }
    for(int i=1;i<=n;i++){
        cin>>f[i];
    }
    long long minn=2e9,mind;
    for(int i=2;i<=n;i++){
        if(f[i-1]<=minn){
            mind=i-1;
            minn=f[i-1];
        }
        mins[i]=mind;
        fm[mind]=i;
    }
    long long sum=0,l;
    int x=n;
    long long h=0;
    while(x!=1){
        scnt++;
        sy[scnt]=x;
        x=mins[x];
    }
    scnt++;
    sy[scnt]=1;
    for(int xx=scnt;xx>1;xx--){
        l=(a[fm[sy[xx]]]-a[sy[xx]]);
        if((l-h)%d==0){
            sum+=(l-h)/d*f[sy[xx]];
            h=0;
        }
        else{
            sum+=((l-h)/d+1)*f[sy[xx]];
            h=d-(l-h)%d;
        }
    }
    cout<<sum;
    return 0;
}
