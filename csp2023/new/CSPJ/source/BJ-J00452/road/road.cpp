
#include <bits/stdc++.h>

using namespace std;
int n,d;
int v[1000000];
int a[1000000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)    cin>>v[i];
    for(int i=1;i<=n;i++)   cin>>a[i];
    int s=0;
    for(int i=1;i<n;i++)    s+=v[i];
    //cout<<s<<" "<<a[1]<<" "<<d<<endl;
    cout<<(ceil((double)s/d))*a[1];
    return 0;
}//11,12,13

/*
#include <bits/stdc++.h>
using namespace std;
int n,d;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(int i=1;i<n;i++)    cin>>v[i];
    for(int i=1;i<=n;i++)   cin>>a[i];
    int minq=1e9;
    cout<<minq<<"*";
    for(int i=1;i<n;i++){
        for(int j=1;j<=10000;j++){
            int k;
            for(int w=1;w<)
            minq=min(minq,k);
        }
    }
}
*/
