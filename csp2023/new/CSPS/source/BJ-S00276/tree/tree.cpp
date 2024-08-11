#include<cstdio>
#include<vector>
using namespace std;
long long a[100005],b[100005],c[100005],nh[100005],dt[100005];
vector<int> vct[100005];
bool cd = 1,cb = 1,gl[100005],vis[100005];
int u,v,cnt,n;
int main(){
    scanf("%d",&n);
    for(int i = 0;i < n;i++){
        scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
        dt[i] = a / b;
        if(a % b != 0) dt[i]++;
    }
    for(int i = 0;i < n;i++){
        scanf("%d %d",&u,&v);
        vct[u].push_back(v);
        vct[v].push_back(u);
        if(u != 1) cd = 0;
        if(u != i || v != 1 + i) cb = 0;
    }
    if(cb){
        for(int i = 0;cnt != n;i++){
            if(i < n) vis[i] = 1;
            for(int j = 0;j <= i;j++){
                if(!gl[j]){
                    nh[j] += max((long long)1,b[j] + i * c[j]);
                    if(nh[j] >= a[i]){
                        gl[j] = 1;
                        cnt++;
                    }
                }

            }
        }
    }

    return 0;
}
