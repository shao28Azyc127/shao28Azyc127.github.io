#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;

const int MAXN = 1e5 + 10;
int n,d,a[MAXN],v[MAXN];
int minn = 1e9,sum,chao;

int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> d;
    for(int i = 1;i < n;++i) cin >> v[i];
    for(int i = 1;i <= n;++i) cin >> a[i];
    for(int i = 1;i < n;++i){
        minn = min(minn,a[i]);
        int jv = int(ceil((v[i] - chao) * 1.0 / d));
        chao = (chao + jv * d) - v[i];
        sum += minn * jv;
    }
    cout << sum << endl;
    return 0;
}
