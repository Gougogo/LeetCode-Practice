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

	//��n-2��ʼ����Ϊ����������
	for (i = n - 2; i >= 0; i--)
	{
		if (s[i] == '(')
		{
			//i+1����һ���Ƿ���)����Ϊ��index�ķ�����(
			//֮����Ҫ+dp[i+1],����"(()())",�����ڵ�һ�����ŵ�ʱ��,ʵ������Ҫ�������������Ƿ���),��ô����Ҫ���±�����
			//�����ɶ�ʱ��max�ᱻ+2������dp[i+1]��Ե���(()���֣�����ǵ�һ��(������һ��Ҳ��(�����(��dpֵΪ�Ѿ��е�()��
			//����((()()())���֣����һ������dpֵʱ��j��Խ����
			j = i + 1 + dp[i + 1];
			if (j<n && s[j] == ')')
			{
				
				dp[i] = dp[i + 1] + 2;
				//j+1��((()()())�������һ��(��dpֵʱ��j+1=13 �����˷�Χ
				//�����<n���ǽ������Ѿ����������dpֵȫ����������������()()())�е�һ�����������������ʱ��Ӧ�üӵ�
				if (j + 1<n)
					dp[i] += dp[j + 1];
			}
			else
				cout << "InValid at " << i + 1 << endl;
		}

		//���Ǵ���()()((()()())ǰ���������Ȼ��һ���͵�������dp��ֵ����ֵ��С��֮ǰ�����8����������dpֵ����֮ǰ��8
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
