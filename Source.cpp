#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>
#include<stdbool.h>
#include <stdlib.h>
#include <limits.h>
#include <string.h>
#define MAX_LINES 1000
#define MAX_LENGTH 100
#define MAXIM 10000000000
#define A "\033[0;36m"



void Caesar_Cipher(char msg[], int key)
{
    int i = 0;
    for (int i = 0; i < strlen(msg); i++)
    {
        int rez;
        if ((int)msg[i] <= (int)('z') && (int)(msg[i]) >= (int)('a'))
        {
            rez = (int)(msg[i]) + key;
            if (rez > (int)('z'))
                rez = (int)('a') + (rez - (int)('z') - 1);
            if (rez < (int)('a'))
                rez = (int)('z') - ((int)('a') - rez - 1);
            msg[i] = (char)(rez);
        }
        else
        {
            if ((int)(msg[i]) <= (int)('Z') && (int)(msg[i]) >= (int)('A'))
            {
                rez = (int)(msg[i]) + key;
                if (rez > (int)('Z'))
                    rez = (int)('A') + (rez - (int)('Z') - 1);
                if (rez < (int)('A'))
                    rez = (int)('Z') - ((int)('A') - rez - 1);
                msg[i] = (char)(rez);
            }
        }
    }
}

void read_dist(float normal[26])
{
    FILE* fp;
    int i = 0;

    fp = fopen("distribution.txt", "r");

    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    while (fscanf(fp, "%f", &normal[i]) == 1)
        i++;

    fclose(fp);
}

void find_dist(float exp[26], float normal[26], int text_length)
{
    for (int i = 0; i < 26; i++)
    {
        exp[i] = text_length * (normal[i] / 100);
    }
}

float chi_square(float c, float e)
{
    return ((c - e) * (c - e)) / e;
}

float chi_for_histogram(float exp[26], int real[26])
{
    float sum = 0;
    for (int i = 0; i < 26; i++)
    {
        sum = sum + chi_square((float)real[i], exp[i]);
    }
    return sum;
}


