class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> visited(n, 0), onPath(n, 0), dist(n, -1);
        int maxLength = -1;

        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int current = i, distance = 0;
                while (current != -1 && !visited[current]) {
                    visited[current] = 1;
                    onPath[current] = 1;
                    dist[current] = distance++;
                    current = edges[current];
                }
                if (current != -1 && onPath[current]) {
                    maxLength = max(maxLength, distance - dist[current]);
                }
                current = i;
                while (current != -1 && onPath[current]) {
                    onPath[current] = 0;
                    current = edges[current];
                }
            }
        }

        return maxLength;
    }
};
