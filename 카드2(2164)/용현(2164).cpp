#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cout.tie(NULL);
	cin.tie(NULL);

	int N;
	cin >> N;

	queue<int> Cards;

	for (int ix = 1; ix <= N; ++ix)
	{
		Cards.push(ix);
	}

	while (Cards.size() > 2)
	{
		Cards.pop();
		Cards.push(Cards.front());
		Cards.pop();
	}

	if (Cards.size() == 2)
	{
		Cards.pop();
	}

	cout << Cards.front();
	
	return 0;
}
