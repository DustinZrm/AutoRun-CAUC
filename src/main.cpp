#include <iostream>
#include <windows.h>
#include <string>
using namespace std;
int main() {
    cout << "Welcome to auto run system" << endl;
    cout << "Starting..." << endl;
    Sleep(3000);
    float timesum=0.0;
    float x, y;
    x = 39.1030;
    y = 117.3505;
    //执行外部exe文件并传递参数x，y
    for (int i = 0; i < 12; ++i) {
        system(("idevicesetlocation.exe " + to_string(x) + " " + to_string(y)).c_str());
        y += 0.00004;
        cout << x << " " << y << endl;
        Sleep(500);
        timesum += 0.5;
    }
    for (int j = 0; j <= 10; j++) {
        for (int i = 0; i < 12; ++i) {
            system(("idevicesetlocation.exe " + to_string(x) + " " + to_string(y)).c_str());
            y += 0.00004;
            x += 0.000025;
            cout << x << " " << y << endl;
            Sleep(1000);
            timesum += 0.5;
        }
        for (int i = 0; i < 41; ++i) {
            system(("idevicesetlocation.exe " + to_string(x) + " " + to_string(y)).c_str());
            x += 0.000025;
            cout << x << " " << y << endl;
            Sleep(500);
            timesum += 0.5;
        }
        for (int i = 0; i < 12; ++i) {
            system(("idevicesetlocation.exe " + to_string(x) + " " + to_string(y)).c_str());
            y -= 0.00004;
            x += 0.000025;
            cout << x << " " << y << endl;
            Sleep(500);
            timesum += 0.5;
        }
        for (int i = 0; i < 12; ++i) {
            system(("idevicesetlocation.exe " + to_string(x) + " " + to_string(y)).c_str());
            y -= 0.00004;
            x -= 0.000025;
            cout << x << " " << y << endl;
            Sleep(500);
            timesum += 0.5;
        }
        for (int i = 0; i < 41; ++i) {
            system(("idevicesetlocation.exe " + to_string(x) + " " + to_string(y)).c_str());
            x -= 0.000025;
            cout << x << " " << y << endl;
            Sleep(500);
            timesum += 0.5;
        }
        for (int i = 0; i < 12; ++i) {
            system(("idevicesetlocation.exe " + to_string(x) + " " + to_string(y)).c_str());
            y += 0.00004;
            x -= 0.000025;
            cout << x << " " << y << endl;
            Sleep(500);
            timesum += 0.5;
        }
        cout << "lap" << j << endl;
        cout << "location shifting" << endl;
        if (j % 2 == 0)x += 0.000025;
        else x -= 0.000025;
        if (j % 2 == 0)y -= 0.00004;
        else y += 0.00004;
    }
    //时间按x分钟x秒格式化后输出
    int x1 = timesum / 60;
    int x2 = timesum;
    x2 = x2 % 60;
    cout << "Time: " << x1 << ":" << x2 << endl;
    cout << "Finished" << endl;
    cout << "Resetting location..." << endl;
    system("idevicesetlocation.exe reset");
    Sleep(3000);
    return 0;
}
