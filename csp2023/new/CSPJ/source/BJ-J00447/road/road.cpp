#include<bits/stdc++.h>
using namespace std;
int main(){
   freopen("road.in","r",stdin);
  freopen("road.out","w",stdout);
    int a[100001],b[100001];
    int n,d;
    cin>>n>>d;
    for(int i=1;i<n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        cin>>b[i];
    }
    int sum=0,m=0;
    for(int i=1;i<n;i++){
        if(sum<a[i]){
             if((a[i]-sum%d)%d==0){
                sum+=(a[i]-sum/d)/d;
            }else{
                sum+=((a[i]-sum/d)/d+1);
            }
            m+=sum*b[i];

        }
        sum-=a[i]/d;

    }
    cout<<m;
   fclose(stdin);
    fclose(stdout);
    return 0;
}
