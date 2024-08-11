#include<bits/stdc++.h>
using namespace std;
int n;
const int N=1e5+10;
struct node{
    long long a;
    long long b;
    long long c;
}t[N];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    int f=0;
    for(int i=1;i<=n;i++){
        cin>>t[i].a>>t[i].b>>t[i].c;
        if(t[i].c!=0)f=1;
    }
    cout<<random();
}
