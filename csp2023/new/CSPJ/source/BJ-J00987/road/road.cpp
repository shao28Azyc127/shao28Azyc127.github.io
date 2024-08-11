#include<bits/stdc++.h>

using namespace std;
int v[100002],a[100002],x=1,y=0,mn=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin >> n >> d;
    for(int i=1;i<n;i++)
    {
        cin >> v[i];
    }
    for(int i=1;i<=n;i++)
    {
        cin >> a[i];
        //cout << x;
        if(a[i]<a[x])
        {
            x=i;
        }
        while(v[i]-y>0)
        {
            y+=d;
            cout << mn << endl;
            mn+=a[x];
        }
        y-=v[i];
    }
    cout << mn << endl;
    return 0;
}