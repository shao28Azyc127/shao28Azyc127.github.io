#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int q,m;
int gcd(int a,int b){
    if(a%b==0)return b;
    else return gcd(max(a%b,b),min(a%b,b));
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>q>>m;
    for(int i=1;i <= q;i++){
        int a,b,c;
        cin >>a >> b >>c;
        int delta=b*b-4*a*c;
        if(b==0&&c==0){
            int k = sqrt(a);
            if(k*k==a)cout<<k<<endl;
            else printf("sqrt(%d)",a);
        }
        else if(delta < 0)cout << "NO"<<endl;
        else{
            int k =sqrt(delta);
            if(delta==0){
                b=-b;
                if(b>0&&2*a>0){
                    int f = gcd(max(b,2*a),min(b,2*a));
                    if(f%2*a==0)cout << b / f<<endl;
                    else printf("%d/%d",b/f,2*a/f);
                }
                if(b<0&&2*a<0){
                    int f = gcd(max(-b,-2*a),min(-b,-2*a));
                    if(f%-2*a==0)cout << -b / f<<endl;
                    else printf("%d/%d",-b/f,-2*a/f);
                }
            }
            else if(k*k==delta){
                int s,mo;
                s=(k-b);
                mo=2*a;
                int j = gcd(max(s,mo),min(s,mo));
                printf("%d/%d",s/j,mo/j);
            }
            else{

            }
        }
    }
    return 0;
}