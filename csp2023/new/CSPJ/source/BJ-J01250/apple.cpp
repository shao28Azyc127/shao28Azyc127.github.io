#include<iostream>
#include<stdio.h>
using namespace std;
int fa(int n){
    int c=0;
    while(true){
        c++;
        n=n-(n/4+1);
        if(n%3==1){
            return c+1;
        }
    }
}
int fb(int n){
    int c=0;
    while(true){
        c++;
        n=n-(n/4+2);
        if(n%3==1){
            return c+1;
        }
    }
}
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n,c=0;
    bool flag=true;
    cin>>n;
    int t=n;
    while(flag){
        c++;
        n=n-(n/4+1);
        if(n==0){
            flag=false;
        }
    }
    cout<<c<<" ";
    if(t==3){
        t++;
    }
    if(t%3==1){
        cout<<"1";
    }else if(t%3==0){
        cout<<fa(t);
    }else if(t%3==2){
        cout<<fb(t);
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
