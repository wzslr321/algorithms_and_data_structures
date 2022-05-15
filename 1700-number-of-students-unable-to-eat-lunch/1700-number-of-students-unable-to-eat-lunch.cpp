class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
    auto unable{0}, i{0}, j{0};

    while (unable != students.size() - j) {
        if (students[j] == sandwiches[i]) {
            ++j;
            ++i;
            unable = 0;
        } else {
            students.push_back(students[j]);
            j++;
            ++unable;
        }
    }
    return unable;
}
};