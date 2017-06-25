#include "GetAverScore.h"
#include "GetAverScore.h"

int main()
{
	int score[5],sum;
	printf("请输入五位学生的成绩：");
	int i;
	float ave;
	for(i = 0;i < 5;i++)
	{
		printf("请输入第%d位学生的成绩：\n",i+1);
		scanf("%d",&score[i]);
	}

	sum = GetTotalScore(score,5);

	ave = GetAverScore(score,5);

	printf("平均成绩%f\n总成绩%d\n", ave,sum);
	return 0;
}