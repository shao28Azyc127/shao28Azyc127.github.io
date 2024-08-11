#include <fstream>
using namespace std;
ifstream cin("apple.in");
ofstream cout("apple.out");
int n,zan,i,noi,lin;
int main()
{
    cin>>n;
    zan=n;
    while(zan!=0)
    {
        lin=0;
        i++;
        if(zan%3==0)
        {
            lin=(zan/3);
            zan-=lin;
        }
        else
        {
            if(zan%3==1)
            {
                if(noi==0)
                    noi=i;
                lin=(zan/3)+1;
                zan-=lin;
            }
            else
            {
                if(zan%3==2)
                {
                    lin=(zan/3)+1;
                    zan-=lin;
                }
            }
        }
    }
    cout<<i<<" "<<noi;
    return 0;
}
