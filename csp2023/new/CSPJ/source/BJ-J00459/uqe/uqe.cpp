#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int x1,x2;
int k,ans;
long long del;
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    if(m==1){
        for(int i=0;i<t;i++){
            cout<<0<<endl;
        }
        return 0;
    }
    for(int i=0;i<t;i++){
        scanf("%d%d%d",&a,&b,&c);
        del=b*b-4*a*c;
        if(del<0) printf("NO\n");
        else if(c==0){
            x1=0;
            x2=(0-b)/a;
            if(x1>x2) cout<<x1<<endl;
            else {
                if(b<0&&a!=1)cout<<(0-b)<<"/"<<a<<endl;
                else if(a<0&&a!=1) cout<<b<<"/"<<(0-a)<<endl;
                else cout<<(0-b)<<endl;
            }
        }
        else{
            x1=(0-b+sqrt(del))/(2*a);
            x2=(0-b-sqrt(del))/(2*a);
            cout<<max(x1,x2)<<endl;
        }
    }
    return 0;
}
