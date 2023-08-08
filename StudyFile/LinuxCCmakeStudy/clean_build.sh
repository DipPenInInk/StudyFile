#!/bin/bash

# 指定要删除的目录
directory_to_delete="./build"

# 删除目录下的所有文件和文件夹
rm -rf ${directory_to_delete}/*

echo "Cleaning is over!"
