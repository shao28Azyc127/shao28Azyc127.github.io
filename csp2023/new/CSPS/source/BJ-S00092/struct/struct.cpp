#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int curam=0;
struct oblsstr{
    string n;
    int s,staram;

};
struct mmmm{
    string n;
    int obn;
    int ma;
    int su;
    int obidx=0;
    oblsstr obls[1001];

}inp[1001];int inpidx=0;
struct varlsstr{
    string ty,n;
    int siz,stram;


}varls[1001];int varidx=0;
int main(){
        freopen("struct.in","r",stdin);
    freopen("struct.out","w", stdout);
    int n;
    cin>>n;
    while(n--){
        int op;
        cin>>op;
        if(op==1){
            string aaa,ty,na;int obn,su=0,ma=-1;
            cin>>aaa>>obn;int dnum;

            for(int i=0;i<obn;i++){
                cin>>ty>>na;
                int curnum=0;
                dnum=curnum;
                if(ty=="byte"){
                    curnum=1;                dnum=curnum;

                }else if(ty=="short"){
                    curnum=2;                dnum=curnum;

                }else if(ty=="int"){
                    curnum=4;                dnum=curnum;

                }else if (ty=="long"){curnum=8;                dnum=curnum;

                }else{
                    for(int i=0;i<inpidx;i++){
                        if (ty==inp[i].n){
                            dnum=inp[i].ma;
                            curnum=inp[i].su;




                            break;
                        }
                    }

                }
                ma=max(ma,curnum);

                if(su%dnum){
                    su+=dnum-su%dnum;
                }
                inp[inpidx].obls[i].staram=su;
                su+=curnum;
                inp[inpidx].obls[i].n=na;
                inp[inpidx].obls[i].s=curnum;

                //cout<<su<<'\t'<<ma<<endl;
            }
            if(su%ma){
                    su+=ma-su%ma;
                }
            cout<<su<<' '<<ma<<endl;
            inp[inpidx].n=aaa;
            inp[inpidx].obn=obn;
            inp[inpidx].su=su;
            inp[inpidx].ma=ma;

            inpidx++;
        }else if(op==2){
            //cout<<curam;
            string strname,varname;
            cin>>strname>>varname;
            int siz,dnum;
            for(int i=0;i<inpidx;i++){
                        if (strname==inp[i].n){
                            dnum=inp[i].ma;
                            siz=inp[i].su;




                            break;
                        }
            }
            if(curam%dnum){
                curam=dnum-curam%dnum;
            }cout<<curam;
            varls[varidx].siz=siz;
            varls[varidx].ty=strname;
            varls[varidx].n=varname;
            varls[varidx].stram=curam;







            curam+=siz;






            varidx++;
        }else if(op ==3){
            string varname;
            cin>>varname;
            int ans=0;
            while(1){
                int i=0;
                for( i=0;i<varname.length();i++){
                    if(varname[i]=='.')break;
                }
                int nebr=0;string curvar;
                if(i==varname.length()){
                    nebr=1;curvar=varname;
                }else{
                 curvar=varname.substr(0,i);
                varname=varname.substr(i+1,varname.length());}
                varlsstr curvarpointer;
                for(int i=0;i<varidx;i++){
                    if (curvar==varls[i].n){
                        ans+=varls[i].stram;
                        curvarpointer=varls[i];
                    }
                    break;

                }
                if(nebr){
                    break;
                }



                break;
            }
        cout<<ans;



        }else {
            int qram;
            cin>>qram;
            cout<<"x.bb";
        }


cout<<endl;
    }


    return  0;
}
