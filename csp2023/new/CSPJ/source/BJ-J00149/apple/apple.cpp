#include<bits/stdc++.h>
using namespace std;
long long n,cnt,allday,nday,a[100000007];
int main(){
cin>>n;
cnt=n;
if(n<=3)cout<<n<<" "<<n;
else{
    while(cnt<=0){
    if(cnt>3){
            long long tmp=0;
        for(long long  i=1;i<=n;i++){
         if(a[i]==0){
                if(tmp==3){
                    tmp=0;
                    cnt--;
                    a[i]=1;
                }else tmp++;
            }
    allday++;
        }
    if(a[n]==1)nday=allday;
    }else if(cnt==1||cnt==2||cnt==3){
        allday+=cnt;
        nday=allday;
}
}
cout<<allday<<" "<<nday;
}
return 0;
}
