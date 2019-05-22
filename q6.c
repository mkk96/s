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
	int kline,i;
	float Eb,Db;
	float Ei,Di,cost,EAF=1;
	printf("Enter no. of line\t");
	scanf("%d",&kline);
	printf("Enter 4 Cost Driver\n");
	for(i=0;i<4;i++)
	{
		scanf("%f",&cost);
		EAF=EAF*cost;
	}
	if(kline<50)
	{
		Eb=basic[0][0]*(pow(kline,basic[0][1]))*EAF;
		Db=basic[0][2]*(pow(Eb,basic[0][3]));
		Ei=intermediate[0][0]*(pow(kline,intermediate[0][1]))*EAF;
		Di=intermediate[0][2]*(pow(Ei,intermediate[0][3]));
	}
	else if(kline<300)
	{
		Eb=basic[1][0]*(pow(kline,basic[1][1]))*EAF;
		Db=basic[1][2]*(pow(Eb,basic[1][3]));
		Ei=intermediate[1][0]*(pow(kline,intermediate[1][1]))*EAF;
		Di=intermediate[1][2]*(pow(Ei,intermediate[1][3]));
	}
	else
	{
		Eb=basic[2][0]*(pow(kline,basic[2][1]))*EAF;
		Db=basic[2][2]*(pow(Eb,basic[2][3]));
		Ei=intermediate[2][0]*(pow(kline,intermediate[2][1]))*EAF;
		Di=intermediate[2][2]*(pow(Ei,intermediate[2][3]));
	}
	float up[6][5]={.06,.16,.26,.42,.16,
					.06,.16,.24,.38,.22,
					.07,.17,.25,.33,.25,
					.07,.17,.24,.31,.28,
					.08,.18,.25,.26,.31,
					.08,.18,.24,.24,.34
				};
	float tp[6][5]={.01,.19,.24,.39,.18,
					.12,.19,.21,.34,.26,
					.02,.26,.21,.27,.26,
					.22,.27,.19,.25,.29,
					.36,.36,.18,.18,.28,
					.04,.38,.16,.16,.03
					};
	float a[4],b[4];
	if(kline<32)
	{
		for(i=0;i<4;i++)
		{
			a[i]=up[0][i+1]*Ei;
			b[i]=tp[0][i+1]*Di;
		}
	}
	else if(kline<128)
	{
		for(i=0;i<4;i++)
		{
			a[i]=up[1][i+1]*Ei;
			b[i]=tp[1][i+1]*Di;
		}
	}
	else if(kline<320)
	{
		for(i=0;i<4;i++)
		{
			a[i]=up[3][i+1]*Ei;
			b[i]=tp[3][i+1]*Di;
		}
	}
	else
	{
		for(i=0;i<4;i++)
		{
			a[i]=up[5][i+1]*Ei;
			b[i]=tp[5][i+1]*Di;
		}
	}
	printf("Effort\t%f\n",Ei);
	printf("Development\t%f\n\n",Di);
	printf("Phase Wise effort Distribution\n");
	printf("System Design\t%f\n",a[0]);
	printf("Detailed Design\t%f\n",a[1]);
	printf("Module Code & Test\t%f\n",a[2]);
	printf("Integration & Test\t%f\n\n",a[3]);
	printf("Phase Wise Development Time duration\n");
	printf("System Design\t%f\n",b[0]);
	printf("Detailed Design\t%f\n",b[1]);
	printf("Module Code & Test\t%f\n",b[2]);
	printf("Integration & Test\t%f\n\n",b[3]);
	return 0;
}
