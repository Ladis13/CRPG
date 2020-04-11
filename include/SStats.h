#ifndef SSTATS_H
#define SSTATS_H

#include "ESSTATS.h"

class SStats {
private:
    int sstats[NSSTATS];

public:
    SStats();
    ~SStats();

    //Functions


    //Accessors
    inline int getVitality() const {
        return this->sstats[SSTAT::VITALITY]; }
    inline int getEnergy() const {
        return this->sstats[SSTAT::ENERGY]; }
    inline int getTenacity() const {
        return this->sstats[SSTAT::TENACITY]; }
    inline int getWill() const {
        return this->sstats[SSTAT::WILL]; }
    inline int getPower() const {
        return this->sstats[SSTAT::POWER]; }
    inline int getResistance() const {
        return this->sstats[SSTAT::RESISTANCE]; }
    inline int getPerception() const {
        return this->sstats[SSTAT::PERCEPTION]; }
    inline int getMastery() const {
        return this->sstats[SSTAT::MASTERY]; }

    //Modifiers
    inline void setVitality(int n) { this->sstats[SSTAT::VITALITY] = n; }
    inline void setEnergy(int n) { this->sstats[SSTAT::ENERGY] = n; }
    inline void setTenacity(int n) { this->sstats[SSTAT::TENACITY] = n; }
    inline void setWill(int n) { this->sstats[SSTAT::WILL] = n; }
    inline void setPower(int n) { this->sstats[SSTAT::POWER] = n; }
    inline void setResistance(int n) { this->sstats[SSTAT::RESISTANCE] = n; }
    inline void setPerception(int n) { this->sstats[SSTAT::PERCEPTION] = n; }
    inline void setMastery(int n) { this->sstats[SSTAT::MASTERY] = n; }
};

#endif
