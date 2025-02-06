#include <queue>
using namespace std;

class RecentCounter {
private:
    queue<int> requests; // Queue to store request timestamps

public:
    RecentCounter() {
        // Constructor: Initialize an empty queue
    }

    int ping(int t) {
        // Step 1: Add the new request's timestamp to the queue
        requests.push(t);

        // Step 2: Remove all requests older than t - 3000
        while (!requests.empty() && requests.front() < t - 3000) {
            requests.pop();
        }

        // Step 3: The size of the queue is the number of recent requests
        return requests.size();
    }
};

/**
 * Explanation of the Code:
 * 1. We use a queue to store the timestamps of all requests.
 * 2. For every `ping`:
 *    - Add the new timestamp `t` to the queue.
 *    - Remove all timestamps from the front of the queue that are older than `t - 3000`.
 *    - The size of the queue now represents the number of requests in the last 3000 milliseconds.
 * 3. The queue ensures that we efficiently manage the requests and only keep the relevant ones.
 */