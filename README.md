# mirai-cpp-template

 mirai-cpp 机器人项目模板

## 使用方法

使用以下指令克隆本仓库

```bash
git clone https://github.com/cyanray/mirai-cpp-template.git --recursive
cd mirai-cpp-template
# 更新 mirai-cpp 到最新
git submodule update --init --force --remote
```

然后使用 Visual Studio 或 Visual Studio Code 直接打开整个文件夹即可。

本模板编译目标为可执行文件，其主函数位于 **src/main.cpp** 。

头文件请添加到 **include** 目录中

源文件请添加到 **src** 目录中，并且不要忘记修改 **CMakeLists.txt**。（参考CMakeLists.txt中的注释进行修改）


mirai-cpp 的说明文档：[使用说明](https://github.com/cyanray/mirai-cpp/blob/master/doc/%E4%BD%BF%E7%94%A8%E8%AF%B4%E6%98%8E.md)

## 切换 mirai-cpp 版本

### 1. 更新到最新版 mirai-cpp

直接在 template 项目根目录执行以下指令:

```bash
# 更新 mirai-cpp 到最新
git submodule update --init --force --remote
```
### 2. 使用特定版本的 mirai-cpp

如果你目前使用的是旧版本的 mirai/mirai-console/mirai-api-http，请根据 **mirai-api-http** 的版本号选择对应的 **mirai-cpp** 版本，以保证兼容性。

例如，mirai-api-http 的版本为 **1.8.4**，那么请使用 **mirai-cpp v1.8.4**。

切换方法如下：

```bash
cd mirai-cpp
git pull
git checkout v1.8.4
```

## 编译出 Linux 可执行文件、部署到服务器上

操作方法：

1. 在 WSL 上编译出二进制可执行文件
2. 把编译出来的二进制可执行文件复制到自己的服务器上

以下内容需要你了解 **WSL** (**W**indows **S**ubsystem for **L**inux) 。

使用 Visual Studio 的 CMake 项目可以很轻松的在 WSL 上进行编译。

按照如图所示步骤，创建一个针对 WSL 平台的配置。因为我的 WSL 安装了 GCC 编译器，所以这里选择 **WSL-GCC-Releas**。

![创建WSL-GCC平台配置1](./doc/pic/vs_3.png)

![创建WSL-GCC平台配置2](./doc/pic/vs_configure_linux_project.png)

之后将配置切换到刚刚创建的 WSL 平台配置，重新编译项目，编译出来的二进制文件就在 **[本模板所在的目录]/out/build/WSL-Release/** 目录下了(不出意外的话，它叫做 **my-qqrobot** )。

把这个文件复制到你的 Linux 服务器上，可以直接运行！