int main()
{
    bool ok = true;
    char lines[MAX_LINES][MAX_LENGTH];
    char cpy[MAX_LINES][MAX_LENGTH];
    FILE* file;
    int line_count = 0;
    int key;
    float sum_min = MAXIM;

    file = fopen("text.txt", "r");

    while (fgets(lines[line_count], MAX_LENGTH, file) != NULL)
    {
        line_count++;
        if (line_count == MAX_LINES)
        {
            printf("Maximum number of lines reached.\n");
            break;
        }
    }
    float normal[26];
    float exp[26];
    char op0;
    char op2;
    char op;
    read_dist(normal);
    find_dist(exp, normal, 217);

    printf("Press S/s in order to start the program\n\n");
    printf("Press C/c in order to collor the text\n\n");
    while (ok)
    {
        int t = scanf("%c", &op);
        int t0 = scanf("%c", &op0);
        if (op == 's' || op == 'S')
        {
            for (int l = 0; l < 26; l++)
            {
                int real[26] = { 0 };
                for (int k = 0; k < line_count; k++)
                {
                    if (l == 0)
                        Caesar_Cipher(lines[k], 0);
                    else
                        Caesar_Cipher(lines[k], 1);
                }

                for (int i = 0; i < line_count; i++)
                {
                    for (int j = 0; j < strlen(lines); j++)
                    {
                        if (lines[i][j] == 'a' || lines[i][j] == 'A')
                            real[0]++;

                        if (lines[i][j] == 'b' || lines[i][j] == 'B')
                            real[1]++;

                        if (lines[i][j] == 'c' || lines[i][j] == 'C')
                            real[2]++;

                        if (lines[i][j] == 'd' || lines[i][j] == 'D')
                            real[3]++;

                        if (lines[i][j] == 'e' || lines[i][j] == 'E')
                            real[4]++;

                        if (lines[i][j] == 'f' || lines[i][j] == 'F')
                            real[5]++;

                        if (lines[i][j] == 'g' || lines[i][j] == 'G')
                            real[6]++;

                        if (lines[i][j] == 'h' || lines[i][j] == 'H')
                            real[7]++;

                        if (lines[i][j] == 'i' || lines[i][j] == 'I')
                            real[8]++;

                        if (lines[i][j] == 'j' || lines[i][j] == 'J')
                            real[9]++;

                        if (lines[i][j] == 'k' || lines[i][j] == 'K')
                            real[10]++;

                        if (lines[i][j] == 'l' || lines[i][j] == 'L')
                            real[11]++;

                        if (lines[i][j] == 'm' || lines[i][j] == 'M')
                            real[12]++;

                        if (lines[i][j] == 'n' || lines[i][j] == 'N')
                            real[13]++;

                        if (lines[i][j] == 'o' || lines[i][j] == 'O')
                            real[14]++;

                        if (lines[i][j] == 'p' || lines[i][j] == 'P')
                            real[15]++;

                        if (lines[i][j] == 'q' || lines[i][j] == 'Q')
                            real[16]++;

                        if (lines[i][j] == 'r' || lines[i][j] == 'R')
                            real[17]++;

                        if (lines[i][j] == 's' || lines[i][j] == 'S')
                            real[18]++;

                        if (lines[i][j] == 't' || lines[i][j] == 'T')
                            real[19]++;

                        if (lines[i][j] == 'u' || lines[i][j] == 'U')
                            real[20]++;

                        if (lines[i][j] == 'v' || lines[i][j] == 'V')
                            real[21]++;

                        if (lines[i][j] == 'w' || lines[i][j] == 'W')
                            real[22]++;

                        if (lines[i][j] == 'x' || lines[i][j] == 'X')
                            real[23]++;

                        if (lines[i][j] == 'y' || lines[i][j] == 'Y')
                            real[24]++;

                        if (lines[i][j] == 'z' || lines[i][j] == 'Z')
                            real[25]++;
                    }
                }


                float sum = 0;
                sum = chi_for_histogram(exp, real);
                if (sum < sum_min)
                {
                    sum_min = sum;
                    key = l;
                    for (int a = 0; a < line_count; a++)
                        strcpy(cpy[a], lines[a]);
                }
            }
            for (int a = 0; a < line_count; a++)
                printf("%s", cpy[a]);
            printf("\n");
            ok = false;
        }
        else
        {
            if (op == 'c' || op == 'C')
            {
                for (int l = 0; l < 26; l++)
                {
                    int real[26] = { 0 };
                    for (int k = 0; k < line_count; k++)
                    {
                        if (l == 0)
                            Caesar_Cipher(lines[k], 0);
                        else
                            Caesar_Cipher(lines[k], 1);
                    }

                    for (int i = 0; i < line_count; i++)
                    {
                        for (int j = 0; j < strlen(lines); j++)
                        {
                            if (lines[i][j] == 'a' || lines[i][j] == 'A')
                                real[0]++;

                            if (lines[i][j] == 'b' || lines[i][j] == 'B')
                                real[1]++;

                            if (lines[i][j] == 'c' || lines[i][j] == 'C')
                                real[2]++;

                            if (lines[i][j] == 'd' || lines[i][j] == 'D')
                                real[3]++;

                            if (lines[i][j] == 'e' || lines[i][j] == 'E')
                                real[4]++;

                            if (lines[i][j] == 'f' || lines[i][j] == 'F')
                                real[5]++;

                            if (lines[i][j] == 'g' || lines[i][j] == 'G')
                                real[6]++;

                            if (lines[i][j] == 'h' || lines[i][j] == 'H')
                                real[7]++;

                            if (lines[i][j] == 'i' || lines[i][j] == 'I')
                                real[8]++;

                            if (lines[i][j] == 'j' || lines[i][j] == 'J')
                                real[9]++;

                            if (lines[i][j] == 'k' || lines[i][j] == 'K')
                                real[10]++;

                            if (lines[i][j] == 'l' || lines[i][j] == 'L')
                                real[11]++;

                            if (lines[i][j] == 'm' || lines[i][j] == 'M')
                                real[12]++;

                            if (lines[i][j] == 'n' || lines[i][j] == 'N')
                                real[13]++;

                            if (lines[i][j] == 'o' || lines[i][j] == 'O')
                                real[14]++;

                            if (lines[i][j] == 'p' || lines[i][j] == 'P')
                                real[15]++;

                            if (lines[i][j] == 'q' || lines[i][j] == 'Q')
                                real[16]++;

                            if (lines[i][j] == 'r' || lines[i][j] == 'R')
                                real[17]++;

                            if (lines[i][j] == 's' || lines[i][j] == 'S')
                                real[18]++;

                            if (lines[i][j] == 't' || lines[i][j] == 'T')
                                real[19]++;

                            if (lines[i][j] == 'u' || lines[i][j] == 'U')
                                real[20]++;

                            if (lines[i][j] == 'v' || lines[i][j] == 'V')
                                real[21]++;

                            if (lines[i][j] == 'w' || lines[i][j] == 'W')
                                real[22]++;

                            if (lines[i][j] == 'x' || lines[i][j] == 'X')
                                real[23]++;

                            if (lines[i][j] == 'y' || lines[i][j] == 'Y')
                                real[24]++;

                            if (lines[i][j] == 'z' || lines[i][j] == 'Z')
                                real[25]++;
                        }
                    }


                    float sum = 0;
                    sum = chi_for_histogram(exp, real);
                    if (sum < sum_min)
                    {
                        sum_min = sum;
                        key = l;
                        for (int a = 0; a < line_count; a++)
                            strcpy(cpy[a], lines[a]);
                    }
                }
                for (int a = 0; a < line_count; a++)
                    printf(A"%s", cpy[a]);
                printf("\n");
                ok = false;
            }
            else
            {
                printf("Please enter a valid option!");
                int t2 = scanf("%c", &op2);
            }
        }
    }

    fclose(file);
    return 0;
}