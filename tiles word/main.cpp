#include <cstdio>
#include <cassert>
#include <cstring>

const int TILE_CNT = 7;

void sortTiles(char * tile)
{
    char ret[TILE_CNT];
    int a = 0, b = TILE_CNT;
    for(int i = 0;i < TILE_CNT;++i)
        if(' ' == tile[i])
            ret[--b] = tile[i];
        else
            ret[a++] = tile[i];
    memcpy(tile, ret, TILE_CNT);
}

bool readWord(FILE * fp, char word[TILE_CNT])
{
    assert(fp);
    for(int i = 0;i < TILE_CNT;++i){
        if(feof(fp))
            word[i] = 0;
        else{
            word[i] = fgetc(fp);
            if('\n' == word[i])
                word[i] = 0;
        }
        if(!word[i])
            return true;
    }
    if(feof(fp) || '\n' == fgetc(fp))
        return true;
    while(!feof(fp) && '\n' != fgetc(fp));
    return false;
}

void toLowercase(char word[TILE_CNT])
{
    for(int i = 0;i < TILE_CNT;++i)
        if('A' <= word[i] && word[i] <= 'Z')
            word[i] += 'a' - 'A';
}

bool useTile(char tiles[TILE_CNT], char c)
{
    for(int i = 0;i < TILE_CNT;++i)
        if(' ' == tiles[i] || c == tiles[i]){
            tiles[i] = 0;
            return true;
        }
    return false;
}

bool testWord(const char word[TILE_CNT], const char tiles[TILE_CNT])
{
    char w[TILE_CNT];
    memcpy(w, word, TILE_CNT);
    toLowercase(w);
    char tmp[TILE_CNT];
    memcpy(tmp, tiles, TILE_CNT);
    for(int i = 0;i < TILE_CNT;++i)
        if(!useTile(tmp, w[i]))
            return false;
    return true;
}

void printWord(const char word[TILE_CNT])
{
    for(int i = 0;i < TILE_CNT;++i){
        if(!word[i])
            break;
        printf("%c", word[i]);
    }
    printf("\n");
}

void findWords(const char * fname, const char tiles[TILE_CNT])
{
    FILE * fp = fopen(fname, "r");
    if(!fp)
        return; //error
    char tile[TILE_CNT];
    memcpy(tile, tiles, TILE_CNT);
    sortTiles(tile);
    for(char word[TILE_CNT];!feof(fp);){
        if(!readWord(fp, word))
            continue;
        if(testWord(word, tile))
            printWord(word);
   }
}

int main()
{
    findWords("input.txt", "ab cdef");
}