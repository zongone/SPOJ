#include <iostream>
#include <cmath>
#include <string>

int main()
{
	std::string digits;
	std::cin >> digits;
	while (digits[0] != '0')
	{	
		if (digits.length() == 1)
		{
			std::cout << 1 << "\n";
		}
		else
		{
			long long int* dp = new long long int[digits.length()+1];
			dp[0] = 1;
			dp[1] = 1;
			for (int i = 1; i<digits.length(); i++)
			{
				if (digits[i] != '0') 
				{
					dp[i + 1] = dp[i];
				}
					
				if ( (digits[i - 1] == '1') || ((digits[i - 1] == '2') && (digits[i]<='6') && (digits[i] > '0')) )
				{
					dp[i+1] += dp[i - 1];
				}
				
				if ((digits[i] == '0') && ((digits[i - 1] == '1') || (digits[i - 1] == '2')))
				{
					dp[i + 1] = dp[i-1];
				}
				
				if ( (digits[i] == '0') && ((digits[i-1] == '0') || (digits[i - 1] > '2') ) )
				{
					dp[i + 1] = 0;
				}
			}
			std::cout << dp[digits.length()] << "\n";
			delete[] dp;
		}

		std::cin >> digits;
	}
	return 0;
}