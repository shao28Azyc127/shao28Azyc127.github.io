#include<iostream>
#include<cstdlib>

using namespace std;
int main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    unsigned seed = time(0);
    srand(seed);


    cout << seed%10+1;

    return 0;
}
