import os
#----------------------------------------------------------------------------------------------------------------------------------------
def max_difference (FileName) :
    try:
        if os.stat(FileName).st_size > 0: #проверка на непустоту файла
            f=open(FileName,'r')
            max_difference=0 
            n=0 #счетчик 
            for s in f:
#удостоверяемся, что все элементы последовательности находятся каждый на своей строке ---------------------------------------------------
                for s1 in s.split(' '):             
                    for s2 in s1.split('\n'):
                        for s3 in s2.split('\t'):
                            for s4 in s3.split(','):
                                if (s4 != ''):
#----------------------------------------------------------------------------------------------------------------------------------------
                                    n+=1
                                    if n==1:        #если считываeтся элемент в первый раз
                                        element_1=int(s4)
                                    if n>1:        #если считываются элементы после 1
                                        element_2=int(s4)
                                        if element_2>element_1:
                                            difference = element_2-element_1
                                        else:
                                            difference = element_1-element_2
                                        if difference > max_difference:
                                            max_difference=difference
                                        element_1=element_2
            f.close()
            return 0, max_difference
        else:
            print ("File is empty!") #вывод, если файл пустой
            return -2,0
    except FileNotFoundError:   #файл вообще не был найден
        print ("File wasn't found!")
        return -2, 0
#----------------------------------------------------------------------------------------------------------------------------------------
def main():
    rez=0;err=0
    print ("Enter the name of your file") #просим пользователя ввести имя файла
    err,rez=max_difference(input() +'.txt') #вызываем функцию поиска максимального перепада с заданным именем файла
    if err:
        print("ERROR!")
    else:
        print("Max difference = ", rez)
#----------------------------------------------------------------------------------------------------------------------------------------
main()

