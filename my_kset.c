#include <linux/kobject.h>
#include <linux/string.h>
#include <linux/sysfs.h>
#include <linux/module.h>
#include <linux/init.h>

static struct kset *example_kset;

static struct kobject *example_kobject_1;
static struct kobject *example_kobject_2;

struct int k1_file_1_val;
struct int k1_file_2_val;

static int k2_file_1_val;
static int k2_file_2_val;
#define ATTRIBUTE_1_NAME "file_1"
#define ATTRIBUTE_2_NAME "file_2"
#define KOBJECT_1_NAME "kobject_1"
#define KOBJECT_2_NAME "kobject_2"



static struct kobject_attribute file_1_attr = _ATTR(file_1, 0664,my_show, my_store);

static struct kobject_attribute file_2_attr = {
    .attr = {.name = ATTRIBUTE_2_NAME,
    .mode = 0644},
    .show = my_show,
    .store = my_store,
};

static struct attribute * attrs[] = {
    &file_1_attr.attr,
    &file_2_attr.attr,
    NULL,
};

static struct attribute_group attribute_group = {
    .attrs = attrs,
};
static int my_kobject_create(struct kobject *kobj, const char *name){
    int err = -1;
    kobj = kobject_create_and_add(name, &example_kset->kobj);
    if(!kobj)
    return -ENOMEM;
    err = sysfs_create_group(kobj, &attr_group);
    if(err)
    kobject_put(kobj);
    return err;

}

static int __init kset_module_init(void)
{
    int err = -1;
    printk("Hello: init\n");
    example_kset = kset_create_and_add("kset_example", NULL, kernel_kobj);
    if(!example_kset)
    return -ENOMEM;

    err = my_kobject_create(example_kobject_1,KOBJECT_1_NAME);
    err = my_kobject_create(example_kobject_2,KOBJECT_2_NAME);
    return err;
    
}

static void __exit kset_module_exit(void)
{
    if(example_kobjt_1) {
        kobject_put(example_kobject_1);
    }
    
    if(example_kobjt_2) {
        kobject_put(example_kobject_2);
    }
    kset_unregister(example_kset);
    printk("hello: exit\n");

}

module_init(kset_modeule_init);
module_exit(kset_module_exit);
MODULE_LICENSE("GPL");