#include <iostream>
#include <string>
#include <sstream>

using namespace std;

void echo_char(void)
{
    char c;

    cout << "echo char." << endl;
    //标准IO对象读取单个字符,实现键盘回显
    while(cin >> c) //读入结束符（Linux ctrl+D；Windows ctrl+Z）自动退出
    {
        cout << c <<endl;
    }

    //清除输入流的状态
    cin.clear();
}

void echo_line_string(void)
{
    string s;

    cout << "echo string." << endl;
    //获取一行字符流给字符串回显
    while(getline(cin, s)) //读入结束符自动退出
    {
        cout << s << endl;
    }

    //清除输入流的状态
    cin.clear();
}

void test_io_error(void)
{
    int n;

    cin >> n;
    //读取非数字则失败
    cout << "read result:" << cin.good() << endl;
    cout << "n:" << n << endl;

    //清除输入流的状态
    cin.clear();
}

void test_string_stream(void)
{
    string line;
    //使用可输入输出字符串流sstream（集istringstream、ostringstream）
    stringstream ssm;

    cout << "test string tream." << endl;
    //从标准输入读一行字符串到字符串对象
    getline(cin, line);

    //将字符串对象作为字符串流输入流
    ssm << line;

    //将字符串流输出到标准输出和字符串对象
    cout << ssm.str() << endl;
    ssm >> line;
    cout << line << endl;

    //清除输入流的状态
    cin.clear();
}

int main()
{
    test_io_error();
    echo_char();
    echo_line_string();
    test_string_stream();
}