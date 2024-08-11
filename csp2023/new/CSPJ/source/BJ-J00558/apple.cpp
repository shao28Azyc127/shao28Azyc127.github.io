#include<iostream>
#include<stdio.h>
#define Max 1000000000
using namespace std;
int n,flag1=0,flag2=0,day=0;
int a[Max]={0},c[Max]={0};
int main(){
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        a[i]=i;
    }
    int w=1;
    bool b[n]={0};
    for(int i=1;i<=Max;i++){
        if(i%2==1){
            for(int j=1;j<=n;j=j+3){
                if(a[j]!=0 && b[j]!=1){
                    if(a[j]==n){
	                flag1=i;
                    }
                    b[j]=1;
                }
            }
            for(int p=1;p<=n;p++){
                if(b[p]!=1){
                    flag2=1;
                }
            }
            if(flag2==0){
                day=i;
                break;
            }else{
                for(int q=1;q<=n;q++){
                    if(b[q]==0){
                        c[w]=a[q];
                        w++;
                    }
                    a[q]=0;
                    b[q]=0;
                }
            }
        }else{
            for(int j=1;j<=n;j=j+3){
	        if(c[j]!=0 && b[j]!=1){
                    if(c[j]==n){
                        flag1=i;
                    }
                    b[j]=1;
                }
            }
            for(int p=1;p<=n;p++){
                if(b[p]!=1){
                    flag2=1;
                }
            }
            if(flag2==0){
                day=i;
                break;
            }else{
                for(int q=1;q<=n;q++){
                    if(b[q]==0){
                        a[w]=c[q];
                        w++;
                    }
                    c[q]=0;
                    b[q]=0;
                }
                flag2=0;
                w=1;
            }
        }
    }
    cout<<day<<" "<<flag1;
    fclose(stdin);
    fclose(stdout);
    return 0;
}