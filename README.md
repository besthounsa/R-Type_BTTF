# **R-Type**

![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black) ![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)

![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
 ![GitHub Actions](https://img.shields.io/badge/github%20actions-%232671E5.svg?style=for-the-badge&logo=githubactions&logoColor=white)
***

## **Table of Contents**

- [**Table of Contents**](#table-of-contents)
- [**Introduction**](#introduction)
- [**Packages managers**](#packages-managers)
  - [**Supported Platforms**](#supported-platforms)
- [**The Game**](#the-game)
- [**How to play ?**](#how-to-play-)
  - [**Prerequisites**](#prerequisites)
  - [**Launch the game**](#launch-the-game)
- [**For developers**](#for-developers)
  - [**Build the program**](#build-the-program)
  - [**Documentation**](#documentation)
- [**Thank for reading**](#thank-for-reading)
- [**Authors**](#authors)

***

## **Introduction**

The goal of the Epitech R-Type project is to implement a multithreaded server and a graphical client for a game called R-Type, using an engine of our own design.

The project is composed of two parts: the server and the client, both in C++.

It uses two libraries:

- 🎮​ [SFML](https://www.sfml-dev.org), The library used to display.
- 🛰️ [BOOST ASIO](https://www.boost.org), The library used to manage communication, threads and processes.

### **Packages managers**

R-Type has been managed with the following package managers:

- 🛠️ [CMAKE](https://cmake.org)
- 🗂️​ [CONAN](https://conan.io)

### **Supported Platforms**

The R-Type project is supported on Windows AND Linux !!

***

## **The Game**

 R-type is an advanced c++ project which consist to develop a network video game. This game content a multithreaded  server and a graphical client,using an engine of our own design. This project explore in-depth advanced development topics and good software engineering practices. 

## **How to play ?**

### **Prerequisites**

To build our R-Type project, you will need CMake 2.8.0 Compiler, C++ 17 and Conan.

### **Launch the game**

***

## **For developers**

### **Build the program**

On Linux :

- You may execute the script `build.sh` or the following commands :

```bash
    cmake -B ./build -DCMAKE_BUILD_TYPE=Release
    cmake --build ./build
```

On Windows :

- You may execute the script `build.bat` or the following commands :

```bash
    mkdir build
    cd build
    conan install .. --build=missing  -c tools.system.package_manager:mode=install -c tools.system.package_manager:sudo=True
    cd ..
    cmake -B ./build -DCMAKE_BUILD_TYPE=Release
    cmake --build ./build
    copy ".\Debug\r-type_server.exe" .
    copy ".\Debug\r-type_client.exe" .
```

### **Documentation**

The code documentation is available [here](https://dossoucharbel.github.io/documentation/). <br>
Additional documentation such as the protocols used for the network are available . [here](https://traff.co/GKS3lx7Y).

***

## **Thank for reading**

Do not hesitate to contact any member for any questions or remarks. You can click on each following name.

## **Authors**

[```Shalom AYITCHEOU```](```shalom.ayitcheou@epitech.eu```)
[```Best HOUNSA```](```best.hounsa@epitech.eu```)
[```Mouamar ADJAHO```](```mouamar.adjaho@epitech.eu```)
[```Charbel DOSSOU```](```charbel.dossou@epitech.eu```)
[```Fabrice KLOUE```](```mingnisse.kloue@epitech.eu```)