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

    默认的变量类型为`字符串`类型
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

- 只读变量：readonly 变量名=变量值
```shell
kurumi@kurumi:~/shells$ readonly r_a=1
kurumi@kurumi:~/shells$ echo $r_a
1
kurumi@kurumi:~/shells$ r_a=2
-bash: r_a: 只读变量
```

- 撤销变量：unset

    `注意`：不能撤销只读变量

```shell
kurumi@kurumi:~/shells$ a=2
kurumi@kurumi:~/shells$ echo $a
2
kurumi@kurumi:~/shells$ unset a
kurumi@kurumi:~/shells$ echo $a

kurumi@kurumi:~/shells$ readonly r_a=1
kurumi@kurumi:~/shells$ unset r_a
-bash: unset: r_a: 无法取消设定: 只读 variable
```

## 3.特殊变量
### 3.1 $n
- 基本语法：$n

功能描述: n为数字，$0代表该脚本本身的名称，`$1-$9`代表第一到第九个参数，十以上的参数需要用大括号包含，如`${10}`

```shell
kurumi@kurumi:~/shells$ vim parameter.sh
#!/bin/bash
echo '==============$n================'
echo $0
echo $1
echo $2
kurumi@kurumi:~/shells$ chmod +x parameter.sh
kurumi@kurumi:~/shells$ ./parameter.sh
==============$n================
./parameter.sh


kurumi@kurumi:~/shells$ ./parameter.sh aaa bbb
==============$n================
./parameter.sh
aaa
bbb
```

`单引号和双引号的区别`：双引号中会把$和后面紧跟的内容认为是变量（如果要输出$需要加转义符\$），单引号不会

### 3.2 $#
`$#` 查看参数个数（不包含$0）
```shell
# 在parameter.sh文件后加入下面两行
echo '==============$#================'
echo 参数个数：$#

kurumi@kurumi:~/shells$ ./parameter.sh aaa bbb
==============$n================
./parameter.sh
aaa
bbb
==============$#================
参数个数：2
```

### 3.2 \$*、$@
`$*`：这个变量代表命令行中所有的参数，`把所有的参数看成一个整体（相当于字符串）`

`$@`：这个变量也代表命令行中所有的参数，但`把每个参数分开对待（相当于数组）`
```shell
# 在parameter.sh文件后加入下面四行
echo '==============$*================'
echo $*
echo '==============$@================'
echo $@

kurumi@kurumi:~/shells$ ./parameter.sh aaa bbb
==============$n================
./parameter.sh
aaa
bbb
==============$#================
参数个数：2
==============$*================
aaa bbb
==============$@================
aaa bbb
```

### 3.3 $?
$?：代表最后一次执行的命令的返回状态。如果这个变量的值为0，表示上一个命令正确执行；如果这个变量的值为非0（具体是哪个数，由命令自己来决定），则表示上一个命令执行异常。
```shell
kurumi@kurumi:~/shells$ echo $?
0
kurumi@kurumi:~/shells$ abc.sh
abc.sh：未找到命令
kurumi@kurumi:~/shells$ echo $?
127
```

# 运算符
## 使用expr命令
把各个数字以及运算符当作参数输入（因此`表达式中间一定要加空格`）
特别地，`乘号 * 需要加转义符`（因为乘号有通配符等特殊含义）

```shell
kurumi@kurumi:~/shells$ expr 1 + 2
3
kurumi@kurumi:~/shells$ expr 1+2
1+2
kurumi@kurumi:~/shells$ expr 5 * 3
expr: 语法错误
kurumi@kurumi:~/shells$ expr 5 \* 3
15
```
赋值：
```shell
kurumi@kurumi:~/shells$ a=$(expr 5 + 2)
kurumi@kurumi:~/shells$ echo $a
7
kurumi@kurumi:~/shells$ a=`expr 1 + 2`
kurumi@kurumi:~/shells$ echo $a
3
```

