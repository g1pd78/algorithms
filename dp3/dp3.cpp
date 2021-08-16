#include <iostream>
#include <vector>

using namespace std;

int main()
{
	int n, inputArray[100000], dp[100000];
	vector<int> ans;

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> inputArray[i];
	for (int i = 0; i < n; i++) {
		dp[i] = 1;
		for (int j = 0; j < i; j++) {
			if (inputArray[j] >= inputArray[i] && dp[j] + 1 > dp[i])
				dp[i] = dp[j] + 1;
		}
	}
	int maxCount = 0, maxPos = 0;
	for (int i = 0; i < n; i++)
		if(maxCount < dp[i]){
			maxCount = dp[i];
			maxPos = i;
		}
	cout << maxCount << '\n';
	for (int i = n - 1; i >= 0; i--) {
		if (dp[i] == maxCount && inputArray[i] >= inputArray[maxPos]) {
			maxCount--;
			maxPos = i;
			ans.push_back(i);
		}
	}
	for (int i = ans.size() - 1; i >= 0; i--)
		cout << ans[i] + 1 << ' ';
}
