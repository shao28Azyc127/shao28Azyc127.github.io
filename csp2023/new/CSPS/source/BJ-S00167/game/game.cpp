#include <iostream>
#include <cstdio>
using namespace std;
int n,s=0,etop=0,etop1=0,etop2=0,flag=0,etop3=0,etop4=0,abc=0;
char ll[10001]={},l[10001],lll[10001][1001]={};
void pop(){
    if(etop>0){
        ll[etop]=' ';
        etop--;
    }
}
void push(char a){
    ll[++etop]=a;
}
char top(){
    return ll[etop];
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>l[i];
    }
    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            etop2=0;
            for(int k=i;k<=j;k++){
                lll[etop1][etop2]=l[k];
                etop2++;
            }
            etop1++;
        }
    }
    for(int i=0;i<1000;i++){
        for(int j=0;j<11;j++){
            if(!lll[i][0]){
                etop3=1;
                etop4=i-1;
                break;
            }
        }
        if(etop3==1){
            break;
        }
    }
    for(int k=0;k<etop4;k++){
        abc=0;
        for(int j=0;j<11;j++){
            l[j]=lll[k][j];
        }
        for(int i=0;i<n;i++){
            if(l[i]==top()){
                pop();
            }else{
                push(l[i]);
            }
        }
        for(int i=0;i<100;i++){
            if(ll[i]){
                abc=1;
                break;
            }
        }
        if(abc==0){
            s++;
        }
    }

    cout<<s;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
