#include<stdio.h>
struct file
{
	int all[10];
	int max[10];
	int need[10];
	int flag;
};
int main()
{
	struct file f[10];
	int fl;
	int i,j,k,p,b,n,r,g,cnt=0,id,newr;
	int avail[10],seq[10];
	//clrscr();
	printf("number of processes");
	scanf("%d",&n);
	printf("number of resorses");
	scanf("%d",&r);
	for(i=0;i<n;i++)
	{
		printf("enter the details of p %d",i);
		printf("enter allocation");
		for(i=0;i<r;i++)
		{
			scanf("%d",&f[i].all[j]);
		}
		printf("enter the max\n");
		for(j=0;j<r;j++)
		{
			scanf("%d",&f[i].max[j]);
		}
		f[i].flag=0;
	}
	printf("enter the available resources");
	for(i=0;i<r;i++)
	{
		scanf("%d",&avail[i]);
	}
	printf("\n enter new request details");
	printf("\n enter the process number");
	printf("enter the resource ");
	for(i=0;i<r;i++)
	{
		scanf("%d",&newr);
		f[id].all[i]+=newr;
		avail[i]=avail[i]-newr;
	}
	for(i=0;i<n;i++)
	{
		for(j=0;j<r;j++)
		{
			f[i].need[j]=f[i].max[j]-f[i].all[j];
			if(f[i].need[j]<0)
			f[i].need[j]=0;
			
		}
	}
	cnt=0;
	fl=0;
	while(cnt!=n)
	{
		g=0;
		for(j=0;j<n;j++)
		{
			if(f[i].flag==0)
			{
				b=0;
				for(p=0;p<r;p++)
				{
					if(avail[p]>+f[j].need[p])
					b=b+1;
					else
					b=b-1;
				}
				if(b==r)
				{
					printf("\n p %d is visited",j);
					seq[fl++]=j;
					f[i].flag=1;
					for(k=0;k<r;k++)
					avail[k]=avail[k]+f[j].all[k];
					cnt=cnt+1;
					printf("(");
					for(k=0;k<r;k++)
					printf("%3d",avail[k]);
					g=1;
				}
			}
			
		}
	if(g==0)
	{
		printf("\n request not granted");
		printf("unsafe state");
		goto y;
	}
}
printf("\n system is in sdafe state");
printf("\n safe sequence");
for(i=0;i<fl;i++)
{
	printf("p%d",seq[i]);
}
y:printf("\n process allocation max ");
for(i=0;i<n;i++)
{
	printf("p%d\t",i);
	for(j=0;j<r;j++)
	printf("%6d\t",f[i].all[j]);
	for(j=0;j<r;j++)
	printf("%6d",f[i].max[j]);
	for(j=0;j<r;j++)
	printf("%6d",f[i].need[j]);
	printf("\n");
}
}
