
#include<bits/stdc++.h>
using namespace std;
int t,m;
int solve(int a,int b){
    if(a%b==0){
        return b;
    }
    solve(b, a%b);
}
pair<int, int> get(int a){
    int res=1;
    for(int i=1;i*i<=a;i++){
        if(a%(i*i)==0){
            res=i;
        }
    }
    return {res, a/res/res};
}
int main(){
    freopen("uqe.in", "r", stdin);
    freopen("uqe.out", "w", stdout);
    cin>>t>>m;
    while(t--){
        int a,b,c;
        cin>>a>>b>>c;
        int delta=b*b-4*a*c;
        if(delta<0){
            cout<<"NO"<<endl;
        }
        else if(delta==0){
            int up=0-b;
            int down=2*a;
            if(up==0){
                cout<<0<<endl;
            }
            else{
                int di=solve(max(up, down), min(up, down));
                if(up%down==0){
                    cout<<up/down<<endl;
                }
                else{
                    up/=di;
                    down/=di;
                    if(up*down>0){
                        cout<<abs(up)<<"/"<<abs(down)<<endl;
                    }
                    else{
                        cout<<"-"<<abs(up)<<"/"<<abs(down)<<endl;
                    }
                }
            }
        }
        else{
            int up=0-b, down=2*a;
            int sq_out, sq_in;
            pair<int , int> res=get(delta);
            sq_out=res.first;
            sq_in=res.second;
            if(sq_in.second==1){
                up+=sq_out;
                if(up==0){
                    cout<<0<<endl;
                }
                else{
                    int di=solve(max(up, down), min(up, down));
                    if(up%down==0){
                        cout<<up/down<<endl;
                    }
                    else{
                        up/=di;
                        down/=di;
                        if(up*down>0){
                            cout<<abs(up)<<"/"<<abs(down)<<endl;
                        }
                        else{
                            cout<<"-"<<abs(up)<<"/"<<abs(down)<<endl;
                        }
                    }
                }
            }
            else{
                int flag=1;
                if(up==0){
                    flag=0;
                }
                else{
                    int di=solve(max(up, down), min(up, down));
                    if(up%down==0){
                        cout<<up/down<<"+";
                    }
                    else{
                        up/=di;
                        down/=di;
                        if(up*down>0){
                            cout<<abs(up)<<"/"<<abs(down)<<"+"<<endl;
                        }
                        else{
                            cout<<"-"<<abs(up)<<"/"<<abs(down)<<"+"<<endl;
                        }
                    }
                    
                    int dis=solve(max(sq_in, down), min(sq_in, down));
                }
            }
        }
    }
    return 0;
}
