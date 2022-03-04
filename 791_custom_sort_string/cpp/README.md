# Solution

## Normal Merge Sort

Construct a order map from the order vector. When sort the string s, use the order map as the 
comparison source.

The complexity of this method is O(nlogn)

|Time|Ratio|Space|Ratio|
|----|-----|-----|-----|
|4ms|30.52%|6.6MB|5.22%|

## O(n) insertion

I did not come up with this solution, but it is really an amazing method. Actually, when we sort an
array, we may not really compare them one by one. Sort algorithms like Bucket Sort and Radix Sort are
not comparison based algorithms. Here, we can apply the idea of Bucket Sort to the problem. We only have
at most 26 different letters. The order vector is just like a bucket. We traverse the string and move all
the letters to the corresponding bucket. Finally, we construct the result sorted string.

The complexity of this method is O(n)