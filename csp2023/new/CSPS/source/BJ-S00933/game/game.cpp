#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("game.in",r);
    freopen("game.out",w);
    string n,m;
    cin>>n;
    m=n;
    int s=0;
    while(l>0){
        int l=m.length();
        for(int i=0;i<l;i++){
            if(m[i]==m[i+1])s++;
            m[i]="";
            m[i+1]="";
        }
    }
    cout<<s;
    fclose();
    return 0;
}