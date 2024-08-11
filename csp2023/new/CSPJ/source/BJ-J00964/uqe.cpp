
#include <iostream>
#include <cstdio>

using namespace std;

int main()
{
    freopen("uqe.in","r",stdin);
    freopen("uqe.out","w",stdout);
    int T,M;
    cin>>T>>M;
    int Tlist[5001][4];
    for (int i=1;i<=T;i++)
    {
        cin>>Tlist[i][1]>>Tlist[i][2]>>Tlist[i][3];
    }
    for (int i=1;i<=T;i++)
    {
        if (Tlist[i][2]*Tlist[i][2]-4*Tlist[i][1]*Tlist[i][3]<0)
        {
            cout<<"NO"<<endl;
        }
        else if (Tlist[i][2]*Tlist[i][2]-4*Tlist[i][1]*Tlist[i][3]==0)
        {
            if (Tlist[i][2] == 0)
            {
                cout<<0<<endl;
            }
            else
            {
                if (Tlist[i][2]%(2*Tlist[i][1])==0)
                {
                    cout<<-1*Tlist[i][2]/2/Tlist[i][1];
                }
                else
                {
                    cout<<"-"<<Tlist[i][2]<<"/"<<2*Tlist[i][1]<<endl;
                }
            }
        }
        else
        {
            if (Tlist[i][2] == 0)
            {
                cout<<"sqrt("<<Tlist[i][2]*Tlist[i][2]-4*Tlist[i][1]*Tlist[i][3]<<")/"<<2*Tlist[i][1]<<endl;
            }
            else
            {
                if (Tlist[i][2]%(2*Tlist[i][1])==0)
                {
                    cout<<-1*Tlist[i][2]/2/Tlist[i][1]<<"+"<<"sqrt("<<Tlist[i][2]*Tlist[i][2]-4*Tlist[i][1]*Tlist[i][3]<<")/"<<2*Tlist[i][1]<<endl;
                }
                else
                {
                    cout<<"-"<<Tlist[i][2]<<"/"<<2*Tlist[i][1]<<"+"<<"sqrt("<<Tlist[i][2]*Tlist[i][2]-4*Tlist[i][1]*Tlist[i][3]<<")/"<<2*Tlist[i][1]<<endl;
                }
            }
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
