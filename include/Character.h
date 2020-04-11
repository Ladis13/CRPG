#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>
#include <string>
#include "Stats.h"
#include "SStats.h"

class Character {
private:
    std::string name;

    int level;
    Stats stats;
    SStats sstats;

    int hp;
    int energy;

public:
    Character();
    ~Character();

    //Functions
    void print();

    //Accessors
    inline int getStrength() const {
        return this->stats.getStrength(); }
    inline int getStrudiness() const {
        return this->stats.getStrudiness(); }
    inline int getIntelligence() const {
        return this->stats.getIntelligence(); }
    inline int getSpirit() const {
        return this->stats.getSpirit(); }
    inline int getAgility() const {
        return this->stats.getAgility(); }
    inline int getLuck() const {
        return this->stats.getLuck(); }

    inline int getVitality() const {
        return this->sstats.getVitality(); }
    inline int getEnergy() const {
        return this->sstats.getEnergy(); }
    inline int getTenacity() const {
        return this->sstats.getTenacity(); }
    inline int getWill() const {
        return this->sstats.getWill(); }
    inline int getPower() const {
        return this->sstats.getPower(); }
    inline int getResistance() const {
        return this->sstats.getResistance(); }
    inline int getPerception() const {
        return this->sstats.getPerception(); }
    inline int getMastery() const {
        return this->sstats.getMastery(); }

    //Modifiers
    inline void setStrength(int n) {
        this->stats.setStrength(n); }
    inline void setSturdiness(int n) {
        this->stats.setSturdiness(n); }
    inline void setIntelligence(int n) {
        this->stats.setIntelligence(n); }
    inline void setSpirit(int n) {
        this->stats.setSpirit(n); }
    inline void setAgility(int n) {
        this->stats.setAgility(n); }
    inline void setLuck(int n) {
        this->stats.setLuck(n); }

    inline void setVitality(int n) {
        this->sstats.setVitality(n); }
    inline void setEnergy(int n) {
        this->sstats.setEnergy(n); }
    inline void setTenacity(int n) {
        this->sstats.setTenacity(n); }
    inline void setWill(int n) {
        this->sstats.setWill(n); }
    inline void setPower(int n) {
        this->sstats.setPower(n); }
    inline void setResistance(int n) {
        this->sstats.setResistance(n); }
    inline void setPerception(int n) {
        this->sstats.setPerception(n); }
    inline void setMastery(int n) {
        this->sstats.setMastery(n); }
};

#endif
