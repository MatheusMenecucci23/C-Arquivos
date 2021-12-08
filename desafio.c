/*
Matheus Menecucci
800310
*/
#include <stdio.h>
#include <stdlib.h>

struct venda {
    unsigned int codigo;
    char comentario[50];
    double quantidade;
    double valor;
};

int main(void){

    unsigned int codigo;
    unsigned int codigoAnterior = 0;
	//nome do arquivo
	char *nome_arquivo = "vendas1.dat";

	//abrindo o arquivo
	FILE *arquivo_vendas = fopen(nome_arquivo, "rb");
    FILE *arquivo_vendas1 = fopen(nome_arquivo, "rb");

	if(arquivo_vendas == NULL || arquivo_vendas1 == NULL){
		perror(nome_arquivo);
	};
    struct venda item;
    while (fread(&item, sizeof item, 1, arquivo_vendas) > 0)
    {
        printf("CODIGO %d, COMENTARIO %s, QUANTIDADE %.2lf, VALOR %.2lf\n", item.codigo, item.comentario, item.quantidade, item.valor);
    }

    struct venda venda1;
    while (fread(&venda1, sizeof venda1, 1, arquivo_vendas1) > 0)
    {
        double totalVenda = 0;

        codigo = venda1.codigo;

        while (fread(&venda1, sizeof venda1, 1, arquivo_vendas) > 0)
        {

            if (codigo == venda1.codigo)
            {
                //calculando o total de venda por produto
                totalVenda += venda1.quantidade * venda1.valor;
            }
        }
        if(codigo != codigoAnterior){
            //printando o total de vendas
            printf("Código: %d, Total de vendas: R$ %.2lf\n\n ", codigo, totalVenda);
            codigoAnterior = codigo;
        }
        rewind(arquivo_vendas);
    }
    return 0;
}