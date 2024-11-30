#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

const int MAX = 100;

struct GRAPH
{
	int sodinh;
	int a[MAX][MAX];
	int visited [MAX];
	int LuuVet [MAX];
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

void printGRAPH (GRAPH g)
{
cout<<"So dinh cua do thi: "<<g.sodinh<<endl;
	for(int i=0;i<g.sodinh;i++)
	{
		for(int j=0;j<g.sodinh;j++)
			cout<<setw(4)<<g.a[i][j];
		cout<<endl;
	}
}

void DFS(int s, GRAPH &g)
{
	//Đánh dấu đỉnh s đã duyệt
	g.visited[s] = 1;

	//Tìm xem từ đỉnh s có đỉnh i nào chưa duyệt và nối trực tiếp với s
	for(int i = 0; i < g.sodinh; i++)
		if(g.visited[i] == 0 && g.a[s][i] != 0)
		{
			g.LuuVet[i] = s; //Lưu trước đỉnh i là đỉnh s
			DFS(i, g);//gọi đệ quy tiến hành xét tiếp
		}
}
//Hàm tìm đường đi từ đỉnh s đến đỉnh f trong đồ thị g
void duyetDFS(int s, int f, GRAPH &g)
{
	//Khởi tạo giá trị ban đầu, tất cả các đỉnh chưa được duyệt và chưa lưu vết
	for(int i = 0; i < g.sodinh; i++)
	{
		g.visited[i] = 0;
		g.LuuVet[i] = -1;
	}
	//Gọi hàm DFS
	DFS(s, g);
	if(g.visited[f] == 1)
	{
		//In ket qua
		int j = f;
		while(j != s)
		{
			cout<<j<<"<---";
			j = g.LuuVet[j];
		}
		cout<<s;
		cout<<endl;
	}
	else
		cout<<"Khong co duong di tu dinh "<<s<<" den dinh "<<f;
	cout<<endl;
}

int main()
{
    GRAPH g;
    string filename= "matrix.txt";
    readGRAPH(filename, g);
    int s = 1;
    int f = 3;
    DFS (s, g);
    duyetDFS (s, f, g);
    return 0;
}
