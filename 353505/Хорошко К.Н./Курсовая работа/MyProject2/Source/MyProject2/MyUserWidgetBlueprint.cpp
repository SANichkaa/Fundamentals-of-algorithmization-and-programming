// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidgetBlueprint.h"
#include <fstream>
#include <string>
#include <vector>
#include <limits>



using namespace std;

vector<int> number;
string record[10];
vector<string> out;

void read() {
    std::ifstream file("E:/MyGame/Record.txt");


    std::string line;
    if (std::getline(file, line)) {
    }
    else {
        std::cout << "Error reading from file" << std::endl;
    }

    for (int i = 0; i < 10; i++) {
        number.push_back(i);
        record[i] = "";
    }

    int k = 0;


    for (int i = 0; i < line.size(); i++) {
        if (line[i] != ' ') {
            record[k] += line[i];
        }
        else
        {
            k++;
        }
    }

    file.close();
}

void gnomeSort()
{

    int index = 0;
    int n = 10;

    while (index < n)
    {
        if (index == 0)
            index++;
        if (number[index] >= number[index - 1])
            index++;
        else
        {
            std::swap(record[index], record[index - 1]);
            std::swap(number[index], number[index - 1]);
            index--;
        }
    }
}


void combSort() {

    int n = 10;
    int gap = n;
    const double shrinkFactor = 1.3; // Фактор уменьшения шага
    bool sorted = false;

    while (!sorted) {

        gap = static_cast<int>(gap / shrinkFactor);
        if (gap <= 1) {
            gap = 1;
            sorted = true;
        }

        for (int i = 0; i + gap < n; ++i) {
            if (record[i] < record[i + gap]) {
                std::swap(record[i], record[i + gap]);
                std::swap(number[i], number[i + gap]);
                sorted = false;
            }
        }
    }
}

TArray<FString> UMyUserWidgetBlueprint::vec_number() {
    TArray<FString> Numbers;
    read();
    out.clear();
    gnomeSort();
    for (int i = 0; i < 10; i++) {
        string stroka;
        stroka = to_string(number[i]) + '.' + record[i];
        out.push_back(stroka);
    }
    for (int i = 0; i < 10; i++) {
        FString stroka(out[i].c_str());
        Numbers.Add(stroka);
    }
    return Numbers;
}

TArray<FString> UMyUserWidgetBlueprint::vec_time() {
    TArray<FString> Times;
    read();
    out.clear();
    combSort();
    for (int i = 0; i < 10; i++) {
        string stroka;
        stroka = to_string(number[i]) + '.' + record[i];
        out.push_back(stroka);
    }
    for (int i = 0; i < 10; i++) {
        FString stroka(out[i].c_str());
        Times.Add(stroka);
    }
    return Times;
}