#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("road.in",'r',stdin);
    freopen("road.out",'w',stdout);
    int n,d;
    cin>>n>>d;
    int a,s=0;
    int e,f,g,h,z;
    for (int i=1;i<n;i++){
        cin>>a;
        s+=a;
    }
    cin>>e>>f>>g>>h>>z;
    cout<<s/d*e;
    return 0;
}
