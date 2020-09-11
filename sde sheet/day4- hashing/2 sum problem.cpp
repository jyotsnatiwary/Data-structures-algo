//2 sum problem

/*Array = [3,4,8,6,7]

Target = 9

Steps:

Create a hash map and start iterating through the Array.

Check for first element 3, since no value is associated with (9-3=)6 in the map so insert (3,0) in the map.

Check for 4 , since no value is associated with 5 so insert (4,1) in the map.

Check for 8, since no value is associated with 1 so insert (8,2) in the map.

Check for 6, this time a value associated with 3 exist so return the index of 6 and value associated with 3 which is the index of integer 3.

Output: [0, 3]

Note: We are using map to link integer with index as it given the same element does not appear twice.*/

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        vector<int> v;
        for(int i=0;i<nums.size();i++)
        {
            if(m.find(target-nums[i])!=m.end())
            {
                v.push_back(m[target-nums[i]]);
                v.push_back(i);
                return v;
            }
            m[nums[i]]=i;
        }
        return v;
    }
};
