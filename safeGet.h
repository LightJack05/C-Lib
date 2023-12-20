#ifndef SAFEGET_H
#define SAFEGET_H

int safeGetInt();

int safeGetPositiveInt();

int safeGetIntInRange(int min, int max);

int safeGetBoolFromInt();

int safeGetContinue();

float safeGetFloat();

char *safeGetStringNotEmpty();

#endif // SAFEGET_H