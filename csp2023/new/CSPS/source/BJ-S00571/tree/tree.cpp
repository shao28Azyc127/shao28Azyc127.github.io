#include<bits/stdc++.h>
using namespace std;
struct IO{
    IO(){
        freopen("tree.in","r",stdin);
        freopen("tree.out","w",stdout);
    }
    ~IO(){
        fclose(stdin);
        fclose(stdout);
    }
}io;
int n;
int main(){
    cin>>n;
    cout<<n+1;
    return 0;
}
