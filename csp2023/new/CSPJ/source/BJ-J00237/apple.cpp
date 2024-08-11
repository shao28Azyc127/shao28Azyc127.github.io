#include<bits/stdc++.h>
using namespace std;
int n,sum,sum1,cnt1;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    int a[n+10];
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int j=1,cnt=0;
    while(cnt<n){
        sum=0;cnt1++;
        for(int i=1;i<=n;i++){
            if(a[i]!=0){
                sum++;
                if(sum%3==1){
                    if(i==n){
                        sum1=cnt1;
                    }
                    a[i]=0;
                    cnt++;
                }
            }
        }
    }
    cout<<cnt1<<" "<<sum1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