## 使用运算符
语法：\$[运算式] 或 \$((运算式))

`运算式中间可以加空格，乘号不需要加转义符`
```shell
kurumi@kurumi:~/shells$ echo $[5+2]
7
kurumi@kurumi:~/shells$ echo $((6*3))
18
```
赋值：
```shell
kurumi@kurumi:~/shells$ a=$[1 - 2]
kurumi@kurumi:~/shells$ echo $a
-1
```

- 实现一个加法脚本输出两数之和
```shell
kurumi@kurumi:~/shells$ vim add.sh
#!/bin/bash
sum=$[$1 + $2]
echo sum=$sum

kurumi@kurumi:~/shells$ chmod +x add.sh
kurumi@kurumi:~/shells$ ./add.sh 10 20
sum=30
```

# 条件判断
- 基本语法

(1) test condition

(2) [ condition ]

`注意condition前后，以及表达式中一定要有空格（[ 是一个linux内建命令）`

表达式是否为真，需要紧接着再执行echo $? 命令来判断，`注意0表示真，1表示假`

特别地，如果[ ]中为空，表示假

```shell
kurumi@kurumi:~/shells$ test 1 = 2
kurumi@kurumi:~/shells$ echo $?
1
kurumi@kurumi:~/shells$ test 1 = 1
kurumi@kurumi:~/shells$ echo $?
0
kurumi@kurumi:~/shells$ [ 1 = 2 ]
kurumi@kurumi:~/shells$ echo $?
1
kurumi@kurumi:~/shells$ [ 2 = 2 ]
kurumi@kurumi:~/shells$ echo $?
0
kurumi@kurumi:~/shells$ [ ]
kurumi@kurumi:~/shells$ echo $?
1
```

（1）两个整数/字符串之间比较

-eq 等于(equal)  （或使用 = ）

-ne 不等于(not equal)  （或使用 != ）

-lt 小于(less than)  （或使用 \\< ）

-le 小于等于(less equal)  （不能用 `<=` ）

-gt 大于(greater than)  （或使用 \\> ）

-ge 大于等于(greater equal)  （不能用 `>=` ）

`注意：两个字符串比较只能用 = 和 != ,不能用-eq -ne`

```shell
kurumi@kurumi:~/shells$ [ 1 -eq 1 ]
kurumi@kurumi:~/shells$ echo $?
0
kurumi@kurumi:~/shells$ [ 1 -ne 1 ]
kurumi@kurumi:~/shells$ echo $?
1
kurumi@kurumi:~/shells$ [ 1 -lt 2 ]
kurumi@kurumi:~/shells$ echo $?
0
kurumi@kurumi:~/shells$ [ 1 -ge 2 ]
kurumi@kurumi:~/shells$ echo $?
1
kurumi@kurumi:~/shells$ [ abc = abc ]
kurumi@kurumi:~/shells$ echo $?
0
kurumi@kurumi:~/shells$ [ abc != abc ]
kurumi@kurumi:~/shells$ echo $?
1
# 一定要分开写，否则视为一个整体无法判断
kurumi@kurumi:~/shells$ [ abc!=abc ]
kurumi@kurumi:~/shells$ echo $?
0
```

（2）按照文件权限进行判断（当前用户对该文件的权限）

-r  读权限

-w  写权限

-x  执行权限

```shell
kurumi@kurumi:~/shells$ touch test
kurumi@kurumi:~/shells$ chmod 644 test  # -rw-r--r--
kurumi@kurumi:~/shells$ [ -r test ]
kurumi@kurumi:~/shells$ echo $?
0
kurumi@kurumi:~/shells$ [ -w test ]
kurumi@kurumi:~/shells$ echo $?
0
kurumi@kurumi:~/shells$ [ -x test ]
kurumi@kurumi:~/shells$ echo $?
1
```

（3）按照文件类型进行判断

-e  文件是否存在

