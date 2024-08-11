#include<bits/stdc++.h>
using namespace std;
int t,m,a,b,c;
int dt;
int x1,x2;
int gcd(int a,int b){
    if(a % b == 0)return b;
    else return gcd(b,a % b);
}
bool check(int n){
    for(int i = 1;i <= n;i++){
        if((i * i) == n)return true;
    }
    return false;
}
void chai1(int n,int a,int b,int c){//yue fen
    int o = (-b) + sqrt(dt),p = 2 * a;
    int t = gcd(o,p);
    if(t > 1){
        o /= t;
        p /= t;
    }
    else if(t < 1){
        o /= abs(t);
        p /= abs(t);
    }
    if(o % p == 0)printf("%d",o / p);
    else if(o == 0)printf("0");
    else printf("%d/%d",o,p);
}

void chai2(int n,int a,int b,int c){//hua jian gen hao  n == dt;
    int q = 0;
    int o = -b,x = 2 * a;
    for(int i = n;i >= 1;i--){
        if(n - (i * i) > 0 && n % (i * i) == 0){
            q = i;
            n /= (i * i);
            break;
        }
    }
    int ttt = x;
    int tt = x;
    //xishu -b
    int t = gcd(o,tt);
    if(t > 1){
        o /= t;
        tt /= t;
    }else if(t < -1){
        o /= abs(t);
        tt /= abs(t);
    }
    //xishu q
    int t1 = gcd(q,x);
    if(t1 > 1){
        q /= t1;
        x /= t1;
    }
    else if(t1 < -1){
        q /= abs(t1);
        x /= abs(t1);
    }
    if(q == 1){
        if(o == 0){
            if(q % x == 0)printf("sqrt(%d)\n",n);
            printf("sqrt(%d)/%d\n",n,2 * a);
        }
        else if(o % tt == 0)printf("%d+sqrt(%d)/%d\n",o / tt,n,x);
        else printf("%d/%d+sqrt(%d)/%d\n",o,tt,n,ttt);
    }
    else if(q != 1){
        if(o == 0){
            if(q % x == 0)printf("%d*sqrt(%d)\n",q,n);
            else printf("%d*sqrt(%d)/%d\n",q,n,tt);
        }
        else if(o % tt == 0 && q % x != 0)printf("%d+%d*sqrt(%d)/%d\n",o / tt,q,n,ttt);
        else if(o % tt == 0 && q % x != 0 && x % q == 0)printf("%d+sqrt(%d)/%d\n",o / tt,n,x / q);
        else if(o % tt == 0 && q % x == 0)printf("%d+%d*sqrt(%d)/%d\n",o / tt,q / x,n,ttt);
        //else printf("%d/%d+%d*sqrt(%d)/%d",o,tt,q,n,x);
        else printf("%d/%d+%d*sqrt(%d)/%d\n",o,ttt,q,n,ttt);
    }
}

void chai3(int a,int b){//dt == 0
    int t = gcd(a,b);
    if(t > 1){
        a /= t;
        b /= t;
    }
    else if(t < -1){
        a /= abs(t);
        b /= abs(t);
    }
    if(a % b == 0)printf("%d\n",a);
    else printf("%d/%d\n",a,b);
}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%d%d",&t,&m);
    for(int i= 1;i <= t;i++){
        scanf("%d%d%d",&a,&b,&c);
        if((b * b) - (4 * a * c) < 0)printf("NO");
        else if((b * b) - (4 * a * c) == 0){
            chai3(-b,2 * a);
        }
        else {
            dt = (b * b) - (4 * a * c);
            if(check(dt)){
                x1 = ((-b)+(sqrt(dt))) / 2 * a;
                x2 = ((-b)-(sqrt(dt))) / 2 * a;
                if(x1 < x2)swap(x1,x2);
                chai1(x1,a,b,c);
            }
            else{
                x1 = ((-b)+(sqrt(dt))) / 2 * a;
                x2 = ((-b)-(sqrt(dt))) / 2 * a;
                if(x1 < x2)swap(x1,x2);
                chai2(dt,a,b,c);
            }
        }
    }


    return 0;
}
