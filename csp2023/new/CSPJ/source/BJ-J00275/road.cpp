#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(){
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int A[100010]={0},W[100010]={0};
    int n,k,ans=0,a,j=0;
    cin>>n>>k;
    for(int i=2;i<=n;i++){
        scanf("%d",&W[i]);
    }
    for(int i=1;i<=n;i++){
        scanf("%d",&A[i]);
    }
    int now=1;
    while(now!=n){
        int l=0;
        int i=now+1;
        while(A[i]>A[now]&&i<n){
            l+=W[i];
            i++;
        }
        l+=W[i];
        if(l%k-j>0){
            ans+=(((l-j)/k)+1)*A[now];
            j+=k-l%k;
        }else if(l%k==0){
            ans+=(l/k)*A[now];
        }else{
            ans+=(l/k)*A[now];
            j+=(l/k)*k-l;
        }
        now=i;
    }
    cout<<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
