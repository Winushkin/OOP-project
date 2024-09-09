#include "application.h"
#include "array.h"
#include "Windows.h"
using namespace std;

int main(){
    SetConsoleOutputCP(CP_UTF8);
    Application app = Application();
    app.exec();
    return 0;
}