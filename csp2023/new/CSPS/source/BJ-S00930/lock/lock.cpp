#include <bits/stdc++.h>
using namespace std;
int a[10][5],st[10][10][10][10][10];
long long ans;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    int n;cin>>n;
    for(int i=1;i<=n;i++)
        for(int j=0;j<5;j++) scanf("%d",&a[i][j]);
    for(int i=1;i<=n;i++)
    for(int j=1;j<=9;j++){
        st[(a[i][0]+j)%10][a[i][1]][a[i][2]][a[i][3]][a[i][4]]++;
        st[a[i][0]][(a[i][1]+j)%10][a[i][2]][a[i][3]][a[i][4]]++;
        st[a[i][0]][a[i][1]][(a[i][2]+j)%10][a[i][3]][a[i][4]]++;
        st[a[i][0]][a[i][1]][a[i][2]][(a[i][3]+j)%10][a[i][4]]++;
        st[a[i][0]][a[i][1]][a[i][2]][a[i][3]][(j+a[i][4])%10]++;
        st[(a[i][0]+j)%10][(j+a[i][1])%10][a[i][2]][a[i][3]][a[i][4]]++;
        st[a[i][0]][(a[i][1]+j)%10][(j+a[i][2])%10][a[i][3]][a[i][4]]++;
        st[a[i][0]][a[i][1]][(a[i][2]+j)%10][(j+a[i][3])%10][a[i][4]]++;
        st[a[i][0]][a[i][1]][a[i][2]][(a[i][3]+j)%10][(j+a[i][4])%10]++;
    }
    for(int aa=0;aa<=9;aa++)
        for(int b=0;b<=9;b++)
            for(int c=0;c<=9;c++)
                for(int d=0;d<=9;d++)
                    for(int e=0;e<=9;e++)
                        if(st[aa][b][c][d][e]==n) ans++;
    cout<<ans;
    return 0;
}
