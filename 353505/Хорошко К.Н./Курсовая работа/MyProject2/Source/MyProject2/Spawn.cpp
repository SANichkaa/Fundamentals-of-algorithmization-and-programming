// Fill out your copyright notice in the Description page of Project Settings.


#include "Spawn.h"
#include <iostream>
#include <chrono>
#include <ctime>

// Sets default values
ASpawn::ASpawn()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

void ASpawn::BeginPlay()
{
	Super::BeginPlay();
	
}

class LinearCongruentialGenerator
{
public:
	LinearCongruentialGenerator(unsigned long long seed) :
		a(6364136223846793005),
		c(1),
		m(9223372036854775808),
		state(seed)
	{
	}

	unsigned long long next()
	{
		state = (a * state + c) % m;
		return state;
	}

private:
	unsigned long long a, c, m;
	unsigned long long state;
};


int ASpawn::Spawn_code(int param) {

	auto now = std::chrono::system_clock::now();


	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);


	std::tm now_tm = *std::localtime(&now_time_t);


	int hours = now_tm.tm_hour;
	int minutes = now_tm.tm_min;
	int seconds = now_tm.tm_sec;


	int total = hours + minutes + seconds;

	LinearCongruentialGenerator lcg(total);

	int ans = 0;

	switch (param) {
	case 0:
		ans = lcg.next() % 5;
		break;
	case 1:
		ans = lcg.next() % 4;
		break;
	case 2:
		ans = lcg.next() % 3;
		break;
	case 3:
		ans = lcg.next() % 2;
		break;
	default:
		ans = 0;
		break;
	}


	return ans;
}




class XorShift {
public:
	XorShift(unsigned int seed) : state(seed) {}

	unsigned int next() {
		unsigned int x = state;
		x ^= x << 13;
		x ^= x >> 17;
		x ^= x << 5;
		state = x;
		return x;
	}

private:
	unsigned int state;
};






int ASpawn::Random_Mod(int param) {

	auto now = std::chrono::system_clock::now();

	
	std::time_t now_time_t = std::chrono::system_clock::to_time_t(now);


	std::tm now_tm = *std::localtime(&now_time_t);


	int hours = now_tm.tm_hour;
	int minutes = now_tm.tm_min;
	int seconds = now_tm.tm_sec;


	int total = hours + minutes + seconds;

	XorShift xorShift(total);

	int ans = xorShift.next()%param;

	
	return ans;
}

// Called every frame
void ASpawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

