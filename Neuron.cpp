/*
    Neuron.cpp - Library for using simple neurons
*/

#include "Neuron.h"

Neuron::Neuron(float fireThreshold, float degredationAmount, float refractorySeconds, float fireSeconds)
{
    this->fireThreshold = fireThreshold;
    this->degredationAmount = degredationAmount;
    this->maxRefractoryPeriod = refractorySeconds;
    this->maxFirePeriod = fireSeconds;
    this->refractoryTime = 0;
    this->fireTime = fireSeconds;
}

bool Neuron::Receive(float amount, float dt)
{
    if (fireTime < maxFirePeriod)
    {
        fireTime += dt;
        return true;
    }

    if (refractoryTime < maxRefractoryPeriod)
    {
        refractoryTime += dt;
        return false;
    }

    totalAmount -= degredationAmount;
    if (totalAmount < 0)
    {
        totalAmount = 0;
    }

    totalAmount += amount;

    if (totalAmount >= fireThreshold)
    {
        fireTime = 0;
        refractoryTime = 0;
        totalAmount = 0;
        return true;
    }

    return false;
}