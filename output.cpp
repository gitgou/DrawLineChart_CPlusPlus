#include<python2.7/Python.h>
#include<vector>
#include<string>
#include<iostream>
using namespace std;

int main()
{
	Py_Initialize();    // 初始化
	vector<int> vec1{1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	vector<int> vec2{2, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	//创建参数元组
	PyObject* pPyArgs = PyTuple_New(2);

	//传入 list k1 
	PyObject* pList_1 = PyList_New(vec1.size());
	for(int i = 0; i < vec1.size(); ++i)
	{
		PyList_SetItem(pList_1, i, Py_BuildValue("i", vec1[i]));
	}
	PyTuple_SetItem(pPyArgs, 0, pList_1);
	//传入 list k2 
	PyObject* pList_2 = PyList_New(vec2.size());
	for(int i = 0; i < vec2.size(); ++i)
	{
		PyList_SetItem(pList_2, i, Py_BuildValue("i", vec2[i]));
	}
	
	PyTuple_SetItem(pPyArgs, 1, pList_2);

    // 将Python工作路径切换到待调用模块所在目录，一定要保证路径名的正确性
    string path = "./pylib";
    string chdir_cmd = string("sys.path.append(\"") + path + "\")";
    cout << chdir_cmd << endl;
	PyRun_SimpleString("import sys");
    PyRun_SimpleString(chdir_cmd.c_str());

	PyObject* moduleName = PyString_FromString("draw"); //模块名，不是文件名
    PyObject* pModule = PyImport_Import(moduleName);
    if (!pModule) // 加载模块失败
    {
        cout << "[ERROR] Python get draw module failed." << endl;
        return 0;
    }
    cout << "[INFO] Python get draw module succeed." << endl;

    // 加载函数
    PyObject* pv = PyObject_GetAttrString(pModule, "draw");
    if (!pv || !PyCallable_Check(pv))  // 验证是否加载成功
    {
        cout << "[ERROR] Can't find funftion (draw)" << endl;
        return 0;
    }
    cout << "[INFO] Get function (draw) succeed." << endl;

    // 调用函数
    PyObject* pRet = PyObject_CallObject(pv, pPyArgs);
	
	Py_Finalize();

	return 0;
}
