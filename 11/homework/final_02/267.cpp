#include <stdio.h>
int month_day1[13] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int month_day2[13] = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
typedef struct
{
    int id;
    int month;
    int day;
    int gender;
} Data1;
typedef struct
{
    int start_month, start_day;
    int end_month, end_day;
    int total_babies;
    int boy;
} Data2;
int isRunYear(int x)
{
    if ((x % 4 == 0 && x % 100 != 0) || (x % 400 == 0))
        return 1;
    return 0;
}
int whatDayInYear(int month, int day, int year)
{
    int curr_days = 0;
    if (isRunYear(year))
    {
        for (int j = 0; j < month; j++)
        {
            curr_days += month_day2[j];
        }
    }
    else
    {
        for (int j = 0; j < month; j++)
        {
            curr_days += month_day1[j];
        }
    }
    return curr_days + day;
}
int main()
{
    int year, n, m;
    scanf("%d", &year);
    scanf("%d %d", &n, &m);
    int year_day[55];  // 年天数
    Data1 baby[10005]; // 新生儿数据
    Data2 week[55];    // 统计新生儿数量
    // 查表：第几天对应的是第几周
    int dayToWeek[367];
    // 先计算年份对应的天数
    int fromDays = 0;
    for (int i = 1969; i <= year; i++)
    {
        if (i == year)
            break;
        if (isRunYear(i))
            year_day[i - 1969] = 366;
        else
            year_day[i - 1969] = 365;

        fromDays += year_day[i - 1969];
    }
    // 我要确定这一年的第一周是从哪里开始的，这样会容易计算
    int whatday = (fromDays + 3) % 7; // 0~6代表星期天到星期六
    // 预处理周
    // week[1].start_month = 1;
    // week[1].start_day = 1;
    // week[1].end_month = 1;
    // week[1].end_day = 1 + 6 - whatday;
    // for (int i = 1 + 6 - whatday; i <=year_day[year-1969];i++)
    // {
    //     int start=i;

    // }
    // 采用模拟法，一天一天过，遇到周六截断
    int current_week_idx = 0;
    int day_cnt = 0; // 天数计算器
    int total_days_year = isRunYear(year) ? 366 : 365;
    int is_new_week = 1;
    // 确定每个月的天数数组
    int *curr_month_days = isRunYear ? month_day2 : month_day1;

    for (int i = 1; i <= 12; i++)
    {
        int days_in_this_month = curr_month_days[m - 1];

        for (int d = 1; d <= days_in_this_month; d++)
        {
            day_cnt++; // 这一年的第几天

            if (is_new_week)
            {
                week[current_week_idx].start_month = m;
                week[current_week_idx].start_day = d;
                week[current_week_idx].total_babies = 0;
                week[current_week_idx].boy = 0;
                is_new_week = 0;
            }

            dayToWeek[day_cnt] = current_week_idx;
            // 计算今天是星期几
            // (1月1日星期几 + 过去了多少天) % 7
            int current_weekday = (whatday + day_cnt - 1) % 7;
            // 如果今天是星期六(6) 或者 今天是这一年的最后一天，本周结束
            if (current_weekday == 6 || day_cnt == total_days_year)
            {
                week[current_week_idx].end_month = m;
                week[current_week_idx].end_day = d;
                current_week_idx++;
                is_new_week = 1;
            }
        }
    }
    // 都是一个年份的，直接计算
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d %d", &baby[i].id, &baby[i].month, &baby[i].day, &baby[i].gender);
        int curr_day = whatDayInYear(baby[i].month, baby[i].day, year);
        // 查表得到是第几周
    }
    return 0;
}
