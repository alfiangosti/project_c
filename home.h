/* 
 * File:   home.h
 * Author: BIN IDRUS BIN GOSTI
 *
 * Created on May 23, 2014, 10:41 PM
 */

#ifndef HOME_H_
#define HOME_H_

#define ROW 6
#define COLUMN 9

/*
 * 
 */
int tab_home[ROW][COLUMN];
struct Answers{
		int value;
		int coor;
	};

struct Answers horizontal[COLUMN];
struct Answers angle45[COLUMN];
struct Answers angle135[COLUMN];
struct Answers horizontal_data[COLUMN];
struct Answers angle45_data[COLUMN];
struct Answers angle135_data[COLUMN];

int result[3];
int tab_data[ROW][COLUMN];

void calculateSomme(int tab_home[][COLUMN],int rowChercher,int columnChercher,int *result);

void readGamefile(char *f,int tab_home[][COLUMN]);
void viewQuestion(int tab_home[][COLUMN]);
void viewtable(int tab_home[][COLUMN]);

#endif /* HOME_H_ */
