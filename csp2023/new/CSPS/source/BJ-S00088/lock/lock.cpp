//please using C++ 17
#include<bits/stdc++.h>
using namespace std;
ifstream __cin("lock.in");
ofstream __cout("lock.out");
#define cout __cout
#define cin __cin
vector<string>sts[8];
void allpwd(string st,vector<string>& out){
    map<string,int>mp;
    for(int i=0;i<5;i++){
        for(int j=1;j<10;j++){
            string tmp=st;
            tmp[i]-=48;
            tmp[i]+=j;
            tmp[i]%=10;
            tmp[i]+=48;
            mp[tmp]++;
            //cout<<tmp<<'\n';
        }for(int j=1;j<10&&i<4;j++){
            //cout<<"log\n";
            string tmp=st;
            tmp[i]-=48;
            tmp[i]+=j;
            tmp[i]%=10;
            tmp[i]+=48;
            tmp[i+1]-=48;
            tmp[i+1]+=j;
            tmp[i+1]%=10;
            tmp[i+1]+=48;
            mp[tmp]++;
            //cout<<tmp<<'\n';
        }
    }for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++)
        out.push_back(it->first);
    //for(string &s:out)cout<<s<<' ';
}
int main(){
    cin.tie(0);
    cout.tie(0);
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        string tmp;
        for(int j=0;j<5;j++){
            int a;
            cin>>a;
            tmp+=(char)(a+48);
        }allpwd(tmp,sts[i]);
    }map<string,int>mp;
    for(int i=0;i<n;i++){
        for(string &s:sts[i]){
            mp[s]++;
        }
    }int ans=0;
    for(map<string,int>::iterator it=mp.begin();it!=mp.end();it++){
        if((it->second)>=n)ans++;
    }cout<<ans;
}
