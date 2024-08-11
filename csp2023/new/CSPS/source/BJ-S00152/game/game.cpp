#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
const int N=2*1e6;
string a;
int qi[N],t[30];
int c2i(char ch){
    int ii=int(ch-'a');
    return ii;
}
int ans;
int on2[N];
int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int n;
    cin >>n;
    cin >>a;
    bool ab=1;
    for(int i=0;i<n;i++)
    {
        qi[i]=c2i(a[i]);

        if(qi[i]!=0&&qi[i]!=1){
            ab=0;
        }
    }
    if(ab){
            on2[0]=qi[0];
        for(int i=1;i<n;i++){
            on2[i]=qi[i]+on2[i-1];
            if(on2[i]%2==0&& i&1){
                ans++;
            }
        }
        int l=0,r=2;
        while(l<n-2){
            if((on2[r]-on2[l])%2==0 ){
                ans++;
            }
            if(r+2<n){r+=2;}
            else{l++;r=l+2;}
        }

    }

    int l=0,r=1;
    t[qi[l]]++;
    t[qi[r]]++;
    while(l<n-1&&ab==0){
        bool b=1;

        for(int i=0;i<26;i++)
        {
            if(t[i]%2!=0)
            {
                b=0;
                break;
            }
        }
        if(b){
            ans++;
        }

        if(r+2<n)
        {
            t[qi[r+1]]++;
            t[qi[r+2]]++;
            r+=2;
        }
        else{
            l++;
            r=l+1;
            for(int i=0;i<26;i++){t[i]=0;}
            t[qi[l]]++;
            t[qi[r]]++;
        }
    }

    cout <<ans;
    fclose(stdin);
    fclose(stdout);
    return 0;
}
