/*
#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin>>s;
    int cnt=0;
    for(int tou=0;tou<s.size()-1;tou++){
        for(int wei=tou+1;wei<s.size();wei++){
                string kc=s.substr(tou,wei);
            for(int h=1;h<=1000;h++){
                for(int i=tou;i<wei-1;i++){
                    if(kc[i]==kc[i+1])kc.erase(i,i+2);
                }
                if(kc.empty()==1)   cnt++;
            }

        }
    }
    cout<<cnt;
    return 0;

}
*/
#include <bits/stdc++.h>
using namespace std;

bool check(string s){
    for(int c=1;c<s.size();c++){
        string s1=s.substr(0,c+1);
        string s2=s.substr(c,s.size());
        if(s1.size()==2)    return s1[1]==s1[2];
        if(s2.size()==2)    return s2[1]==s2[2];
        bool ans=0;
        ans|=(check(s1)&&check(s2));
        return ans;
    }
}
int main(){
    freopen("game.in","r",stdin);
    freopen("game.out","w",stdout);
    int f;
    cin>>f;
    string x;
    cin>>x;
    int cnt=0;
    for(int tou=0;tou<x.size()-1;tou++){
        for(int wei=tou+1;wei<x.size();wei++){
            string kc=x.substr(tou,wei);
            if(check(kc))   cnt++;
        }
    }
    cout<<cnt;
    return 0;
}

