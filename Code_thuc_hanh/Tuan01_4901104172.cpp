#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;

struct Graph {
    int soDinh;
    int a[MAX][MAX];
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

bool maTranHopLe(Graph &g) {
    for (int i = 0; i < g.soDinh; i++)
        if (g.a[i][i] != 0) 
            return false;
    return true;
}

bool doThiVoHuong(Graph &g) {
    for (int i = 0; i < g.soDinh; i++)
        for (int j = i + 1; j < g.soDinh; j++)  
            if (g.a[i][j] != g.a[j][i])
                return false;
    return true;
}

int soCanh(Graph &g) {
    bool voHuong = doThiVoHuong(g);
    int count = 0;

    for (int i = 0; i < g.soDinh; i++)
        for (int j = 0; j < g.soDinh; j++)
            if (g.a[i][j]) count++;
            
    return voHuong ? count / 2 : count;
}

void xuatBac(Graph &g) {
    bool voHuong = doThiVoHuong(g);

    for (int i = 0; i < g.soDinh; i++) {
        int bac = 0;

        if (voHuong) {
            for (int j = 0; j < g.soDinh; j++)
                if (g.a[i][j])
                    bac++;

        } else {
            int bacTrong = 0, bacNgoai = 0;
            for (int j = 0; j < g.soDinh; j++) {
                if (g.a[i][j]) bacNgoai++;
                if (g.a[j][i]) bacTrong++;
            }
            bac = bacTrong + bacNgoai;
        }
        cout << "Dinh " << i + 1 << " co bac la " << bac << endl;
    }
}

void timDinh(Graph &g) {
    bool voHuong = doThiVoHuong(g);
    int maxBac = -1, minBac = INT_MAX;
    vector<int> bacMax, bacMin, bacChan, bacLe;

    for (int i = 0; i < g.soDinh; i++) {
        int bac = 0;

        if (voHuong) {
            for (int j = 0; j < g.soDinh; j++)
                if (g.a[i][j])
                    bac++;

        } else {
            int bacTrong = 0, bacNgoai = 0;

            for (int j = 0; j < g.soDinh; j++) {
                if (g.a[i][j]) bacNgoai++;
                if (g.a[j][i]) bacTrong++;
            }

            bac = bacTrong + bacNgoai;
        }

        if (bac > maxBac) {
            maxBac = bac;
            bacMax.clear();
            bacMax.push_back(i + 1);
        } else if (bac == maxBac) 
            bacMax.push_back(i + 1);

        if (bac < minBac) {
            minBac = bac;
            bacMin.clear();
            bacMin.push_back(i + 1);
        } else if (bac == minBac) 
            bacMin.push_back(i + 1);

        if (bac % 2 == 0)
            bacChan.push_back(i + 1);
        else
            bacLe.push_back(i + 1);
    }

    cout << "Dinh co bac lon nhat: ";
    for (int i : bacMax) 
        cout << i << " ";
    cout << endl;

    cout << "Dinh co bac nho nhat: ";
    for (int i : bacMin) 
        cout << i << " ";
    cout << endl;

    cout << "Dinh bac chan: ";
    for (int i : bacChan) 
        cout << i << " ";
    cout << endl;

    cout << "Dinh bac le: ";
    for (int i : bacLe) 
        cout << i << " ";
    cout << endl;
}

void dinhCoLapTreo(Graph &g) {
    bool voHuong = doThiVoHuong(g);
    vector<int> dinhCoLap, dinhTreo;

    for (int i = 0; i < g.soDinh; i++) {
        int bac = 0;

        if (voHuong) {
            for (int j = 0; j < g.soDinh; j++)
                if (g.a[i][j])
                    bac++;

        } else {
            int bacTrong = 0, bacNgoai = 0;

            for (int j = 0; j < g.soDinh; j++) {
                if (g.a[i][j]) bacNgoai++;
                if (g.a[j][i]) bacTrong++;
            }

            bac = bacTrong + bacNgoai;
        }

        if (bac == 0) 
            dinhCoLap.push_back(i + 1);
        else if (bac == 1) 
            dinhTreo.push_back(i + 1);
    }

    cout << "Dinh co lap: ";
    for (int i : dinhCoLap)
        cout << i << ' ';
    cout << endl;

    cout << "Dinh treo: ";
    for (int i : dinhTreo)
        cout << i << ' ';
    cout << endl;

    cout << endl;
}

int main() {
    Graph g;
    docDoThi("dothi.txt", g);
    inDoThi(g);

    if (!maTranHopLe(g)) {
        cout << "Ma tran khong hop le!" << endl;
        return 0;
    }

    cout << "Do thi " << (doThiVoHuong(g) ? "vo huong" : "co huong") << endl;
    cout << "So canh: " << soCanh(g) << endl;

    xuatBac(g);
    timDinh(g);
    dinhCoLapTreo(g);

    return 0;
}