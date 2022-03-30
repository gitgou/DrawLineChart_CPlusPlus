Note:
  
  C++ 调用 python 函数代码案例: 使用 python matplotlib 库绘制折线图。

#依赖:

     python -m pip install  matplotlib

#编译:

在Windows下需要安装Visual Studio。在Visual Studio命令提示符下，编译命令为:

    cl output.cpp -IC:\Python27\include C:\Python27\libs\python27.lib

Linux/Mac 编译:

    g++ -std=c++11 output.cpp  -I /usr/include/ -L /usr/lib -l python2.7

