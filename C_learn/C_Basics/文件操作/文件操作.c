#define _CRT_SECURE_NO_WARNINGS 1

// ʲô���ļ���Ϊʲô��Ҫ�ļ�
// �ļ������ļ�����
// �ļ�������
// �ļ�ָ��
// �ļ��Ĵ���ر�
// ˳���д�������д
// �ļ��������ж�

#include <stdio.h>
#include <string.h>
#include <errno.h>

/*
 * ��������ŵĶ����ļ�
 *
 * > Linux ������֮һ��һ�н��ļ�
 *
 * ֮ǰ��������ݣ���������������ն��Ͻ��С�
 * ����Ҫ�����ݵ��������ת�������Ͻ��У�
 * ����ı��Ǵ����ϵ��ļ�
 *
 * �������ݴ�ŵ����̣���Ϊ��ʹ���ݳ־û���
 * ���ȳ�����Ҫ�� CPU ���У����ȷŽ��ڴ档
 *
 * > CPU - register - memory - disk
 *
 * ���ڴ�Ŀռ������޵ģ����������н�����ռ��Ҫ�����ա�
 * ����ִ�й��������ɵ�����Ҳ�����ų���Ľ��������ͷš�
 * ����ڴ棬���̵Ŀռ���󣬶���д���ݵ��ٶȸ�����
 * �ʺ������洢���ݡ�
 * ��˴��������洢�������ݣ����ڴ��������������¡���
 */

/*
 * �ļ������ļ�·��+�ļ�������+�ļ���׺�������չ����
 * ����C:\User\test.txt
 *
 * �ļ�����
 * ����д������ʱ���ݵ���֯��ʽ��
 * �ļ�����Ϊ�ı��ļ���������ļ���
 * ���ݲ�����ת�������ڴ�ֱ�Ӵ�����̣�Ϊ�������ļ���
 * ����ͨ�� ASCII �ȱ���ת�����ٴ��ڴ������̣���Ϊ�ı��ļ���
 *
 * �ַ�ֻ���� ASCII �ȱ���洢��
 * ��ֵ�����ݿ����� ASCII �ȱ���洢��Ҳ�����ö�������ʽ�洢��
 * ����˼�ǣ���ֵ�������ԡ������ַ�������ʽ�����ǿ�����
 * ����ô�洢ʱ���������ַ��Ĵ洢��ʽ�洢��Ҳ�����ö����Ƶķ�ʽ��
 */

/*
 * �ļ�������
 * C ��׼���á������ļ�ϵͳ�������ļ���
 *
 * �ӳ���������ݵ��ⲿ���ļ����ն˵ȣ���
 * ����ⲿ�������ݵ�����
 * ��Ҫ������������
 *
 * �õײ�Ӳ���Ͳ���ϵͳ��֪ʶ�����͡�
 * ϵͳ���Զ����ڴ��У�
 * Ϊ�����ÿһ������ʹ�õ��ļ�����һ�顰�ļ�����������
 * ���ڴ�ʹ���֮�����������ݣ����ȴ������뻺�����������������
 * ֱ�����������ˣ�
 * ��д���Ӧ�Ĵ洢����
 * �������н������ǻ�����δ����
 * ʣ�µ�����һ���ᱻд���Ӧ�Ĵ洢����
 *
 * �������Ĵ�С�� C ����ϵͳ������
 */

/*
 * �ļ�ָ��
 * �ڻ����ļ�ϵͳ�У�ÿ����ʹ�õ��ļ�
 * �����ڴ��п�����һ���ļ���Ϣ����ע�ⲻ���ļ�����������
 * ���ļ���Ϣ����������ļ��������Ϣ
 * �����ļ������ļ�״̬���ļ�λ�õȣ���
 *
 * ������ļ���Ϣ�����͸պ��ǽṹ���������
 * ���ǣ�ϵͳ���ýṹ����������Ϊ FILE��
 * ÿʹ��һ���ļ���
 * ϵͳ�ʹ���һ�� FILE �ṹ����������Զ���ʼ����Ա������
 * ������Щ��Ա�����洢�������Ϣ��
 * ���Ե��ļ������Ϣ�����仯��
 * FILE �ĳ�Ա����Ҳ�ᷢ���仯��
 *
 * ��ô����鿪�ٵĿռ���ɡ��ļ�ָ�롱������
 * �����˸о����ļ���������Խṹ�� FILE �Ķ�̬�ڴ������
 */

