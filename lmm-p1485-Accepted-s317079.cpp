//by pter

#include <cstdio>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1002;

char word[MAX];

int main()
{
    scanf("%s", word);

    int size = strlen(word);

    sort(word, word + size);

    for(int i = 0; i < size; i++)
        printf("%c", word[i]);

    printf("\n");
    return 0;
}
