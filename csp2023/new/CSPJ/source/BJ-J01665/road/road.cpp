#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int u[N];
int a[N];
int cnt;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    for(int i=1;i<=n-1;i++){
        scanf("%d",&u[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=1;i<=n;i++){
        if(a[i]<a[i+1]){
            u[i]+=u[i+1];
            u[i+1]=0;
        }
        if(u[i]%d!=0){
            cnt+=(u[i]/d+1)*a[i];
        }else{
            cnt+=u[i]/d*a[i];
        }
        cout<<cnt<<" ";
    }
    cout<<"\n"<<cnt;
    return 0;
}
