#include<bits/stdc++.h>
using namespace std;
int a[10000];
int main(){
    int n,j=0,h=1;
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;

    while(1){
        int y=0;
        for(int i=1;i<=n;i++){
            if(a[i]==0) y=1;
        }
        if(y==0) break;
        for(int i=1;i<=n;i++){
        if(j==0&&a[i]==0){
            a[i]=1;
            j=2;
            if(i==n)  cout<<h<<' ';
        }else {
        if(a[i]==0) j--;
        }
        }
        j=0;
        h++;
    }
    cout<<h-1;
    return 0;
}
