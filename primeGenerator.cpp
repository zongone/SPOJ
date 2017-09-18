#include <iostream>
#include <cmath>

int main()
{
	int testNo;
	int min = 1;
	int max = 10;
	int** ranges = new int* [2];
	
	while (std::cin >> testNo)
	{
		if (testNo > 10 || testNo < 1)
		{
			std::cout << "Enter number of tests:";
			continue;
		}
		else
			break;
	}

	for (int i = 0; i < testNo; i++)
	{
		ranges[i] = new int[2];
		while (std::cin >> min >> max)
		{
			if (min < 1 || max > 1000000000 || (max - min) > 100000 || (max - min) < 0)
			{
			std::cout << "Enter proper values:";
				continue;
			}
			else
				break;
		}

		ranges[i][0] = min;
		ranges[i][1] = max;
	}

	for (int i = 0; i < testNo; i++)
	{
		for (int j = ranges[i][0]; j <= ranges[i][1]; j++)
		{
			//std::cout << j << " ";
			bool prime = true;
		//	std::cout<<(int)sqrt(j);
			int test = sqrt(j) +1;
			for (int k = 2; k < test; k++)
			{
				if (j%k == 0)
				{
					prime = false;
					break;
				}

			}

			if (prime && j!=1)
			{
				std::cout << j << "\n";
			}
		}
		std::cout << "\n";
	}


		

	return 0;
}