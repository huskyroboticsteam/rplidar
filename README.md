# rplidar_cpp

This is a C++17 interface to the RPLidar series of laser triangulation sensors from RoboPeak that specifically **does not depend on ROS**.

## Getting Started

### Prerequisites

Install cmake and a C++17 compiler.
On Ubuntu, you can install cmake via the following command.

```
sudo apt -y install cmake
```

### Installing

A step by step series of examples that tell you how to get a development env running

Clone the repository.

```
git clone https://github.com/huskyroboticsteam/rplidar.git
```

Use cmake to build and install.

```
cd rplidar_cpp
mkdir build
cd build
cmake ..
make
sudo make install
```

Install the udev rule for the RPLidar.

```
cd rplidar_cpp/scripts
chmod +x create_udev_rules.sh delete_udev_rules.sh
sudo ./create_udev_rules.sh
```

## Running the Demo

After building the code, you can run the demo by plugging in an RPLidar
and running the rpdemo executable as follows:

```
cd rplidar_cpp/build/demo
./rpdemo
```

The demo will start the RPLidar and print scan data for 10 seconds.

## Usage

Place the following in your project's CMakeLists.txt:

```
cmake_minimum_required(VERSION 3.0)
project(YOUR_PROJECT_NAME)

find_package(RPLidar)

add_executable(${CMAKE_PROJECT_NAME} ...)
target_link_libraries(${CMAKE_PROJECT_NAME} RPLidar::RPLidar)
```

In your code, include the RPLidar library as follows:

```
#include <RPLidar/rplidar.h>
```

See [demo.cpp](https://github.com/huskyroboticsteam/rplidar/blob/master/demo/demo.cpp) for an example usage.
Check out [RPLidar/rplidar.h](https://github.com/huskyroboticsteam/rplidar/blob/master/include/RPLidar/rplidar.h) to view the complete interface.

## Authors

* **Jordan Ford** - [jrdnfrd.com](http://jrdnfrd.com)
* **Husky Robotics Team** <uwrobots@uw.edu> - CMake config and SDK updates

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details

## Acknowledgments

* This code makes use of the RPLidar SDK provided by RoboPeak.