-f  文件是否是普通文件

-d  文件是否是目录文件

```shell
kurumi@kurumi:~/shells$ [ -e testdir ]
kurumi@kurumi:~/shells$ echo $?
1
kurumi@kurumi:~/shells$ mkdir testdir
kurumi@kurumi:~/shells$ [ -e testdir ]
kurumi@kurumi:~/shells$ echo $?
0
kurumi@kurumi:~/shells$ [ -f testdir ]
kurumi@kurumi:~/shells$ echo $?
1
kurumi@kurumi:~/shells$ [ -d testdir ]
kurumi@kurumi:~/shells$ echo $?
0
```

（4）多条件判断

常用格式：[ condition ] && true_branch || false_branch

本质上是利用 && 和 || 的短路效应
```shell
kurumi@kurumi:~/shells$ a=15
kurumi@kurumi:~/shells$ [ $a -lt 20 ] && echo "$a < 20" || echo "$a >= 20"
15 < 20
kurumi@kurumi:~/shells$ a=25
kurumi@kurumi:~/shells$ [ $a -lt 20 ] && echo "$a < 20" || echo "$a >= 20"
25 >= 20
```

# 流程控制
## if语句
### 1）基本语法

（1）单分支
```shell
# 语法1
if [ condition ];then  # ;可以用来在同一行中按序执行多个命令
    程序
fi

# 语法2
if [ condition ]
then
    程序
fi
```
```shell
kurumi@kurumi:~/shells$ a=25
kurumi@kurumi:~/shells$ if [ $a -gt 18 ]; then echo OK; fi
OK
kurumi@kurumi:~/shells$ a=15
kurumi@kurumi:~/shells$ if [ $a -gt 18 ]; then echo OK; fi
```
使用文件编写：
```shell
kurumi@kurumi:~/shells$ vim if_test.sh
#!/bin/bash
if [ $1 = kurumi ]
then
        echo hello
fi

kurumi@kurumi:~/shells$ chmod +x if_test.sh
kurumi@kurumi:~/shells$ ./if_test.sh aaa
kurumi@kurumi:~/shells$ ./if_test.sh kurumi
hello
# 注意没有输入参数的时候会报错
kurumi@kurumi:~/shells$ ./if_test.sh
./if_test.sh: 第 3 行: [: =: 需要一元表达式
# 解决方法：对条件语句进行修改，附加一个特定字符保证其不为空
kurumi@kurumi:~/shells$ vim if_test.sh
#!/bin/bash
if [ "$1"x = "kurumi"x ]
then
        echo hello
fi

kurumi@kurumi:~/shells$ ./if_test.sh
kurumi@kurumi:~/shells$ ./if_test.sh kurumi
hello
```
多条件判断：

- 逻辑与：[ condition ] && [ condition ] 或 [ condition -a condition]
- 逻辑或：[ condition ] || [ condition ] 或 [ condition -o condition]
```shell
kurumi@kurumi:~/shells$ a=25
kurumi@kurumi:~/shells$ if [ $a -gt 18 ] && [ $a -lt 35 ]; then echo OK; fi
OK
kurumi@kurumi:~/shells$ a=36
kurumi@kurumi:~/shells$ if [ $a -gt 18 ] && [ $a -lt 35 ]; then echo OK; fi
kurumi@kurumi:~/shells$ if [ $a -gt 18 -a $a -lt 50 ]; then echo OK; fi
OK
```

（2）多分支
```shell
# 语法
if [ condition ]
then
    分支1
elif [ condition ]
then
    分支2
...
else
    default分支
fi
```

```shell
kurumi@kurumi:~/shells$ vim if_else.sh
#!/bin/bash
if [ $1 -lt 18 ]
then
        echo "未成年人"
elif [ $1 -ge 18 -a $1 -le 35 ]
then
        echo "青年人"
else
        echo "老年人"
fi

kurumi@kurumi:~/shells$ chmod +x if_else.sh
kurumi@kurumi:~/shells$ ./if_else.sh 10
未成年人
kurumi@kurumi:~/shells$ ./if_else.sh 18
青年人
kurumi@kurumi:~/shells$ ./if_else.sh 60
老年人
```

