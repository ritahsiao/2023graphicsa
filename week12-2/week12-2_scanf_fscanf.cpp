#include <stdio.h>
int main()
{
    FILE * fin =fopen("file.txt","r");///Ū�e�@�ӽd��

    char line[100];
    fscanf(fin,"%s",line);
    printf("�qfile.txtŪ��F:%s\n",line);

    fscanf(fin,"%s",line);
    printf("�qfile.txtŪ��F:%s\n",line);
}
