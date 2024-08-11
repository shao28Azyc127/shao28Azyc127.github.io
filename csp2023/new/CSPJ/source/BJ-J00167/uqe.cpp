#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define int long long
int Txx,TTTT;

bool derta_judge(int derta){
    int tmp = (int)sqrt((double)derta);
    return (tmp * tmp == derta);
}
int gcd(int a,int b){
    if(a % b == 0) return b;
    else return gcd(b,a % b);
}
void print_youlishu(int fenmu,int fenzi)
{
    if(fenzi == 0){
        printf("0");
        return ;
    }
    bool fushu_fenmu,fushu_fenzi;
    if(fenmu < 0) fushu_fenmu = 1;
    else fushu_fenmu = 0;
    if(fenzi < 0) fushu_fenzi = 1;
    else fushu_fenzi = 0;
    fenmu = abs(fenmu),fenzi = abs(fenzi);

    int tmp = gcd(fenmu,fenzi);
    fenmu /= tmp,fenzi /= tmp;

    if((fushu_fenmu + fushu_fenzi) % 2 == 0){
        if(fenmu == 1) printf("%lld",fenzi);
        else printf("%lld/%lld",fenzi,fenmu);
    }else{
        printf("-");
        if(fenmu == 1) printf("%lld",fenzi);
        else printf("%lld/%lld",fenzi,fenmu);
    }
}
void solve(int now)
{
    int a,b,c; scanf("%lld%lld%lld",&a,&b,&c);
    int derta = b * b - 4 * a * c;
    if(derta < 0){//wu jie
        printf("NO\n");
        return ;
    }
    else if(derta_judge(derta) == true){//you li shu
        int fenmu = 2 * a;
        int fenzi_a = -b + (int)sqrt((double)derta);
        int fenzi_b = -b - (int)sqrt((double)derta);
        int fenzi;
        if(fenmu < 0) fenzi = min(fenzi_a,fenzi_b);
        else fenzi = max(fenzi_a,fenzi_b);
        print_youlishu(fenmu,fenzi);
        printf("\n");
    }else{//wu li shu
        //r
        int zheng = 1,genhao = derta;
        for(int i = 2; i <= 2300 && i * i <= genhao; i++){
            while(genhao % (i * i) == 0) zheng *= i,genhao /= (i * i);
        }
        //q1 = -b + /2a
        int q1_fenmu = 2 * a;
        int q1_fenzi = -b;
        if(q1_fenzi != 0) print_youlishu(q1_fenmu,q1_fenzi);
        if(q1_fenzi != 0) printf("+");
        //q2
        int q2_fenmu = 2 * a;
        int q2_fenzi = zheng;
        if(q2_fenzi *q2_fenmu < 0) q2_fenzi = -q2_fenzi;
        if(q2_fenzi + q2_fenmu < 0) q2_fenzi = -q2_fenzi,q2_fenmu = -q2_fenmu;
        if(abs(zheng) == abs(2 * a)) printf("sqrt(%lld)",genhao);
        else if(q2_fenzi % q2_fenmu == 0) printf("%lld*sqrt(%lld)",q2_fenzi / q2_fenmu,genhao);
        else if(q2_fenmu % q2_fenzi == 0) printf("sqrt(%lld)/%lld",genhao,q2_fenmu / q2_fenzi);
        else{
            bool q2_fushu_fenmu,q2_fushu_fenzi;
            if(q2_fenmu < 0) q2_fushu_fenmu = 1;
            else q2_fushu_fenmu = 0;
            if(q2_fenzi < 0) q2_fushu_fenzi = 1;
            else q2_fushu_fenzi = 0;
            q2_fenmu = abs(q2_fenmu),q2_fenzi = abs(q2_fenzi);

            int q2_tmp = gcd(q2_fenmu,q2_fenzi);
            q2_fenmu /= q2_tmp,q2_fenzi /= q2_tmp;

            if(q2_fushu_fenzi) printf("-");
            printf("%lld",q2_fenzi);
            printf("*sqrt(%lld)/",genhao);
            if(q2_fushu_fenmu) printf("-");
            printf("%lld",q2_fenmu);
        }
        printf("\n");
    }
}

signed main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    scanf("%lld%lld",&Txx,&TTTT);
    for(int i = 1; i <= Txx; i++) solve(i);
    return 0;
}
