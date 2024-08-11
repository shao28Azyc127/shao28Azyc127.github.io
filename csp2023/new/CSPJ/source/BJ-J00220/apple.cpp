#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    int tn=n;

    int c=0;
    while(n){
        int t=n/3;
        if(n%3>0)t++;
        c++;
        n-=t;
    }
    cout<<c<<' ';

    n=tn;
    c=1;
    while(n%3!=1){
        int t=n/3;
        if(n%3>0)t++;
        c++;
        n-=t;
    }
    cout<<c;
    return 0;
}
/*
1 2 3 4 5 6 7 8
2 3 5 6 8
3 5 8
5 8
8

8/3 3
5/3 2
3/3 1
2/3 1
1/3 1

#1
1

#2
2

#3
3

#4
1000000000

#5
32489463

#6
7329133

#7
10

#8
50
*/
