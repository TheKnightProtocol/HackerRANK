#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
#include <string>
#include <functional>
#include <cmath>

using namespace std;

struct Board {
    vector<vector<int>> tiles;
    int zeroRow, zeroCol;
    int moves;
    string path;
    int cost;
    
    Board(vector<vector<int>> t, int zr, int zc, int m, string p) 
        : tiles(t), zeroRow(zr), zeroCol(zc), moves(m), path(p) {
        cost = moves + manhattan();
    }
    
    int manhattan() const {
        int n = tiles.size();
        int dist = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                int val = tiles[i][j];
                if (val != 0) {
                    int targetRow = val / n;
                    int targetCol = val % n;
                    dist += abs(i - targetRow) + abs(j - targetCol);
                }
            }
        }
        return dist;
    }
    
    bool isSolved() const {
        int n = tiles.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (i == n-1 && j == n-1) {
                    if (tiles[i][j] != 0) return false;
                } else {
                    if (tiles[i][j] != i * n + j + 1) return false;
                }
            }
        }
        return true;
    }
    
    bool operator==(const Board& other) const {
        return tiles == other.tiles;
    }
    
    vector<Board> getNeighbors() const {
        vector<Board> neighbors;
        int n = tiles.size();
        int dirs[4][3] = {{-1, 0, 'U'}, {1, 0, 'D'}, {0, -1, 'L'}, {0, 1, 'R'}};
        
        for (auto& dir : dirs) {
            int newRow = zeroRow + dir[0];
            int newCol = zeroCol + dir[1];
            
            if (newRow >= 0 && newRow < n && newCol >= 0 && newCol < n) {
                vector<vector<int>> newTiles = tiles;
                swap(newTiles[zeroRow][zeroCol], newTiles[newRow][newCol]);
                
                string newPath = path;
                if (!newPath.empty()) newPath += "\n";
                newPath += string(1, dir[2]);
                
                neighbors.emplace_back(newTiles, newRow, newCol, moves + 1, newPath);
            }
        }
        return neighbors;
    }
};

struct BoardHash {
    size_t operator()(const Board& board) const {
        size_t hash = 0;
        int n = board.tiles.size();
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                hash = hash * 31 + board.tiles[i][j];
            }
        }
        return hash;
    }
};

struct CompareBoard {
    bool operator()(const Board& a, const Board& b) const {
        return a.cost > b.cost;
    }
};

string solvePuzzle(vector<vector<int>>& initial, int zr, int zc) {
    priority_queue<Board, vector<Board>, CompareBoard> pq;
    unordered_set<Board, BoardHash> visited;
    
    Board start(initial, zr, zc, 0, "");
    pq.push(start);
    
    while (!pq.empty()) {
        Board current = pq.top();
        pq.pop();
        
        if (visited.count(current)) continue;
        visited.insert(current);
        
        if (current.isSolved()) {
            return current.path;
        }
        
        for (auto& neighbor : current.getNeighbors()) {
            if (!visited.count(neighbor)) {
                pq.push(neighbor);
            }
        }
    }
    
    return "";
}

int main() {
    int k;
    cin >> k;
    
    vector<vector<int>> board(k, vector<int>(k));
    int zeroRow = 0, zeroCol = 0;
    
    for (int i = 0; i < k; i++) {
        for (int j = 0; j < k; j++) {
            cin >> board[i][j];
            if (board[i][j] == 0) {
                zeroRow = i;
                zeroCol = j;
            }
        }
    }
    
    string solution = solvePuzzle(board, zeroRow, zeroCol);
    
    if (!solution.empty()) {
        int moveCount = 1;
        for (char c : solution) {
            if (c == '\n') moveCount++;
        }
        cout << moveCount << endl;
        cout << solution << endl;
    }
    
    return 0;
}
