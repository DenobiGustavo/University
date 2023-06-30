#include <stdio.h>

int main()
{
    float gasto;
    float para_garcom;
    float pagamento;

    printf("Quanto vc gastou?: ");
    scanf("%f", &gasto);

    para_garcom = gasto * 0.10;
    pagamento = gasto + para_garcom;

    printf("Voce pagara: %f \n", pagamento);
}
