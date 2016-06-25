// Fill out your copyright notice in the Description page of Project Settings.
#pragma once

#include "../BNYCharacter.h"
#include "../Stat/Stat.h"


class BNYCharacter;
/**
 * 
 */
class FRISBEENUL_API Effect
{
public:
	Effect(BNYCharacter *character);
	~Effect();

	void onReceiveDamage(BNYCharacter *from, float damageAmount);

	void applyStatModifier();

protected:
	BNYCharacter *character;
	float timeLeft;
};
