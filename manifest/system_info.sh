#!/bin/sh

# 获取主机名
hostname=$(hostname)

# 操作系统
os=$(uname)

# 获取平台和平台版本
if [ -f /etc/os-release ]; then
    # 提取 NAME 和 VERSION_ID
    platform=$(grep '^NAME=' /etc/os-release | sed 's/NAME=//; s/"//g')
    platform_version=$(grep '^VERSION_ID=' /etc/os-release | sed 's/VERSION_ID=//; s/"//g')
else
    platform="N/A"
    platform_version="N/A"
fi

# 获取内核版本
kernel_version=$(uname -r)

# 获取机器架构
machine=$(uname -m)

# 输出信息
echo "Hostname: $hostname"
echo "OS: $os"
echo "Platform: $platform"
echo "PlatformVersion: $platform_version"
echo "KernelVersion: $kernel_version"
echo "Machine: $machine"

