#include<bits/stdc++.h>
using namespace std;
string s;
string ss;
int n;
int flag=0;

struct ab{
    int numa;
    int numb;
};

bool sub(int l,int r){
    char w='1';
    int cont=1;
    for(int i=l+1;i<=r;i++){
        if(s[i]=='1'){
            cont++;
        }else if(s[i-1]!='1')cont=1;

        if(s[i]!=w && s[i]==s[i-cont]){
            w=s[i];
            s[i]='1';
            s[i-cont]='1';
            if(i-cont-2>=l) cont+=2;
            else cont++;
        }else if(s[i]==w){
            s[i]=='1';
            cont++;
        }else if(s[i]!=w && w!='1'){
            return 1;
        }
    }
    if(cont>r-l+1) flag=1;
    return 0;
}

void if_(int l,int r){
    while(1) if(sub(l,r)==0) break;
    return ;
}

int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);

    int mod=0;
    cin>>n;
    cin>>ss;
    int ans=0;
    s=ss;
    for(int i=0;i<n;i++){
        if(s[i]!='a' || s[i]!='b'){
            mod=1;
        }
    }
    for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            flag=0;
            s=ss;
            if_(j,i);
            if(flag==1){
                flag=0;
                ans++;
            }
        }
    }
    cout<<ans;
}
