#include<cstdio>
#include<algorithm>
using namespace std;

int minn,n,d,lon[100005],mon[100005];
long long len,mony;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    scanf("%d%d",&n,&d);
    for(int i=1;i<n;i++){
        scanf("%d",&lon[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&mon[i]);
    }
    minn=mon[1];
    for(int i=1;i<n;i++){
        minn=min(minn,mon[i]);
        if(len>=lon[i]) continue;
        int lenn;
        lenn=lon[i]-len;
        if(lenn%d==0){
            mony+=lenn/d*minn;
            len=0;
        }
        else{
            mony+=(lenn/d+1)*minn;
            len=d-(lenn%d);
        }
    }
    printf("%d",mony);
    fclose(stdin);
    fclose(stdout);
    return 0;
}
