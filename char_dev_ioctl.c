#include<linux/init.h>
#include<linux/module.h>
#include<linux/delay.h>
#include<linux/uaccess.h>
#include<linux/cdev.h>
#include<linux/fs.h>

int major_num = 0;
int minor_num = 0;

dev_t dev =0;
struct cdev cdev;


//enable to input params from the cmd
module_param(major_num, int, 0);
module_param(minor_num, int, 0);

#define MY_CHAR_DEV_SIZE 512
#define NUM_MINORS 1
char kernel_char_array [MY_CHAR_DEV_SIZE] = {0};
void char_dev_exit(void);

int char_open(struct inode *inode, struct file *filp)
{
    printk(KERN_NOTICE "char_release() release function was called\n")
    return 0;
    /* data */
}

int char_read(struct file *filp, char __user *buf, size_t count, loff_t *f_pos)
{
    printk(KERN_NOTICE "char_read() release function was called\n")
    kernel_char_array[1] = kernel_char_array[1]+2;
    kernel_char_array[2] = kernel_char_array[2]+3;
    printk(KERN_NOTICE "char_read() read function was called\n");
    if(copy_to_user(buf, kernel_char_array, count))
    {
        count = -EFAULT;
    }
    return count;
    /* data */
}

int char_write(struct file *filp, const char __user *buf, size_t count, loff_t *f_pos)
{
    printk(KERN_NOTICE "char_write() release function was called\n")


    if(copy_from_user( kernel_char_array, buf, count))
    {
        count = -EFAULT;
    }
    return count;

    /* data */
}

static long my_unlocked_ioctl(struct file *filp, unsigned int cmd, unsigned long argp)
{
    void __user *arg_user;
    int input;
    if (_IOC_TYPE(cmd) != MY_IOCTL_MAGIC){
        return -ENOTTY;
    }
}
struct file_operations char_fops = {
    .owner = THIS_MODULE,
    .read = char_read,
    .write = char_write,
    .open = char_open,
    .release = char_release,
    .unlocked_ioctl = my_unlocked_ioctl,
};





static int __init hello_func(void){

    printk(KERN_DEBUG "Called: %s \n", __FUNCTION__);
    while (howmany)
    {
        printk(KERN_INFO "(%d) Hello, %s\n", howmany--,whom);
        msleep(2000);
    }
    
    return 0;

}

static void __exit hello_exit(void){
    printk(KERN_DEBUG "Called: %s \n", __FUNCTION__);
    return;
}

module_init(hello_func);
module_exit(hello_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("Yonor");
MODULE_DESCRIPTION("some descripet");
MODULE_VERSION("0.1.1.1");