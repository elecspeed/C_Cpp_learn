#define _CRT_SECURE_NO_WARNINGS 1

//ʲô���ļ�
//�ļ��� �� �ļ�����
//�ļ�������
//�ļ�ָ��
//�ļ��Ĵ���ر�
//�ļ���˳���д �� �����д
//�ļ��������ж�

#include <stdio.h>
#include <string.h>
#include <errno.h>


//��������ŵĶ����ļ�
//������ӳ�����ƵĽǶȣ����ļ���Ϊ���֣������ļ� �� �����ļ�

//�����ļ�
//���� Դ�ļ�����׺��Ϊ.c����Ŀ���ļ���.obj������ִ�г���.exe��
//�����ļ�
//�����ļ����Զ�ȡ��д�����ݵ��ļ�
//�������۵��Ƕ������ļ��Ĳ���

//��ǰ��������ݣ���������������ն��Ͻ��С�
//����Ҫ�����ݵ��������ת�������Ͻ��У�����ı��Ǵ����ϵ��ļ�



//�ļ������ļ�·��+�ļ�������+�ļ���׺�������չ����
//����C:\User\test.txt

//�ļ�����
//����д������ʱ���ݵ���֯��ʽ�������ļ�����Ϊ�ı��ļ� �� �������ļ�
//���ݲ�����ת�������ڴ�ֱ��������̣����̴洢��Ϊ�������ļ�
//����ת����ASCII�룬�ٴ��ڴ�������̣���Ϊ�ı��ļ�

//�ַ�ֻ����ASCII��洢����ֵ�����ݿ�����ASCII��洢��Ҳ�����ö�������ʽ�洢



//�ļ�������
//C��׼���á������ļ�ϵͳ�����������ļ���
//ϵͳ���Զ����ڴ��У�Ϊ�����ÿһ������ʹ�õ��ļ�����һ�顰�ļ�����������
//���ڴ�ʹ���֮�����������ݣ����ȴ������뻺���������������
//���������˲��͵���Ӧ������
//�������Ĵ�С��C����ϵͳ����

//�ӳ���������ݵ��ⲿ���ļ����ն˵ȣ�������ⲿ�������ݵ����򣬶�Ҫ����������



//�ļ�ָ��
//�ڻ����ļ�ϵͳ�У�ÿ����ʹ�õ��ļ������ڴ��п�����һ���ļ���Ϣ���������ļ���������
//���ļ���Ϣ����������ļ��������Ϣ�����ļ������ļ�״̬���ļ�λ�õȣ�
//��C���Կ�������Щ�ļ���Ϣ�����ǽṹ�����
//ϵͳ���ýṹ����������ΪFILE
//��ͬ��������FILE�Ķ���ǳ�����
//ÿʹ��һ���ļ���ϵͳ�ʹ���һ��FILE�ṹ����������Զ���������Ϣ
//���ļ����ݷ����仯��FILE�ṹ���Ա����Ҳ�ᷢ���仯
// 
//��ô����鶯̬���ٵĿռ���ɡ��ļ�ָ�롱������



//�ļ�ʹ��ǰҪ�ȴ򿪣�ʹ����Ҫ�ر�

//C����ÿ���ļ������᷵���ļ���Ϣ���ĵ�ַ����̬�ڴ���䣩��
//�൱�ڽ�����ָ����ļ�����ϵ

//���ļ���fopen����
// 
// FILE *fopen( const char *filename, const char *mode );
// 
// filenameΪ�ļ�����modeΪ�򿪷�ʽ

//�򿪷�ʽ    ����                         ���ָ���ļ�������
//  "r"     ��һ���ı��ļ���ȡ����         ����
//  "w"     ��һ���ı��ļ�д������         �½�һ���ı��ļ���д�����ݣ����ԭ�е��ļ����ǵ���
//  "a"     ���ı��ļ�β��׷������           ����
//  "rb"    
//  "wb"    
//  "ab"    ͬ�ϣ����ɶ������ļ���           ͬ��
// 
//  "r+"    ��һ���ı��ļ���д����         ����
//  "w+"    �½�һ���ı��ļ���д����      
//  "a+"    ��һ���ı��ļ�����β����д���� �½�
//  "rb+"
//  "wb+"
//  "ab+"   ͬ��
//

//���ļ�test.txt
//int main()
//{
//    //����·��
//    //FILE* pf = fopen("E:\\Source\\Repos\\elecspeed\\C_learn\\�ļ�����\\test.txt", "r");
//
//    //���·��
//    //FILE* pf = fopen("../../test.txt", "r");
//    FILE* pf = fopen("test.txt", "r");
//
//    if (!pf)
//    {
//        //��ʧ��
//        printf("%s", strerror(errno));
//        return 0;
//    }
//    //�򿪳ɹ�
//    
//    //���ļ�
//    //�ر��ļ�
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

//�ر��ļ���fclose �� _fcloseall����
// Closes a stream (fclose) or closes all open streams (_fcloseall).
// 
// ����
// int fclose( FILE *stream );
// int _fcloseall( void );



//�ļ���˳���д
//  ������      ����                ������
//  fgetc       �ַ�����            ����������
//  fputc       �ַ����            ���������
//  fgets       �ı�������          
//  fputs       �ı������          ͬ��
//  fscanf      ��ʽ������          
//  fprintf     ��ʽ�����          ͬ��
//  fread       ����������          �ļ�
//  fwrite      ���������          �ļ�

