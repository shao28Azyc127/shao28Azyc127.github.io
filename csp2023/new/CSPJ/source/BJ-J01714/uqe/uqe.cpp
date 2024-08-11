#include<bits/stdc++.h>
using namespace std;

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    while(T--){
        int a,b,c;
        cin>>a>>b>>c;
        long long delta=b*b-4*a*c;
        if(delta<0) cout<<"NO"<<endl;
        else if(c==0){
            int num;
            if(b%a==0) {
                num=-(b/a);
                cout<<max(num,0)<<endl;;
            }
            else{
                int k=__gcd(a,b);
                if(-(b/a)>0){
                        b=-b;
                        a=-a;
                    cout<<(b/k)<<"/"<<(a/k)<<endl;
                }
                else cout<<"0"<<endl;
            }

        }
        else{
            cout<<(-b+sqrt(delta))/(2*a);
        }
    }

    return 0;}
