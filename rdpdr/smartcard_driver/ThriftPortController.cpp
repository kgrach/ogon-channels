#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
#include <cstdlib>
#include <chrono>
using namespace std::chrono_literals;

#include "ThriftPortController.hpp"

ThriftPortController::ThriftPortController(unsigned short port) : port_(port) {

    std::error_code ec;

    fifo_filename_ = std::getenv("OGON_COOKIE");    

    fifo_path_in_ = "/tmp/";
    fifo_path_in_ += fifo_filename_;
    fifo_path_in_ += ".in";

    fifo_path_out_ = "/tmp/";
    fifo_path_out_ += fifo_filename_;
    fifo_path_out_ += ".out";
    
    //if(std::filesystem::exists(fifo_path_in_, ec)) {
        std::filesystem::remove(fifo_path_in_.c_str(), ec);
    //}

    mkfifo(fifo_path_in_.c_str(), 0777);

    //if(std::filesystem::exists(fifo_path_out_, ec)) {
        std::filesystem::remove(fifo_path_out_.c_str(), ec);
    //}

    mkfifo(fifo_path_out_.c_str(), 0777);

    fifo_thread_ = std::move(std::thread(&ThriftPortController::fifo_loop, this));
}

ThriftPortController::~ThriftPortController() {
    
    std::error_code ec;

    stop = 1;

    fifo_thread_.join();
    
    std::filesystem::remove(fifo_path_in_.c_str(), ec);
    std::filesystem::remove(fifo_path_out_.c_str(), ec);
}

void ThriftPortController::fifo_loop() {
  
    int len;
    
    char buf[100];
    int fd_r, fd_w;

    if ( (fd_r = open(fifo_path_in_.c_str(), O_RDONLY | O_NONBLOCK)) > 0 &&
         (fd_w = open(fifo_path_out_.c_str(), O_RDWR | O_NONBLOCK )) > 0 ) {
       
        do {

            if(stop)
                break;
         
            len = read(fd_r, buf, sizeof(buf));

            if(!stop && len > 0) {
                write(fd_w, &port_, 2);
                len = 0; 
            }

            std::this_thread::sleep_for(500ms);
            
        } while ( true );

        close(fd_r);
        close(fd_w);
    }
}