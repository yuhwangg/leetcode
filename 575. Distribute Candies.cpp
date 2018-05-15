/* Given an integer array with even length, where different numbers in this array represent different 
kinds of candies. Each number means one candy of the corresponding kind. You need to distribute these 
candies equally in number to brother and sister. Return the maximum number of kinds of candies the 
sister could gain.

Example 1:
Input: candies = [1,1,2,2,3,3]
Output: 3
Explanation: There are three different kinds of candies (1, 2 and 3), and two candies for each kind.
Optimal distribution: The sister has candies [1,2,3] and the brother has candies [1,2,3], too. 
The sister has three different kinds of candies. 

Example 2:
Input: candies = [1,1,2,3]
Output: 2
Explanation: For example, the sister has candies [2,3] and the brother has candies [1,1]. 
The sister has two different kinds of candies, the brother has only one kind of candies. 
*/

/*
Set - O(n) time, O(n) space
We can use a set to count all unique kinds of candies, but even all candies are unique, 
the sister cannot get more than half.
*/


class Solution {
public:
    int distributeCandies(vector<int>& candies) {
        unordered_set<int> kinds;
        for (int candy : candies){
            kinds.insert(candy);
        }
        return min(kinds.size(), candies.size()/2);
        
    }
};





