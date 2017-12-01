#include "MFileAPI.h"
#include <cstdio>

int main(void)
{
#ifdef UNICODE
    std::vector<MString> items;
    if (!mdir_GetItemList(L".", items))
        return 1;

    for (auto& str : items)
    {
        printf("item: %ls\n", str.c_str());
    }

    std::vector<MString> paths;
    if (!mdir_GetFullPathList(L"..", paths))
        return 2;

    for (auto& str : paths)
    {
        printf("path: %ls\n", str.c_str());
    }
#else
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
#endif

    return 0;
}
