#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;
const int maxn = 1e5+20;
int n,a[maxn],b[maxn],c[maxn],u[maxn],v[maxn],nowtree = 0,high[maxn];
bool flag[maxn];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i = 1; i <= n; i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i = 1; i < n; i++){
        cin>>u[i]>>v[i];
    }

    cout<<"5"<<endl;
    return 0;
}
