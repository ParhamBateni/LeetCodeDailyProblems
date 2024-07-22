/*
There are n 1-indexed robots, each having a position on a line, health, and movement direction.

You are given 0-indexed integer arrays positions, healths, and a string directions (directions[i] is either 'L' for left or 'R' for right). All integers in positions are unique.

All robots start moving on the line simultaneously at the same speed in their given directions. If two robots ever share the same position while moving, they will collide.

If two robots collide, the robot with lower health is removed from the line, and the health of the other robot decreases by one. The surviving robot continues in the same direction it was going. If both robots have the same health, they are both removed from the line.

Your task is to determine the health of the robots that survive the collisions, in the same order that the robots were given, i.e. final heath of robot 1 (if survived), final health of robot 2 (if survived), and so on. If there are no survivors, return an empty array.

Return an array containing the health of the remaining robots (in the order they were given in the input), after no further collisions can occur.

Note: The positions may be unsorted.




Example 1:

Input: positions = [5,4,3,2,1], healths = [2,17,9,15,10], directions = "RRRRR"
Output: [2,17,9,15,10]
Explanation: No collision occurs in this example, since all robots are moving in the same direction. So, the health of the robots in order from the first robot is returned, [2, 17, 9, 15, 10].

Example 2:

Input: positions = [3,5,2,6], healths = [10,10,15,12], directions = "RLRL"
Output: [14]
Explanation: There are 2 collisions in this example. Firstly, robot 1 and robot 2 will collide, and since both have the same health, they will be removed from the line. Next, robot 3 and robot 4 will collide and since robot 4's health is smaller, it gets removed, and robot 3's health becomes 15 - 1 = 14. Only robot 3 remains, so we return [14].

Example 3:

Input: positions = [1,2,5,6], healths = [10,10,11,11], directions = "RLRL"
Output: []
Explanation: Robot 1 and robot 2 will collide and since both have the same health, they are both removed. Robot 3 and 4 will collide and since both have the same health, they are both removed. So, we return an empty array, [].



Constraints:

    1 <= positions.length == healths.length == directions.length == n <= 105
    1 <= positions[i], healths[i] <= 109
    directions[i] == 'L' or directions[i] == 'R'
    All values in positions are distinct


 */
#include "../utils.h"
#include "gtest/gtest.h"


class Solution2751 : public ::testing::Test {
    struct Robot {
        int position, health, direction;

        bool operator<(const Robot &r) { return position < r.position; }
    };

public:
    static vector<int> survivedRobotsHealths(vector<int> &positions,
                                             vector<int> &healths, string directions) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL), cout.tie(NULL);
        int n = positions.size();
        vector<Robot> robots(n);
        map<int, int> position_map;
        for (int i = 0; i < n; i++) {
            Robot r{positions[i], healths[i], directions[i]};
            robots[i] = r;
            position_map[positions[i]] = i;
        }
        sort(robots.begin(), robots.end());
        int start = 0, end = n - 1;
        while (start < n && robots[start++].direction == 'L');
        start--;
        while (end >= 0 && robots[end--].direction == 'R');
        end++;
        if (start != end) {
            stack<Robot *> s;
            for (int i = start; i <= end; i++) {
                if (robots[i].direction == 'R')
                    s.push(&robots[i]);
                else {
                    while (s.size() > 0) {
                        Robot *r = s.top();
                        if (robots[i].health > r->health) {
                            robots[i].health -= 1;
                            r->health = 0;
                            s.pop();
                        } else if (robots[i].health < r->health) {
                            r->health -= 1;
                            robots[i].health = 0;
                            break;
                        } else {
                            r->health = 0;
                            robots[i].health = 0;
                            s.pop();
                            break;
                        }
                    }
                }
            }
            for (auto &r: robots) {
                healths[position_map[r.position]] = r.health;
            }
            vector<int> res;
            for (auto &x: healths)
                if (x != 0)
                    res.push_back(x);
            return res;
        }
        return healths;
    }
};

TEST(Solution2751, T1) {
    vector<int> positions {5,4,3,2,1};
    vector<int> healths {2,17,9,15,10};
    string directions = "RRRRR";
    vector<int> expected {2,17,9,15,10};
    ASSERT_TRUE(expected==Solution2751::survivedRobotsHealths(positions,healths,directions));
}


TEST(Solution2751, T2) {
    vector<int> positions {3,5,2,6};
    vector<int> healths {10,10,15,12};
    string directions = "RLRL";
    vector<int> expected {14};
    ASSERT_TRUE(expected==Solution2751::survivedRobotsHealths(positions,healths,directions));
}