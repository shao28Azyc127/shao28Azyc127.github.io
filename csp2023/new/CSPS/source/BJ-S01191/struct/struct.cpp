#include <bits/stdc++.h>
using namespace std;

struct tps
{
    bool isst;
    vector<pair<string,pair<int,int> > > tp;//1:byte,2:short,4:int,8:long
    int duiqi;
};

int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
/*
    map<string,int> totp;
    map<int,string> tonm;
    map<string,int> a;

    totp["byte"]=1;
    totp["short"]=2;
    totp["int"]=4;
    totp["long"]=8;
    int n;
    scanf("%d",&n);
    int op;
    string cache,c1,c2;
    int addr=0;
    while(n--)
    {
        scanf("%d",&op);
        switch(op)
        {
            case 2:
            {
                cin>>c1>>c2;
                tonm[addr]=c1;
                a[c2]=totp[c1];
                cout<<addr<<endl;
                addr+=totp[c1];
                break;
            }

            case 3:
            {
                cin>>cache;
                cout<<a[cache]<<endl;

                break;
            }
        }
    }*/
    srand(int(time(0)));

    int n;
    scanf("%d",&n);
    int op;
    string cache,c1,c2;
    map<string,pair<tps,int> > a;
    map<string,int> totp;
    map<int,string> tonm;
    totp["byte"]=1;
    totp["short"]=2;
    totp["int"]=4;
    totp["long"]=8;
    int addr=0,cadr=0;
    while(n--)
    {
        scanf("%d",&op);
        switch(op)
        {
            case 1:
            {
                cin>>cache;
                int k;
                scanf("%d",&k);
                a[cache].first.isst=true;
                a[cache].second=-1;
                while(k--)
                {
                    cin>>c1>>c2;
                    a[cache].first.tp.push_back(make_pair(c2,make_pair(totp[c1],0)));
                    a[cache].first.duiqi=max(a[cache].first.duiqi,totp[c1]);
                }

                k=0;
                for(int i=0;i<a[cache].first.tp.size();i++)
                {
                    cadr+=a[cache].first.tp[i].second.first;
                    if(cadr>a[cache].first.duiqi)
                    {
                        k+=a[cache].first.duiqi;
                        cadr=a[cache].first.tp[i].second.first;
                    }
                    a[cache].first.tp[i].second.second=k+cadr-a[cache].first.tp[i].second.first;
                }
                k+=a[cache].first.duiqi;
                totp[cache]=k;

                cout<<k<<" "<<a[cache].first.duiqi<<endl;

                break;
            }

            case 2:
            {
                cin>>c1>>c2;
                a[c2].first.tp.push_back(make_pair(c2,make_pair(totp[c1],0)));
                a[c2].second=addr;
                printf("%d\n",addr);
                tonm[addr/8]=c2;
                addr+=totp[c1];

                break;
            }

            case 3:
            {
                cin>>cache;

                string cc;
                for(int i=0;i<cache.length();i++)
                {
                    cc+=cache[i];
                    if(cache[i]=='.')
                    {
                        cc.clear();
                    }
                }
                printf("%d\n",a[cc].second);

                break;
            }

            case 4:
            {
                int k;
                cin>>k;

                if(tonm[k/8]!="")
                    cout<<tonm[k/8]<<endl;
                else
                    cout<<"ERR"<<endl;

                break;
            }
        }
    }

    return 0;
}
