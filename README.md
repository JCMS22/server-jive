# server-jive

Test Module :
Test Module was tested using Python 2.7

Server Application :
Application opens a TCP server on port 6969

C++ Setup:
Requires QT5Core and QT5Network.
Tested on Mac OS using QT5.9.1 and compiled with CLang
Project is a CMake project done with CLion

Compile and run :
From Mac OS X:
You can directly run the versioned executable on the root of the repository.

From CLion :
Import project
In CLion->Preferences->Build,Execution,Deployment->CMake
Add the path of the QT Cmake libraries options.
On Mac OS it would be something like this :
-DCMAKE_PREFIX_PATH=/Users/Jayce/Qt/5.9.1/clang_64/lib/cmake
On the executable configuration, set the working directory as this repository root.
Exemple : /Users/Jayce/server-jive
What we need is the JSON folder at the same level as the executable.
The executable should then build and run directly from CLion

From terminal or Qt Creator:

Open the CMake GUI and set the following :

SourceCode Path : This directory
Binary path : doesn't matter
Add the variable CMAKE_PREFIX_PATH with the path to your QT cmake libraries as shown earlier in the CLion section
Then you can click on generate and it should generate without errors.

Open the shell in the path where the binary was generated and execute the make command. This will generate the executable.
You need to copy the generated executable to the root of this repository
(so the executable is at the same level as the JSON folder).

Then you can simply run the application from the terminal.

