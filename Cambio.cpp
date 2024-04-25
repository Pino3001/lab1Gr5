#include "Cambio.h"
#include "definiciones.h"

float Cambio::a_peso(float monto)
{ // Retorna el parametro pasado en pesos.
    return monto * VALOR_DOLAR;
}
float Cambio::a_dolar(float monto)
{ // Retorna el parametro pasado en dolares.
    return monto / VALOR_DOLAR;
}