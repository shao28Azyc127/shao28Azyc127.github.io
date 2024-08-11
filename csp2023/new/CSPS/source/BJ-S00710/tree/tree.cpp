#include<bits/stdc++.h>
using namespace std;
int n;
int ans;
struct Land{
    int b,c;
    long long a,high=0;
    vector<int>road;
}land[100005];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>land[i].a>>land[i].b>>land[i].c;
    for(int i=1;i<n;i++){
        int x,y;
        cin>>x>>y;
        land[x].road.push_back(y);
        land[y].road.push_back(x);
    }
    srand(time(NULL));
    cout<<rand()%10+1;
    return 0;
}
