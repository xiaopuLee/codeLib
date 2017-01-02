#include <string>
#include <fstream>

#include <fcntl.h>

#include <glog/logging.h>
#include "message.pb.h"

#include <google/protobuf/io/coded_stream.h>
#include <google/protobuf/text_format.h>
#include <google/protobuf/io/zero_copy_stream_impl.h>



using google::protobuf::io::FileInputStream;
using google::protobuf::io::FileOutputStream;
using google::protobuf::io::ZeroCopyOutputStream;
using google::protobuf::io::CodedInputStream;
using google::protobuf::io::ZeroCopyInputStream;
using google::protobuf::io::CodedOutputStream;
using google::protobuf::Message;

const int kProtoLimit = INT_MAX;


bool ReadProtoFromTextFile(const char* filename, Message* proto)
{
    int fd = open(filename, O_RDONLY);
    CHECK_NE(fd, -1) << "file not find" << filename;
    FileInputStream *input = new FileInputStream(fd);
    bool success = google::protobuf::TextFormat::Parse(input, proto);
    delete input;
    close(fd);
    return success;
}

void WriteProtoToTextFile(const Message& proto, const char* filename)
{
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    FileOutputStream *output = new FileOutputStream(fd);
    CHECK(google::protobuf::TextFormat::Print(proto, output));
    delete output;
    close(fd);
}


bool ReadProtoFromBinaryFile(const char* filename, Message* proto)
{
    int fd = open(filename, O_RDONLY);
    CHECK_NE(fd, -1) << "file not found : " << filename;
    ZeroCopyInputStream *raw_input = new FileInputStream(fd);
    CodedInputStream *coded_input = new CodedInputStream(raw_input);
    coded_input->SetTotalBytesLimit(kProtoLimit, 536870912);

    bool success = proto->ParseFromCodedStream(coded_input);
    delete coded_input;
    delete raw_input;
    close(fd);
    return success;
}

void WriteProtoToBinaryFile(const Message& proto, const char* filename)
{
    std::fstream output(filename, std::ios::out | std::ios::trunc | std::ios::binary);
    CHECK(proto.SerializeToOstream(&output));
}


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
