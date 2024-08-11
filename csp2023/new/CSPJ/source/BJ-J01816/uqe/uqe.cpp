#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    scanf("%d%d",&t,&m);
    for(int i=1;i<=t;i++){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int p=b*b-4*a*c;
        if(p<0){
            cout<<"NO"<<endl;
        }else{
            int x1=((0-b+sqrt(p)))/(2*a);
            int x2=((0-b-sqrt(p)))/(2*a);
            cout<<max(x1,x2)<<endl;
        }
    }
    return 0;
}
