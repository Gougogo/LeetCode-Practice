#include <stdio.h>
#include <string.h>
#include <iostream>
using namespace std;
#define N 65536
int longestValidParentheses(const char *s)
{
	int i, j, n;
	int dp[N];
	int max = 0;
	n = strlen(s);
	for (i = 0; i<N; i++)
		dp[i] = 0;

	//从n-2开始是因为括号有两个
	for (i = n - 2; i >= 0; i--)
	{
		if (s[i] == '(')
		{
			//i+1是上一个是否是)，因为本index的符号是(
			//之所以要+dp[i+1],是如"(()())",当处于第一个符号的时候,实际上需要检测第六个符号是否是),那么就需要将下标增加
			//（）成对时，max会被+2，所以dp[i+1]针对的是(()这种，算的是第一个(，但上一个也是(，这个(的dp值为已经有的()数
			//比如((()()())这种，算第一个（的dp值时，j就越界了
			j = i + 1 + dp[i + 1];
			if (j<n && s[j] == ')')
			{
				
				dp[i] = dp[i + 1] + 2;
				//j+1是((()()())这种算第一个(的dp值时，j+1=13 超过了范围
				//而如果<n则是将后面已经计算出来的dp值全部加起来，即是算()()())中第一个，第三个，第五个时，应该加的
				if (j + 1<n)
					dp[i] += dp[j + 1];
			}
			else
				cout << "InValid at " << i + 1 << endl;
		}

		//这是处理()()((()()())前面的数，虽然第一个和第三个的dp有值，但值都小于之前计算的8，所以最大的dp值还是之前的8
		if (max <= dp[i])
			max = dp[i];
	}
	return max;
}
int main()
{
	const char *s = "()())(()()())";
	printf("%d\n", longestValidParentheses(s));
	system("pause");
	return 0;
}
