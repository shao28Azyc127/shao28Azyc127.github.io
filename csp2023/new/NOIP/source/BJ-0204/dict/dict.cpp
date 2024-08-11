#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3010;
const int maxm=3010;

ifstream fin("dict.in");
ofstream fout("dict.out");

int n,m;
string s[maxn];
string smx[maxn],smn[maxn];

int main(){
    ios::sync_with_stdio(0);
    fin>>n>>m;
    for(int i=1;i<=n;i++)
        fin>>s[i];

    if(n==1){
        fout<<"1"<<endl;
        return 0;
    }
    for(int i=1;i<=n;i++){
        smn[i]=s[i];
        sort(smn[i].begin(),smn[i].end());
        smx[i]=smn[i];
        reverse(smx[i].begin(),smx[i].end());
    }
    string mn=smx[1],mn2=smx[1];
    for(int i=1;i<=n;i++){
        if(smx[i]<=mn){
            mn2=mn;
            mn=smx[i];
        }
    }
    // fout<<"mn "<<mn<<' '<<mn2<<endl;
    // for(int i=1;i<=n;i++)fout<<smx[i]<<' '<<smn[i]<<endl;
    for(int i=1;i<=n;i++){
        bool flag=1;
        if(smx[i]==mn){
            if(smn[i]>=mn2)
                flag=0;
        }
        else{
            if(smn[i]>=mn)
                flag=0;
        }
        fout<<flag;
    }
    fout<<endl;


    return 0;
}