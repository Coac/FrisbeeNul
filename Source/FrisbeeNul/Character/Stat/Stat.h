// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

/**
 * 
 */
class FRISBEENUL_API Stat
{
public:
	Stat();
	~Stat();

	void addValue(float val);

private:
	float baseValue;
	float calculatedValue;

};

enum StatId { SPEED, MATK, ATK };
