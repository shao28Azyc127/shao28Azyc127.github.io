#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;
int main(){
    freopen("apple.in","r",stdin)
    freopen("apple.out","w",stdout)
    int an,ae=0,t=0,as,res=0;
    cin >> an;
    bool apple[an];
    for (int i=0;i<an;i++) apple[i]=1;
    while (an-ae){
        t++;
        as=0;
        for (int i=0;i<an;i++){
            if (apple[i]){
                if (!(as%3)) {
                    apple[i]=0;
                    ae++;
                }
                as++;
            }
        }
        if (!res && !apple[an-1]) res=t;
    }
    cout << t << " " << res << endl;
    return 0;
}