import random
import sys

#sys.stdin = open("a.txt", "r")

n = int(input())

Ax, Ay = map(int, input().split())
Bx, By = map(int, input().split())
move = set()
for _ in range(n):
    x, y = map(int, input().split())
    move.add((x, y))

def inside(x, y):
    return (x > 0 and y > 0 and x <= n and y <= n)

def reach(x, y, u, v):
    if (x == u and y == v):
        return True
    
    if (u-x, v-y) in move:
        return True
    
    for xx, yy in move:
        newx = xx + x
        newy = yy + y
        if not inside(newx, newy):
            continue
        if (u-newx, v-newy) in move:
            return True
    return False

def tie_lose():
    # tie if n < 100
    if n < 100:
        for x in range(1, n+1):
            for y in range(1, n+1):
                if not reach(Bx, By, x, y):
                    print("tie %d %d" %(x, y))
                    return None
    else:
        for _ in range(10000):
            x = random.randrange(1, n)
            y = random.randrange(1, n)
            if not reach(Bx, By, x, y):
                print("tie %d %d" %(x, y))
                return None
    print("Bob wins")
    

if reach(Ax, Ay, Bx, By):
    print("Alice wins")
else:
    tie_lose()

