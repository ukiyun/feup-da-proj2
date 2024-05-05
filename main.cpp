#include "Code/include/Interface.h"
#include <locale.h>

int main() {
    setlocale(LC_ALL, "pt-PT");
    Interface i;
    i.open();
    return 0;
}
