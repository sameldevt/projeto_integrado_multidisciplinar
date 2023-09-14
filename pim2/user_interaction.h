#pragma once
#ifndef USER_INTERACTION
#define USER_INTERACTION

int answer_survey(int theme, char survey[51]);

int evaluate_art(char art_name[21]);

int select_theme_menu_option();

int select_art(int theme);

int switch_arts(int theme);

int card_payment();

int pix_payment();

int select_payment_menu();

int full_price_ticket();

int student_ticket();

int senior_ticket();

int disabled_ticket();

int select_ticket_type();

int select_main_menu_option();

void start_program();

#endif