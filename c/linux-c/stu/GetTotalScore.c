#include "GetTotalScore.h"

int GetTotalScore(int score[],int n)
{
	int sum = 0;
	int i;
	for(i = 0;i < n;i++)
	{
		sum += score[i];
	}
	return sum;
	
}