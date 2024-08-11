#include<iostream>
#include<stdio.h>
#include<cstdio>
using namespace std;
int main(){
    freopen("apple.in",'r',stdin);
    freopen("apple.out",'w',stdout);
    int n,d,mon,x;
    cin>>n>>d;
    int road[n-1],oil[n];
    for(int i=0;i<n-1;i++){
        cin>>road[i];
    }
    for(int i=0;i<n;i++){
        cin>>oil[i];
    }
    for(int i=0;i<n-1){
        x = i;
        if(oil[x]<=oil[i+1]){
            for(int j=x;j<n-1;j+=1){
                if(oil[x]<=oil[j+1]){
                }
                else{
                    break;
                }
            }
        }

    }
    return 0;
}

