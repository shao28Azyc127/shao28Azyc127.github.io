#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int Max = 1e5+10;
ll rd(){
    int x=0;int f=1;

    char b = getchar();
    while(!isdigit(b)){
        if(b=='-') f=-1;
        b=getchar();
    }
    while (isdigit(b)){
        x = x*10 + b - '0';
        b = getchar();
    }
    return x*f;

}

bool isg(int a,int b){
    int n[a],m[b];
    int cnt=0;
    for(int i = 2; i < a; i++){
        if(a%i==0){
            n[++cnt] = i;
        }
    }
    int cmt = 0;
    for(int i = 1; i <= b ; i++){
        if(a%i==0){
            m[++cmt] = i;
        }
    }
    for(int i = 0; i < cnt;i++){
        for(int j = 0; j < cmt; j++){
            if(n[i] == m[j]) return false;
        }
    }
    return true;
}
int t,m;
int p,q;
bool isrea(ll a,ll b,ll c){
    for(int i=-m;i <= m;i++){
        for(int j =-m; j <= m ; j++){
            if((b*b - (4*a*c))*j*j == pow(2,(2*a*i)+(b*j))&&isg(i,j)){
                p=i;q=j;
                return true;
            }

        }
    }
    return false;

}


int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    t=rd();m=rd();
    while(t--){
        int a=rd(),b=rd(),c=rd();
        if((b*b) - (4*a*c) < 0){
            cout << "No"<<endl;
            continue;
        }
        ll x = (b*b) - (4*a*c);
            //x=-b+sqrt(b^2-4ac)/2a
            if(isrea(a,b,c)){
                if(q==1) cout << p<<endl;
                else cout << p <<"/" << q<<endl;
                continue;
            }else{
                if(-b/(2*a) != 0){
                    if(2*a == 1){
                        cout << -b <<"+";
                    }else{
                        cout << -b << "/" << 2*a << "+";
                    }
                }
                if(1/(2*a) == 1)cout << "sqrt(" << x <<")"<<endl;
                if((double)1/(2*a) == 1/(2*a)){
                    cout << 1/(2*a) << "*" << "sqrt(" << x <<")"<<endl;
                }
                else if((double)(2*a) == (2*a)){
                    cout <<  "sqrt(" << x <<")/" << 2*a<<endl;
                    continue;
                }
                else{
                    int t1,t2;
                    //bool flag = false;
                     for(int i=-m;i <= m;i++){
                        for(int j =-m; j <= m ; j++){
                            if(2*a*i == j && isg(i,j)){
                                t1=1;t2=j;
                            }

                        }
                    }
                    cout << t1 << "*" << "sqrt("<<x<<")/"<<t2<<endl;
                    continue;
                }

            }

    }

    return 0;
}
