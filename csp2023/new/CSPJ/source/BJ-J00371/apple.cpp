#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,cnt=1,ans2=0,flag=0;
    cin>>n;
    if(n==1||n==2||n==3){
        cout<<n<<' '<<n;
    }
else{
    while(n>0){
        if(flag==0&&(n-1)%3==0){
            ans2=cnt;
            flag=1;
        }
        int tmp=(n-1)/3;
        n=n-tmp-1;
        cnt++;
    }
    if(ans2==0)ans2=cnt+1;
    cout<<cnt<<' '<<ans2;
}
    fclose(stdin);
    fclose(stdout);
    return 0;
}