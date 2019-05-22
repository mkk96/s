#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int main()
{
	float basic[3][4]={2.4,1.05,2.5,.38,
						3.0,1.12,2.5,.35,
						3.6,1.2,2.5,.32
					};
	float intermediate[3][4]={3.2,1.05,2.5,.38,
							3.0,1.12,2.5,.35,
							2.8,1.2,2.5,.32
							};
	int kline;
	float Eb,Db,SSb,Pb;
	float Ei,Di,SSi,Pi;
	printf("Enter no. of line\t");
	scanf("%d",&kline);
	if(kline<50)
	{
		Eb=basic[0][0]*(pow(kline,basic[0][1]));
		Db=basic[0][2]*(pow(Eb,basic[0][3]));
		SSb=Eb/Db;
		Pb=kline/Eb;
		Ei=intermediate[0][0]*(pow(kline,intermediate[0][1]));
		Di=intermediate[0][2]*(pow(Ei,intermediate[0][3]));
		SSi=Ei/Di;
		Pi=kline/Ei;
	}
	else if(kline<300)
	{
		Eb=basic[1][0]*(pow(kline,basic[1][1]));
		Db=basic[1][2]*(pow(Eb,basic[1][3]));
		SSb=Eb/Db;
		Pb=kline/Eb;
		Ei=intermediate[1][0]*(pow(kline,intermediate[1][1]));
		Di=intermediate[1][2]*(pow(Ei,intermediate[1][3]));
		SSi=Ei/Di;
		Pi=kline/Ei;
	}
	else
	{
		Eb=basic[2][0]*(pow(kline,basic[2][1]));
		Db=basic[2][2]*(pow(Eb,basic[2][3]));
		SSb=Eb/Db;
		Pb=kline/Eb;
		Ei=intermediate[2][0]*(pow(kline,intermediate[2][1]));
		Di=intermediate[2][2]*(pow(Ei,intermediate[2][3]));
		SSi=Ei/Di;
		Pi=kline/Ei;
	}
	printf("Basic Cocomo\n");
	printf("Effort\t%f PM\n",Eb);
	printf("Development time\t%f M\n",Db);
	printf("Average Staff Size\t%f Persons\n",SSb);
	printf("Productivity\t%f KLOC/PM\n\n\n",Pb);
	printf("intermediate Cocomo\n");
	printf("Effort\t%f PM\n",Eb);
	printf("Development time\t%f DB\n",Db);
	printf("Average Staff Size\t%f Persons\n",SSi);
	printf("Productivity\t%f KLOC/PM\n",Pi);

	return 0;
}
