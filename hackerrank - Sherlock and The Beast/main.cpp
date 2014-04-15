#include <iostream>

using namespace std;

void printR(int count, char c)
{
    for (int i = 0; i < count; ++i)
        cout << c;
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i){
        int x;
        cin >> x;
        if (x < 3){
            cout << "-1";
        } else{
            int d = x / 3;
            int r = x % 3;
            switch (r){
                case 0:printR(x, '5'); break;
                case 1:
                    if (d < 3){
                        cout << "-1";
                    } else{
                        printR(x - 10, '5');
                        printR(10, '3');
                    }
                    break;
                case 2:
                    if (d < 1){
                        cout << "-1";
                    } else{
                        printR(x - 5, '5');
                        printR(5, '3');
                    }
            }
        }
        cout << endl;
    }
    return 0;
}