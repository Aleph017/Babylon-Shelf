import random
import string
import time

letters = 'абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ' + string.ascii_letters

print("Добро пожаловать в одну из полок Вавилонской Библиотеки! Здесь можно найти любое слово, но чем оно длинее, тем больше времени понадобится - одно слово можно искать тысячи лет(!)")

goal_word = input("Какое слово вы хотите найти? ")

def babylon_shelf():
    counter = 0
    while True:
        idk = ""
        for _ in range(len(goal_word)):
            idk += random.choice(letters)
        counter += 1
        if counter % 100000 == 0:
            print("100,000 passed")
        if idk.lower() == goal_word.lower():
            return counter

# Запоминаем текущее время до выполнения функции
start_time = time.time()

attempts = babylon_shelf()

# Запоминаем текущее время после выполнения функции
end_time = time.time()

execution_time = end_time - start_time

print(f"Слово {goal_word} было найдено! Для этого понадобилось перебрать {attempts} символов, это заняло {execution_time:.2f} секунд.")
