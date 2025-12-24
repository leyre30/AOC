#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cstdint>   // <-- para uint64_t

using namespace std;

// Tabla hash sencilla para guardar resultados ya calculados.
class HashTable {
    struct Entry {
        long long key;
        unsigned char value;
        Entry* next;
        Entry(long long k, unsigned char v, Entry* n) : key(k), value(v), next(n) {}
    };

    vector<Entry*> buckets;
    size_t mask;

    static uint64_t mix64(uint64_t x) {
        x += 0x9e3779b97f4a7c15ULL;
        x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9ULL;
        x = (x ^ (x >> 27)) * 0x94d049bb133111ebULL;
        return x ^ (x >> 31);
    }

    size_t idx(long long key) const {
        uint64_t h = mix64((uint64_t)key);
        return (size_t)(h & mask);
    }

public:
    explicit HashTable(size_t cap_pow2 = 1 << 20) {
        size_t cap = 1;
        while (cap < cap_pow2) cap <<= 1;
        buckets.assign(cap, nullptr);
        mask = cap - 1;
    }

    ~HashTable() {
        clear();
    }

    void clear() {
        for (auto &head : buckets) {
            Entry* cur = head;
            while (cur) {
                Entry* nx = cur->next;
                delete cur;
                cur = nx;
            }
            head = nullptr;
        }
    }

    bool get(long long key, unsigned char &out) const {
        Entry* cur = buckets[idx(key)];
        while (cur) {
            if (cur->key == key) {
                out = cur->value;
                return true;
            }
            cur = cur->next;
        }
        return false;
    }

    void put(long long key, unsigned char value) {
        size_t i = idx(key);
        Entry* cur = buckets[i];
        while (cur) {
            if (cur->key == key) {
                cur->value = value;
                return;
            }
            cur = cur->next;
        }
        buckets[i] = new Entry(key, value, buckets[i]);
    }
};

// Comprueba si un número es de la forma XX (dos repeticiones exactas).
static bool is_repeat_2(long long x) {
    string s = to_string(x);
    int n = s.size();
    if (n % 2 != 0) return false;
    int len = n / 2;

    for (int i = 0; i < len; i++) {
        if (s[i] != s[i + len]) return false;
    }
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string line;
    if (!getline(cin, line)) return 0;
    if (!line.empty() && line.back() == '\r') line.pop_back();

    HashTable memo(1 << 20);

    long long sum1 = 0;

    string token;
    stringstream ss(line);

    while (getline(ss, token, ',')) {
        if (token.empty()) continue;

        long long L = 0, R = 0;
        if (sscanf(token.c_str(), "%lld-%lld", &L, &R) != 2) continue;

        for (long long id = L; id <= R; id++) {
            unsigned char v = 0;

            if (memo.get(id, v) && (v & 0x80)) {
                if (v & 0x01) sum1 += id;
                continue;
            }

            bool p1 = is_repeat_2(id);

            unsigned char nv = 0x80;
            if (p1) nv |= 0x01;

            memo.put(id, nv);

            if (p1) sum1 += id;
        }
    }

    cout << "parte 1: " << sum1 << "\n";
    return 0;
}

