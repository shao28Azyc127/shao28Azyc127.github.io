#include<iostream>
#include<map>
#include<string>
#include<iomanip>
#include<bits/stdc++.h>
using namespace std;
int n;
map<string,int> s2;
int main(){
    freopen("lock.in","r",stdin);
    freopen("lock.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++){
        int a[5]; string b="";
        map<string,int> s1;
        for(int j=0;j<5;j++) cin>>a[j];
        for(int j=0;j<5;j++){
            b+=a[j]+'0';
        }
        for(int j=0;j<5;j++){
            for(int k=1;k<=9;k++){
                b[j]=char((a[j]+k)%10+'0');
                s1[b]++;
                b[j]=a[j]+'0';
            }
        }
        for(int j=0;j<4;j++){
            for(int k=1;k<=9;k++){
                b[j]=(a[j]+k)%10+'0';
                b[j+1]=(a[j+1]+k)%10+'0';
                s1[b]++;
                b[j]=a[j]+'0',b[j+1]=a[j+1]+'0';
            }
        }
        for(map<string,int>::iterator j=s1.begin();j!=s1.end();j++){
            if((*j).second>0){

                s2[(*j).first]++;
            }
        }
    }
    int ans=0;
    for(map<string,int>::iterator i=s2.begin();i!=s2.end();i++){
        if((*i).second==n){
            ans++;
        }
    }
    cout<<ans;
    return 0;
}
