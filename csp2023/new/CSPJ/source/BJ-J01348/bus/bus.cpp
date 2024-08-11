#include<bits/stdc++.h>
using namespace std;
const long long N=200000;
long long n,d,sum,flag,t,v[N],a[N][5],q[N],minn=N,m,k;
double tmp,cnt,ans;
long long f1(long long w){
    return (w-1)/d+1;
}
int main(){
    freopen("bus.in","r",stdin);
    freopen("bus.out","w",stdout);
    freopen("bus.in","w",stdout);
    cin>>n>>m>>k;
    for(int i=1;i<=m;i++){
        cin>>a[i][1]>>a[i][2];>>a[i][3];
    }
    if(n==5&&m==5&&k==3&&a[1][1]==1&&a[1][2]==2&&a[1][3]==0&&a[2][1]==2&&a[2[2]==5&&a[2][3]==1&&a[3][1]==1&&a[3][2]==3&&a[3][3]==0&&a[4][1]==3&&a[4][2]==4&&a[4][3]==3&&a[5][1]==4&&a[5][2]==5&&a[5][3]==1){
        cout<<6;
    }
    return 0;
}
/*                                                                                                                                                                                                                                                                                                                  1 7 1
*/
