#include "test2.cpp"
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

extern void fun2(); // extern functions should also include corresponding files
extern int a, b;    // global variable defined in others files
#define LENGTH 20
#define WIDTH 30
#define NEWLINE '\n'

const int HEIGHT = 50;
static int count = 5;
void func1(void);
double sum1(double arg[], int size);
struct Book
{
    char name[50];
    int age;
    int page;
};
// transfer into an array
int modarry(double *parry, int size);
// return a reference as left value
double &setValues(int i);
double vals[] = {1, 2, 3, 4, 5};
double &setValues(int i)
{
    return vals[i];
}
// return a local *static* array
int *retarry(void);
int *retarry(void)
{
    static int carry[5];
    for (int i = 0; i < 5; i++)
    {
        carry[i] = i;
    }
    return carry;
}
// class data and method
class Box
{
    //   public:
    char name[20] = "book1";
    int page = 20;

  public:
    int age = 30;
    double volume;
    static int objectNum;

  public:
    Box(double b)
    {
        volume = b;
        objectNum++;
    }
    void getPages(void)
    {
        cout << page << endl;
    }
    void getAge(void);
    friend void optAge(Box box);
    int compare(Box box)
    {
        cout << volume << endl;
        cout << box.volume << endl;
        return volume > box.volume;
    }
};
class SmallBox : Box
{
  public:
    void output(void)
    {
        cout << age << endl;
    }
};
void Box::getAge(void)
{
    cout << age << endl;
}
// void optAge(Box box);
void optAge(Box box)
{
    box.age = 100;
    cout << box.age << endl;
}
int Box::objectNum = 1;

class Animal
{
  public:
    virtual void printani()
    {
        cout << "animal age is" << endl;
    }

  public:
    int age = 8;
};
class Dog : public Animal
{
  public:
    void printani()
    {
        cout << "dog age is" << endl;
    }
    int age = 10;
};
class Bird
{
  public:
    Dog dog1;
};
// 1. 模板的意义为了 重用代码，思想在 先不指定数据类型，调用时指定数据类型
// 2. 模板的执行过程，两次编译，获得数据类型后，真编译
// 3. 语法规则，定义：模板头，类型参数表，返回值类型。调用，显式指定类型；隐式推断类型；多参数类型，指定返回值类型
// 4. 本质还是 一般的函数，只是 抽象了数据类型
// 5. 类模板 实例化时显式指定数据类型；类外定义函数成员，使用 泛指类型，带模板符号；

template <typename T1, typename T2>
T1 func(T1 &t1, T2 &t2)
{
    T1 t3;
    t3 = t1 + t2;
    cout << t3 << endl;
    return t3;
}

template <typename C1, typename C2>
class Clsmod
{
  public:
    // Clsmod(){}
    void func1(C1 c1, C2 c2)
    {
        cout << c1 + c2 << endl;
    }
};

int main(int argc, char *args[])
{
    int i = 1, j = 2, k = 3;
    double ii = 1.5, jj = 2.5, kk = 3.5;
    double balance[6] = {2, 3, 4, 4, 5, 6};
    char cdata[50];
    double *p = NULL;
    int *pint = &j;
    cout << *pint << endl;
    // cout << func<double, int>(ii, i) << endl;
    // Clsmod<int, int> cls1;
    // cls1.func1(i, j);

    Bird bird1;
    Bird *pc = &bird1;
    cout << bird1.dog1.age << endl;
    cout << pc->dog1.age << endl;

    const int &b = i;
    cout << b << endl;
    fun2();
    // // ---------- char string --------------
    // string name;
    // const char *pchar = NULL;
    // string *pstr = NULL;
    // name = "good name";  // 字符串变量
    // pchar = "nice name"; // 常字符指针
    // pstr = &name;
    // name = "hi";
    // cout << *pstr << endl;
    // cout << pchar << endl;
    // cout << name << endl;
    // // ---------- char string ends--------------

    // ofstream outfile;
    // outfile.open("afile.out", ios::app);
    // cout << "input name" << endl;
    // // cin >> cdata;
    // cin.getline(cdata, 20);
    // outfile << cdata << endl;
    // outfile.close();
    // Box *pcls = NULL;
    // Animal *pcls = NULL;
    // Dog dog1;
    // pcls = &dog1;
    // dog1.printani();
    // pcls->printani();
    // pint = new int;
    // cout << new int << endl;
    // Box box1(90);
    // Box box2(30);
    // pcls = &box2;
    // cout << (*pcls).age << endl;

    // cout << Box::objectNum << endl;
    // Box::objectNum = 10;
    // cout << box2.objectNum << endl;
    // cout << Box::objectNum << endl;
    // box1.objectNum = 20;
    // cout << box2.objectNum << endl;
    // box1.age = 50;
    // cout << box1.volume << ' ' << box2.volume << endl;
    // cout << box1.compare(box2);
    // box1.getPages();
    // box1.getAge();
    // SmallBox sbox1;
    // sbox1.output();
    // optAge(box1);
    // cout << box1.age << endl;

    // pint = retarry();
    // cout << pint[2] << endl;

    // setValues(4) = 444;
    // cout << vals[4] << endl;
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << balance[i];
    // }
    // cout << endl;
    // modarry(balance, 6);
    // for (int i = 0; i < 6; i++)
    // {
    //     cout << balance[i];
    // }
    // cout << endl;

    // struct Book book1;
    // strcpy(book1.name, "my book");
    // book1.age = 10;
    // book1.page = 100;
    // cout << book1.name << ' ' << book1.age << ' ' << book1.page << endl;

    // p = balance;

    // cout << sum1(balance, 5) << endl;
    // cout << *p;
    // cout << "," << *balance << endl;
    // cout << *(p + 1);
    // cout << "," << *(balance + 1) << endl;
    // cout << p[3];
    // cout << "," << balance[3] << endl;
    // const double area = 50;
    // printf("hello, world2!\n");
    // printf("hello, world!\n");
    // getchar();
    // cout << a << endl;
    // cout << "area is: " << LENGTH * WIDTH << endl;
    // cout << "area is: " << area << endl;
    // cout << NEWLINE << endl;
    // cout << a << endl;
    // cout << b << endl;
    // while (count--)
    // {
    //     func1();
    // }
    // cout << k / i << endl;
    // cout << k % i << endl;
    // srand((unsigned)time(NULL));
    // cout << rand() << endl;

    return 0;
}

// static local variable keeps its value during the main process
// ignore the definition and initiation
// void func1(void)
// {
//     static int i = 6;
//     i--;
//     cout << "i is " << i;
//     cout << ", count is " << count << endl;
// }
double sum1(double *arg, int size)
{
    double sum;
    for (int i = 0; i < size; i++)
    {
        sum += arg[i];
        cout << i << endl;
    }
    return sum;
}
int modarry(double *parry, int size)
{
    // double barry[size];
    for (int i = 0; i < size; i++)
    {
        parry[i] += 1;
        // barry[i] = parry[i] * 2
    }
    return 0;
}

// local master change 2
// in dev change 1
// in master change 2
// origin change 3 
