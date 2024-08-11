#include<bits/stdc++.h>
using namespace std;
int n,a[10][10];
int fd(int a,int b,int dre){
    if(dre==1){
        if(a>b){
            return 10+(b-a);
        }else{
            return (b-a);
        }
    }else{
        if(a<b){
            return 10+(a-b);
        }else{
            return (a-b);
        }
    }
}bool change(int a[],int b[]){
    int cnt=0;int flag=-1,fds=-123;
    int x=0,y=0;
    for(int i=1;i<=5;i++){
        if(a[i]!=b[i]){
            if(flag!=i-1&&cnt>=1){
                return false;
            }if((fd(a[i],b[i],1)!=fd(x,y,1)||fd(a[i
            ],b[i],0)!=fd(x,y,0))&&cnt>=1){
                return false;
            }cnt++;flag=i;
            x=a[i],y=b[i];
        }if(cnt>=3){
            return false;
        }
    }if(cnt!=0){
        return true;
    }else{
        return false;
    }return true;
}int ch[10],cnts=0;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=5;j++){
            cin>>a[i][j];
        }
    }for(int i=0;i<=9;i++){
        for(int j=0;j<=9;j++){
            for(int k=0;k<=9;k++){
                for(int e=0;e<=9;e++){
                    for(int x=0;x<=9;x++){
                        ch[1]=i,ch[2]=j,ch[3]=k;
                        ch[4]=e,ch[5]=x;
                        bool flag=1;
                        if(change(ch,a[1])){
                            for(int m=2;m<=n;m++){
                                if(!change(ch,a[m])){
                                    flag=0;
                                    break;
                                }
                            }
                            if(flag==1){
                                cnts++;int m=1;
                            }
                        }
                    }
                }
            }
        }
    }cout<<cnts;

    return 0;
}
