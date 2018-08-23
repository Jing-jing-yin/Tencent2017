/*删去最少的字母使字符串变成回文*/
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int max(int a, int b)
{
	return a > b ? a : b;
}
int main()
{
	int n;
	string s;
	cin >> s;
	string s1 = s;
	reverse(s.begin(), s.end());
	n = s.length();
	//cout << " s.length: " << s.length() << " s1.length" << s1.length() << endl;
	vector<vector<int>> memo = vector<vector<int>>(n, vector<int>(n, 0)); //n行n+1列
	memo[0][0] = s[0] == s1[0] ? 1 : 0;
	for (int i = 1; i < n; i++)
	{
		memo[i][0] = max(memo[i - 1][0], s[i] == s1[0] ? 1 : 0);
		memo[0][i] = max(memo[0][i - 1], s[0] == s1[i] ? 1 : 0);
	}
	for (int j = 1; j < n; j++)
	{
		for (int i = 1; i < n; i++)
		{
			if (s[i] == s1[j])
			{
				memo[i][j] = memo[i - 1][j - 1] + 1;
			}
			else
				memo[i][j] = max(memo[i - 1][j], memo[i][j - 1]);
		}
	}

	cout << n - memo[n - 1][n - 1] << endl;
	system("pause");
	return 0;
}

/*在不申请额外的空间的情况下把大写字母放在字符串的后面，且相对位置不变*/
#include <iostream>
#include <vector>
#include<string>
using namespace std;
int main() {
	string s;
	while (cin >> s)
	{
		int l = s.length();
		vector<bool> mem(l, 1);
		for (int i = 0; i < l; i++)
		{
			if (s[i] >= 97 && s[i] <= 122)
			{
				cout << s[i];
				mem[i] = 0;
			}
		}
		for (int i = 0; i < l; i++)
		{
			if (mem[i])
				cout << s[i];
		}
		cout << endl;
	}
	system("pause");
	return 0;
}

/*有趣的数字*/
#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int main()
{
	int n;
	while (cin >> n)
	{
		if (n == 1)
		{
			cout << 0 << " " << endl;
		}
		else
		{
			vector<int> v;
			int t;
			for (int i = 0; i < n; i++)
			{
				cin >> t;
				v.push_back(t);
			}
			map<int, int> m;
			for (int i = 0; i < n; i++)
			{
				if (m.find(v[i]) == m.end())
					m[v[i]] = 1;
				else
					m[v[i]]++;
			}
			if (m[v[0]] == n)
				cout << n*(n - 1) / 2 << " " << n*(n - 1) / 2 << endl;
			sort(v.begin(), v.end());
			int min;
			min = v[1] - v[0];
			for (int i = 1; i < n - 1; i++)
			{
				if (min > v[i + 1] - v[i])
					min = v[i + 1] - v[i];
			}
			int mi = 0;
			if (m.size() == n)
			{
				for (int i = 0; i < n - 1; i++)
				{
					if (min == v[i + 1] - v[i])
						mi++;
				}
			}
			else
			{
				auto it = m.begin();
				for (it; it != m.end(); it++)
				{
					if (it->second > 1)
						mi += (it->second)*(it->second - 1) / 2;
				}
			}
			int ma;
			ma = m[v[0]] * m[v[n - 1]];
			cout << mi << " " << ma << endl;
		}
	}
	return 0;
}