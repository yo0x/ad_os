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