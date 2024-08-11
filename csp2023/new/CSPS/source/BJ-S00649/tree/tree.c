#include<stdio.h>
#inlcude<rand.h>
using namespace std;

int main()
{
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);
    printf("%d",rand());
    fclose(stdin);
    fclose(stdout);
    return 0;
}
