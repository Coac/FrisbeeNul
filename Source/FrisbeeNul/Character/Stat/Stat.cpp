// Fill out your copyright notice in the Description page of Project Settings.

#include "FrisbeeNul.h"
#include "Stat.h"

Stat::Stat(float val)
{
	this->baseValue = val;
}

Stat::~Stat()
{
}

void Stat::addValue(float val)
{
	this->calculatedValue += val;
}

float Stat::getValue()
{
	return this->calculatedValue;
}

void Stat::resetToBase()
{
	this->calculatedValue = this->baseValue;
}