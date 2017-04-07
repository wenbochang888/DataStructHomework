#include "HeaderFile.h"


void ioFstream()
{
	freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
	
    string item;
    while(cin >> item)
    {
        calOpr(item);
    }

    freopen("CON","w",stdout);
}