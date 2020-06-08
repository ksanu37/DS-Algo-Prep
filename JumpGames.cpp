#include<bits/stdc++.h>
using namespace std;

int minJump(int index, vector<int>&nums, vector<int>&res);

int main(){
	
	vector<int>nums = {2,3,1,1,4};
	vector<int>res(nums.size(),-1);
	
	/*  If we can reach the end or not */
	
	int maxReachable = 0; 
	bool canReach = true;
	for(int i=0; i<nums.size(); i++){
		if(maxReachable>=nums.size()-1){
			canReach = true;
			break;
		}
		if(maxReachable<i){
			canReach = false;
			break;
		}
		else{
			maxReachable = max(maxReachable, i+nums[i]);
		}
	}
	
	
	int last = nums.size()-1;
	
	for(int i=last; i>=0; i--){
		if(i+nums[i]>=last){  /* Can be reached from this index */
			last = i;   /* Now check if we can reach this index or not */
		}
	}
	
	canReach = last==0;
	
	
	/* Minimum Number of jumps to reach end */
	
	minJump(0, nums, res);
	
}

int minJump(int index, vector<int>&nums, vector<int>&res){
	if(index>=nums.size()-1)
		return 0;
		
	if(nums[index]==0)
		return -1;
	
	if(res[index]!=-1)
		return res[index];
		
	int minM = INT_MAX;
	
	for(int i=1; i<=nums[index]; i++){
		int temp = (i+index, nums, res);
		if(temp!=INT_MAX && temp!=-1)
			minM = min(minM, 1+temp);
	}
	
	res[index] = minM==INT_MAX?-1:minM;
	return res[index];
}


int minimumJumpDP(vector<int>&nums){
	
		if(index>=nums.size()-1)
		return 0;
		
		if(nums[index]==0)
		return -1;
		
		vector<int>res(nums.size(), INT_MAX);
		res[nums.size()-1] = 0;
		
		for(int i=n-2; i>=0; i--){
			for(int j=1; i<=nums[i]; j++){
				if(i+j>=nums.size()-1)
					res[i] = 1;
				else{
					res[i] = min(res[i], 1+res[i+j]);
				}
			}
		}
		
		return res[0];
}

int minJumpLinear(vector<int>&nums){
	int currFar = 0, int prevFar = 0, int jumps = 0;
	
	for(int i=0; i<nums.size()-1; i++){
		currFar = max(currFar, i+nums[i]);    // Maintain the farthest index that can be reached from this or previous indices
		
		if(i==prevFar){   // If we have reached a previous maintained farthest distance, it is time to jump, if prevFar>n-1  -> No further jump would occur
			jumps++;
			prevFar = currFar;
		}
	}
	
	return jumps;
}
