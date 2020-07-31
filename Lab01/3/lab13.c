#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

void tong(int a[][],int h,int c);
void dem(int a[][],int h,int c);
void tim(int a[][],int h,int c);
void tongg(int a[][],int h,int c);
static int lab13_init(void)
{
    printk(KERN_ALERT "Khoi tao ok\n");
        int h =3,c=3 ;
	int a[3][3]={1,2,3,4,5,6,7,8,9};
	tong(a,h,c);
	dem(a,h,c);
	tim(a,h,c);
	tongg(a,h,c);
        return 0;
}

void tong(int a[][],int h,int c)
{  
 	int i ,j,sum=0;
        	for(i=0; i<h; i++)
		{
			for(j=0; j<c; j++)
			{
				sum=sum+a[i][j];        
			}
		}
         printk("tong= %d",sum);
	 
}

void dem(int a[][],int h,int c)
{  
 	int i ,j,am=0,duong=0;
        for(i=0; i<h; i++)
	{
		for(j=0; j<c; j++)
		{
			if (a[i][j]<0) am=am+1;  
			if (a[i][j]>0) duong=duong+1;      
		}
	}
        printk("tong phan tu am= %d \n",am);
 	printk("tong phan tu duong= %d \n",duong);
	 
}
void tim(int a[][],int h,int c)
{  
	int maxc=a[0][0],minc=a[0][0],maxp=a[0][0],minp=a[0][0];
	if (h==c)
	{
		for(i=0; i<h; i++)
		{
			for(j=0; j<c; j++)
			{
				if (i==j && maxc<a[i][j]) 
					maxc=a[i][j]; 
 				if (i==j && minc<a[i][j])
					minc=a[i][j]; 
			}
		}
		for(i=0; i<h; i++)
		{
			for(j=0; j<c; j++)
			{
				if (i+j==n+1 && maxp<a[i][j]) 
					maxp=a[i][j];
				if (i+j==n+1 && minp>a[i][j]) 
					minp=a[i][j];  
			}
		}
	} 
	else
	{
		printk("khong tinh duoc\n");
	}
        
	printk("gia tri lon nhat tren duong cheo chinh= %d \n",maxc);
	printk("gia tri nho nhat tren duong cheo chinh= %d \n",minc);
	printk("gia tri lon nhat tren duong phu= %d \n",maxp);
	printk("gia tri nho nhat tren duong phu= %d \n",minp);	 
}
void tongg(int a[][],int h,int c)
{  
 	int i ,j,sumc=0,suml=0;
        for(i=0; i<h; i++)
	{
		for(j=0; j<c; j++)
		{
			if (a[i][j]%2==0) 
				sumc=sumc+a[i][j];   
			if (a[i][j]%2!=0) 
				suml=suml+a[i][j];     
		}
	}
        printk("tong chan= %d \n",sumc);
	printk("tong le= %d \n",suml);
}
static void lab13_exit(void)
{
    	printk(KERN_ALERT "Ket thuc ok\n");
}

module_init(lab13_init);
module_exit(lab13_exit);
