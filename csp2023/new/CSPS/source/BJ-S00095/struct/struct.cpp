#include<bits/stdc++.h>
using namespace std;
#define int long long
#define mod 998244853
int n,k,lastest=1;
string t[10010],Empty;
map<int,string> hashcheck;
map<int,int> hashs;
int HASH(string s){
    //cout<<s<<'\n';
    int res=0;
    //cout<<"?\n";
    for(int i=1;i<=s.size();i++){
        res=((res*26)+s[i-1]-'a')%mod;
    }//cout<<"?\n";
    return res;
}void getstring(string *s){
    //string s;
    char ch=getchar();int cnt=0;
    while(ch==' '||ch=='\n') ch=getchar();
    while(ch<='z'&&ch>='a'){
        //cout<<ch<<'\n';
        s[cnt]=ch;cnt++;
        //cout<<cnt<<'\n';
        ch=getchar();
    }//cout<<"??\n";
    return;
}void solve2(){
    string s,name;
    getstring(&s);//cout<<s<<'\n';
    getstring(&name);
    int res=HASH(name);
    while(hashs[res]!=0) res++;
    hashcheck[res]=name;
    if(s[0]=='b'){
        t[lastest]=name;
        lastest++;
        hashs[res]=lastest-1;
    }else{
        if(s[0]=='s'){
            if(lastest%2!=0){
                lastest++;
            }t[lastest]=name;
            t[lastest+1]=name;
            lastest+=2;
            hashs[res]=lastest-2;
        }else{
            if(s[0]=='i'){
                if(lastest%4!=0){
                    lastest=((lastest/4)+1)*4;
                }for(int i=0;i<4;i++){
                    t[lastest+i]=name;
                }lastest+=4;
                hashs[res]=lastest-4;
            }else{
                    if(s[0]=='l'){
                        if(lastest%8!=0){
                        lastest=((lastest/8)+1)*8;
                    }for(int i=0;i<8;i++){
                        t[lastest+i]=name;
                    }
                }lastest+=8;
                hashs[res]=lastest-8;
            }
        }
    }cout<<hashs[res]-1<<'\n';
}void solve3(){
    string now;
    getstring(&now);
    int res=HASH(now);
    while(hashcheck[res]!=now) res++;
    cout<<hashs[res]-1<<'\n';
}void solve4(){
    int addr;
    cin>>addr;
    if(t[addr]!=Empty){
        cout<<t[addr+1]<<'\n';
    }else{
        cout<<"ERR\n";
    }
}signed main(){
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++){
        //cout<<i<<'\n';
        int op;
        cin>>op;
        if(op==2){
            solve2();
        }else{
            if(op==3){
                solve3();
            }else{
                if(op==4){
                    solve4();
                }
            }
        }
    }fclose(stdin);
    fclose(stdout);
    return 0;
}
