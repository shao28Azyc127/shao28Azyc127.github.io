#include<bits/stdc++.h>
using namespace std;
int n,m,sum,k;
int x[10000];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        x[i]=i;
    }
    for(int j=1; ;j++){
        for(int i=1;i<=n;i++){
            if(x[i]!=0){
                x[i]=0;
                if(x[i]==n)sum=i;
                k++;
                i=i+3;
            }
        }
        if(k==n){
            cout<<j<<" "<<sum;
            return 0;
        }
    }
}