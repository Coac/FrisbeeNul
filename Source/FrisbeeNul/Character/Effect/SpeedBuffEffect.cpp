// Fill out your copyright notice in the Description page of Project Settings.

#include "FrisbeeNul.h"
#include "SpeedBuffEffect.h"


void SpeedBuffEffect::applyStatModifier()
{
	this->character->statList[StatId::SPEED]->addValue(1);
}