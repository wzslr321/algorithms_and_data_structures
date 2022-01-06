#pragma GCC optimize("O3,unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define ll long long

#define PB push_back
#define MP make_pair

#define LPI(i, a, b, d) for (int i = a; i < (int)b; i += d)

using VI = vector<int>;
using VS = vector<string>;
using PI = pair<int, int>;

//

struct Node {
  int index;
  int value;
  int parent;
  vector<Node> children;
  Node() : index(0), value(0), parent(0), children({}) {}
  Node(int i, int v, int p, vector<Node> c)
      : index(i), value(v), parent(p), children(c) {}
};

const int N = 1000007;

// przechowuje czy pensja o wartosci <1,n> została już użyta
vector<bool> pensje(N);
vector<Node> pracownicy(N);
unordered_map<int, vector<int>> mozliwosci;
unordered_map<int, vector<int>> wysokosci;
int root;
int maks_wysokosc = 0;
vector<int> listki;
vector<bool> odwiedzony(N);

int n;
auto zbuduj_drzewo() -> void {
  LPI(i, 1, n + 1, 1) {
    int p, x;
    cin >> p >> x;
    if (p == i) root = p;
    pensje[x] = true;
    pracownicy[i] = Node(i, x, p, {});
    pracownicy[p].children.PB(pracownicy[i]);
  }
}

auto aktualizuj_wysokosc() -> void {
  LPI(i, 1, n + 1, 1) {
    auto obecny = pracownicy[i];
    int wysokosc = 0;
    while (obecny.index != root) {
      ++wysokosc;
      obecny = pracownicy[obecny.parent];
    }
    maks_wysokosc = max(wysokosc, maks_wysokosc);
    wysokosci[wysokosc].PB(i);
  }
}

auto znajdz_listki() -> void {
  for (int i = 0; i < maks_wysokosc + 1; ++i) {
    for (size_t j = 0; j < wysokosci[i].size(); ++j) {
      auto wierzch = pracownicy[wysokosci[i][j]].index;
      if (pracownicy[wierzch].children.size() == 0) listki.PB(wierzch);
    }
  }
}

auto sprawdz_braci(int listek) -> void {
  auto rodzic = pracownicy[pracownicy[listek].parent].index;
  auto sz = mozliwosci[listek].size();
  if (sz == pracownicy[rodzic].children.size()) {
    bool pasuje = true;
    for (auto child : pracownicy[rodzic].children) {
      for (size_t i = 0; i < sz; ++i) {
        if (mozliwosci[child.index].size() < sz) {
          pasuje = false;
          break;
        }
        if (mozliwosci[child.index][i] != mozliwosci[listek][i]) {
          pasuje = false;
          break;
        }
      }
      if (!pasuje) break;
    }

    if (pasuje) {
      for (auto p : mozliwosci[listek])
        pensje[p] = true;
    }
  }
}

auto penetruj_listki() -> void {
  for (auto listek : listki) {
    odwiedzony[listek] = true;
    if (pracownicy[listek].value != 0) continue;
    auto stary = pracownicy[pracownicy[listek].parent].value;
    for (int i = stary - 1; i > 0; --i) {
      if (!pensje[i]) {
        mozliwosci[listek].push_back(i);
      }
    }
    if (mozliwosci[listek].size() == 1) {
      pracownicy[listek].value = mozliwosci[listek][0];
      pensje[mozliwosci[listek][0]] = true;
    }
    if (mozliwosci[listek].size() > 1) sprawdz_braci(listek);
  }
}

auto wielkosc_poddrzewka(int index) {}
auto penetruj_drzewo() -> void {
  for (auto i = maks_wysokosc; i >= 0; --i) {
    for (size_t j = 0; j < wysokosci[i].size(); ++j) {
      if (odwiedzony[wysokosci[i][j]]) continue;
      auto obecny = pracownicy[wysokosci[i][j]];
      if (obecny.value != 0) continue;
      auto stary = pracownicy[obecny.parent];
      for (int i = stary.value - 1; i > 0; --i) {
        if (!pensje[i]) mozliwosci[obecny.index].push_back(i);
      }
      if (mozliwosci[obecny.index].size() == 1) {
        pracownicy[obecny.index].value = mozliwosci[obecny.index][0];
        pensje[mozliwosci[obecny.index][0]] = true;
      }
      if (mozliwosci[obecny.index].size() > 1) sprawdz_braci(obecny.index);
    }
  }
}

auto main() -> int {
  ios::sync_with_stdio(false);
  cin.tie(0);

  cin >> n;
  zbuduj_drzewo();
  aktualizuj_wysokosc();
  znajdz_listki();
  penetruj_listki();
  penetruj_drzewo();

  LPI(i, 1, n + 1, 1) { cout << pracownicy[i].value << '\n'; }

  return 0;
}
