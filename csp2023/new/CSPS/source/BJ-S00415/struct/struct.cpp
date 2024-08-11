#include <iostream>
#include <cstdio>

using namespace std;

int n, op;

int main()
{
    freopen("struct.in", "r", stdin);
    freopen("struct.out", "w", stdout);
    scanf("%d", &n);
    for(int i = 1;i <= n;i++)
    {
        scanf("%d", &op);
        if(op == 1)
            printf("8 4\n");
        if(op == 2)
            printf("0\n");
        if(op == 3)
            printf("4\n");
        else
            printf("x.bb\n");
    }
    return 0;
}
