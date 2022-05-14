#include <iostream>
#include <vector>
#include <filesystem>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
	int N, K;
	cin >> N >> K;
	vector <int> v(N);
	vector <int> w(N);
	for (int i = 0; i < N; i++)
	{
		cin >> v[i] >> w[i];
	}
	//v - ценность; w -  масса
	for (int i = 0; i < N-1; i++)
	{
		for (int i = 0; i < N-1; i++)
		{
			if (v[i + 1] > v[i])
			{
				swap(v[i], v[i + 1]);
				swap(w[i], w[i + 1]);
			}
		}
	}
	for (int i = 0; i < N-1; i++)
	{
		if ((v[i + 1] == v[i]) && (w[i + 1] < w[i]))
		{
			swap(v[i], v[i + 1]);
			swap(w[i], w[i + 1]);
		}
	}

	int T = 0;
	int V = 0;
	int j = 0;
	for (int i = 0; i < N; i++)
	{ 
		if (T + w[i]<= K)
		{
			T = T + w[i];
			V = V + v[i];
		}
	}
	cout << V;
}
