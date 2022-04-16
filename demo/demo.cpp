#include "RPLidar/rplidar.h"
#include <chrono>
#include <iostream>
#include <thread>


int main(int argc, char *argv[]) {
  std::cout << "RPLidar C++ Interface Demo" << std::endl;
  std::cout << "--------------------------" << std::endl;
  std::cout << "Jordan Ford, 2018    " << std::endl;

  std::string lidar_path = (argc > 1) ? argv[1] : "/dev/ttyUSB0";

  RPLidar rp(lidar_path);
  rp.setBaudrate(115200);
  rp.setMaxDistance(16.0);

  using namespace std::chrono;
  system_clock::time_point start = system_clock::now();

  while (duration_cast<seconds>(system_clock::now() - start).count() < 10) {
    if (auto scan = rp.poll()) {
      std::cout << *scan << std::endl;
    } else {
      std::this_thread::sleep_for(milliseconds(10));
    }
  }

  return 0;
}
