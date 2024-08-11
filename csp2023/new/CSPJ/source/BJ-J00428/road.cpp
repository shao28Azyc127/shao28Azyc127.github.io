#include <bits/stdc++.h>
using namespace std;
int v[100005],a[100005],p[1005][1005],y[1005][1005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int vs=0;
    for(int i=1;i<n;i++){
        cin>>v[i];
        vs+=v[i];
    }
    int s=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        s=min(s,a[i]);
    }
    if(n<=1000){
        int ys=0,small;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                small=1e8;
                if(i==0){
                    p[i][j]=a[i]*j;
                    y[i][j]=j;
                    if(small>p[i][j] && y[0][ys]<y[0][j]){
                        ys=j;
                    }
                    small=min(small,p[i][j]);
                }
                if(i!=0){
                    p[i][j]=small+a[i]*j;
                    if(small>p[i][j] && y[i][ys]<y[i][j]){
                        ys=j;
                    }
                    small=min(small,p[i][j]);
                    y[i][j]=y[i-1][ys]-v[i]/d;
                }
            }
        }
        cout<<small;
        return 0;
    }
    cout<<vs/d*s;
    return 0;
}