#pragma once 

#include <thread>
#include <string>
#include <filesystem>

class ThriftPortController {
    unsigned short  port_;
    bool            stop = false;
    std::string     fifo_filename_;                
    
    std::filesystem::path     fifo_path_in_,
                              fifo_path_out_;
    
    std::thread     fifo_thread_;

    void fifo_loop();
public:

    ThriftPortController(unsigned short port);
    ~ThriftPortController();
};