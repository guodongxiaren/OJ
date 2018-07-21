leetcode
========

|#|Title|Difficulty|Remarks
|:---:|------|----|---
|1|Two Sum|Medium|`STL`: find(), distance()|
|2|Add Two Numbers|Medium|链表相加|
|26|Remove Duplicates from Sorted Array|Easy|`STL`: unique(), distance()|
|27|Remove Element|Easy|`STL`:vector::earse(), ~~remove()~~|
|31|Next Permutation|Medium|`STL`: next_permutation()|
|34|Search for a Range|Medium|`STL`: lower_bound(), upper_bound(), equal_range()|
|35|Search Insert Position|Medium|`STL`: lower_bound()|
|41|First Missing Positive|Hard|有时for循环比find_if更直观高效|
|46|Permutations|Medium|`STL`: next_permutation()|
|47|Permutations II|Medium|`STL`: next_permutation()|
|66|Plus One|Easy|`STL`: vector, reverse()|
|69|Sqrt(x)|Medium|库函数
|75|sort Colors|Medium|`STL`: sort()|
|136|Single Number|Medium|`STL`: accmulate()|
|151|Reverse Words in s String|Medium|
|162|Find Peak Element|Medium|`python` float('Inf')
|169|Mgiority Element|Easy|`STL`: sort()|
|189|Rotate Array|Easy|`STL`: rotate()|
|217|Contains Duplicate|Easy|`STL`: set|
|228|Summary Range|Easy|std::ostringstream|
|231|Power of Two|Easy|n&(n-1)==0
|242|Valid Anagram|Easy|
|258|Add Digits|Easy|有规律|
|268|Missing Number|Medium|`STL`: find_if()|
|**278**|Find Bad Version|Easy|二分。有点疑惑|
|283|Move Zeroes|Easy|`STL`: remove()|
|287|Fine the Duplicate Number|Hard|`STL`: adjacent_find()|

## HINT
### STL
- remove算法不会真是移除元素，它既不改变end()迭代器，也不改变成员函数size()的值。
（g++不会将待删除元素交换到末尾，而是只做单向复制，比如[0,1,0,3,12] 删除0是 [1,3,12,3,12]）
- next_permutation算法产出的组合不会重复。如果新的排列大于原排列则返回`true`，否则返回`false`。
- vector的构造函数中如果指定了个数，那么等同于执行的是resize而不是reserve。
- lower_bound采用的是二分查找

### 链表
- [链表相加](2.cpp)
- [反转链表](206.cpp)
- [反转部分链表](92.cpp)
