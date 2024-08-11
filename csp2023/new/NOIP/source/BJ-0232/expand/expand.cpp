#include<bits/stdc++.h>
using namespace std;
const int N = 5e5+9;
int num;
int n, m, q;
int x[N], y[N];
bool judge(int a, int b, int c, int d){
    if(a==c || b==d) return 1;
    if(a>c && b<d) return 1;
    if(a<c && b>d) return 1;
    return 0;
}
int main(){
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin>>n>>m>>q;
    for(int i=1; i<=n; ++i){
        scanf("%d", &x[i]);
    }
    for(int i=1; i<=m; ++i){
        scanf("%d", &y[i]);
    }
    if(n==1 && m==1){
        if(x[1]==y[1]) putchar('0');
        else putchar('1');
        for(int i=1; i<=q; ++i){
            int kx, ky;
            scanf("%d%d", &kx, &ky);
            for(int j=1; j<=kx; ++j){
                int loc, to;
                scanf("%d%d", &loc, &to);
                x[loc] = to;
            }for(int j=1; j<=ky; ++j){
                int loc, to;
                scanf("%d%d", &loc, &to);
                y[loc] = to;
            }
            if(x[1]==y[1]) putchar('0');
            else putchar('1');
        }
    }else if(n==2 && m==2){
        if(judge(x[1], x[2], y[1], y[2])) putchar('0');
        else putchar('1');
        for(int i=1; i<=q; ++i){
            int kx, ky;
            scanf("%d%d", &kx, &ky);
            for(int j=1; j<=kx; ++j){
                int loc, to;
                scanf("%d%d", &loc, &to);
                x[loc] = to;
            }for(int j=1; j<=ky; ++j){
                int loc, to;
                scanf("%d%d", &loc, &to);
                y[loc] = to;
            }
            if(judge(x[1], x[2], y[1], y[2])) putchar('0');
            else putchar('1');
        }
    }else if(n==2 && m==1){
        if(judge(x[1], x[2], y[1], y[1])) putchar('0');
        else putchar('1');
        for(int i=1; i<=q; ++i){
            int kx, ky;
            scanf("%d%d", &kx, &ky);
            for(int j=1; j<=kx; ++j){
                int loc, to;
                scanf("%d%d", &loc, &to);
                x[loc] = to;
            }for(int j=1; j<=ky; ++j){
                int loc, to;
                scanf("%d%d", &loc, &to);
                y[loc] = to;
            }
            if(judge(x[1], x[2], y[1], y[1])) putchar('0');
            else putchar('1');
        }
    }else if(m==2 && n==1){
        if(judge(x[1], x[1], y[1], y[2])) putchar('0');
        else putchar('1');
        for(int i=1; i<=q; ++i){
            int kx, ky;
            scanf("%d%d", &kx, &ky);
            for(int j=1; j<=kx; ++j){
                int loc, to;
                scanf("%d%d", &loc, &to);
                x[loc] = to;
            }for(int j=1; j<=ky; ++j){
                int loc, to;
                scanf("%d%d", &loc, &to);
                y[loc] = to;
            }
            if(judge(x[1], x[1], y[1], y[2])) putchar('0');
            else putchar('1');
        }
    }else{
        if(judge(x[1], x[2], y[1], y[2])) putchar('0');
        else putchar('1');
        for(int i=1; i<=q; ++i){
            int kx, ky;
            scanf("%d%d", &kx, &ky);
            for(int j=1; j<=kx; ++j){
                int loc, to;
                scanf("%d%d", &loc, &to);
                x[loc] = to;
            }for(int j=1; j<=ky; ++j){
                int loc, to;
                scanf("%d%d", &loc, &to);
                y[loc] = to;
            }
            if(judge(x[1], x[2], y[1], y[2])) putchar('0');
            else putchar('1');
        }
    }
    return 0;
}