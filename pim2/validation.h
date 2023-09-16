#pragma once
#ifndef VALIDATION
#define VALIDATION


int validateDisabledPersonId(int student_id);

int validateDisabledPersonId(int disabled_person_id);

int validatePixPayment(double value);

int validateCardPayment(char card_holder[100], int card_number, int identification_number);

#endif