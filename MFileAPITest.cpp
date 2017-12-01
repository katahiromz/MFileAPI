#include "MFileAPI.h"
#include <cstdio>

int main(void)
{
    std::vector<MString> items;
    if (!mdir_GetItemList(".", items))
        return 1;

    for (auto& str : items)
    {
        printf("item: %s\n", str.c_str());
    }

    std::vector<MString> paths;
    if (!mdir_GetFullPathList("..", paths))
        return 2;

    for (auto& str : paths)
    {
        printf("path: %s\n", str.c_str());
    }

    return 0;
}
