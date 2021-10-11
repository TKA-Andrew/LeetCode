/**
 * @param {number[]} nums
 * @return {number}
 */

// EXPLANATION
/*
    NOTE THAT: this is explained using Javascript Object(), but when comes to code implementation, please use Javascript Map() for better performance

    let's say our input is [2,4,6,8,10]

    Concept: Any 2 numbers (as long as they are different) can form a WEAK arithmetic subsequences.
        For example:
            - 4 and 2 is a weak arithmetic subsequence with difference of 2
            - 6 and 2 is a weak arithemtic subsequence with difference of 4
            - 8 and 2 is a weak arithemtic subsequence with difference of 6
            - 10 and 2 is a weak arithmetic subsequence with difference of 8
            - 6 and 4 is a weak arithmetic subseqeunce with difference of 2 
            - 10 and 8 is a weak arithmetic subseqeunce with difference of 2 ... etc

    Concept: For every arithmetic subsequences (including weak one), if we found the subsequent number that belongs 
    to the sequence, the number of weak arithmetic subsequences WITH SAME DIFFERENCE will plus 1
        For example:
            - If we have a arithmetic subsequence [2,6,10]
              then we 2 weak arithmetic subsequences with difference of 4: [2,6] and [6,10]
            - If we found the next number that belongs to the subsequence, it will become [2,6,10.14].
              then we have 3 weak arithmetic subsequences with difference of 4: [2,6], [6,10], [10,14]
            - If we found the next number that belongs to the subsequence, it will become [2,6,10.14,18].
              then we have 4 weak arithmetic subsequences with difference of 4: [2,6], [6,10], [10,14], [14,18]
        
    STEPS
    1)  Initialize a variable to store the total number of arithmetic subsequences
            let total = 0;
    
    2)  Initialize a dp varibale to store the total number of weak arithmetic found at each index 'i', for each 'difference'
            let dp = new Array(nums.length).fill().map(()=> new Object());
        
        We will get >>>> dp = [ {}, {}, {}, {}, {} ]

    3)  Do 2 for loops in such way:
            for (let i=1; i<nums.length; i++) {
                for (let j=0; j<i; j++) {
                }
            }
        so that:
        i) we skips i = 0 because one number is not enough to form weak arithmetic subsequence
        ii) we go from left to right
        iii) and then slowly updates the number of weak arithmetic subsequence found for each difference up until the index i

        Examples to demonstrate the meaning of dp[i][difference]:
            - Let's say our input is [2,4,6,8,10]
            - We will have dp[1][2] = 1
                means from index i = 0 to i = 1, we have 1 weak arithmetic subsequences with difference of 2, which is [2,4]
            - We will have dp[2][4] = 1
                means from index i = 0 to i = 2, we have 1 weak arithmetic subsequences with difference of 4, which is [2,6]
            - We will have dp[2][2] = 2
                means from index i = 0 to i = 2, we have 2 weak arithmetic subsequences with difference of 2, which is [2,4] and [4,6]
    
    4)  In each nested loop, we get the difference between the nums[i] and nums[j]:
            const difference = nums[i] - nums[j]

    5)  In each nested loop, we initiliaze dp[i][difference] to 0 if it is undefined
            if (dp[i][difference] === undefined) {
                dp[i][difference] = 0;
            }

    6)  In each nested loop,  
            if (dp[j][difference]) {
                dp[i][difference] += dp[j][difference] + 1
                total += dp[j][difference]                
            } else {
                dp[i][difference] += 1
            }
        
        The adding of one is because as we said earlier, every time we found one more number with the same difference, 
        it adds one more weak arithmetic subsequence to the previously found one. 
            For example:
                - When we have [2,4,6], we have 2 weak arithmetic subsequences with difference of 2, which are [2,4] and [4,6]
                - When we found the subsequent number to the sequence, the sequence will become [2,4,6,8]
                - Then with [2,4,6,8] we will have 3 weak arithmetic subsequences with difference of 2, which are [2,4], [4,6] and [6,8]
        
        For the equation of 'total', let's look at the following example:
            - Let's say we focus on arithmetic subsequence with difference of 2 only
            - Initially 
                totalArithmeticSubsequenceWithDifference2Only = 0
            - when i = 1, we have [2,4]. so we have one weak arithmetic subsequence with difference of 2
                dp[1][2] = 1
            - When we add the next number into the sequence, we have [2,4,6], and this can form one arithmetic subsequence
                totalArithmeticSubsequenceWithDifference2Only = 1
            - So, now [2,4,6] have 2 weak arithmetic subsequences with difference of 2, which are [2,4] and [4,6]
                dp[2][2] = 2
            - When we add the next number into the sequence, we have [2,4,6,8], and this can form 3 arithmethic subsequences
              with difference of 2, which are [2,4,6], [4,6,8] and [2,4,6,8]
                totalArithmeticSubsequenceWithDifference2Only = 3
            - So, now [2,4,6,8] have 3 weak arithmetic subsequences with difference of 2, which are [2,4], [4,6] and [6,8]
                dp[3][2] = 3
            - When we add the next number into the sequence, we have [2,4,6,8,10], and this can form 6 arithmethic subsequences
              with difference of 2, which are [2,4,6], [4,6,8], [2,4,6,8], [6,8,10], [4,6,8,10], [2,4,6,8,10]
                totalArithmeticSubsequenceWithDifference2Only = 6
            - Hence, the total arithmetic subsequences of a specific difference is based on the dp[j][difference]
            - Therefore, total += dp[j][difference]
        
        NOTE: The above explanation is my personal understanding, you may refer to other references for better explanations.
*/

// Javascript Object() implementation
// modified from: https://www.cxyzjd.com/article/dai_qingyun/88054114
const numberOfArithmeticSlices_usingJavacriptObject = function(nums) {
    let total = 0
    let dp = new Array(nums.length).fill().map(()=> new Object()); // dp[i][difference]
    // dp = [ {}, {}, {}, {}, {} ......]
    for (let i=1; i<nums.length; i++) {
        for (let j=0; j<i; j++) {
            const difference = nums[i] - nums[j]
            if (dp[i][difference] === undefined) {
                dp[i][difference] = 0
            }
            if (dp[j][difference]) {
                dp[i][difference] += dp[j][difference] + 1
                total += dp[j][difference]   
            } else {
                dp[i][difference] += 1
            }
        }
    }
    return total
};

// Javascript Map() Implementation
// credit to: https://www.cxyzjd.com/article/dai_qingyun/88054114
const numberOfArithmeticSlices = function(nums) {
    let ans = 0
    const dp = new Array(nums.length).fill(0).map(() => new Map())
    for (let i = 1; i < nums.length; i++) {
      for (let j = 0; j < i; j++) {
        const difference = nums[i] - nums[j]
        dp[i].set(difference, (dp[i].get(difference) || 0) + 1) // similar to d[i][difference] ++ with default 0 if undefined
        if (dp[j].get(difference)) {
          dp[i].set(difference, dp[i].get(difference) + dp[j].get(difference))
          ans += dp[j].get(difference)
        }
      }  
    }
    return ans
  }