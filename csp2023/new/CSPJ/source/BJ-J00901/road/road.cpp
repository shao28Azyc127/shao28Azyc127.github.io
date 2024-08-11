#include<bits/stdc++.h>
using namespace std;
int n,x,wq,v[100005],w[100005],s;
double y,d;
int main(){
    freopen("road2.in","r",stdin);
    freopen("road.out","w",stdout);
    cin >> n >> wq;
    for (int i=1;i<n;i++){
        cin >> v[i];
    }
    for (int i=1;i<=n;i++){
        cin >> w[i];
    }
    int l=1;y=0;
    double d = wq;
    while (l < n){
        long long V=0;
        for (int j=l+1;j<=n;j++){
            V+=v[j-1];
            if (w[l] > w[j]){
                if (y*d<V){
                    s+=ceil((V-y*d)/d)*w[l];
                    y += ceil((V-y*d)/d) - (V-y*d)/d;
                }
                else y-= V/d;
                l=j;
                break;
            }
        }
    }
    cout << s;
    return 0;
}