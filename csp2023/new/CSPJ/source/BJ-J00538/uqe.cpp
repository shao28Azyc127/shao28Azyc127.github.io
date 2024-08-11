#include <bits/stdc++.h>
using namespace std;

int t,m;
int a,b,c;
int p,q;
double p1,p2,p3;
int r,d;
bool isyouli(double n){
    int cnt = 0;
    for( int pf = n*-1;pf<=n;pf++){
        for(int qf = n*-1;qf<=n;qf++){
            if(__gcd(pf,qf) == 1 && n == pf/qf){
                ++cnt;
                p = pf;q = qf;
            }
        }
    }
    if(cnt == 1){
        
        return true;
    }
    return false;

}

void findp12(double x){

    int ix = ceil(x);

    srand(time(NULL));
    bool flag = rand()%1;
    p1 = rand()%ix;
    if(flag == 1){
        p2 = rand()%ix;
    }
    else{
        p2 = 0;
    }
    r = rand()%20;
    d = rand()%20;
    p3 = rand()%1;
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        if(b*b-4*a*c < 0){
            cout<<"NO\n";
        }else{
            double tmp1 = (((b*-1)+(b*b-4*a*c))/2*a);
            double tmp2 = (((b*-1)-(b*b-4*a*c))/2*a);
            double ans = max(tmp1,tmp2);
            
            if(isyouli(ans) == true){
                if(q == 1){
                    cout<<p<<'\n';
                }
                else{

                    cout<<p<<'/'<<q<<'\n';
                }
            }else{
                findp12(ans);

                if(p1 != 0){
                    cout<<p1<<'+';
                }
                if(p2){
                    cout<<p2<<"*sqrt("<<r<<')'<<'\n';
                }
                else if(p3){
                    p3 = 1/p2;
                    cout<<"sqrt("<<r<<"/"<<p3<<'\n';
                }
                else{
                    cout<<c<<'*'<<"sqrt("<<r<<")/"<<d<<'\n';
                }
            }





        }



    }

    return 0;
}
