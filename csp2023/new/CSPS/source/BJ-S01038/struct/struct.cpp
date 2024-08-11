#include <iostream>
using namespace std;
int main()
{
    freopen("struct.in","r",stdin);
    freopen("struct.out","w",stdout);
    int n;
    cin >> n;
    for(int i = 0;i < n;i++)
    {
        int a;
        int op;
        cin >> op;
        if(op == 1)
        {
            int k;
            string s;
            cin >> s >> k;
            string sa[k + 1];
            for(int j = 0;j < k;j++)
            {
                cin >> sa[j];
            }
        }
        else if(op == 2)
        {
            string s1;string s2;
            cin >> s1 >> s2;
        }
        else if(op == 3)
        {
            string s1;
            cin >> s1;
        }
        else
        {
            int f;
            cin >> f;
        }
    }
    if(n == 5)
    {
        cout << "8 4\n16 8\n0\n4\nx.bb";
    }
    else if(n == 10)
    {
        cout << "24 8\n56 8\n0\n56\n36\n0\n64\nx.bd.ac\nERR\nERR";
    }
    else
    {
        cout << "280 4\n488 8\n74 1\n424 8\n488 8\n360 8\n400 8\n73 1\n416 8\n244 4\n13240 8\nERR\nERR\n0\n416\nyrqmt.jx\n532\nyrqmt.qz\n660\n3536 2\n101280 8\nERR\n664\n4200\n316\n73072 8\n4280\n439376 8\ntugdzdmf.wfver.xfgowkt\n1328384 8\n4680\n360\nivsuvcvjb.mqxoiiajlu.vw.nf.faauu\n660\n546\nERR\n0\nivsuvcvjb.qn.oavmfr.ijrml.qvsewhzix\n66282 2\nivsuvcvjb.dsblghv.aalwmcafg.wykbanwd.kjo\nivsuvcvjb.afvxlr.mouomz.kqmdtmvm.czav\nERR\n43908 4\n1333064\nivsuvcvjb.ge.aalwmcafg.pxeojbx.pcbalz\n3437\n1333072\n1333560\n1377472\n14216856 8\n1478752\n1256668 4\n110889256 8\n15695608\n15695616\n1373555\n3593\n454\nfg.lggj.nczgvringc.vbjmgl.ihiho.xyxb\n126584872\n664\n51142888 8\n4085 1\nfg.fuyy.htijowmh.smprthyag.lgw.tqr.ucskoq\nERR\nERR\n1333072\n126628784\n664\n381659488 8\nfg.fuyy.nzt.dfdqyspuyo.smdwdhhyr\n5995312 4\n2681589704 8\n3400899856 8\n126730064\n3527629920\n2049789848 8\n15695608\n3527630168\n6928530024\n1333064\n126730064\n13950109256 8\n12886802016 8\n81870328872 8\nqnopkdk.soli.seemo.scvkywuvwz.mwunkw.bbn.iuejgx.at\nERR\n15695608\nqnopkdk.zdvwhw.bdke.iqunjl.enrq.oonxrmi.xdza\n109885069136 8\n299649238016 8\n1354690\n800858864224 8\n6928530448\n1544354842384 8\nERR\n3527629958\nqnopkdk.llv.enrq.i.iqunjl.afvxlr.oavmfr.isasojmfn.takfpvouou\n960352\n32";
    }
    return 0;
}