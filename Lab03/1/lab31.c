#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

int TichVoHuong(int arr_1[3], int arr_2[3], int n);
void Tong(int arr_1[3], int arr_2[3], int arr_3[3], int n);
void Hieu(int arr_1[3], int arr_2[3], int arr_3[3], int n);
void Tich(int arr_1[3], int arr_2[3], int arr_3[3], int n);
void InMaTran(int arr[3], int n);
int GiaiThua(int a);
int ChinhHop(int k, int n);
void End(void);

static int lab31_init(void)
{
	printk(KERN_INFO "\nHello from module Lab 03 Bai 1\n");

	int n = 3;
	int n2 = 6;
	int k = 3;
	int arr_1[3] = {1, 2, 3};
	int arr_2[3] = {4, 5, 6};
	int arr_sum[3] = {0, 0, 0};
	int arr_sub[3] = {0, 0, 0};
	int arr_mul[3] = {0, 0, 0};
	int sum = 0;

	printk("Tich Vo Huong: %d", TichVoHuong(arr_1, arr_2, n));

	printk("\nTong 2 ma tran: ");
	Tong(arr_1, arr_2, arr_sum, n);
	InMaTran(arr_sum, n);

	printk("\nHieu 2 ma tran: ");
	Hieu(arr_1, arr_2, arr_sub,n);
	InMaTran(arr_sub, n);

	printk("\nTich 2 ma tran: ");
	Tich(arr_1, arr_2, arr_mul, n);
	InMaTran(arr_mul, n);

	if(k>n2 || k*n2 < 0) return 0;
	else {
		printk("\nChinh hop chap k cua n: %d", ChinhHop(k, n2));
	}

	End();
	return 0;
}

int TichVoHuong(int arr_1[3], int arr_2[3], int n)
{
	int i = 0;
	int sum = 0;
	for(i = 0; i < n; i++) {
		sum += arr_1[i]*arr_2[i];
	}
	return sum;
}

void Tong(int arr_1[3], int arr_2[3], int arr_3[3], int n)
{
	int i = 0;
	int sum = 0;
	for(i = 0; i < n; i++) {
		arr_3[i] = arr_1[i]+arr_2[i];
	}
}
void Hieu(int arr_1[3], int arr_2[3], int arr_3[3], int n)
{
	int i = 0;
	int sub = 0;
	for(i = 0; i < n; i++) {
		arr_3[i] = arr_1[i]-arr_2[i];
	}
}
void Tich(int arr_1[3], int arr_2[3], int arr_3[3], int n)
{
	int i = 0;
	int mul = 0;
	for(i = 0; i < n; i++) {
		arr_3[i] = arr_1[i]*arr_2[i];
	}
}
void InMaTran(int arr[3], int n)
{
	int i = 0;
	for(i = 0; i < n; i++) {
		printk("%d", arr[i]);
	}
}

int GiaiThua(int a)
{
	int s = 1;
	int i;
	for(i = 1; i <= a; i++) {
		s*=i;
	}
	return s;
}
int ChinhHop(int k, int n)
{
	return GiaiThua(n)/GiaiThua(n-k);
}
void End(void)
{
	printk("\nEnd");
}

static void lab31_exit(void)
{
	printk(KERN_INFO "\nBye from module Lab 03 Bai 1\n");
}

module_init(lab31_init);
module_exit(lab31_exit);
