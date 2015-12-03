#include <iostream>
#include <string>

using namespace std;

long long fact(long long n)
{
	if (n == 1)
		return 1;
	else
		return n * fact(n - 1);
}

string removeChar(string s, int id)
{
	string f = "";
	int size = s.size();
	for (int i = 0; i < size; i++)
	{
		if (i != id)
		{
			f += s[i];
		}
	}
	return f;
}

int findMinRep(int alpha[])
{
	int min_rep = 99999;
	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] != 0 && alpha[i] < min_rep)
			min_rep = alpha[i];
	}
	return min_rep;
}


long long permutation(long long n, int alpha[])
{
	n = fact(n);
	for (int i = 0; i < 26; i++)
	{
		if (alpha[i] > 1)
		{
			n /= fact(alpha[i]);
		}
	}
	return n;
}

int main()
{

	string str = "", final = "";
	long long K = 0;
	//cout << "Enter anagram and order : ";
	cin >> str;
	cin >> K;
	K--;
	while (str != "#")
	{

		long long range = 0, num_rep = -1, check = 0, rep_count = 0;
		int minrep = 0;
		char ch;
		long long fct = 0, Start = 0, End = 0, S = 0, E = 0, c = 0;
		bool rep = false, re_af = false, check_nums = false;

		int alpha[26] = { 0 };

		for (int i = 0; i < str.size(); i++)
		{
			++alpha[str[i] - 'A'];
		}

		fct = permutation(str.size(), alpha);

		Start = 0;
		End = fct;

		if (str.size() == 1)
			cout << str << endl;

		c = 0;
		while (str.size() != 1)
		{
			str = "";
			for (int i = 0; i < 26; i++)
			{
				if (alpha[i] != 0)
				{
					for (int j = 0; j < alpha[i]; j++)
					{
						str += i + 'A';
					}

					if (num_rep == -1)
					{
						num_rep = alpha[i];
						++rep_count;
					}
					else if (num_rep == alpha[i] && check == 0)
					{
						rep = true;
						++rep_count;
					}
					else
					{
						rep = false;
						check = 1;
					}
				}
			}
			check = 0;

			if (!rep)
			{
				if ((fct%str.size()) != 0)
				{
					minrep = findMinRep(alpha);
					int nums = 0;

					for (int i = 0; i < 26; i++)
					{
						if (alpha[i] != 0)
						{
							if (alpha[i] == minrep)
								nums++;
							else
							{
								nums += (alpha[i] / minrep);
							}
						}
					}

					range = fct / nums;
					check_nums = true;
				}
				else
					range = fct / str.size();
			}
				
			else
				range = fct / rep_count;

			if (range <= 0)
			{
				for (int i = 0; i < 26; i++)
				{
					if (alpha[i] != 0)
					{
						for (int j = 0; j < alpha[i]; j++)
						{
							final += (i + 'A');
						}
					}
				}
				break;
			}
			int id = 0;
			S = c;
			ch = str[id];

			do
			{
				E = S + range - 1;
				if (K >= S && K <= E)
				{
					final += str[id];
					alpha[ch - 'A']--;
					str = removeChar(str, id);
					num_rep = -1;
					rep_count = 0;
					rep = false;
					check_nums = false;
					break;
				}
				else
				{
					S = E + 1;

					if (!rep)
					{
						if (check_nums)
						{
							id += minrep;
						}
						else
							id++;
					}
						
					else
						id += num_rep;

					if (ch != str[id])
					{
						ch = str[id];
						c = S;
					}
				}
			} while (E < End);

			fct = permutation(str.size(), alpha);
		}
		if (range != 0 && str.size() == 1)
			final += str;
		//cout << endl << ": " << final << endl;
		if (range != 0)
			cout << final << endl;
		str = ""; final = "";
		K = 0;
		//cout << "Enter anagram and order : ";
		cin >> str;
		cin >> K;
		K--;
	}
	return 0;
}

