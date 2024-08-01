import os
#----------------------------------------------------------------------------------------------------------------------------------------
def local_elements(FileName) :
    try:
        if os.stat(FileName).st_size > 0: #проверка на непустоту файла
            f=open(FileName,'r')
            count=0 #кол-во элементов, удовлетворяющих условию задачи
            n=0 #счетчик элемента, который считывается
            for s in f:
#удостоверяемся, что все элементы последовательности находятся каждый на своей строке ---------------------------------------------------
                for s1 in s.split(' '):             
                    for s2 in s1.split('\n'):
                        for s3 in s2.split('\t'):
                            for s4 in s3.split(','):
                                if (s4 != ''):
#----------------------------------------------------------------------------------------------------------------------------------------
                                    n+=1
                                    if n==1:
                                        el_1 = int(s4)
                                    if n==2:
                                        el_2=int(s4)
                                    if n >2:
                                        el_3=int(s4)
                                        if el_1 < el_2 and el_2 > el_3:
                                            print("Local maximum = ", el_2)
                                        elif el_1>el_2 and el_2 < el_3:
                                            print ("Local minimum = ", el_2)
                                        else:
                                            count+=1
                                        el_1=el_2
                                        el_2=el_3
                                            
            f.close()
            return 0, count
#первый и последний элементы последовательности не явл-ся локальными максимумами или локальными минимумами
        else:
            print ("File is empty!") #вывод, если файл пустой
            return -2,0
    except FileNotFoundError:   #файл вообще не был найден
        print ("File wasn't found!")
        return -2, 0
#----------------------------------------------------------------------------------------------------------------------------------------
def main():
    rez=0
    err=0
    print ("Enter the name of your file") #просим пользователя ввести имя файла
    err,rez=local_elements(input() +'.txt') #вызываем функцию подсчета элементов, которые не явл-ся локальными максимумами или минимумами
    if err:
        print("ERROR!")
    else:
        if rez > 0:
            print("There are elements which are not local maximum or local minimum. The amount of such elements is", rez)
        else:
            print("There are NO elements which are not local maximum or local minimum")
#----------------------------------------------------------------------------------------------------------------------------------------
main()

