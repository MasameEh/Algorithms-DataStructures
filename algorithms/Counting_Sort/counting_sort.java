import java.util.Arrays;

class CountingSort
{

    public int[] sortPositiveArray(int[] nums) 
    {    
        int max = nums[0];
        int[] outputArr = new int[nums.length];

        for(int value : nums)
        {
            max = Math.max(value, max);
        }

        int[] countingArr = new int[max + 1]; 
        Arrays.fill(countingArr, 0);
   
        for(int i = 0; i < nums.length; i++)
        {
            countingArr[nums[i]]++;
        }

        for(int i = 1; i < max + 1; i++)
        {
            countingArr[i] += countingArr[i-1];
        }

        for(int i = 0; i < nums.length; i++)
        {
            int index = countingArr[nums[i]] - 1;
            outputArr[index] = nums[i];
            countingArr[nums[i]]--;;
        }
        return outputArr;
    }

    public int[] sortNegativeArray(int[] nums) 
    {
        int max = nums[0] , min = nums[0], offset = 0, n = 0;
        int[] outputArr = new int[nums.length];

        for(int value : nums)
        {
            max = Math.max(value, max);
            min = Math.max(value, min);
        }

        offset = 0 - min;
        n = max + offset + 1;
        int[] countingArr = new int[n];
        Arrays.fill(countingArr, 0);

        for(int i = 0; i < nums.length; i++)
        {
            countingArr[nums[i] + offset]++;
        }

        for(int i = 1; i < n; i++)
        {
            countingArr[i] += countingArr[i-1];
        }

        for(int i = 0; i < nums.length; i++)
        {
            int index = countingArr[nums[i] + offset] - 1;
            outputArr[index] = nums[i];
            countingArr[nums[i] + offset]--;;
        }
        return outputArr;
    }
    public static void main(String args[])
    {
        int arr[] = { 44, 1, 13, 9, 6 };
        
        CountingSort ob = new CountingSort();
        arr = ob.sortPositiveArray(arr);
        
        System.out.println(Arrays.toString(arr));
    }

}