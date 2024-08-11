#include<bits/stdc++.h>

using namespace std;

const int N = 1e5+5;

struct ch{
    long long x, y, v;
} mrr[N];

int c, t;
long long n, m, k, d;

long long cnt = -1;

void findd(long long day, long long con, long long en, long long conbe){
    //printf("%lld %lld %lld %lld\n", day, con, en, conbe);
    if(day > n){
        cnt = max(cnt, en);
        return ;
    }
    for(int i = 1; i <= m; i++){
        if(mrr[i].x < day && mrr[i].y <= con) en += mrr[i].v;
    }
    if(conbe != 0){
        if(conbe == k){
            findd(day+1, con, en, 0);
        }else{
            findd(day+1, max(con, conbe+1), en - d, conbe+1);
            findd(day+1, con, en, 0);
        }
    }else{
        findd(day+1, max(con, conbe+1), en - d, conbe+1);
        findd(day+1, con, en, 0);
    }



}

int main(){
    freopen("run.in", "r", stdin);
    freopen("run.out", "w", stdout);
    cin >>c >> t;
    while(t--){
        memset(mrr, 0, sizeof(mrr));
        cin >> n >> m >>k >>d;
        for(long long i=1;i<=m;i++){
            cin >> mrr[i].x >> mrr[i].y >> mrr[i].v;
        }
        findd(1, 0, 0, 0);
        cout << cnt;
    }


    return 0;
}
