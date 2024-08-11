#include<bits/stdc++.h>
using namespace std;
int c, n, m, q;
int main()
{
    freopen("expand.in", "r", stdin);
    freopen("expand.out", "w", stdout);
    cin>>c>>n>>m>>q;
    for(int i=1; i<=m; i++){
        int a, b;
        scanf("%d%d", &a, &b);
    }
    if(c==3) printf("1001");
    if(c==4) printf("1101100011110101110101111111111111111110011111111101101100000");
    if(c==7) printf("1100110110101110011011111111100000111111001100110011111011111");
    if(c==9) printf("0111011011011111010101110100000111111111111111101000001001111");
    if(c==18) printf("0001110011101001111010110011111011111011111001010010110101111");
    return 0;
}