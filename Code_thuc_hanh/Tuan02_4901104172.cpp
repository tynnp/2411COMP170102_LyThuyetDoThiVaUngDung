#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

const int MAXN = 100;

struct Graph {
    int soDinh;
    int a[MAXN][MAXN];
    bool tham[MAXN];
    int luu[MAXN];
};

void docDoThi(string fn, Graph &g) {
    ifstream f;
    f.open(fn);

    if (f.is_open()) {
        f >> g.soDinh;
        
        for (int i = 0; i < g.soDinh; i++)
            for (int j = 0; j < g.soDinh; j++)
                f >> g.a[i][j];
        
        f.close();

    } else 
        cout << "Khong mo duoc file!";
}

void inDoThi(Graph &g) {
    cout << "So dinh cua do thi: " << g.soDinh << endl;

    for (int i = 0; i < g.soDinh; i++) {
        for (int j = 0; j < g.soDinh; j++)
            cout << setw(4) << g.a[i][j];
        cout << endl;
    }
}

void DFS(int s, Graph &g) {
    g.tham[s] = true;

    for (int i = 0; i < g.soDinh; i++) {
        if (!g.tham[i] && g.a[s][i] != 0) {
            g.luu[i] = s;
            DFS(i, g);
        }
    }
}

// Duyệt từ s đến t
void duyetDFS(int s, int t, Graph &g) {
    for (int i = 0; i < g.soDinh; i++) {
        g.tham[i] = false;
        g.luu[i] = -1;
    }

    DFS(s, g);

    if (g.tham[t]) {
        cout << "Duong di tu " << s << " den " << t <<": ";

        int j = t;
        while (j != s) {
            cout << j << "<---";
            j = g.luu[j];
        }

        cout << s << endl;

    } else 
        cout << "Khong co duong di tu dinh " << s << " den dinh " << t << endl;
}

// Duyệt từ s đến các đỉnh còn lại
void duyetDFS(int s, Graph &g) {
    for (int i = 0; i < g.soDinh; i++) {
        g.tham[i] = false;
        g.luu[i] = -1; 
    }

    DFS(s, g);
    cout << "Duong di tu dinh " << s << " den cac dinh con lai:" << endl;

    for (int t = 0; t < g.soDinh; t++) {
        if (t == s) 
            continue;

        if (g.tham[t]) { 
            cout << "Den dinh " << t << ": ";

            int j = t;
            while (j != s) {
                cout << j << " <--- ";
                j = g.luu[j];
            }

            cout << s << endl;

        } else 
            cout << "Khong co duong di den dinh " << t << endl;
    }
}

int main() {
    Graph g;
    docDoThi("matrix.txt", g);

    int s = 1;
    int t = 3;

    duyetDFS(s, t, g);
    duyetDFS(s, g);

    return 0;
}