#include<bits/stdc++.h>

using namespace std;

int n,num;
string s;
int a[2000005]={0};
bool flag=true;

int f2(int x,int y,int a[]){
    for(int i=x+1;i<=y-1;i++){
        if(a[i]!=1){
            return 0;
        }
    }
    return 1;
}

void f1(int a[]){
    for(int i=1;i<=(n-1)/2;i++){
        if(s[i-1]==s[n-i] && f2(i-1,n-i,a)){
            num++;
        }
    }
}

void hh(int n,string s,int a[]){
    for(int i=3;i<n;i+=2){
        for(int j=0;j<=(n-i);j++){
                bool flag=true;
            for(int k=j;k<=(j+i-2);k++){
                if(s[k]!=s[k+1] || a[k]!=a[k+1]){
                    flag=false;
                    break;
                }
            }
            if(flag) num++;
        }
    }
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n;
    int a[n+9]={0};
    cin>>s;
    for(int i=0;i<(n-1);i++){
        if(s[i]==s[i+1]){
            num++;
            a[i]=1;
            a[i+1]=1;
            int x=i-1,y=i+2;
            while(s[x]==s[y] && y<=(n-1) && x>=0){
                if(x==0 && y==(n-1))flag=false;
                a[x]=1;
                a[y]=1;
                num++;
                x-=1;
                y+=1;
            }
        }
    }
    int sum=0;
    for(int i=0;i<n;i++)
        if(a[i]==1)sum++;
    if(sum==n){
        if(flag){
           num++;
        }
    }else{
        f1(a);
    }
    hh(n,s,a);
    cout<<num;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
