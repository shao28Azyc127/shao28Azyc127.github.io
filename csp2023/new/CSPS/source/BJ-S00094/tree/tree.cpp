#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct tree{
    int m;
    int id;
};a[N];
vector<int>e[N];
int cell(int x,int y){
    if(x%y==0)return x/y;\
    return x/y+1;    
}
bool cmp(tree x,tree y){
    return 1;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    int n;
    cin>>n;
    cout<<n+1;

    return 0;
}
