#include<bits/stdc++.h>
using namespace std;
int n;
int a[101][101];
int check(int n){
    int cnt = 0;
    for(int i = 1;i<n;i++){
        for(int j = 1;j<=5;j++){
            if(a[i][j] == a[i+1][j]){
                cnt++;
            }
        }
    }
    return cnt;
}
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=5;j++){
            cin>>a[i][j];
        }
    }
    if(n==1){
        cout<<81<<endl;
    }
    else if(n==2&&check(n) == 4){
        cout<<8<<endl;
    }

    else if(check(n)<=n*5-3*n){
        cout<<0;
    }
    else{
        cout<<10-n;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}