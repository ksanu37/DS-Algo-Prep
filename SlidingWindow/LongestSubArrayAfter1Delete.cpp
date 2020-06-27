//
//  LongestSubArrayAfter1Delete.cpp
//  SlidingWindow
//
//  Created by Kumar Sanu on 27/06/20.
//  Copyright © 2020 Kumar Sanu. All rights reserved.
//

/*
 
 https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
 
 The idea: Use sliding window mechanism
 
 Given a binary array nums, you should delete one element from it.

 Return the size of the longest non-empty subarray containing only 1's in the resulting array.

 Return 0 if there is no such subarray.
 
 Maintain a counter K=1, a pointer i to the start of the array and
 an iterator j,
 
 Start traversing the array
 
 if the element is 0 --> Decrease K -> Deleted this one
 
 if K<0 --> Two items are deleted, move i to the next location of 0 that is get the window between this 0 and the previous 0.
 
 */

#include "LongestSubArrayAfter1Delete.hpp"
#include <vector>
using namespace std;


class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        if(nums.size()==0)
            return 0;
        int res=0;
        int i=0, j, k=1;
        for(j=0; j<nums.size(); j++){
            if(nums[j]==0){
                k--;     // Delete this zero
            }
            
            while(k<0){   // If two zeroes are deleted
                if(nums[i]==0)
                    k++;
                i++;    // Move i to the next zero
            }
           res = max(j-i, res);
            
        }
        
        return res;
    }
};
