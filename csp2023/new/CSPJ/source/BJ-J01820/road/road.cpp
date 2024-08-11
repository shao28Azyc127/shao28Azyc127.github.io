#include <iostream>
using namespace std;
int w(double s){
    if(s-int(s)==0) return s;
    else return int(s)+1;
}
int main()
{

    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d,u[100005]={},a[100005]={},s=0,a2[100005]={},l=0,j;
    cin>>n>>d;
    for(int i = 0;i < n-1;i++){
        cin>>u[i];
    }
    for(int i = 0;i < n;i++){
        cin>>a[i];
    }
    for(int i = 0;i < n-1;i++){
        if(a2[i]==0){
            s = u[i];
            for(j = i+1;a[i]<a[j] &&j < n;j++){
                s += u[j];
                a2[j] = 1;
            }
            l += w(1.0*s/d)*a[i];
            u[j] -= w(1.0*s/d)*d-s;
            s = 0;
        }
    }
    cout<<l;
    return 0;
}
