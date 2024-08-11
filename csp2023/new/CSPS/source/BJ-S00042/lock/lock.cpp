#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=1e5+10;
int n,a[N],q[10][10],ans=0;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=1;j<=5;j++)
            cin>>q[i][j];
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            q[i][j]=(q[i][j]+1)%10;
            for(int k=1;k<=9;k++){
                int temp=q[i][1]*10000+q[i][2]*1000+q[i][3]*100+q[i][4]*10+q[i][5];
                a[temp]++;
                q[i][j]=(q[i][j]+1)%10;
            }
        }
        for(int j=1;j<=4;j++){
            q[i][j]=(q[i][j]+1)%10;
            q[i][j+1]=(q[i][j+1]+1)%10;
            for(int k=1;k<=9;k++){
                int temp=q[i][1]*10000+q[i][2]*1000+q[i][3]*100+q[i][4]*10+q[i][5];
                a[temp]++;
                q[i][j]=(q[i][j]+1)%10;
                q[i][j+1]=(q[i][j+1]+1)%10;
            }
        }
    }
    for(int i=1;i<=99999;i++)
        if(a[i]==n)
            ans++;
    cout<<ans<<endl;
    return 0;
}