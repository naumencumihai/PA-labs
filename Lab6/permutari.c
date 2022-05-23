#include <stdio.h>

int x[10] ,n;

void Afisare()
{
    for( int j=1;j<=n;j++)
        printf("%d ",x[j]);    
    printf("\n");
}

int valid(int k){
    for(int i=1;i<k;++i)
        if(x[k]==x[i])
            return 0;
    return 1;
}

void back(int k){
    for(int i=1 ; i<=n ; ++i)
    {
        x[k]=i;
        if( valid(k) )
            if(k == n)
                Afisare();
            else
                back(k+1);
    }
}
int main(){
    scanf("%d",&n);
    back(1);
    return 0;
}