#include <iostream>
#include <gflags/gflags.h>


static bool ValidatorIntV(const char* flagname, int value)
{
    if(value > 0 && value < 255)
    {
        return true;
    }
    std::cout << "invalid values : " << flagname << " : " << value << std::endl;
    return false;
}


DEFINE_bool(bV, true, "bool values");
DEFINE_string(strV, "hello_world", "string values");
DEFINE_int32(intV, 12, "int value");
static bool dummy = google::RegisterFlagValidator(&FLAGS_intV, &ValidatorIntV);
DEFINE_uint64(uint64V, 12, "int value");
DEFINE_int64(int64V, 12, "int value");
DEFINE_double(doubleV, 1.2, "double value");


int main(int argc, char** argv)
{
    google::SetVersionString("1.0.1");
    google::SetUsageMessage("use : ");
    google::ParseCommandLineFlags(&argc, &argv, true);

    std::cout << "argc : " << argc << std::endl;

    std::cout << argv[0] << std::endl;
    std::cout << argv[1] << std::endl;

    if(FLAGS_bV)
    {
        std::cout << "bv value is set, default is true " << std::endl;
    }
    else
    {
        std::cout << "bv not set" << std::endl;
    }

    std::cout << "string value : " << FLAGS_strV << std::endl;
    std::cout << "int value : " << FLAGS_intV << std::endl;
    std::cout << "double vaule : " << FLAGS_doubleV << std::endl;


    return 0;
}
