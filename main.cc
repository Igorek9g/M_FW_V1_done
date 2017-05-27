#include <iostream>
#include <Logger.hh>
#include <Loader.hh>

int main(int argc, char** argv) {
    Logger::Open(1);

    Loader* loader = new Loader(argc,argv);
    delete loader;

    Logger::Close();
    return 0;
}