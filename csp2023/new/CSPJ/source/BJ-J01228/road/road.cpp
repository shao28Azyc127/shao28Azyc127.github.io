#include<bits/stdc++.h>
using namespace std;
int n,mile;
int minn = 1, sum = 0,num = 0;
int a[100005];
int b[100005];
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    cin>>n>>mile;
    for(int i = 1;i<=n-1;i++){
        cin>>a[i];
    }
    for(int i = 1;i<=n;i++){
        cin>>b[i];
    }
    for(int j = 1;j<=n;j++){
        if(b[j] < b[minn]){
            for(int k = minn;k<=j-1;k++){
                sum = sum + a[k];
            }
            if(sum%mile != 0){
                num = num + sum / mile * b[j] + b[j];
            }
            else{
                num = num + sum / mile * b[j];
            }
            minn = j;
        }

        else if(j==n){
            for(int k = minn;k<=j-1;k++){
                sum = sum + a[k];
            }
            if(sum%mile != 0){
                num = num + sum / mile * b[j] + b[j];
            }
            else{
                num = num + sum / mile * b[j];
            }
        }

    }
    cout<<num;
}
