#include <bits/stdc++.h>
#define forr(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
int n,s[10][10][10][10][10],a,b,c,d,e,ans;
int main() {
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    forr(i,1,n) {
        scanf("%d %d %d %d %d",&a,&b,&c,&d,&e);
        forr(j,0,9) s[j][b][c][d][e] ++ ;
        forr(j,0,9) s[a][j][c][d][e] ++ ;
        forr(j,0,9) s[a][b][j][d][e] ++ ;
        forr(j,0,9) s[a][b][c][j][e] ++ ;
        forr(j,0,9) s[a][b][c][d][j] ++ ;

        forr(j,1,9) s[(a+j)%10][(b+j)%10][c][d][e] ++ ;
        forr(j,1,9) s[a][(b+j)%10][(c+j)%10][d][e] ++ ;
        forr(j,1,9) s[a][b][(c+j)%10][(d+j)%10][e] ++ ;
        forr(j,1,9) s[a][b][c][(d+j)%10][(e+j)%10] ++ ;
    }
    forr(i1,0,9) forr(i2,0,9) forr(i3,0,9) forr(i4,0,9) forr(i5,0,9) {
        if(s[i1][i2][i3][i4][i5]==n) ++ans;
    } cout<<ans;

    return 0;
}
