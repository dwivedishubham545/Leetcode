class Solution {
public:
    int smallestChair(vector<vector<int>>& times, int targetFriend) {
        int n = times.size();
        
        for (int i = 0; i < n; ++i) {
            times[i].push_back(i); 
        }

        sort(times.begin(), times.end(), [](const vector<int>& a, const vector<int>& b) {
            return a[0] < b[0];
        });

        priority_queue<int, vector<int>, greater<int>> availableChairs;
        
        for (int i = 0; i < n; ++i) {
            availableChairs.push(i);
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> occupiedChairs;

        for (int i = 0; i < n; ++i) {
            int arrival = times[i][0];
            int leaving = times[i][1];
            int friendIndex = times[i][2];
            
            while (!occupiedChairs.empty() && occupiedChairs.top().first <= arrival) {
                availableChairs.push(occupiedChairs.top().second);
                occupiedChairs.pop();
            }
            int chair = availableChairs.top();
            availableChairs.pop();
            
            if (friendIndex == targetFriend) {
                return chair;
            }
            occupiedChairs.push({leaving, chair});
        }
        
        return -1;
    }
};