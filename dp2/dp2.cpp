#include <iostream>

using namespace std;

int main()
{
	int n, inputArray[1000], dp[1000];

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inputArray[i];
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++)
			if (inputArray[i] % inputArray[j] == 0 && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
	}
	int ans = 0;
	for (int i = 0; i < n; i++)
		ans = max(ans, dp[i]);
	cout << ans;
}
