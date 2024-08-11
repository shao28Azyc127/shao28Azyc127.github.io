#include<iostream>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
freopen("apple.out","w",stdout);
int n,d;
cin>>n>>d;
int num[100005],us[100005];

for(int i=1;i<=n-1;i++){
    scanf("%d",&num[i]);
}
for(int i=1;i<=n-1;i++){
    scanf("%d",&us[i]);
    //tmp[i]=us[i];
}
int small=999999999,ans=0,wie;
for(int i=1;i<=n;i++){
    if(us[i]<small) {
            wie=i;
            small=us[i];
}
}
int sum=0,jia;
for(int i=1;i<=n-1;i++){
    sum+=num[i];
}
if (wie==1){
    if(sum%d==0) jia=sum/d;
    else jia=sum/d+1;
    ans=jia*small;

}
cout<<ans;
return 0;
}
