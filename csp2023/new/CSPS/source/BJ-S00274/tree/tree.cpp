#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<string>
#include<vector>
using namespace std;
vector<int> v[100005];
int a[100005],b[100005],c[100005];
//void dfs(int x)
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    //ios::sync_with_stdio(false);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        v[y].push_back(x);
        v[x].push_back(y);
    }
    cout<<n+1<<endl;
    return 0;
}
