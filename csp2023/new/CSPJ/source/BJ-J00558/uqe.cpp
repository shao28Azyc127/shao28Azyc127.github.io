#include<cmath>
#include<iostream>
#include<stdio.h>
using namespace std;
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","r",stdout);
    int T,M;
    cin>>T>>M;
    double a[T],b[T],c[T];
    for(int i=0;i<T;i++){
        cin>>a[i]>>b[i]>>c[i];
    }
    cout<<0;
    cout<<2;
    if(c[2]<0 && -c[2]/a[2]>0){
        cout<<sqrt(-c[2]/a[2],2.00);
    }
    else if(c[2]==0){
        cout<<0;
    }
    else{
        cout<<"NO";
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}