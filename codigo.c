#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <stdbool.h>
struct venda {
    unsigned int codigo;
    char comentario[50];
    double quantidade;
    double valor;
};
#define FILE_NAME "vendas1.dat"
int main(){
FILE* file_legal;
FILE* file_mais_legal ;
file_legal = fopen(FILE_NAME,"rb");
file_mais_legal=fopen(FILE_NAME,"rb");


int size=0;
int codigo;

struct venda item;
while(fread(&item,sizeof item,1,file_legal)>0){
       printf("CODIGO %d COMENTARIO %s QUANTIDADE %lf VALOR %lf\n",item.codigo,item.comentario,item.quantidade,item.valor);
       size  +=1;
}
if(file_legal==NULL||file_mais_legal==NULL){
    perror(FILE_NAME);
    exit(1);
}else{
    struct venda legal;


int* v;
 v=(int*)malloc(size*sizeof(int));
double* p;
 p=(double*)malloc(size*sizeof(double));

int i=0;
while(fread(&legal,sizeof legal,1,file_mais_legal)>0){
double totalVENDprod=0;
   

    codigo = legal.codigo;
    


    while(fread(&legal,sizeof legal,1,file_legal)>0){
        
        if(codigo == legal.codigo){
        totalVENDprod += legal.quantidade * legal.quantidade;}
          
    }
    
  v[i]=codigo;
  p[i]=totalVENDprod;  
  printf("CODIGO: %d TOTAL_VENDAS: ",codigo);
  printf("%lf\n",totalVENDprod);
  rewind(file_legal);
  i++;
}

double* pAUXILIAR;
 pAUXILIAR=(double*)malloc(size*sizeof(double));
 int* vAUXILIAR;
 vAUXILIAR=(int*)malloc(size*sizeof(int));
int n=0;
int j;
  for(int i = 0; i < size; i++)
    {
        for( j = 0; j < n; j++ )
        {
            if( v[i] == vAUXILIAR[j] )
                break;
        }

        if( j == n )
        {
            vAUXILIAR[n] =v[i];
            n++;
            
        }
    }
n=0;
  for(int i = 0; i < size; i++)
    {
        for( j = 0; j < n; j++ )
        {
            if( p[i] == pAUXILIAR[j] )
                break;
        }

        if( j == n )
        {
            pAUXILIAR[n] =p[i];
            n++;
           
        }
    }



printf("\n\n Agora irei printar sem repetições \n\n");
for(int i=0;i<size;i++){
    if(vAUXILIAR[i-1]!=0){
    printf("\n");
    printf("CODIGO: %d TOTAL_VENDAS: ",vAUXILIAR[i-1]);
    printf("%lf\n",pAUXILIAR[i]);
}}
}

    return 0;
}