int strStr(string haystack, string needle) {
    if (haystack.size() < 1) {
        if (needle.size() < 1) {
            return 0;
        }
        return -1;
    }
    if (needle.size() < 1) {
        return 0;
    }
    auto left{0};
    auto in{-1};
    for (auto i{0}; i < haystack.size(); i++) {
        if ((haystack.size() - left) < needle.size()) {
            return -1;
        }
        if (haystack[i] == needle[0]) {
            in = i;
            for (auto j{0}; j < needle.size(); j++) {
                if (haystack[i + j] != needle[j]) {
                    in = -1;
                    break;
                }
                if (j == needle.size() - 1) {
                    return in;
                }
            }
        }
    }
    return in;
}
