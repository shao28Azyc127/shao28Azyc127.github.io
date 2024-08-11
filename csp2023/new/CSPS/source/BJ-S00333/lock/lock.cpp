#include<bits/stdc++.h>
using namespace std;
int n;
int p[5];
int q[10][10][10][10][10];
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=0;j<5;j++)cin>>p[j];
        for(int j=0;j<5;j++){
            for(int k=1;k<=9;k++){
                p[j]=(p[j]+k)%10;
                q[p[0]][p[1]][p[2]][p[3]][p[4]]++;
                if(j+1<5){
                    p[j+1]=(p[j+1]+k)%10;
                    q[p[0]][p[1]][p[2]][p[3]][p[4]]++;
                    p[j+1]=(p[j+1]+10-k)%10;
                }
                p[j]=(p[j]+10-k)%10;
            }
        }
    }
    int ans=0;
    for(int a=0;a<=9;a++)
        for(int b=0;b<=9;b++)
            for(int c=0;c<=9;c++)
                for(int d=0;d<=9;d++)
                    for(int e=0;e<=9;e++)
                        ans+=(q[a][b][c][d][e]==n);
    cout<<ans;
    return 0;
}
