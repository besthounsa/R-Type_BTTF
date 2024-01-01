# **R-Type**
The goal of the Epitech R-Type project is to implement a multithreaded server and a graphical client for a game called R-Type, using an engine of our own design.

## Pre-requisites
What you need to get started with our project...

![Linux](https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black)
![Windows](https://img.shields.io/badge/Windows-0078D6?style=for-the-badge&logo=windows&logoColor=white)
![C++](https://img.shields.io/badge/c++-%2300599C.svg?style=for-the-badge&logo=c%2B%2B&logoColor=white)
![CMake](https://img.shields.io/badge/CMake-%23008FBA.svg?style=for-the-badge&logo=cmake&logoColor=white)
![GitHub Actions](https://img.shields.io/badge/github%20actions-%232671E5.svg?style=for-the-badge&logo=githubactions&logoColor=white)

## Project layout

    This advanced C++ knowledge unit project introduces you to the development of networked video games and gives you the opportunity to explore advanced development techniques and learn how to develop networked video games.
    Also, gives you the opportunity to explore advanced development techniques as well as learn good software engineering practices.

    Firstly, you'll develop the game's basic architecture and deliver a working prototype.
    Secondly, we'll develop several aspects of the prototype, exploring specialized areas of our choice from a list of proposed options.
    
***

It uses two libraries:

- 🎮​ [SFML](https://www.sfml-dev.org), The library used to display.
- 🛰️ [BOOST ASIO](https://www.boost.org), The library used to manage communication, threads and processes.

## Installation
```sh
$ git clone git@github.com:EpitechPromo2026/B-CPP-500-COT-5-1-rtype-shalom.ayitchehou.git
```
or
``` hp
$ git clone https://github.com/EpitechPromo2026/B-CPP-500-COT-5-1-rtype-shalom.ayitchehou.git
```

### **Packages managers**

R-Type has been managed with the following package managers:

- 🛠️ [CMAKE](https://cmake.org)
- 🗂️​ [CONAN](https://conan.io)

## **Build the program**

On Linux :

- You may execute the script `build.sh` or the following commands :

```bash
    cmake -B ./build -DCMAKE_BUILD_TYPE=Release
    cmake --build ./build
```

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
 
The code documentation is available:

[Server](https://lucid.app/lucidchart/dcd631c4-4265-47fa-81f6-ebf7fe80d5ed/edit?viewport_loc=167%2C-45%2C2212%2C1043%2CHWEp-vi-RSFO invitationId=inv_33d50535-be60-460c-a122-5483f01b67e8. )

[Client](https://lucid.app/lucidchart/1f1aadfa-2631-49be-9e85-a9ce490fd09b/edit?view_items=JVm1QveUth_l&invitationId=inv_3e05bed4-eff8-4b51-8ff4-7fa0b386eb5d<br>
Additional documentation such as the protocols used for the network are available . [here](https://traff.co/GKS3lx7Y))
***