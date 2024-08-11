#include<bits/stdc++.h>
using namespace std;
int arr[10000005];
int day=0;
int n;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int a=n;
    for(int i=1;i<=n;i++){
        arr[i]=1;
    }
    while(a){
        for(int i=1;i<=n;i+=3){
            if(arr[i]){
                arr[i]=0;
                if(i==n){
                    cout<<day<<" ";
                    break;
                }
            }
        }
        day++;
        a=a/3+a%3;
    }
    cout<<day;
    return 0;
}