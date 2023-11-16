
// Multi x na cifru
string& mOne(const string& a, const char& b)
{
		static string result;
		result = "";
		int digit = b - '0';
		int temp = 0;
		for (ll i = 0; a[i]; i++)
		{
				temp += (a[i] - '0') * digit;
				result.push_back(temp % 10 + '0');
				temp /= 10;
		}
		if (temp)
				result.push_back(temp % 10 + '0');
		return result;
}

// Multi x na chislo
string& multX(const string& a, const string& b)
{
		static string result;
		result = mOne(a, b[0]);
	//	cout << mOne(a, b[0]) << "\n";
		if (b.length() == 1) {
				// cout << result << "\n";
				return result;
		}
	//	cout << string(b.begin() + 1, b.end()) + result << "\n";
		return result = string(b.begin() + 1, b.end()) + result;
}

string& Sum(string& a, string& b)
{
		static string result;
		result = "";

		ll i = a.length(), j = b.length();
		if (i < j)
				for (; i < j; ++i)
						a.push_back('0');
		else if (j < i)
				for (; j < i; ++j)
						b.push_back('0');

		ll temp = 0;
		for (i = 0; i < j; i++)
		{
				temp += a[i] + b[i] - 2 * '0';
				result.push_back(temp % 10 + '0');
				temp /= 10;
		}

		if (temp)
				result.push_back(temp % 10 + '0');

		return result;
}


string& Multi(string& a, string& b)
{
		static string result;
		result = "";

		if (a.length() < b.length())
				swap(a, b);

		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());

		for (ll i = 0; i < b.length(); i++)
		{
				string tmp(&b[i], 1);
				// cout << tmp;
				for (ll j = 0; j < i; j++)
						tmp.push_back('0');
	//			cout << tmp << "\n";
				result = Sum(multX(a, tmp), result);
		}

		reverse(result.begin(), result.end());
		return result;
}