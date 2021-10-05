// ConsoleApplication1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <chrono>
#include <thread>
using namespace std;

class Lib {
public:
    /// <summary>
    /// For making strings print one character at a time
    /// </summary>
    /// <param name="msg">The string that will be printed.<para>does not work with the "value: {0}",var method, use "value: "+var</para></param>
    /// <param name="scrollTime">Time between each character being printed in thousands of a second.</param>
    /// <param name="finishTime">Time after the string is finished in thousands of a second.</param>
    /// <param name="lineBreak">How many times \n is sent AFTER msg</param>
    /// <param name="tabs">How many times \t is sent BEFORE msg</param>
    void Scroll(string msg, unsigned int scrollTime = 30, unsigned int finishTime = 1000, unsigned int lineBreak = 1, unsigned int tabs = 1) {
        for (unsigned int  i = 0; i < tabs; i++) {
            cout << "\t";
        }

        for (unsigned int i = 0; i < msg.length(); i++) {
            this_thread::sleep_for(std::chrono::milliseconds(scrollTime));
            cout << msg[i];
        }

        for (unsigned int  i = 0; i < lineBreak; i++) {
            cout << "\n";
        }
        this_thread::sleep_for(std::chrono::milliseconds(finishTime));
    }

    void BasicBox(string msg) {
        cout << "\t ";
        for (unsigned int i = 0; i < msg.length() + 1; i++)
        {
            Scroll("_", 2, 0, 0, 0);
        }
        Scroll("_\n\t| ", 2, 0, 0, 0);
        Scroll(msg, 5, 10, 0, 0);
        Scroll(" |\n\t|", 2, 0, 0, 0);
        for (unsigned int i = 0; i < msg.length() + 2; i++)
        {
            Scroll("_", 2, 0, 0, 0);
        }
        Scroll("|", 30, 1000, 1, 0);
    }
};

void main()
{
    cout << "Hello World!\n";
    Lib _Lib;

    string inp;
    _Lib.Scroll("Input:");
    cin >> inp;
    _Lib.Scroll(inp);
    _Lib.BasicBox(inp);
};