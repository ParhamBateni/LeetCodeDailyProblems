/*
 * There are n workers. You are given two integer arrays quality and wage where quality[i] is the quality of the ith worker and wage[i] is the minimum wage expectation for the ith worker.

We want to hire exactly k workers to form a paid group. To hire a group of k workers, we must pay them according to the following rules:

    Every worker in the paid group must be paid at least their minimum wage expectation.
    In the group, each worker's pay must be directly proportional to their quality. This means if a worker’s quality is double that of another worker in the group, then they must be paid twice as much as the other worker.

Given the integer k, return the least amount of money needed to form a paid group satisfying the above conditions. Answers within 10-5 of the actual answer will be accepted.
 */

#include "../utils.h"
#include "gtest/gtest.h"

class Solution857 : public ::testing::Test {
public:
    static double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        ios::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        vector<pair<int,int>> v;
        int n = quality.size();
        for (int i=0;i<n;i++){
            v.push_back(pair(quality[i],wage[i]));
        }
        sort(v.begin(),v.end(),[](const pair<int,int>& p1 , const pair<int,int>& p2){return p1.first*p2.second<p2.first*p1.second;});
        int mem[n+1];
        priority_queue<int> pq;
        int s = 0;
        for (int i=n-1;i>n-k;i--){
            pq.push(v[i].first);
            s+=v[i].first;
        }
        mem[n-k+1] = s;
        for (int i=n-k;i>=0;i--){
            pq.push(v[i].first);
            s+=v[i].first-pq.top();
            pq.pop();
            mem[i] = s;
        }
        double mn = INT_MAX;
        for (int i=0;i<n-k+1;i++){
            mn = min(mn,v[i].second*1.0/v[i].first*mem[i+1]+v[i].second);
        }
        return mn;
    }
};

TEST(Solution857, T1) {
    vector<int> q = vector<int>{10,20,5};
    vector<int> w = vector<int>{70,50,30};
    int k = 2;
    double res = Solution857::mincostToHireWorkers(q,w,k);
    double expected = 105.00;
    ASSERT_TRUE(abs(expected-res)<1e-5);
}

TEST(Solution857, T2) {
    vector<int> q = vector<int>{3,1,10,10,1};
    vector<int> w = vector<int>{4,8,2,2,7};
    int k = 3;
    double res = Solution857::mincostToHireWorkers(q,w,k);
    double expected = 30.66667;
    ASSERT_TRUE(abs(expected-res)<1e-5);
}