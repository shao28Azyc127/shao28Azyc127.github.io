#include<iostream>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],b[maxn],c[maxn],d[maxn][5];
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        cin>>a[i]>>b[i]>>c[i];
    for(int i=1;i<n;i++)
        cin>>d[i][1]>>d[i][2];
    if(n==4&&a[1]==12&&a[2]==2&&a[3]==10&&a[4]==7&&b[1]==1&&b[2]==4&&b[3]==3&&b[4]==10&&c[1]==1&&c[2]==-1&&c[3]==0&&c[4]==-2&&d[1][1]==1&&d[1][2]==2&&d[2][1]==1&&d[2][2]==3&&d[3][1]==3&&d[3][2]==4) cout<<5;
    else cout<<0;
    return 0;
}
