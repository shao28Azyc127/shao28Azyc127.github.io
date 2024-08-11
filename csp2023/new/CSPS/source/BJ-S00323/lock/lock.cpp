#include <iostream>
#include <bits/stdc++.h>

using namespace std;

const int N=12;

int a[8][6];
int t[N][N][N][N][N];
int n,ans;

int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i][1]>>a[i][2]>>a[i][3]>>a[i][4]>>a[i][5];
    }
    for(int i=1;i<=n;i++){
        for(int k=1;k<=9;k++){
            t[a[i][1]][a[i][2]][a[i][3]][a[i][4]][(a[i][5]+k)%10]++;
            t[a[i][1]][a[i][2]][a[i][3]][(a[i][4]+k)%10][a[i][5]]++;
            t[a[i][1]][a[i][2]][(a[i][3]+k)%10][a[i][4]][a[i][5]]++;
            t[a[i][1]][(a[i][2]+k)%10][a[i][3]][a[i][4]][a[i][5]]++;
            t[(a[i][1]+k)%10][a[i][2]][a[i][3]][a[i][4]][a[i][5]]++;

            t[(a[i][1]+k)%10][(a[i][2]+k)%10][a[i][3]][a[i][4]][a[i][5]]++;
            t[a[i][1]][(a[i][2]+k)%10][(a[i][3]+k)%10][a[i][4]][a[i][5]]++;
            t[a[i][1]][a[i][2]][(a[i][3]+k)%10][(a[i][4]+k)%10][a[i][5]]++;
            t[a[i][1]][a[i][2]][a[i][3]][(a[i][4]+k)%10][(a[i][5]+k)%10]++;
        }
    }
    for(int i1=0;i1<=9;i1++)
        for(int i2=0;i2<=9;i2++)
            for(int i3=0;i3<=9;i3++)
                for(int i4=0;i4<=9;i4++)
                    for(int i5=0;i5<=9;i5++)
                        if(t[i1][i2][i3][i4][i5]>=n) ans++;
    cout<<ans;
    return 0;
}
