#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <climits>
#include <stack>
#include <queue>
using namespace std;

class Solution {
    int findRoom(vector<pair<int, int>> rooms, int target) {
        for (int i = 0; i < rooms.size(); i++) {
            if (rooms[i].first <= target)
                return i;
        }
        return -1;
    }

    int findMin(vector<pair<int, int>> rooms) {
        int minT = INT_MAX, minR = -1;
        for (int i = 0; i < rooms.size(); i++) {
            if (minT > rooms[i].first) {
                minT = rooms[i].first;
                minR = i;
            }
        }
        return minR;
    }

public:
    int mostBooked(int n, vector<vector<int>>& meetings) {
        vector<int> roomMap(n, 0);
        priority_queue<int, vector<int>, greater<int>> rooms;
        priority_queue<pair<int, int>, vector<pair<int, int>>,
                       greater<pair<int, int>>>
            busyRooms;

        int duration = 0;
        // sorting wrt st
        sort(meetings.begin(), meetings.end());

        // insert all the rooms in rooms
        for (int i = 0; i < n; i++)
            rooms.push(i);

        for (vector<int> meeting : meetings) {
            int start = meeting[0];
            int end = meeting[1];
            long long dur = end - start;

            // clear the busy rooms where meetings have already covered
            while (!busyRooms.empty() && busyRooms.top().first <= start) {
                rooms.push(busyRooms.top().second);
                busyRooms.pop();
            }

            int room;
            long long newEnd;
            // find non busy room
            if (!rooms.empty()) {
                room = rooms.top();
                newEnd = end;
                rooms.pop();
            }

            // find fast ending room in busy rooms
            else {
                room = busyRooms.top().second;
                newEnd = busyRooms.top().first + dur;
                busyRooms.pop();
            }

            // record the busy room with new entries
            busyRooms.push({newEnd, room});

            // record the count of the room
            roomMap[room]++;
        }

        // find max
        int maxR = -1, maxC = 0;
        for (int i = 0; i < roomMap.size(); i++) {
            if (maxC < roomMap[i]) {
                maxR = i;
                maxC = roomMap[i];
            }
        }

        return maxR;
    }
};