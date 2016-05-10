// Fill out your copyright notice in the Description page of Project Settings.

#include "FrisbeeNul.h"
#include "SpeedBuffEffect.h"


void SpeedBuffEffect::applyStatModifier(StatId statId)
{
	if (statId == StatId::SPEED) {
		this->character->statList[statId]->addValue(1);
	}
}