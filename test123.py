# class Mammal:
#   def __init__(self):
#     print('is a warm-blooded animal.')
#     self.name = "Sam"
    
# class Dog(Mammal):
#   def __init__(self):
#     print('Dog has four legs.')
#     super().__init__()
#     print(super().name)
    
# d1 = Dog()
a = input()
# print(type(a))
a = list(map(int,a.split() ) )
# print(a)
b=1
for i in range(1,a[0]+1):
  b*=i

print(b)
# b = "".join(a)

# print(a,b)