#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    cout<<n<<d;
    int a[100005],b[100005],c[100005];
    for(int i = 1 ; i <= n-1 ; i++){
        cin>>b[i];
    }
    for(int i = 1 ; i <= n ; i++){
        cin>>c[i];
    }
    memset(a,1e5,sizeof(a));
    a[1] = 0;
    for(int i = 2 ; i <= n ; i++){
        for(int j = i - 1 ; j >= 0 ; j--){
            int op = a[j];
            for(int m = j - 1 ; m >= 1 ; m--)op -= b[m];
            int po = 0;
            for(int m = j ; m <= i-1 ; m++)po+=b[m];
            if((po - op) % (c[j]*d))po--;
            a[i] = min(a[i],a[j] + (po - op) / (c[j]*d) + 1);
        }
    }
    cout<<a[n] / d;
    return 0;
}