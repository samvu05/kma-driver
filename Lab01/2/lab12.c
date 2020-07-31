#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>

void timlonbe(int a[],int n);
void trungbinhcong(int a[],int n);

static int lab12_init(void)
{
    printk(KERN_ALERT "Khoi tao ok\n");
        int n = 5;
	int a[5]={1,2,3,4,5};
	timlonbe(a,n);
         trungbinhcong(a,n);
        return 0;
}

void timlonbe(int a[],int n)
{
       
 int i ,max,min;
max=a[0];
min=a[0];
        for(i=1; i<n; i++)
        {
         
if (a[i]>max) max=a[i];
if (a[i]<min) min=a[i];      
        }

         printk("so lon nhat %d",max);
	printk("so nho nhat %d",min);
}

void trungbinhcong(int a[],int n)
{ 
int i,tong=0;
       for(i=0;i<n;i++) tong=tong+a[i];
printk("trung binh cong %d \n",tong);
}

static void lab12_exit(void)
{
    printk(KERN_ALERT "Ket thuc ok\n");

}

module_init(lab12_init);
module_exit(lab12_exit);
