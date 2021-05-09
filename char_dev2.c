#include <linux/init.h>
#include <linux/module.h>
#include <linux/delay.h>
#include <linux/uaccess.h>
#include <linux/cdev.h>
#include <linux/fs.h>
#include "ioctl_user.h"

int major_num = 0;
int minor_num = 0;

dev_t dev = 0;
struct cdev cdev;

//enable to input params from the cmd
module_param(major_num, int, 0);
module_param(minor_num, int, 0);
#define NUM_MINORS 1
void char_dev_exit(void);
