// Fill out your copyright notice in the Description page of Project Settings.


#include "MyUserWidget.h"

#include <fstream>
#include <string>
#include <vector>
#include <limits>



using namespace std;

vector<int> numbers;
string records[10];
vector<string> outs;

void reading() {
    std::ifstream file("E:/MyGame/Record.txt");


    std::string line;
    if (std::getline(file, line)) {
    }
    else {
        std::cout << "Error reading from file" << std::endl;
    }

    for (int i = 0; i < 10; i++) {
        numbers.push_back(i);
        records[i] = "";
    }

    int k = 0;


    for (int i = 0; i < line.size(); i++) {
        if (line[i] != ' ') {
            records[k] += line[i];
        }
        else
        {
            k++;
        }
    }

    file.close();
}

void gnomSort()
{

    int index = 0;
    int n = 10;

    while (index < n)
    {
        if (index == 0)
            index++;
        if (numbers[index] >= numbers[index - 1])
            index++;
        else
        {
            std::swap(records[index], records[index - 1]);
            std::swap(numbers[index], numbers[index - 1]);
            index--;
        }
    }
}


void combaSort() {

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
            if (records[i] < records[i + gap]) {
                std::swap(records[i], records[i + gap]);
                std::swap(numbers[i], numbers[i + gap]);
                sorted = false;
            }
        }
    }
}

TArray<FString> UMyUserWidget::vec_number() {
    TArray<FString> Numbers;
    reading();
    outs.clear();
    gnomSort();
    for (int i = 0; i < 10; i++) {
        string stroka;
        stroka = to_string(numbers[i]) + '.' + records[i];
        outs.push_back(stroka);
    }
    for (int i = 0; i < 10; i++) {
        FString stroka(outs[i].c_str());
        Numbers.Add(stroka);
    }
    return Numbers;
}

TArray<FString> UMyUserWidget::vec_time() {
    TArray<FString> Times;
    reading();
    outs.clear();
    combaSort();
    for (int i = 0; i < 10; i++) {
        string stroka;
        stroka = to_string(numbers[i]) + '.' + records[i];
        outs.push_back(stroka);
    }
    for (int i = 0; i < 10; i++) {
        FString stroka(outs[i].c_str());
        Times.Add(stroka);
    }
    return Times;
}


void UMyUserWidget::output(FString param){
    std::string stdParam(TCHAR_TO_UTF8(*param));
    cout << stdParam << "\n";
    reading();
    combaSort();
    if (stdParam > records[9]) {
        records[9] = stdParam;
    }
    gnomSort();
    std::string wr = "";
    for (int i = 0; i < 10; i++) {
        if (i != 9) {
            wr += records[i];
            wr += " ";
        }
        else {
            wr += records[i];
        }
    }

    std::ofstream outFile("E:/MyGame/Record.txt", std::ios::out | std::ios::trunc);

    if (outFile.is_open()) {
        outFile << wr;

        outFile.close();
        cout << wr;
    }
    else {
        cout << "error";
    }
}