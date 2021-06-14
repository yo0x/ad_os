#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/module.h>
#include <linux/init.h>

static irqreturn_t my_mouse_handler(int irq, void *dev)
{
    unsigned long flags = 0;
    local_irq_save(flags);
    printk("handler irq = %d \n", irq);
    local_irq_restore(flags);
    return IRQ_HANDLED;
}
static int myinit(void)
{
    // int i;
    int ret;

    // for (i=1; i<128; i++){
    //     ret = request_irq(
    //         i,
    //         handler,
    //         IRQF_SHARED,
    //         "myirqhadler0",
    //         MY_DEV_NAME
    //     );
    //     printk("Request irq = %d ret = %d\n", i,ret);

    // }
    if(request_irq(mouse_irq, my_mouse_handler, IRQF_SHARED,"my_mouse_init", MY_DEV_NAME)) return -1;
    printk("module: init finished \n");
    return 0;
}

static void myexit(void)
{
    int i;
    for (i=1; i<128; ++i)
    free_irq(i, MY_DEV_NAME);
}

module_init(myinit);
module_exit(myexit);