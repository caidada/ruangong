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
	cout<<"����ɹ�"<<endl; 
}
    srand(time(NULL)) ;
	freopen("sudoku.txt","w",stdout);
	int i,j,k,l;
	int n;      //�������������� 
	int Block[3][3] ;  //�ȶ��塢��ʼ��һ��������� 
    int m,a;
    int r[9]; 
    int rr[10000][9];   //�洢��ʷ���飬���в��� 
	int r_n;  
	int g=0;
	int rr_n1=0;      //���ؼ������� 
	int rr_n2=0; 
	int dd;
	         
	for(i=0;i<10000;i++)
	{
		for(j=0;j<9;j++)
		rr[i][j]=0;
	 } 
	//��������������  
//	cin>>D;  
	for(dd=0;dd<D;dd++)
	{  
	cout<<endl;
	n=0 ;
	//��ʼ������
	 	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			Block[i][j]=2;
//			cout<<Block[i][j]<<" ";
            r[i+j]=2;
		}
	}
    //����һ�鲻ͬ�ҵ�һ����Ϊ2�������   	
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
	//�����ɵ�һ���������ֵ����һ������ 
	r_n=0;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{		
		Block[i][j]=r[r_n]; 
		rr[dd][i+j] =r[r_n];       //�����ɵ���������浽����rr�� 
		r_n++ ;
	}
	}
for(i=0;i<dd;i++)
{
	for(j=0;j<9;j++)
	{
		if(r[j]==rr[i][j])     //��һ������ͬrr_n1��1�� 
		rr_n1++;		
	}
	if(rr_n1==9)              //��9������ͬ����˴����ɵ����������ʹ�ã���Ҫ�������� 
	rr_n2++;
	else
	rr_n1=0;
}
if(rr_n2<=1)
{
	//��һ��������б仯����9x9���� 
	for(i=0;i<3;i++)
	{
		k=(i+1)%3;                      //����һ��������������ƶ�һ�б�ɵڶ������� 
	    l=(i+2)%3;
		for(j=0;j<3;j++)              //����һ��������������ƶ����б�ɵ��������� 
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
			if(n==3||n==6)               //��4-6����ͨ����1-3�н��������ƶ�һ�����ɵ� 
			{
		    	for(i=0;i<3;i++)          //��7-9����ͨ����1-3�н��������ƶ����������ɵ� 
			    {
				a=Block[i][0];          //�ݴ��һ�е��� 
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
