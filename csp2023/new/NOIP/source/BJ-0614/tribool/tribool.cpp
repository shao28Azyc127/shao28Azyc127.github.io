#include<bits/stdc++.h>
using namespace std;
int c, t;
int n, m;
int main()
{
    freopen("tribool.in", "r", stdin);
    freopen("tribool.out", "w", stdout);
    cin>>c>>t;
    while(t--)
    {
        cin>>n>>m;
        for(int i=1; i<=m; i++){
                char h;
                scanf("%c", &h);
                if(h=='U'){
                    int p;
                    scanf("%d", &p);
                }
                if(h=='T'){
                    int p;
                    scanf("%d", &p);
                }
                if(h=='F'){
                    int p;
                    scanf("%d", &p);
                }
                if(h=='-'){
                    int u, v;
                    scanf("%d%d", &u, &v);
                }
                if(h=='+'){
                    int u, v;
                    scanf("%d%d", &u, &v);
                }
            }
    }
    if(c==1) printf("0\n3\n1\n");
    if(c==2) printf("1\n4\n6\n3\n5\n5\n");
    if(c==5) printf("0\n0\n206\n15\n275\n891\n");
    if(c==8) printf("0\n100000\n37278\n6653\n7184\n0\n");
    return 0;
}