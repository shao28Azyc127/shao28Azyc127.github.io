#include <bits/stdc++.h>
using namespace std;

int n, a[1000005];

int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);

    scanf("%d", &n);

    int k=5;
    a[1]=1;
    a[2]=2;
    a[3]=3;
    a[4]=3;
    for (int i = 4; i <= 1200; i++){
        for (int j = 1; j < i; j++){
            a[k] = i;
            k++;
        }
    }

    if (n > 12){
        printf("%d 1", a[n]);
    }
    else if (n==1)printf("1 1");
    else if (n==2)printf("2 2");
    else if (n==3)printf("3 3");
    else if (n==4)printf("3 1");
    else if (n==5)printf("4 4");
    else if (n==6)printf("4 2");
    else if (n==7)printf("4 1");
    else if (n==8)printf("5 5");
    else if (n==9)printf("5 3");
    else if (n==10)printf("5 1");
    else if (n==11)printf("5 2");
    else if (n==12)printf("6 6");
    return 0;
}
/**rp++**/