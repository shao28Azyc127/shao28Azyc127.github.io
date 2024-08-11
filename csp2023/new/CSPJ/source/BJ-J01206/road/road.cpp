#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e5+10;
int n,d,l[maxn],v[maxn],a[maxn];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long ans=0;
    bool flag = false;
    vector<int> pos;
    int mn=maxn;
    scanf("%d%d",&n,&d);
    for(int i=1; i<n; i++){
        scanf("%d",&v[i]);
        l[i]=v[i]+l[i-1];
        if(v[i]%d!=0) flag=true;
    }
    /*for(int i=1; i<n; i++){
        cout << l[i] << " ";
    }
    cout << endl;*/
    pos.push_back(0);
    //cout << l[n-1] << endl;
    for(int i=0; i<n; i++){
        scanf("%d",&a[i]);
        if(a[i]<mn){
            mn=a[i];
            pos.push_back(i);
        }
    }
    pos.push_back(n-1);
    if(mn==a[0]){
        cout << ((l[n-1]+(d-1))/d)*mn << endl;
        return 0;
    }
    int lp=pos.size();
    if(!flag){
        for(int i=1; i<lp; i++){
            ans+=((l[pos[i]]-l[pos[i-1]])/d)*a[pos[i-1]];
            /*cout << pos[i] << endl;
            cout << (l[pos[i]]-l[pos[i-1]])<< endl;
            cout << ((l[pos[i]]-l[pos[i-1]])/d)*a[pos[i-1]] << endl;*/
        }
        cout << ans << endl;
        return 0;
    }
}
