#include <linux/init.h>
#include <linux/module.h>

#include <linux/fs.h> /*char dev drv support*/

int ex_open(struct inode *pinode, struct file *pfile)
{
  printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
  return 0;
}

ssize_t ex_read(struct file *pfile, char __user *buffer, size_t length, loff_t *offset)
{
  printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
  return 0;
}

ssize_t ex_write (struct file *pfile, const char __user *buffer, size_t length, loff_t *offset)
{
  printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
  return length;
}

int ex_close(struct inode *pinode, struct file *pfile)
{
  printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
  return 0;
}

/* To hold the file operations performed on this device*/
struct file_operations ex_file_operations = {
   .owner    = THIS_MODULE,
   .open    = ex_open,
   .read    = ex_read,
   .write   = ex_write,
   .release = ex_close,
};


int char_dev_drv_module_init(void)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);

	/*Register with kernel and indicate that we are registering a character device driver*/
	register_chrdev(240/*Major Number*/,
	                "Simple char Drv"/*Name of the driver*/,
	                 &ex_file_operations /*file operations*/);

	return 0;
}


void char_dev_drv_module_exit(void)
{
	printk(KERN_ALERT "Inside the %s function\n", __FUNCTION__);
	/*Unregister the char dev driver*/
	unregister_chrdev(240,"Simple char Dev");
}


module_init(char_dev_drv_module_init);
module_exit(char_dev_drv_module_exit);