//
// Created by idalov on 10.05.17.
//

#ifndef FINAL_LOGGER_HH
#define FINAL_LOGGER_HH

#include <fstream>
#include <iostream>
#include <sstream>
#include <G4Threading.hh>
#include <G4AutoLock.hh>
#include <ctime>

//Версия 0.1
//все логи создаются в папке logs, в корне. Если папка отсутствует, то создайте её
//Метод Info рабоает аналогично фцункции printf():
//        %с - одиночный симовл
//        %i - целое число
//        %g - дробное число
//        %s - строка
//        %b - логическая переменная (выводится либо true либо false)


class Logger{
private:
    static std::string title(int level);
    static std::ofstream fout;
    static int verbose_level;
public:
    static void Open(int Verbose_level = 1);
    static void Close();
    static void Info(const char *__restrict,...);

};
#endif //FINAL_LOGGER_HH
