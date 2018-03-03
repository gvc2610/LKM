#include <linux/init.h>
#include <linux/module.h>
#include <linux/stat.h>

MODULE_LICENSE("Dual BSD/GPL");

static char *whom = "world";
static int howmany = 1;
static int arr_argc = 0;
static int myIntArray[5] = {0};

module_param(howmany,int,S_IRUGO);
module_param(whom,charp,S_IRUGO);
module_param_array(myIntArray,int,&arr_argc,S_IRUGO);

static int hello_init(void)
{
	int i;
	printk(KERN_ALERT "Hello, world\n");
 
	for(i=0;i<howmany;i++)
		printk(KERN_ALERT "Hello %s for %d times\n",whom,i);

	for(i=0;i<sizeof(myIntArray)/sizeof(int);i++)
		printk(KERN_ALERT "Value of array[%d] = %d \n",i,myIntArray[i]);

        printk(KERN_ALERT "Received %d arguments \n",arr_argc);
	return 0;
}

static void hello_exit(void)
{
	printk(KERN_ALERT "Goodbye,cruel world\n");
}

module_init(hello_init);
module_exit(hello_exit);