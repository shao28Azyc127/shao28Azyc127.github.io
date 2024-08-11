#include<iostream>
#include<ctime>
#include<cstdlib>
using namespace std;
int l[1000010]={0};
int r[1000010]={0};
int main()
{
    ios::sync_with_stdio(false);
    freopen("apple.in","r",stdin);
    freopen("apple.out","w",stdout);
    int n;
    cin>>n;
    for(int j1=1;j1<=n;j1++)
    {
        r[j1]=j1+1;
        l[j1]=j1-1;
    }
    int ddd=1;
    int ubt=1;
    int ooo=0;
    int you=0;
    int tianshu=1;
    l[r[ooo]]=l[ooo];
    r[l[ooo]]=r[ooo];
    if(ddd==n)
    {
        you=tianshu;
    }
//    cout<<1<<" ";
//    int abc=0;
    while(true)
    {
//        abc++;
        ooo=r[r[r[ddd]]];
//        cout<<ooo<<" ";
//        cout<<"ddd="<<ddd<<"r[ddd]"<<r[ddd]<<"r[r[ddd]]="<<r[r[ddd]]<<"r[r[r[ddd]]]="<<r[r[r[ddd]]]<<endl;
//        cout<<"ooo="<<ooo<<endl;
        if(ooo>n || ooo==0)
        {
//            cout<<endl;
            ddd=r[ubt];
//            cout<<"ddd="<<ddd<<endl;
            if(ddd>n)
            {
                break;
            }
//            cout<<ddd<<" ";
            tianshu++;
            if(ddd==n)
            {
                you=tianshu;
            }
            l[r[ddd]]=l[ddd];
            r[l[ddd]]=r[ddd];
            ubt=ddd;
        }
        else
        {
            if(ooo==n)
            {
                you=tianshu;
            }
            l[r[ooo]]=l[ooo];
            r[l[ooo]]=r[ooo];
            ddd=ooo;
        }
    }
//    lunshu--;
    cout<<tianshu<<" "<<you;
    return 0;
}
