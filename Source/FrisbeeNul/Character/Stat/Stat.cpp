// Fill out your copyright notice in the Description page of Project Settings.

#include "FrisbeeNul.h"
#include "Stat.h"

Stat::Stat()
{
}

Stat::~Stat()
{
}

void Stat::addValue(float val)
{
	this.calculatedValue = this.baseValue + val;
}
