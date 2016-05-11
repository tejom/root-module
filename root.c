#include <linux/module.h> /* needed for modules*/
#include <linux/kernel.h> /*adds KERN_INFO*/
#include <linux/init.h> /*needed for macros*/
#include <linux/fs.h>
#include <linux/fdtable.h>
#include <linux/cred.h>
#include <linux/sched.h>
#include <asm/uaccess.h>


#include "root.h"


static struct task_struct *task;
static struct cred *cred;
static int pid =0;

module_param(pid,int,0);

int init_module()
{
	printk(KERN_INFO "module initizialzed\n");
	
	for_each_process(task)
		if(task->pid == pid)
		{
			cred = (struct cred *)__task_cred(task);
			printk(KERN_INFO "changing %d - %s ; uid %d\n",task->pid,task->comm,task->real_cred->uid.val);
			cred -> uid.val = 0;
			cred -> gid.val =0;
			cred->suid.val = 0;
			cred->sgid.val = 0;
            cred->euid.val = 0;
            cred->egid.val = 0;
            cred->fsuid.val = 0;
            cred->fsgid.val = 0;
            
			printk(KERN_INFO "uids %d -- %d \n",task->real_cred->uid.val,cred->uid.val);
			printk(KERN_WARNING "pid %d , %s is now root\n",task->pid,task->comm);
		}

	return 0;
}

void cleanup_module()
{
	printk(KERN_INFO "cleaning up module\n");
}

MODULE_LICENSE("GPL");
MODULE_AUTHOR(DRIVER_AUTHOR);
MODULE_DESCRIPTION(DREIVER_DESC);