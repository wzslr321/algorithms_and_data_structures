#include <iostream>
#include <vector>
#include <utility>
#include <optional>

using namespace std;

// TODO - MAXIMIZE GROUPS

class Solution {
private:
    vector<int> lettersOcc;
    vector<pair<string, int>> doableWords;
    vector<tuple<vector<string>, vector<int>, int>> doableGroups;
    int aAscii = 97;
    int alphabetSize = 26;

    void countLetters(const vector<char> &letters) noexcept {
        lettersOcc.resize(alphabetSize);
        for (const auto ch : letters) {
            lettersOcc[ch - aAscii]++;
        }
    }

    bool tryToMakeWord(const string &word, const vector<char> &letters, const vector<int> &score) noexcept {
        vector<int> lettersOccC = lettersOcc;
        for (const auto ch : word) {
            auto i = ch - aAscii;
            if (lettersOccC[i] == 0) return false;
            lettersOccC[i]--;
        }
        auto wordScore = getWordScore(word, score);
        doableWords.emplace_back(word, wordScore);
        return true;
    }

    void findDoableWords(const vector<string> &words, const vector<char> &letters, const vector<int> &score) {
        for (const auto &word : words) {
            tryToMakeWord(word, letters, score);
        }
    }

    [[nodiscard]] int getWordScore(const string &word, const vector<int> &score) const {
        int value = 0;
        for (const auto ch : word) {
            value += score[ch - aAscii];
        }

        return value;
    }

    optional<vector<int>> canConnectWords(const string &word1, const string &word2) {
        vector<int> lettersOccC = lettersOcc;
        for (const auto ch: word1) {
            lettersOccC[ch - aAscii]--;
        }
        for (const auto ch: word2) {
            if (lettersOccC[ch - aAscii] == 0) return nullopt;
            lettersOccC[ch - aAscii]--;
        }

        return lettersOccC;
    }

    void tryToConnectWords() {
        for (size_t i = 0; i < doableWords.size() - 1; ++i) {
            auto word1 = doableWords[i];
            auto word2 = doableWords[i + 1];
            auto leftLetters = canConnectWords(word1.first, word2.first);
            if (leftLetters) {
                vector<string> words = {word1.first, word2.first};
                auto group = make_tuple(words, *leftLetters, word1.second + word2.second);
                doableGroups.emplace_back(group);
            }
        }
    }

public:

    int maxScoreWords(const vector<string> &words, const vector<char> &letters, const vector<int> &score) {

        countLetters(letters);
        findDoableWords(words, letters, score);
        tryToConnectWords();
        auto ans = 0;
        for (const auto &group : doableGroups) {
            ans = max(ans, get<2>(group));
        }


        return ans;
    }

};


int main() {
    /*
    vector<string> t1w = {"dog", "cat", "dad", "good"};
    vector<char> t1l = {'a', 'a', 'c', 'd', 'd', 'd', 'g', 'o', 'o'};
    vector<int> t1s = {1, 0, 9, 5, 0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    */


    vector<string> t2w = {"xxxz", "ax", "bx", "cx"};
    vector<char> t2l = {'z', 'a', 'b', 'c', 'x', 'x', 'x'};
    vector<int> t2s = {4, 4, 4, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 5, 0, 10};


    auto solution = Solution();
    // assert(solution.maxScoreWords(t1w, t1l, t1s) == 23);
    assert(solution.maxScoreWords(t2w, t2l, t2s) == 27);

    return 0;
}
