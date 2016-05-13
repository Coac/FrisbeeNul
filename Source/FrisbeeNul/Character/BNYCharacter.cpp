// Fill out your copyright notice in the Description page of Project Settings.

#include "FrisbeeNul.h"
#include "BNYCharacter.h"

BNYCharacter::BNYCharacter()
{
	// Stats Declaration
	this->statList[StatId::SPEED] = new Stat(10.f);

	// Buff Declaration
	this->activeEffects = new TArray<Effect>();
	// this->activeEffects->Add(new SpeedBuffEffect(this));
}

BNYCharacter::~BNYCharacter()
{
}

void BNYCharacter::resetStatsToBase()
{
	
	for (int i = 0; i < StatId::STAT_COUNT; i++) {
		this->statList[i]->resetToBase();
	}
}

void BNYCharacter::recalculateStats()
{
	this->resetStatsToBase();
	TArray<Effect> *activeEffects = this->activeEffects;
	for (Effect& effect : *activeEffects)
	{
		effect.applyStatModifier();
	}
}

float BNYCharacter::getStat(StatId statId) {
	return this->statList[statId]->getValue();
}
