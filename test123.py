class Mammal:
  def __init__(self):
    print('is a warm-blooded animal.')
    self.name = "Sam"
    
class Dog(Mammal):
  def __init__(self):
    print('Dog has four legs.')
    super().__init__()
    print(super().name)
    
d1 = Dog()