// Fill out your copyright notice in the Description page of Project Settings.

#include "FrisbeeNul.h"
#include "Effect.h"

Effect::Effect(BNYCharacter *character)
{
	this->character = character;
}

Effect::~Effect()
{
}

void Effect::onReceiveDamage(BNYCharacter *from, float damageAmount)
{
}

void Effect::applyStatModifier(StatId statId)
{

}
