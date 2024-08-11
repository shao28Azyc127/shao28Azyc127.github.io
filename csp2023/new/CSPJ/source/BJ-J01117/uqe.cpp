#include<bits/stdc++.h>
using namespace std;

int issqr(int n){
    if(n < 0){
        return -1;
    }
    int sqr = sqrt(n);
    return n == sqr*sqr;
}

void tof(int a,int b,int &p,int &q){
    int g = __gcd(a,b);
    p = a/g;
    q = b/g;
}

void change(int &sq,int &d){
    for(int i = sqrt(sq); i >= 2; i--){
        if((i*i)%sq == 0){
            sq /= i*i;
            d = i;
            return;
        }
    }
    d = 1;
}

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m;
    cin >> t >> m;
    while(t--){
        int a,b,c;
        scanf("%d%d%d",&a,&b,&c);
        int bt = b*b - 4*a*c;
        int op = issqr(bt);
        if(op <= -1){
            printf("NO\n");
        }
        else if(op == 1){
            int sq = sqrt(bt),up;
            if(a>0){
                up = max(0-b+bt,0-b-bt);
            }
            else{
                up = min(0-b+bt,0-b-bt);
            }
            int p,q;
            tof(up,2*a,p,q);
            if(q != 1){
                printf("%d/%d\n",p,q);
            }
            else{
                printf("%d\n",p);
            }
        }
        else{
            int p,q,d;
            tof(0-b,2*a,p,q);
            if(q != 1 && p != 0){
                printf("%d/%d+",p,q);
            }
            else if(p != 0){
                printf("%d+",p);
            }
            bool w = (0-b+sqrt(bt))/2*a > (0-b-sqrt(bt))/2*a;
            change(bt,d);
            int q1 = 1,q2 = 1;
            if(d == 1){
                q2 = 2*a;
            }
            else{
                q1 = d*d;
                q2 = 2*a;
            }
            tof(q1,q2,q1,q2);
            if(w){
                if(q1 != 1){
                    printf("%d*",q1);
                }
                printf("sqrt(%d)",bt);
                if(q2 != 1){
                    printf("/%d",q2);
                }
                printf("\n");
            }
            else{
                q1 = 0-q1;
                if(q1 != 1){
                    printf("%d*",q1);
                }
                printf("sqrt(%d)",bt);
                if(q2 != 1){
                    printf("/%d",q2);
                }
                printf("\n");
            }
        }
    }

    return 0;
}
