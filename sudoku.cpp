#include<iostream>
#include<cstdlib>
#include <time.h>
using namespace std;
int main(int argc ,char *argv[])
{  
    int D=atoi(argv[argc - 1]); 
	if(D>1000000||D<1)
	{	
    	cout<<"error 3"<<endl;
    	return 0;
	}
	else
	{
	cout<<"传入成功"<<endl; 
}
    srand(time(NULL)) ;
	freopen("sudoku.txt","w",stdout);
	int i,j,k,l;
	int n;      //生成数独的行数 
	int Block[3][3] ;  //先定义、初始化一个宫格的数 
    int m,a;
    int r[9]; 
    int rr[10000][9];   //存储历史数组，进行查重 
	int r_n;  
	int g=0;
	int rr_n1=0;      //查重计数变量 
	int rr_n2=0; 
	int dd;
	         
	for(i=0;i<10000;i++)
	{
		for(j=0;j<9;j++)
		rr[i][j]=0;
	 } 
	//输入生成数独数  
//	cin>>D;  
	for(dd=0;dd<D;dd++)
	{  
	cout<<endl;
	n=0 ;
	//初始化数组
	 	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			Block[i][j]=2;
//			cout<<Block[i][j]<<" ";
            r[i+j]=2;
		}
	}
    //生成一组不同且第一个数为2的随机数   	
    for(i=1;i<9;i++)
    {
    	r[i]=rand()%9+1;
    	for(j=1;j<9;j++)
    	{
    		g=(i+j)%9;
    		if(r[i]==r[g])
    		{ 			
			r[i]=rand()%9+1;
				j=0;	
			}
		} 
	}
	//将生成的一组随机数赋值给第一个宫格 
	r_n=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{		
		Block[i][j]=r[r_n]; 
		rr[dd][i+j] =r[r_n];       //将生成的随机数保存到数组rr中 
		r_n++ ;
	}
	}
for(i=0;i<dd;i++)
{
	for(j=0;j<9;j++)
	{
		if(r[j]==rr[i][j])     //若一个数相同rr_n1加1， 
		rr_n1++;		
	}
	if(rr_n1==9)              //当9个都相同，则此次生成的随机数不能使用，需要重新生成 
	rr_n2++;
	else
	rr_n1=0;
}
if(rr_n2<=1)
{
	//第一个宫格进行变化生成9x9数独 
	for(i=0;i<3;i++)
	{
		k=(i+1)%3;                      //将第一宫格的数组向上移动一行变成第二个宫格 
	    l=(i+2)%3;
		for(j=0;j<3;j++)              //将第一宫格的数组向上移动两行变成第三个宫格 
		{
			cout<<Block[i][j]<<" ";
		}
		for(j=0;j<3;j++)
		{
			cout<<Block[k][j]<<" ";
		}
		for(j=0;j<3;j++)
		{
			cout<<Block[l][j]<<" ";
		}
		cout<<endl;
		n++;
		if(i==2)
		{
			if(n==3||n==6)               //第4-6行是通过第1-3行进行向左移动一列生成的 
			{
		    	for(i=0;i<3;i++)          //第7-9行是通过第1-3行进行向左移动两列列生成的 
			    {
				a=Block[i][0];          //暂存第一列的数 
			       for(j=0;j<3;j++)
			       {	       	
			       	m=(j+1)%3;
				   Block[i][j]=Block[i][m];     
			       }
			    Block[i][2]=a;
			    
			    }
				i=-1;
			}
		}
	}
	}
	else 
	dd--;
}
	return 0;
	

}
