# Shell概述
Shell是一个命令行解释器，它接收应用程序/用户命令，然后调用操作系统内核。

Shell还是一个功能相当强大的编程语言，易编写、易调试、灵活性强。

`脚本`是使用一种特定的描述性语言，依据一定的格式编写的可执行文件。执行脚本的时候可以对其中的代码进行逐行的解释执行。

```shell
# 查看Linux系统提供的Shell解释器
kurumi@kurumi:~$ cat /etc/shells
# /etc/shells: valid login shells
/bin/sh
/bin/bash
/bin/rbash
/bin/dash

# 查看当前环境变量
kurumi@kurumi:~$ echo $SHELL
/bin/bash
```
# Shell脚本入门
shell脚本文件的约定俗成的后缀名是.sh，但实际上任何命名都可以，只要文件内容符合shell编写规则即可

## 1.脚本格式
shell脚本一般都是以`#!/bin/bash`开头，用于指定脚本的解析器

- 创建一个shell脚本输出hello, world!
```shell
kurumi@kurumi:~/shells$ touch hello.sh
kurumi@kurumi:~/shells$ vim hello.sh

#!/bin/bash
echo "hello, world!"
```

## 2.脚本常用执行方式
- bash/sh + 脚本路径
```shell
kurumi@kurumi:~/shells$ bash hello.sh
hello, world!
kurumi@kurumi:~/shells$ sh hello.sh
hello, world!
```

- 直接输入脚本路径（需要修改脚本文件权限，加上可执行的权限x）
```shell
kurumi@kurumi:~/shells$ chmod +x hello.sh
kurumi@kurumi:~/shells$ ./hello.sh
hello, world!
kurumi@kurumi:~/shells$ /home/kurumi/shells/hello.sh
hello, world!
# 这样是不行的，会把hello.sh看作一个命令
kurumi@kurumi:~/shells$ hello.sh
hello.sh：未找到命令
```

- 在脚本的路径前加上". "或"source"
```shell
kurumi@kurumi:~/shells$ . hello.sh  # 注意"."和文件名之间有一个空格
hello, world!
kurumi@kurumi:~/shells$ source hello.sh
hello, world!
```

`注意`：第三种方法（使用.或source）不会创建一个子shell，而前两种方法实际上是创建了一个子shell来执行shell脚本，不会影响当前shell

## 3.进入子shell
```shell
kurumi@kurumi:~/shells$ ps -f
UID         PID   PPID  C STIME TTY          TIME CMD
kurumi    43990  43989  0 14:56 pts/0    00:00:00 -bash
kurumi    44639  43990  0 14:57 pts/0    00:00:00 ps -f
kurumi@kurumi:~/shells$ bash  # 相当于是创建了一个子进程并让其成为前台进程
kurumi@kurumi:~/shells$ ps -f
UID         PID   PPID  C STIME TTY          TIME CMD
kurumi    43990  43989  0 14:56 pts/0    00:00:00 -bash
kurumi    44682  43990  0 14:57 pts/0    00:00:00 bash
kurumi    44720  44682  0 14:57 pts/0    00:00:00 ps -f
kurumi@kurumi:~/shells$ exit  # 退出子shell
exit
```

是否使用子shell的区别在于环境变量的继承关系，如在子shell中创建的环境变量，父shell是不可见的

# Shell变量
## 1.系统预定义变量
### 常用系统变量
- $HOME：当前主目录
- $PWD：当前工作目录
- $SHELL：当前使用的shell解析器
- $USER：当前的用户

env和printenv命令可以查看当前系统变量
```shell
kurumi@kurumi:~/shells$ env
kurumi@kurumi:~/shells$ printenv
```

需要查看具体变量名时，env需要结合grep命令，printenv后面可以直接加上变量名查看
```shell
kurumi@kurumi:~/shells$ env | grep HOME
HOME=/home/kurumi
kurumi@kurumi:~/shells$ printenv HOME  # 注意printenv后面不用加$
/home/kurumi
kurumi@kurumi:~/shells$ echo $HOME
/home/kurumi
```

set命令查看当前shell中的所有变量
```shell
kurumi@kurumi:~/shells$ set
```

## 2.自定义变量
### 1）基本语法
- 定义变量：变量名=变量值   （`注意：=前后不能有空格！`）
```shell
kurumi@kurumi:~/shells$ a=2
kurumi@kurumi:~/shells$ echo $a
2
kurumi@kurumi:~/shells$ my_var=hello
kurumi@kurumi:~/shells$ echo $my_var
hello
kurumi@kurumi:~/shells$ echo $my_var  # 变量可以更改
world
kurumi@kurumi:~/shells$ my_var="Hello, world!"
kurumi@kurumi:~/shells$ echo $my_var
Hello, world!
kurumi@kurumi:~/shells$ my_var='Hello, world!'
kurumi@kurumi:~/shells$ echo $my_var
Hello, world!
kurumi@kurumi:~/shells$ b = 1
b：未找到命令
```
`注意`：这样定义的是局部变量，创建子shell后无法使用。使用export命令可以将其提升为全局变量（当前shell下的）
```shell
kurumi@kurumi:~/shells$ bash
kurumi@kurumi:~/shells$ echo $my_var

kurumi@kurumi:~/shells$ exit
exit
kurumi@kurumi:~/shells$ export my_var
kurumi@kurumi:~/shells$ bash
kurumi@kurumi:~/shells$ echo $my_var
Hello, world!
```
`注意`：子shell中创建或更改自定义变量（甚至对这个变量进行export），不会影响父shell的变量（参考创建进程时，`读时共享，写时拷贝`的思想）

```shell
# 验证source/. 和利用bash/sh或直接用路径运行脚本的区别
kurumi@kurumi:~/shells$ new_var="father"
kurumi@kurumi:~/shells$ source hello.sh  # 直接用父进程运行
hello, world!
father
kurumi@kurumi:~/shells$ ./hello.sh  #创建一个子进程运行，下同
hello, world!

kurumi@kurumi:~/shells$ bash hello.sh
hello, world!

```

- 撤销变量：