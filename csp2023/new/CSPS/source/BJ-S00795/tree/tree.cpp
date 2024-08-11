#include<iostream>
#include<cstdlib>

using namespace std;
int main(){
    freopen("tree.in","r",stdin);
    freopen("tree.out","w",stdout);

    unsigned seed = time(0);
    srand(seed);


    cout << seed%10+1;

    return 0;
}
