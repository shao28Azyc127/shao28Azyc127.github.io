#include<bits/stdc++.h>
using namespace std;

int n,sum=0;
char a[1200000];
int main(){
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        if(a[i+1]!=a[i]){
            sum++;
        }
//        vis[i]=a[i]-'0';
//        vis[i+1]=a[i+1]-'0';
    }
    cout<<sum-1;
    return 0;
}
