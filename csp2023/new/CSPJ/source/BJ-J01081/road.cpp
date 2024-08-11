#include <iostream>

using namespace std;
int v[100005];
int a[100005];
int main()
{
    freopen("road.in","r",stdin);
    freopen("road.out","w",stdout);
    int n,d;
    cin>>n>>d;
    int zzz=0;
    v[1]=0;
    for(int i=2;i<=n;i++)
    {
        cin>>zzz;
        v[i]=v[i-1]+zzz;
    }
    int minn=100005;//zuidiyoujia
    int last=1;//shang yi ci zai na li mai you
    int y=0;//目前可以行使到的距离
    int cost=0;
    for(int i=1;i<=n;i++)
    {

        cin>>a[i];
        if(i==1)
            minn=a[1];
        if(a[i]<minn&&i!=1)
        {
            //if(y*d>=(v[i]-v[last]))
            minn=a[i];
            if(v[i]-y<0)continue;
            if((v[i]-y)%d==0)//last=y?
            {
                cost+=(v[i]-y)/d*a[last];
                //cout<<(v[i]-y)/d<<" "<<(v[i]-y)/d*a[last]<<" "<<cost<<endl;
                //y+=(v[i]-);
                y=v[i];
                last=i;
            }


            else
                {

                    cost+=  (((v[i]-y)/d)+1)  *  a[last];//remember tiao shi
                    //cout<<((v[i]-y)/d)+1<<" "<<(((v[i]-y)/d))*a[last]<<" "<<cost<<endl;
                    //y+=(((v[i]-y)/d))*d;
                    y=y+d*(((v[i]-y)/d)+1);
                    last=i;
                }


        }
    }

    cout<<cost;

/*
5 4 10 10 10 10 9 8 9 6 5





*/


    return 0;
}
