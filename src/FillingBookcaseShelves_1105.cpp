/*
You are given an array books where books[i] = [thicknessi, heighti] indicates the thickness and height of the ith book. You are also given an integer shelfWidth.

We want to place these books in order onto bookcase shelves that have a total width shelfWidth.

We choose some of the books to place on this shelf such that the sum of their thickness is less than or equal to shelfWidth, then build another level of the shelf of the bookcase so that the total height of the bookcase has increased by the maximum height of the books we just put down. We repeat this process until there are no more books to place.

Note that at each step of the above process, the order of the books we place is the same order as the given sequence of books.

    For example, if we have an ordered list of 5 books, we might place the first and second book onto the first shelf, the third book on the second shelf, and the fourth and fifth book on the last shelf.

Return the minimum possible height that the total bookshelf can be after placing shelves in this manner.



Example 1:

Input: books = [[1,1],[2,3],[2,3],[1,1],[1,1],[1,1],[1,2]], shelfWidth = 4
Output: 6
Explanation:
The sum of the heights of the 3 shelves is 1 + 3 + 2 = 6.
Notice that book number 2 does not have to be on the first shelf.

Example 2:

Input: books = [[1,3],[2,4],[3,2]], shelfWidth = 6
Output: 4



Constraints:

    1 <= books.length <= 1000
    1 <= thicknessi <= shelfWidth <= 1000
    1 <= heighti <= 1000


 */
#include "../utils.h"
#include "gtest/gtest.h"

map<vector<int>, int> mem;
vector<vector<int>> books;
int shelfWidth;

class Solution1105 : public ::testing::Test {
private:
    static int solve(int i = 0, int c = 0, int m = 0) {
        if (i == books.size())
            return m;
        vector<int> v{i, c, m};
        if (mem.count(v))
            return mem[v];
        else if (c == 0)
            mem[v] = solve(i + 1, c + books[i][0], max(m, books[i][1]));
        else if (books[i][0] <= shelfWidth - c)
            mem[v] = min(solve(i + 1, c + books[i][0], max(m, books[i][1])),
                         m + solve(i));
        else
            mem[v] = m + solve(i);
        return mem[v];
    }

public:
    static int minHeightShelves(vector<vector<int>> &b, int s) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        books = b;
        shelfWidth = s;
        mem = map<vector<int>, int>();
        return solve();
    }
};

TEST(Solution1105, T1) {
    vector<vector<int>> b{{1, 1},
                          {2, 3},
                          {2, 3},
                          {1, 1},
                          {1, 1},
                          {1, 1},
                          {1, 2}};
    int s = 4;
    int expected = 6;
    ASSERT_TRUE(expected == Solution1105::minHeightShelves(b, s));
}


TEST(Solution1105, T2) {
    vector<vector<int>> b{{1, 3},
                          {2, 4},
                          {3, 2}};
    int s = 6;
    int expected = 4;
    ASSERT_TRUE(expected == Solution1105::minHeightShelves(b, s));
}