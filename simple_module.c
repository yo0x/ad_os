#include<linux/init.h>
#include<linux/module.h>

static int __init hello_func(void){

    printk(KERN_DEBUG "Called: %s \n", __FUNCTION__);
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