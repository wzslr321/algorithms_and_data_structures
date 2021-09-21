// https://leetcode.com/problems/valid-parentheses/

/*
 * Those comments is just my process of thinking
 *
 * string contains parentheses, which we can consider as numbers for simplicity
 * ( = 0, ) = 1, { = 2, } = 3, [ = 4, ] = 5
 *
 * We can store opening and closing characters in different array, or
 * create a map with those chars as indexes and bool describing if it is
 * opening. map<char,bool> key: 0, value: true ; key: 1, value: false ; etc.
 *
 * We need to keep track of its indexes Let's say we have a string: "(){[]}" -
 it
 * is valid btw. We iterate through it and we save index of parentheses to a map
 * of char,array<int> - array holds indexes.
 *
 * First char creates a '(' key in a map and append an index to array of values.
 * Second char create a ')' key in a  map and append an index ... blah blah blah
 *
 * Okay, we got chars, and indexes. How we can check is valid now?
 * This one isn't valid - "([)]" Hmm, okay so in this case where we have
 * nested parentheses, index of closing parenthese which was opened on the
 * outter layer, must be bigger than index of closing parenthese y which was
 * opened in the inner layer.
 *
 * Okay, but should we actually care this way? Maybe, we don't have to iterate
 one by one... We can
 * check 1 and n-1 element. If those are same opening and closing, check 2 and
 * n-1 etc. If those are not the same, we save opening to one map with this char
 * as key, and value as same but closing one. respectively with closing char.
 *
 * We iterate and check 2 and n-2 element. If 2nd element is closing char and is
 * not equal to value of map accesed by key of 1 element we can return false.
 * Otherwise we iterate again.

 * check 3 and n-3 element. same if logic to return false. so okay we are on the
 stage,
 * where this kind of string, would return false: "({[}...anything else, we
 don't care - it returned false"
 *
 * it doesn't seem as bad tbh. At this moment I would just add a check if
 current
 * index is equal to n - index. But what if so.. We would have to add some
 * functionality that would increment/decrement a variable if parenthese would
 * find its match. If in the moment of spotting this variable would be greater
 * than 0, return false, otherwise - true.
 */

#include <array>
#include <cassert>
#include <iostream>
#include <unordered_map>

using namespace std;

unordered_map<char, char> parentheses{
    {'(', ')'},
    {'{', '}'},
    {'[', ']'},
};

unordered_map<char, bool> isClosing{
    {'}', true},  {')', true},  {']', true},
    {'{', false}, {'(', false}, {'[', false},
};

unordered_map<int, char> opening{};
unordered_map<int, char> closing{};

int un{};

int in1{};
int in2{};

bool validate(char a, char b, char c, char d) {
    if (isClosing[b] && b != parentheses[a]) {
        return false;
    }

    if (!isClosing[c] && d != parentheses[c]) {
        return false;
    }

    if (!isClosing[a] && b == parentheses[a]) {
        return true;
    }

    if (!isClosing[c] && d == parentheses[c]) {
        return true;
    }

    if (!isClosing[a]) {
        opening[in1] = a;
        opening[in1 + 1] = b;
        ++un;
        in1 += 2;
    }

    if (isClosing[d]) {
        closing[in2] = c;
        closing[in2 + 1] = d;
        --un;
        in2 += 2;
    }

    if (parentheses[opening[in1 - 2]] != closing[in1 - 2]) {
        ++un;
    } else {
        --un;
    }

    if (parentheses[opening[in2 - 1]] != closing[in2 - 1]) {
        ++un;
    } else {
        --un;
    }


    cout << un << '\n';

    return true;
};

bool isValid(string s) {
    if ((s.size() % 2) != 0) {
        return false;
    }

    if (!isClosing[s[s.size() - 1]] || isClosing[s[0]]) {
        return false;
    }

    if (s.size() == 2) {
        if (s[1] != parentheses[s[0]]) {
            return false;
        }
        return true;
    }

    for (auto i{0}; i < s.size(); i++) {
        if (i < (s.size() / 2) - 1) {
            if (validate(s[i], s[i + 1], s[s.size() - 1], s[s.size() - 2]) ==
                false) {
                return false;
            }
        }
    }

    if(un > 0){
        return false;
    }

    return true;
}

int main() {
    cout << isValid("({[)");
    return 0;
}
