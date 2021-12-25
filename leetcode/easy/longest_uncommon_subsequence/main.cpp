using namespace std;

int findLUSlength(string a, string b) {
  return a == b ? -1 : max(a.size(), b.size());
}