// �۲� FILE ��Ա
// int main()
// {
//     // �� "r","w","a" ���ַ�ʽ�򿪵��ļ���
//     // �� FILE ��Ա��ʲô��ͬ
//     char *str_arr[3] = {"r", "w", "a"};
//     int i;
//     for (i = 0; i < 3; ++i)
//     {
//         FILE *pf = fopen("./test.txt", str_arr[i]);
//         if (!pf)
//             return 0;
//         else
//         {
//             printf("%s\n", pf->_base);
//             printf("%d\n", pf->_bufsiz);
//             printf("%d\n", pf->_charbuf);
//             printf("%d\n", pf->_cnt);
//             printf("%d\n", pf->_file);
//             printf("%d\n", pf->_flag);
//             printf("%s\n", pf->_ptr);
//             printf("%s\n", pf->_tmpfname);
//             fclose(pf);
//         }
//     }
//     return 0;
// }

/*
 * �ļ�ʹ��ǰҪ�ȴ򿪣�ʹ����Ҫ�رա�
 * C ����ÿ���ļ������᷵���ļ���Ϣ���ĵ�ַ����̬�ڴ���䣩��
 * �൱�ڽ�����ָ����ļ�����ϵ��
 */

/*
 * fopen ����
 * ����
 * FILE *fopen( const char *filename, const char *mode );
 * filename���ļ�����
 * mode���򿪷�ʽ��
 *
 * �򿪷�ʽ
 * "r"����ֻ���ķ�ʽ�򿪡�
 *      ���ָ���ļ������ڻ�û�ҵ������� NULL��
 * "w"����ֻд�ķ�ʽ�򿪡�
 *      ���ڣ������ݽ�����գ�
 *      �����ڣ��½�һ����
 * "a"����ֻ׷�ӵķ�ʽ�򿪡�
 *      �������ȴ�����
 *      ֻ�����ļ�β��д�����ݡ�
 * "r+"���Զ�д�ķ�ʽ�򿪡�
 *       ����ͬ "r"��
 * "w+"���Զ�д�ķ�ʽ�򿪡�
 *       ����ͬ "w"
 * "a+"���Զ�д�ķ�ʽ�򿪡�
 *       ��׷�ӵ��ļ��� EOF ��β��
 *       ����ͬ "a"
 * ��ʹ�� "a" �� "a+"��ԭ���ݲ��ᱻ�޸ģ�
 *
 * ��׺ t,b,c,n
 * t�����ı�ģʽ�򿪡��漰�ı��������⡣
 * b���Զ�����ģʽ�򿪡�
 * c��δ֪
 * n��δ֪
 */

// ���ļ� test.txt
// int main()
// {
//     // ����·��
//     // FILE *pf = fopen(
//     //     "C:\\Users\\elecspeed\\Desktop\\test.txt",
//     //     "r");
//     // ���·��
//     // FILE *pf = fopen("../../test.txt", "r");
//
//     FILE *pf = fopen("test.txt", "r");
//     if (!pf)
//     {
//         // ��ʧ��
//         printf("%s", strerror(errno));
//         return 0;
//     }
//     // ...
//
//     // �ر��ļ�
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

/*
 * �ر��ļ�
 * Closes a stream (fclose)
 * or
 * closes all open streams except for stdin,stdout,stderr
 * (_fcloseall).
 *
 * ����
 * int fclose( FILE *stream );
 * int _fcloseall( void );
 * stream����Ӧ���ļ�ָ��
 *
 * fclose �ɹ����� 0�����򷵻� EOF��
 * _fcloseall �ɹ����عرյ��ļ��������򷵻� EOF��
 */

