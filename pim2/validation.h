#pragma once
#ifndef VALIDATION
#define VALIDATION

int validate_student_id(int student_id);

int validate_disabled_person_id(int disabled_person_id);

int validate_pix_payment(double value);

int validate_card_payment(char card_holder[100], int card_number, int identification_number);

#endif