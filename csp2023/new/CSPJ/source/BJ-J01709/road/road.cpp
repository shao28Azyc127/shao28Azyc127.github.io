#include<bits/stdc++.h>
using namespace std;
int n,d,a[100005],v[100005],o,mon,s;
int main(){
    freopen('road.in','r',stdin);
    freopen('road.out','w',stdout);
    cin >> n >> d;
    for(int i=1;i<n;i++)
        cin >> v[i];
    for(int i=1;i<=n;i++)
        cin >> a[i];
    for(int i=1;i<n;i++)
    {
        if(a[i]<=a[i+1])
            a[i+1]=a[i];
    }
    for(int i=1;i<n;i++)
    {
        if(s<v[i])
        {
            if((v[i]-s)%d!=0)o=(v[i]-s)/d+1;
            else o=(v[i]-s)/d;
            s=s+o*d-v[i];
            mon=mon+o*a[i];
        }
        else 
        {
            s=s-v[i];
        }
    }
    cout << mon << endl;
    return 0;
}
