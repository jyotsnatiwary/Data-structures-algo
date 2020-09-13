class Person():
    def __init__(self, person_name, person_age, person_weight, person_height):
        print("constructor ")
        self.name=person_name
        self.age=person_age
        self.weight=person_weight
        self.height=person_height

person1= Person("Om",20,"74 kg","170 cm")

person2= Person("Som", 25,"78 Kg","175cm")


person3=Person('Sahil',28,'65 Kg','165 cm')

person4=Person('Sahil',28,'65 Kg','165 cm')
print(person3.age)

print(person1.age)

print(person1.name)

print(person2.name)

print(person4.name)