## case语句
```shell
# 语法
case $变量名 in
"候选值1")
    分支1
;;  # ;;相当于break
"候选值2")
    分支2
;;
...
*)
    default分支
;;
esac
```
样例：
```shell
kurumi@kurumi:~/shells$ vim case_test.sh
#!/bin/bash
case $1 in
1)
        echo one
;;
case $1 in
2)
        echo two
;;
case $1 in
3)
        echo three
;;
*)
        echo other
;;
esac

kurumi@kurumi:~/shells$ ./case_test.sh 1
one
kurumi@kurumi:~/shells$ ./case_test.sh 2
two
kurumi@kurumi:~/shells$ ./case_test.sh 3
three
kurumi@kurumi:~/shells$ ./case_test.sh 114
other
```

## for语句
- C/Java风格
```shell
# 语法
for ((初始值;循环控制条件;变量变化))
do
    程序
done
```
样例：
```shell
kurumi@kurumi:~/shells$ vim for_test.sh
#!/bin/bash
sum=0
for ((i=1; i<=$1; ++i))
do
        sum=$[ $sum + $i ]
        # 以下三种均可
        # sum=$((sum+i))
        # ((sum = sum + i))
        # ((sum += i))
done
echo "sum="$sum

chmod +x for_test.sh
kurumi@kurumi:~/shells$ ./for_test.sh 100
sum=5050
```
- 自定义遍历列表
```shell
# 语法
for 变量 in 值1 值2 值3 ...
do
    程序
done
```
样例：
```shell
kurumi@kurumi:~/shells$ for num in 11 45 14; do echo $num; done
11
45
14
```
特别地，可以用`{begin...end}`生成一个序列
```shell
kurumi@kurumi:~/shells$ sum=0; for i in {1..100}; do sum=$[$sum+$i]; done; echo $sum
5050
```
\$* 和 \$@ 的区别
```shell
kurumi@kurumi:~/shells$ vim for_test2.sh
#!/bin/bash
echo '============$*==========='
for i in $*
do
        echo $i
done
echo '============$@==========='
for i in $@
do
        echo $i
done
echo '============"$*"==========='
for i in "$*"
do
        echo $i
done
echo '============"$@"==========='
for i in "$@"
do
        echo $i
done

kurumi@kurumi:~/shells$ chmod +x for_test2.sh
kurumi@kurumi:~/shells$ ./for_test2.sh 1 2 3
# 不加""时候两者没区别，都分别遍历其中内容
============$*===========
1
2
3
============$@===========
1
2
3
# 加""时候$*把所有参数看作一个整体，$@仍然分开
============"$*"===========
1 2 3
============"$@"===========
1
2
3
```

## while语句
```shell
# 语法
while [ condition ]
do
    程序
done
```
样例：
```shell
kurumi@kurumi:~/shells$ a=0; sum=0; while [ $a -le 100 ]; do sum=$[$sum+$a]; a=$[$a+1]; done; echo $sum
5050
```

# read读取控制台输入
## 1）基本语法
read (选项) (参数)

① 选项

- -p：指定读取值时的提示符
- -t：指定读取值时的阻塞等待时间，超时自动继续执行后续代码。不加表示一直等待

② 参数

指定读取值的变量名

样例：
```shell
kurumi@kurumi:~/shells$ read -t 5 -p "Please enter your name in 5 sec: " name; echo "welcome, $name"
Please enter your name in 5 sec: cxk
welcome, cxk
kurumi@kurumi:~/shells$ read -t 5 -p "Please enter your name in 5 sec: " name; echo "welcome, $name"
Please enter your name in 5 sec: welcome,  # 超时
```