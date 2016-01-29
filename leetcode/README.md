leetcode
========
|#|Title|Difficulty|Remarks
|:---:|------|----|---
|26|Remove Duplicates from Sorted Array|Easy|`STL`: unique(), distance()|
|27|Remove Element|Easy|`STL`:vector::earse(), ~remove~|
|66|Plus One|Easy|`STL`: vector, reverse()|
|69|Sqrt(x)|Medium|库函数
|151|Reverse Words in s String|Medium|
|162|Find Peak Element|Medium|`python` float('Inf')
|217|Contains Duplicate|Easy|`STL`: set|
|231|Power of Two|Easy|n&(n-1)==0
|242|Valid Anagram|Easy|
|283|Move Zeroes|Easy|`STL`: remove()|

##HIT
###STL
- remove算法不会真是移除元素，它既不改变end()迭代器，也不改变成员函数size()的值。
（g++不会将待删除元素交换到末尾，而是只做单向复制，比如[0,1,0,3,12] 删除0是 [1,3,12,3,12]）
