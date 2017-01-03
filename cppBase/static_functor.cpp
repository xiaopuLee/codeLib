#include <iostream>
#include <glog/logging.h>

struct Person
{
    Person(std::string name_, int age_):
        name(name_), age(age_){}
    std::string name;
    int age;
};

struct Ani
{
    Ani(std::string name_, int age_):
        name(name_), age(age_){}
    std::string name;
    int age;
};

struct Com
{
    bool operator()(Person alpha, Person beta)
    {
        return alpha.age < beta.age;
    }

    bool operator()(Ani alpha, Ani beta)
    {
        return alpha.age < beta.age;
    }

    int operator()(int num)
    {
        return num * num;
    }
};

void fun(int num)
{
    static int id = 1;
    LOG(INFO) << "current id : " << id;
    //++id;
    id = id + num;
}

int main()
{
    FLAGS_log_dir = "log";
    google::InitGoogleLogging("static");

    for(int id=0; id!=100; ++id)
    {
        //fun(id);
        fun(id);
    }

    Person a("sharp", 23);
    Person b("he", 454);
    
    Com com = Com();

   if(com(a, b))
   {
       LOG(INFO) << "a is smaller than b";
   }
   else
   {
       LOG(INFO) << "a is bigger than b";
   }
   
   Ani aa("aa", 12), bb("bb", 15);
   if(com(aa, bb))
   {
       LOG(INFO) << "aa is smaller than bb";
   }
   else
   {
       LOG(INFO) << "aa is bigger than bb";
   }


   int num = 11;
   CHECK_EQ(num * num, com(num)) << "failed, they are not equal";
   LOG(INFO) << com(num);

    return 0;
}
