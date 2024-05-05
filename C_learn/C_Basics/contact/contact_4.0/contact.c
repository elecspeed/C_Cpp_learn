#include "contact.h"

static int once = 1;

static long fsize(FILE *pf)
{
    // 返回文件大小，单位是字节
    fpos_t fpos;
    fgetpos(pf, &fpos);
    fseek(pf, 0, SEEK_END);
    long ret = ftell(pf);
    fsetpos(pf, &fpos);
    return ret;
}
static void ExtendContact(contact *cont)
{
    // 扩容通讯录
    cont->_capacity =
        (cont->_capacity < 2 ? 4 : cont->_size * 2);
    person *tmp_ptr =
        (person *)realloc(cont->_data, SIZE_PERSON * cont->_capacity);
    if (!tmp_ptr)
    {
        perror("ExtendContact::realloc failure");
        exit(-1);
    }
    cont->_data = tmp_ptr;
    tmp_ptr = NULL;
}
static void EnterInformation(person *data)
{
    printf("name: ");
    scanf("%s", data->_name);
    printf("sex: ");
    scanf("%s", data->_sex);
    printf("age: ");
    scanf("%s", data->_age);
    printf("telephone: ");
    scanf("%s", data->_telephone);
    printf("address: ");
    scanf("%s", data->_address);
}
static void Instruction()
{
    // 使用指南
    printf("\n"
           "EXAMPLE\n"
           //    "Name            Sex    Age Telephone       Address\n"
           //    "aaa             male   18  123             unknow\n"
           //    "bbb             male   18  1234            China_Peking\n"
           //    "ccc             female 18  12345           England_London\n"
           //    "Please enter your choice: 3\n"
           "Enter the key informations.\n"
           "name: .\n"
           "sex: male\n"
           "age: 18\n"
           "telephone: .\n"
           "address: .\n"
           //    "Name            Sex    Age Telephone       Address\n"
           //    "aaa             male   18  123             unknow\n"
           //    "bbb             male   18  1234            China_Peking\n"
           //    "continue or not?(Y/N): y\n"
           //    "name: aaa\n"
           //    "telephone: .\n"
           //    "address: .\n"
           //    "Name            Sex    Age Telephone       Address\n"
           //    "aaa             male   18  123             unknow\n"
           "\n");
}
static int *FilterContact(contact *cont,
                          person *keyInformation,
                          int *nums)
{
    // 筛选联系人
    // 函数返回动态数组，存储符合关键信息的联系人的对应下标
    // nums 为该数组大小
    char *key_member[5] = {
        keyInformation->_name,
        keyInformation->_sex,
        keyInformation->_age,
        keyInformation->_telephone,
        keyInformation->_address,
    };
    char *firstElem_member[5] = {
        cont->_data->_name,
        cont->_data->_sex,
        cont->_data->_age,
        cont->_data->_telephone,
        cont->_data->_address,
    };
    int *index_arr =
        (int *)malloc(sizeof(int) * cont->_capacity);
    if (!index_arr)
    {
        perror("SearchContact::allocation failure");
        exit(-1);
    }
    index_arr[0] = -1;
    int count1 = cont->_size, count2 = 0;
    // 三个数组
    // key_member：存储 keyInformation 数据成员的地址
    // firstElem_member：存储 cont->_data 首元素的数据成员的地址
    // index_arr：存储匹配成功的下标
    // 两个变量
    // count1：要匹配的次数
    // count2：一轮筛选结束后，匹配成功的个数
    //
    // index_arr[0] 设为 -1，
    // 用来判断是否是第一次筛选。

    for (int i = 0; i < 5; ++i)
        if (*key_member[i] != '.')
        {
            // 首字符为 '.'，
            // 表示该关键信息未知（即对应的数据成员未知）；
            // 首字符不为 '.'，
            // 表示该关键信息可以用来筛选。
            if (index_arr[0] < 0)
            {
                // 第一次筛选，筛选全部联系人
                for (int j = 0; j < count1; ++j)
                    if (!strcmp(key_member[i],
                                firstElem_member[i] + SIZE_PERSON * j))
                        index_arr[count2++] = j;
            }
            else
                // 第二次及以后筛选，根据前一个筛选结果来筛选
                for (int j = 0; j < count1; ++j)
                    if (!strcmp(key_member[i],
                                firstElem_member[i] + SIZE_PERSON * index_arr[j]))
                        index_arr[count2++] = index_arr[j];
            if (!count2)
            {
                // 某一次筛选（即某一个关键信息）没有匹配的联系人
                free(index_arr);
                if (!nums)
                    *nums = 0;
                return NULL;
            }
            count1 = count2;
            count2 = 0;
        }
    if (index_arr[0] < 0)
    {
        // 没有筛选出相关下标，说明
        // 1.用户对每个关键信息都输入了 '.'；
        // 2.某一个关键信息没有匹配的联系人
        //
        // 只能是 1，情况 2 已经在循环时被 return。
        free(index_arr);
        if (nums)
            *nums = -1;
        return NULL;
    }
    if (nums)
        *nums = count1;
    return index_arr;
}
void InitContact(contact *cont)
{
    // 初始化通讯录
    FILE *pf = fopen("contact.cat", "r+");
    if (!pf)
    {
        // 没找到文件，可能丢了或本来就没有
        cont->_capacity = 4;
        cont->_size = 0;
        cont->_data = (person *)
            malloc(SIZE_PERSON * cont->_capacity);
        if (!cont->_data)
        {
            perror("InitContact::Malloc failure");
            exit(-1);
        }
        return;
    }
    // 找到文件，读取文件
    cont->_size = cont->_capacity = fsize(pf) / SIZE_PERSON;
    cont->_data = NULL;
    ExtendContact(cont);
    size_t tmp =
        fread(cont->_data, SIZE_PERSON, cont->_size, pf);
    if (ferror(pf))
    {
        perror("InitContact::ferrer");
        exit(-1);
    }
    else if (tmp == cont->_size || feof(pf))
        printf("Read file successfully.\n");
    fclose(pf);
    pf = NULL;
}
void DisplayContact(contact *cont)
{
    // 展示通讯录
    if (cont->_size == 0)
    {
        printf("There is nobody.\n");
        return;
    }
    printf("Name            Sex    Age Telephone       Address\n");
    for (int i = 0; i < cont->_size; ++i)
        printf("%-16s%-7s%-4s%-16s%s\n",
               cont->_data[i]._name,
               cont->_data[i]._sex,
               cont->_data[i]._age,
               cont->_data[i]._telephone,
               cont->_data[i]._address);
    putchar('\n');
}
void AddContact(contact *cont)
{
    // 添加联系人
    if (cont->_capacity == cont->_size)
        ExtendContact(cont);

    EnterInformation(&cont->_data[cont->_size]);
    cont->_size++;
    printf("Add success!\n\n");
}
void EraseContact(contact *cont)
{
    // 删除联系人
    // 先找到该联系人
    if (once)
    {
        Instruction();
        --once;
    }
    printf("Enter the key informations.\n");
    person keyInformation; // 存储关键信息
    EnterInformation(&keyInformation);

    int nums = 0;
    int *list = FilterContact(cont, &keyInformation, &nums);
    if (!list)
    {
        printf("No find.\n");
        return;
    }
    if (nums == 1)
    {
    }
}
void SearchContact(contact *cont)
{
    // 查找联系人
    if (once)
    {
        Instruction();
        --once;
    }
    printf("Enter the key informations.\n");
    person keyInformation; // 存储关键信息
    EnterInformation(&keyInformation);

    // 根据关键信息来筛选
    int nums = 0;
    int *list = FilterContact(cont, &keyInformation, &nums);
    if (!list)
    {
        if (nums == 0)
            // 没有符合的联系人
            printf("No find.\n");
        if (nums == -1)
            // 输入全为 '.'
            printf("Sorry, unable to Search.\n");
    }
    else
    {
        // 最后把符合关键信息的联系人展示出来
        printf("Name            Sex    Age Telephone       Address\n");
        for (int i = 0; i < nums; ++i)
            printf("%-16s%-7s%-4s%-16s%s\n",
                   cont->_data[list[i]]._name,
                   cont->_data[list[i]]._sex,
                   cont->_data[list[i]]._age,
                   cont->_data[list[i]]._telephone,
                   cont->_data[list[i]]._address);
    }
    putchar('\n');
    free(list);
}
void ModifyContact(contact *cont) {}
void SaveContact(contact *cont)
{
    FILE *pf = fopen("contact.cat", "w");
    if (!pf)
    {
        perror("SaveContact::fail to open file");
        exit(-1);
    }
    fwrite(cont->_data, SIZE_PERSON, cont->_size, pf);
    fclose(pf);
    pf = NULL;
    printf("Save success!\n\n");
}
void DestroyContact(contact *cont)
{
    cont->_capacity = cont->_size = 0;
    free(cont->_data);
    cont->_data = NULL;
}
