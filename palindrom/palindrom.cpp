#include <iostream>

using namespace std;



int main()
{
	string example;
	int sum_ch=0;
	int max_nech=0;
	int index_nech = -1;
	int count_nech = 0;
	int last_nech = -1;

	cin >> example;

	int alphab[256]{ 0 };
	for (int i = 0; i < example.length(); ++i)
		alphab[int(example[i])] += 1;


		for (int i = 0; i < 256; ++i)
		{
			if ((alphab[i] % 2) && (alphab[i] > max_nech))
			{
				max_nech = alphab[i];
				index_nech = i;
			}
		}

		for (int i = 0; i < 256; ++i)
		{

			if (alphab[i] % 2 && i != index_nech)
				alphab[i]--;
			sum_ch += alphab[i];
		}

		char* res = new char[sum_ch];
		int N = sum_ch;
		int max_ind = 0;
		int sred_ind = N / 2;
		bool bflag = false;

		if (index_nech != -1)
		{
			res[(N / 2)] = char(index_nech);
			alphab[index_nech] -= 1;


			int i = 1;
			while (alphab[index_nech] > 0)
			{
				bflag = true;
				res[(N / 2) - i] = char(index_nech);
				res[(N / 2) + i] = char(index_nech);
				alphab[index_nech] -= 2;
				sred_ind = i;
				++i;
			}
		}

		for (int i = 0; i < N; ++i)
		{
			if (((i == sred_ind + N / 2 || i == N / 2 - sred_ind) && bflag) || (i==N/2))
				continue;

			for (int j = 0; j < 256; ++j)
			{
				if (alphab[j] != 0 && j!=index_nech)
				{
					res[i] = char(j);
					res[N - i - 1] = char(j);
					alphab[j] -= 2;
					break;
				}
			}
		}

		for (int i = 0; i < sum_ch; ++i) {
			cout << res[i];
		}

	return 0;
}

