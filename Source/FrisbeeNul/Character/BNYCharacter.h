// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "Effect/Effect.h"
#include "Stat/Stat.h"
#include "Array.h"

class Effect;
/**
 * 
 */
class FRISBEENUL_API BNYCharacter
{
public:
	BNYCharacter();
	~BNYCharacter();

	float getStat(StatId statId);

	void recalculateStats();
	void resetStatsToBase();

	Stat *statList[StatId::STAT_COUNT];
	TArray<Effect> *activeEffects;

};
