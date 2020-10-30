//Примерный поиск слова в файле и его последующий вывод с указание времени выполения
//На входе, имя файла и искомое слова
//На выхоже список слов и время выполнения

#include <iostream>
#include <fstream>
#include <string>
#include <time.h> 
#include <cmath>

using namespace std;

//Функция сравнения слов
bool chec(string a_word, string b_word){
    int err = 0;//Число различий между словами
    int r = fabs(a_word.size()- b_word.size());//Модуль разницы длинны слов
    if(r >= 2){//Если разница более 2х буквы солово не выводим
        return false;
    }
    else if(r==0){
        for (int i = 0; i < a_word.size(); i++)//При равенстве длинны слов сравниваем каждую мекву между собой и считаем различия
            if (a_word[i]!=b_word[i])
                err++;}
    else{//Если разница в длинне слов в 1 симвов 
        if (a_word[0] == b_word[0])//Сравнивае первые буквы
        {
            for (int i = 0; i < a_word.size(); i++){//Повторяем прошый случай
                if (a_word[i]!=b_word[i])
                    err++;}
            
        }else//Если первые буквы не равны
        {
            err=1;//Сохраняем разницу
            if (a_word.size() == 1){//Спец условие для случая одной буквы
                if (a_word[0]!=b_word[1])
                    err++;
                }
            else
            {            
                for (int i = 1; i < a_word.size()+1; i++){//То то же алгоритм что и раньше, но сраниваемое слоло сдвигаем
                    if (a_word[i]!=b_word[i-1])
                        err++;
                }
            }     
        }
    }

    if (err <= 1)// сравнение разницы с допустимой
        return true;
        
    return false;
}


int main(){

    clock_t start, end;

    start = clock();//Начало отсчета времени

    cout << "file name: ";
    string filename = "test.tst";   
    cin >> filename;
    
    string line;

    fstream in(filename);//Инициализация файла

    if(in.is_open()){//Проверка файла на существование

        cout << "slovo: ";
        string word = "hell";
        cin >> word;

        while (getline(in, line))//прогонка по всем строкам файла
        {            
            if(chec(line, word))//Запуск функции сравнения
                cout << line << endl;
        }
    }
    else
    {
        cout << "file undifine" << endl;
    }
    
    in.close();

    end = clock();

    cout << "time: " << ((double) end - start)/((double) CLOCKS_PER_SEC) << endl;

    return 0;
}