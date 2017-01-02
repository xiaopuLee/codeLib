
#include <gflags/gflags.h>

google::ParseCommandLineFlags(&argc, &argv, true);
第三个参数，如果是true，则parse后flags全部会移除，相应的argc和argv会改变，即使设置为false
gflags也会重新指定commandline arguments的顺序使得所有的flags都位于前部


通过设定validator函数可以检测所有的输入flag是否在有效值内
static bool validatorFun(const char* flagname, int value)
{
    if(value > 0 && value < 12)
       return true;
    std::cout << "invalid vlaues : " << flagname << " " << value <<　std::endl;
    return false;
}
DEFINE_int32(intV, 12, "int value");
static bool dummy = google::RegisterFlagValidator(&FLAGS_intV, &validatorFun);


google::SetVersionString("1.0.1"); 指定版本 ./app --version可以看到
google::SetUsageMessage("\n\tuse : ");

如果某个flag在多个文件中使用，在一处定义，然后在使用到的地方
DECLARE_bool(bV);


输入的时候

./app -flag = <value>
./app --flag = <value>
./app -flag  <value>
./app --flag  <value>
都可以，
如果是bool 值，除此之外也可以使用
./app --noBV
./app --BV


如果某个flag定义在一个lib中，而想要改变他的默认值，则可以
DECLARE_bool(lib_verbose);
int main(int argc, char** argv)
{
   FLAGS_lib_verbose = true;
   google::ParseCommandLineFlags(&argc, &argv, true);
}


当然每次都输入一遍参数挺麻烦
可以使用fromenv flagfile
export FLAGS_foo = xxx;
export FLAGS_bar = xxx;
./app --fromenv=foo, bar

从文件中读取
--flagfile=f
f的内容是 每行一个
--foo=xxx
--bar=xxx
