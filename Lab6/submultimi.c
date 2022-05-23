#include <stdio.h>

int x2[20], n, nrsol=0,v[20];

void Afisare2()
{ int i;
  for(i=1;i<=n;i++)
    if (x2[i]==1) 
      printf("%d ",v[i]);;
  printf("\n");
  nrsol++;
}

void BackRec2(int k) {
  int i;
  for(i=0;i<=1;i++) {
    x2[k]=i;
    if (k==n) 
      Afisare2();
    else 
      BackRec2(k+1);
    }
}

int main()
{ 
  printf("\nDati nr elementelor multimii: "); 
  scanf("%d",&n);
  printf("\nDati elementele multimii: ");
  for(int i = 1 ; i<=n;i++)
    scanf("%d",&v[i]);
  BackRec2(1);
  printf("\nNumar solutii: %d",nrsol);
  return 0;
}