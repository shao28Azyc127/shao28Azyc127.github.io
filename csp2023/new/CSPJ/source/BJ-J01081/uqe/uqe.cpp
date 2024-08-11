#include <iostream>

using namespace std;

int T,M;
int a,b,c;
int gcd(int aa,int bb)
{

    if(bb==0)return aa;
    return gcd(bb,aa%bb);
}






int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);

    cin>>T>>M;
int z;
    for(int i=1;i<=T;i++)
    {

        cin>>a>>b>>c;
        int dlt=b*b-4*a*c;
        if(dlt<0){
            cout<<"NO"<<endl;
            continue;
        }

        if(b==0&&c==0)
        {
            cout<<"0"<<endl;

            continue;




        }
        
        if(dlt==0)
        {
            if(b==0)cout<<"0";
            if(-1*b*a<=0)//-b 2a butonghao
            z=gcd(2*a,-1*b);
            cout<<z<<endl;
            cout<<"-"<<(b/z)<<"/"<<(a/z)<<endl;


        }





    }










    return 0;
}
