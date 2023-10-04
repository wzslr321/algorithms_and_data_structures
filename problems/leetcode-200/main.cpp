// https://leetcode.com/problems/number-of-islands/description/

class Solution {
public:
       void visit_neighbors(std::vector<std::vector<char>> &visited, std::vector<std::vector<char>> &grid, size_t rows,
                     size_t columns, size_t x, size_t y) {
    if (visited[x][y] == 'v') return;
    visited[x][y] = 'v';
    if (grid[x][y] == '0') return;

    if (x > 0) {
        visit_neighbors(visited, grid, rows, columns, x - 1, y);
    }
    if (x < rows - 1) {
        visit_neighbors(visited, grid, rows, columns, x + 1, y);
    }
    if (y > 0) {
        visit_neighbors(visited, grid, rows, columns, x, y - 1);
    }
    if (y < columns - 1) {
        visit_neighbors(visited, grid, rows, columns, x, y + 1);
    }

}

int numIslands(std::vector<std::vector<char>> &grid) {
    auto rows = grid.size(), columns = grid[0].size();
    std::vector<std::vector<char>> visited(rows, std::vector<char>(columns, 'u')); // 'u' = unvisited, 'v' = visited

    int answer = 0;
    for (size_t i = 0; i < rows; ++i) {
        for (size_t j = 0; j < columns; ++j) {
            if (visited[i][j] == 'v' || grid[i][j] == '0') {
                continue;
            }
            ++answer;
            visit_neighbors(visited, grid, rows, columns, i, j);
        }
    }


    return answer;
}
};