print(i, end='')  # 就可以连着输出没有默认的空格
print(a // b, a / b, sep='\n')  # 地板除//（向下取整）


def is_leap(year):
    return (year % 400 == 0) or ((year % 100 != 0) and (year % 4 == 0))

