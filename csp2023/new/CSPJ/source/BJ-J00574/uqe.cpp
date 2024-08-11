#include <bits/stdc++.h>

using namespace std;

int t,m;
int cf(int a,int k){
    int ans = 1;
    while(k--){
        ans*=a;
    }
    return ans;
}
int gcd(int a,int b){
    if(a%b)return gcd(b,a%b);
    return b;
}
int d2r(int r){
    for(int i = sqrt(r);i>1;i--){
        if(r%(i*i)==0){
            return i;
        }
    }
    return 1;
}
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int a,b,c;
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        int dert = cf(b,2)-4*a*c,a2 = a,b2 = b,c2 = c;
        if(dert<0){
            cout<<"NO"<<endl;
            continue;
        }
        int d;
        if(dert == 0){
            if(b == 0){
                cout<<0<<endl;
                continue;
            }
            d = gcd(2*a,b);
            a = 2*a/d;
            b = b/d;
            b = 0-b;
            if(a==1){
                cout<<b<<endl;
                continue;
            }
            if(a==-1){
                cout<<0-b<<endl;
                continue;
            }
            if(a<0){
                a = 0-a;
                b = 0-b;
            }
            printf("%d/%d",b,a);
            cout<<endl;
            continue;
        }
        if((int)(sqrt(dert)) == sqrt(dert)){
            b = 0-b;
            b+=sqrt(dert);
            if(b == 0){
                cout<<0<<endl;
                continue;
            }
            d = gcd(2*a,b);
            if(d!=1){
                a = 2*a/d;
                b = b/d;
            }
            if(a==1){
                cout<<b<<endl;
                continue;
            }
            if(a==-1){
                cout<<0-b<<endl;
                continue;
            }
            if(a<0){
                a = 0-a;
                b = 0-b;
            }
            printf("%d/%d",b,a);
            continue;
        }
        if(b){
            d = gcd(2*a,b);
            a = 2*a/d;
            b = b/d;
            b = 0-b;
            if(a==1){
                cout<<b<<"+";
            }
            else if(a==-1){
                cout<<0-b<<"+";
            }
            else{
                if(a<0){
                    a = 0-a;
                    b = 0-b;
                }
                printf("%d/%d+",b,a);
            }
        }
        int cr = d2r(dert);
        dert = dert/(cr*cr);
        int v = gcd(cr,2*a2);
        if(cr == 2*a2){
            printf("sqrt(%d)",dert);
            cout<<endl;
            continue;
        }
        if(cr%(2*a2)==0&&cr>a2){
            printf("%d*sqrt(%d)",abs(cr/(2*a2)),dert);
            cout<<endl;
            continue;
        }
        if(a2%cr == 0&&2*a2>cr){
            printf("sqrt(%d)/%d",dert,2*a2/cr);
            cout<<endl;
            continue;
        }
        cr = cr/v;
        a2 = 2*a2/v;
        if(a2<0){
            a2 = 0-a2;
            cr = 0-cr;
        }
        if(cr<0){
            cr = 0-cr;
        }
        printf("%d*sqrt(%d)/%d",cr,dert,a2);
        cout<<endl;
    }
    return 0;
}
