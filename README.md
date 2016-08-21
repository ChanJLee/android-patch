# AndroidPatch
用于实现Android端的增量升级

# 目录结构
- ypatchcore  是Android Studio工程，用于编译生成Android客户端的patch工具。
- serverpatch 是用于生成服务器版本的diff，patch源代码

# 安装
1：对于ypatchcore直接导入到Android Studio中就可以
2：对于serverpatch，首先先安装bzip2库，解压bzip2-1.0.6.tar.gz，执行make就行。然后再编译bsdiff，解压bsdiff-4.3.tar.gz，运行make程序就行

使用：
服务器端运行bsdiff old_file new_file patch_file生成差异文件，Android加入如下代码:

```
YPatch.patch(oldFilePath, newFilePath, patchFilePatch)
```

将合成后的文件保存到newFilePath下
