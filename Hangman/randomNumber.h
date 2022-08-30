#pragma once
#include<iostream>;
#include<random>;
using std::random_device;
using std::default_random_engine;
using std::uniform_int_distribution;

int random_number(int min, int max){
	random_device rd;
	default_random_engine eng(rd());
	uniform_int_distribution<int> distr(min, max);
	return distr(eng);
}