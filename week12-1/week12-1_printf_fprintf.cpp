///week12-1_printf_fprintf.cpp
///�n��g�ɮ�
#include <stdio.h>
int main()
{   /// �ɮ׫��� fout = �}�ɮ�("�ɦW,"�Τ���Ҧ�")
    FILE * fout = fopen("file.txt","w");///w:write

    printf("Hello World\n");
    fprintf(fout,"Hello World�b�ɮ׸�\n");
}
