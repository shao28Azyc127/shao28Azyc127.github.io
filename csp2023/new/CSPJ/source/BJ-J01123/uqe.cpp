#include <bits/stdc++.h>

using namespace std;

int gcd(int m,int n){
    if(m>n){
        swap(m,n);
    }
    if(n%m==0){
        return m;
    }
    return gcd(n%m,m);
}
void printp(int m,int n){
    if(m==0){
        cout << 0;
        return ;
    }int k=0;
    if(m<0)k++;
    if(n<0)k++;
    if(k==1)cout << "-";
    m = abs(m);
    n = abs(n);
    if(m==n){
        cout << 1;
        return ;
    }
    if(m%n==0){
        cout << m/n;
        return ;
    }int gy = gcd(m,n);
    cout << m/gy << "/" << n/gy;
}
bool num[50000001];
int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin >> T >> M;
    int a,b,c;
    int dt;
    for(int i=1;i<=sqrt(5000000);i++){
        num[i*i] = true;
    }
    while(T--){
        cin >> a >> b >> c;
        dt = b*b-4*a*c;
        if(dt<0){
            cout << "NO" << endl;
            continue;
        }
        if(num[dt]){
            if(a>0)printp(-b+sqrt(dt),2*a);
            else printp(-b-sqrt(dt),2*a);
            cout << endl;
        }else{
            bool fu = false;
            if(dt==0){
                printp(-b,2*a);
                continue;
            }
                if(b!=0){
                    printp(-b,2*a);
                    cout << "+";
                }int q2=1;
                for(int i=sqrt(dt);i>=2;i--){
                    if(dt%(i*i)==0){
                        q2*=i;
                        dt/=(i*i);
                    }
                }
                a = abs(a);
                if(q2==2*a){
                    printf("sqrt(%d)\n",dt);
                }else if(q2%(2*a)==0){
                    printf("%d*sqrt(%d)\n",(q2/(2*a)),dt);
                }else if(2*a%(q2)==0){
                    printf("sqrt(%d)/%d\n",dt,(2*a/q2));
                }else{
                    int gy = gcd(q2,2*a);
                    printf("%d*sqrt(%d)/%d\n",q2/gy,dt,2*a/gy);
                }
        }
    }
    return 0;
}