//int main()
//{
//    FILE* pf = fopen("test.txt", "r");    //�򿪷�ʽ��Ӱ���д����
//    if (!pf)
//    {
//        printf("%s\n", strerror(errno));
//        return 0;
//    }
//    //д
//    //fputc('g', pf);
//
//    //��
//    int ch = fgetc(pf);
//    putchar(ch);
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//���̺���Ļ�����ⲿ�豸
//���� - ��׼�����豸
//��Ļ - ��׼����豸
//��ÿ������Ĭ�ϴ򿪵��������豸
//����Ĭ�ϴ򿪵����豸��stdin��stdout��stderr
//FILE* stdin
//FILE* stdout
//FILE* stderr

//��ˣ��ļ���д�������Բ�����׼���������
//int main()
//{
//    int ch = fgetc(stdin);
//    fputc(ch, stdout);
//
//    return 0;
//}

//��ϰʹ���ļ���д����
//int main()
//{
//    char buf[100] = { 0 };
//    FILE* pf = fopen("test.txt", "r");
//    if (!pf)
//    {
//        printf("%s", strerror(errno));
//        return 0;
//    }
//    //���ļ�
//    fgets(buf, 100, pf);
//    //printf("%s", buf);       //��ӡ������ͬʱע��printf��fprintf��puts��fputs���ߵĲ�ͬ����ͬ
//    //fprintf(stdout, "%s", buf);
//    //puts(buf);
//    //fputs(buf, stdout);
//
//    fgets(buf, 100, pf);
//    //printf("%s", buf);
//    //fprintf(stdout, "%s", buf);
//    //puts(buf);
//    //fputs(buf, stdout);
//
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

//int main()
//{
//    char buf[100] = { 0 };
//
//    FILE* pf = fopen("test.txt", "w");
//    if (!pf)
//    {
//        printf("%s", strerror(errno));
//        return 0;
//    }
//    //д�ļ�
//    //scanf("%s", buf);
//    //fscanf(stdin, "%s", buf);
//    //gets(buf);
//    //fgets(buf, 100, stdin);
//    fputs(buf, pf);
//
//    fclose(pf);
//    pf = NULL;
//
//    return 0;
//}

//�����⣨�Ա����к�����
//printf/fprintf/sprintf
//scanf /fscanf /sscanf
//
//print��scanf   ����� ��׼��������� �� ��ʽ�������������
//fprintf��fscnaf����� ������������� �� ��ʽ�������������

//sscanf��sprintf
//struct S
//{
//    int i;
//    float f;
//    char arr[10];
//};
//int main()
//{
//    struct S s = { 100, 3.14f, "abcdef" };
//    char buf[1024] = { 0 };
//
//    sprintf(buf, "%d %f %s", s.i, s.f, s.arr);
//
//    struct S tmp = { 0 };
//    sscanf(buf, "%d %f %s", &(tmp.i), &(tmp.f), tmp.arr);
//
//    //���Կ����
//    return 0;
//}
//
//int sprintf( char *buffer, const char *format [, argument] ... );
//������Ĳ���������format�ַ����ĸ�ʽת��str���ٴ洢��buffer
//
//int sscanf( const char *buffer, const char *format [, argument ] ... );
//��ǰ����ַ���buffer������format�ĸ�ʽ��ȡ���ݣ��ٴ洢������Ĳ���

//struct S
//{
//    char name[20];
//    int age;
//    double score;
//};
//int main()
//{
//    struct S s[3] = {
//        { "����", 20, 59.9},
//        { "����", 20, 59.9 },
//        { "����", 20, 59.9 },
//    };
//    FILE* pf = fopen("test.txt", "wb");
//    if (!pf)
//        return 0;
//    //�Զ����Ƶ���ʽд�ļ�
//    fwrite(&s, sizeof(struct S), 3, pf);
//
//    fclose(pf);
//    pf = NULL;
//
//    //��ͬĿ¼��test.txt�ļ������
//    return 0;
//}
//int main()
//{
//    struct S s[3] = { 0 };
//    FILE* pf = fopen("test.txt", "rb");
//    if (!pf)
//        return 0;
//    //�Զ����Ƶ���ʽ���ļ�
//    fread(&s, sizeof(struct S), 3, pf);
//
//    fclose(pf);
//    pf = NULL;
//
//    //���Կ����
//    return 0;
//}



//�ļ��������д

//fseek
// ��λ�ı�ָ�루�����ļ�ָ�룩ָ���ض����ı�λ��
// 
// ����
// int fseek( FILE *stream, long offset, int origin );
// 
// offset��ƫ����
// origin����ʼƫ�Ƶ�λ�ã���SEEK_CUR����ǰ�ı�ָ���λ�ã�, SEEK_END �� SEEK_SET
//
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");
//    if (!pf)
//        return 0;
//    //1.��λ�ı�ָ��
//    fseek(pf, -2, SEEK_END);      //SEEK_ENDһ����'\0'
//
//    //2.��ȡ�ļ�
//    int ch = fgetc(pf);
//    printf("%c\n", ch);
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//ftell
// �����ı�ָ�������SEEK_SET��ƫ����
// 
// ����
// long ftell( FILE *stream );
//
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");
//    if (!pf)
//        return 0;
// 
//    //�ı�ָ������ʼλ��
//    long pos = ftell(pf);
//    printf("%ld\n", pos);
//
//    //�ı�ָ������ʼλ�ú�3���ֽڴ�
//    fseek(pf, 3, SEEK_SET);
//    pos = ftell(pf);
//    printf("%ld\n", pos);
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}

//rewind
// ���ı�ָ��ص�SEEK_SETλ��
// 
// ����
// void rewind( FILE *stream );
//
//int main()
//{
//    FILE* pf = fopen("test.txt", "r");
//    if (!pf)
//        return 0;
//
//    fseek(pf, 3, SEEK_SET);
//    rewind(pf);
//
//    int ch = fgetc(pf);
//    printf("%c\n", ch);
//
//    fclose(pf);
//    pf = NULL;
//    return 0;
//}



//�ļ��Ľ����ж�
//
//
