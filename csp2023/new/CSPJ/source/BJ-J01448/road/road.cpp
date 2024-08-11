#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int a[100005];
    int b[100005];
    int n,d,s=0;
    cin >> n >> d;
    for(int i=1;i<=n-1;i++){
        cin >> a[i];
    }
    for(int i=1;i<=n;i++){
        cin >> b[i];
        s=s+ceil(a[i]/d)*b[i];
    }
    cout << s << endl;
}
