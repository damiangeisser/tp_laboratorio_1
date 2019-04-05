float sumar(float sumando1, float sumando2)
{
    float rtaFuncionSum;

    rtaFuncionSum = sumando1 + sumando2;

    return rtaFuncionSum;
}

float restar(float minuendo, float sustraendo)
{
    float rtaFuncionRes;

    rtaFuncionRes = minuendo - sustraendo;

    return rtaFuncionRes;
}

float multiplicar(float factor1, float factor2)
{
    float rtaFuncionMulti;

    rtaFuncionMulti = factor1 * factor2 ;

    return rtaFuncionMulti;
}

float dividir(float dividendo, float divisor)
{
    float rtaFuncionDiv;

    rtaFuncionDiv = dividendo / divisor ;

    return rtaFuncionDiv;
}

int factorial(int operandoFac)
{
    int rtaFuncionFactor=1;

    for(operandoFac; operandoFac>1; operandoFac--)
    {
        rtaFuncionFactor = rtaFuncionFactor * operandoFac;
    }
    return rtaFuncionFactor;
}
