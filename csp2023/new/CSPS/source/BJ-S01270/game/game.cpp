#include <bits/stdc++.h>

using namespace std;

int n;
string str;
long long sum=0;

bool hw(string a){
    string b;
    while(1){
        bool flag=0;
        for(int i=0;i<a.size()-2;i++){
            if(a[i]==a[i+1]){
                flag=1;
                if(a.size()==2)a="";
                else a=a.substr(0,i)+a.substr(i+2,a.size()-i-2);
            }
            if(a=="")return 1;
        }
        if(flag==0)return 0;
    }
    return 1;
}

int go(){
    for(int i=2;i<=n;i+=2){
        for(int j=0;j<=n-i;j++){
            string tmp=str.substr(j,i);//cout<<tmp<<endl;
            if(hw(tmp)){sum++;}
        }
    }
}


int main()
{
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    cin>>n>>str;

    go();

    cout<<sum;

    return 0;
}
