namespace _1._Two_Sum
{
    public class Solution
    {
        public int[] TwoSum(int[] nums, int target)
        {
            int len = nums.Length;
            for (int i = 0; i < len; ++i)
            {
                int target_2 = target - nums[i];
                for (int j = i + 1; j < len; ++j)
                {
                    if (nums[j] == target_2)
                    {
                        return new int[] { i, j };
                    }
                }
            }

            return new int[] { 0, 0 };
        }
    }

    internal class Program
    {
        static void Main(string[] args)
        {
            int[] nums = new int[] { 1, 2, 3 };
            int target = 3;
            int[] result = new Solution().TwoSum(nums, target);
            Console.WriteLine(result[0] + " " + result[1]);  
        }
    }
}