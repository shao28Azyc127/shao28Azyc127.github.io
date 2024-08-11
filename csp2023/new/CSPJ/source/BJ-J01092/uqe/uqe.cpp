#include<bits/stdc++.h>
using namespace std;
int t,m;
int a,b,c;
int drt;
bool sm[1000000005];
int s[10000],cnts=1;

void zpfs(){
    sm[0]=1;
    for(int i=1;i<=1000;i++){
        sm[i*i]=1;
        s[cnts]=i*i;
        cnts++;
    }
}
bool jc(){
    drt=b*b-4*a*c;
    if(drt<0) return false;
    return true;
}
int gcd(int x,int y){
    if(y==0) return x;
    return gcd(y,x%y);
}
void clq(){
    if(a>0){
        int lg;
        if(b>0){
            cout<<'-';
            if(b%(a*2)==0){
                cout<<b/(2*a);
            }else{
                lg=gcd(b,2*a);
                cout<<b/lg<<'/'<<(2*a)/lg;
            }
        }
        if(b<0){
            if(-b%(a*2)==0){
                cout<<-b/(2*a);
            }else{
                lg=gcd(-b,2*a);
                cout<<-b/lg<<'/'<<(2*a)/lg;
            }
        }
    }
    if(a<0){
        int lg;
        if(b>0){
            if(b%(-a*2)==0){
                cout<<b/(-2*a);
            }else{
                lg=gcd(b,-2*a);
                cout<<b/lg<<'/'<<(-2*a)/lg;
            }
        }

        if(b<0){
            cout<<'-';
            if(b%(a*2)==0){
                cout<<b/(2*a);
            }else{
                lg=gcd(b,2*a);
                cout<<b/lg<<'/'<<(2*a)/lg;
            }
        }
    }
    if(b!=0&&drt!=0) cout<<'+';
    return;
}
void clh(){

    int ghs=drt,ghxs;
    for(int i=cnts-1;i>=1;i--){
        if(ghs%s[i]==0){
            ghxs=i;
            ghs/=s[i];
            break;
        }
    }
    if(a>0){
        int lg;
        lg=gcd(ghxs,2*a);
        if(ghxs%(2*a)==0){
            cout<<ghxs/(2*a)<<'*'<<"sqrt("<<ghs<<')';
        }else{
            if(ghxs/lg!=1) cout<<ghxs/lg<<'*';
            cout<<"sqrt("<<ghs<<')'<<'/'<<(2*a)/lg;
        }
    }
    if(a<0){
        int lg;
        lg=gcd(ghxs,-2*a);
        if(ghxs%(-2*a)==0){
            cout<<ghxs/(-2*a)<<'*'<<"sqrt("<<ghs<<')';
        }else{
            if(ghxs/lg!=1) cout<<ghxs/lg<<'*';
            cout<<"sqrt("<<ghs<<')'<<'/'<<(-2*a)/lg;
        }
    }

}
int main(){
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    zpfs();
    cin>>t>>m;
    while(t--){
        cin>>a>>b>>c;
        if(!jc()){
            cout<<"NO"<<endl;
            continue;
        }
        if(sm[drt]){
            if(a>0){
                int ls=-b+sqrt(drt);
                int lg=gcd(ls,2*a);
                if(ls<0){
                    cout<<'-';
                    ls=-ls,lg=-lg;
                }
                if(ls%(2*a)==0){
                    cout<<ls/(2*a)<<endl;
                }else{
                    cout<<ls/lg<<'/'<<(2*a)/lg<<endl;
                }
            }
            if(a<0){
                int ls=b+sqrt(drt);
                int lg=gcd(ls,-2*a);
                if(ls%(-2*a)==0){
                    cout<<ls/(-2*a)<<endl;
                }else{
                    cout<<ls/lg<<'/'<<(-2*a)/lg<<endl;
                }
            }
            continue;
        }
        clq();
        clh();
        cout<<endl;
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
