#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/init.h>

int MaHoa(char message[], int key);
int GiaiMa(char message[], int key);

static int lab32_init(void)
{
	printk(KERN_INFO "\nHello from module Lab 03 Bai 2\n");

	char message[100] = "Hello Driver Programming";
	int key = 12;

	printk("\nMa Hoa: %s", MaHoa(message, key));

	printk("\nGiai Ma: %s", GiaiMa(message, key));

	return 0;
}

int MaHoa(char message[100], int key)
{
	int i=0;
    for(i = 0; message[i] != '\0'; ++i){
		char ch = message[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch + key;

			if(ch > 'z'){
				ch = ch - 'z' + 'a' - 1;
			}
			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch + key;

			if(ch > 'Z'){
				ch = ch - 'Z' + 'A' - 1;
			}

			message[i] = ch;
		}
	}
	return message;
}
int GiaiMa(char message[100], int key)
{
	int i=0;
    for(i = 0;  message[i] != '\0'; ++i){
		char ch = message[i];

		if(ch >= 'a' && ch <= 'z'){
			ch = ch - key;

			if(ch < 'a'){
				ch = ch + 'z' - 'a' + 1;
			}

			message[i] = ch;
		}
		else if(ch >= 'A' && ch <= 'Z'){
			ch = ch - key;

			if(ch < 'A'){
				ch = ch + 'Z' - 'A' + 1;
			}

			message[i] = ch;
		}
	}
	return message;
}

static void lab32_exit(void)
{
	printk(KERN_INFO "\nBye from module Lab 03 Bai 2\n");
}

module_init(lab32_init);
module_exit(lab32_exit);
