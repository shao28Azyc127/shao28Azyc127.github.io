#include<iostream>
using namespace std;
int x[100001],y[100001],cx[100001],cy[100001];
int ff[10000][10000];
int ffh[100000000],ffh2[100000000];

int gff(int x,int y,int m){
    if(x<0||y<0)return 0;
    if (m)return ffh[y];
    return ffh2[y];
}

bool x1gy1;
bool legit(int xpl, int ypl){
    if(x1gy1)return cx[xpl]>cy[ypl];
    else return cx[xpl]<cy[ypl];




}
int main(){
    freopen("expand.in","r",stdin);
    //
    freopen("expand.out","w",stdout);
    int c, n, m, q;
    cin>>c>> n>> m>> q;
    for(int i=0;i<n;i++){
        cin>>x[i];
    }for(int i=0;i<m;i++){
        cin>>y[i];
    }
    q++;bool f1=1;
    while(q--){
        for(int i=0;i<n;i++){
            cx[i]=x[i];
        }for(int i=0;i<m;i++){
            cy[i]=y[i];
        }
        int cxn=0,cyn=0;
        if (f1){
            f1=0;
        }else
            cin>>cxn>>cyn;
        int place,val;
        while(cxn--){
            cin>>place>>val;
            place--;
            cx[place]=val;
        }while(cyn--){
            cin>>place>>val;
            place--;
            cy[place]=val;
        }
        if(cx[0]==cy[0]||cx[n-1]==cy[m-1]){
            cout<<0;
            continue;
        }int idx=0,idy=0;
        //kaishishuangzhizhenzoule
        ffh2[0]=1;
        x1gy1=cx[0]>cy[0];
        for(idx=0;idx<n;idx++){
            for(idy=0;idy<m;idy++){
                if(idx==0&&idy==0)continue;
                ffh2[idy]=0;
                if(gff(idx-1,idy,1)||gff(idx,idy-1,0)){
                    if(legit(idx,idy)){
                        ffh2[idy]=1;
                    }
                }
                //cout<<ff[idx][idy];

                for(int i=0;i<m;i++){
                    ffh[i]=ffh2[i];
                }
            }
           // cout<<endl;
        }
        cout<<ffh2[m-1];



    }






    return 0;
}

