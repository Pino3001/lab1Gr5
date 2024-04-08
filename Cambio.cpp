#include "Cambio.h"

float Cambio::a_peso(float monto)
{
    return monto / 39.05;
}
float Cambio::a_dolar(float monto)
{
    return monto * 39.05;
}