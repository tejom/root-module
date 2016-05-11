# root-module
This is a kernel module that will give a given pid root access. This was made using kernal 4.5.0 .

### Use
`make PID=#`

or for the first run

`make PID=# install`

PID is the proccess to give root too...

#### A little example
```
[matthew@localhost ~]$ id
uid=1000(matthew) gid=1000(matthew) groups=1000(matthew),10(wheel) context=unconfined_u:unconfined_r:unconfined_t:s0-s0:c0.c1023
[matthew@localhost ~]$ echo $BASHPID
12706
```

`[root@localhost ~]# make PID=12706 `

```
[matthew@localhost ~]$ id
uid=0(root) gid=0(root) groups=0(root),10(wheel),1000(matthew) context=unconfined_u:unconfined_r:unconfined_t:s0-s0:c0.c1023
```



### Background
Ive been learning a little bit about linux and thought writing a module would be a good place to start.
I browsed the internet for a bit and came across another repo with some simple modules and one of them was a rootkit. When I saw this I thought it would a be a really cool little short project. Searching didn't bring anything up for newer kernels.

It was a little challenging but I got through it. [This article](http://www.theregister.co.uk/2016/05/09/allwinners_allloser_custom_kernel_has_a_nasty_root_backdoor/) popped up and helped with one thing I was stuck on.
