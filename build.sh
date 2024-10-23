cmake -DCMAKE_BUILD_TYPE=Debug -DCMAKE_PREFIX_PATH=/opt/ogon -DCMAKE_INSTALL_PREFIX=/opt/ogon .
make -j $(grep -c '^processor' /proc/cpuinfo) install
