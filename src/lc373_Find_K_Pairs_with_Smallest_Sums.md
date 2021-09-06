Input: nums1 = [1,7,11], nums2 = [2,4,6], k = 3
Output: [[1,2],[1,4],[1,6]]

思路1:
把输入看成是一个二维矩阵, 使用优先队列(priority_queue)解决。
```
    2      4      6
1 [1,2] ,[1,4] ,[1,6]

7 [2,2] ,[2,4] ,[2,6]

11[11,2],[11,4],[11,6]
```

思路2:采用二分法