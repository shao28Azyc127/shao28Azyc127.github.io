//dthkxy ak ioi
#include<bits/stdc++.h>
#define int long long
using namespace std;

string a[1000005];
map <string,int> dqyq;
map <string,int> structsize;
map <string,vector <pair <string,string> > > structmember;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);

    int n; cin>>n;
    int now; now=0;

    structsize["byte"]=1;
    structsize["short"]=2;
    structsize["int"]=4;
    structsize["long"]=8;

    for(int i=0;i<1000005;i++){
        a[i]="ERR";
    }

    for(int i=1;i<=n;i++){
        int opt; cin>>opt;
        if(opt==1){ //全为基本类型
            string name; cin>>name;
            int x; cin>>x;

            string ty[105];
            string nm[105];
            int duiqi; duiqi=-1;
            for(int j=1;j<=x;j++){
                cin>>ty[j]>>nm[j];
                duiqi=max(duiqi,structsize[ty[j]]);
                structmember[name].push_back(make_pair(ty[j],nm[j]));
            }

            structsize[name]=x*duiqi;
            dqyq[name]=duiqi;
        }

        if(opt==2){
            string type; cin>>type;
            string name; cin>>name;

            if(type=="byte"){
                for(int i=1;i<=1;i++){
                    a[now]=name;
                    now++;
                }
            }
            else if(type=="short"){
                for(int i=1;i<=2;i++){
                    a[now]=name;
                    now++;
                }
            }
            else if(type=="int"){
                for(int i=1;i<=4;i++){
                    a[now]=name;
                    now++;
                }
            }
            else if(type=="long"){
                for(int i=1;i<=8;i++){
                    a[now]=name;
                    now++;
                }
            }
            else{
                //cout<<"*";
                for(int i=0;i<structmember[type].size();i++){
                    while(now%dqyq[type]){
                        now++;
                    }
                    //cout<<"now:"<<now<<endl;
                    string ins; ins=name+"."+structmember[type][i].second;
                    if(structmember[type][i].first=="byte"){
                        for(int i=1;i<=1;i++){
                            a[now]=ins;
                            now++;
                        }
                    }
                    else if(structmember[type][i].first=="short"){
                        for(int i=1;i<=2;i++){
                            a[now]=ins;
                            now++;
                        }
                    }
                    else if(structmember[type][i].first=="int"){
                        for(int i=1;i<=4;i++){
                            a[now]=ins;
                            now++;
                        }
                    }
                    else if(structmember[type][i].first=="long"){
                        for(int i=1;i<=8;i++){
                            a[now]=ins;
                            now++;
                        }
                    }
                }
            }
        }

        if(opt==3){
            string s; cin>>s;
            for(int i=0;i<=now;i++){
                if(a[i]==s){
                    cout<<i<<endl;
                    break;
                }
            }
        }

        if(opt==4){
            int addr; cin>>addr;
            cout<<a[addr]<<endl;
        }
    }
    /*
    for(int i=0;i<now;i++){
        cout<<a[i]<<" ";
    }
    */
    return 0;
}
