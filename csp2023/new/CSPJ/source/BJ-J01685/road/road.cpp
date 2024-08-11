#include<bits/stdc++.h>
using namespace std;
long long l[110000],m[110000],n[110000];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    long long a,b,c,d,e,f;
    cin>>a>>b;
    c=0;
    for (d=1;d<=a-1;d++) cin>>l[d],l[d]+=l[d-1];
    for (d=1;d<=a;d++) cin>>m[d];
    for (d=1;d<=a-1;d++)
    {
        e=1;
        while (m[d]<=m[d+e]&&d+e<=a) e++;
        if (d+e>a) n[d]=a;
        else
        {
            f=d;
            while (f<d+e) n[f]=d+e,f++;
        }
    }
    d=1;
    e=0;
    while (d<a)
    {
        f=ceil((double)(l[n[d]-1]-l[d-1]-e)/b)*m[d];
        c+=f;
        e=f*b/m[d]+e-l[n[d]-1]+l[d-1];
        d=n[d];
    }
    cout<<c;
    return 0;
}
