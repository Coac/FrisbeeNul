// Fill out your copyright notice in the Description page of Project Settings.
#include "Stat/Stat.h"
#pragma once

/**
 * 
 */
class FRISBEENUL_API BNYCharacter
{
public:
	BNYCharacter();
	~BNYCharacter();

	float getStat(StatId statId);

	Stat *statList[];
};
