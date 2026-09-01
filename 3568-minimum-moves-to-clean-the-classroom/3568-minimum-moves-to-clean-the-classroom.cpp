#include <vector>
#include <string>
#include <queue>
#include <tuple>

using namespace std;

class Solution {
public:
    int minMoves(vector<string>& classroom, int maxEnergy) {
        int m = classroom.size();
        int n = classroom[0].size();
        
        int startR = -1, startC = -1;
        vector<pair<int, int>> litters;
        vector<vector<int>> litterIdx(m, vector<int>(n, -1));
        
        for (int r = 0; r < m; ++r) {
            for (int c = 0; c < n; ++c) {
                if (classroom[r][c] == 'S') {
                    startR = r;
                    startC = c;
                } else if (classroom[r][c] == 'L') {
                    litterIdx[r][c] = litters.size();
                    litters.push_back({r, c});
                }
            }
        }
        
        int numLitters = litters.size();
        if (numLitters == 0) return 0;
        
        int targetMask = (1 << numLitters) - 1;

        vector<vector<vector<int>>> maxEnergyLeft(
            m, vector<vector<int>>(n, vector<int>(1 << numLitters, -1))
        );

        queue<tuple<int, int, int, int>> q;
        
        int initialMask = 0;
        int initialEnergy = maxEnergy;
        if (classroom[startR][startC] == 'L') {
            initialMask |= (1 << litterIdx[startR][startC]);
        }
        
        maxEnergyLeft[startR][startC][initialMask] = initialEnergy;
        q.push({startR, startC, initialMask, 0});
        
        int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

        while (!q.empty()) {
            auto [r, c, mask, steps] = q.front();
            q.pop();

            if (mask == targetMask) {
                return steps;
            }

            int currEnergy = maxEnergyLeft[r][c][mask];

            // If we are at 0 energy and NOT on an 'R' cell, we cannot move further out
            if (currEnergy == 0 && classroom[r][c] != 'R') continue;

            for (auto& dir : dirs) {
                int nr = r + dir[0];
                int nc = c + dir[1];

                if (nr < 0 || nr >= m || nc < 0 || nc >= n || classroom[nr][nc] == 'X') {
                    continue;
                }

                int nextEnergy = currEnergy - 1;
                if (nextEnergy < 0) continue;

                char cell = classroom[nr][nc];
                
                // Energy refill
                if (cell == 'R') {
                    nextEnergy = maxEnergy;
                }

                // Litter collection
                int nextMask = mask;
                if (cell == 'L') {
                    nextMask |= (1 << litterIdx[nr][nc]);
                }

                if (nextEnergy > maxEnergyLeft[nr][nc][nextMask]) {
                    maxEnergyLeft[nr][nc][nextMask] = nextEnergy;
                    q.push({nr, nc, nextMask, steps + 1});
                }
            }
        }

        return -1;
    }
};