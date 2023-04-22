class MyClass:
    def __init__(self, param1, param2):
        self.param1 = param1
        self.param2 = param2

    def __init__(self, param1, param2, param3):
        self.param1 = param1
        self.param2 = param2
        self.param3 = param3

# 測試
obj1 = MyClass(1, 2)
print(obj1)
obj2 = MyClass(1, 2, 3)
print(obj2)