/*
 * �ļ���˳���д
 * ������       ����                ������
 * fgetc       �ַ�����            ����������
 * fputc       �ַ����            ���������
 * fgets       �ı�������
 * fputs       �ı������          ͬ��
 * fscanf      ��ʽ������
 * fprintf     ��ʽ�����          ͬ��
 * fread       ����������          �ļ�
 * fwrite      ���������          �ļ�
 */

// int main()
// {
//     // ��ͬ�Ĵ򿪷�ʽ���в�ͬ�Ķ�д����
//     FILE *pf = fopen("test.txt", "r");
//     if (!pf)
//     {
//         printf("%s\n", strerror(errno));
//         return 0;
//     }
//
//     // д
//     fputc('g', pf);
//     // ��
//     int ch = fgetc(pf);
//     putchar(ch);
//
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

/*
 * ���̺���Ļ�����ṩ�������豸��
 * ���� - ��׼�����豸
 * ��Ļ - ��׼����豸
 * ������ÿ������Ĭ�ϴ򿪵��������豸��
 * ��ʵ��
 * һ��������Ĭ�ϴ򿪵����豸��stdin,stdout,stderr
 * FILE* stdin
 * FILE* stdout
 * FILE* stderr
 *
 * ��ˣ��ļ���д�������Բ�����׼���������
 */

// int main()
// {
//     int ch = fgetc(stdin);
//     fputc(ch, stdout);
//     return 0;
// }

// ��ϰʹ���ļ���д�������ԣ�

// �����⣨�Ա����к�����
// printf,fprintf,sprintf
// scanf,fscanf,sscanf
//
// printf �� scanf ����� ��׼��������� �� ��ʽ�������������
// fprintf �� fscnaf ����� ������������� �� ��ʽ�������������
// ��ˣ�
// printf,scanf �ֱ��� fprintf,fscanf ���Ӽ���

// sscanf �� sprintf
// struct S
// {
//     int i;
//     float f;
//     char arr[10];
// };
// typedef struct S S;
// int main()
// {
//     S s = {100, 3.14f, "abcdef"};
//     S tmp = {0};
//     char buf[1024] = {0};
//
//     sprintf(buf,
//             "%d %f %s",
//             s.i, s.f, s.arr);
//     sscanf(buf,
//            "%d %f %s",
//            &(tmp.i), &(tmp.f), tmp.arr);
//     // ���Կ����
//     return 0;
// }

/*
 * sprintf �� sscanf
 * ����
 * int sprintf( char *buffer, const char *format [, argument] ... );
 * �ַ�����ʽ��
 *
 * int sscanf( const char *buffer, const char *format [, argument ] ... );
 * ��ȡ��ʽ���ַ����е�����
 */

// struct S
// {
//     char name[8];
//     int age;
//     double score;
// };
// typedef struct S S;
// int main()
// {
//     S s1[3] = {
//         {"����", 20, 59.9},
//         {"����", 20, 59.9},
//         {"����", 20, 59.9},
//     };
//     FILE *pf = fopen("test.txt", "wb");
//     if (!pf)
//         return 0;
//     fwrite(&s1, sizeof(S), 3, pf);
//     fclose(pf);
//     // ��ͬĿ¼�� test.txt �ļ������
//
//     S s2[3] = {0};
//     pf = fopen("test.txt", "rb");
//     if (!pf)
//         return 0;
//     fread(&s2, sizeof(S), 3, pf);
//     fclose(pf);
//     pf = NULL;
//     // ���Կ����
//     return 0;
// }

// �ļ��������д

