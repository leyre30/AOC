#include <iostream>
#include <vector>
#include <string>
#include <queue>

using namespace std;

int main() { 
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // leer la rejilla
    vector<string> grid;
    string line;
    while (getline(cin, line)) {
        if (!line.empty() && (line.back() == '\r' || line.back() == '\n'))
            line.pop_back();
        if (!line.empty())
            grid.push_back(line);
    }

    int H = grid.size();
    if (H == 0) {
        cout << "0\n";
        return 0;
    }
    int W = grid[0].size();

    // buscar la S
    int sr = -1, sc = -1;
    for (int r = 0; r < H; ++r) {
        for (int c = 0; c < W; ++c) {
            if (grid[r][c] == 'S') {
                sr = r;
                sc = c;
            }
        }
    }

    if (sr == -1) {
        cout << "0\n";
        return 0;
    }

    long long splitsPart1 = 0;

    queue<pair<int,int>> q;
    vector<vector<bool>> visited(H, vector<bool>(W, false));

    if (sr + 1 < H) {
        q.push({sr + 1, sc});
    }

    while (!q.empty()) {
        auto [r, c] = q.front();
        q.pop();

        while (true) {
            if (r < 0 || r >= H || c < 0 || c >= W) {
                break;
            }

            if (visited[r][c]) {
                break;
            }
            visited[r][c] = true;

            if (grid[r][c] == '^') {
                splitsPart1++;

                int nr = r + 1;

                if (nr < H && c - 1 >= 0) {
                    q.push({nr, c - 1});
                }
                if (nr < H && c + 1 < W) {
                    q.push({nr, c + 1});
                }

                break;
            }

            r++;
        }
    }

    cout << splitsPart1 << "\n";
    return 0;
}

