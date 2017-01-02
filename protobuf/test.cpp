#include <string>
#include <fstream>

#include <fcntl.h>

#include <glog/logging.h>
#include "message.pb.h"

#include "util.cpp"

int main()
{
    FLAGS_log_dir = "./log";
    google::InitGoogleLogging("main");

    Test::Config config = Test::Config();
    std::string path = "config.prototxt";

    bool res = ReadProtoFromTextFile(path.c_str(), &config);

    LOG(INFO) << "the name of the config : " << config.name();
    LOG(INFO) << "the number of the config : " << config.number();
    if(config.reuse())
    {
        LOG(INFO) << "the reuse flag is set";
    }
    LOG_IF(INFO, config.reuse()) << "reuse is set";

    //config.mutable_name() = "sharp";
    config.set_name("sharp");

    
    LOG(INFO) << "the elem size : " << config.elem_size();

    LOG(INFO) << "start to add elem ";

    for(int id=0; id!=10; ++id)
    {
        config.add_elem(id * 1.1);
    }
    LOG(INFO) << "current elem size : " << config.elem_size();

    WriteProtoToTextFile(config, "res.prototxt");
    WriteProtoToBinaryFile(config, "res.bin");

    //res = ReadProtoFromBinaryFile("res.bin2", &config);
    //if(res)
    //{
    //LOG(INFO) << "success parse from binary";
     //   LOG(INFO) << "name : " << config.name();
       // LOG(INFO) << "number : " << config.number();
      //  LOG_IF(INFO, config.reuse()) << "reuse is set too";
    //}
    //else
    //{
     //   LOG(ERROR) << "failed to read from binary";
    //}
    return 0;
}
