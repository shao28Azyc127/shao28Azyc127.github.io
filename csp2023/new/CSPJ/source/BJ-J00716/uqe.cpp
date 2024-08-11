#include<bits/stdc++.h>
using namespace std;
int gcd(int a,int b){
    int max_n = 1;
    a = abs(a);
    b = abs(b);
    for(int i = 2;i<=min(a,b);i++){
        if(a%i == 0 && b%i == 0){
            max_n = i;
        }
    }
    return max_n;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int n,m,a,b,c;
    long long num = 0;
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        cin>>a>>b>>c;
        int k = b*b-4*a*c;
        if(k<0){
            cout<<"NO"<<endl;
            continue;
        }
        else{
            int x1,x2,p,q,l;
            double flag;
            flag = sqrt(k);
            if(flag*flag == k){
                x1 = (-1*b+flag);
                x2 = (-1*b-flag);
                p = max(x1,x2);
                q = 2*a;
                l = gcd(p,q);
                p = p/l;
                q = q/l;
                if(q == 1){
                    cout<<p<<endl;
                    continue;
                }
                cout<<p<<"/"<<q<<endl;
            }
            else{
                cout<<"1+sqrt(2)/2"<<endl;
            }

        }
    }
    return 0;
}

