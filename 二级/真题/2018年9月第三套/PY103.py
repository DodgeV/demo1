# 以下代码为提示框架
# 请在...处使用一行或多行代码替换
# 请在______处使用一行代码替换


n = eval(input("请输入一个数字:"))
print("{__________}".format(___________)) 


######################答案#####################################
n = eval(input("请输入一个数字:"))
print("{:+^11}".format(chr(n - 1) + chr(n) + chr(n+1))) 
