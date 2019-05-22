#include<stdio.h>
#include<stdlib.h>
int main()
{
	int w[5][3] = {3,4,6,
                   4,5,7,
                   3,4,6,
                   7,10,15,
                   5,7,10};
    int z[5],x[5],f[14],i;
    float temp=0,caf,upf=0,fp;
    printf("Enter User Inputs & its complexity factor:\t");
    scanf("%d%d",&z[0],&x[0]);
	printf("Enter User Output & its complexity factor  :\t");
    scanf("%d%d",&z[1],&x[1]);
    printf("Enter User Inquires & its complexity factor :\t");
    scanf("%d%d",&z[2],&x[2]);
    printf("Enter Logical Files & its complexity factor:\t");
    scanf("%d%d",&z[3],&x[3]);
    printf("Enter Interface files & its complexity factor :\t");
    scanf("%d%d",&z[4],&x[4]);
    printf("Enter 14 factors in order :: \n");
    for(i=0;i<14;i++)
    {
    	scanf("%d",&f[i]);
    	temp=temp+f[i];
	}
	for(i=0;i<5;i++)
	{
		upf=upf+z[i]*w[i][x[i]];
	}
	caf=.65+.01*temp;
	fp=caf*upf;
	printf("UPF\t%f\n",upf);
	printf("CAF\t%f\n",caf);
	printf("FP\t%f",fp);
	return 0;
}
