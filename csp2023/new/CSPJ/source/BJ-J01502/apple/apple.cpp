#include<bits/stdc++.h>
using namespace std;

int n,m,c,t,c1;

struct node{
    int n;
    bool f;
}a[1000010];

int main(){
    int i,j;

    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);

    cin >> n;

    m = n;

    while(m != 0){
        c++;
        m = m - ceil(m / 3.0);
    }

    for(i = 1;i <= n;i++){
        a[i].n = i;
        a[i].f = false;
    }

    while(!a[n].f){
        t = 0;
        c1++;
        for(i = 1;i <= n;i++){
            if(!a[i].f){
                t++;
                if(t % 3 == 1){
                    a[i].f = true;
                }
            }
        }
    }

    cout << c << " " << c1 << endl;
}