#include "GetAverScore.h"
float GetAverScore(int score[],int n)
{
	int sum = 0;
	int i;
	float ave;
	for(i = 0;i < n;i++)
	{
		sum += score[i];
	}
	ave = sum * 1.0 / n;
	return ave;
}