/*
 * fseek
 * ��λ�ı�ָ���λ�ã�ע�ⲻ���ļ�ָ�룩
 *
 * ����
 * int fseek( FILE *stream, long offset, int origin );
 * stream����Ӧ���ļ�ָ��
 * offset��ƫ��������λ���ֽ�
 * origin����ʼƫ�Ƶ�λ�ã����֣�
 *         SEEK_CUR����ǰ�ı�ָ���λ��
 *         SEEK_END���ı�ĩ
 *         SEEK_SET���ı���
 *
 * �ɹ����� 0�����򷵻ط��㡣
 * ���ڲ��ܶ�λ�Ļ������䷵��ֵδ���塣
 */

// int main()
// {
//     FILE *pf = fopen("test.txt", "w+");
//     if (!pf)
//         return 0;
//
//     // 1.��λ�ı�ָ��
//     fseek(pf, -2, SEEK_END); // SEEK_END һ���� '\0'
//     // 2.��ȡ�ļ�
//     int ch = fgetc(pf);
//     printf("%c\n", ch);
//
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// ftell
//  �����ı�ָ�������SEEK_SET��ƫ��������λ���ֽ�
//
//  ����
//  long ftell( FILE *stream );
//
// int main()
//{
//     FILE* pf = fopen("test.txt", "r");
//     if (!pf)
//         return 0;
//
//     //�ı�ָ������ʼλ��
//     long pos = ftell(pf);
//     printf("%ld\n", pos);
//
//     //�ı�ָ������ʼλ�ú�3���ֽڴ�
//     fseek(pf, 3, SEEK_SET);
//     pos = ftell(pf);
//     printf("%ld\n", pos);
//
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// rewind
//  ���ı�ָ��ص�SEEK_SETλ��
//
//  ����
//  void rewind( FILE *stream );
//
// int main()
//{
//     FILE* pf = fopen("test.txt", "r");
//     if (!pf)
//         return 0;
//
//     fseek(pf, 3, SEEK_SET);
//     rewind(pf);
//
//     int ch = fgetc(pf);
//     printf("%c\n", ch);
//
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// �ļ��������ж�
//  fgetc��fgets��fread ���з���ֵ���������˵����ȡ���� �� ��������
//
//  fgetc    ����EOF��end of file���ļ�������־��ֵΪ-1��
//  fgets    ����NULL��ֵΪ0
//  fread    ����ֵС��ʵ��Ҫ���ĸ���

// feof
//  Tests for end-of-file on a stream.
//  �ж��ļ�������ԭ���ǲ��Ƕ�ȡ������
//
//  ����
//  int feof( FILE *stream );
//
//  �Ƕ�ȡ�������򷵻ط��㣨�������棩
//

// ferror
//  Tests for an error on a stream.
//  �ж��ļ�������ԭ���ǲ��Ƿ�������
//
//  ����
//  int ferror( FILE *stream );
//
//  �Ƿ��������򷵻ط��㣨�������棩
//

// feof �� ferror ����һ��ʹ��

// �Ƚ���perror
//  strerror - �Ѵ������Ӧ���ַ��� �ĵ�ַ����
//  perror - �ڴ�����Ϣǰ�����Զ���˵����ֱ�Ӵ�ӡ
//
// int main()
//{
//     FILE* pf = fopen("test2.txt", "r");
//     if (!pf)
//     {
//         //perror("");
//         perror("abcd");
//         return 0;
//     }
//     //...
//
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }

// ʹ�� feof �� ferror
// int main()
//{
//     //��test.txt�ļ�
//     FILE* pf = fopen("test.txt", "r");
//     if (!pf)
//     {
//         perror("fail to open test.txt");
//         return 0;
//     }
//
//     //ѭ����ȡ�ļ�
//     int ch = 0;
//     while ((ch = fgetc(pf)) != EOF)
//         putchar(ch);
//     printf("\n");
//
//     //�ж�ѭ��������ԭ��
//     if (ferror(pf))
//         puts("I/O error when reading");
//     else if (feof(pf))
//         puts("End of file reached successfully");
//
//     //�ر��ļ�
//     fclose(pf);
//     pf = NULL;
//     return 0;
// }
