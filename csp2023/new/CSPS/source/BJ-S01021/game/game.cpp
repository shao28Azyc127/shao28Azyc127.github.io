#include<bits/stdc++.h>
using namespace std;
int n,ans;
char n1[15];
int main(){
    std::ios::sync_with_stdio(0);
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    if(n==1){
        cout<<0<<endl;
        return 0;
    }
    cin>>n1;
    if(n==2){
        if(n1[0]==n1[1]){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    else if(n==3){
        if(n1[0]==n1[1]||n1[1]==n1[2]){
            cout<<1<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    else if(n==4){
        if(n1[0]==n1[1]&&n1[2]!=n1[3]){
            cout<<1<<endl;
        }
        else if(n1[0]!=n1[1]&&n1[2]==n1[3]){
            cout<<1<<endl;
        }
        else if(n1[0]==n1[3]&&n1[1]==n1[2]||n1[0]==n1[1]&&n1[2]==n1[3]){
            cout<<2<<endl;
        }
        else{
            cout<<0<<endl;
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}