1 setting flags

  可以在程序内部指定保存日志目录FLAGS_log_dir="log",但是这条语句必须是在最初始化的时候就设定，中途不宜改变

  logtostderr default=false
   把日志输出到命令行而不是保存为文件
　　stderrthreshold(int, default=2)
   除了输出到日志文件中，另外将该等级以上的日志信息输出到命令行，默认是ERROR以上的
　　minloglevel(int, default=0)
   安装INFO WARNING ERROR FATAL的顺序决定输出日志的等级，默认是０以上的也就是INFO以上的全输出
　　log_dir(string, default="")
   日志存放目录，默认是空，ubuntu下会存在/tmp中，

２　编译命令
　　　　g++ <某cpp文件> -lglog

３　LOG_IF(INFO, condition) << "";
    LOG_EVERY_N(INFO, number) << google::COUNTER << "";
    LOG_IF_EVERY_N(INFO, condition, number) << google::COUNTER;
    LOG_FIRST_N(INFO, number) << "";

    CHECK(condition) << "log";
    CHECK_EQ(1, 2) << "error"
    CHECK_NE CHECK_LE CHECK_LT CHECK_GE CHECK_GT
    如果条件不满足，会输出FATAL信息, 并且比较的信息必须支持operator<<(ostream, ...)
　　　　
　　　　CHECK_NOTNULL(pointer);
    这条命令返回输入的指针，因此并不支持输出某些辅助log
    CHECK_EQ(pointer, static_cast<sometype*>(NULL)) << "log";
　　　　
    针对c strings(char*)，有这些宏可以使用
　　　　CHECK_STREQ CHECK_STRNE CHECK_STRCASEEQ CHECK_CASENE,
    上述宏可以接受NULL参数．
    
对于window用户来说，ERROR在windows.h中也有定义
    
    

