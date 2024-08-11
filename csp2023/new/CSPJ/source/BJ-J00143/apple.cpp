#include<bits/stdc++.h>
using namespace std;
int a, b=1000000000;
void ss(int x, int id){
    //cout<<"ss( "<<x<<" , "<<id<<" );\n";
    if(x%3==1){
        b=min(b, id);
    }
    if(x==1){
        a=id;
        return;
    }
    ss(x-((x-1)/3+1), id+1);
}
int main(){
    freopen("apple.in", "r", stdin);
    freopen("apple.out", "w", stdout);
    int n;
    cin>>n;
    ss(n, 1);
    cout<<a<<" "<<b;
    return 0;
}