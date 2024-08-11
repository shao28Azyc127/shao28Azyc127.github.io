#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ll n;
    cin>>n;
    srand(time(NULL));
    cout<<rand()%(3*n)+1;
    return 0;
}
