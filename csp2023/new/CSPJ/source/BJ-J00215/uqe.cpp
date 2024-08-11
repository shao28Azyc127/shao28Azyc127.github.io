#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int t,m,a,b,c;
    scanf("%d %d",&t,&m);
    for(int i = 0;i < t;i++){
        scanf("%d %d %d",&a,&b,&c);
        int delta;
        delta = b * b - 4 * a * c;
        if(delta < 0)printf("NO\n");
        else{
            int j1,j2,j;
            j1 = (-1 * b + sqrt(delta)) / (2 * a);
            j2 = (-1 * b - sqrt(delta)) / (2 * a);
            j = max(j1,j2);
            cout << j << endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
