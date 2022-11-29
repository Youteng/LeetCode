<center><h1>First Missing Positive</h1></center>

### Introduction
A unsorted vector `nums` is given, the first missing positive int should be returned.  
The time complexity can be optimized to O(n) and uses extra constant space.

Examples:
```cpp
nums = [1,2,0]
output: 3
```

```cpp
nums = [3,4,-1,1]
output: 2
```

```cpp
nums = [7,8,9,11,12]
output: 1
```

A easy and an optimized methods are provided.

### Method
Before starting to solve this problem, an important point should be focused:
> The possible answer is [1..len+1] where `len` is the length of provided vector.  

A easy solution with both time and space complexity are O(n) is that using a hash map to memorize the frequency of each possible number.  

<div style="text-align:center">
    <img src = https://hackmd.io/_uploads/B1uKlymvs.png></div>
    
The answer will be the first key with a 0 frequency.

### Code
```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map <int, bool> map;
        
        for(auto &num : nums)
        {
            if(num > 0 && num <= nums.size())
            {
                map[num] = true;
            }
        }
        
        for(int i = 1; i <= nums.size() + 1; i++)
        {
            if(!map[i])
            {
                return i;
            }
        }
        
        return -1;
    }
};
```

### Optimizaton
The extra hash map can't be used per the definition of constant space, but we can change it to use the index as the key:

<div style="text-align:center">
    <img src = https://hackmd.io/_uploads/SyqSsJ7vo.png></div>

To achieve that, things shold be done:
1. The possible numbers can be kept in the vector, others will be reset to 0.
2. Add `len + 1` to the values located on the indexes that indicate appeared numbers.
3. Dividing all the values by `len + 1`, then the first index that contains the value with a 0 quotient is the answer. 
4. Return `len + 1` if all the quotients bigger than 0.

```cpp
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        //push 0 to the end of vector first to avoid corner cases.
        nums.push_back(0); 
        int len = nums.size();
        
        //1.
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] < 0 || nums[i] >= nums.size())
            {
                nums[i] = 0;
            }
        }
        
        //2.
        for(int i = 0; i < nums.size(); i++)
        {
            if(nums[i] != 0)
            {
                nums[nums[i] % len] += len;
            }
        }
        
        //3.
        for(int i = 1; i < nums.size(); i++)
        {
            if(nums[i] / len == 0)
            {
                return i;
            }
        }
        
        //4.
        return len;
    }
};
```

### Optimized Code



###### tags: `Leetcode`