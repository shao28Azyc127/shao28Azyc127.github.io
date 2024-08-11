#include<bits/stdc++.h>
using namespace std;

int t,m;
double emm,ans;

/*int zhishu(int x){
    for(int i=2;i<=x/2;i++){
        if(x%i==0)return 1;//bushi zhishu
    }
};
*/
int kekaifang(int x){
    for(int i=1;i<=x;i++){
        for(int j=2;j<=x;j++){
            if(x==i*j*j){
                return 1;
            }
        }
    }
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    cin>>t>>m;
    for(int i=1;i<=t;i++){
        int a,b,c;
        cin>>a>>b>>c;

        emm=b*b-4*a*c;
        if(emm<0)
            cout<<"NO"<<endl;
        else{
                int ans1=(-b+sqrt(emm))/(2*a);
                int ans2=(-b-sqrt(emm))/(2*a);
                ans=max(ans1,ans2);
                cout<<int(ans)<<endl;
            }
    return 0;
}

