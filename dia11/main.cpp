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

    // parte 2
    unordered_map<string, array<ll, 4>> dp2;

    function<ll(const string&, int)> dfs2 = [&](const string& u, int mask) -> ll {
        if (u == "out") {
            return (mask == 3) ? 1LL : 0LL;
        }

        if (dp2[u][mask] != -1) return dp2[u][mask];

        ll total = 0;
        for (const string& v : g[u]) {
            int nmask = mask;
            if (v == "dac") nmask |= 1;
            if (v == "fft") nmask |= 2;
            total += dfs2(v, nmask);
        }

        dp2[u][mask] = total;
        return total;
    };

    // inicializar dp2 a -1
    for (auto& [u, _] : g) {
        dp2[u].fill(-1);
    }

    ll res_parte2 = dfs2("svr", 0);

    cout << res_parte1 << "\n" << res_parte2 << "\n";
    return 0;
}
