#include  <fstream>
#include <cstdlib>
#include <string>
#include <algorithm>
#include <time.h>
using namespace std;

void CombSort( int tab[], int sizee )
{
    int gap = sizee;
    bool replacee = true;

    while( gap > 1 || replacee )
    {
        gap = gap * 10 / 13;
        if( gap == 0 )
             gap = 1;

        replacee = false;
        for( int i = 0; i + gap < sizee; i++ )
        {
            if( tab[ i + gap ] < tab[ i ] )
            {
                swap( tab[ i ], tab[ i + gap ] );
                replacee = true;
            }
        }
    }
}
int main(){
    return 0;
}
