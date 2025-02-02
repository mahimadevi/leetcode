#include <vector>
#include <string>
#include <queue>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    vector<int> countMentions(int numberOfUsers, vector<vector<string>>& events) {
        // Initialize mentions array to store the count of mentions for each user
        vector<int> mentions(numberOfUsers, 0);

        // Initialize status array to track whether each user is online (true) or offline (false)
        vector<bool> status(numberOfUsers, true);

        // Min-heap to track when users will come back online
        // Each element is a pair: (timestamp, user_id)
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> onlineQueue;

        // Sort events by timestamp
        // If two events have the same timestamp, process OFFLINE events first
        sort(events.begin(), events.end(), [](const vector<string>& a, const vector<string>& b) {
            int timeA = stoi(a[1]);
            int timeB = stoi(b[1]);
            if (timeA == timeB) {
                // OFFLINE events come before MESSAGE events
                return a[0] == "OFFLINE";
            }
            return timeA < timeB;
        });

        // Process each event
        for (const auto& event : events) {
            string type = event[0];
            int timestamp = stoi(event[1]);

            // Update user statuses based on the current timestamp
            while (!onlineQueue.empty() && onlineQueue.top().first <= timestamp) {
                int user = onlineQueue.top().second;
                status[user] = true; // Mark user as online
                onlineQueue.pop();
            }

            if (type == "OFFLINE") {
                int user = stoi(event[2]);
                status[user] = false; // Mark user as offline
                onlineQueue.push({timestamp + 60, user}); // Schedule user to come back online
            } else if (type == "MESSAGE") {
                string mentionsStr = event[2];
                if (mentionsStr == "ALL") {
                    // Mention all users
                    for (int i = 0; i < numberOfUsers; i++) {
                        mentions[i]++;
                    }
                } else if (mentionsStr == "HERE") {
                    // Mention only online users
                    for (int i = 0; i < numberOfUsers; i++) {
                        if (status[i]) {
                            mentions[i]++;
                        }
                    }
                } else {
                    // Mention specific users
                    // Split the mentions string into individual user IDs
                    size_t pos = 0;
                    while ((pos = mentionsStr.find("id")) != string::npos) {
                        mentionsStr.erase(0, pos + 2); // Remove "id"
                        size_t endPos = mentionsStr.find(" ");
                        string userIdStr = (endPos == string::npos) ? mentionsStr : mentionsStr.substr(0, endPos);
                        int userId = stoi(userIdStr);
                        mentions[userId]++; // Increment mention count for the user
                        if (endPos == string::npos) break;
                        mentionsStr.erase(0, endPos + 1); // Remove the processed user ID
                    }
                }
            }
        }

        return mentions;
    }
};