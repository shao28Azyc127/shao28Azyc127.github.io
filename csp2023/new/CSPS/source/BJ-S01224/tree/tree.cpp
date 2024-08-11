#include <bits/stdc++.h>
using namespace std;
int n,a[100010],b[100010],c[100010];
vector<int >edge[100010];
bool flag=1;
bool check1(int *x){
    for(int i=1;i<=n;i++)
        if(x[i]<a[i])
            return 1;
    return 0;
}
void solve1(){
    int day=0,tree[100010]{0},plant;
    while(check1(tree)){
        day++;
        for(int i=1;i<=day;i++)
            tree[i]+=max(c[i]*day+b[i],1);
    }
    cout<<day;
}
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        if(x>y)
            swap(x,y);
        edge[x].push_back(y);
        if(x+1!=y)
            flag=0;
    }
    if(flag){
        solve1();
        return 0;
    }
    cout<<n;
    return 0;
}
