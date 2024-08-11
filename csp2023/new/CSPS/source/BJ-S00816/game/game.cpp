#include<iostream>
#include<stdio.h>
using namespace std;
int n,l[1000002]={20000000},r[1000002]={20000000},num=0,cnt=0;
string str;
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>str;
    for(int i=0;i<n-1;i++){
        if(str[i]==str[i+1]){
            int l1=str[i],r1=str[i+1];
            cnt++;
            int j=1;
            while(i-j>=0&&i+1+j<n&&str[i-j]==str[i+1+j]){
                l1=i-j,r1=i+1+j;
                cnt++;
                j++;
            }
            if(l1<=l[num]&&r1>=r[num]){
                l[num]=l1;
                r[num]=r1;
            }
            else if(l1>=l[num]&&r1<=r[num]){}
            else{
                l[++num]=l1;
                r[num]=r1;
            }
        }
    }
    int co=0;
    for(int i=1;i<num;i++){
        if(r[i]+1==l[i+1]) co++;
        else{
            cnt=cnt+co*(co+1)/2;
            co=0;
        }
    }
    cnt=cnt+co*(co+1)/2;
    cout<<cnt<<endl;
    return 0;
}
