#include <iostream>
#include <unordered_map>
#include <vector>
#include <string>
#include <sstream>
#include <array>
#include <functional>

using namespace std;

using ll = long long;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    unordered_map<string, vector<string>> g;
    string linea;

    // leer grafo
    while (getline(cin, linea)) {
        if (linea.empty()) continue;

        size_t c = linea.find(':');
        if (c == string::npos) continue;

        string u = linea.substr(0, c);
        string rest = linea.substr(c + 1);

        stringstream ss(rest);
        string v;
        while (ss >> v) {
            g[u].push_back(v);
        }
    }

    // parte 1
    // dp[u] = numero de caminos desde u hasta out
    unordered_map<string, ll> dp1;

    function<ll(const string&)> dfs1 = [&](const string& u) -> ll {
        if (u == "out") return 1;
        if (dp1.count(u)) return dp1[u];

        ll total = 0;
        for (const string& v : g[u]) {
            total += dfs1(v);
        }
        dp1[u] = total;
        return total;
    };

    ll res_parte1 = dfs1("you");

    cout << res_parte1 << "\n";
    return 0;
}

