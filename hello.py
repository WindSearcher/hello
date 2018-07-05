




age = 20;
message ="Happy" + str(age) +" rd birthday"
print(message)

bicycles =["trek","cannondale","redline","specialized"]
print(bicycles)
print(bicycles[0])
print(bicycles[-1])#-1为最后一个元素的索引
bicycles.append("hello")
print(bicycles)
bicycles.insert(0,"hello")
print(bicycles)
bicycles.append("world")
print(bicycles)
bicycles.insert(0,"world")
print(bicycles)

del bicycles[0]
print(bicycles)

m_bicycles = bicycles.pop()
print(bicycles)
print(m_bicycles)
