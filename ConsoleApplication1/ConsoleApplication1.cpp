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

int main()
{
#pragma region main shit that actually works good
    string name;

    cout << "Hello World!\n";
    Lib _Lib;

    string inp;
    _Lib.Scroll("Input:");
    cin >> inp;
    _Lib.Scroll(inp);
    _Lib.BasicBox(inp);
#pragma endregion

    //---------------
    tm then{};
    chrono::system_clock::time_point inpTime;
    cout << "enter\nyear month day\n";
    cin >> then.tm_year >> then.tm_mon >> then.tm_mday;
    
    //cc now contains the input date as a time_point

    //---------------------------

    auto today = std::chrono::system_clock::now();

    cout << "today: "<< then.tm_year;

    std::chrono::duration<double> elapsed_years = (today - inpTime) / 31536000;

    std::cout <<"\nelapsed time: " << elapsed_years.count() << "s\n";

    //----------------------------

    const auto p1 = std::chrono::system_clock::now();
    const auto p2 = p1 - std::chrono::hours(24);

    std::time_t today_time = std::chrono::system_clock::to_time_t(p1);

    #pragma warning(disable:4996) //stops the ide complaining about ctime's depreciation
    std::cout << "today: " << std::ctime(&today_time);

    cout << today_time - then;

    /*
    typedef std::chrono::high_resolution_clock Time;
    typedef std::chrono::hours h;
    typedef std::chrono::duration<float> fsec;
    auto t0 = Time::now();
    auto t1 = Time::now();
    fsec fs = t1 - t0;
    h d = std::chrono::duration_cast<h>(fs);
    std::cout << fs.count() << "h\n";
    std::cout << d.count() << "ms\n";
    */
};