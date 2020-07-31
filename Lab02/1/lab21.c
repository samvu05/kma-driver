#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

void DecToBinary(int n);
int BinaryToDec(int n);

static int lab21_init(void) 
{
	printk(KERN_INFO "\nHello from module Bai 1 - Lab 2\n");

	int n1 = 85;
	DecToBinary(n1);

	int n2 = 101010;
	printk("2 sang 1): %d", BinaryToDec(n2));

	printk("\n");
	return 0;
}

void DecToBinary(int n)
{
	int arr[1000];
	int i = 0;
	int j = 0;
	while(n > 0) {
		arr[i] = n%2;
		n = n/2;
		i++;
	}
	printk("\n%d tu he 10 sang 2: \n", n);
	for(j = i-1; j >= 0; j--)
	{
		printk("%d", arr[j]);
	}
	printk("\n");
}

int BinaryToDec(int n)
{
	int i = 0;
	int decNumber = 0;
	while(n>0) {
		decNumber = decNumber + pow(2, i)*(n%10);
		n = n/10;
		i++;
	}
	return decNumber;
}


static void lab21_exit(void)
{
	printk(KERN_INFO "\nBye from module Bai 1 - Lab 2\n");
}

module_init(lab21_init);
module_exit(lab21_exit);

