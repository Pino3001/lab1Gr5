#include "Cambio.h"
#include "definiciones.h"

float Cambio::a_peso(float monto)
{
    return monto / VALOR_DOLAR;
}
float Cambio::a_dolar(float monto)
{
    return monto * VALOR_DOLAR;
}