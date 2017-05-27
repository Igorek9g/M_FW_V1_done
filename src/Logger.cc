//
// Created by idalov on 10.05.17.
//
#include<stdio.h>
#include<stdarg.h>
#include <G4String.hh>
#include "../include/Logger.hh"

namespace {
    G4Mutex aMutex=G4MUTEX_INITIALIZER;
}
std::ofstream Logger::fout;

int Logger::verbose_level = 0;

void Logger::Open(int Verbose_level) {
    verbose_level = (Verbose_level) ? 1 : 0;
    time_t t = time(0);
    struct tm *now = localtime(&t);
    std::ostringstream strs;
    strs << (now->tm_year + 1900) << '_'
         << (now->tm_mon + 1) << '_'
         << now->tm_mday << '_'
         << (now->tm_hour) << '_'
         << (now->tm_min) << '_'
         << (now->tm_sec);
    static G4String path = static_cast<G4String>("../logs/log" + strs.str() + ".txt");
    fout.open(path);
}

void Logger::Close() {
    fout.close();
}



std::string Logger::title(int level) {
    std::ostringstream strs;
    time_t t = time(0);
    struct tm *now = localtime(&t);
    strs << (level ? "INFO:" : "ERROR:") <<
         (now->tm_year + 1900) << '-'
         << (now->tm_mon + 1) << '-'
         << now->tm_mday << '|'
         << (now->tm_hour) << ':'
         << (now->tm_min) << ':'
         << (now->tm_sec) << '|'
         << "ThreadID#" << G4Threading::G4GetThreadId() << ":";
    return strs.str();
}

void Logger::Info(const char *__restrict format,...) {
    if (!verbose_level)return;
    G4AutoLock l(&aMutex);
    try {
        if (!fout.is_open())throw 14;
        fout << title(1);
        const char *__restrict traverse;

        G4double d;
        G4int i;
        char *s;

        va_list arg;
        va_start(arg, format);
        for (traverse = format; *traverse != '\0'; traverse++) {
            while (*traverse != '%') {
                fout << *traverse;
                traverse++;
                if (*traverse == '\0') {
                    fout << std::endl;
                    return;
                }
            }

            traverse++;

            switch (*traverse) {
                case 'c' :
                    i = va_arg(arg, int);
                    fout << char(i);
                    break;

                case 'i' :
                    i = va_arg(arg, G4int);

                    fout << i;
                    break;

                case 'g':
                    d = va_arg(arg, G4double);
                    fout << d;
                    break;

                case 's':
                    s = va_arg(arg, char*);
                    fout << s;
                    break;

                case 'b':
                    i = va_arg(arg, int);
                    fout << ((i) ? "true" : "false");
                    break;
                default:
                    return;
            }
        }
        va_end(arg);
        fout << std::endl;
    } catch (int e) {
        std::cout << "Logger didn't initialize:" << e << std::endl;
    }
}