#include<bits/stdc++.h>
using namespace std;
const int MAX = 100;
struct GRAPH
{
    int sodinh;//so dinh do thi
    int a[MAX][MAX];//ma tran ke
};

void readGRAPH (string fn, GRAPH &g)
{
    ifstream f;
    f.open(fn);
    if(f.is_open())
    {
        f>>g.sodinh;
        for(int i = 0;i < g.sodinh; i++)
            for(int j = 0;j < g.sodinh; j++)
                f>>g.a[i][j];
            f.close();
    }
    else
    cout<<"Khong mo duoc file!!!";
}
void printGRAPH(GRAPH g)
{
    cout <<"So dinh la: " << g.sodinh<<"\n";
    for(int i = 0;i < g.sodinh; i++)
    {
        for(int j = 0;j < g.sodinh; j++)
                cout << g.a[i][j]<<" ";
            cout << endl;
    }

}
int main()
{
    GRAPH h;
    readGRAPH("dothi.txt",h);
    printGRAPH(h);
    return 0;
}
