#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

int tongchuoi(int a[],int n);
int UCLN(int a,int b);

static int lab11_init(void)
{
    printk(KERN_ALERT "Khoi tao ok\n");
        int n = 5;
	int a[5]={1,2,3,4,5};
	int tong = tongchuoi(a,n);
	int ucln = UCLN(8,6);
        printk("\ntong = %d", tong);
	printk("UCLN 8 va 6 la %d", ucln);
        return 0;
}

int tongchuoi(int a[],int n)
{
       
 int i ,tong=0;

        for(i=0; i<n; i++)
        {
                tong= tong+a[i];
        }

        return tong;
}

int UCLN(int a,int b)
{
        int i, ucln;
	if(a<b)
	{
		for(i=1; i<a; i++)
		{
			if((a%i==0)&&(b%i==0))
				ucln = i;
		}
	}
	else
	{
		for(i=1; i<b; i++)
		{
			if((a%i==0)&&(b%i==0))
				ucln = i;
		}
	}
	return ucln;
}

static void lab11_exit(void)
{
    printk(KERN_ALERT "Ket thuc ok\n");
}

module_init(lab11_init);
module_exit(lab11_exit);
