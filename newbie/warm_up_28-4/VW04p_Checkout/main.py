import math
d, a1, a2, v, t = map(float, input().split())

a = -1/(2*a1) - 1/(2*a2)
b = -t
c = d
delta = b*b-4*a*c
x1 = (-b+math.sqrt(delta))/(2*a)
x2 = (-b-math.sqrt(delta))/(2*a)
v_new = max(x1,x2)
if v_new<v:
    v= v_new
t = v/(2*a1) + v/(2*a2) +  d/v
print(round(t,12))