/*
    Neuron.h - Library for using simple neurons
*/

#ifndef Neuron_h
#define Neuron_h

class Neuron
{

private:
    float fireThreshold = 1;
    float degredationAmount = 0.02;
    float maxRefractoryPeriod = 0.2;
    float maxFirePeriod = 0.2;
    float refractoryTime;
    float fireTime;
    float totalAmount;
public:
    Neuron(float fireThreshold, float degredationAmount, float refractorySeconds, float fireSeconds);
    bool Receive(float amount, float dt);
};

#endif