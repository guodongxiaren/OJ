leetcode
========
|#|Title|Difficulty|Remarks
|:---:|------|----|---
|26|Remove Duplicates from Sorted Array|Easy|`STL`: unique(), distance()|
|27|Remove Element|Easy|`STL`:vector::earse(), ~remove()~|
|41|First Missing Positive|Hard|有时for循环比find_if更直观高效|
|66|Plus One|Easy|`STL`: vector, reverse()|
|69|Sqrt(x)|Medium|库函数
|136|Single Number|Medium|`STL`: accmulate()|
|151|Reverse Words in s String|Medium|
|162|Find Peak Element|Medium|`python` float('Inf')
|217|Contains Duplicate|Easy|`STL`: set|
|231|Power of Two|Easy|n&(n-1)==0
|242|Valid Anagram|Easy|
|268|Missing Number|Medium|`STL`: find_if()|
|283|Move Zeroes|Easy|`STL`: remove()|
|287|Fine the Duplicate Number|Hard|`STL`: adjacent_find()|

##HIT
###STL
- remove算法不会真是移除元素，它既不改变end()迭代器，也不改变成员函数size()的值。
（g++不会将待删除元素交换到末尾，而是只做单向复制，比如[0,1,0,3,12] 删除0是 [1,3,12,3,12]）
