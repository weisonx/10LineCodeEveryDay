#include <iostream>
#include <vector>
#include <Algorithm>

using namespace std;
//O(n²)，leetcode超时
class Solution {
    bool is_pillar(vector<int> &height, int row, int col)
    {
        if(height[col] != 0 && row < height[col])
        {
            return true;
        }

        return false;
    }
public:
    int trap(vector<int>& height) {
        int row_size = *max_element(height.begin(), height.end());
        int col_size = height.size();
        int ret = 0;

        for(int i = 0; i < row_size; i++)
        {
            int left = 0;
            int right = 0;
            while(left < col_size)
            {
                while(left < col_size && is_pillar(height, i, left) != 1)
                {
                    left++;
                }
                if(left < col_size)
                {
                    right = left + 1;
                    while(right < col_size && is_pillar(height, i, right) != 1)
                    {
                        right++;
                    }
                    if(right < col_size)
                    {
                        ret += right - left - 1;
                    }
                }
                left = right;
            }
        }
        
        return ret;
    }
};