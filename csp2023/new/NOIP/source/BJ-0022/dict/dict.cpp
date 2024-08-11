#include <bits/stdc++.h>
using namespace std;
#define FILENAME "dict"
ifstream fin{FILENAME".in"};
ofstream fout{FILENAME".out"};

enum{ N=3003,M=3003 };
string S[N];
int main(){
    int n,m; fin>>n>>m;
    if(n==1) fout<<"1\n", exit(0);
    int i1{0},i2{0};
    for(int i=1;i<=n;i++){
        string s; fin>>s;
        sort(s.begin(),s.end(),greater<int>());
        if(!i1||s<S[i1]) i2=i1, i1=i;
        else if(!i2||s<S[i2]) i2=i;
        S[i]=move(s);
    }
    for(int i=1;i<=n;i++){
        string s=S[i];
        reverse(s.begin(),s.end());
        if(i!=i1) fout<<(s<S[i1]);
        else fout<<(s<S[i2]);
    }
    fout<<'\n';
}