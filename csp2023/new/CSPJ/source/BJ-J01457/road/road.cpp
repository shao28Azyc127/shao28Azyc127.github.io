#include<bits/stdc++.h>
using namespace std;
const int m=100005;
int n,d,i,j,l,f=0,x,v[m],k,a[m],s=0,g=0,q=0;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>d;
    for(i=1;i<n;i++)cin>>v[i];
    for(i=1;i<=n;i++)cin>>a[i];
    for(i=1;i<n;i++){
        if(q>0){
            q--;
            continue;
        }
        g=v[i];
        if(a[i]<=a[i+1]){
            for(j=1;j<n-i;j++){
                if(a[i+j]>a[i+j+1])break;
                g+=v[i+j];
                q++;
            }

        }
            x=g/d-l;
            s+=x/a[i];

    }
    cout<<s;
    return 0;
}