void mastermind(const int *solution, const int *guess, char *result, unsigned int len)
{
	int i;
	for (i = 0; i < len; i++)
	{
		if(guess[i]==solution[i])
		{
			result[i]='+';
			continue;
		}
		else
		{
		int j;
		for (j = 0; j<len; j++)
		{
			if ((i != j) && (guess[i] == solution[j]))
			{
				result[i] = '*';
				continue;
			}
			else if (guess[i] != solution[j])
			{
				continue;
			}
		}
		if ((j == len) && (result[i] != '+') && (result[i] != '*'))
		
			result[i] = '-';
		}
	} 
}
