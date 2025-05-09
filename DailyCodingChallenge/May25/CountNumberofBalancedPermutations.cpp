#include<bits/stdc++.h>
using namespace std;

int countBalancedPermutations(string num) {
  vector<int> nums = getNums(num);
  int sum = accumulate(nums.begin(), nums.end(), 0);
  if (sum % 2 == 1)
      return 0;

  ranges::sort(nums, greater<>());

  int even = (nums.size() + 1) / 2;
  int odd = nums.size() / 2;
  int evenBalance = sum / 2;
  vector<vector<vector<long>>> mem(
      even + 1,
      vector<vector<long>>(odd + 1, vector<long>(evenBalance + 1, -1)));
  long perm = getPerm(nums);
  return countBalancedPermutations(nums, even, odd, evenBalance, mem) *
         modInverse(perm) % kMod;
}

int kMod = 1'000'000'007;

long countBalancedPermutations(vector<int>& nums, int even, int odd,
                             int evenBalance,
                             vector<vector<vector<long>>>& mem) {
  if (evenBalance < 0)
      return 0;
  if (even == 0)
      return evenBalance == 0 ? factorial(odd) : 0;
  int index = nums.size() - (even + odd);
  if (odd == 0) {
      long remainingSum = 0;
      for (int i = index; i < nums.size(); ++i)
          remainingSum += nums[i];
      return (remainingSum == evenBalance) ? factorial(even) : 0;
  }
  if (mem[even][odd][evenBalance] != -1)
      return mem[even][odd][evenBalance];
  long placeEven =
      countBalancedPermutations(nums, even - 1, odd,
                                evenBalance - nums[index], mem) *
      even % kMod;
  long placeOdd =
      countBalancedPermutations(nums, even, odd - 1, evenBalance, mem) *
      odd % kMod;
  return mem[even][odd][evenBalance] = (placeEven + placeOdd) % kMod;
}

vector<int> getNums(const string& num) {
  vector<int> nums;
  for (char c : num)
      nums.push_back(c - '0');
  return nums;
}

long getPerm(vector<int>& nums) {
  long res = 1;
  vector<int> count(10);
  for (int num : nums)
      ++count[num];
  for (int freq : count)
      res = res * factorial(freq) % kMod;
  return res;
}

long factorial(int n) {
  long res = 1;
  for (int i = 2; i <= n; ++i)
      res = res * i % kMod;
  return res;
}

long modInverse(long a) {
  long m = kMod;
  long y = 0;
  long x = 1;
  while (a > 1) {
      long q = a / m;
      long t = m;
      m = a % m;
      a = t;
      t = y;
      y = x - q * y;
      x = t;
  }
  return x < 0 ? x + kMod : x;
}

int main()
{
  string num = "123321";
  int result = countBalancedPermutations(num);
  cout << "Number of balanced permutations: " << result << endl;

  return 0;
}