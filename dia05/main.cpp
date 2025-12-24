#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

// Nodo del árbol binario. Cada nodo guarda un intervalo [l, r].
struct Node {
    long long l, r;
    Node* left;
    Node* right;

    Node(long long L, long long R) : l(L), r(R), left(nullptr), right(nullptr) {}
};

// Árbol binario de búsqueda para almacenar intervalos sin usar map/set.
class IntervalBST {
public:
    IntervalBST() : root(nullptr) {}
    ~IntervalBST() { freeTree(root); }

    void insert(long long l, long long r) {
        root = insertRec(root, l, r);
    }

    // Devuelve los intervalos ordenados por su extremo izquierdo.
    void inorder(vector<pair<long long,long long>>& out) const {
        out.clear();
        inorderRec(root, out);
    }

private:
    Node* root;

    static Node* insertRec(Node* cur, long long l, long long r) {
        if (!cur) return new Node(l, r);
        if (l < cur->l) cur->left = insertRec(cur->left, l, r);
        else cur->right = insertRec(cur->right, l, r);
        return cur;
    }

    static void inorderRec(Node* cur, vector<pair<long long,long long>>& out) {
        if (!cur) return;
        inorderRec(cur->left, out);
        out.push_back({cur->l, cur->r});
        inorderRec(cur->right, out);
    }

    static void freeTree(Node* cur) {
        if (!cur) return;
        freeTree(cur->left);
        freeTree(cur->right);
        delete cur;
    }
};

// Lee un rango con formato "a-b".
static bool parseRangeLine(const string& line, long long& L, long long& R) {
    size_t dash = line.find('-');
    if (dash == string::npos) return false;
    try {
        L = stoll(line.substr(0, dash));
        R = stoll(line.substr(dash + 1));
    } catch (...) {
        return false;
    }
    return true;
}

// Fusiona intervalos ya ordenados por su extremo izquierdo.
static vector<pair<long long,long long>> mergeSortedIntervals(
    const vector<pair<long long,long long>>& sorted
) {
    vector<pair<long long,long long>> merged;

    for (auto [l, r] : sorted) {
        if (merged.empty() || l > merged.back().second + 1) {
            merged.push_back({l, r});
        } else {
            merged.back().second = max(merged.back().second, r);
        }
    }
    return merged;
}

// Comprueba si un ID está dentro de alguno de los intervalos fusionados.
static bool isFresh(const vector<pair<long long,long long>>& merged, long long x) {
    int lo = 0, hi = merged.size() - 1;
    int pos = -1;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;
        if (merged[mid].first <= x) {
            pos = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    if (pos < 0) return false;
    return merged[pos].first <= x && x <= merged[pos].second;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    IntervalBST bst;
    string line;
    bool readingRanges = true;
    vector<long long> ids;

    // Primero se leen los rangos, luego los IDs (separados por una línea en blanco).
    while (getline(cin, line)) {
        if (!line.empty() && line.back() == '\r') line.pop_back();

        if (readingRanges) {
            if (line.empty()) {
                readingRanges = false;
                continue;
            }
            long long L, R;
            if (parseRangeLine(line, L, R)) {
                bst.insert(L, R);
            }
        } else {
            if (line.empty()) continue;
            try {
                ids.push_back(stoll(line));
            } catch (...) {}
        }
    }

    // Obtenemos los intervalos ordenados.
    vector<pair<long long,long long>> sorted;
    bst.inorder(sorted);

    // Fusionamos intervalos que se solapan.
    vector<pair<long long,long long>> merged = mergeSortedIntervals(sorted);

    // Parte 1: contar cuántos IDs están dentro de los intervalos.
    long long freshCount = 0;
    for (long long x : ids) {
        if (isFresh(merged, x)) freshCount++;
    }

    cout << "parte 1: " << freshCount << "\n";
    return 0;
}
