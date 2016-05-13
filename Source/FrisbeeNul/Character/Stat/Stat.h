// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class FRISBEENUL_API Stat
{
public:
	Stat(float val);
	~Stat();

	void addValue(float val);
	float getValue();
	void resetToBase();

private:
	float baseValue;
	float calculatedValue;

};

enum StatId { SPEED, MATK, ATK, STAT_COUNT };
