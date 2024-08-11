#include<iostream>
using namespace std;
struct cont
{
    string name;
    int l,r;
};
struct struc
{
    vector <cont> v;
    long long siz;
};
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int M;
    cin>>M;
    while(M--)
    {
        int op;
        cin>>op;
        if(op==1)
        {
            string s;
            int k;
            cin>>s>>k;
            for(int i=0;i<k;i++)
            {
                string t,n;
                cin>>t>>n;
            }
        }
        if(op==2)
        {

        }
        if(op==3)
        {

        }
        if(op==4)
        {

        }
    }
    return 0;
}