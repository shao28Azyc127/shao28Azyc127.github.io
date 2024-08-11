#include<bits/stdc++.h>
using namespace std;
bool vis[1000000001];
int a[100000001];
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int sum=0;
    int k=n%3;
    int w=n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    while(w!=0){
        k=w%3;
        w=w/3*2+k;
        if(n%4==0&&w==2){
            cout<<sum+2<<" ";
            break;
        }
        if(w==2){
            cout<<sum+1<<" ";
            break;
        }
         sum++;
    }

    int sum1=0;
    int g=n;
    while(vis[a[n]]!=1){
        int j=1;
        for(int i=1;i<=g;i++){
            if(i%3==1) vis[a[i]]=1;
            else{
                a[j]=a[i];
                j++;
            }
        }
        g=j-1;
        sum1++;
    }
    cout<<sum1;
    return 0;
}
