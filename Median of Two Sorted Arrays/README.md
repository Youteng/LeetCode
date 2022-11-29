<center><h1>Median of Two Sorted Arrays</h1></center>

[Leetcode Link](https://leetcode.com/problems/median-of-two-sorted-arrays/)

### Intorduce
Two sorted arrays will be provided as input for this problem, we should merge these two arrays to one, then return the median of it.<br/> And please note that, the time complexity should be optimized to O(lg(m+n)). 

### Method
The simplest method is to merge these sorted arrays with merge sort then get the median, but the time complexity won't achieve the requirement.<br/> So, we should solve this problem with some mathmatical skill:
> Fining the K-th number of the merged array, that is what we want.


### Code
```python
class Solution:
    def findMedianSortedArrays(self, A, B):
        l = len(A) + len(B)
        if l % 2 == 1:
            return self.kth(A, B, l // 2)
        else:
            return (self.kth(A, B, l // 2) + self.kth(A, B, l // 2 - 1)) / 2.   
    
    def kth(self, a, b, k):
        if not a:
            return b[k]
        if not b:
            return a[k]
        ia, ib = len(a) // 2 , len(b) // 2
        ma, mb = a[ia], b[ib]
    
        # when k is bigger than the sum of a and b's median indices 
        if ia + ib < k:
            # if a's median is bigger than b's, b's first half doesn't include k
            if ma > mb:
                return self.kth(a, b[ib + 1:], k - ib - 1)
            else:
                return self.kth(a[ia + 1:], b, k - ia - 1)
        # when k is smaller than the sum of a and b's indices
        else:
            # if a's median is bigger than b's, a's second half doesn't include k
            if ma > mb:
                return self.kth(a[:ia], b, k)
            else:
                return self.kth(a, b[:ib], k)
```

###### tags: `Leetcode`
