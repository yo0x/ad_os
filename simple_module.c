#include<linux/init.h>
#include<linux/module.h>
#include<linux/delay.h>

#define ALL_READ    (S_IRUSR|S_IROTH)

#define UG_WRITE    (S_IWUSR|S_IWGRP)

//MODULE PARAM!
static char *whom = "NoName";
module_param(whom, charp, 0);
MODULE_PARAM_DESC(whom, "Name of someone to say hello");
static int howmany = 2;
module_param(howmany, int, ALL_READ|UG_WRITE);
MODULE_PARAM_DESC(howmany,"How many times to say hellow");





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