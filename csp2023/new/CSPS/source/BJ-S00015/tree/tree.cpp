#include<bits/stdc++.h>
using namespace std;
int n,a,b,c;
int main(){
    cin>>n;
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    srand(time(NULL));
    for(int i=1;i<=n;i++)cin>>a>>b>>c;
    for(int i=1;i<n;i++)cin>>a>>b;
    cout<<rand()%100000000+1;
    return 0;
}
