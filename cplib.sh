#!/bin/sh
exe="FlySnailWebDisk"         #修改发布程序的名称
des="$(pwd)/build_linux" #修改输出可执行文件路径
deplist=$(ldd $exe | awk  '{if (match($3,"/")){ printf("%s "),$3 } }')
cp $deplist $des
