// Fill out your copyright notice in the Description page of Project Settings.
#include "../BNYCharacter.h"
#include "../Stat/Stat.h"
#pragma once

/**
 * 
 */
class FRISBEENUL_API Effect
{
public:
	Effect(BNYCharacter *character);
	~Effect();

	void onReceiveDamage(BNYCharacter *from, float damageAmount);

	void applyStatModifier(StatId statId);


private:
	BNYCharacter *character;
};
